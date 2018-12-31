#include "TargetLanguageEmulator.h"

namespace TargetLanguage{
    Emulator::Emulator(){
        memoryStack = new std::stack<NUMERIC>();
        programMemory = new std::vector<std::string>();
    }

    Emulator::~Emulator(){
        delete memoryStack;
        delete programMemory;
    }
}

