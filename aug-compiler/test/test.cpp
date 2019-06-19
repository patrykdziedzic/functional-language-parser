#include <iostream>
#include "TestFixture.h"
#include "emulator/TargetLanguageEmulatorTest.h"
#include "emulator/ProgramMemoryTest.h"
#include "emulator/TargetLanguageEngineTest.h"
#include "emulator/TargetLanguageParserTest.h"

using namespace std;

int main(int argc, char *argv[])
{
    Logger* logger = new Logger();
    TestFixture* targetLanguageEmulatorFixture = new TargetLanguageEmulatorTest(logger);
    TestFixture* programMemoryFixture = new ProgramMemoryTest(logger);
    TestFixture* targetLanguageEngineFixture = new TargetLanguageEngineTest(logger);
    TestFixture* parserFixture = new TargetLanguageParserTest(logger);

    logger->LogInfoMessage("Starting unit tests");
    targetLanguageEmulatorFixture->Run();
    programMemoryFixture->Run();
    targetLanguageEngineFixture->Run();
    parserFixture->Run();
    
    delete targetLanguageEmulatorFixture;
    delete programMemoryFixture;
    delete targetLanguageEngineFixture;
    delete parserFixture;
    delete logger;
    return 0;
}
