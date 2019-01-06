%define api.prefix {TargetLanguageEmulator}

%{
    #include <iostream>
    using namespace std;

    extern int TargetLanguageEmulatorlex();
    extern int TargetLanguageEmulatorparse();
    extern int TargetLanguageEmulator_scan_string(const char *str_input);
    void TargetLanguageEmulatorerror(const char *s);
%}

%union{
    long long unsigned unsignedValue;
    long long signed signedValue;
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
%token<unsignedValue> UNSIGNED
%token<signedValue> SIGNED

%type<unsignedValue> ADDRESS
%type<signedValue> VALUE

%%
TargetLanguage:
    DataLine
    | Instruction
    | TargetLanguage Instruction
;
Instruction:
    PUSH ADDRESS {
        cout << "Push to stack value from address: " << $2 << endl;
    }
    | PUSH VALUE{
        cout << "Push to stack value: " << $2 << endl;
    }
    | JUMP ADDRESS{
        cout << "Jump to address: " << $2 << endl;
        TargetLanguageEmulator_scan_string("PUSH $10");
    }
    | POP ADDRESS{
        cout << "Pop from stack to address: " << $2 << endl;
    }
    | POP{
        cout << "Pop from stack and drop" << endl;
    }
    | DUP{
        cout << "Duplicate value on stack" << endl;
    }
    | ADD{
        cout << "Add 2 top values from stack" << endl;
    }
    | MUL{
        cout << "Multiply 2 top values from stack" << endl;
    }
    | DIV{
        cout << "Divide 2 top values from stack" << endl;
    }
    | NEG{
        cout << "Negate value from stack" << endl;
    }
    | JUMP_IF_ZERO ADDRESS{
        cout << "If value on stack is zero, go to address: " << $2 << endl;
    }
    | JUMP_IF_NOT_ZERO ADDRESS{
        cout << "If value on stack is not zero, go to address: " << $2 << endl;
    }
    | JUMP_IF_NEGATIVE ADDRESS{
        cout << "If value on stack is negative, go to address: " << $2 << endl;
    }
    | JUMP_IF_NOT_POSITIVE ADDRESS{
        cout << "If value on stack is negative or zero, go to address: " << $2 << endl;
    }
    | JUMP_IF_POSITIVE ADDRESS{
        cout << "If value on stack is positive, go to address: " << $2 << endl;
    }
    | JUMP_IF_NOT_NEGATIVE ADDRESS{
        cout << "If value on stack is positive or zero, go to address: " << $2 << endl;
    }
    | READ{
        cout << "Read value from standard input" << endl;
    }
    | PRINT{
        cout << "Print value to standard input" << endl;
    }
    | STOP{
        cout << "Stop program" << endl;
    }
    | NOP{
        cout << "No action" << endl;
    }
;
DataLine:
    DATA {
        cout << "DATA token found" << endl;
    }
;
ADDRESS:
    DOLLAR UNSIGNED { $$ = $2; }
;
VALUE:
    SIGNED | UNSIGNED
;
%%

int main(int, char**) {
    const char *input =
        "DATA"
        "PUSH 5"
        "PUSH $5"
        "PUSH $7"
        "POP"
        "DUP"
        "POP $10"
        "ADD"
        "MUL"
        "DIV"
        "NEG"
        "JZ $6"
        "JNZ $124"
        "JLZ $768"
        "JLEZ $231"
        "JGZ $23"
        "JGEZ $125"
        "READ"
        "PRINT"
        "NOP"
        "STOP"
        "JUMP $3";
    cout << "Start parsing" << endl;
    TargetLanguageEmulator_scan_string(input);
    TargetLanguageEmulatorparse();
    return 0;
}

void TargetLanguageEmulatorerror(const char *s) {
  cout << "Target language emulator parser error!" << endl << "Message: " << s << endl;
  exit(-1);
}