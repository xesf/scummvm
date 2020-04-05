MODULE := engines/virtualcinema
 
MODULE_OBJS := \
    agrippa/agrippa.o \
    agrippa/video.o \
    detection.o
 
MODULE_DIRS += \
    engines/virtualcinema
 
# This module can be built as a plugin
ifeq ($(ENABLE_VIRTUALCINEMA), DYNAMIC_PLUGIN)
PLUGIN := 1
endif
 
# Include common rules
include $(srcdir)/rules.mk
