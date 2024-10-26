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
	cd $(CURRENT_DIR)/build/hdf && ./configure --prefix=$(CURRENT_DIR)/build/hdf/output
	make -C $(CURRENT_DIR)/build/hdf
	make check -C $(CURRENT_DIR)/build/hdf
	make install -C $(CURRENT_DIR)/build/hdf
	make check-install -C $(CURRENT_DIR)/build/hdf

