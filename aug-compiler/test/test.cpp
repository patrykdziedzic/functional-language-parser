#include <iostream>
#include "TestFixture.h"
#include "emulator/TargetLanguageEmulatorTest.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Starting unit tests" << endl;
    TestFixture* testFixture = new TargetLanguageEmulatorTest();
    testFixture->Run();
    delete testFixture;
    return 0;
}