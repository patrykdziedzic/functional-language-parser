#include <iostream>
#include <sstream>
#include <fstream>
#include "ProgramMemoryTest.h"

void ProgramMemoryTest::Run(){
    cout << "Program memory test start" << endl;
    TestIfCreatesObjectProperely();
    TestIfCreatesObjectWithEmptyInput();
    TestIfEmptyInputReturnsZeroLength();
    TestIfLengthIsCorrectForOneLine();
    TestIfLinesCountIsCorrectForEmptyInput();
    TestIfLinesCountIsCorrectForOneLine();
    TestIfLinesMappingIsCorrectForOneLine();
    TestIfLinesMappingIsCorrectForTwoLines();
    TestProgramSizeForBigProgramFile();
    TestLinesCountForBigProgramFile();
    cout << "Program memory test finish" << endl;
}

void ProgramMemoryTest::TestIfCreatesObjectProperely(){
    cout << "Test if program memory is created successfuly" << endl;
    ProgramMemory* programMemory = CreateProgramMemory("TEST\n");
    delete programMemory;
}

void ProgramMemoryTest::TestIfCreatesObjectWithEmptyInput(){
    cout << "Test if program memory is created successfuly with empty input" << endl;
    ProgramMemory* programMemory = CreateProgramMemory("");
    delete programMemory;
}

void ProgramMemoryTest::TestIfEmptyInputReturnsZeroLength(){
    cout << "Test if program memory created with empty input returns zero length" << endl;
    ProgramMemory* programMemory = CreateProgramMemory("");
    AssertIsTrue(programMemory->GetProgramLength() == 0);
    delete programMemory;
}

void ProgramMemoryTest::TestIfLengthIsCorrectForOneLine(){
    cout << "Test if program length is correct for a one line input" << endl;
    ProgramMemory* programMemory = CreateProgramMemory("TEST\n");
    AssertIsTrue(programMemory->GetProgramLength() == 5);
    delete programMemory;
}

void ProgramMemoryTest::TestIfLinesCountIsCorrectForEmptyInput(){
    cout << "Test if lines count is correct for empty input" << endl;
    ProgramMemory* programMemory = CreateProgramMemory("");
    AssertIsTrue(programMemory->GetLinesCount() == 0);
    delete programMemory;
}

void ProgramMemoryTest::TestIfLinesCountIsCorrectForOneLine(){
    cout << "Test if lines count is correct for a one line input" << endl;
    ProgramMemory* programMemory = CreateProgramMemory("TEST\n");
    AssertIsTrue(programMemory->GetLinesCount() == 1);
    delete programMemory;
}

void ProgramMemoryTest::TestIfLinesMappingIsCorrectForOneLine(){
    cout << "Test if lines mapping is correct for a one line input" << endl;
    ProgramMemory* programMemory = CreateProgramMemory("TEST\n");
    string textOnLineZero(programMemory->GetPosition(0));
    AssertIsTrue(textOnLineZero == "TEST\n");
    delete programMemory;
}

void ProgramMemoryTest::TestIfLinesMappingIsCorrectForTwoLines(){
    cout << "Test if lines mapping is correct for a two lines input" << endl;
    ProgramMemory* programMemory = CreateProgramMemory("TEST1\nTEST2\n");
    string textOnSecondLine(programMemory->GetPosition(1));
    AssertIsTrue(textOnSecondLine == "TEST2\n");
    delete programMemory;
}

ProgramMemory* ProgramMemoryTest::CreateProgramMemory(string input){
    istringstream iss(input);
    return new ProgramMemory(&iss);
}

void ProgramMemoryTest::TestProgramSizeForBigProgramFile(){
    cout << "Test calculating program size for a big program file" << endl;
    function<void(ProgramMemory*)> testFunction = [&](ProgramMemory* programMemory){
        AssertIsTrue(programMemory->GetProgramLength() == 5009);
    };

    TestWithProgramFile("./../test/data/program-memory-test1.txt", testFunction);
}

void ProgramMemoryTest::TestLinesCountForBigProgramFile(){
    cout << "Test calculating lines count for a big program file" << endl;
    function<void(ProgramMemory*)> testFunction = [&](ProgramMemory* programMemory){
        AssertIsTrue(programMemory->GetLinesCount() == 9);
    };

    TestWithProgramFile("./../test/data/program-memory-test1.txt", testFunction);
}

void ProgramMemoryTest::TestWithProgramFile(string programFilePath, function<void(ProgramMemory*)> test){
    ifstream testFile;
    testFile.open(programFilePath);
    ProgramMemory* programMemory = new ProgramMemory(&testFile);
    test(programMemory);
    testFile.close();
    delete programMemory;
}

ProgramMemoryTest::ProgramMemoryTest(){
    
}

ProgramMemoryTest::~ProgramMemoryTest(){

}
