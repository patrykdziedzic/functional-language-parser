#ifndef TARGETLANGUAGEEMULATOR_H
#define TARGETLANGUAGEEMULATOR_H

#define NUMERIC signed long long
#include <stack>

namespace TargetLanguage{
    class Emulator{
        public:
            std::stack<NUMERIC>* memoryStack;
            Emulator();
            ~Emulator();
    };
}

#endif