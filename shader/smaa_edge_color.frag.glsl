#version 450
#extension  GL_GOOGLE_include_directive : require

layout(set = 0, binding = 0) uniform sampler2D colorImg;

layout(set = 1, binding = 0) uniform SmaaBufferObject{
    float screenWidth;
    float screenHeight;
    float reverseScreenWidth;
    float reverseScreenHeight;

} sbo;

layout(location = 0) out vec4 fragColor;
layout(location = 0) in vec2 textureCoord;
layout(location = 1) in vec4[3] offsets;

#define SMAA_RT_METRICS vec4(sbo.reverseScreenWidth,sbo.reverseScreenHeight,sbo.screenWidth,sbo.screenHeight)
#define SMAA_GLSL_4 1
#define SMAA_PRESET_ULTRA 1
#define SMAA_INCLUDE_VS 0
#define SMAA_INCLUDE_PS 1
#include "smaa.h"

void main()
{
    fragColor = vec4(SMAAColorEdgeDetectionPS(textureCoord, offsets, colorImg), 0.0, 0.0);
}

