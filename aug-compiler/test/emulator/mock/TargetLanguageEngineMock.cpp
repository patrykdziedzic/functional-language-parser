#include "TargetLanguageEngineMock.h"
using namespace std;

//WARNING: In this mock only Pop method will actually pop values from inital stack

EngineMock::EngineMock(Logger* logger){
    initialStack = nullptr;
    initialMemory = new vector<NUMERIC>();
    operations = new vector<OperationResult*>();
    this->logger = logger;
}

EngineMock::EngineMock(Logger* logger, vector<NUMERIC> initialStackSequence) : EngineMock(logger){
    initialStack = new stack<NUMERIC>();
    for(NUMERIC& argument: initialStackSequence) {
        initialStack->push(argument);
    }
}

void EngineMock::PushFromAddress(NUMERIC address){
    logger->LogDebugMessage("Push from address " + to_string(address));
    OperationResult* operation = new OperationResult(
        OperationCode::PushFromAddress, address);
    operations->push_back(operation);
}

void EngineMock::PushValue(NUMERIC value){
    logger->LogDebugMessage("Push value " + to_string(value));
    OperationResult* operation = new OperationResult(
        OperationCode::PushValue, value);
    operations->push_back(operation);
}

void EngineMock::PopToAddress(NUMERIC address){
    logger->LogDebugMessage("Pop to address " + to_string(address));
    OperationResult* operation = new OperationResult(
        OperationCode::PopToAddress, address);
    operations->push_back(operation);
}

void EngineMock::CopyAsInitialMemory(std::vector<NUMERIC>* initialMemory){
    logger->LogDebugMessage("Load initial memory");
    this->initialMemory = new vector<NUMERIC>(*initialMemory);
    OperationResult* operation = new OperationResult(OperationCode::CopyAsInitialMemory);
    operations->push_back(operation);
}

NUMERIC EngineMock::Pop(){
    logger->LogDebugMessage("Pop");

    if(initialStack == nullptr || initialStack->empty()){
        SavePopOperation();
        return 0;
    }
    
    NUMERIC result = initialStack->top();
    initialStack->pop();
    SavePopOperation(result);
    return result;
}

void EngineMock::SavePopOperation(NUMERIC result){
    OperationResult* operation = new OperationResult(OperationCode::Pop, result);
    operations->push_back(operation);
}

void EngineMock::SavePopOperation(){
    OperationResult* operation = new OperationResult(OperationCode::Pop);
    operations->push_back(operation);
}

void EngineMock::Duplicate(){
    logger->LogDebugMessage("Duplicate");
    OperationResult* operation = new OperationResult(OperationCode::Duplicate);
    operations->push_back(operation);
}

void EngineMock::Add(){
    logger->LogDebugMessage("Add");
    OperationResult* operation = new OperationResult(OperationCode::Add);
    operations->push_back(operation);
}

void EngineMock::Negate(){
    logger->LogDebugMessage("Negate");
    OperationResult* operation = new OperationResult(OperationCode::Negate);
    operations->push_back(operation);
}

void EngineMock::Multiply(){
    logger->LogDebugMessage("Multiply");
    OperationResult* operation = new OperationResult(OperationCode::Multiply);
    operations->push_back(operation);
}

void EngineMock::Divide(){
    logger->LogDebugMessage("Divide");
    OperationResult* operation = new OperationResult(OperationCode::Divide);
    operations->push_back(operation);
}

void EngineMock::Read(){
    logger->LogDebugMessage("Read");
    OperationResult* operation = new OperationResult(OperationCode::Read);
    operations->push_back(operation);
}

void EngineMock::Print(){
    logger->LogDebugMessage("Print");
    OperationResult* operation = new OperationResult(OperationCode::Print);
    operations->push_back(operation);
}

std::vector<OperationResult*> EngineMock::GetOperations(){
    return *operations;
}

std::vector<NUMERIC> EngineMock::GetOperationalMemory(){
    return *initialMemory;
}

EngineMock::~EngineMock() {
    delete initialMemory;

    if(initialStack != nullptr)
        delete initialStack;
    
    for(const auto &operation : *operations)
        delete operation;

    operations->clear();
    delete operations;
}