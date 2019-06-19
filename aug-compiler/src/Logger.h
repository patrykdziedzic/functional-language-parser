#ifndef LOGGER_H
#define LOGGER_H

#define DEBUG false

#include <string>
#include "Logger.h"

class Logger{
    public:
        void LogDebugMessage(const std::string message);
        void LogErrorMessage(const std::string message);
        void LogInfoMessage(const std::string message);
    protected:
        void LogMessageWithPrefix(const std::string message, const std::string prefix);
    private:
        std::string FormatDateTime(tm* timeArgument);
        std::string GetCurrentDateTime();
};

#endif