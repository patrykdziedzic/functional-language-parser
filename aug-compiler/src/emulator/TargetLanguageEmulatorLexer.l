%option noyywrap
%option prefix="TargetLanguageEmulator"

%{
    #include <string>
    #include "TargetLanguageEmulatorParser.h"
    using namespace std;
%}

%%
[ \t\n] ;
DATA    { return DATA; }
[a-zA-Z0-9]+   {
    TargetLanguageEmulatorlval.sval = new string(yytext);
    return STRING;
}
%%