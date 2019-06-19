#include <sstream>
#include <fstream>
#include "ProgramMemoryTest.h"

using namespace std;

void ProgramMemoryTest::Run(){
    logger->LogInfoMessage("Program memory test start");
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
    logger->LogInfoMessage("Program memory test finish");
}

void ProgramMemoryTest::TestIfCreatesObjectProperely(){
    logger->LogInfoMessage("Test if program memory is created successfuly");
    ProgramMemory* programMemory = CreateProgramMemory("TEST\n");
    delete programMemory;
}

void ProgramMemoryTest::TestIfCreatesObjectWithEmptyInput(){
    logger->LogInfoMessage("Test if program memory is created successfuly with empty input");
    ProgramMemory* programMemory = CreateProgramMemory("");
    delete programMemory;
}

void ProgramMemoryTest::TestIfEmptyInputReturnsZeroLength(){
    logger->LogInfoMessage("Test if program memory created with empty input returns zero length");
    ProgramMemory* programMemory = CreateProgramMemory("");
    AssertIsTrue(programMemory->GetProgramLength() == 0);
    delete programMemory;
}

void ProgramMemoryTest::TestIfLengthIsCorrectForOneLine(){
    logger->LogInfoMessage("Test if program length is correct for a one line input");
    ProgramMemory* programMemory = CreateProgramMemory("TEST\n");
    AssertIsTrue(programMemory->GetProgramLength() == 5);
    delete programMemory;
}

void ProgramMemoryTest::TestIfLinesCountIsCorrectForEmptyInput(){
    logger->LogInfoMessage("Test if lines count is correct for empty input");
    ProgramMemory* programMemory = CreateProgramMemory("");
    AssertIsTrue(programMemory->GetLinesCount() == 0);
    delete programMemory;
}

void ProgramMemoryTest::TestIfLinesCountIsCorrectForOneLine(){
    logger->LogInfoMessage("Test if lines count is correct for a one line input");
    ProgramMemory* programMemory = CreateProgramMemory("TEST\n");
    AssertIsTrue(programMemory->GetLinesCount() == 1);
    delete programMemory;
}

void ProgramMemoryTest::TestIfLinesMappingIsCorrectForOneLine(){
    logger->LogInfoMessage("Test if lines mapping is correct for a one line input");
    ProgramMemory* programMemory = CreateProgramMemory("0 TEST\n");
    string textOnLineZero(programMemory->GetPosition(0));
    AssertIsTrue(textOnLineZero == "0 TEST\n");
    delete programMemory;
}

void ProgramMemoryTest::TestIfLinesMappingIsCorrectForTwoLines(){
    logger->LogInfoMessage("Test if lines mapping is correct for a two lines input");
    ProgramMemory* programMemory = CreateProgramMemory("0 TEST1\n1 TEST2\n");
    string textOnSecondLine(programMemory->GetPosition(1));
    this->logger->LogDebugMessage(textOnSecondLine);
    AssertIsTrue(textOnSecondLine == "1 TEST2\n");
    delete programMemory;
}

ProgramMemory* ProgramMemoryTest::CreateProgramMemory(string input){
    istringstream iss(input);
    return new ProgramMemory(&iss);
}

void ProgramMemoryTest::TestProgramSizeForBigProgramFile(){
    logger->LogInfoMessage("Test calculating program size for a big program file");
    function<void(ProgramMemory*)> testFunction = [&](ProgramMemory* programMemory){
        AssertIsTrue(programMemory->GetProgramLength() == 5009);
    };

    TestWithProgramFile("./../test/data/program-memory-test1.txt", testFunction);
}

void ProgramMemoryTest::TestLinesCountForBigProgramFile(){
    logger->LogInfoMessage("Test calculating lines count for a big program file");
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

ProgramMemoryTest::ProgramMemoryTest(Logger* logger) : TestFixture(logger){}

ProgramMemoryTest::~ProgramMemoryTest(){}
