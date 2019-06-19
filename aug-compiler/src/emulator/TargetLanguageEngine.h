#ifndef TARGETLANGUAGEENGINE_H
#define TARGETLANGUAGEENGINE_H

#include "ITargetLanguageEngine.h"
#include <stack>
#include <string>
#include <istream>
#include <ostream>

namespace TargetLanguage{
    class Engine : public IEngine{
        public:
            friend TargetLanguageEngineTest;
            Engine();
            Engine(std::istream* input, std::ostream* output);
            Engine(std::vector<NUMERIC>* initialMemory);
            Engine(std::vector<NUMERIC>* initialMemory, std::istream* input, std::ostream* output);
            virtual void PushFromAddress(NUMERIC address);
            virtual void PushValue(NUMERIC value);
            virtual void PopToAddress(NUMERIC address);
            virtual void CopyAsInitialMemory(std::vector<NUMERIC>* initialMemory);
            virtual NUMERIC Pop();
            virtual void Duplicate();
            virtual void Add();
            virtual void Negate();
            virtual void Multiply();
            virtual void Divide();
            virtual void Read();
            virtual void Print();
            virtual ~Engine();
        private:
            std::vector<NUMERIC>* operationalMemory;
            std::stack<NUMERIC>* memoryStack;
            std::istream* input;
            std::ostream* output;
    };
}

#endif