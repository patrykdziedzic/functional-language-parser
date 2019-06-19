#ifndef ITARGETLANGUAGEENGINE_H
#define ITARGETLANGUAGEENGINE_H

#define NUMERIC signed long long
#include <vector>

class TargetLanguageEngineTest;

namespace TargetLanguage{
    class IEngine{
        public:
            virtual void PushFromAddress(NUMERIC address) = 0;
            virtual void PushValue(NUMERIC value) = 0;
            virtual void PopToAddress(NUMERIC address) = 0;
            virtual void CopyAsInitialMemory(std::vector<NUMERIC>* initialMemory) = 0;
            virtual NUMERIC Pop() = 0;
            virtual void Duplicate() = 0;
            virtual void Add() = 0;
            virtual void Negate() = 0;
            virtual void Multiply() = 0;
            virtual void Divide() = 0;
            virtual void Read() = 0;
            virtual void Print() = 0;
            virtual ~IEngine() {}
    };
}

#endif