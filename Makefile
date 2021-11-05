
CC=cc
CFLAGS=

all: ts-endian

.PHONY: clean
clean:
	rm -fv ts-endian

ts-endian: main.c tree-sitter/lib/src/*
	${CC} -Itree-sitter/lib/include ${CFLAGS} main.c -o ts-endian
