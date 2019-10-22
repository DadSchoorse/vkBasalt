INSTALL_DIR := $(HOME)/.local/share/vulkan/implicit_layer.d
LIB32 := $(HOME)/.local/share/vkBasalt/libvkbasalt32.so
LIB64 := $(HOME)/.local/share/vkBasalt/libvkbasalt64.so
CONFIG := $(HOME)/.local/share/vkBasalt/vkBasalt.conf

install: 
	mkdir -p $(INSTALL_DIR)
	sed 's+@lib+$(LIB32)+g' vkBasalt32.json > $(INSTALL_DIR)/vkBasalt32.json
	sed 's+@lib+$(LIB64)+g' vkBasalt64.json > $(INSTALL_DIR)/vkBasalt64.json
	install -m 0644 -D -T vkBasalt.conf $(CONFIG)
	
