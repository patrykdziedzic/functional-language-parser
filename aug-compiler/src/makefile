CC=g++
CFLAGS=-std=c++11 -g -Wall -pedantic
OUT_DIR=./../out ./../out/test

main.cpp:
	flex -o ./main.cpp ./main.l

.PHONY: test-output-dir output-dir

output-dir:
	mkdir -p ./../out

test-output-dir:
	mkdir -p ./../out/test

build: main.cpp output-dir
	$(CC) -o ./../out/parser.o ./main.cpp $(CFLAGS)

test-build: test-output-dir
	$(CC) -o ./../out/test/test.o ./../test/TestFixture.cpp ./../test/emulator/TargetLanguageEmulatorTest.cpp ./../test/emulator/ProgramMemoryTest.cpp ./emulator/TargetLanguageEmulator.cpp ./emulator/ProgramMemory.cpp ./../test/test.cpp $(CFLAGS)

test-run: test-build
	./../out/test/test.o

.PHONY: clean
clean:
	rm -f -r ./../out/* && rm -f ./main.cpp
