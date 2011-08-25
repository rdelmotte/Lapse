# Makefile "Lapse"
#
# Created by Romain Delmotte on 2011-08-25.
# Copyright (c) 2011 LiveFyre. All rights reserved.
#

CC = gcc
SRC = src/main.c

all:
    $(CC) $(SRC) -o bin/lapse

clean:
    rm -rf bin/lapse