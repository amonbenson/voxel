INCLUDE_DIR = include
SRC_DIR = src

cflags += -I$(INCLUDE_DIR)
cflags += -std=c99
cflags += -Wall -Wextra

lib.name = voxel~
class.sources = $(addprefix $(SRC_DIR)/, voxel~.c)
common.sources = $(addprefix $(SRC_DIR)/, vocaldetector.c)
datafiles = voxel~.pd

# use pd-lib-builder
include pd-lib-builder/Makefile.pdlibbuilder
