# logtrace/Makefile
NAME = logtrace

# Compilation settings
CC = gcc
CFLAGS = -Wall -Iinclude -std=c99

# Ensure the build directory exists
BUILDDIR ?= ./build

# Source and object files
SRC = src/$(NAME).c
OBJ = $(BUILDDIR)/$(NAME).o
LIB = $(BUILDDIR)/lib$(NAME).a


#Default target
all:  $(BUILDDIR) $(LIB)

$(BUILDDIR):
	mkdir -p $@

$(LIB): $(OBJ)
	ar rcs $@ $^

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIB)
