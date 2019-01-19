#ifndef TARGETLANGUAGEENGINETEST_H
#define TARGETLANGUAGEENGINETEST_H

#include "../TestFixture.h"
#include "../../src/emulator/TargetLanguageEngine.h"
#include <functional>
#include <vector>

class TargetLanguageEngineTest: public TestFixture{
    public:
        TargetLanguageEngineTest();
        virtual void Run();
        virtual ~TargetLanguageEngineTest();
    private:
        void TestIfCreatesObjectProperely();
        void TestIfPushesToStack();
        void TestIfPopsFromStackProperValue();
        void TestIfStackDuplicatesTopValue();
        void TestIfStackReducesElementsAfterPop();
        void TestIfReadsValue();
        void TestIfReadsManyValues();
        void TestIfPrintsValue();
        void TestIfPrintingPopsValueFromStack();
        void TestIfPrintsManyValues();
        void TestIfNegatesValue();
        void TestIfNegationPopsPreviousValue();
        void TestIfAddsValues();
        void TestIfAddingPopsArguments();
        void TestIfMultipliesValues();
        void TestIfMultiplicationPopsArguments();
        void TestIfDividiesValues();
        void TestIfDivisionPopsArguments();
        void TestIfDividiesToFloorResult();
        void TestIfPushesProperValueFromAddress();
        void TestIfAddressValueRemainsSameAfterPushing();
        void TestIfPopsProperValueToAddress();
        void TestIfStackReducesAfterPoppingToAddress();
        void TestWithInitialStack(std::vector<NUMERIC>, std::function<void(TargetLanguage::Engine*)>);
        void TestWithInitialMemory(std::vector<NUMERIC>, std::function<void(TargetLanguage::Engine*)>);
};

#endif