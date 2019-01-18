#ifndef TARGETLANGUAGEENGINETEST_H
#define TARGETLANGUAGEENGINETEST_H

#include "../TestFixture.h"

class TargetLanguageEngineTest: public TestFixture{
    public:
        TargetLanguageEngineTest();
        virtual void Run();
        virtual ~TargetLanguageEngineTest();
    private:
        void TestIfCreatesObjectProperely();
};

#endif