#include "Logger.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

void Logger::LogDebugMessage(const string message){
    if(DEBUG)
        LogMessageWithPrefix(message, "DEBUG");
}

void Logger::LogInfoMessage(const string message){
    LogMessageWithPrefix(message, "INFO");
}

void Logger::LogErrorMessage(const string message){
    LogMessageWithPrefix(message, "ERROR");
}

string Logger::GetCurrentDateTime(){
    time_t t = time(0);
    tm* currentTime = localtime(&t);
    string formattedTime = FormatDateTime(currentTime);
    return formattedTime;
}

string Logger::FormatDateTime(tm* timeArgument){
    char formattedTime[24];
    strftime(formattedTime, sizeof(formattedTime), "%Y-%m-%d %H:%M:%S", timeArgument);
    return string(formattedTime);
}

void Logger::LogMessageWithPrefix(const std::string message, const std::string prefix){
    cout << "[" << GetCurrentDateTime() <<"] [" << prefix << "] : " << message << endl;
}