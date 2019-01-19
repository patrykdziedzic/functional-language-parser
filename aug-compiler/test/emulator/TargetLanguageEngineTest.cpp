#include <iostream>
#include "TargetLanguageEngineTest.h"
#include <sstream>

using namespace std;
using namespace TargetLanguage;

void TargetLanguageEngineTest::Run(){
    cout << "Target language engine test start" << endl;
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
    cout << "Target language engine test finish" << endl;
}

void TargetLanguageEngineTest::TestIfCreatesObjectProperely(){
    cout << "Test if engine is created successfuly" << endl;
    TargetLanguage::Engine* engine = new TargetLanguage::Engine();
    delete engine;
}

void TargetLanguageEngineTest::TestIfPushesToStack(){
    cout << "Test if engine pushes to stack properely" << endl;
    TargetLanguage::Engine* engine = new TargetLanguage::Engine();
    engine->PushValue(1);
    AssertIsTrue(engine->memoryStack->top() == 1);
    delete engine;
}

void TargetLanguageEngineTest::TestIfPopsFromStackProperValue(){
    cout << "Test if engine pops proper value from stack" << endl;
    function<void(Engine*)> testFunction = [&](Engine* engine){
        AssertIsTrue(engine->Pop() == 1);
    };
    TestWithInitialStack({1}, testFunction);
}

void TargetLanguageEngineTest::TestIfStackReducesElementsAfterPop(){
    cout << "Test if engine reduces stack after pop" << endl;
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Pop();
        engine->Pop();
        AssertIsTrue(engine->memoryStack->size() == 1);
    };
    TestWithInitialStack({1, 1, 1}, testFunction);
}

void TargetLanguageEngineTest::TestIfStackDuplicatesTopValue(){
    cout << "Test if stack duplicates top value" << endl;
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
    cout << "Test a value is read from input stream to memory stack" << endl;
    istringstream inputStream("10\n");
    TargetLanguage::Engine* engine = new TargetLanguage::Engine(&inputStream, &cout);
    engine->Read();
    AssertIsTrue(engine->memoryStack->top() == 10);
    delete engine;
}

void TargetLanguageEngineTest::TestIfReadsManyValues(){
    cout << "Test if many values are read from input stream to memory stack" << endl;
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
    cout << "Test if value is printed from memory stack to output stream" << endl;
    function<void(Engine*)> testFunction = [&](Engine* engine){
        ostringstream outputStream;
        engine->output = &outputStream;
        engine->Print();
        AssertIsTrue(outputStream.str() == "3\n");
    };
    TestWithInitialStack({3}, testFunction);
}

void TargetLanguageEngineTest::TestIfPrintingPopsValueFromStack(){
    cout << "Test if printing pops a value from the stack" << endl;
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
    cout << "Test if prints many values" << endl;
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
    cout << "Test if negates value" << endl;
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Negate();
        AssertIsTrue(engine->memoryStack->top() == -5);
    };
    TestWithInitialStack({5}, testFunction);
}

void TargetLanguageEngineTest::TestIfNegationPopsPreviousValue(){
    cout << "Test if negation pops previous value" << endl;
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Negate();
        engine->memoryStack->pop();
        AssertIsTrue(engine->memoryStack->top() == 5);
    };
    TestWithInitialStack({5, 10}, testFunction);
}

void TargetLanguageEngineTest::TestIfAddsValues(){
    cout << "Test if adds values" << endl;
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Add();
        AssertIsTrue(engine->memoryStack->top() == 13);
    };
    TestWithInitialStack({2, 5, 8}, testFunction);
}

void TargetLanguageEngineTest::TestIfAddingPopsArguments(){
    cout << "Test if adding pops arguments" << endl;
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Add();
        engine->memoryStack->pop();
        AssertIsTrue(engine->memoryStack->top() == 5);
    };
    TestWithInitialStack({5, 8, 2}, testFunction);
}

void TargetLanguageEngineTest::TestIfMultipliesValues(){
    cout << "Test if multiplies values" << endl;
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Mulitply();
        AssertIsTrue(engine->memoryStack->top() == 40);
    };
    TestWithInitialStack({5, 8}, testFunction);
}

void TargetLanguageEngineTest::TestIfMultiplicationPopsArguments(){
    cout << "Test if muliplication pops arguments" << endl;
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Mulitply();
        engine->memoryStack->pop();
        AssertIsTrue(engine->memoryStack->top() == 5);
    };
    TestWithInitialStack({5, 8, 2}, testFunction);
}

void TargetLanguageEngineTest::TestIfDividiesValues(){
    cout << "Test if dividies values" << endl;
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Divide();
        AssertIsTrue(engine->memoryStack->top() == 3);
    };
    TestWithInitialStack({12, 4}, testFunction);
}

void TargetLanguageEngineTest::TestIfDividiesToFloorResult(){
    cout << "Test if division results in floor integer" << endl;
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Divide();
        AssertIsTrue(engine->memoryStack->top() == 3);
    };
    TestWithInitialStack({15, 4}, testFunction);
}

void TargetLanguageEngineTest::TestIfDivisionPopsArguments(){
    cout << "Test if muliplication pops arguments" << endl;
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->Divide();
        engine->memoryStack->pop();
        AssertIsTrue(engine->memoryStack->top() == 5);
    };
    TestWithInitialStack({5, 8, 2}, testFunction);
}

void TargetLanguageEngineTest::TestIfPushesProperValueFromAddress(){
    cout << "Test if pushes proper value from address" << endl;
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->PushFromAddress(1);
        AssertIsTrue(engine->memoryStack->top() == 8);
    };
    TestWithInitialMemory({5, 8, 2}, testFunction);
}

void TargetLanguageEngineTest::TestIfAddressValueRemainsSameAfterPushing(){
    cout << "Test if address remains same after pushing" << endl;
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->PushFromAddress(1);
        AssertIsTrue(engine->operationalMemory->at(1) == 8);
    };
    TestWithInitialMemory({5, 8, 2}, testFunction);
}

void TargetLanguageEngineTest::TestIfPopsProperValueToAddress(){
    cout << "Test if pops proper value to address" << endl;
    function<void(Engine*)> testFunction = [&](Engine* engine){
        engine->PushValue(21);
        engine->PopToAddress(2);
        AssertIsTrue(engine->operationalMemory->at(2) == 21);
    };
    TestWithInitialMemory({5, 8, 2}, testFunction);
}

void TargetLanguageEngineTest::TestIfStackReducesAfterPoppingToAddress(){
    cout << "Test if stack reduces after poping to address" << endl;
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

TargetLanguageEngineTest::TargetLanguageEngineTest() {}

TargetLanguageEngineTest::~TargetLanguageEngineTest() {}
