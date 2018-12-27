#include <iostream>
#include <stdexcept>
#include "TestFixture.h"

using namespace std;

void TestFixture::AssertIsTrue(bool expression){
    if(!expression)
        throw exception();
}