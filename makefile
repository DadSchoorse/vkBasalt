DIRS = src shader
INSTALL_DIRS = src shader config
compile:
	for i in $(DIRS); do make -C $$i; done
	
install:
	for i in $(INSTALL_DIRS); do make install -C $$i; done
	
	
