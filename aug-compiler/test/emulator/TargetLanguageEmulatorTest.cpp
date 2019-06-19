#include <iostream>
#include "TargetLanguageEmulatorTest.h"
#include "../../src/emulator/TargetLanguageEmulator.h"

using namespace std;

void TargetLanguageEmulatorTest::Run(){
    logger->LogInfoMessage("Target language emulator test start");
    this->TestIfCreatesObjectProperely();
    logger->LogInfoMessage("Target language emulator test finish");
}

void TargetLanguageEmulatorTest::TestIfCreatesObjectProperely(){
    logger->LogInfoMessage("Test if emulator is created successfuly");
    TargetLanguage::Emulator* emulator = new TargetLanguage::Emulator();
    delete emulator;
}

TargetLanguageEmulatorTest::TargetLanguageEmulatorTest(Logger* logger) : TestFixture(logger){

}

TargetLanguageEmulatorTest::~TargetLanguageEmulatorTest(){

}
