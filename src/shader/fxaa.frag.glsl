#version 450
#extension  GL_GOOGLE_include_directive : require

#define FXAA_QUALITY_PRESET 39
#define FXAA_GLSL_130 1
#define FXAA_PC 1
#define FXAA_GREEN_AS_LUMA 1
#include "fxaa3_11.h"

layout(set=0, binding=0) uniform sampler2D img;

layout (constant_id = 0) const float fxaaQualitySubpix = 0.75;
layout (constant_id = 1) const float fxaaQualityEdgeThreshold = 0.125;
layout (constant_id = 2) const float fxaaQualityEdgeThresholdMin = 0.0312;
layout (constant_id = 3) const float screenWidth = 1920;
layout (constant_id = 4) const float screenHeight = 1080;

layout(location = 0) in vec2 textureCoord;
layout(location = 0) out vec4 fragColor;

void main()
{
    vec2 size = vec2(screenWidth,screenHeight);
    vec2 fxaaQualityRcpFrame = vec2(1.0)/size;
    
    vec4 zero = vec4(0.0);
    
    fragColor = FxaaPixelShader(textureCoord, zero, img, img, img, fxaaQualityRcpFrame, zero, zero, zero, fxaaQualitySubpix, fxaaQualityEdgeThreshold, fxaaQualityEdgeThresholdMin, 8.0, 0.125, 0.05, zero);
}
