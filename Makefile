#
# Makefile
# 
# HANGMAN TERMINALISED!
# Copyright (c) 2015
# Khaled Mohammad <itskhaledmohammad@gmail.com> (twitter: @itskhaledmd)
# All Rights Reserved.
#


# Compiler to use.
CC = gcc

# -std=c99 turns on the support for c99 standard.
CFLAGS = -std=c99

# Name for the executable file.
EXE = hangman

# List of Headers.
HDRS = drawing.h funcs.h words.h 

# List of source files.
SRCS = main.c drawing.c funcs.c

# Automatically generated list of object files
OBJS = $(SRCS:.c=.o)


# default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)

# dependencies 
$(OBJS): $(HDRS) Makefile

# Cleaning up...
clean:
	rm -f core $(EXE) *.o

