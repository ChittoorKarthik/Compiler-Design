
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "t2parser.y"

    /*definitions*/
    #include <stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include <limits.h>
    // #include"lex.yy.c"  // this is creating multiple definitions

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

    void check_declaration(char *);
	void check_return_type(char *);
	char *get_type(char *);
    char *get_datatype(char *);

    struct dataType {
        char * id_name;
        int used;   // for optimization stage - to check if the declared variable is used anywhere else in the program
        char * data_type;
        char * type;
        int line_no;
        int thisscope;
        int num_params;
        int range[10][2];  // [start index of first computation in icg,end index of assignment in icg for that chunk]
        int range_count;
    } symbol_table[10000];

    int count=0;
    int q;
    char type[10];
    extern int countn;
    extern int scope;
    int curr_num_params=0;
    int curr_num_args=0;
    extern char* yy_text;
    char exp_type[30];  // will be empty if no expression is there
    int sem_errors=0;
	char buff[10000];
	char errors[10][10000];
    int oldscope=-1;
    int performedConstantFolding=0;

    int firstexpvalue=-1000000,secondexpvalue=-1000000;

    // Intermediate code generation
    int ic_idx=0;    // used to index the intermediate 3 address codes to show them together later in output
	int label[10000];     // label stack to store the order of labels in the intermediate code
                        // label number in the intermediate code -> GOTO L4
                        // LABEL L4: ....
    int ifelsetracker=-1;  // used to store the ending label for an if-elseLadder
    int jumpcorrection[10000]; // jumpcorrection[instruction number] = label number after a if-else Ladder
    int lastjumps[10000];
    int lastjumpstackpointer=0;
    int laddercounts[10000];
    int laddercountstackpointer=0;

    int stackpointer=0; // used to index the label stack
    int labelsused=0;   // used to keep track of the number of labels used in the intermediate code
    int looplabel[10000]; // another stack
    int looplabelstackpointer=0; // another stack pointer
    int insNumOfLabel[10000]; // used to store the instruction number of each label

    int gotolabel[10000]; // another stack
    int gotolabelstackpointer=0; // another stack pointer
    
    int rangestart=-1,rangeend=-1;  // used to store the range of instructions for a chunk of variable declaration/assignment code temperorily
    int uselessranges[10000][2];  // used to store the range of instructions for a chunk of useless variable declaration/assignment code overall
    int uselessrangescount=0;

    char icg[10000][20];  // stores the intermediate code instructions themselves as strings
    int isleader[10000];  // stores whether the instruction is a leader or not
    int registerIndex=0;  // used to index the registers used in the intermediate code
    int registers[10000];   // stores the registers used in the intermediate code
    int regstackpointer=0; // used to index the register stack
    int firstreg=-1,secondreg=-1,thirdreg=-1; // used to track regIndices in exp*exp 

    //finish writing the reserved words,there are more reserved words
    const int reserved_count = 13;   // why is this not working for reserved[reserved_count][20]???
	char reserved[13][20] = {"sankhya", "thelu", "aksharam", "pani", "okavela", "lekaokavela",
    "lekapothe", "aithaunte", "ivvu", "thechko","theesko","chupi","theega"};

    int stringToInt(const char *str) {
        int result = 0;
        int sign = 1;
        int i = 0;
        
        // Handling negative numbers
        if (str[0] == '-') {
            sign = -1;
            i = 1;
        }
        
        // Iterate through each character of the string
        for (; str[i] != '\0'; ++i) {
            // Ignore if it's a negative sign (already handled) or positive sign
            if (str[i] == '-' || str[i] == '+') {
                continue;
            }
            
            // Check if character is a digit
            if (str[i] >= '0' && str[i] <= '9') {
                // Update result by multiplying it by 10 and adding the digit
                result = result * 10 + (str[i] - '0');
            } else {
                // If non-digit character encountered, return 0 (or handle error as required)
                return 0;
            }
        }
        
        // Apply sign to the result
        return sign * result;
    }

    // Function to mark a variable as used if found in the symbol table
        void markVariableAsUsed(const char *id_name) {
            for (int i = 0; i < 10000; ++i) {
                if (symbol_table[i].id_name != NULL && strcmp(symbol_table[i].id_name, id_name) == 0) {
                    symbol_table[i].used = 1;
                    return;
                }
            }
        }

    // Function to search for an identifier in the symbol table and return its index if found
    int findIdentifierIndex(char *id_name) {
        for (int i = 0; i < 10000; i++) {
            if (symbol_table[i].id_name != NULL && strcmp(symbol_table[i].id_name, id_name) == 0) {
                return i; // Return the index if found
            }
        }
        return -1; // Return -1 if not found
    }

    // Function to swap two ranges
    void swapRanges(int range1[], int range2[]) {
        int tempStart = range1[0];
        int tempEnd = range1[1];
        range1[0] = range2[0];
        range1[1] = range2[1];
        range2[0] = tempStart;
        range2[1] = tempEnd;
    }

    // Function to sort the 2D array of ranges
    void sortRanges(int ranges[][2], int rangeCount) {
        for (int i = 0; i < rangeCount - 1; i++) {
            for (int j = 0; j < rangeCount - i - 1; j++) {
                if (ranges[j][0] > ranges[j + 1][0]) {
                    swapRanges(ranges[j], ranges[j + 1]);
                }
            }
        }
    }
    



/* Line 189 of yacc.c  */
#line 245 "t2parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     EOL = 258,
     TELUGU_INT = 259,
     TELUGU_FLOAT = 260,
     TELUGU_ARITHMETIC_OPERATOR = 261,
     TELUGU_COMPARISON_OPERATOR = 262,
     TELUGU_ASSIGNMENT_OPERATOR = 263,
     TELUGU_LOGICAL_OPERATOR = 264,
     TELUGU_DATATYPE = 265,
     TELUGU_IF = 266,
     TELUGU_ELIF = 267,
     TELUGU_ELSE = 268,
     TELUGU_WHILE = 269,
     TELUGU_OPEN_FLOOR_BRACKET = 270,
     TELUGU_CLOSED_FLOOR_BRACKET = 271,
     TELUGU_IDENTIFIER = 272,
     TELUGU_STRING = 273,
     TELUGU_OPEN_CURLY_BRACKET = 274,
     TELUGU_CLOSED_CURLY_BRACKET = 275,
     TELUGU_OPEN_SQUARE_BRACKET = 276,
     TELUGU_CLOSED_SQUARE_BRACKET = 277,
     TELUGU_PUNCTUATION_COMMA = 278,
     TELUGU_NEWLINE = 279,
     TELUGU_FINISH = 280,
     TELUGU_FUNCTION = 281,
     TELUGU_RETURN = 282,
     TELUGU_CHARACTER = 283,
     TELUGU_PRINT = 284,
     TELUGU_IMPORT = 285,
     TELUGU_INPUT = 286
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 174 "t2parser.y"
 
	struct var_name { 
		char name[10000]; 
		struct node* nd;
	} nd_obj; 



