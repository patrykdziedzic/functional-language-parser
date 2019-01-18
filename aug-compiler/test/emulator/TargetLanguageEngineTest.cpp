#include <iostream>
#include "TargetLanguageEngineTest.h"
#include "../../src/emulator/TargetLanguageEngine.h"

using namespace std;

void TargetLanguageEngineTest::Run(){
    cout << "Target language engine test start" << endl;
    this->TestIfCreatesObjectProperely();
    cout << "Target language engine test finish" << endl;
}

void TargetLanguageEngineTest::TestIfCreatesObjectProperely(){
    cout << "Test if emulator is created successfuly" << endl;
    TargetLanguage::Engine* engine = new TargetLanguage::Engine();
    delete engine;
}

TargetLanguageEngineTest::TargetLanguageEngineTest(){

}

TargetLanguageEngineTest::~TargetLanguageEngineTest(){

}
