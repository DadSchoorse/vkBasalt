#version 450

layout(set=0, binding=0) uniform sampler2D img;
layout(set=1, binding=0) uniform sampler3D lut;

//Only works with cubes not with cuboids
layout(constant_id = 0) const int lutSize = 32;
layout(constant_id = 1) const int flipGB = 0;

layout(location = 0) in vec2 textureCoord;
layout(location = 0) out vec4 fragColor;

void main()
{
    vec4 color;
    if(flipGB != 0)
    {
        color = texture(img,textureCoord).rbga;
    }
    else
    {
        color = texture(img,textureCoord);
    }
    
    //see https://developer.nvidia.com/gpugems/GPUGems2/gpugems2_chapter24.html
    vec3 scale = (vec3(lutSize) - 1.0) / vec3(lutSize);
    vec3 offset = 1.0 / (2.0 * vec3(lutSize));
    
    fragColor = vec4(texture(lut, scale * color.rgb + offset).rgb, color.a);
}
