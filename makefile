CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR= ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: Sudoku run clean

Sudoku:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./Sudoku

clean:
	rm Sudoku

