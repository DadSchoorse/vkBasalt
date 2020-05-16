

layout(constant_id = 0) const float screenWidth = 1920;
layout(constant_id = 1) const float screenHeight = 1080;
layout(constant_id = 2) const float reverseScreenWidth = 1.0/1920.0;
layout(constant_id = 3) const float reverseScreenHeight = 1.0/1080.0;
layout(constant_id = 4) const float threshold = 0.05;
layout(constant_id = 5) const int   maxSearchSteps = 32;
layout(constant_id = 6) const int   maxSearchStepsDiag = 16;
layout(constant_id = 7) const int   cornerRounding = 25;

#define SMAA_RT_METRICS vec4(reverseScreenWidth, reverseScreenHeight, screenWidth, screenHeight)
#define SMAA_GLSL_4 1
#define SMAA_THRESHOLD threshold
#define SMAA_MAX_SEARCH_STEPS maxSearchSteps
#define SMAA_MAX_SEARCH_STEPS_DIAG maxSearchStepsDiag
#define SMAA_CORNER_ROUNDING cornerRounding

