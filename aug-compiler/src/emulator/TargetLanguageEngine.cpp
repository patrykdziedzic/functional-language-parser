#include <iostream>
#include "TargetLanguageEngine.h"
using namespace std;

namespace TargetLanguage{
    Engine::Engine() : Engine(&cin, &cout) { }

    Engine::Engine(istream* input, ostream* output) : Engine(nullptr, input, output) { }

    Engine::Engine(std::vector<NUMERIC>* initialMemory) :
        Engine(initialMemory, &cin, &cout) { }

    Engine::Engine(std::vector<NUMERIC>* initialMemory, istream* input, ostream* output){
        this->input = input;
        this->output = output;
        this->operationalMemory = initialMemory;
        this->memoryStack = new stack<NUMERIC>();
    }

    void Engine::PushFromAddress(NUMERIC address){
        PushValue(operationalMemory->at(address));
    }

    void Engine::PushValue(NUMERIC value){
        this->memoryStack->push(value);
    }

    void Engine::PopToAddress(NUMERIC address){
        operationalMemory->at(address) = Pop();
    }

    NUMERIC Engine::Pop(){
        NUMERIC result = memoryStack->top();
        memoryStack->pop();
        return result;
    }

    void Engine::Duplicate(){
        NUMERIC valueToPush = memoryStack->top();
        PushValue(valueToPush);
    }

    void Engine::Add(){
        NUMERIC arg1 = Pop();
        NUMERIC arg2 = Pop();
        PushValue(arg1 + arg2);
    }

    void Engine::Negate(){
        NUMERIC arg = Pop();
        PushValue(-arg);
    }

    void Engine::Mulitply(){
        NUMERIC arg1 = Pop();
        NUMERIC arg2 = Pop();
        PushValue(arg1 * arg2);
    }

    void Engine::Divide(){
        NUMERIC arg1 = Pop();
        NUMERIC arg2 = Pop();
        PushValue(arg2 / arg1);
    }

    void Engine::Read(){
        NUMERIC arg;
        *input >> arg;
        memoryStack->push(arg);
    }

    void Engine::Print(){
        *output << Pop() << endl;
    }
    
    Engine::~Engine(){
        delete this->memoryStack;
    }
}
