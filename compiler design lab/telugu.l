%{
#include<stdio.h>
#include <ctype.h> // Include the <ctype.h> header for isspace() and isdigit()
char prev='@';
int line_num = 1;
int col_num = 1;
   
%}

keyword "sankhya"|"thelu"|"okavela"|"lekapothe"|"chupi"|"theega"|"ivvu"|"pani"|"aithaunte"|"mariyu"|"leda"|"kaadu"
identifier [a-zA-Z_][a-zA-Z0-9_]*
digit [0-9]
int [-+]?{digit}+
float {int}"."({digit}+)
arthematic_operator ("+")|("-")|("*")|("/")|("^")
comparision_operator ("samanam")|("bhinnam")|("peddadiLedaSamanam")|("chinnadiLedaSamanam")|("chinnadi")|("peddadi")
assignment_operator "="
space [ \t]
newline [\n]
finish ";"
string \"(\\.|[^\\"])*\"
invalidIdentifier (({digit}+{identifier}))

%%

{int} {
    if(prev != '=') {
        if(yytext[0]!='+' && yytext[0]!='-'){
            printf("%s is an  integer (line: %d, column: %d)\n",yytext, line_num, col_num);
        }
        else{
            printf(" %c is arthematic operator\n%s is an integer (line: %d, column: %d)\n",yytext[0] ,yytext+1, line_num, col_num+1);
        }
    } 
    else {
        printf("%s is a  integer (line: %d, column: %d)\n", yytext, line_num, col_num);
    }
    prev='@';
    col_num += yyleng;
}

{float} {
    if(prev != '=') {
        if(yytext[0]!='+' && yytext[0]!='-'){
            printf("%s is an unsigned float (line: %d, column: %d)\n",yytext, line_num, col_num);
        }
        else{
            printf("- is arthematic operator\n%s is a float (line: %d, column: %d)\n", yytext+1, line_num, col_num+1);
        }
    } 
    else {
        printf("%s is a signed float (line: %d, column: %d)\n", yytext, line_num, col_num);
    }
    prev='@';
    col_num += yyleng;
}

{finish} {
    printf("%s is the end of a statement (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev='@';
    col_num += yyleng;
}

{arthematic_operator} {
    if(prev != '='){
        printf("%s is an arthematic operator (line: %d, column: %d)\n", yytext, line_num, col_num);
        prev='@';
        col_num += yyleng;
    }
    // Check if the arithematic operator is '+' or '-'
    else if(yytext[0] == '+' || yytext[0] == '-') {
        int c;
        // Skip whitespace characters
        do {
            c = input();
        } while (isspace(c));
        
        // If the next character is a digit, treat the token as an integer
        if (isdigit(c)) {
            // Print the arithematic operator
            printf("%c", yytext[0]);
            // Print the digits
            do {
                printf("%c", c);
                c = input();
            } while (isdigit(c));
            // Put back the non-digit character
            unput(c);
            printf(" is an integer (line: %d, column: %d)\n", line_num, col_num);
            prev = '@';
            continue;
        } else {
            // If the next character is not a digit, treat the token as an arithematic operator
            unput(c); // Put back the non-digit character
            printf("%s is an arithematic operator (line: %d, column: %d)\n", yytext, line_num, col_num);
            prev = '@';
            col_num += yyleng;
        }
    } else {
        // If the arithematic operator is not '+' or '-', treat it as an arithematic operator
        printf("%s is an arithematic operator (line: %d, column: %d)\n", yytext, line_num, col_num);
        prev = '@';
        col_num += yyleng;
    }
}

{comparision_operator} {
    printf("%s is a comparison operator (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev='@';
    col_num += yyleng;
}

{assignment_operator} {
    printf("%s is an assignment operator (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev='=';
    col_num += yyleng;
}

{keyword} {
    printf("%s is a keyword (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev='@';
    col_num += yyleng;
}

{space} {
    col_num += yyleng;
}

{newline} {
    printf("%s is a new line (line: %d)\n", yytext, line_num);
    line_num++;
    col_num = 1;
}

{identifier} {
    printf("%s is an identifier (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev='i'; 
    col_num += yyleng;
}

{invalidIdentifier} {
     printf("ERROR: %s is an invalid identifier (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
}

{string} {
     printf("%s is a string (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
}
"(" {
    printf("%s is an open curly bracket (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
}
")" {
    printf("%s is an closed curly bracket (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
}
"[" {
    printf("%s is an open square bracket (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
}
"]" {
    printf("%s is an closed square bracket (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
}
"{" {
    printf("%s is an open flower bracket (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
}
"}" {
    printf("%s is an closed flower bracket (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
}  
"," {
    printf("%s is a punctuation comma (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
}

"//"        {
                while (1) {
                    int c = input();
                    if (c == '\n' || c == EOF) {
                        unput(c);
                        break;
                    }
                }
            }

. {
    printf("\nLEXER ERROR:%s is unknown symbol to me (line: %d, column: %d)\n\n", yytext, line_num, col_num);
    prev='@';
    col_num += yyleng;
}


%%

int main(int argc, char *argv[]) {
    FILE *file;
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    yyin = file;  // Set yyin to point to the file stream

    yylex();

    fclose(file);
    return 0;
}
int yywrap(){
    return 1;
}