/* Line 214 of yacc.c  */
#line 321 "t2parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 333 "t2parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   617

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNRULES -- Number of states.  */
#define YYNSTATES  241

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    49,    51,    53,    55,    57,
      59,    61,    63,    65,    67,    69,    71,    73,    75,    76,
      79,    82,    87,    92,    96,    97,   102,   104,   106,   108,
     110,   112,   114,   119,   123,   124,   125,   131,   132,   133,
     139,   140,   141,   147,   148,   154,   155,   158,   161,   162,
     163,   169,   177,   181,   186,   191,   197,   202,   207,   210,
     212,   213,   214,   220,   221,   222,   228,   229,   230,   240,
     241,   244,   245,   246,   247,   260,   261,   264,   269,   270,
     275,   276,   280,   281,   282,   283,   294,   295,   301,   304,
     310,   311,   316,   317,   318,   319,   325,   326,   328,   330,
     332,   336,   338,   339,   340,   346,   347,   355,   358,   361,
     365,   367,   372,   378,   383,   384,   387,   390,   393,   396,
     400,   404,   409,   410,   411,   422,   423
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      33,     0,    -1,    66,    -1,     3,    -1,    17,    -1,    17,
      -1,    17,    -1,    17,    -1,    29,    -1,     4,    -1,    31,
      -1,     5,    -1,    30,    -1,     4,    -1,     5,    -1,    18,
      -1,    28,    -1,     6,    -1,     7,    -1,     8,    -1,     9,
      -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,    14,
      -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,    22,
      -1,    15,    -1,    16,    -1,    23,    -1,    25,    -1,    26,
      -1,    27,    -1,    28,    -1,    -1,    66,    34,    -1,    34,
      66,    -1,    66,    43,    38,    62,    -1,    43,    38,    62,
      66,    -1,    66,    76,    66,    -1,    -1,    66,    67,   114,
      66,    -1,    40,    -1,    42,    -1,    65,    -1,    54,    -1,
      35,    -1,   117,    -1,    35,    57,    68,    58,    -1,    55,
      68,    56,    -1,    -1,    -1,    68,    69,    45,    68,    70,
      -1,    -1,    -1,    68,    71,    48,    68,    72,    -1,    -1,
      -1,    68,    73,    46,    68,    74,    -1,    -1,    35,    57,
      68,    75,    58,    -1,    -1,    34,    76,    -1,    76,    34,
      -1,    -1,    -1,    76,    92,    77,    76,    78,    -1,    76,
      41,    55,    35,    56,    62,    76,    -1,    76,    95,    76,
      -1,    76,   113,    62,    76,    -1,    76,    99,    62,    76,
      -1,    76,    59,    76,    60,    76,    -1,    76,   117,    62,
      76,    -1,    76,   107,    62,    76,    -1,     1,    62,    -1,
      68,    -1,    -1,    -1,    68,    80,    46,    68,    81,    -1,
      -1,    -1,    68,    82,    48,    68,    83,    -1,    -1,    -1,
      50,    55,    79,    85,    56,    59,    76,    86,    60,    -1,
      -1,    34,    87,    -1,    -1,    -1,    -1,    87,    51,    55,
      79,    88,    56,    59,    76,    89,    60,    90,    87,    -1,
      -1,    34,    91,    -1,    52,    59,    76,    60,    -1,    -1,
      84,    87,    93,    91,    -1,    -1,    84,    87,    94,    -1,
      -1,    -1,    -1,    53,    55,    79,    96,    56,    59,    76,
      97,    60,    98,    -1,    -1,    49,    37,    47,   100,    68,
      -1,    49,    37,    -1,    49,    37,    57,    68,    58,    -1,
      -1,   101,    49,    37,    61,    -1,    -1,    -1,    -1,   103,
     101,    49,    37,   104,    -1,    -1,    35,    -1,    44,    -1,
      68,    -1,   105,    61,   105,    -1,   105,    -1,    -1,    -1,
      35,    47,   108,   109,    68,    -1,    -1,    35,    57,    68,
     110,    58,    47,    68,    -1,   111,    34,    -1,    34,   111,
      -1,    76,   111,    76,    -1,    76,    -1,    76,    64,    62,
      76,    -1,    76,    64,    68,    62,    76,    -1,    76,   117,
      62,    76,    -1,    -1,   112,    34,    -1,    34,   112,    -1,
     112,    54,    -1,   112,    68,    -1,   112,    61,    54,    -1,
     112,    61,    68,    -1,    39,    55,   112,    56,    -1,    -1,
      -1,    63,   115,    36,   116,    55,   102,    56,    59,   111,
      60,    -1,    -1,    35,   118,    55,   106,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   196,   196,   209,   211,   214,   222,   226,   228,   231,
     233,   235,   238,   240,   241,   242,   243,   247,   250,   253,
     256,   259,   262,   265,   268,   271,   274,   277,   280,   283,
     286,   289,   292,   307,   313,   318,   321,   324,   330,   331,
     339,   347,   358,   369,   378,   378,   397,   423,   439,   448,
     464,   474,   481,   493,   531,   532,   531,   571,   571,   571,
     598,   598,   598,   634,   634,   650,   651,   659,   667,   687,
     667,   698,   711,   720,   730,   740,   751,   761,   771,   779,
     786,   786,   786,   817,   817,   817,   829,   830,   829,   849,
     850,   859,   861,   862,   858,   881,   882,   890,   903,   902,
     919,   918,   944,   946,   947,   944,   962,   962,   986,  1002,
    1017,  1018,  1031,  1032,  1032,  1032,  1044,  1045,  1054,  1063,
    1072,  1085,  1094,  1094,  1094,  1117,  1117,  1132,  1140,  1148,
    1157,  1164,  1174,  1185,  1197,  1198,  1206,  1214,  1222,  1230,
    1239,  1250,  1262,  1262,  1262,  1283,  1283
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EOL", "TELUGU_INT", "TELUGU_FLOAT",
  "TELUGU_ARITHMETIC_OPERATOR", "TELUGU_COMPARISON_OPERATOR",
  "TELUGU_ASSIGNMENT_OPERATOR", "TELUGU_LOGICAL_OPERATOR",
  "TELUGU_DATATYPE", "TELUGU_IF", "TELUGU_ELIF", "TELUGU_ELSE",
  "TELUGU_WHILE", "TELUGU_OPEN_FLOOR_BRACKET",
  "TELUGU_CLOSED_FLOOR_BRACKET", "TELUGU_IDENTIFIER", "TELUGU_STRING",
  "TELUGU_OPEN_CURLY_BRACKET", "TELUGU_CLOSED_CURLY_BRACKET",
  "TELUGU_OPEN_SQUARE_BRACKET", "TELUGU_CLOSED_SQUARE_BRACKET",
  "TELUGU_PUNCTUATION_COMMA", "TELUGU_NEWLINE", "TELUGU_FINISH",
  "TELUGU_FUNCTION", "TELUGU_RETURN", "TELUGU_CHARACTER", "TELUGU_PRINT",
  "TELUGU_IMPORT", "TELUGU_INPUT", "$accept", "program", "eol",
  "telugu_identifier", "telugu_function_name",
  "telugu_identifier_declaring", "telugu_imported_library", "telugu_print",
  "telugu_int", "telugu_input", "telugu_float", "telugu_import",
  "telugu_constant", "telugu_arithmetic_operator",
  "telugu_comparison_operator", "telugu_assignment_operator",
  "telugu_logical_operator", "telugu_datatype", "telugu_if", "telugu_elif",
  "telugu_else", "telugu_while", "telugu_string",
  "telugu_open_curly_bracket", "telugu_closed_curly_bracket",
  "telugu_open_square_bracket", "telugu_closed_square_bracket",
  "telugu_open_floor_bracket", "telugu_closed_floor_bracket",
  "telugu_punctuation_comma", "telugu_finish", "telugu_function",
  "telugu_return", "telugu_character", "input", "$@1", "exp", "$@2", "$@3",
  "$@4", "$@5", "$@6", "$@7", "$@8", "bunch_of_statements", "$@9", "$@10",
  "condition", "$@11", "$@12", "$@13", "$@14", "if_statement", "$@15",
  "$@16", "elif_repeat", "$@17", "$@18", "$@19", "else_statement",
  "if_else_ladder", "$@20", "$@21", "while_loop", "$@22", "$@23", "$@24",
  "variable_declaration", "$@25", "parameters_repeat", "parameters_line",
  "$@26", "$@27", "identifiers_repeat", "identifiers_line", "equation",
  "$@28", "$@29", "$@30", "function_content", "print_content",
  "print_statement", "function_declaration", "$@31", "$@32",
  "function_call", "$@33", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    44,    44,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    66,
      66,    66,    66,    66,    67,    66,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    70,    68,    71,    72,    68,
      73,    74,    68,    75,    68,    76,    76,    76,    77,    78,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    79,
      80,    81,    79,    82,    83,    79,    85,    86,    84,    87,
      87,    88,    89,    90,    87,    91,    91,    91,    93,    92,
      94,    92,    96,    97,    98,    95,   100,    99,    99,    99,
     101,   101,   102,   103,   104,   102,   105,   105,   105,   105,
     105,   106,   108,   109,   107,   110,   107,   111,   111,   111,
     111,   111,   111,   111,   112,   112,   112,   112,   112,   112,
     112,   113,   115,   116,   114,   118,   117
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     2,
       2,     4,     4,     3,     0,     4,     1,     1,     1,     1,
       1,     1,     4,     3,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     0,     5,     0,     2,     2,     0,     0,
       5,     7,     3,     4,     4,     5,     4,     4,     2,     1,
       0,     0,     5,     0,     0,     5,     0,     0,     9,     0,
       2,     0,     0,     0,    12,     0,     2,     4,     0,     4,
       0,     3,     0,     0,     0,    10,     0,     5,     2,     5,
       0,     4,     0,     0,     0,     5,     0,     1,     1,     1,
       3,     1,     0,     0,     5,     0,     7,     2,     2,     3,
       1,     4,     5,     4,     0,     2,     2,     2,     2,     3,
       3,     4,     0,     0,    10,     0,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      38,     3,    12,     0,    38,     0,     0,     1,     0,     7,
       0,     0,     0,     0,     0,    38,    34,    38,    78,     0,
      66,     0,    35,   142,    38,    21,    22,    25,    31,     4,
       8,    10,    38,   145,     0,     0,     0,     0,     0,     0,
       0,    89,    68,     0,     0,     0,     0,     0,     0,    67,
      41,     0,     0,    19,    29,   122,     0,     0,    27,   134,
       0,     6,   108,     0,     0,     0,    89,    98,     0,    72,
       0,     0,     0,     0,     5,   143,   123,     9,    11,    26,
      37,    50,    46,    47,    49,     0,    48,    54,    51,   116,
     134,     0,     0,   106,     0,    54,    86,   102,    32,     0,
      90,    23,     0,    95,   101,    69,    74,    77,    73,    76,
       0,     0,     0,    54,     0,     0,     0,     0,     9,    11,
      26,    37,    50,   118,   119,   121,     0,   136,    28,    33,
     135,    49,   141,     0,   138,     0,     0,    54,     0,     0,
       0,     0,    75,     0,    24,    95,     0,    99,    70,   112,
      54,    54,    53,    17,     0,    20,     0,    18,     0,    30,
       0,   116,   146,    49,   140,     0,    54,   109,     0,     0,
       0,     0,    91,    96,     0,     0,   110,    52,     0,    55,
      58,    61,     0,   120,    71,    54,    54,     0,     0,     0,
       0,     0,     0,    64,    56,    59,    62,    54,    82,    85,
      87,   103,     0,    97,     0,     0,     0,     0,     0,     0,
       0,     0,   114,    88,   104,    92,     0,   128,    36,     0,
       0,     0,     0,   127,   144,   111,   115,   105,     0,     0,
      54,     0,   129,     0,    93,   131,     0,    76,    89,   132,
      94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    19,    33,    75,    62,    10,    34,    82,    35,
      83,     5,   123,   154,   158,    55,   156,    36,    37,   102,
     146,    38,    84,    85,   132,   112,   160,    39,    99,   133,
      17,    23,   220,    86,     8,    14,    95,   114,   194,   115,
     195,   116,   196,   178,    15,    68,   148,    96,   138,   198,
     139,   199,    41,   140,   206,    67,   189,   228,   238,   147,
      42,   103,   104,    43,   141,   207,   227,    44,   136,   192,
     175,   176,   226,   125,   126,    45,    76,   111,   117,   217,
      91,    46,    24,    51,   110,    88,    57
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -136
static const yytype_int16 yypact[] =
{
       7,  -136,  -136,    46,     7,    30,   409,  -136,   433,  -136,
      50,    50,   455,    30,    45,   552,  -136,     7,  -136,   374,
     574,    50,  -136,  -136,     7,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,     7,     6,    65,    65,   104,    65,    65,   154,
     477,   129,  -136,   374,    50,    50,    50,    50,   499,  -136,
    -136,   120,   521,  -136,  -136,  -136,   413,    65,  -136,   129,
     123,  -136,     6,   413,   413,   243,   129,   146,   374,   574,
     374,   374,   374,   374,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,   140,  -136,  -136,  -136,   413,  -136,    16,  -136,   582,
     129,   589,   142,  -136,   413,   147,  -136,  -136,  -136,   374,
     146,  -136,    65,    13,  -136,   574,   574,   574,   574,   574,
      65,   413,   413,   171,   157,   163,   167,   155,  -136,  -136,
      31,    56,    62,  -136,   122,   156,   142,   285,  -136,  -136,
    -136,  -136,  -136,   413,   122,    50,   413,   144,   167,   163,
     142,   142,   574,   413,  -136,    13,   172,  -136,  -136,   184,
      24,   144,  -136,  -136,   413,  -136,   413,  -136,   413,  -136,
     187,   582,  -136,  -136,   122,   374,    85,  -136,   413,   413,
     172,   172,  -136,  -136,   154,   142,  -136,  -136,   155,   190,
      12,   122,   413,   156,   574,   179,   205,   154,   154,   142,
     243,   172,   193,  -136,  -136,  -136,  -136,    95,  -136,  -136,
     574,   574,   172,  -136,   324,   104,   181,   181,   154,   324,
     543,    52,   156,  -136,  -136,   574,   543,   129,  -136,   324,
      68,   154,    50,  -136,  -136,  -136,  -136,  -136,   181,   154,
     116,   154,   574,   324,  -136,   574,   154,   574,   129,   574,
     146
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,     0,   188,  -136,    -7,   192,  -136,  -136,  -136,
    -136,    22,  -136,  -136,    75,   -49,    67,    34,  -136,  -136,
    -136,  -136,   -69,    79,   -63,   -28,   -98,  -135,   -68,  -123,
      -2,  -136,  -136,  -136,   135,  -136,   225,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,    76,  -136,  -136,   -61,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,   -65,  -136,  -136,  -136,    77,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,    69,  -136,  -136,  -136,  -136,  -136,   -86,
     133,  -136,  -136,  -136,  -136,    -8,  -136
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -146
static const yytype_int16 yytable[] =
{
       4,   100,   161,    97,     4,    56,    12,    47,    12,    18,
       1,   174,    47,    93,    53,    32,     1,     4,   -54,    50,
      49,   -57,   131,   -60,     4,   -57,   144,    54,    13,   135,
      13,   -60,     4,   -57,    94,   187,   188,     2,  -125,   167,
      12,    66,    70,    71,    72,    73,     7,     9,    12,  -124,
     152,   -15,    12,   177,   -15,     1,   204,    47,   131,    90,
     161,    47,    13,   162,   163,    49,    66,   208,    98,    49,
      13,    22,    77,    78,    13,    16,   -16,   170,   171,   -16,
     193,  -145,   172,    54,    58,    29,    79,    58,    20,   225,
      90,   130,   -60,    16,   -57,    20,    80,    47,    47,    47,
      47,    47,   -60,   145,   -57,    49,    49,    49,    49,    49,
    -107,   182,   191,    59,    60,    65,    63,    64,   211,    69,
    -126,    61,   203,   -60,   221,   -57,   202,   130,   -54,   -60,
     221,   -57,     1,   165,    47,     6,    89,    74,   213,   214,
      29,    16,    49,   224,   105,   145,   106,   107,   108,   109,
      40,   -60,    48,   -57,   -60,    11,   -57,     1,   101,    52,
     234,    54,   128,   153,   -65,   -65,   159,   -79,   -65,   -65,
     -65,   -65,   155,   240,   157,   142,    47,   159,   -60,   129,
     -57,   143,    47,   -65,    49,   -65,   -60,    28,   -57,   149,
      49,   128,    47,    47,  -113,    53,   -54,    98,   212,   -81,
      49,    49,   222,    25,   209,    21,   169,    47,   222,   209,
     219,   223,   -60,   168,   -57,    49,   219,   223,   229,   209,
     233,   231,   173,   127,    47,   -84,   205,    47,   236,    47,
     183,    47,    49,     0,     0,    49,     0,    49,    66,    49,
       0,   184,     0,     0,    81,     0,     1,     0,    92,     0,
     190,    81,    81,    25,    26,     0,     0,    27,    28,    98,
      29,     0,     0,   200,   201,     0,     0,     0,     0,     0,
       0,     0,    30,    81,    31,     0,     0,   122,     0,    81,
     210,    87,    81,     0,   215,   216,   210,     0,     1,    77,
      78,     0,   210,     0,     0,   216,     0,   232,     0,    81,
      81,     0,    29,    79,    58,   235,     0,    20,   129,   237,
     113,     0,   239,    80,   124,    81,   134,     0,     0,   137,
       0,    81,     0,     0,    81,    11,     0,     1,     0,     0,
       0,    81,     0,     0,   -65,   -65,   150,   151,   -65,   -65,
     -65,   -65,    81,     0,    81,     0,    81,     0,     0,   122,
       0,   -65,   134,   -65,     0,   -65,    81,    81,   164,     0,
       0,   166,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,   -65,    11,     0,     1,     0,   179,
       0,   180,     0,   181,   -65,   -65,   124,     0,   -65,   -65,
     -65,   -65,     0,   185,   186,     0,     0,     0,     0,     0,
     -65,   -65,     0,   -65,   -65,   -65,     0,   197,    81,    -2,
      11,     0,     1,     0,     0,     0,     0,    77,    78,   -65,
     -65,     0,     0,   -65,   -65,     0,   -65,     0,     0,     0,
      29,    79,    58,   -40,    11,   -44,     1,     0,   -65,     2,
     -65,    80,     0,   -40,   -40,   230,     0,   -40,   -40,     0,
     -40,     0,     0,     0,     0,   -39,    11,     0,     1,   -40,
       0,     0,   -40,     2,   -40,   -39,   -39,     0,     0,   -39,
     -39,     0,   -39,     0,     0,     0,     0,   -43,    11,     0,
       1,   -39,     0,     0,   -39,   -39,   -39,   -43,   -43,     0,
       0,   -43,   -43,     0,   -43,     0,     0,     0,     0,   -42,
      11,     0,     1,   -43,     0,     0,   -43,     2,   -43,   -42,
     -42,     0,     0,   -42,   -42,     0,   -42,     0,     0,     0,
       0,   -45,    11,     0,     1,   -42,     0,     0,   -42,     2,
     -42,   -45,   -45,     0,     0,   -45,   -45,     0,   -45,     0,
       0,     0,     0,     0,    11,     0,     1,   -44,     0,     0,
     -45,     2,   -45,    25,    26,     1,     0,    27,    28,   -65,
      29,     0,    25,    26,     0,     0,    27,    28,     0,    29,
     218,     0,    30,     0,    31,     0,     0,     1,     0,     0,
       0,    30,     2,    31,    25,    26,   118,   119,    27,    28,
       0,    29,     1,    77,    78,     0,     0,     0,     0,    29,
     120,    58,     0,    30,     0,    31,    29,    79,    58,   128,
     121,     0,   129,     0,     0,     0,     0,    80
};

static const yytype_int16 yycheck[] =
{
       0,    66,   125,    64,     4,    33,     6,    15,     8,    11,
       3,   146,    20,    62,     8,    15,     3,    17,     6,    21,
      20,     9,    91,     7,    24,     9,    13,    21,     6,    92,
       8,     7,    32,     9,    62,   170,   171,    30,    22,   137,
      40,    41,    44,    45,    46,    47,     0,    17,    48,    25,
     113,    20,    52,   151,    23,     3,   191,    65,   127,    59,
     183,    69,    40,   126,   133,    65,    66,   202,    16,    69,
      48,    26,     4,     5,    52,    25,    20,   140,   141,    23,
     178,    19,   143,    21,    19,    17,    18,    19,    12,   212,
      90,    91,     7,    25,     9,    19,    28,   105,   106,   107,
     108,   109,     7,   103,     9,   105,   106,   107,   108,   109,
      25,   160,   175,    34,    35,    39,    37,    38,   204,    43,
      25,    17,   190,     7,   210,     9,   189,   127,     6,     7,
     216,     9,     3,   135,   142,     0,    57,    17,   206,   207,
      17,    25,   142,   211,    68,   145,    70,    71,    72,    73,
      15,     7,    17,     9,     7,     1,     9,     3,    12,    24,
     228,    21,    20,     6,    10,    11,    22,    20,    14,    15,
      16,    17,     9,   238,     7,    99,   184,    22,     7,    23,
       9,   102,   190,    29,   184,    31,     7,    15,     9,   110,
     190,    20,   200,   201,    10,     8,     6,    16,   205,    20,
     200,   201,   210,    10,   204,    13,   139,   215,   216,   209,
     210,   211,     7,   138,     9,   215,   216,   217,   220,   219,
     222,   221,   145,    90,   232,    20,   192,   235,   230,   237,
     161,   239,   232,    -1,    -1,   235,    -1,   237,   238,   239,
      -1,   165,    -1,    -1,    56,    -1,     3,    -1,    60,    -1,
     174,    63,    64,    10,    11,    -1,    -1,    14,    15,    16,
      17,    -1,    -1,   187,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    85,    31,    -1,    -1,    89,    -1,    91,
     204,    56,    94,    -1,   208,   209,   210,    -1,     3,     4,
       5,    -1,   216,    -1,    -1,   219,    -1,   221,    -1,   111,
     112,    -1,    17,    18,    19,   229,    -1,   231,    23,   233,
      85,    -1,   236,    28,    89,   127,    91,    -1,    -1,    94,
      -1,   133,    -1,    -1,   136,     1,    -1,     3,    -1,    -1,
      -1,   143,    -1,    -1,    10,    11,   111,   112,    14,    15,
      16,    17,   154,    -1,   156,    -1,   158,    -1,    -1,   161,
      -1,    27,   127,    29,    -1,    31,   168,   169,   133,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,    -1,    -1,    -1,     0,     1,    -1,     3,    -1,   154,
      -1,   156,    -1,   158,    10,    11,   161,    -1,    14,    15,
      16,    17,    -1,   168,   169,    -1,    -1,    -1,    -1,    -1,
      26,    27,    -1,    29,    30,    31,    -1,   182,   220,     0,
       1,    -1,     3,    -1,    -1,    -1,    -1,     4,     5,    10,
      11,    -1,    -1,    14,    15,    -1,    17,    -1,    -1,    -1,
      17,    18,    19,     0,     1,    26,     3,    -1,    29,    30,
      31,    28,    -1,    10,    11,   220,    -1,    14,    15,    -1,
      17,    -1,    -1,    -1,    -1,     0,     1,    -1,     3,    26,
      -1,    -1,    29,    30,    31,    10,    11,    -1,    -1,    14,
      15,    -1,    17,    -1,    -1,    -1,    -1,     0,     1,    -1,
       3,    26,    -1,    -1,    29,    30,    31,    10,    11,    -1,
      -1,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,     0,
       1,    -1,     3,    26,    -1,    -1,    29,    30,    31,    10,
      11,    -1,    -1,    14,    15,    -1,    17,    -1,    -1,    -1,
      -1,     0,     1,    -1,     3,    26,    -1,    -1,    29,    30,
      31,    10,    11,    -1,    -1,    14,    15,    -1,    17,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,    26,    -1,    -1,
      29,    30,    31,    10,    11,     3,    -1,    14,    15,    16,
      17,    -1,    10,    11,    -1,    -1,    14,    15,    -1,    17,
      27,    -1,    29,    -1,    31,    -1,    -1,     3,    -1,    -1,
      -1,    29,    30,    31,    10,    11,     4,     5,    14,    15,
      -1,    17,     3,     4,     5,    -1,    -1,    -1,    -1,    17,
      18,    19,    -1,    29,    -1,    31,    17,    18,    19,    20,
      28,    -1,    23,    -1,    -1,    -1,    -1,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    30,    33,    34,    43,    66,     0,    66,    17,
      38,     1,    34,    43,    67,    76,    25,    62,    62,    34,
      76,    38,    26,    63,   114,    10,    11,    14,    15,    17,
      29,    31,    34,    35,    39,    41,    49,    50,    53,    59,
      66,    84,    92,    95,    99,   107,   113,   117,    66,    34,
      62,   115,    66,     8,    21,    47,    57,   118,    19,    55,
      55,    17,    37,    55,    55,    76,    34,    87,    77,    76,
      62,    62,    62,    62,    17,    36,   108,     4,     5,    18,
      28,    35,    40,    42,    54,    55,    65,    68,   117,    55,
      34,   112,    35,    47,    57,    68,    79,    79,    16,    60,
      87,    12,    51,    93,    94,    76,    76,    76,    76,    76,
     116,   109,    57,    68,    69,    71,    73,   110,     4,     5,
      18,    28,    35,    44,    68,   105,   106,   112,    20,    23,
      34,    54,    56,    61,    68,    56,   100,    68,    80,    82,
      85,    96,    76,    55,    13,    34,    52,    91,    78,    55,
      68,    68,    56,     6,    45,     9,    48,     7,    46,    22,
      58,    61,    56,    54,    68,    62,    68,    58,    46,    48,
      56,    56,    79,    91,    59,   102,   103,    58,    75,    68,
      68,    68,    47,   105,    76,    68,    68,    59,    59,    88,
      76,    56,   101,    58,    70,    72,    74,    68,    81,    83,
      76,    76,    56,    60,    59,    49,    86,    97,    59,    34,
      76,   111,    37,    60,    60,    76,    76,   111,    27,    34,
      64,   111,   117,    34,    60,    61,   104,    98,    89,    62,
      68,    34,    76,    62,    60,    76,    62,    76,    90,    76,
      87
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 196 "t2parser.y"
    {int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        
        // Assigning children nodes
        children[0] = (yyvsp[(1) - (1)].nd_obj).nd;  // Assuming $1 represents the parse tree node for symbol1
        // Assign more children if needed
        
        // Create the parse tree node for the production rule
        (yyval.nd_obj).nd = mknode(num_children, children, "program");
         head = (yyval.nd_obj).nd;;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 209 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, "newline");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 211 "t2parser.y"
    {printf("CHECKING FOR %s\n",(yyvsp[(1) - (1)].nd_obj).name);check_declaration((yyvsp[(1) - (1)].nd_obj).name); printf("saw pure id2");(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 214 "t2parser.y"
    {printf("parser saw teluguFuncNamex");
    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 222 "t2parser.y"
    { printf("saw varDeclareid");add('V');(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 226 "t2parser.y"
    { add('L');(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 228 "t2parser.y"
    {add('K');(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 231 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);add('i');;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 233 "t2parser.y"
    {add('K');(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 235 "t2parser.y"
    {add('f');(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 238 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 240 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);add('i');;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 241 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);add('f');;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 242 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);add('s');;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 243 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);add('c');;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 247 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 250 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 253 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 256 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 259 "t2parser.y"
    {insert_type();(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 262 "t2parser.y"
    {add('K');(yyval.nd_obj).nd = mknode(NULL, NULL, "if");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 265 "t2parser.y"
    {add('K');(yyval.nd_obj).nd = mknode(NULL, NULL, "elif");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 268 "t2parser.y"
    {add('K');(yyval.nd_obj).nd = mknode(NULL, NULL, "else");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 271 "t2parser.y"
    {add('K');(yyval.nd_obj).nd = mknode(NULL, NULL,"while");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 274 "t2parser.y"
    {add('s');(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 277 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 280 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 283 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 286 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 289 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);scope++;;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 292 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);
        //here we need to remove all the variables declared in this scope
        // change all of their scope to INT_MAX
            int i;
            for(i=count-1; i>=0; i--) {
                if(symbol_table[i].thisscope == scope && 
                        strcmp(symbol_table[i].type, "Variable")==0) {
                    symbol_table[i].thisscope = INT_MAX;
                    printf("\nERASING %s from symbol table as its CURRENT SCOPE is FINISHED\n", symbol_table[i].id_name);
                }
            }
        scope--;
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 307 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 313 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name); 
        strcpy(exp_type," ");
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 318 "t2parser.y"
    {add('K');(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 321 "t2parser.y"
    {add('K');(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 324 "t2parser.y"
    {add('c');(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 330 "t2parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "empty"); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 331 "t2parser.y"
    { 
        printf("Parser found input-eol\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "input-eol");
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 339 "t2parser.y"
    { 
        printf("Parser found eol-input\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "eol-input");
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 347 "t2parser.y"
    { 
        //add('H');
        printf("Parser found input-import-lib-;\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "input-import-lib-;");
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 358 "t2parser.y"
    { 
        //add('H');
        printf("Parser found import-lib-;-input\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "import-lib-;-input");
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 369 "t2parser.y"
    { 
        printf("Parser found input-bunch_of_stmts-input\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd; 
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "input-bunch-input");
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 378 "t2parser.y"
    {insNumOfLabel[labelsused]=ic_idx; sprintf(icg[ic_idx++], "LABEL L%d:\n", labelsused++);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 378 "t2parser.y"
    { 
        //add('F');
        printf("Parser found input-functionDec-input\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(3) - (4)].nd_obj).nd; 
        children[2] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "input-funDec-input");
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 397 "t2parser.y"
    {    
                    if(strcmp(exp_type," ")==0) {
                        strcpy(exp_type, "sankhya");
                    }
                    else if(strcmp(exp_type, "theega")==0) {
                        sprintf(errors[sem_errors], "Line %d: operation among int and string in expression not allowed\n", countn+1);
                        sem_errors++;
                    }
                    printf("Parser found int\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = (yyvsp[(1) - (1)].nd_obj).nd;  
                    (yyval.nd_obj).nd = mknode(num_children, children, "INT");

                    // if(firstreg == -1){
                    //     firstreg = registerIndex++;
                    //     sprintf(icg[ic_idx++], "R%d = %s\n", firstreg, $1.name);
                    // }
                    // else{
                    //     secondreg = registerIndex++;
                    //     sprintf(icg[ic_idx++], "R%d = %s\n", secondreg, $1.name);
                    // }
                    registers[regstackpointer++]=registerIndex;
                    sprintf(icg[ic_idx++], "MOV R%d , %s\n", (registerIndex++)-1, (yyvsp[(1) - (1)].nd_obj).name);

                ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 423 "t2parser.y"
    {
                    if(strcmp(exp_type," ")==0) {
                        strcpy(exp_type, "thelu");
                    }
                    else if(strcmp(exp_type, "theega")==0) {
                        sprintf(errors[sem_errors], "Line %d: operation among float and string in expression not allowed\n", countn+1);
                        sem_errors++;
                    }
                    printf("Parser found float\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = (yyvsp[(1) - (1)].nd_obj).nd;  
                    (yyval.nd_obj).nd = mknode(num_children, children, "FLOAT");
                    registers[regstackpointer++]=registerIndex;
                    sprintf(icg[ic_idx++], "MOV R%d , %s\n",( registerIndex++)-1, (yyvsp[(1) - (1)].nd_obj).name);
                ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 439 "t2parser.y"
    {
                    printf("Parser found character\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = (yyvsp[(1) - (1)].nd_obj).nd;  
                    (yyval.nd_obj).nd = mknode(num_children, children, "CHAR");
                    registers[regstackpointer++]=registerIndex;
                    sprintf(icg[ic_idx++], "MOV R%d , %s\n", (registerIndex++)-1, (yyvsp[(1) - (1)].nd_obj).name);
                ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 448 "t2parser.y"
    {
                    if(strcmp(exp_type," ")==0) {
                        strcpy(exp_type, "theega");
                    }
                    else if(strcmp(exp_type, "sankhya")==0 || strcmp(exp_type, "thelu")==0) {
                        sprintf(errors[sem_errors], "Line %d: operation among string and int/float in expression not allowed\n", countn+1);
                        sem_errors++;
                    }
                    printf("Parser found string\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = (yyvsp[(1) - (1)].nd_obj).nd;  
                    (yyval.nd_obj).nd = mknode(num_children, children, "STRING");
                    registers[regstackpointer++]=registerIndex;
                    sprintf(icg[ic_idx++], "MOV R%d , %s\n", (registerIndex++)-1, (yyvsp[(1) - (1)].nd_obj).name);
                ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 464 "t2parser.y"
    {
                    printf("Parser found identifier\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = (yyvsp[(1) - (1)].nd_obj).nd;  
                    (yyval.nd_obj).nd = mknode(num_children, children, "ID");
                    registers[regstackpointer++]=registerIndex;
                    sprintf(icg[ic_idx++], "MOV R%d , %s\n", (registerIndex++)-1, (yyvsp[(1) - (1)].nd_obj).name);
                    markVariableAsUsed((yyvsp[(1) - (1)].nd_obj).name);  // optimization stage
                ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 474 "t2parser.y"
    {
                    printf("Parser found funcCall\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = (yyvsp[(1) - (1)].nd_obj).nd;  
                    (yyval.nd_obj).nd = mknode(num_children, children, "funcCall");
                ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 481 "t2parser.y"
    {
                    printf("Parser found id[exp]\n");
                    int num_children = 4;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = (yyvsp[(1) - (4)].nd_obj).nd;  
                    children[1] = (yyvsp[(2) - (4)].nd_obj).nd; 
                    children[2] = (yyvsp[(3) - (4)].nd_obj).nd; 
                    children[3] = (yyvsp[(4) - (4)].nd_obj).nd; 
                    (yyval.nd_obj).nd = mknode(num_children, children, "ID[exp]");
                    //registers[regstackpointer++]=registerIndex;
                    sprintf(icg[ic_idx++], "MOV R%d , %s+R%d\n", registerIndex , (yyvsp[(1) - (4)].nd_obj).name,registerIndex-1);
                ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 493 "t2parser.y"
    { 
        printf("Parser found (exp)\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        
        // Assigning children nodes
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;  // Assuming $1 represents the parse tree node for symbol1
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd;  // Assuming $2 represents the parse tree node for symbol2
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "(exp)");
        
        // Free the memory allocated for the array of children
        //free(children);
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 531 "t2parser.y"
    {firstreg = registerIndex-1;registers[registerIndex-1]=firstreg;;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 532 "t2parser.y"
    {secondreg = registerIndex-1;registers[registerIndex-1]=secondreg;;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 532 "t2parser.y"
    { 
        printf("Parser found exp-arithmeticOp-exp\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        
        // Assigning children nodes
        children[0] = (yyvsp[(1) - (5)].nd_obj).nd;  // Assuming $1 represents the parse tree node for symbol1
        children[1] = (yyvsp[(3) - (5)].nd_obj).nd;  // Assuming $2 represents the parse tree node for symbol2
        children[2] = (yyvsp[(4) - (5)].nd_obj).nd;
        // Assign more children if needed
        
        // Create the parse tree node for the production rule
        (yyval.nd_obj).nd = mknode(num_children, children, "AthematicOp");
        
        // Free the memory allocated for the array of children
        //free(children);
        regstackpointer--;
        if(((yyvsp[(3) - (5)].nd_obj).name)[0] == '+')
            sprintf(icg[ic_idx++], "ADD R%d , R%d\n", secondreg , registers[--regstackpointer]-1);
        else if(((yyvsp[(3) - (5)].nd_obj).name)[0] == '-')
            sprintf(icg[ic_idx++], "SUB R%d , R%d\n", secondreg-1 , registers[--regstackpointer]-1);
        else if(((yyvsp[(3) - (5)].nd_obj).name)[0] == '*')
            sprintf(icg[ic_idx++], "MUL R%d , R%d\n", secondreg , registers[--regstackpointer]-1);
        else if(((yyvsp[(3) - (5)].nd_obj).name)[0] == '/')
            sprintf(icg[ic_idx++], "DIV R%d , R%d\n", secondreg , registers[--regstackpointer]-1);
        else if(((yyvsp[(3) - (5)].nd_obj).name)[0] == '%')
            sprintf(icg[ic_idx++], "MOD R%d , R%d\n", secondreg , registers[--regstackpointer]-1);
        else{
            sprintf(icg[ic_idx++], "R%d = R%d %c R%d\n", secondreg , registers[--regstackpointer]-1, ((yyvsp[(3) - (5)].nd_obj).name)[0],secondreg);
        }

        // // CONSTANT FOLDING
        // if(($3.name)[0] == '+')
        //     sprintf(icg[ic_idx++], "MOV R%d , %d\n", secondreg , registers[--regstackpointer]-1);

        //secondreg = firstreg;
        //first = registers[regstackpointer];
      
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 571 "t2parser.y"
    {firstreg = registerIndex-1;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 571 "t2parser.y"
    {secondreg = registerIndex-1;;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 571 "t2parser.y"
    { 
        printf("Parser found exp-logicalOp-exp\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (5)].nd_obj).nd;
        children[1] = (yyvsp[(3) - (5)].nd_obj).nd; 
        children[2] = (yyvsp[(4) - (5)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "LogicalOp");
        //sprintf(icg[ic_idx++], "R%d = R%d %s R%d\n", secondreg , firstreg, $3.name, secondreg);
        if (strcmp((yyvsp[(3) - (5)].nd_obj).name, "mariyu") == 0) {
            sprintf(icg[ic_idx++], "AND R%d , R%d\n", secondreg , firstreg);
        }
        else if (strcmp((yyvsp[(3) - (5)].nd_obj).name, "leda") == 0) {
            sprintf(icg[ic_idx++], "OR R%d , R%d\n", secondreg , firstreg);
        }  
        // else if (strcmp($3.name, "kaadu") == 0) {
        //     sprintf(icg[ic_idx++], "NOT R%d , R%d\n", secondreg , firstreg);
        // }  
        else if (strcmp((yyvsp[(3) - (5)].nd_obj).name, "pratyekam") == 0) {
            sprintf(icg[ic_idx++], "XOR R%d , R%d\n", secondreg , firstreg);
        }
        else{
            sprintf(icg[ic_idx++], "R%d = R%d %s R%d\n", secondreg , firstreg, (yyvsp[(3) - (5)].nd_obj).name,secondreg);
        }  


    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 598 "t2parser.y"
    {firstreg = registerIndex-1;;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 598 "t2parser.y"
    {secondreg = registerIndex-1;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 598 "t2parser.y"
    { 
        printf("Parser found exp-compOp-exp\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (5)].nd_obj).nd;
        children[1] = (yyvsp[(3) - (5)].nd_obj).nd; 
        children[2] = (yyvsp[(4) - (5)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "CompOp");
        //sprintf(icg[ic_idx++], "R%d = R%d %s R%d\n", secondreg , firstreg, $3.name, secondreg);
        if (strcmp((yyvsp[(3) - (5)].nd_obj).name, "chinnadi") == 0) {
            sprintf(icg[ic_idx++], "LT R%d , R%d\n", secondreg , firstreg);
        }
        else if (strcmp((yyvsp[(3) - (5)].nd_obj).name, "peddadi") == 0) {
            sprintf(icg[ic_idx++], "GT R%d , R%d\n", secondreg , firstreg);
        }  
        // else if (strcmp($3.name, "kaadu") == 0) {
        //     sprintf(icg[ic_idx++], "NOT R%d , R%d\n", secondreg , firstreg);
        // }  
        else if (strcmp((yyvsp[(3) - (5)].nd_obj).name, "peddadiLedaSamanam") == 0) {
            sprintf(icg[ic_idx++], "GE R%d , R%d\n", secondreg , firstreg);
        }  
        else if (strcmp((yyvsp[(3) - (5)].nd_obj).name, "chinnadiLedaSamanam") == 0) {
            sprintf(icg[ic_idx++], "LE R%d , R%d\n", secondreg , firstreg);
        }  
        else if (strcmp((yyvsp[(3) - (5)].nd_obj).name, "samanam") == 0) {
            sprintf(icg[ic_idx++], "EQ R%d , R%d\n", secondreg , firstreg);
        }  
        else if (strcmp((yyvsp[(3) - (5)].nd_obj).name, "bhinnam") == 0) {
            sprintf(icg[ic_idx++], "NE R%d , R%d\n", secondreg , firstreg);
        }  
        else{
            sprintf(icg[ic_idx++], "R%d = R%d %s R%d\n", secondreg , firstreg, (yyvsp[(3) - (5)].nd_obj).name,secondreg);
        }  


    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 634 "t2parser.y"
    {registers[regstackpointer++]=registerIndex;
        sprintf(icg[ic_idx++], "MOV R%d , %s + R%d\n", registerIndex , (yyvsp[(1) - (3)].nd_obj).name, registerIndex-1);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 635 "t2parser.y"
    { 
        printf("Parser found id[exp]\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (5)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (5)].nd_obj).nd; 
        children[2] = (yyvsp[(3) - (5)].nd_obj).nd;
        children[3] = (yyvsp[(5) - (5)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "id[exp]");
        //sprintf(icg[ic_idx++], "MOV R%d , %s + R%d\n", firstreg , $1.name, firstreg);
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 650 "t2parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "empty"); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 651 "t2parser.y"
    { 
        printf("Parser found EOL-bunch\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "eol-bunch");
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 659 "t2parser.y"
    { 
        printf("Parser found bunch-EOL\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "bunch-eol");
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 667 "t2parser.y"
    {
            insNumOfLabel[labelsused]=ic_idx; 
            sprintf(icg[ic_idx++], "LABEL L%d:\n", labelsused++);
            //lastjumps[lastjumpstackpointer++] = label[stackpointer-2];
            int index = ic_idx - 1;
            int count = laddercounts[laddercountstackpointer-1]; // Number of iterations

            for (int i = index; i >= 0 && count > 0; i--) {
                printf("icg[%d] = %s\n", i, icg[i]);
                if (strncmp(icg[i], "JUMP ", 5) == 0) { // Check if the prefix matches "JUMP "
                    printf("...................\n");
                    char jump_str[20]; // Assuming the number won't exceed 20 digits
                    sprintf(jump_str, "%d", labelsused-1); // Convert number to string
                    snprintf(icg[i], 20, "JUMPx L%s\n", jump_str); // Set icg[i] to "JUMP" followed by the number
                    count--;
                }
            }
            lastjumpstackpointer--;  // forgetting the current ifelseLadder's lastjump and counts
            laddercountstackpointer--;
        
        ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 687 "t2parser.y"
    {

        ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 689 "t2parser.y"
    { 
        printf("Parser found bunch_of_statement if_else_ladder bunch\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (5)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (5)].nd_obj).nd;
        children[2] = (yyvsp[(4) - (5)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "bunch-IfElse-bunch");
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 698 "t2parser.y"
    { 
        printf("Parser found bunch_of_statement-inputscan-bunch\n");
        int num_children = 7;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (7)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (7)].nd_obj).nd; 
        children[2] = (yyvsp[(3) - (7)].nd_obj).nd;
        children[3] = (yyvsp[(4) - (7)].nd_obj).nd;
        children[4] = (yyvsp[(5) - (7)].nd_obj).nd;
        children[5] = (yyvsp[(6) - (7)].nd_obj).nd;
        children[6] = (yyvsp[(7) - (7)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "bunch-inputScan-bunch");
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 711 "t2parser.y"
    { 
        printf("Parser found bunch_of_statement while_loop bunch\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd; 
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "bunch-while-bunch");
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 720 "t2parser.y"
    { 
        printf("Parser found bunch-printStmt-finish\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd; 
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd;
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "bunch-printStmt-;-bunch");
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 730 "t2parser.y"
    { 
        printf("Parser found bunch-varDeclare-finish\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd; 
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd;
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "bunch-varDeclare-;-bunch");
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 740 "t2parser.y"
    {
        printf("parser found bunch {bunch}\n");
        int num_children = 5;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (5)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (5)].nd_obj).nd; 
        children[2] = (yyvsp[(3) - (5)].nd_obj).nd;
        children[3] = (yyvsp[(4) - (5)].nd_obj).nd;
        children[4] = (yyvsp[(5) - (5)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "bunch-{bunch}-bunch");
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 751 "t2parser.y"
    { 
        printf("Parser found bunch-functionCall-;\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd; 
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "bunch-functionCall-;-bunch");
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 761 "t2parser.y"
    { 
        printf("Parser found bunch-equation-finish\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd; 
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd;
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "bunch-equation-;-bunch");
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 771 "t2parser.y"
    {
        printf("PARSER ERROR: syntax error \n");
        int num_children = 0;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        (yyval.nd_obj).nd = mknode(num_children, children, "error-;");
;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 779 "t2parser.y"
    { 
        printf("Parser found exp as condition\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (1)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "condition");
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 786 "t2parser.y"
    {firstreg = registerIndex-1;;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 786 "t2parser.y"
    {secondreg = registerIndex-1;;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 786 "t2parser.y"
    { 
        printf("Parser found exp-compareOp-exp\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (5)].nd_obj).nd;
        children[1] = (yyvsp[(3) - (5)].nd_obj).nd; 
        children[2] = (yyvsp[(4) - (5)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "condition");
        
        //sprintf(icg[ic_idx++], "R%d = R%d %s R%d\n", secondreg , firstreg, $3.name, secondreg);
        if (strcmp((yyvsp[(3) - (5)].nd_obj).name, "chinnadi") == 0) {
            sprintf(icg[ic_idx++], "LT R%d R%d R%d\n", registerIndex++ , firstreg, secondreg);
        }
        else if (strcmp((yyvsp[(3) - (5)].nd_obj).name, "peddadi") == 0) {
            sprintf(icg[ic_idx++], "GT R%d R%d R%d\n", registerIndex++ , firstreg, secondreg);
        }
        else if (strcmp((yyvsp[(3) - (5)].nd_obj).name, "chinnadiLedaSamanam") == 0) {
            sprintf(icg[ic_idx++], "LTE R%d R%d R%d\n", registerIndex++ , firstreg, secondreg);
        }
        else if (strcmp((yyvsp[(3) - (5)].nd_obj).name, "peddadiLedaSamanam") == 0) {
            sprintf(icg[ic_idx++], "GTE R%d R%d R%d\n", registerIndex++ , firstreg, secondreg);
        }
        else if (strcmp((yyvsp[(3) - (5)].nd_obj).name, "samanam") == 0) {
            sprintf(icg[ic_idx++], "EQ R%d R%d R%d\n", registerIndex++ , firstreg, secondreg);
        }
        else{
            sprintf(icg[ic_idx++], "R%d = R%d %s R%d\n", secondreg , firstreg, (yyvsp[(3) - (5)].nd_obj).name, secondreg);
            registerIndex++;   // is this needed?
        }
         
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 817 "t2parser.y"
    {firstreg = registerIndex-1;;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 817 "t2parser.y"
    {secondreg = registerIndex-1;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 817 "t2parser.y"
    { 
        printf("Parser found exp-logicalOp-exp\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (5)].nd_obj).nd;
        children[1] = (yyvsp[(3) - (5)].nd_obj).nd; 
        children[2] = (yyvsp[(4) - (5)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "condition");
        sprintf(icg[ic_idx++], "R%d = R%d %s R%d\n", secondreg , firstreg, (yyvsp[(3) - (5)].nd_obj).name, secondreg);
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 829 "t2parser.y"
    {
        sprintf(icg[ic_idx++], "if NOT (R%d) GOTO L%d\n",registerIndex-1,labelsused);isleader[insNumOfLabel[labelsused]]=1;isleader[ic_idx]=1; label[stackpointer++]=labelsused++;;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 830 "t2parser.y"
    {sprintf(icg[ic_idx++], "JUMP L%d\n",label[stackpointer-1]);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 830 "t2parser.y"
    { 
        printf("Parser found if(cond){bunch}\n");
        int num_children = 7;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (9)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (9)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (9)].nd_obj).nd; 
        children[3] = (yyvsp[(5) - (9)].nd_obj).nd;
        children[4] = (yyvsp[(6) - (9)].nd_obj).nd;
        children[5] = (yyvsp[(7) - (9)].nd_obj).nd;
        children[6] = (yyvsp[(9) - (9)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "if(cond){bunch}");
        insNumOfLabel[label[stackpointer-1]]=ic_idx; 
        sprintf(icg[ic_idx++], "LABEL L%d:\n", label[--stackpointer]);
        laddercounts[laddercountstackpointer++]=1;

    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 849 "t2parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "empty"); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 850 "t2parser.y"
    { 
        printf("Parser found eol elif_repeat\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "EOL-elifrepeat");
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 859 "t2parser.y"
    {sprintf(icg[ic_idx++], "if NOT (R%d) GOTO L%d\n",registerIndex-1,labelsused);isleader[insNumOfLabel[labelsused]]=1;isleader[ic_idx]=1;label[stackpointer++]=labelsused++;;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 861 "t2parser.y"
    {sprintf(icg[ic_idx++], "JUMP L%d\n",label[stackpointer-1]);;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 862 "t2parser.y"
    {insNumOfLabel[label[stackpointer-1]]=ic_idx;  sprintf(icg[ic_idx++], "LABEL L%d:\n", label[--stackpointer]);;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 862 "t2parser.y"
    { 
        printf("Parser found elif(cond){bunch}\n");
        int num_children = 9;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (12)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (12)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (12)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (12)].nd_obj).nd;
        children[4] = (yyvsp[(6) - (12)].nd_obj).nd;
        children[5] = (yyvsp[(7) - (12)].nd_obj).nd;
        children[6] = (yyvsp[(8) - (12)].nd_obj).nd;
        children[7] = (yyvsp[(10) - (12)].nd_obj).nd;
        children[8] = (yyvsp[(12) - (12)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "elif(cond){bunch}");
        laddercounts[laddercountstackpointer-1]++;
       
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 881 "t2parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "empty"); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 882 "t2parser.y"
    { 
        printf("Parser found EOL-else\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "EOL-else");
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 890 "t2parser.y"
    { 
        printf("Parser found else{bunch}\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "else{bunch}");
    ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 903 "t2parser.y"
    {
             lastjumps[lastjumpstackpointer++] = label[stackpointer-1];

        ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 907 "t2parser.y"
    { 
        printf("Parser found ifElseLadder\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd;
        children[2] = (yyvsp[(4) - (4)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "ifElseLadder");
        // lastjumpstackpointer--;  // forgetting the current ifelseLadder's lastjump and counts
        // laddercountstackpointer--;
    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 919 "t2parser.y"
    {
             lastjumps[lastjumpstackpointer++] = label[stackpointer-1];
            // int index = ic_idx - 1;
            // int count = laddercounts[laddercountstackpointer-1]; // Number of iterations

            // for (int i = index; i >= 0 && count > 0; i--) {
            //     if (strncmp(icg[i], "JUMP ", 5) == 0) { // Check if the prefix matches "JUMP "
            //         char jump_str[20]; // Assuming the number won't exceed 20 digits
            //         sprintf(jump_str, "%d", lastjumps[lastjumpstackpointer-1]); // Convert number to string
            //         snprintf(icg[i], 20, "JUMPx L%s\n", jump_str); // Set icg[i] to "JUMP" followed by the number
            //         count--;
            //     }
            // }

        ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 934 "t2parser.y"
    {    // without the else statement
        printf("Parser found ifElseLadder\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "ifElseLadder");
    ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 944 "t2parser.y"
    { looplabel[looplabelstackpointer++] = labelsused; insNumOfLabel[labelsused]=ic_idx;  sprintf(icg[ic_idx++], "LABEL L%d:\n", labelsused++);
        gotolabel[gotolabelstackpointer++]=labelsused;  sprintf(icg[ic_idx++], "if NOT (R%d) GOTO L%d\n",registerIndex-1,labelsused++);isleader[insNumOfLabel[labelsused-1]]=1;isleader[ic_idx]=1;
    ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 946 "t2parser.y"
    { sprintf(icg[ic_idx++], "JUMPtoLOOP L%d\n",looplabel[--looplabelstackpointer]);
    ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 947 "t2parser.y"
    {insNumOfLabel[gotolabel[gotolabelstackpointer-1]]=ic_idx;  sprintf(icg[ic_idx++], "LABEL L%d:\n", gotolabel[--gotolabelstackpointer]);;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 947 "t2parser.y"
    { 
        printf("Parser found while(cond){bunch}\n");
        int num_children = 7;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (10)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (10)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (10)].nd_obj).nd; 
        children[3] = (yyvsp[(5) - (10)].nd_obj).nd;
        children[4] = (yyvsp[(6) - (10)].nd_obj).nd;
        children[5] = (yyvsp[(7) - (10)].nd_obj).nd;
        children[6] = (yyvsp[(9) - (10)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "while(cond){bunch}");
    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 962 "t2parser.y"
    {rangestart = ic_idx;;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 962 "t2parser.y"
    {
        //add('V');   // this is taking ';' as a variable
        printf("Parser found datatypeId=exp\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (5)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (5)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (5)].nd_obj).nd; 
        children[3] = (yyvsp[(5) - (5)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "datatypeId=exp");
        if(strcmp(exp_type,(yyvsp[(1) - (5)].nd_obj).name)!=0 && strcmp(exp_type, " ")!=0){
            sprintf("$1name=%s and exp_type=%s\n", (yyvsp[(1) - (5)].nd_obj).name,exp_type);
            sprintf(errors[sem_errors], "Line %d: Data type casting not allowed in declaration\n", countn);
            sem_errors++;
        }
        rangeend = ic_idx;
        printf("QQQQQQQQQQQQQQQQQQQQQ rangestart=%d rangeend=%d\n",rangestart,rangeend);
        int idIndexinSymbolTable = findIdentifierIndex((yyvsp[(2) - (5)].nd_obj).name);
        symbol_table[idIndexinSymbolTable].range[symbol_table[idIndexinSymbolTable].range_count][0] = rangestart;
        symbol_table[idIndexinSymbolTable].range[symbol_table[idIndexinSymbolTable].range_count++][1] = rangeend;  //stack counter is increased
        if(performedConstantFolding) registerIndex++;
            sprintf(icg[ic_idx++], "MOVe %s , R%d\n", (yyvsp[(2) - (5)].nd_obj).name, registerIndex-1);
        performedConstantFolding=0;
    ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 986 "t2parser.y"
    {
        
        printf("Parser found datatype Id\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "datatypeId");

        //// not needed here
        // rangestart = ic_idx;
        // rangeend = ic_idx;
        // int idIndexinSymbolTable = findIdentifierIndex($2.name);
        // symbol_table[idIndexinSymbolTable].range[symbol_table[idIndexinSymbolTable].range_count][0] = rangestart;
        // symbol_table[idIndexinSymbolTable].range[symbol_table[idIndexinSymbolTable].range_count++][1] = rangeend;  //stack counter is increased
    ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1002 "t2parser.y"
    {
        
        printf("Parser found datatype Id\n");
        int num_children = 5;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (5)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (5)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (5)].nd_obj).nd;
        children[3] = (yyvsp[(4) - (5)].nd_obj).nd;
        children[4] = (yyvsp[(5) - (5)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "datatype Id[exp]");
    ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1017 "t2parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "empty"); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1018 "t2parser.y"
    { 
        printf("Parser found paramRepDatatypeIdComma\n");
        curr_num_params++;
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "paramRepDatatypeIdComma");
    ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1031 "t2parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "empty"); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1032 "t2parser.y"
    {scope++;;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1032 "t2parser.y"
    {scope--;;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1032 "t2parser.y"
    { 
        printf("Parser found parameters_line\n");
        curr_num_params++;
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(2) - (5)].nd_obj).nd;
        children[1] = (yyvsp[(3) - (5)].nd_obj).nd;
        children[2] = (yyvsp[(4) - (5)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "paramLine");
    ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1044 "t2parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "empty"); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1045 "t2parser.y"
    { 
        curr_num_args++;
        printf("Parser found lastparam\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (1)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "paramEnd");
        sprintf(icg[ic_idx++], "PARAM %s\n", (yyvsp[(1) - (1)].nd_obj).name);
    ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1054 "t2parser.y"
    { 
        curr_num_args++;
        printf("Parser found lastparam\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (1)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "paramEnd");
        sprintf(icg[ic_idx++], "PARAM %s\n", (yyvsp[(1) - (1)].nd_obj).name);
    ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1063 "t2parser.y"
    { 
        curr_num_args++;
        printf("Parser found lastparam\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (1)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "paramEnd");
        sprintf(icg[ic_idx++], "PARAM R%d\n", registers[regstackpointer-1]+1);
    ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1072 "t2parser.y"
    { 
        curr_num_args++;
        printf("Parser found id-comma-prep\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "paramRep");
        sprintf(icg[ic_idx++], "PARAM %s\n", (yyvsp[(1) - (3)].nd_obj).name);
    ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1085 "t2parser.y"
    {
        printf("Parser found idLine\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (1)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "idline");
    ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1094 "t2parser.y"
    { strcpy(exp_type," "); ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1094 "t2parser.y"
    {rangestart = ic_idx;;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1094 "t2parser.y"
    { 
        printf("Parser found equation\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (5)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (5)].nd_obj).nd;
        children[2] = (yyvsp[(5) - (5)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "id=exp");
        //check if identifier type and exp_type mismatch -> if yes then typecast is happening
        printf("type of identifier: %s XXXXXXXXXXXXXXXXX exp_type=%s\n\n", get_type((yyvsp[(1) - (5)].nd_obj).name),exp_type);
        if(strcmp(get_datatype((yyvsp[(1) - (5)].nd_obj).name) , exp_type) && strcmp(exp_type, " ")){
            sprintf(errors[sem_errors], "Line %d: Data type casting not allowed in equation\n", countn);
            sem_errors++;
        }
        // a = exp   ---> t1=exp, a=t1
        rangeend = ic_idx;
        printf("ZZZZZZZZZZ      rangestart=%d rangeend=%d\n",rangestart,rangeend);
        int idIndexinSymbolTable = findIdentifierIndex((yyvsp[(1) - (5)].nd_obj).name);
        symbol_table[idIndexinSymbolTable].range[symbol_table[idIndexinSymbolTable].range_count][0] = rangestart;
        symbol_table[idIndexinSymbolTable].range[symbol_table[idIndexinSymbolTable].range_count++][1] = rangeend;  //stack counter is increased

        sprintf(icg[ic_idx++], "%s = R%d\n", (yyvsp[(1) - (5)].nd_obj).name, registerIndex-1);
    ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1117 "t2parser.y"
    {thirdreg = registerIndex-1;;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1117 "t2parser.y"
    { 
        printf("Parser found id[exp]=exp\n");
        int num_children = 6;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (7)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (7)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (7)].nd_obj).nd; 
        children[3] = (yyvsp[(5) - (7)].nd_obj).nd;
        children[4] = (yyvsp[(6) - (7)].nd_obj).nd;
        children[5] = (yyvsp[(7) - (7)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "id[exp]=exp");
        sprintf(icg[ic_idx++], "MOV %s+R%d , R%d\n", (yyvsp[(1) - (7)].nd_obj).name,thirdreg ,registerIndex-1);
    ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1132 "t2parser.y"
    { 
        printf("Parser found funContentEOL\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "funContentEOL");
    ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1140 "t2parser.y"
    { 
        printf("Parser found EOL-funContent\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "EOL-funContent");
    ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1148 "t2parser.y"
    { 
        printf("Parser found bunch_function_content_bunch\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "bunch-content-bunch");
    ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1157 "t2parser.y"
    { 
        printf("Parser found bunch_function_content_bunch\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (1)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "bunch-content-bunch");
    ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1164 "t2parser.y"
    { 
        printf("Parser found bunchReturnFinish\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd;
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "bunchReturnFinish");
    ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1174 "t2parser.y"
    { 
        printf("Parser found bunchReturnExpFinish\n");
        int num_children = 5;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (5)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (5)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (5)].nd_obj).nd;
        children[3] = (yyvsp[(4) - (5)].nd_obj).nd;
        children[4] = (yyvsp[(5) - (5)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "bunchReturnExpFinish");
    ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1185 "t2parser.y"
    { 
        printf("Parser found bunchReturnExpFinish\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd;
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "bunchFunCallFinish");
    ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1198 "t2parser.y"
    { 
        printf("Parser found print_contentEOL\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "print_content-EOL");
    ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1206 "t2parser.y"
    {    // take care of infinite loop
        printf("Parser found EOL-print_content\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "EOL-printContent");
    ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1214 "t2parser.y"
    { 
        printf("Parser found print_content-String\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "printContent-String");
    ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1222 "t2parser.y"
    { 
        printf("Parser found print_content-exp\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "printContent-exp");
    ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1230 "t2parser.y"
    { 
        printf("Parser found print_content-comma-String\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "print_content-comma-String");
    ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1239 "t2parser.y"
    { 
        printf("Parser found print_content-comma-exp\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "print_content-comma-exp");
    ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1250 "t2parser.y"
    { 
        printf("Parser found printStatement\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd;
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "printStatement");
    ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1262 "t2parser.y"
    {oldscope=scope;scope=0;;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1262 "t2parser.y"
    {add('F');scope=oldscope;;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1262 "t2parser.y"
    { 
        printf("Parser found equation\n");
        int num_children = 8;  // Number of childrenfunction_call
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (10)].nd_obj).nd;
        children[1] = (yyvsp[(3) - (10)].nd_obj).nd;
        children[2] = (yyvsp[(5) - (10)].nd_obj).nd; 
        children[3] = (yyvsp[(6) - (10)].nd_obj).nd;
        children[4] = (yyvsp[(7) - (10)].nd_obj).nd;
        children[5] = (yyvsp[(8) - (10)].nd_obj).nd;
        children[6] = (yyvsp[(9) - (10)].nd_obj).nd;
        children[7] = (yyvsp[(10) - (10)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "func-id-(param){content}");
        symbol_table[count-curr_num_params-3].num_params= curr_num_params;
        if(symbol_table[count-curr_num_params-3].num_params>=0){
            printf("XXXX changed num_params of %s to %d\n",symbol_table[count-curr_num_params-3].id_name,symbol_table[count-curr_num_params-3].num_params);
            curr_num_params=0;
        }
    ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1283 "t2parser.y"
    { check_declaration((yyvsp[(1) - (1)].nd_obj).name); ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1283 "t2parser.y"
    { 
        printf("Parser found id(idLine)Finish\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (5)].nd_obj).nd;
        children[1] = (yyvsp[(3) - (5)].nd_obj).nd;
        children[2] = (yyvsp[(4) - (5)].nd_obj).nd; 
        children[3] = (yyvsp[(5) - (5)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "id(idLine)Finish");

        for(int i=0;i<count;i++){
            if(strcmp(symbol_table[i].id_name,(yyvsp[(1) - (5)].nd_obj).name)==0){  // found the corresponding function
            if(symbol_table[i].num_params==-1){
                printf("ERROR:  %s is not a function\n",(yyvsp[(1) - (5)].nd_obj).name);
                sprintf(errors[sem_errors], "Line %d:  %s is not a function\n", countn+1,(yyvsp[(1) - (5)].nd_obj).name);
                sem_errors++;
                break;
            }
                // if(symbol_table[i].num_params!=curr_num_args){
                //     printf("ERROR: Number of parameters do not match\n");
                //     sprintf(errors[sem_errors], "Line %d: need %d arguments but found %d args\n", countn+1,symbol_table[i].num_params,curr_num_args);
                //     sem_errors++;
                //     break;
                // }
            }
        }

        curr_num_args=0;
        sprintf(icg[ic_idx++], "CALL %s\n", (yyvsp[(1) - (5)].nd_obj).name);
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 3712 "t2parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1313 "t2parser.y"


int main(){
    for(int i=0;i<10000;i++){
        laddercounts[i]=0;
        isleader[i]=0;
        insNumOfLabel[i]=-1;
    }
    isleader[0]=1;
    strcpy(exp_type," ");
    printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
    for(int i=0;i<10000;i++){
        symbol_table[i].used = 0;
        symbol_table[i].range_count = 0;   
        // for(int j=0;j<10000;j++){
        //     symbol_table[i].range[j][0]=-1;
        //     symbol_table[i].range[j][1]=-1;   // dummy values
        // }
    }
    yyparse();
	printf("\nSYMBOL   DATATYPE   TYPE   LineNUMBER  SCOPE  numParams\n");
	printf("_______________________________________\n\n");
	int i=0;
	// for(i=0; i<count; i++) {

	// 	printf("%s\t%s\t%s\t%d\t%d\t%d\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no,symbol_table[i].thisscope,symbol_table[i].num_params);
	// }
    for (i = 0; i < count; i++) {
        printf("%s\t%s\t%s\t%d\t%d\t%d\t%s\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no, symbol_table[i].thisscope, symbol_table[i].num_params, symbol_table[i].used ? "Used" : "unUsed");
    }

	
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
	printtree(head); 
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 3: SEMANTIC ANALYSIS \n\n");
	if(sem_errors>0) {
		printf("Semantic analysis completed with %d errors\n", sem_errors);
		for(int i=0; i<sem_errors; i++){
			printf("\t - %s", errors[i]);
		}
	} else {
		printf("Semantic analysis completed with no errors");
	}
	printf("\n\n");
    printf("\t\t\t\t\t\t\t   PHASE 4: INTERMEDIATE CODE GENERATION \n\n");
	for(int i=0; i<ic_idx; i++){
        if(icg[i][0]=='L' && icg[i][0]=='A'){
            printf("\n");
        }
		printf("%d  %s", i,icg[i]);
	}
	printf("\n\n");

    // Assuming icg[] contains the strings "LABEL L15", "LABEL L20", etc.
    for (int i = 0; i < ic_idx; i++) {
        // Check if the string starts with "LABEL L"
        if (strncmp(icg[i], "LABEL L", 7) == 0) {
            // Extract the label number from the string
            int labelNumber = atoi(icg[i] + 7); // Skip "LABEL L" and convert the rest to integer
            
            // Use the label number to index into insNumOfLabel array
            insNumOfLabel[labelNumber] = i;
        }
    }

    for(int i=0;i<ic_idx;i++){
        if (strncmp(icg[i], "if NOT (", 8) == 0) {
            char *ptr = strstr(icg[i], "L"); // Find the first occurrence of "L" in the string
            int labelNumber = atoi(ptr + 1); // Convert the substring after "L" to integer
            //printf("Extracted label number: %d\n", labelNumber);
            isleader[insNumOfLabel[labelNumber]] = 1;
            if(i+1<10000)
                isleader[i+1]=1;
        }
    }

    printf("\t\t\tBLOCKS:\n\n");
    int prev=-1,blockcount=0;
    for(int i=0;i<10000;i++){
        // if(insNumOfLabel[i]!=-1){
        //     printf("Label %d is at %d\n",i,insNumOfLabel[i]);
        // }
        if(isleader[i]){
            if(prev!=-1)
            printf("block %d: %d to %d\n",blockcount++,prev,i-1);
            //printf("Leader %d\n",i);
            prev=i;
        }
    }
    
    printf("\n\n");

    // Iterate over the symbol table to print ranges for unused variables
    for (int i = 0; i < count; i++) {
        if (symbol_table[i].used <= 0 && strcmp(symbol_table[i].type, "Variable") == 0) {
             printf("Variable %s declared but not used\n", symbol_table[i].id_name);
             printf("Ranges for %s:\n", symbol_table[i].id_name);
            for (int j = 0; j < symbol_table[i].range_count; j++) {
                printf("[%d, %d]\n", symbol_table[i].range[j][0], symbol_table[i].range[j][1]);
                uselessranges[uselessrangescount][0] = symbol_table[i].range[j][0];
                uselessranges[uselessrangescount++][1] = symbol_table[i].range[j][1];
            }
            printf("\n");
        }
    }
    for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);   // symbol is needed, so dont free yet
		free(symbol_table[i].type);
	}
    //printf("done");

    // Sort uselessranges
    sortRanges(uselessranges, uselessrangescount);
    int uselessrangesidx = 0;
    printf(" uselessrangescount=%d\n", uselessrangescount);
    printf("\t\t\t\t\t\t\t   PHASE 5: OPTIMIZATION \n\n");
	for(int i=0; i<ic_idx; i++){
        if (uselessrangesidx < uselessrangescount && i == uselessranges[uselessrangesidx][0]) {
            uselessrangesidx++;
            i=uselessranges[uselessrangesidx-1][1];
            //printf("skipping from %d to %d\n", uselessranges[uselessrangesidx-1][0], uselessranges[uselessrangesidx-1][1]);
            continue;
        }
        if(icg[i][0]=='L' && icg[i][0]=='A'){
            printf("\n");
        }
		printf("%d %s",i, icg[i]);
	}
	printf("\n\n");

    

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

/////////////////////////////////////  SYMBOL TABLE & SEMANTIC ANALYSIS PART

int search(char *type) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, type)==0) {
			return symbol_table[i].thisscope;
			break;
		}
	}
	return 0;
}

void check_declaration(char *c) {
    q = search(c);
    // if(!q) {
    //     sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared before usage!\n", countn+1, c);
	// 	sem_errors++;
    // }
}

char *get_type(char *var){
	for(int i=0; i<count; i++) {
		// Handle case of use before declaration
		if(!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].type;
		}
	}
}
char *get_datatype(char *var){
	for(int i=0; i<count; i++) {
		// Handle case of use before declaration
		if(!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
}

void add(char c) {
	if(c == 'V'){ // variable
		for(int i=0; i<reserved_count; i++){
			if(!strcmp(reserved[i], strdup(yy_text))){
        		sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword!\n", countn+1, yy_text);
				sem_errors++;
				return;
			}
		}
	}
    q=search(yy_text);
	if(!q) {   // insert into symbol table only if not already present
		if(c == 'H') {  //header
			symbol_table[count].id_name=strdup(yy_text);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Header");
            symbol_table[count].thisscope=scope;
            symbol_table[count].num_params=-1; 
			count++;
		}
		else if(c == 'K') { //keyword
			symbol_table[count].id_name=strdup(yy_text);
			symbol_table[count].data_type=strdup("N/A");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Keyword\t");
            symbol_table[count].thisscope=scope;
            symbol_table[count].num_params=-1;
			count++;
		}
		else if(c == 'V') { //variable
            printf("yytext: %s\n", yy_text);
			symbol_table[count].id_name=strdup(yy_text);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Variable");
            symbol_table[count].thisscope=scope;
            symbol_table[count].num_params=-1;
			count++;
		}
        else if(c == 'C') {  //constant sankhya
			symbol_table[count].id_name=strdup(yy_text);
			symbol_table[count].data_type=strdup("CONST");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("constantx");
            symbol_table[count].thisscope=scope;
            symbol_table[count].num_params=-1;
			count++;
		}
		else if(c == 'i') {  //constant sankhya
			symbol_table[count].id_name=strdup(yy_text);
			symbol_table[count].data_type=strdup("CONST");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("sankhya");
            symbol_table[count].thisscope=scope;
            symbol_table[count].num_params=-1;
			count++;
		}
        else if(c == 'f') {  //constant float thelu
			symbol_table[count].id_name=strdup(yy_text);
			symbol_table[count].data_type=strdup("CONST");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("thelu");
            symbol_table[count].thisscope=scope;
            symbol_table[count].num_params=-1;
			count++;
		}
        else if(c == 'c') {  //constant character aksharam
			symbol_table[count].id_name=strdup(yy_text);
			symbol_table[count].data_type=strdup("CONST");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("aksharam");
            symbol_table[count].thisscope=scope;
            symbol_table[count].num_params=-1;
			count++;
		}
        else if(c == 's') {  //constant string theega
			symbol_table[count].id_name=strdup(yy_text);
			symbol_table[count].data_type=strdup("CONST");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("theega");
            symbol_table[count].thisscope=scope;
            symbol_table[count].num_params=-1;
			count++;
		}
		else if(c == 'F') {
			symbol_table[count].id_name=strdup(yy_text);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Function");
            symbol_table[count].thisscope=scope;
            printf("\nSETTING %s's params to %d\n", symbol_table[count-curr_num_params].id_name, curr_num_params);
            symbol_table[count-curr_num_params].num_params=curr_num_params;
            curr_num_params=0;
			count++;
		}
        else if(c == 'L') {
            symbol_table[count].id_name=strdup(yy_text);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("Library");
            symbol_table[count].thisscope=scope;
            symbol_table[count].num_params=0;
            count++;
        }
               
    }
    else if(c == 'V' && q) {
        if(q != INT_MAX){

            sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed!\n", countn+1, yy_text);
            sem_errors++;
        }
        else{ // its scope is already destroyed, now it can be redeclared again into the symbol table with current scope
            // search again for that symbol table value
            int i;
            for(i=count-1; i>=0; i--) {
                if(strcmp(symbol_table[i].id_name, type)==0) {
                    symbol_table[i].thisscope = scope;
                    symbol_table[count].line_no=countn;
                    symbol_table[count].num_params=0;
                    printf("\nReinserted %s because its previous scope is finished\n", type);
                    break;
                }
            }
        }
    }
}

void insert_type() {
	strcpy(type, yy_text);
}




