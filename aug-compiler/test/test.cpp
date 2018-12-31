#include <iostream>
#include "TestFixture.h"
#include "emulator/TargetLanguageEmulatorTest.h"
#include "emulator/ProgramMemoryTest.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Starting unit tests" << endl;
    TestFixture* targetLanguageEmulatorFixture = new TargetLanguageEmulatorTest();
    TestFixture* programMemoryFixture = new ProgramMemoryTest();

    targetLanguageEmulatorFixture->Run();
    programMemoryFixture->Run();

    delete targetLanguageEmulatorFixture;
    delete programMemoryFixture;
    return 0;
}
