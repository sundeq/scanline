CC=gcc
CFLAGS=-I

scanmake: scanline.c
	$(CC) -o scanline.o scanline.c -lSDL2 -lm
