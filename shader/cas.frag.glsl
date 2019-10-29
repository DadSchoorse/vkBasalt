#version 450

layout(set=0, binding=0) uniform sampler2D img;
layout(set=1, binding=0) uniform CasBufferObject{
    float sharpness;
} cbo;

layout(location = 0) in vec2 textureCoord;
layout(location = 0) out vec4 fragColor;

void main()
{
    float sharpness = cbo.sharpness;
    
    // fetch a 3x3 neighborhood around the pixel 'e',
    //  a b c
    //  d(e)f
    //  g h i
    float alpha = texture(img,textureCoord).w;
    
    vec3 a = textureOffset(img, textureCoord, ivec2(-1,-1)).xyz;
    vec3 b = textureOffset(img, textureCoord, ivec2( 0,-1)).xyz;
    vec3 c = textureOffset(img, textureCoord, ivec2( 1,-1)).xyz;
    vec3 d = textureOffset(img, textureCoord, ivec2(-1, 0)).xyz;
    vec3 e = textureOffset(img, textureCoord, ivec2( 0, 0)).xyz;
    vec3 f = textureOffset(img, textureCoord, ivec2( 1, 0)).xyz;
    vec3 g = textureOffset(img, textureCoord, ivec2(-1, 1)).xyz;
    vec3 h = textureOffset(img, textureCoord, ivec2( 0, 1)).xyz;
    vec3 i = textureOffset(img, textureCoord, ivec2( 1, 1)).xyz;
    
    // Soft min and max.
    //  a b c             b
    //  d e f * 0.5  +  d e f * 0.5
    //  g h i             h
    // These are 2.0x bigger (factored out the extra multiply).
    
    vec3 mnRGB  = min(min(min(d,e),min(f,b)),h);
    vec3 mnRGB2 = min(min(min(mnRGB,a),min(g,c)),i);
    mnRGB += mnRGB2;
    
    vec3 mxRGB  = max(max(max(d,e),max(f,b)),h);
    vec3 mxRGB2 = max(max(max(mxRGB,a),max(g,c)),i);
    mxRGB += mxRGB2;
    
    // Smooth minimum distance to signal limit divided by smooth max.
    
    vec3 rcpMxRGB = -vec3(1)/mxRGB;
    vec3 ampRGB = clamp((min(mnRGB,2.0-mxRGB)-rcpMxRGB),0,1);
    
    // Shaping amount of sharpening.
    ampRGB = inversesqrt(ampRGB);
    float peak = 8.0 - 3.0 * sharpness;
    vec3 wRGB = -vec3(1)/(ampRGB * peak);
    vec3 rcpWeightRGB = vec3(1)/(1.0 + 4.0 * wRGB);
    
    //                          0 w 0
    //  Filter shape:           w 1 w
    //                          0 w 0  
    
    vec3 window = (b + d) + (f + h);
    vec3 outColor = clamp((window * wRGB + e) * rcpWeightRGB,0,1);
    
    fragColor = vec4(outColor,alpha);
}
