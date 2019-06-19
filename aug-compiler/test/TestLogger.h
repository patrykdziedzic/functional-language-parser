#include "../src/ApplicationLogger.h"
#include <string>

class TestLogger : public ApplicationLogger{
    virtual void LogDebugMessage(const std::string message);
};