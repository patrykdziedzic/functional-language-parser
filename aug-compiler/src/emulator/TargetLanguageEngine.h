#ifndef TARGETLANGUAGEENGINE_H
#define TARGETLANGUAGEENGINE_H

#define NUMERIC signed long long
#include <stack>
#include <vector>
#include <string>

namespace TargetLanguage{
    class Engine{
        public:
            Engine();
            Engine(std::vector<NUMERIC>);
            void PushFromAddress(NUMERIC address);
            void PushValue(NUMERIC value);
            void PopToAddress(NUMERIC address);
            NUMERIC Pop();
            void Duplicate();
            void Add();
            void Negate();
            void Mulitply();
            void Divide();
            void ReadFromStandardInput();
            void PrintToStandardOutput();
            ~Engine();
        private:
            std::vector<NUMERIC>* operationalMemory;
            std::stack<NUMERIC>* memoryStack;
    };
}

#endif