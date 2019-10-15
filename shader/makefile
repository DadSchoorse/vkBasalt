BUILD_DIR := ../build/shader

SRC_FILES := $(wildcard *.glsl)
SPV_FILES := $(foreach file,$(patsubst %.glsl,%.spv,$(SRC_FILES)),$(BUILD_DIR)/$(file))

all: $(SPV_FILES)

$(BUILD_DIR)/%.spv: %.glsl $(BUILD_DIR)
	glslangValidator -V $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
