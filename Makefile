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

default:
	#$(CC) 

SHELL:=/usr/bin/bash
build-hdf:
	$(shell cd $(CURRENT_DIR)/build/hdf && ./configure --prefix=$(CURRENT_DIR)/build/hdf/output)
	$(shell make -C $(CURRENT_DIR)/build/hdf)
	$(shell make check -C $(CURRENT_DIR)/build/hdf)
	$(shell make install -C $(CURRENT_DIR)/build/hdf)
	$(shell make check-install -C $(CURRENT_DIR)/build/hdf)

