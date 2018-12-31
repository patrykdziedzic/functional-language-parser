#ifndef TARGETLANGUAGEEMULATOR_H
#define TARGETLANGUAGEEMULATOR_H

#define NUMERIC signed long long
#include <stack>
#include <vector>
#include <string>

namespace TargetLanguage{
    class Emulator{
        public:
            std::stack<NUMERIC>* memoryStack;
            Emulator();
            ~Emulator();
        private:
            std::vector<std::string>* programMemory;
    };
}

#endif