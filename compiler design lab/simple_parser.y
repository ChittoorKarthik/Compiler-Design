%{
#include <stdio.h>
#include <ctype.h>
#include "simple_parser.tab.h"
#include "token.h"  // Include the header file that defines TokenInfo
#include "token.c"
%}

%union {
    TokenInfo tokenInfo;
}

%token <tokenInfo> ALPHABET EOL

%%

program:
    statement_list
    ;

statement_list:
    statement
    | statement_list statement
    ;

statement:
    ALPHABET { printf("Token: ALPHABET, x: %d, y: %d\n", $1.tokenInfo.line_num, $1.tokenInfo.col_num); }
    ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Parser error: %s\n", s);
}
