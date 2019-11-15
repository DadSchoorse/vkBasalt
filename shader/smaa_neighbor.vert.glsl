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

layout(set=1, binding=0) uniform SmaaBufferObject{
    float screenWidth;
    float screenHeight;
    float reverseScreenWidth;
    float reverseScreenHeight;

} sbo;

layout(location=0) out vec2 textureCoord;
layout(location=1) out vec4 offset;

#define SMAA_RT_METRICS vec4(sbo.reverseScreenWidth,sbo.reverseScreenHeight,sbo.screenWidth,sbo.screenHeight)
#define SMAA_GLSL_4 1
#define SMAA_PRESET_ULTRA 1
#define SMAA_INCLUDE_VS 1
#define SMAA_INCLUDE_PS 0
#include "smaa.h"

void main()
{
    textureCoord = texture_coordinates[gl_VertexIndex];
    SMAANeighborhoodBlendingVS(textureCoord, offset);
    gl_Position = vec4(positions[gl_VertexIndex], 0.0, 1.0);
    
}
