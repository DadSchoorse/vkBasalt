/**
 * Deband shader by haasn
 * https://github.com/haasn/gentoo-conf/blob/xor/home/nand/.mpv/shaders/deband-pre.glsl
 *
 * Copyright (c) 2015 Niklas Haas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#version 450

layout(set=0, binding=0) uniform sampler2D img;

layout(constant_id = 0) const float screenWidth = 1920;
layout(constant_id = 1) const float screenHeight = 1080;
layout(constant_id = 2) const float reverseScreenWidth = 1.0/1920.0;
layout(constant_id = 3) const float reverseScreenHeight = 1.0/1080.0;
layout(constant_id = 4) const float debandAvgdiff = 3.4;
layout(constant_id = 5) const float debandMaxdiff = 6.8;
layout(constant_id = 6) const float debandMiddiff = 3.3;
layout(constant_id = 7) const float range = 16.0;
layout(constant_id = 8) const int   iterations = 4;

layout(location = 0) in vec2 texcoord;
layout(location = 0) out vec4 fragColor;

#define textureLod0Offset(img, coord, offset) textureLodOffset(img, coord, 0.0f, offset)
#define textureLod0(img, coord) textureLod(img, coord, 0.0f)

float rand(float x)
{
    return fract(x / 41.0);
}

float permute(float x)
{
    return mod(((34.0 * x + 1.0) * x), 289.0);
}

void analyze_pixels(vec3 ori, sampler2D tex, vec2 texcoord, vec2 _range, vec2 dir, out vec3 ref_avg, out vec3 ref_avg_diff, out vec3 ref_max_diff, out vec3 ref_mid_diff1, out vec3 ref_mid_diff2)
{
    // Sample at quarter-turn intervals around the source pixel

    // South-east
    vec3 ref = textureLod0(tex, texcoord + _range * dir).rgb;
    vec3 diff = abs(ori - ref);
    ref_max_diff = diff;
    ref_avg = ref;
    ref_mid_diff1 = ref;

    // North-west
    ref = textureLod0(tex, texcoord + _range * -dir).rgb;
    diff = abs(ori - ref);
    ref_max_diff = max(ref_max_diff, diff);
    ref_avg += ref;
    ref_mid_diff1 = abs(((ref_mid_diff1 + ref) * 0.5) - ori);

    // North-east
    ref = textureLod0(tex, texcoord + _range * vec2(-dir.y, dir.x)).rgb;
    diff = abs(ori - ref);
    ref_max_diff = max(ref_max_diff, diff);
    ref_avg += ref;
    ref_mid_diff2 = ref;

    // South-west
    ref = textureLod0(tex, texcoord + _range * vec2( dir.y, -dir.x)).rgb;
    diff = abs(ori - ref);
    ref_max_diff = max(ref_max_diff, diff);
    ref_avg += ref;
    ref_mid_diff2 = abs(((ref_mid_diff2 + ref) * 0.5) - ori);

    ref_avg *= 0.25; // Normalize avg
    ref_avg_diff = abs(ori - ref_avg);
}

void main()
{
    // Normalize
    float avgdiff = debandAvgdiff / 255.0;
    float maxdiff = debandMaxdiff / 55.0;
    float middiff = debandMiddiff / 255.0;
    
    const int drandom = 436;//TODO very random 

    // Initialize the PRNG by hashing the position + a random uniform
    float h = permute(permute(permute(texcoord.x) + texcoord.y) + drandom / 32767.0);

    vec3 ref_avg; // Average of 4 reference pixels
    vec3 ref_avg_diff; // The difference between the average of 4 reference pixels and the original pixel
    vec3 ref_max_diff; // The maximum difference between one of the 4 reference pixels and the original pixel
    vec3 ref_mid_diff1; // The difference between the average of SE and NW reference pixels and the original pixel
    vec3 ref_mid_diff2; // The difference between the average of NE and SW reference pixels and the original pixel

    vec4 ori_alpha = textureLod0(img, texcoord); // Original pixel
    vec3 ori = ori_alpha.rgb;
    vec3 res; // Final pixel

    // Compute a random angle
    float dir  = rand(permute(h)) * 6.2831853;
    vec2 o = vec2(cos(dir), sin(dir));

    for (int i = 1; i <= iterations; ++i) {
        // Compute a random distance
        float dist = rand(h) * range * i;
        vec2 pt = dist * vec2(reverseScreenWidth, reverseScreenHeight);

        analyze_pixels(ori, img, texcoord, pt, o,
                       ref_avg,
                       ref_avg_diff,
                       ref_max_diff,
                       ref_mid_diff1,
                       ref_mid_diff2);

        vec3 ref_avg_diff_threshold = vec3(avgdiff * i);
        vec3 ref_max_diff_threshold = vec3(maxdiff * i);
        vec3 ref_mid_diff_threshold = vec3(middiff * i);
        

        // Fuzzy logic based pixel selection
        vec3 factor = pow(clamp(3.0 * (1.0 - ref_avg_diff  / ref_avg_diff_threshold), 0, 1) *
                          clamp(3.0 * (1.0 - ref_max_diff  / ref_max_diff_threshold), 0, 1) *
                          clamp(3.0 * (1.0 - ref_mid_diff1 / ref_mid_diff_threshold), 0, 1) *
                          clamp(3.0 * (1.0 - ref_mid_diff2 / ref_mid_diff_threshold), 0, 1), vec3(0.1));

        res = mix(ori, ref_avg, factor);

        h = permute(h);
    }

	const float dither_bit = 8.0; //Number of bits per channel. Should be 8 for most monitors.

	/*------------------------.
	| :: Ordered Dithering :: |
	'------------------------*/
	//Calculate grid position
	float grid_position = fract(dot(texcoord, (vec2(screenWidth, screenHeight) * vec2(1.0 / 16.0, 10.0 / 36.0)) + 0.25));

	//Calculate how big the shift should be
	float dither_shift = 0.25 * (1.0 / (pow(2, dither_bit) - 1.0));

	//Shift the individual colors differently, thus making it even harder to see the dithering pattern
	vec3 dither_shift_RGB = vec3(dither_shift, -dither_shift, dither_shift); //subpixel dithering

	//modify shift acording to grid position.
	dither_shift_RGB = mix(2.0 * dither_shift_RGB, -2.0 * dither_shift_RGB, grid_position); //shift acording to grid position.

	//shift the color by dither_shift
	res += dither_shift_RGB;

    fragColor = vec4(res,ori_alpha.a);
}
