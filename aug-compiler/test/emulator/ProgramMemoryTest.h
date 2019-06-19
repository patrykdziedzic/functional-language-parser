#ifndef PROGRAMMEMORYTEST_H
#define PROGRAMMEMORYTEST_H

#include "../TestFixture.h"
#include "../../src/emulator/ProgramMemory.h"
#include <string>
#include <functional>

using namespace TargetLanguage;

class ProgramMemoryTest: public TestFixture{
    public:
        ProgramMemoryTest(Logger* logger);
        virtual void Run();
        virtual ~ProgramMemoryTest();
    private:
        void TestIfCreatesObjectProperely();
        void TestIfCreatesObjectWithEmptyInput();
        void TestIfEmptyInputReturnsZeroLength();
        void TestIfLengthIsCorrectForOneLine();
        void TestIfLinesCountIsCorrectForEmptyInput();
        void TestIfLinesCountIsCorrectForOneLine();
        void TestIfLinesMappingIsCorrectForOneLine();
        void TestIfLinesMappingIsCorrectForTwoLines();
        ProgramMemory* CreateProgramMemory(std::string input);
        void TestProgramSizeForBigProgramFile();
        void TestLinesCountForBigProgramFile();
        void TestWithProgramFile(std::string programFilePath, std::function<void(ProgramMemory*)> test);
};

#endif
