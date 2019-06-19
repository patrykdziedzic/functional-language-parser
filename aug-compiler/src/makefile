CC=g++
CFLAGS=-std=c++11 -g -Wall -pedantic
OUT_DIR=./../out ./../out/test
TEST_FIXTURES=./Logger.cpp ./../test/TestFixture.cpp ./../test/emulator/TargetLanguageEmulatorTest.cpp ./../test/emulator/ProgramMemoryTest.cpp ./../test/emulator/TargetLanguageEngineTest.cpp ./../test/emulator/TargetLanguageParserTest.cpp
CLASSES_TO_TEST=./../test/emulator/mock/TargetLanguageEngineMock.cpp ./emulator/TargetLanguageEmulatorLexer.cpp ./emulator/TargetLanguageEmulatorParser.cpp ./emulator/TargetLanguageEmulator.cpp ./emulator/ProgramMemory.cpp ./emulator/TargetLanguageEngine.cpp ./../test/test.cpp

main.cpp:
	flex -o ./main.cpp ./main.l

.PHONY: test-output-dir output-dir

output-dir:
	mkdir -p ./../out

test-output-dir:
	mkdir -p ./../out/test

build: main.cpp output-dir
	$(CC) -o ./../out/parser.o ./main.cpp $(CFLAGS)

test-build: test-output-dir target-parser-compile target-lexer-compile
	$(CC) -o ./../out/test/test.o  $(TEST_FIXTURES) $(CLASSES_TO_TEST) $(CFLAGS)

test-run: test-build
	./../out/test/test.o

target-parser-compile:
	bison -o ./emulator/TargetLanguageEmulatorParser.cpp --defines=./emulator/TargetLanguageEmulatorParser.h ./emulator/TargetLanguageEmulatorParser.y

target-lexer-compile:
	flex -o ./emulator/TargetLanguageEmulatorLexer.cpp ./emulator/TargetLanguageEmulatorLexer.l

.PHONY: clean
clean:
	rm -f -r ./../out/* && rm -f ./main.cpp
