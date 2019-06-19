#ifndef TARGETLANGUAGEEMULATORTEST_H
#define TARGETLANGUAGEEMULATORTEST_H

#include "../TestFixture.h"

class TargetLanguageEmulatorTest: public TestFixture{
    public:
        TargetLanguageEmulatorTest(Logger* logger);
        virtual void Run();
        virtual ~TargetLanguageEmulatorTest();
    private:
        void TestIfCreatesObjectProperely();
};

#endif