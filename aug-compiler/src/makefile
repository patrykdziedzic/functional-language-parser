CC=gcc
CFLAGS=-lstdc++

main.cpp:
	flex -o ./main.cpp ./main.l

build: main.cpp
	$(CC) -o ./../out/parser.o ./main.cpp $(CFLAGS)

.PHONY: clean
clean:
	rm -f ./../out/*.o && rm -f ./main.cpp