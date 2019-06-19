#include "TargetLanguageEngineTest.h"
#include <sstream>
#include <iostream>

using namespace std;
using namespace TargetLanguage;

void TargetLanguageEngineTest::Run(){
    logger->LogInfoMessage("Target language engine test start");
    TestIfCreatesObjectProperely();
    TestIfPushesToStack();
    TestIfPopsFromStackProperValue();
    TestIfStackReducesElementsAfterPop();
    TestIfStackDuplicatesTopValue();
    TestIfReadsValue();
    TestIfReadsManyValues();
    TestIfPrintsValue();
    TestIfPrintingPopsValueFromStack();
    TestIfPrintsManyValues();
    TestIfNegatesValue();
    TestIfNegationPopsPreviousValue();
    TestIfAddsValues();
    TestIfAddingPopsArguments();
    TestIfMultipliesValues();
    TestIfMultiplicationPopsArguments();
    TestIfDividiesValues();
    TestIfDivisionPopsArguments();
    TestIfDividiesToFloorResult();
    TestIfPushesProperValueFromAddress();
    TestIfAddressValueRemainsSameAfterPushing();
    TestIfPopsProperValueToAddress();
    TestIfStackReducesAfterPoppingToAddress();
    logger->LogInfoMessage("Target language engine test finish");
}

void TargetLanguageEngineTest::TestIfCreatesObjectProperely(){
    logger->LogInfoMessage("Test if engine is created successfuly");
    TargetLanguage::Engine* engine = new TargetLanguage::Engine();
    delete engine;
}

void TargetLanguageEngineTest::TestIfPushesToStack(){
    logger->LogInfoMessage("Test if engine pushes to stack properely");
    TargetLanguage::Engine* engine = new TargetLanguage::Engine();
    engine->PushValue(1);
    AssertIsTrue(engine->memoryStack->top() == 1);
    delete engine;
}

void TargetLanguageEngineTest::TestIfPopsFromStackProperValue(){
    logger->LogInfoMessage("Test if engine pops proper value from stack");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        AssertIsTrue(engine->Pop() == 1);
    };
    TestWithInitialStack({1}, testFunction);
}

void TargetLanguageEngineTest::TestIfStackReducesElementsAfterPop(){
    logger->LogInfoMessage("Test if engine reduces stack after pop");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Pop();
        engine->Pop();
        AssertIsTrue(engine->memoryStack->size() == 1);
    };
    TestWithInitialStack({1, 1, 1}, testFunction);
}

void TargetLanguageEngineTest::TestIfStackDuplicatesTopValue(){
    logger->LogInfoMessage("Test if stack duplicates top value");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Duplicate();
        AssertIsTrue(engine->memoryStack->top() == 3);
        engine->memoryStack->pop();
        AssertIsTrue(engine->memoryStack->top() == 3);
        engine->memoryStack->pop();
        AssertIsTrue(engine->memoryStack->size() == 1);
    };
    TestWithInitialStack({1, 3}, testFunction);
}

void TargetLanguageEngineTest::TestIfReadsValue(){
    logger->LogInfoMessage("Test a value is read from input stream to memory stack");
    istringstream inputStream("10\n");
    TargetLanguage::Engine* engine = new TargetLanguage::Engine(&inputStream, &cout);
    engine->Read();
    AssertIsTrue(engine->memoryStack->top() == 10);
    delete engine;
}

void TargetLanguageEngineTest::TestIfReadsManyValues(){
    logger->LogInfoMessage("Test if many values are read from input stream to memory stack");
    istringstream inputStream("10\n5\n3\n");
    TargetLanguage::Engine* engine = new TargetLanguage::Engine(&inputStream, &cout);
    engine->Read();
    engine->Read();
    engine->Read();
    AssertIsTrue(engine->memoryStack->top() == 3);
    engine->memoryStack->pop();
    AssertIsTrue(engine->memoryStack->top() == 5);
    engine->memoryStack->pop();
    AssertIsTrue(engine->memoryStack->top() == 10);
    delete engine;
}

void TargetLanguageEngineTest::TestIfPrintsValue(){
    logger->LogInfoMessage("Test if value is printed from memory stack to output stream");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        ostringstream outputStream;
        engine->output = &outputStream;
        engine->Print();
        AssertIsTrue(outputStream.str() == "3\n");
    };
    TestWithInitialStack({3}, testFunction);
}

void TargetLanguageEngineTest::TestIfPrintingPopsValueFromStack(){
    logger->LogInfoMessage("Test if printing pops a value from the stack");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        ostringstream outputStream;
        engine->output = &outputStream;
        engine->Print();
        engine->Print();
        AssertIsTrue(engine->memoryStack->size() == 1);
    };
    TestWithInitialStack({3, 3, 3}, testFunction);
}

void TargetLanguageEngineTest::TestIfPrintsManyValues(){
    logger->LogInfoMessage("Test if prints many values");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        ostringstream outputStream;
        engine->output = &outputStream;
        engine->Print();
        engine->Print();
        engine->Print();
        AssertIsTrue(outputStream.str() == "4\n5\n3\n");
    };
    TestWithInitialStack({3, 5, 4}, testFunction);
}

