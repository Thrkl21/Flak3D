# Makefile to compile and run project

CC = clang
CFLAGS = -g -Wall
SDLINCLUDE = /opt/homebrew/Cellar/sdl2/2.28.5/include/SDL2
SDLLIB = /opt/homebrew/Cellar/sdl2/2.28.5/lib
SDLFLAGS = -I$(SDLINCLUDE) -L$(SDLLIB) -lSDL2


all: run

run: build/main
	./build/main

build/main: src/F3D_main.c src/F3D_init.c src/F3D_input.c src/F3D_draw.c
	$(CC) $(CFLAGS)  $(SDLFLAGS) -o build/main src/F3D_main.c src/F3D_init.c src/F3D_input.c src/F3D_draw.c

.PHONY: clean

clean:
	rm -rf build/*