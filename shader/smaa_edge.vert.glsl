#version 450
#extension  GL_GOOGLE_include_directive : require

vec2 positions[3] = vec2[](
    vec2(-1.0,-1.0),
    vec2( 3.0,-1.0),
    vec2(-1.0, 3.0)
);

vec2 texture_coordinates[3] = vec2[](
    vec2( 0.0, 0.0),
    vec2( 2.0, 0.0),
    vec2( 0.0, 2.0)
);

layout (constant_id = 0) const float screenWidth = 1920;
layout (constant_id = 1) const float screenHeight = 1080;
layout (constant_id = 2) const float reverseScreenWidth = 1.0/1920.0;
layout (constant_id = 3) const float reverseScreenHeight = 1.0/1080.0;

layout(location=0) out vec2 textureCoord;
layout(location=1) out vec4[3] offsets;

#define SMAA_RT_METRICS vec4(reverseScreenWidth, reverseScreenHeight, screenWidth, screenHeight)
#define SMAA_GLSL_4 1
#define SMAA_PRESET_ULTRA 1
#define SMAA_INCLUDE_VS 1
#define SMAA_INCLUDE_PS 0
#include "smaa.h"

void main()
{
    textureCoord = texture_coordinates[gl_VertexIndex];
    SMAAEdgeDetectionVS(textureCoord, offsets);
    gl_Position = vec4(positions[gl_VertexIndex], 0.0, 1.0);
    
}
