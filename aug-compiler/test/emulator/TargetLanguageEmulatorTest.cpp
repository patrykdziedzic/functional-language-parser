#include <iostream>
#include "TargetLanguageEmulatorTest.h"
#include "../../src/emulator/TargetLanguageEmulator.h"

using namespace std;

void TargetLanguageEmulatorTest::Run(){
    cout << "Target language emulator test start" << endl;
    this->TestIfCreatesObjectProperely();
    cout << "Target language emulator test finish" << endl;
}

void TargetLanguageEmulatorTest::TestIfCreatesObjectProperely(){
    cout << "Test if emulator is created successfuly" << endl;
    TargetLanguage::Emulator* emulator = new TargetLanguage::Emulator();
    delete emulator;
}

TargetLanguageEmulatorTest::TargetLanguageEmulatorTest(){

}

TargetLanguageEmulatorTest::~TargetLanguageEmulatorTest(){

}