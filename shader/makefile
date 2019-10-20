BUILD_DIR := ../build/shader

INSTALL_DIR := $(HOME)/.local/share/vkBasalt/shader/

SRC_FILES := $(wildcard *.glsl)
SPV_FILES := $(foreach file,$(patsubst %.glsl,%.spv,$(SRC_FILES)),$(BUILD_DIR)/$(file))

all: $(SPV_FILES)

$(BUILD_DIR)/%.spv: %.glsl $(BUILD_DIR)
	glslangValidator -V $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	
	
install: all
	mkdir -p $(INSTALL_DIR)
	install -m 0644 -t  $(INSTALL_DIR)  $(SPV_FILES)
	
