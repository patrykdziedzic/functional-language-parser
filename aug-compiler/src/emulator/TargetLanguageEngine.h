#ifndef TARGETLANGUAGEENGINE_H
#define TARGETLANGUAGEENGINE_H

#define NUMERIC signed long long
#include <stack>
#include <vector>
#include <string>
#include <istream>
#include <ostream>

class TargetLanguageEngineTest;

namespace TargetLanguage{
    class Engine{
        public:
            friend TargetLanguageEngineTest;
            Engine();
            Engine(std::istream* input, std::ostream* output);
            Engine(std::vector<NUMERIC>* initialMemory);
            Engine(std::vector<NUMERIC>* initialMemory, std::istream* input, std::ostream* output);
            void PushFromAddress(NUMERIC address);
            void PushValue(NUMERIC value);
            void PopToAddress(NUMERIC address);
            NUMERIC Pop();
            void Duplicate();
            void Add();
            void Negate();
            void Mulitply();
            void Divide();
            void Read();
            void Print();
            ~Engine();
        private:
            std::vector<NUMERIC>* operationalMemory;
            std::stack<NUMERIC>* memoryStack;
            std::istream* input;
            std::ostream* output;
    };
}

#endif