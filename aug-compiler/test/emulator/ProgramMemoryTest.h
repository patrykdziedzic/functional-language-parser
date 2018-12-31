#ifndef PROGRAMMEMORYTEST_H
#define PROGRAMMEMORYTEST_H

#include "../TestFixture.h"
#include "../../src/emulator/ProgramMemory.h"
#include <string>

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
};

#endif
