# Makefile "Lapse"
#
# Created by Romain Delmotte on 2011-08-25.
# Copyright (c) 2011. All rights reserved.
#
CC = gcc
SRC = src/main.c src/stat.c src/lastlog.c
OUTNAME = lapse

all:
	$(CC) $(SRC) -o $(OUTNAME)
