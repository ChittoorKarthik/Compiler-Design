%{
    /*definitions*/
    #include <stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    // Declaration of tree
    struct node {
        int num_children;       // Number of children
        struct node **children; // Array of pointers to child nodes
        char *token;            // Token associated with the node
    };

    struct node *head;
    struct node* mknode(int num_children, struct node **children, char *token) ;
    void printtree(struct node* tree);
    void printInorder(struct node *tree);
    void add(char);
    void insert_type();
    int search(char *);
    void insert_type();

    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
    } symbol_table[40];

    int count=0;
    int q;
    char type[10];
    extern int new_line;

    int sem_errors=0;
	int label=0;
	char buff[100];
	char errors[10][100];
	//char reserved[10][10] = {"sankhya", "thelu", "aksharam", "pani", "okavela", "lekaokavela","lekapothe", "aithaunte", "ivvu", "thechko","theesko","chupi","theega",""};


%}

%error-verbose

%union { 
	struct var_name { 
		char name[100]; 
		struct node* nd;
	} nd_obj; 
} 



%token<nd_obj> EOL TELUGU_INT TELUGU_FLOAT TELUGU_ARITHMETIC_OPERATOR TELUGU_COMPARISON_OPERATOR TELUGU_ASSIGNMENT_OPERATOR TELUGU_LOGICAL_OPERATOR 
%token<nd_obj> TELUGU_DATATYPE TELUGU_IF TELUGU_ELIF TELUGU_ELSE TELUGU_WHILE TELUGU_OPEN_FLOOR_BRACKET TELUGU_CLOSED_FLOOR_BRACKET
%token<nd_obj> TELUGU_IDENTIFIER TELUGU_STRING TELUGU_OPEN_CURLY_BRACKET TELUGU_CLOSED_CURLY_BRACKET TELUGU_OPEN_SQUARE_BRACKET TELUGU_CLOSED_SQUARE_BRACKET  
%token<nd_obj> TELUGU_PUNCTUATION_COMMA TELUGU_NEWLINE TELUGU_FINISH TELUGU_FUNCTION TELUGU_RETURN TELUGU_CHARACTER TELUGU_PRINT TELUGU_IMPORT TELUGU_INPUT

%type<nd_obj> program,input,exp,condition,if_statement,while_loop,variable_declaration,parameters_repeat,equation,parameters_line,function_declaration,function_content,bunch_of_statements,elif_repeat,
                else_statement,if_else_ladder,empty_lines,function_call,identifiers_line,identifiers_repeat,telugu_print,print_content,print_statement,telugu_constant
%type<nd_obj> eol,telugu_int, telugu_float, telugu_arithmetic_operator, telugu_comparison_operator, telugu_assignment_operator, telugu_logical_operator, telugu_datatype, telugu_if, telugu_elif, telugu_else,
                 telugu_while, telugu_identifier, telugu_string, telugu_open_curly_bracket, telugu_closed_curly_bracket, telugu_open_square_bracket, telugu_closed_square_bracket, telugu_open_floor_bracket, 
                 telugu_closed_floor_bracket, telugu_punctuation_comma, telugu_newline, telugu_finish, telugu_function, telugu_return, telugu_character,telugu_import,telugu_input

%%
program:
    input {int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        
        // Assigning children nodes
        children[0] = $1.nd;  // Assuming $1 represents the parse tree node for symbol1
        // Assign more children if needed
        
        // Create the parse tree node for the production rule
        $$.nd = mknode(num_children, children, "program");
         head = $$.nd;}


eol:
    EOL {$$.nd = mknode(NULL, NULL, "newline");}
telugu_identifier:
    TELUGU_IDENTIFIER {$$.nd = mknode(NULL, NULL, $1.name);}
