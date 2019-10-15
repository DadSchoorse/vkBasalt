DIRS = src shader

compile:
	for i in $(DIRS); do make -C $$i; done

