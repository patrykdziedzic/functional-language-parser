#ifndef PROGRAMMEMORYTEST_H
#define PROGRAMMEMORYTEST_H

#include "../TestFixture.h"
#include "../../src/emulator/ProgramMemory.h"
#include <string>
#include <functional>

using namespace std;
using namespace TargetLanguage;

class ProgramMemoryTest: public TestFixture{
    public:
        ProgramMemoryTest();
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
        ProgramMemory* CreateProgramMemory(string input);
        void TestProgramSizeForBigProgramFile();
        void TestLinesCountForBigProgramFile();
        void TestWithProgramFile(string programFilePath, std::function<void(ProgramMemory*)> test);
};

#endif
