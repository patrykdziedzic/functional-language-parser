#include "TestLogger.h"
using namespace std;

void TestLogger::LogDebugMessage(const string message){
    LogMessageWithPrefix(message, "DEBUG");
}