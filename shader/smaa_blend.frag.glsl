#version 450
#extension  GL_GOOGLE_include_directive : require

layout(set = 0, binding = 1) uniform sampler2D edgesTex;
layout(set = 0, binding = 2) uniform sampler2D areaTex;
layout(set = 0, binding = 3) uniform sampler2D searchTex;

layout(set = 1, binding = 0) uniform SmaaBufferObject{
    float screenWidth;
    float screenHeight;
    float reverseScreenWidth;
    float reverseScreenHeight;

} sbo;

layout(location = 0) out vec4 fragColor;
layout(location = 0) in vec2 textureCoord;
layout(location = 1) in vec2 pixelCoord;
layout(location = 2) in vec4[3] offsets;

#define SMAA_RT_METRICS vec4(sbo.reverseScreenWidth,sbo.reverseScreenHeight,sbo.screenWidth,sbo.screenHeight)
#define SMAA_GLSL_4 1
#define SMAA_PRESET_ULTRA 1
#define SMAA_INCLUDE_VS 0
#define SMAA_INCLUDE_PS 1
#include "smaa.h"

void main()
{
    fragColor = SMAABlendingWeightCalculationPS(textureCoord, pixelCoord, offsets, edgesTex, areaTex, searchTex, vec4(0.0));
}

