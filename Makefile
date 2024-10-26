##
#	This is for my DNN practice
#	OS: linux
##
CC ?= gcc
LDFLAGS = 
CFLAGS = -lsz -lz -ldl -lm 
OUTPUT_FILE = dnn
OUTPUT_DIR = output
SOURCE_DIR = src

INCLUDE_DIR = 
LIBRARY_DIR = 
HDF_STATIC_LIB = 

CURRENT_DIR:=$(shell pwd)

ifeq ($(wildcard build/hdf/output/include/hdf5.h),)
$(error HDF module is missing!\
	$(info [Error]: HDF module not found!) \
	$(info Please use `git pull --recurse-submodules` to pull the HDF module.) \
	$(info And use `make build-hdf` to build HDF module in here.) \
	$(info If you want to build with yourself. Please refer to 'https://github.com/HDFGroup/hdf5' installation guide.) \
)
else
$(info HDF module exist!)
endif

default: 
	echo hi

build-hdf:
	cd $(CURRENT_DIR)/build/hdf && ./configure --prefix=$(CURRENT_DIR)/build/hdf/output
	make -C $(CURRENT_DIR)/build/hdf
	make check -C $(CURRENT_DIR)/build/hdf
	make install -C $(CURRENT_DIR)/build/hdf
	make check-install -C $(CURRENT_DIR)/build/hdf
