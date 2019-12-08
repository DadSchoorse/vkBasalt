DIRS = src shader
INSTALL_DIRS = src shader config
DESTDIR ?= $(HOME)
PREFIX ?= /.local

export DESTDIR PREFIX

compile:
	for i in $(DIRS); do $(MAKE) -C $$i; done

install:
	for i in $(INSTALL_DIRS); do $(MAKE) install -C $$i; done

uninstall:
	rm -rf $(DESTDIR)$(PREFIX)/share/vkBasalt
	$(MAKE) uninstall -C config

clean:
	rm -rf build
