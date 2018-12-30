#include "TargetLanguageEmulator.h"
#include <stack>

namespace TargetLanguage{
    Emulator::Emulator(){
        this->memoryStack = new std::stack<NUMERIC>();
    }

    Emulator::~Emulator(){
        delete this->memoryStack;
    }
}

