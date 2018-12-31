#include <iostream>
#include <sstream>
#include <string> 
#include "ProgramMemoryTest.h"
#include "../../src/emulator/ProgramMemory.h"

using namespace std;
using namespace TargetLanguage;

void ProgramMemoryTest::Run(){
    cout << "Program memory test start" << endl;
    TestIfCreatesObjectProperely();
    TestIfCreatesObjectWithEmptyInput();
    TestIfEmptyInputReturnsZeroLength();
    TestIfLengthIsCorrectForOneLine();
    TestIfLinesCountIsCorrectForEmptyInput();
    TestIfLinesCountIsCorrectForOneLine();
    cout << "Program memory test finish" << endl;
}

void ProgramMemoryTest::TestIfCreatesObjectProperely(){
    cout << "Test if program memory is created successfuly" << endl;
    string programContent = "TEST\n";
    istringstream iss(programContent);
    ProgramMemory* programMemory = new ProgramMemory(&iss);
    delete programMemory;
}

void ProgramMemoryTest::TestIfCreatesObjectWithEmptyInput(){
    cout << "Test if program memory is created successfuly with empty input" << endl;
    string programContent = "";
    istringstream iss(programContent);
    ProgramMemory* programMemory = new ProgramMemory(&iss);
    delete programMemory;
}

void ProgramMemoryTest::TestIfEmptyInputReturnsZeroLength(){
    cout << "Test if program memory created with empty input returns zero length" << endl;
    string programContent = "";
    istringstream iss(programContent);
    ProgramMemory* programMemory = new ProgramMemory(&iss);
    AssertIsTrue(programMemory->GetProgramLength() == 0);
    delete programMemory;
}

void ProgramMemoryTest::TestIfLengthIsCorrectForOneLine(){
    cout << "Test if program length is correct for a one line input" << endl;
    string programContent = "TEST\n";
    istringstream iss(programContent);
    ProgramMemory* programMemory = new ProgramMemory(&iss);
    AssertIsTrue(programMemory->GetProgramLength() == 5);
    delete programMemory;
}

void ProgramMemoryTest::TestIfLinesCountIsCorrectForEmptyInput(){
    cout << "Test if lines count is correct for empty input" << endl;
    string programContent = "";
    istringstream iss(programContent);
    ProgramMemory* programMemory = new ProgramMemory(&iss);
    AssertIsTrue(programMemory->GetLinesCount() == 0);
    delete programMemory;
}

void ProgramMemoryTest::TestIfLinesCountIsCorrectForOneLine(){
    cout << "Test if lines count is correct for a one line input" << endl;
    string programContent = "TEST\n";
    istringstream iss(programContent);
    ProgramMemory* programMemory = new ProgramMemory(&iss);
    AssertIsTrue(programMemory->GetLinesCount() == 1);
    delete programMemory;
}

ProgramMemoryTest::ProgramMemoryTest(){

}

ProgramMemoryTest::~ProgramMemoryTest(){

}
