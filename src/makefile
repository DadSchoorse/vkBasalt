CPPC := g++
CFLAGS := -O3 -fPIC #-Wall -Wextra
LINKER :=  -shared #-fvisibility=hidden

BUILD_DIR := ../build


SRC_FILES := $(wildcard *.cpp)
OBJ_FILES := $(foreach file,$(patsubst %.cpp,%.o,$(SRC_FILES)),$(BUILD_DIR)/$(file))


all: $(BUILD_DIR)/libvkbasalt.so

$(BUILD_DIR)/libvkbasalt.so: $(OBJ_FILES)
	$(CPPC) -o $@ $^ $(CFLAGS) $(LINKER)

$(BUILD_DIR)/%.o: %.cpp $(BUILD_DIR)
	$(CPPC) $< -o $@ -c  $(CFLAGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)


