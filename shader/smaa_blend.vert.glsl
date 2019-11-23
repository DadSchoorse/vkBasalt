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

layout(location=0) out vec2 textureCoord;
layout(location=1) out vec2 pixelCoord;
layout(location=2) out vec4[3] offsets;

#include "smaa_settings.h"
#define SMAA_INCLUDE_VS 1
#define SMAA_INCLUDE_PS 0
#include "smaa.h"

void main()
{
    textureCoord = texture_coordinates[gl_VertexIndex];
    SMAABlendingWeightCalculationVS(textureCoord, pixelCoord, offsets);
    gl_Position = vec4(positions[gl_VertexIndex], 0.0, 1.0);
    
}
