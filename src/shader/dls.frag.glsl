/*
  Image sharpening filter from GeForce Experience. Provided by NVIDIA Corporation.
  
  Copyright 2019 Suketu J. Shah. All rights reserved.
  Redistribution and use in source and binary forms, with or without modification, are permitted provided
  that the following conditions are met:
    1. Redistributions of source code must retain the above copyright notice, this list of conditions
       and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
       and the following disclaimer in the documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
       or promote products derived from this software without specific prior written permission.
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
  PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#version 450

layout(set=0, binding=0) uniform sampler2D img;

layout (constant_id = 0) const float sharpen = 0.5;
layout (constant_id = 1) const float denoise = 0.17;

layout(location = 0) in vec2 textureCoord;
layout(location = 0) out vec4 fragColor;

#define textureLod0Offset(img, coord, offset) textureLodOffset(img, coord, 0.0f, offset)
#define textureLod0(img, coord) textureLod(img, coord, 0.0f)

float GetLumaComponents(float r, float g, float b)
{
    // Y from JPEG spec
    return 0.299 * r + 0.587 * g + 0.114 * b;
}

float GetLuma(vec4 p)
{
    return GetLumaComponents(p.x, p.y, p.z);
}

float Square(float v)
{
    return v * v;
}

// highlight fall-off start (prevents halos and noise in bright areas)
#define kHighBlock 0.65
// offset reducing sharpening in the shadows
#define kLowBlock (1.0 / 256.0)
#define kSharpnessMin (-1.0 / 14.0)
#define kSharpnessMax (-1.0 / 6.5)
#define kDenoiseMin (0.001)
#define kDenoiseMax (-0.1)

void main()
{
    //  e  d  h
    //  a (x) b
    //  g  c  f

    vec4 x = textureLod0(img, textureCoord);

    vec4 a = textureLod0Offset(img, textureCoord, ivec2(-1,  0));
    vec4 b = textureLod0Offset(img, textureCoord, ivec2( 1,  0));
    vec4 c = textureLod0Offset(img, textureCoord, ivec2( 0,  1));
    vec4 d = textureLod0Offset(img, textureCoord, ivec2( 0, -1));

    vec4 e = textureLod0Offset(img, textureCoord, ivec2(-1, -1));
    vec4 f = textureLod0Offset(img, textureCoord, ivec2( 1,  1));
    vec4 g = textureLod0Offset(img, textureCoord, ivec2(-1,  1));
    vec4 h = textureLod0Offset(img, textureCoord, ivec2( 1, -1));

    float lx = GetLuma(x);

    float la = GetLuma(a);
    float lb = GetLuma(b);
    float lc = GetLuma(c);
    float ld = GetLuma(d);

    float le = GetLuma(e);
    float lf = GetLuma(f);
    float lg = GetLuma(g);
    float lh = GetLuma(h);

    // cross min/max
    const float ncmin = min(min(le, lf), min(lg, lh));
    const float ncmax = max(max(le, lf), max(lg, lh));

    // plus min/max
    float npmin = min(min(min(la, lb), min(lc, ld)), lx);
    float npmax = max(max(max(la, lb), max(lc, ld)), lx);

    // compute "soft" local dynamic range -- average of 3x3 and plus shape
    float lmin = 0.5 * min(ncmin, npmin) + 0.5 * npmin;
    float lmax = 0.5 * max(ncmax, npmax) + 0.5 * npmax;

    // compute local contrast enhancement kernel
    float lw = lmin / (lmax + kLowBlock);
    float hw = Square(1.0 - Square(max(lmax - kHighBlock, 0.0) / ((1.0 - kHighBlock))));

    // noise suppression
    // Note: Ensure that the denoiseFactor is in the range of (10, 1000) on the CPU-side prior to launching this shader.
    // For example, you can do so by adding these lines
    //      const float kDenoiseMin = 0.001f;
    //      const float kDenoiseMax = 0.1f;
    //      float kernelDenoise = 1.0 / (kDenoiseMin + (kDenoiseMax - kDenoiseMin) * min(max(denoise, 0.0), 1.0));
    // where kernelDenoise is the value to be passed in to this shader (the amount of noise suppression is inversely proportional to this value),
    //       denoise is the value chosen by the user, in the range (0, 1)
	const float kernelDenoise = 1.0 / (kDenoiseMin + (kDenoiseMax - kDenoiseMin) * denoise);
    const float nw = Square((lmax - lmin) * kernelDenoise);

    // pick conservative boost
    const float boost = min(min(lw, hw), nw);

    // run variable-sigma 3x3 sharpening convolution
    // Note: Ensure that the sharpenFactor is in the range of (-1.0/14.0, -1.0/6.5f) on the CPU-side prior to launching this shader.
    // For example, you can do so by adding these lines
    //      const float kSharpnessMin = -1.0 / 14.0;
    //      const float kSharpnessMax = -1.0 / 6.5f;
    //      float kernelSharpness = kSharpnessMin + (kSharpnessMax - kSharpnessMin) * min(max(sharpen, 0.0), 1.0);
    // where kernelSharpness is the value to be passed in to this shader,
    //       sharpen is the value chosen by the user, in the range (0, 1)
    const float kernelSharpness = kSharpnessMin + (kSharpnessMax - kSharpnessMin) * sharpen;
    const float k = boost * kernelSharpness;

    float accum = lx;
    accum += la * k;
    accum += lb * k;
    accum += lc * k;
    accum += ld * k;
    accum += le * (k * 0.5);
    accum += lf * (k * 0.5);
    accum += lg * (k * 0.5);
    accum += lh * (k * 0.5);

    // normalize (divide the accumulator by the sum of convolution weights)
    accum /= 1.0 + 6.0 * k;

    // accumulator is in linear light space            
    float delta = accum - lx;
    x.x += delta;
    x.y += delta;
    x.z += delta;

    fragColor = x;
}
