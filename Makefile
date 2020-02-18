.DEFAULT_GOAL := all

.PHONY: build64 build32 all clean install

DESTDIR ?= /
PREFIX ?= $(HOME)/.local

PKG_CONFIG_PATH_32 ?= /usr/lib32/pkgconfig

MESON_FILES := meson.build
MESON_FLAGS += --buildtype release --prefix $(PREFIX)
MESON_CROSS_FILE_32 ?= meson-32-cross.txt
MESON_FLAGS_32 += --libdir=lib32

INSTALL_BUILD_DIRS := builds/Release32 builds/Release64

builds/Release64/build.ninja: $(MESON_FILES)
	meson $(MESON_FLAGS) $(@D)

builds/Release32/build.ninja: $(MESON_FILES) $(MESON_CROSS_FILE_32)
	PKG_CONFIG_PATH="$(PKG_CONFIG_PATH_32)" meson $(MESON_FLAGS) $(MESON_FLAGS_32) --cross-file $(MESON_CROSS_FILE_32) $(@D)

build64: builds/Release64/build.ninja
	ninja -C $(<D)

build32: builds/Release32/build.ninja
	ninja -C $(<D)

all: build64 build32

clean:
	[ ! -d builds/Release32 ] || rm -rf builds/Release32
	[ ! -d builds/Release64 ] || rm -rf builds/Release64

install: all
	$(foreach dir, $(INSTALL_BUILD_DIRS), DESTDIR=$(DESTDIR) ninja -C $(dir) install; )
