.DEFAULT_GOAL := all

.PHONY: build64 build32 all clean install

PKG_CONFIG_PATH_32 ?= /usr/lib32/pkgconfig

MESON_FILES := meson.build
MESON_FLAGS += --buildtype release
MESON_CROSS_FILE_32 ?= meson-32-cross.txt
MESON_FLAGS_32 += --libdir=lib32

INSTALL_BUILD_DIRS := builds/Release32 builds/Release64

builds/Release64: $(MESON_FILES)
	[ ! -d $@ ] || rm -rf $@
	meson $(MESON_FLAGS) $@

builds/Release32: $(MESON_FILES) $(MESON_CROSS_FILE_32)
	[ ! -d $@ ] || rm -rf $@
	PKG_CONFIG_PATH="$(PKG_CONFIG_PATH_32)" meson $(MESON_FLAGS) $(MESON_FLAGS_32) --cross-file $(MESON_CROSS_FILE_32) $@

build64: builds/Release64
	ninja -C $<

build32: builds/Release32
	ninja -C $<

all: build64 build32

clean:
	[ ! -d builds/Release32 ] || rm -rf builds/Release32
	[ ! -d builds/Release64 ] || rm -rf builds/Release64

install: all
	$(foreach dir, $(INSTALL_BUILD_DIRS), ninja -C $(dir) install; )
