CC=gcc
CFLAGS=-I

scanmake: scanline.c
	$(CC) -o scanline.o scanline.c sorting.c edge_data_structs.c -lSDL2 -lm
