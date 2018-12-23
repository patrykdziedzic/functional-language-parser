/* https://lagunita.stanford.edu/courses/course-v1:Medicine+IPE21CC+ongoing/wiki/Engineering.Compilers.Fall2014/troubleshoot-liblibflso-undefined-reference-yylex/ */
%option noyywrap
%{
    int num_lines = 0, num_chars = 0;
%}

%%
\n      ++num_lines; ++num_chars;
.       ++num_chars;

%%

#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    yyin = fopen(argv[1], "r");
    yylex();
    cout <<"# of lines = " << num_lines << ", # of chars = " << num_chars << endl;
    fclose(yyin);
    return 0;
}