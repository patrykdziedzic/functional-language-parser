#ifndef TESTFIXTURE_H
#define TESTFIXTURE_H

class TestFixture{
    public:
        virtual void Run() = 0;
        void AssertIsTrue(bool expression);
        virtual ~TestFixture() {}
};

#endif