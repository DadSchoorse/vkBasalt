#version 450

layout(location = 0) out vec2 textureCoord;

void main() {
    gl_Position = vec4(gl_VertexIndex == 1 ? 3.0 : -1.0, 
                       gl_VertexIndex == 2 ? 3.0 : -1.0,
                       0.0,
                       1.0);

    textureCoord = vec2(gl_VertexIndex == 1 ? 2.0 : 0.0, 
                        gl_VertexIndex == 2 ? 2.0 : 0.0);
}

