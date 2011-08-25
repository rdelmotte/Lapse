# Makefile "Lapse"
#
# Created by Romain Delmotte on 2011-08-25.
# Copyright (c) 2011 LiveFyre. All rights reserved.
#
CC = gcc
SRC = src/main.c
OUTNAME = lapse

all:
    $(CC) $(SRC) -o $(OUTNAME)
