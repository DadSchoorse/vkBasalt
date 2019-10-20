DIRS = src shader
INSTALL_DIRS = src shader config
compile:
	for i in $(DIRS); do $(MAKE) -C $$i; done
	
install:
	for i in $(INSTALL_DIRS); do $(MAKE) install -C $$i; done
	
	
