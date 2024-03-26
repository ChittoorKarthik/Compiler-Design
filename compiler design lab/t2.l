%{
#include <stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
#include "t2parser.tab.h"

extern int line_num;
extern int col_num;


char prev='@';
int line_num = 1;
int col_num = 1;
const int largest_length_for_yytext_clone=10000;
%}

datatype "sankhya"|"thelu"|"aksharam"|"theega"
telugu_if "okavela"
telugu_elif "lekaokavela"
telugu_else "lekapothe"
telugu_while "aithaunte"
telugu_function "pani"
telugu_return "ivvu"
telugu_print "chupi"
telugu_import "thechko"
telugu_input "theesko"

identifier [a-zA-Z_][a-zA-Z0-9_]*
digit [0-9]
int [-+]?{digit}+
float {int}"."({digit}+)
arthematic_operator ("+")|("-")|("*")|("/")|("%")
comparision_operator ("samanam")|("bhinnam")|("peddadiLedaSamanam")|("chinnadiLedaSamanam")|("chinnadi")|("peddadi")
logical_operator "mariyu"|"leda"|"kaadu"|"pratyekam"
assignment_operator "="
space [ \t]
newline [\n]
finish ";"
string \"(\\.|[^\\"])*\"
invalidIdentifier (({digit}+{identifier}))

%%
D
{int} {
    // HANDLE THIS CASE PROPERLY
    if(prev != '=') {
        if(yytext[0]!='+' && yytext[0]!='-'){ // will this case be reached?
            printf("%s is an  integer1 (line: %d, column: %d)\n",yytext, line_num, col_num);
            //yylval.num=atoi(yytext);
            prev='@';
            strcpy(yylval.nd_obj.name,(yytext));
            return TELUGU_INT; // unsigned needed?
        }
        else{
            //printf("total yytext = %s\n",yytext);
            printf(" %c is an arithmetic operator(line: %d, column: %d)\n", yytext[0], line_num, col_num + 1);
            int i = 1;
            int textlen=strlen(yytext)-1;
            //printf("textlen=%d\n",textlen);
            char dummy[largest_length_for_yytext_clone]; // Declaration of dummy array
            strcpy(dummy, yytext); 
            i=1;
            for (i = textlen; i >= 1; i--) {
                //printf("i=%d\n", i);
                //printf(" unputting %c\n", dummy[i]);
                unput(dummy[i]); // Put back each digit into the input stream
            }
            //printf("length=%d for unput\n",i-1);
            //unxput(yytext, 1, i-1);
            //printf("after unput yytext=%s\n",yytext);
            prev = '@';
            //colnum +=1-yyleng;  // to balance the next +yyleng because we only saw one operation character
            strcpy(yylval.nd_obj.name,(yytext));
            return TELUGU_ARITHMETIC_OPERATOR;
        }
    } 
    else {
        printf("%s is a  integer3 (line: %d, column: %d)\n", yytext, line_num, col_num);
        prev='@';
        strcpy(yylval.nd_obj.name,(yytext));
        return TELUGU_INT;
    }
    col_num += yyleng;
}

{float} {
    if(prev != '=') {
        if(yytext[0]!='+' && yytext[0]!='-'){
            printf("%s is an unsigned float (line: %d, column: %d)\n",yytext, line_num, col_num);
            strcpy(yylval.nd_obj.name,(yytext));
            return TELUGU_FLOAT;
        }
        else{
            printf("%s is arithmatic operator\n%s is a float (line: %d, column: %d)\n", yytext[0],yytext+1, line_num, col_num+1);
            unput(yytext[0]); // Put back the arithmatic operator into the input stream
            strcpy(yylval.nd_obj.name,(yytext));
            return TELUGU_ARITHMETIC_OPERATOR;
        }
    } 
    else {
        printf("%s is a signed float (line: %d, column: %d)\n", yytext, line_num, col_num);
        strcpy(yylval.nd_obj.name,(yytext));
        return TELUGU_FLOAT;
    }
    prev='@';
    col_num += yyleng;
}

