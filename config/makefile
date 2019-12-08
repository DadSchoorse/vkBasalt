INSTALL_DIR := $(DESTDIR)$(PREFIX)/share/vulkan/implicit_layer.d
LIB32 := $(DESTDIR)$(PREFIX)/share/vkBasalt/libvkbasalt32.so
LIB64 := $(DESTDIR)$(PREFIX)/share/vkBasalt/libvkbasalt64.so
CONFIG := $(DESTDIR)$(PREFIX)/share/vkBasalt/vkBasalt.conf
SED ?= sed

install:
	mkdir -p $(INSTALL_DIR)
	$(SED) 's+@lib+$(LIB32)+g' vkBasalt32.json > $(INSTALL_DIR)/vkBasalt32.json
	$(SED) 's+@lib+$(LIB64)+g' vkBasalt64.json > $(INSTALL_DIR)/vkBasalt64.json
	install -m 0644 -D -T vkBasalt.conf $(CONFIG)

uninstall:
	rm $(INSTALL_DIR)/vkBasalt64.json
	rm $(INSTALL_DIR)/vkBasalt32.json
