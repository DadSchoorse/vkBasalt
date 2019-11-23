

layout (constant_id = 0) const float screenWidth = 1920;
layout (constant_id = 1) const float screenHeight = 1080;
layout (constant_id = 2) const float reverseScreenWidth = 1.0/1920.0;
layout (constant_id = 3) const float reverseScreenHeight = 1.0/1080.0;

#define SMAA_RT_METRICS vec4(reverseScreenWidth, reverseScreenHeight, screenWidth, screenHeight)
#define SMAA_GLSL_4 1
#define SMAA_PRESET_ULTRA 1
