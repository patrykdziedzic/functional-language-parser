%option noyywrap
%option prefix="TargetLanguageEmulator"

%{
    #include <string>
    #include "TargetLanguageEmulatorParser.h"
    using namespace std;
%}

%%
#.*$ ; //Comment
[ \t\n] ;
DATA    { return DATA; }
^[0-9]+ {
    TargetLanguageEmulatorlval.unsignedValue = stoi(yytext);
    return LINE_ADDRESS;    
}
PUSH    { return PUSH; }
POP { return POP; }
DUP { return DUP; }
ADD { return ADD; }
MUL { return MUL; }
DIV { return DIV; }
NEG { return NEG; }
JMP { return JUMP; }
JZ  { return JUMP_IF_ZERO; }
JNZ { return JUMP_IF_NOT_ZERO; }
JLZ { return JUMP_IF_NEGATIVE; }
JLEZ    { return JUMP_IF_NOT_POSITIVE; }
JGZ { return JUMP_IF_POSITIVE; }
JGEZ { return JUMP_IF_NOT_NEGATIVE; }
READ    { return READ; }
PRINT   { return PRINT; }
STOP    { return STOP; }
NOP { return NOP; }
,   { return DELIMITER; }
[0-9]+  {
    TargetLanguageEmulatorlval.unsignedValue = stoi(yytext);
    return UNSIGNED;
}
-?[0-9]+ {
    TargetLanguageEmulatorlval.signedValue = stoi(yytext);
    return SIGNED;
}
\$ { return DOLLAR; }
%%