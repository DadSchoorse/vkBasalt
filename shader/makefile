BUILD_DIR := ../build/shader
BUILD_DIR_TMP := ../build/tmp

INSTALL_DIR := $(DESTDIR)$(PREFIX)/share/vkBasalt/shader/

SRC_FILES := $(wildcard *.glsl)
TMP_FILES := $(foreach file,$(patsubst %.glsl,%.spv,$(SRC_FILES)),$(BUILD_DIR_TMP)/$(file))
SPV_FILES := $(foreach file,$(patsubst %.glsl,%.spv,$(SRC_FILES)),$(BUILD_DIR)/$(file))

all: $(SPV_FILES)

$(BUILD_DIR)/%.spv: $(BUILD_DIR_TMP)/%.spv $(BUILD_DIR)
	spirv-opt $< -O -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	
$(BUILD_DIR_TMP)/%.spv: %.glsl $(BUILD_DIR_TMP)
	glslangValidator -V $< -o $@

$(BUILD_DIR_TMP):
	mkdir -p $(BUILD_DIR_TMP)

install:
	mkdir -p $(INSTALL_DIR)
	install -m 0644 -t  $(INSTALL_DIR)  $(SPV_FILES)
