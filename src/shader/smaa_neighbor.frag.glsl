#version 450
#extension  GL_GOOGLE_include_directive : require

layout(set = 0, binding = 0) uniform sampler2D colorImg;
layout(set = 0, binding = 4) uniform sampler2D blendTex;

layout(location = 0) out vec4 fragColor;
layout(location = 0) in vec2 textureCoord;
layout(location = 1) in vec4 offset;

#include "smaa_settings.h"
#define SMAA_INCLUDE_VS 0
#define SMAA_INCLUDE_PS 1
#include "smaa.h"

void main()
{
    fragColor = SMAANeighborhoodBlendingPS(textureCoord, offset, colorImg, blendTex);
}

