%define api.prefix {TargetLanguageEmulator}

%code requires{
    #include <iostream>
    #include "ProgramMemory.h"
    #include "ITargetLanguageEngine.h"

    namespace TargetLanguage{
        void TargetLanguageEmulatorerror(const char *s);
        class EmulatorParser{
            public:
                EmulatorParser(IEngine* engine);
                void ParseLanguage(ProgramMemory* programMemory);
                ~EmulatorParser();
        };
    }
}

%code{
    extern int TargetLanguageEmulatorlex();
    extern int* TargetLanguageEmulator_scan_string(const char *str_input);
    extern int TargetLanguageEmulatorparse();
    using namespace std;

    TargetLanguage::IEngine* emulatorEngine;
    TargetLanguage::ProgramMemory* targetLanguageCode;

    namespace TargetLanguage{
        EmulatorParser::EmulatorParser(IEngine* engine){
            emulatorEngine = engine;
        }

        void EmulatorParser::ParseLanguage(ProgramMemory* programMemory){
            targetLanguageCode = programMemory;
            TargetLanguageEmulator_scan_string(targetLanguageCode->GetPosition(0));
            TargetLanguageEmulatorparse();
        }

        EmulatorParser::~EmulatorParser() { }
    }

    void TargetLanguageEmulatorerror(const char *s) {
        cout << "Target language emulator parser error!" << endl << "Message: " << s << endl;
        exit(-1);
    }
}

%union{
    long long unsigned unsignedValue;
    long long signed signedValue;
    std::vector<long long signed> *signedVector;
}

%token DATA
%token PUSH
%token POP
%token DOLLAR
%token DUP
%token ADD
%token MUL
%token DIV
%token NEG
%token JUMP
%token JUMP_IF_ZERO
%token JUMP_IF_NOT_ZERO
%token JUMP_IF_NEGATIVE
%token JUMP_IF_NOT_NEGATIVE
%token JUMP_IF_POSITIVE
%token JUMP_IF_NOT_POSITIVE
%token READ
%token PRINT
%token STOP
%token NOP
%token DELIMITER
%token<unsignedValue> UNSIGNED
%token<signedValue> SIGNED
%token<unsignedValue> LINE_ADDRESS

%type<unsignedValue> ADDRESS
%type<signedValue> VALUE
%type<signedVector> VECTOR

%%
TARGET_LANGUAGE:
    DATA_LINE
    | INSTRUCTION_LINE
    | TARGET_LANGUAGE INSTRUCTION_LINE
;
INSTRUCTION_LINE:
    LINE_ADDRESS INSTRUCTION
;
INSTRUCTION:
    PUSH ADDRESS {
        emulatorEngine->PushFromAddress($2);
    }
    | PUSH VALUE{
        emulatorEngine->PushValue($2);
    }
    | JUMP ADDRESS{
        TargetLanguageEmulator_scan_string(targetLanguageCode->GetPosition($2));
    }
    | POP ADDRESS{
        emulatorEngine->PopToAddress($2);
    }
    | POP{
        emulatorEngine->Pop();
    }
    | DUP{
        emulatorEngine->Duplicate();
    }
    | ADD{
        emulatorEngine->Add();
    }
    | MUL{
        emulatorEngine->Multiply();
    }
    | DIV{
        emulatorEngine->Divide();
    }
    | NEG{
        emulatorEngine->Negate();
    }
    | JUMP_IF_ZERO ADDRESS{
        if(emulatorEngine->Pop() == 0)
            TargetLanguageEmulator_scan_string(targetLanguageCode->GetPosition($2));
    }
    | JUMP_IF_NOT_ZERO ADDRESS{
        if(emulatorEngine->Pop() != 0)
            TargetLanguageEmulator_scan_string(targetLanguageCode->GetPosition($2));
    }
    | JUMP_IF_NEGATIVE ADDRESS{
        if(emulatorEngine->Pop() < 0)
            TargetLanguageEmulator_scan_string(targetLanguageCode->GetPosition($2));
    }
    | JUMP_IF_NOT_POSITIVE ADDRESS{
        if(emulatorEngine->Pop() <= 0)
            TargetLanguageEmulator_scan_string(targetLanguageCode->GetPosition($2));
    }
    | JUMP_IF_POSITIVE ADDRESS{
        if(emulatorEngine->Pop() > 0)
            TargetLanguageEmulator_scan_string(targetLanguageCode->GetPosition($2));
    }
    | JUMP_IF_NOT_NEGATIVE ADDRESS{
        if(emulatorEngine->Pop() >= 0)
            TargetLanguageEmulator_scan_string(targetLanguageCode->GetPosition($2));
    }
    | READ{
        emulatorEngine->Read();
    }
    | PRINT{
        emulatorEngine->Print();
    }
    | STOP{
        return 0;
    }
    | NOP{ }
;
DATA_LINE:
    DATA VECTOR{
        emulatorEngine->CopyAsInitialMemory($2);
        delete $2;
    }
    | DATA{ }
;
ADDRESS:
    DOLLAR UNSIGNED { $$ = $2; }
;
VALUE:
    SIGNED | UNSIGNED
;
VECTOR:
    VALUE{
        $$ = new vector<long long signed>();
        $$->push_back($1);
    }
    | VECTOR DELIMITER VALUE{
        $$->push_back($3);
    }
%%