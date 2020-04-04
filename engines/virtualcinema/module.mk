MODULE := engines/virtualcinema
 
MODULE_OBJS := \
    virtualcinema.o \
    detection.o \
    video.o
 
MODULE_DIRS += \
    engines/virtualcinema
 
# This module can be built as a plugin
ifeq ($(ENABLE_VIRTUALCINEMA), DYNAMIC_PLUGIN)
PLUGIN := 1
endif
 
# Include common rules
include $(srcdir)/rules.mk
