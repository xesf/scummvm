MODULE := engines/hdb

MODULE_OBJS := \
	detection.o \
	draw-manager.o \
	file-manager.o \
	hdb.o \
	lua-script.o \
	console.o

MODULE_DIRS += \
	engines/hdb

# This module can be built as a plugin
ifeq ($(ENABLE_HDB), DYNAMIC_PLUGIN)
PLUGIN := 1
endif

# Include common rules
include $(srcdir)/rules.mk