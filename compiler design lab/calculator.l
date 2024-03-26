%{   
    #include<stdio.h>
    double first=0,second=0;
    int turn=1;
    char operation;
    void calculate(){
        if(operation == '+'){
            printf("sum of %f and %f = %f\n",first,second,first+second);
        }
        else if(operation == '-'){
            printf("sum of %f and %f = %f\n",first,second,first-second);
        }
        else if(operation == '*'){
            printf("sum of %f and %f = %f\n",first,second,first*second);
        }
        else if(operation == '/'){
            printf("sum of %f and %f = %f\n",first,second,first/second);
        }
        else{
            printf("i dont know this operation\n");
        }
    }
%}
keyword "sankhya"|"thelu"|"aksharam"|"okavela"|"leda"|"chupi"
symbols [#_$@]+

letter [a-z]
digit [0-9]
add "+"
subtract "-"
divide "/"
multiply "*"
int [+-]{digit}+
id {symbols}({letter}*{digit}*){symbols}
A [ ]
C [\n]
number {digit}+(\.{digit}+)?(E[+-]?{digit}+)?
%%

{int} {printf("%s is an integer\n",yytext);}
{keyword} {printf("%s is an keyword\n",yytext);}
{A} {printf("%s space\n",yytext);}
{C} {}
{symbols} {printf("%s is a symbol\n",yytext);}
{letter} {printf("%s is a letter\n",yytext);}
{id} {printf("%s is an identifier\n",yytext);}
{number} {printf("%s is an number\n",yytext);
            if(turn==1){
                first  = atoi(yytext);
                turn++;
            }
            else{ 
                second=atoi(yytext);
                calculate();
                turn=1;
            }
        }
{add} {printf("%s indicates addition\n",yytext);operation='+';}
{subtract} {printf("%s indicates subtract\n",yytext);operation='-';}
{multiply} {printf("%s indicates multiply\n",yytext);operation='*';}
{divide} {printf("%s indicates divide\n",yytext);operation='/';}
. {printf("%sthis is error in telugu\n",yytext);}


%%

int main(){
    printf("enter input string:");
    printf("%d",yylex());

}

int yywrap(){
    return 1;
}