#ifndef PROGRAMMEMORYTEST_H
#define PROGRAMMEMORYTEST_H

#include "../TestFixture.h"

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
};

#endif
