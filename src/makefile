CXX ?= g++
CXXFLAGS ?= -O3 -Wall -Wextra -Wno-unused-parameter
CXXFLAGS += -fPIC -std=c++2a -I../reshade/deps/spirv/include/spirv/unified1 -I../include
LDFLAGS +=  -shared -lstdc++fs -lX11 -fvisibility=hidden

BUILD_DIR := ../build
INSTALL_DIR := $(DESTDIR)$(PREFIX)/share/vkBasalt

SRC_FILES := $(wildcard *.cpp)
OBJ_FILES64 := $(foreach file,$(patsubst %.cpp,%.64.o,$(SRC_FILES)),$(BUILD_DIR)/$(file))
OBJ_FILES32 := $(foreach file,$(patsubst %.cpp,%.32.o,$(SRC_FILES)),$(BUILD_DIR)/$(file))

RESHADE_SRC := $(wildcard ../reshade/source/effect*.cpp)
RESHADE_SRC := $(filter-out ../reshade/source/effect_codegen_hlsl.cpp,$(RESHADE_SRC))
RESHADE_SRC := $(filter-out ../reshade/source/effect_codegen_glsl.cpp,$(RESHADE_SRC))
RESHADE_OBJ64 := $(foreach file,$(patsubst %.cpp,%.64.o,$(notdir $(RESHADE_SRC))),$(BUILD_DIR)/reshade/$(file))
RESHADE_OBJ32 := $(patsubst %.64.o,%.32.o,$(RESHADE_OBJ64))

all: $(BUILD_DIR)/libvkbasalt64.so $(BUILD_DIR)/libvkbasalt32.so

$(BUILD_DIR)/libvkbasalt64.so: $(OBJ_FILES64) $(RESHADE_OBJ64)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) -m64

$(BUILD_DIR)/libvkbasalt32.so: $(OBJ_FILES32) $(RESHADE_OBJ32)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) -m32

$(BUILD_DIR)/%.64.o: %.cpp $(BUILD_DIR)
	$(CXX) $< -o $@ -c  $(CXXFLAGS) -m64

$(BUILD_DIR)/%.32.o: %.cpp $(BUILD_DIR)
	$(CXX) $< -o $@ -c  $(CXXFLAGS) -m32

$(BUILD_DIR)/reshade/%.32.o: ../reshade/source/%.cpp $(BUILD_DIR)/reshade
	$(CXX) $< -o $@ -c  $(CXXFLAGS) -Wno-unknown-pragmas -m32

$(BUILD_DIR)/reshade/%.64.o: ../reshade/source/%.cpp $(BUILD_DIR)/reshade
	$(CXX) $< -o $@ -c  $(CXXFLAGS) -Wno-unknown-pragmas -m64

$(BUILD_DIR)/reshade:
	mkdir -p $(BUILD_DIR)/reshade

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

install:
	install -m 0755 -D -T $(BUILD_DIR)/libvkbasalt64.so $(INSTALL_DIR)/libvkbasalt64.so
	install -m 0755 -D -T $(BUILD_DIR)/libvkbasalt32.so $(INSTALL_DIR)/libvkbasalt32.so
