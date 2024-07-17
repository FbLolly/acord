CC=gcc
CFLAGS=-Wall -Wextra
LDFLAGS=`pkg-config --libs raylib`

SRC=$(wildcard src/*.c)
OBJ=$(patsubst %.c,build/%.o,$(SRC))

all: $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o acord $(LDFLAGS)
	@echo "acord"

build/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $< -c $(CFLAGS)
	@echo $@

clean:
	@rm -rf acord build/
	@echo "clean"
