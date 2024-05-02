# Compiler-Design
Telugu language compiler (uses syntax with a mix of python and c++)

TO RUN THE COMPILER:
types these in the terminal:
flex t2.l
bison -d t2parser.y
gcc lex.yy.c t2parser.tab.c -o my_program
Get-Content input3.txt | my_program.exe
