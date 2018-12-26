CC=g++
CFLAGS=-std=c++11 -g -Wall -pedantic

main.cpp:
	flex -o ./main.cpp ./main.l

build: main.cpp
	$(CC) -o ./../out/parser.o ./main.cpp $(CFLAGS)

test-build:
	$(CC) -o ./../out/test/test.o ./../test/test.cpp

test-run: test-build
	./../out/test/test.o

.PHONY: clean
clean:
	rm -f ./../out/*.o && rm -f ./main.cpp