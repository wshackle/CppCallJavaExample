
JDK_DIR=$(shell ./findJavaHome.sh)
JRE_LIB_DIR=$(shell ./findJVMLib.sh)
JAVAC=$(JDK_DIR)/bin/javac

build clean clobber all help:
	$(MAKE) -C CppWrapJavaExampleDynamicLibrary JDK_DIR=$(JDK_DIR) JRE_LIB_DIR=$(JRE_LIB_DIR) JAVAC=$(JAVAC) $@
	$(MAKE) -C CppCallJavaApplication JDK_DIR=$(JDK_DIR) JRE_LIB_DIR=$(JRE_LIB_DIR) JAVAC=$(JAVAC) $@
	

.PHONY: build clean clobber all help

