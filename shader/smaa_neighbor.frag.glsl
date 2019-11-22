#version 450
#extension  GL_GOOGLE_include_directive : require

layout(set = 0, binding = 0) uniform sampler2D colorImg;
layout(set = 0, binding = 4) uniform sampler2D blendTex;

layout (constant_id = 0) const float screenWidth = 1920;
layout (constant_id = 1) const float screenHeight = 1080;
layout (constant_id = 2) const float reverseScreenWidth = 1.0/1920.0;
layout (constant_id = 3) const float reverseScreenHeight = 1.0/1080.0;

layout(location = 0) out vec4 fragColor;
layout(location = 0) in vec2 textureCoord;
layout(location = 1) in vec4 offset;

#define SMAA_RT_METRICS vec4(reverseScreenWidth, reverseScreenHeight, screenWidth, screenHeight)
#define SMAA_GLSL_4 1
#define SMAA_PRESET_ULTRA 1
#define SMAA_INCLUDE_VS 0
#define SMAA_INCLUDE_PS 1
#include "smaa.h"

void main()
{
    fragColor = SMAANeighborhoodBlendingPS(textureCoord, offset, colorImg, blendTex);
}

