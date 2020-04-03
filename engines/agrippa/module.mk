MODULE := engines/agrippa
 
MODULE_OBJS := \
    agrippa.o \
    detection.o
 
MODULE_DIRS += \
    engines/agrippa
 
# This module can be built as a plugin
ifeq ($(ENABLE_AGRIPPA), DYNAMIC_PLUGIN)
PLUGIN := 1
endif
 
# Include common rules
include $(srcdir)/rules.mk
