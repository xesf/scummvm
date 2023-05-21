MODULE := engines/virtualcinema

MODULE_OBJS = \
    roland/roland.o \
    roland/rintro.o \
    roland/rmenu.o \
    x-files/agrippa.o \
    x-files/game.o \
    x-files/intro.o \
    x-files/menu.o \
    core/image.o \
    core/scene.o \
    core/vcengine.o \
    core/video.o \
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