telugu_print:
    TELUGU_PRINT {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_int:
    TELUGU_INT {$$.nd = mknode(NULL, NULL, $1.name);}
telugu_input:
    TELUGU_INPUT {$$.nd = mknode(NULL, NULL, $1.name);}
telugu_float:
    TELUGU_FLOAT {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_import:
    TELUGU_IMPORT {$$.nd = mknode(NULL, NULL, $1.name);}
telugu_constant:
    TELUGU_INT {$$.nd = mknode(NULL, NULL, $1.name);}
    | TELUGU_FLOAT {$$.nd = mknode(NULL, NULL, $1.name);}
    | TELUGU_STRING {$$.nd = mknode(NULL, NULL, $1.name);}
    | TELUGU_CHARACTER {$$.nd = mknode(NULL, NULL, $1.name);}


telugu_arithmetic_operator:
    TELUGU_ARITHMETIC_OPERATOR {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_comparison_operator:
    TELUGU_COMPARISON_OPERATOR {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_assignment_operator:
    TELUGU_ASSIGNMENT_OPERATOR {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_logical_operator:
    TELUGU_LOGICAL_OPERATOR {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_datatype:
    TELUGU_DATATYPE {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_if:
    TELUGU_IF {$$.nd = mknode(NULL, NULL, "if");}

telugu_elif:
    TELUGU_ELIF {$$.nd = mknode(NULL, NULL, "elif");}

telugu_else:
    TELUGU_ELSE {$$.nd = mknode(NULL, NULL, "else");}

telugu_while:
    TELUGU_WHILE {$$.nd = mknode(NULL, NULL,"while");}

telugu_string:
    TELUGU_STRING {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_open_curly_bracket:
    TELUGU_OPEN_CURLY_BRACKET {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_closed_curly_bracket:
    TELUGU_CLOSED_CURLY_BRACKET {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_open_square_bracket:
    TELUGU_OPEN_SQUARE_BRACKET {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_closed_square_bracket:
    TELUGU_CLOSED_SQUARE_BRACKET {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_open_floor_bracket:
    TELUGU_OPEN_FLOOR_BRACKET {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_closed_floor_bracket:
    TELUGU_CLOSED_FLOOR_BRACKET {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_punctuation_comma:
    TELUGU_PUNCTUATION_COMMA {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_newline:
    TELUGU_NEWLINE {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_finish:
    TELUGU_FINISH {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_function:
    TELUGU_FUNCTION {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_return:
    TELUGU_RETURN {$$.nd = mknode(NULL, NULL, $1.name);}

telugu_character:
    TELUGU_CHARACTER {$$.nd = mknode(NULL, NULL, $1.name);}




input:  // input can be empty also
    { $$.nd = mknode(NULL, NULL, "empty"); }
|   input eol { 
        printf("Parser found input-eol\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        $$.nd = mknode(num_children, children, "input-eol");
    }
|   eol input { 
        printf("Parser found eol-input\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        $$.nd = mknode(num_children, children, "eol-input");
    }
|   input telugu_import telugu_identifier telugu_finish { 
        
        printf("Parser found input-import-id-;\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        children[3] = $4.nd;
        $$.nd = mknode(num_children, children, "input-import-id-;");
    }
|   telugu_import telugu_identifier telugu_finish input { 
        printf("Parser found import-id-;-input\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        children[3] = $4.nd;
        $$.nd = mknode(num_children, children, "import-id-;-input");
    }
|   input bunch_of_statements input { 
        printf("Parser found input-bunch_of_stmts-input\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        children[2] = $3.nd;
        $$.nd = mknode(num_children, children, "input-bunch-input");
    }
|   input function_declaration input { 
        printf("Parser found input-functionDec-input\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        children[2] = $3.nd;
        $$.nd = mknode(num_children, children, "input-funDec-input");
    }
;


empty_lines:
    EOL
|   empty_lines EOL

exp:   // empty not allowed

    telugu_int {
                    printf("Parser found int\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = $1.nd;  
                    $$.nd = mknode(num_children, children, "INT");
                }
|   telugu_float {
                    printf("Parser found float\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = $1.nd;  
                    $$.nd = mknode(num_children, children, "FLOAT");
                }
|   telugu_character {
                    printf("Parser found character\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = $1.nd;  
                    $$.nd = mknode(num_children, children, "CHAR");
                }
|   telugu_string {
                    printf("Parser found string\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = $1.nd;  
                    $$.nd = mknode(num_children, children, "STRING");
                }
|   telugu_identifier {
                    printf("Parser found identifier\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = $1.nd;  
                    $$.nd = mknode(num_children, children, "ID");
                }
|   function_call {
                    printf("Parser found funcCall\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = $1.nd;  
                    $$.nd = mknode(num_children, children, "funcCall");
                }
|   telugu_identifier telugu_open_square_bracket exp telugu_closed_square_bracket {
                    printf("Parser found id[exp]\n");
                    int num_children = 4;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = $1.nd;  
                    children[1] = $2.nd; 
                    children[2] = $3.nd; 
                    children[3] = $4.nd; 
                    $$.nd = mknode(num_children, children, "ID[exp]");
                }
|   telugu_open_curly_bracket exp telugu_closed_curly_bracket { 
        printf("Parser found (exp)\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        
        // Assigning children nodes
        children[0] = $1.nd;  // Assuming $1 represents the parse tree node for symbol1
        children[1] = $2.nd;  // Assuming $2 represents the parse tree node for symbol2
        children[2] = $3.nd;
        $$.nd = mknode(num_children, children, "(exp)");
        
        // Free the memory allocated for the array of children
        //free(children);
    }
|   exp telugu_arithmetic_operator exp { 
        printf("Parser found exp-arithmeticOp-exp\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        
        // Assigning children nodes
        children[0] = $1.nd;  // Assuming $1 represents the parse tree node for symbol1
        children[1] = $2.nd;  // Assuming $2 represents the parse tree node for symbol2
        children[2] = $3.nd;
        // Assign more children if needed
        
        // Create the parse tree node for the production rule
        $$.nd = mknode(num_children, children, "AthematicOp");
        
        // Free the memory allocated for the array of children
        //free(children);
    }
|   exp telugu_logical_operator exp { 
        printf("Parser found exp-logicalOp-exp\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        children[2] = $3.nd;
        $$.nd = mknode(num_children, children, "LogicalOp");
    }
|   telugu_identifier telugu_open_square_bracket exp telugu_closed_square_bracket { 
        printf("Parser found id[exp]\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        children[2] = $3.nd;
        children[3] = $4.nd;
        $$.nd = mknode(num_children, children, "id[exp]");
    }
;


bunch_of_statements:  //can be empty
    { $$.nd = mknode(NULL, NULL, "empty"); }
|   eol bunch_of_statements { 
        printf("Parser found EOL-bunch\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        $$.nd = mknode(num_children, children, "eol-bunch");
    }
|   bunch_of_statements eol { 
        printf("Parser found bunch-EOL\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        $$.nd = mknode(num_children, children, "bunch-eol");
    }
|   bunch_of_statements if_else_ladder bunch_of_statements { 
        printf("Parser found bunch_of_statement if_else_ladder bunch\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        $$.nd = mknode(num_children, children, "bunch-IfElse-bunch");
    }
|   bunch_of_statements telugu_input telugu_open_curly_bracket telugu_identifier telugu_closed_curly_bracket telugu_finish bunch_of_statements { 
        printf("Parser found bunch_of_statement-inputscan-bunch\n");
        int num_children = 7;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        children[2] = $3.nd;
        children[3] = $4.nd;
        children[4] = $5.nd;
        children[5] = $6.nd;
        children[6] = $7.nd;
        $$.nd = mknode(num_children, children, "bunch-inputScan-bunch");
    }
|   bunch_of_statements while_loop bunch_of_statements { 
        printf("Parser found bunch_of_statement while_loop bunch\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        children[2] = $3.nd;
        $$.nd = mknode(num_children, children, "bunch-while-bunch");
    }
|   bunch_of_statements equation telugu_finish bunch_of_statements { 
        printf("Parser found bunch-equation-finish\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        children[2] = $3.nd;
        children[3] = $4.nd;
        $$.nd = mknode(num_children, children, "bunch-equation-;-bunch");
    }
|   bunch_of_statements print_statement telugu_finish bunch_of_statements { 
        printf("Parser found bunch-printStmt-finish\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        children[2] = $3.nd;
        children[3] = $4.nd;
        $$.nd = mknode(num_children, children, "bunch-printStmt-;-bunch");
    }
|   bunch_of_statements variable_declaration telugu_finish bunch_of_statements { 
        printf("Parser found bunch-varDeclare-finish\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        children[2] = $3.nd;
        children[3] = $4.nd;
        $$.nd = mknode(num_children, children, "bunch-varDeclare-;-bunch");
    }
|   bunch_of_statements telugu_open_floor_bracket bunch_of_statements telugu_closed_floor_bracket bunch_of_statements {
        printf("parser found bunch {bunch}\n");
        int num_children = 5;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        children[2] = $3.nd;
        children[3] = $4.nd;
        children[4] = $5.nd;
        $$.nd = mknode(num_children, children, "bunch-{bunch}-bunch");
    }
|   bunch_of_statements function_call telugu_finish bunch_of_statements { 
        printf("Parser found bunch-functionCall-;\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        children[2] = $3.nd; 
        children[3] = $4.nd;
        $$.nd = mknode(num_children, children, "bunch-functionCall-;-bunch");
    }
|   error telugu_finish {
        printf("PARSER ERROR: syntax error \n");
        int num_children = 0;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        $$.nd = mknode(num_children, children, "error-;");
}

condition:  // for if_statement and while loop, empty not allowed
    exp { 
        printf("Parser found exp\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        $$.nd = mknode(num_children, children, "condition");
    }
|   exp telugu_comparison_operator exp { 
        printf("Parser found exp-compareOp-exp\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        children[2] = $3.nd;
        $$.nd = mknode(num_children, children, "condition");
    }
|   exp telugu_logical_operator exp { 
        printf("Parser found exp-logicalOp-exp\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd; 
        children[2] = $3.nd;
        $$.nd = mknode(num_children, children, "condition");
    }

if_statement:
    telugu_if telugu_open_curly_bracket condition telugu_closed_curly_bracket telugu_open_floor_bracket bunch_of_statements telugu_closed_floor_bracket { 
        printf("Parser found if(cond){bunch}\n");
        int num_children = 7;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        children[3] = $4.nd;
        children[4] = $5.nd;
        children[5] = $6.nd;
        children[6] = $7.nd;
        $$.nd = mknode(num_children, children, "if(cond){bunch}");
    }

elif_repeat: //can be empty
    { $$.nd = mknode(NULL, NULL, "empty"); }
|   eol elif_repeat { 
        printf("Parser found eol elif_repeat\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        $$.nd = mknode(num_children, children, "EOL-elifrepeat");
    }
|   elif_repeat telugu_elif telugu_open_curly_bracket condition telugu_closed_curly_bracket telugu_open_floor_bracket bunch_of_statements telugu_closed_floor_bracket elif_repeat { 
        printf("Parser found elif(cond){bunch}\n");
        int num_children = 9;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        children[3] = $4.nd;
        children[4] = $5.nd;
        children[5] = $6.nd;
        children[6] = $7.nd;
        children[7] = $8.nd;
        children[8] = $9.nd;
        $$.nd = mknode(num_children, children, "elif(cond){bunch}");
    }

else_statement:  //can be empty   
    { $$.nd = mknode(NULL, NULL, "empty"); }
|   eol else_statement { 
        printf("Parser found EOL-else\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        $$.nd = mknode(num_children, children, "EOL-else");
    }
|   telugu_else telugu_open_floor_bracket bunch_of_statements telugu_closed_floor_bracket { 
        printf("Parser found else{bunch}\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        children[3] = $4.nd;
        $$.nd = mknode(num_children, children, "else{bunch}");
    }

if_else_ladder:
    if_statement elif_repeat else_statement { 
        printf("Parser found ifElseLadder\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        $$.nd = mknode(num_children, children, "ifElseLadder");
    }
|   if_statement elif_repeat {    // without the else statement
        printf("Parser found ifElseLadder\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        $$.nd = mknode(num_children, children, "ifElseLadder");
    }

while_loop:
    telugu_while telugu_open_curly_bracket condition telugu_closed_curly_bracket telugu_open_floor_bracket bunch_of_statements telugu_closed_floor_bracket { 
        printf("Parser found while(cond){bunch}\n");
        int num_children = 7;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        children[3] = $4.nd;
        children[4] = $5.nd;
        children[5] = $6.nd;
        children[6] = $7.nd;
        $$.nd = mknode(num_children, children, "while(cond){bunch}");
    }

variable_declaration:
    telugu_datatype telugu_identifier telugu_assignment_operator exp { 
        printf("Parser found datatypeId=exp\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        children[3] = $4.nd;
        $$.nd = mknode(num_children, children, "datatypeId=exp");
    }
|   telugu_datatype telugu_identifier { 
        printf("Parser found datatype Id\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        $$.nd = mknode(num_children, children, "datatypeId");
    }
|   telugu_datatype telugu_identifier telugu_open_square_bracket exp telugu_closed_square_bracket { 
        printf("Parser found datatype Id\n");
        int num_children = 5;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd;
        children[3] = $4.nd;
        children[4] = $5.nd;
        $$.nd = mknode(num_children, children, "datatype Id[exp]");
    }


parameters_repeat: // can be empty 0 or more occurences
    { $$.nd = mknode(NULL, NULL, "empty"); }
|   parameters_repeat telugu_datatype telugu_identifier telugu_punctuation_comma { 
        printf("Parser found paramRepDatatypeIdComma\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        children[3] = $4.nd;
        $$.nd = mknode(num_children, children, "paramRepDatatypeIdComma");
    }

parameters_line: // can be empty
    { $$.nd = mknode(NULL, NULL, "empty"); }
|   parameters_repeat telugu_datatype telugu_identifier { 
        printf("Parser found parameters_line\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        $$.nd = mknode(num_children, children, "paramLine");
    }

identifiers_repeat: // abc,x,y,p  can be empty
     { $$.nd = mknode(NULL, NULL, "empty"); }
|   telugu_identifier { 
        printf("Parser found lastparam\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        $$.nd = mknode(num_children, children, "paramEnd");
    }
|   telugu_constant { 
        printf("Parser found lastparam\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        $$.nd = mknode(num_children, children, "paramEnd");
    }
|   telugu_identifier telugu_punctuation_comma identifiers_repeat { 
        printf("Parser found id-comma-prep\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        $$.nd = mknode(num_children, children, "paramRep");
    }
|   telugu_constant telugu_punctuation_comma identifiers_repeat { 
        printf("Parser found const-comma-prep\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        $$.nd = mknode(num_children, children, "paramRep");
    }

identifiers_line: // for function call,can be empty
    identifiers_repeat {
        printf("Parser found idLine\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd; 
        $$.nd = mknode(num_children, children, "idline");
    }

equation:
    telugu_identifier telugu_assignment_operator exp { 
        printf("Parser found equation\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        $$.nd = mknode(num_children, children, "id=exp");
    }
|   telugu_identifier telugu_open_square_bracket exp telugu_closed_square_bracket telugu_assignment_operator exp { 
        printf("Parser found id[exp]=exp\n");
        int num_children = 6;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        children[3] = $4.nd;
        children[4] = $5.nd;
        children[5] = $6.nd;
        $$.nd = mknode(num_children, children, "id[exp]=exp");
    }

function_content:  // can be empty also, return not needed
    function_content eol { 
        printf("Parser found funContentEOL\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        $$.nd = mknode(num_children, children, "funContentEOL");
    }
|    bunch_of_statements { 
        printf("Parser found bunch_function_content\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        $$.nd = mknode(num_children, children, "content-bunch");
    }
|   bunch_of_statements telugu_return telugu_finish bunch_of_statements { 
        printf("Parser found bunchReturnFinish\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd;
        children[3] = $4.nd; 
        $$.nd = mknode(num_children, children, "bunchReturnFinish");
    }
|   bunch_of_statements telugu_return exp telugu_finish bunch_of_statements { 
        printf("Parser found bunchReturnExpFinish\n");
        int num_children = 5;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd;
        children[3] = $4.nd;
        children[4] = $5.nd; 
        $$.nd = mknode(num_children, children, "bunchReturnExpFinish");
    }


print_content:  // can be empty also
|   print_content eol { 
        printf("Parser found print_contentEOL\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        $$.nd = mknode(num_children, children, "print_content-EOL");
    }
|   eol print_content {    // take care of infinite loop
        printf("Parser found EOL-print_content\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        $$.nd = mknode(num_children, children, "EOL-printContent");
    }
|   print_content telugu_string { 
        printf("Parser found print_content-String\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        $$.nd = mknode(num_children, children, "printContent-String");
    }
|   print_content exp { 
        printf("Parser found print_content-exp\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        $$.nd = mknode(num_children, children, "printContent-exp");
    }
|   print_content telugu_punctuation_comma telugu_string { 
        printf("Parser found print_content-comma-String\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd;
        $$.nd = mknode(num_children, children, "print_content-comma-String");
    }
|   print_content telugu_punctuation_comma exp { 
        printf("Parser found print_content-comma-exp\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd;
        $$.nd = mknode(num_children, children, "print_content-comma-exp");
    }

print_statement:
    telugu_print telugu_open_curly_bracket print_content telugu_closed_curly_bracket { 
        printf("Parser found printStatement\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd;
        children[3] = $4.nd;
        $$.nd = mknode(num_children, children, "printStatement");
    }

function_declaration:
    telugu_function telugu_identifier telugu_open_curly_bracket parameters_line telugu_closed_curly_bracket telugu_open_floor_bracket function_content telugu_closed_floor_bracket { 
        printf("Parser found equation\n");
        int num_children = 8;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        children[3] = $4.nd;
        children[4] = $5.nd;
        children[5] = $6.nd;
        children[6] = $7.nd;
        children[7] = $8.nd;
        $$.nd = mknode(num_children, children, "func-id-(param){content}");
    }

function_call:
    telugu_identifier telugu_open_curly_bracket identifiers_line telugu_closed_curly_bracket { 
        printf("Parser found id(idLine)Finish\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = $1.nd;
        children[1] = $2.nd;
        children[2] = $3.nd; 
        children[3] = $4.nd;
        $$.nd = mknode(num_children, children, "id(idLine)Finish");
    }
%%

int main(){
    yyparse();
    printtree(head);
    return 0;
}

int yyerror(char *s){
    printf("PARSER ERROR: %s\n",s);
    //return 0;
}

struct node* mknode(int num_children, struct node **children, char *token) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->num_children = num_children;
    newnode->children = children;
    newnode->token = strdup(token);
    return newnode;
}

void printtree(struct node* tree) {
	printf("\n\n Inorder traversal of the Parse Tree: \n\n");
	printInorder(tree);
	printf("\n\n");
}

void printInorder(struct node *tree) {
	if (tree) {
		printf("%s, ", tree->token);
		for (int i = 0; i < tree->num_children; i++) {
			printInorder(tree->children[i]);
		}
	}
}

int search(char *type) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, type)==0) {
			return -1;
			break;
		}
	}
	return 0;
}

void add(char c) {
  q=search(yytext);
  if(!q) {
    if(c == 'H') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Header");
			count++;
		}
		else if(c == 'K') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("N/A");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Keyword\t");
			count++;
		}
		else if(c == 'V') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Variable");
			count++;
		}
		else if(c == 'C') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("CONST");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Constant");
			count++;
		}
		else if(c == 'F') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Function");
			count++;
		}
	}
}

void insert_type() {
	strcpy(type, yytext);
}



