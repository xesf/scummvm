MODULE := engines/dgds
 
MODULE_OBJS := \
    dgds.o \
    detection.o \
    metaengine.o
 
MODULE_DIRS += \
    engines/dgds
 
# This module can be built as a plugin
ifeq ($(ENABLE_DGDS), DYNAMIC_PLUGIN)
PLUGIN := 1
endif
 
# Include common rules
include $(srcdir)/rules.mk

# Detection objects
DETECT_OBJS += $(MODULE)/detection.o
