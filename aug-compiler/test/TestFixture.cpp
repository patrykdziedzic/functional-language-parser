#include <iostream>
#include <stdexcept>
#include "TestFixture.h"

using namespace std;

TestFixture::TestFixture(Logger* logger){
    this->logger = logger;
}

void TestFixture::AssertIsTrue(bool expression){
    if(!expression)
        throw exception();
}