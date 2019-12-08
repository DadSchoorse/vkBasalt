CXX ?= g++
CXXFLAGS ?= -O3 -fPIC -Wall -Wextra -Wno-unused-parameter
CXXFLAGS += -std=c++17
LDFLAGS +=  -shared -lstdc++fs -fvisibility=hidden

BUILD_DIR := ../build
INSTALL_DIR := $(DESTDIR)$(PREFIX)/share/vkBasalt

SRC_FILES := $(wildcard *.cpp)
OBJ_FILES64 := $(foreach file,$(patsubst %.cpp,%.64.o,$(SRC_FILES)),$(BUILD_DIR)/$(file))
OBJ_FILES32 := $(foreach file,$(patsubst %.cpp,%.32.o,$(SRC_FILES)),$(BUILD_DIR)/$(file))

all: $(BUILD_DIR)/libvkbasalt64.so $(BUILD_DIR)/libvkbasalt32.so

$(BUILD_DIR)/libvkbasalt64.so: $(OBJ_FILES64)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) -m64

$(BUILD_DIR)/libvkbasalt32.so: $(OBJ_FILES32)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) -m32

$(BUILD_DIR)/%.64.o: %.cpp $(BUILD_DIR)
	$(CXX) $< -o $@ -c  $(CXXFLAGS) -m64

$(BUILD_DIR)/%.32.o: %.cpp $(BUILD_DIR)
	$(CXX) $< -o $@ -c  $(CXXFLAGS) -m32

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

install:
	install -m 0755 -D -T $(BUILD_DIR)/libvkbasalt64.so $(INSTALL_DIR)/libvkbasalt64.so
	install -m 0755 -D -T $(BUILD_DIR)/libvkbasalt32.so $(INSTALL_DIR)/libvkbasalt32.so
