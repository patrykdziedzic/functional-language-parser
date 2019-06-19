#ifndef TESTFIXTURE_H
#define TESTFIXTURE_H

#include "./../src/Logger.h"

class TestFixture{
    public:
        TestFixture(Logger* logger);
        virtual void Run() = 0;
        void AssertIsTrue(bool expression);
        virtual ~TestFixture() {}
    protected:
        Logger* logger;
};

#endif