{finish} {
    printf("%s is the end of a statement (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev='@';
    col_num += yyleng;
    strcpy(yylval.nd_obj.name,(yytext));
    return TELUGU_FINISH;
}

{arthematic_operator} {
    
    if(prev != '='){
        printf("%s is an arithmatic operator (line: %d, column: %d)\n", yytext, line_num, col_num);
        prev='@';
        col_num += yyleng;
        strcpy(yylval.nd_obj.name,(yytext));
        return TELUGU_ARITHMETIC_OPERATOR;
    }
    else if(yytext[0] == '+' || yytext[0] == '-') {
        int c;
        do {
            c = input();
        } while (isspace(c));
        
        if (isdigit(c)) {
            unput(c);
            printf("%c is an arithmetic operator\n%s is an integer (line: %d, column: %d)\n", yytext[0], yytext + 1, line_num, col_num + 1);
            strcpy(yylval.nd_obj.name,(yytext));
            return TELUGU_ARITHMETIC_OPERATOR;
        } else {
            unput(c);
            printf("%s is an arithmatic operator (line: %d, column: %d)\n", yytext, line_num, col_num);
            strcpy(yylval.nd_obj.name,(yytext));
            return TELUGU_ARITHMETIC_OPERATOR;
        }
    } else {
        printf("%s is an arithmatic operator (line: %d, column: %d)\n", yytext, line_num, col_num);
        prev = '@';
        col_num += yyleng;
        strcpy(yylval.nd_obj.name,(yytext));
        return TELUGU_ARITHMETIC_OPERATOR;
    }
}

{logical_operator} {
    printf("%s is a comparison operator (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev='@';
    col_num += yyleng;
    strcpy(yylval.nd_obj.name,(yytext));
    return TELUGU_LOGICAL_OPERATOR;
}

{comparision_operator} {
    printf("%s is a comparison operator (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev='@';
    col_num += yyleng;
    strcpy(yylval.nd_obj.name,(yytext));
    return TELUGU_COMPARISON_OPERATOR;
}

{assignment_operator} {
    printf("%s is an assignment operator (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev='=';
    col_num += yyleng;
    strcpy(yylval.nd_obj.name,(yytext));
    return TELUGU_ASSIGNMENT_OPERATOR;
}

{telugu_import} {
    printf("%s is import keyword (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev='@';
    col_num += yyleng;
    strcpy(yylval.nd_obj.name,(yytext));
    return TELUGU_IMPORT;
}

{datatype} {
    printf("%s is a data type (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev = '@';
    col_num += yyleng;
    strcpy(yylval.nd_obj.name,(yytext));
    return TELUGU_DATATYPE;
}

{telugu_if} {
    printf("%s is a telugu_if statement (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev = '@';
    col_num += yyleng;
    strcpy(yylval.nd_obj.name,(yytext));
    return TELUGU_IF;
}

{telugu_elif} {
    printf("%s is a telugu_elif statement (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev = '@';
    col_num += yyleng;
    strcpy(yylval.nd_obj.name,(yytext));
    return TELUGU_ELIF;
}

{telugu_else} {
    printf("%s is a telugu_else statement (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev = '@';
    col_num += yyleng;
    strcpy(yylval.nd_obj.name,(yytext));
    return TELUGU_ELSE;
}

{telugu_while} {
    printf("%s is a telugu_while statement (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev = '@';
    col_num += yyleng;
    strcpy(yylval.nd_obj.name,(yytext));
    return TELUGU_WHILE;
}

{telugu_function} {
    printf("%s is a telugu_function keyword (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev = '@';
    col_num += yyleng;
    strcpy(yylval.nd_obj.name,(yytext));
    return TELUGU_FUNCTION;
}

{telugu_return} {
    printf("%s is a telugu_return keyword (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev = '@';
    col_num += yyleng;
    strcpy(yylval.nd_obj.name,(yytext));
    return TELUGU_RETURN;
}

{telugu_print} {
    printf("%s is a telugu_print keyword (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev = '@';
    col_num += yyleng;
    strcpy(yylval.nd_obj.name,(yytext));
    return TELUGU_PRINT;
}

{space} {
    col_num += yyleng;
    //return -1; // No token associated with space
}

{newline} {
    printf("%s is a new line (line: %d)\n", yytext, line_num);
    line_num++;
    col_num = 1;
    //strcpy(yylval.nd_obj.name,(yytext));
    return EOL;
}

{identifier} {
    printf("%s is an identifier (line: %d, column: %d)\n", yytext, line_num, col_num);
    prev='i'; 
    col_num += yyleng;
    strcpy(yylval.nd_obj.name,(yytext));
    return TELUGU_IDENTIFIER;
}

{invalidIdentifier} {
     printf("%s is an invalid identifier (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
     strcpy(yylval.nd_obj.name,(yytext));
     return -1; // No specific token for invalid identifier
}

{string} {
     printf("%s is a string (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
     strcpy(yylval.nd_obj.name,(yytext));
     return TELUGU_STRING;
}

"(" {
    printf("%s is an open curly bracket (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
     strcpy(yylval.nd_obj.name,(yytext));
     return TELUGU_OPEN_CURLY_BRACKET;
}
")" {
    printf("%s is an closed curly bracket (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
     strcpy(yylval.nd_obj.name,(yytext));
     return TELUGU_CLOSED_CURLY_BRACKET;
}
"[" {
    printf("%s is an open square bracket (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
     strcpy(yylval.nd_obj.name,(yytext));
     return TELUGU_OPEN_SQUARE_BRACKET;
}
"]" {
    printf("%s is an closed square bracket (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
     strcpy(yylval.nd_obj.name,(yytext));
     return TELUGU_CLOSED_SQUARE_BRACKET;
}
"{" {
    printf("%s is an open flower bracket (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
     strcpy(yylval.nd_obj.name,(yytext));
     return TELUGU_OPEN_FLOOR_BRACKET;
}
"}" {
    printf("%s is an closed flower bracket (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
     strcpy(yylval.nd_obj.name,(yytext));
     return TELUGU_CLOSED_FLOOR_BRACKET;
}  
"," {
    printf("%s is a punctuation comma (line: %d, column: %d)\n", yytext, line_num, col_num);
     prev='@';
     col_num += yyleng;
     strcpy(yylval.nd_obj.name,(yytext));
     return TELUGU_PUNCTUATION_COMMA;
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
    printf("\nLEXICAL ERROR:%s is not defined for me (line: %d, column: %d)\n\n", yytext, line_num, col_num);
    prev='@';
    col_num += yyleng;
    strcpy(yylval.nd_obj.name,(yytext));
    return -1; // No specific token for undefined character
}

%%

int yywrap(){
    //return 1;
}