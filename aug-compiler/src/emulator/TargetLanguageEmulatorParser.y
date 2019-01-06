%define api.prefix {TargetLanguageEmulator}

%{
    #include <iostream>
    #include <string>

    extern int TargetLanguageEmulatorlex();
    extern int TargetLanguageEmulatorparse();
    extern int TargetLanguageEmulator_scan_string(const char *str_input);
    void TargetLanguageEmulatorerror(const char *s);
%}

%union{
    std::string* sval;
}

%token DATA
%token <sval> STRING

%%
TargetLanguage:
    TargetLanguage STRING {
        std::cout << "String found: " << *$2 << std::endl;
        delete $2;
    }
    | TargetLanguage DATA {
        std::cout << "DATA token found" << std::endl;
    }
    | STRING {
        std::cout << "String found: " << *$1 << std::endl;
        delete $1;
    }
    | DATA {
        std::cout << "DATA token found" << std::endl;
    }
%%

int main(int, char**) {
    std::cout << "Hello boy I am starting xdxd" << std::endl;
    TargetLanguageEmulator_scan_string("Hey hey here comes DATA");
    TargetLanguageEmulatorparse();
    return 0;
}

void TargetLanguageEmulatorerror(const char *s) {
  std::cout << "Target language emulator parser error!" << std::endl << "Message: " << s << std::endl;
  exit(-1);
}