#version 450
#extension  GL_GOOGLE_include_directive : require

layout(set = 0, binding = 1) uniform sampler2D edgesTex;
layout(set = 0, binding = 2) uniform sampler2D areaTex;
layout(set = 0, binding = 3) uniform sampler2D searchTex;

layout(location = 0) out vec4 fragColor;
layout(location = 0) in vec2 textureCoord;
layout(location = 1) in vec2 pixelCoord;
layout(location = 2) in vec4[3] offsets;

#include "smaa_settings.h"

#define SMAA_INCLUDE_VS 0
#define SMAA_INCLUDE_PS 1
#include "smaa.h"

void main()
{
    fragColor = SMAABlendingWeightCalculationPS(textureCoord, pixelCoord, offsets, edgesTex, areaTex, searchTex, vec4(0.0));
}

