%{
#include <stdio.h>
#include <ctype.h>
#include "simple_parser.tab.h"
#include "token.h"  // Include the header file that defines TokenInfo
#include "token.c"
%}

%%

[a-z]      { yylval.tokenInfo.token = ALPHABET; yylval.tokenInfo.line_num = 2; yylval.tokenInfo.col_num = 3; return ALPHABET; }
\n         { return EOL; }
.          { /* Ignore all other characters */ }

%%

int yywrap() {
    return 1;
}
