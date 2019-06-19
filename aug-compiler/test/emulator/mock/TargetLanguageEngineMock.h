#include "./../../../src/emulator/ITargetLanguageEngine.h"
#include "./../../../src/Logger.h"
#include <stack>

struct OperationResult;
class EngineMock : public TargetLanguage::IEngine{
    public:
        EngineMock(Logger* logger);
        EngineMock(Logger* logger, std::vector<NUMERIC> initialStackSequence);
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
        std::vector<OperationResult*> GetOperations();
        std::vector<NUMERIC> GetOperationalMemory();
        ~EngineMock();
    private:
        void SavePopOperation();
        void SavePopOperation(NUMERIC value);
        std::vector<NUMERIC>* initialMemory;
        std::stack<NUMERIC>* initialStack;
        std::vector<OperationResult*>* operations;
        Logger* logger;
};

enum OperationCode{
    PushFromAddress,
    PushValue,
    PopToAddress,
    CopyAsInitialMemory,
    Pop,
    Duplicate,
    Add,
    Negate,
    Multiply,
    Divide,
    Read,
    Print
};

struct OperationResult{
    OperationCode Code;
    NUMERIC* Argument;
    
    OperationResult(OperationCode code, NUMERIC argument){
        Code = code;
        Argument = new NUMERIC();
        *Argument = argument;
    }
    
    OperationResult(OperationCode code){
        Code = code;
        Argument = nullptr;
    }

    OperationResult(const OperationResult &operationResult){
        Code = operationResult.Code;
        Argument = nullptr;
        if(operationResult.Argument != nullptr){
            Argument = new NUMERIC();
            *Argument = *operationResult.Argument;
        };
    }

    bool operator==(const OperationResult & operation) const{
        if(operation.Code != this->Code)
            return false;
        
        if((operation.Argument == nullptr && this->Argument != nullptr)
        || (operation.Argument != nullptr && this->Argument == nullptr))
            return false;

        if(operation.Argument == nullptr && this->Argument == nullptr)
            return true;

        return *operation.Argument == *this->Argument;
    }

    ~OperationResult(){
        if(Argument != nullptr)
            delete Argument;
    }
};