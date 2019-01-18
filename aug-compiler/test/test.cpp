#include <iostream>
#include "TestFixture.h"
#include "emulator/TargetLanguageEmulatorTest.h"
#include "emulator/ProgramMemoryTest.h"
#include "emulator/TargetLanguageEngineTest.h"

using namespace std;

int main(int argc, char *argv[])
{
    TestFixture* targetLanguageEmulatorFixture = new TargetLanguageEmulatorTest();
    TestFixture* programMemoryFixture = new ProgramMemoryTest();
    TestFixture* targetLanguageEngineFixture = new TargetLanguageEngineTest();

    cout << "Starting unit tests" << endl;
    targetLanguageEmulatorFixture->Run();
    programMemoryFixture->Run();
    targetLanguageEngineFixture->Run();
    
    delete targetLanguageEmulatorFixture;
    delete programMemoryFixture;
    delete targetLanguageEngineFixture;
    return 0;
}