void TargetLanguageEngineTest::TestIfNegatesValue(){
    logger->LogInfoMessage("Test if negates value");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Negate();
        AssertIsTrue(engine->memoryStack->top() == -5);
    };
    TestWithInitialStack({5}, testFunction);
}

void TargetLanguageEngineTest::TestIfNegationPopsPreviousValue(){
    logger->LogInfoMessage("Test if negation pops previous value");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Negate();
        engine->memoryStack->pop();
        AssertIsTrue(engine->memoryStack->top() == 5);
    };
    TestWithInitialStack({5, 10}, testFunction);
}

void TargetLanguageEngineTest::TestIfAddsValues(){
    logger->LogInfoMessage("Test if adds values");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Add();
        AssertIsTrue(engine->memoryStack->top() == 13);
    };
    TestWithInitialStack({2, 5, 8}, testFunction);
}

void TargetLanguageEngineTest::TestIfAddingPopsArguments(){
    logger->LogInfoMessage("Test if adding pops arguments");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Add();
        engine->memoryStack->pop();
        AssertIsTrue(engine->memoryStack->top() == 5);
    };
    TestWithInitialStack({5, 8, 2}, testFunction);
}

void TargetLanguageEngineTest::TestIfMultipliesValues(){
    logger->LogInfoMessage("Test if multiplies values");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Multiply();
        AssertIsTrue(engine->memoryStack->top() == 40);
    };
    TestWithInitialStack({5, 8}, testFunction);
}

void TargetLanguageEngineTest::TestIfMultiplicationPopsArguments(){
    logger->LogInfoMessage("Test if muliplication pops arguments");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Multiply();
        engine->memoryStack->pop();
        AssertIsTrue(engine->memoryStack->top() == 5);
    };
    TestWithInitialStack({5, 8, 2}, testFunction);
}

void TargetLanguageEngineTest::TestIfDividiesValues(){
    logger->LogInfoMessage("Test if dividies values");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Divide();
        AssertIsTrue(engine->memoryStack->top() == 3);
    };
    TestWithInitialStack({12, 4}, testFunction);
}

void TargetLanguageEngineTest::TestIfDividiesToFloorResult(){
    logger->LogInfoMessage("Test if division results in floor integer");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Divide();
        AssertIsTrue(engine->memoryStack->top() == 3);
    };
    TestWithInitialStack({15, 4}, testFunction);
}

void TargetLanguageEngineTest::TestIfDivisionPopsArguments(){
    logger->LogInfoMessage("Test if muliplication pops arguments");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Divide();
        engine->memoryStack->pop();
        AssertIsTrue(engine->memoryStack->top() == 5);
    };
    TestWithInitialStack({5, 8, 2}, testFunction);
}

void TargetLanguageEngineTest::TestIfPushesProperValueFromAddress(){
    logger->LogInfoMessage("Test if pushes proper value from address");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->PushFromAddress(1);
        AssertIsTrue(engine->memoryStack->top() == 8);
    };
    TestWithInitialMemory({5, 8, 2}, testFunction);
}

void TargetLanguageEngineTest::TestIfAddressValueRemainsSameAfterPushing(){
    logger->LogInfoMessage("Test if address remains same after pushing");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->PushFromAddress(1);
        AssertIsTrue(engine->operationalMemory->at(1) == 8);
    };
    TestWithInitialMemory({5, 8, 2}, testFunction);
}

void TargetLanguageEngineTest::TestIfPopsProperValueToAddress(){
    logger->LogInfoMessage("Test if pops proper value to address");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->PushValue(21);
        engine->PopToAddress(2);
        AssertIsTrue(engine->operationalMemory->at(2) == 21);
    };
    TestWithInitialMemory({5, 8, 2}, testFunction);
}

void TargetLanguageEngineTest::TestIfStackReducesAfterPoppingToAddress(){
    logger->LogInfoMessage("Test if stack reduces after poping to address");
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->PushValue(1);
        engine->PushValue(1);
        engine->PopToAddress(2);
        AssertIsTrue(engine->memoryStack->size() == 1);
    };
    TestWithInitialMemory({5, 8, 2}, testFunction);
}

void TargetLanguageEngineTest::TestWithInitialStack(
    vector<NUMERIC> initialStack,
    function<void(Engine*)> test
){
    Engine* engine = new Engine();
    for(NUMERIC& argument: initialStack) {
        engine->memoryStack->push(argument);
    }
    test(engine);
    delete engine;
}

void TargetLanguageEngineTest::TestWithInitialMemory(
    vector<NUMERIC> initialMemory,
    function<void(Engine*)> test
){
    Engine* engine = new Engine(&initialMemory);
    test(engine);
    delete engine;
}

TargetLanguageEngineTest::TargetLanguageEngineTest(Logger* logger) : TestFixture(logger) {}

TargetLanguageEngineTest::~TargetLanguageEngineTest() {}
