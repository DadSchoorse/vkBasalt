#version 450
#extension  GL_GOOGLE_include_directive : require

layout(location=0) out vec2 textureCoord;
layout(location=1) out vec4 offset;

#include "smaa_settings.h"
#define SMAA_INCLUDE_VS 1
#define SMAA_INCLUDE_PS 0
#include "smaa.h"

void main()
{
    gl_Position = vec4(gl_VertexIndex == 1 ? 3.0 : -1.0,
                       gl_VertexIndex == 2 ? 3.0 : -1.0,
                       0.0,
                       1.0);

    textureCoord = vec2(gl_VertexIndex == 1 ? 2.0 : 0.0,
                        gl_VertexIndex == 2 ? 2.0 : 0.0);

    SMAANeighborhoodBlendingVS(textureCoord, offset);
}
