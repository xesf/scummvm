MODULE := engines/virtualcinema

MODULE_OBJS = \
	agrippa/nodes/node.o \
    agrippa/agrippa.o \
    agrippa/game.o \
    agrippa/intro.o \
    agrippa/menu.o \
    agrippa/video.o \
	console.o \
	metaengine.o

# This module can be built as a plugin
ifeq ($(ENABLE_VIRTUALCINEMA), DYNAMIC_PLUGIN)
PLUGIN := 1
endif

# Include common rules
include $(srcdir)/rules.mk

# Detection objects
DETECT_OBJS += $(MODULE)/detection.o
