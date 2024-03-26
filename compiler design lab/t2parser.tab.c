
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
    void insert_type();



/* Line 189 of yacc.c  */
#line 95 "t2parser.tab.c"

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
#line 24 "t2parser.y"
 
	struct var_name { 
		char name[100]; 
		struct node* nd;
	} nd_obj; 



/* Line 214 of yacc.c  */
#line 171 "t2parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 183 "t2parser.tab.c"

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
#define YYLAST   581

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNRULES -- Number of states.  */
#define YYNSTATES  193

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
      59,    61,    63,    65,    67,    69,    70,    73,    76,    81,
      86,    90,    94,    96,    98,   100,   102,   104,   106,   111,
     115,   119,   123,   128,   129,   132,   135,   139,   147,   151,
     156,   161,   166,   172,   177,   180,   182,   186,   190,   198,
     199,   202,   212,   213,   216,   221,   225,   228,   236,   241,
     244,   250,   251,   256,   257,   261,   262,   264,   266,   270,
     274,   276,   280,   287,   290,   292,   297,   303,   304,   307,
     310,   313,   316,   320,   324,   329,   338
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      33,     0,    -1,    63,    -1,     3,    -1,    17,    -1,    29,
      -1,     4,    -1,    31,    -1,     5,    -1,    30,    -1,     4,
      -1,     5,    -1,    18,    -1,    28,    -1,     6,    -1,     7,
      -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,    14,    -1,    18,    -1,    19,    -1,    20,
      -1,    21,    -1,    22,    -1,    15,    -1,    16,    -1,    23,
      -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,    -1,
      63,    34,    -1,    34,    63,    -1,    63,    40,    35,    59,
      -1,    40,    35,    59,    63,    -1,    63,    65,    63,    -1,
      63,    81,    63,    -1,    37,    -1,    39,    -1,    62,    -1,
      51,    -1,    35,    -1,    82,    -1,    35,    54,    64,    55,
      -1,    52,    64,    53,    -1,    64,    42,    64,    -1,    64,
      45,    64,    -1,    35,    54,    64,    55,    -1,    -1,    34,
      65,    -1,    65,    34,    -1,    65,    70,    65,    -1,    65,
      38,    52,    35,    53,    59,    65,    -1,    65,    71,    65,
      -1,    65,    77,    59,    65,    -1,    65,    80,    59,    65,
      -1,    65,    72,    59,    65,    -1,    65,    56,    65,    57,
      65,    -1,    65,    82,    59,    65,    -1,     1,    59,    -1,
      64,    -1,    64,    43,    64,    -1,    64,    45,    64,    -1,
      47,    52,    66,    53,    56,    65,    57,    -1,    -1,    34,
      68,    -1,    68,    48,    52,    66,    53,    56,    65,    57,
      68,    -1,    -1,    34,    69,    -1,    49,    56,    65,    57,
      -1,    67,    68,    69,    -1,    67,    68,    -1,    50,    52,
      66,    53,    56,    65,    57,    -1,    46,    35,    44,    64,
      -1,    46,    35,    -1,    46,    35,    54,    64,    55,    -1,
      -1,    73,    46,    35,    58,    -1,    -1,    73,    46,    35,
      -1,    -1,    35,    -1,    41,    -1,    35,    58,    75,    -1,
      41,    58,    75,    -1,    75,    -1,    35,    44,    64,    -1,
      35,    54,    64,    55,    44,    64,    -1,    78,    34,    -1,
      65,    -1,    65,    61,    59,    65,    -1,    65,    61,    64,
      59,    65,    -1,    -1,    79,    34,    -1,    34,    79,    -1,
      79,    51,    -1,    79,    64,    -1,    79,    58,    51,    -1,
      79,    58,    64,    -1,    36,    52,    79,    53,    -1,    60,
      35,    52,    74,    53,    56,    78,    57,    -1,    35,    52,
      76,    53,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    46,    46,    59,    61,    63,    66,    68,    70,    73,
      75,    76,    77,    78,    82,    85,    88,    91,    94,    97,
     100,   103,   106,   109,   112,   115,   118,   121,   124,   127,
     130,   136,   139,   142,   145,   151,   152,   160,   168,   178,
     188,   197,   215,   222,   229,   236,   243,   250,   257,   267,
     281,   298,   307,   321,   322,   330,   338,   347,   360,   369,
     379,   389,   399,   410,   420,   428,   435,   444,   455,   470,
     471,   479,   496,   497,   505,   517,   526,   536,   551,   561,
     569,   583,   584,   596,   597,   608,   609,   616,   623,   632,
     643,   652,   661,   675,   683,   690,   700,   713,   714,   722,
     730,   738,   746,   755,   766,   778,   794
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
  "telugu_identifier", "telugu_print", "telugu_int", "telugu_input",
  "telugu_float", "telugu_import", "telugu_constant",
  "telugu_arithmetic_operator", "telugu_comparison_operator",
  "telugu_assignment_operator", "telugu_logical_operator",
  "telugu_datatype", "telugu_if", "telugu_elif", "telugu_else",
  "telugu_while", "telugu_string", "telugu_open_curly_bracket",
  "telugu_closed_curly_bracket", "telugu_open_square_bracket",
  "telugu_closed_square_bracket", "telugu_open_floor_bracket",
  "telugu_closed_floor_bracket", "telugu_punctuation_comma",
  "telugu_finish", "telugu_function", "telugu_return", "telugu_character",
  "input", "exp", "bunch_of_statements", "condition", "if_statement",
  "elif_repeat", "else_statement", "if_else_ladder", "while_loop",
  "variable_declaration", "parameters_repeat", "parameters_line",
  "identifiers_repeat", "identifiers_line", "equation", "function_content",
  "print_content", "print_statement", "function_declaration",
  "function_call", 0
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
      41,    41,    41,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    66,    66,    67,    68,
      68,    68,    69,    69,    69,    70,    70,    71,    72,    72,
      72,    73,    73,    74,    74,    75,    75,    75,    75,    75,
      76,    77,    77,    78,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    80,    81,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     2,     4,     4,
       3,     3,     1,     1,     1,     1,     1,     1,     4,     3,
       3,     3,     4,     0,     2,     2,     3,     7,     3,     4,
       4,     4,     5,     4,     2,     1,     3,     3,     7,     0,
       2,     9,     0,     2,     4,     3,     2,     7,     4,     2,
       5,     0,     4,     0,     3,     0,     1,     1,     3,     3,
       1,     3,     6,     2,     1,     4,     5,     0,     2,     2,
       2,     2,     3,     3,     4,     8,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      35,     3,     9,     0,    35,     0,     0,     1,     0,     4,
       0,     0,    32,     0,     0,     0,    35,    35,    31,    35,
      64,     0,    54,     0,     0,    18,    19,    22,    28,     5,
       7,    35,     0,     0,     0,     0,     0,     0,     0,     0,
      69,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      38,    24,    81,    16,    26,     0,    85,     0,    97,     0,
      79,     0,     0,     0,    69,    72,    56,    58,     0,     0,
       0,     0,     0,     0,     6,     8,    23,    34,    46,    42,
      43,    45,     0,    44,    91,    47,    10,    11,    12,    13,
      86,    87,    90,     0,     0,    97,     0,     0,     0,     0,
      65,     0,     0,    29,     0,    70,    20,    21,    72,     0,
       0,    75,    61,    59,    60,    63,     0,    25,     0,     0,
       0,    14,    17,     0,     0,    30,    85,    85,   106,    27,
       0,    99,    98,    45,   104,     0,   101,     0,    78,     0,
      15,     0,     0,     0,     0,    62,    73,     0,     0,    84,
       0,     0,    49,    50,    51,    88,    89,     0,    45,   103,
       0,    80,    66,    51,     0,     0,     0,     0,    82,    94,
       0,    48,    92,    57,     0,     0,     0,    74,    33,     0,
      93,   105,    68,    77,     0,     0,     0,     0,    95,     0,
      69,    96,    71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    21,    32,    33,    79,    34,    80,     5,    91,
     123,   141,    55,   124,    35,    36,   109,   110,    37,    81,
      82,   118,    57,   130,    38,   104,   135,    19,    15,   179,
      83,     8,   100,    16,   101,    40,    65,   111,    41,    42,
      43,    72,    73,    92,    93,    44,   170,    96,    45,    17,
      46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -131
static const yytype_int16 yypact[] =
{
      11,  -131,  -131,    23,    11,    34,   331,  -131,   353,  -131,
       3,     3,  -131,   375,    34,    34,   222,    11,  -131,    11,
    -131,   309,   525,     3,    42,  -131,  -131,  -131,  -131,  -131,
    -131,    11,     5,    42,    42,    34,    42,    42,   485,   397,
      69,   309,   309,     3,     3,     3,     3,   419,   441,  -131,
    -131,  -131,    57,  -131,  -131,   181,   106,   181,    69,    34,
      24,   181,   181,   494,    69,   127,   525,   525,   309,   309,
     309,   309,    76,    77,  -131,  -131,  -131,  -131,   131,  -131,
    -131,  -131,   181,  -131,   132,  -131,  -131,  -131,  -131,  -131,
      82,    82,  -131,    77,   113,    69,   545,    77,   181,   181,
     140,    77,    77,  -131,   309,    81,  -131,  -131,    17,    42,
      94,  -131,   525,   525,   525,   525,    34,  -131,    94,   181,
      79,  -131,  -131,   181,   181,  -131,   106,   106,  -131,  -131,
     110,   299,  -131,  -131,  -131,   181,   132,     3,   132,   113,
    -131,   181,   181,    94,    94,   525,  -131,   181,   485,    82,
     463,   113,  -131,   132,   132,  -131,  -131,   181,  -131,   132,
     309,  -131,   132,   132,   485,   485,    77,   494,  -131,   516,
      46,  -131,   132,   525,   494,   494,    94,  -131,  -131,   553,
    -131,  -131,  -131,  -131,   485,   485,   111,   494,   525,   485,
      69,   525,    81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,     0,   149,  -131,  -131,  -131,  -131,    21,  -131,
    -131,  -131,   -55,    28,    60,  -131,  -131,  -131,  -131,   -89,
      70,   121,   -26,  -130,  -100,   -96,   -79,    -8,  -131,  -131,
    -131,    73,     2,    12,   -60,  -131,   -63,    43,  -131,  -131,
    -131,  -131,  -131,   -71,  -131,  -131,  -131,    47,  -131,  -131,
     158
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -84
static const yytype_int16 yytable[] =
{
       4,   105,   102,    20,     4,    98,    13,   133,    13,   161,
     148,   126,   127,    53,     1,    50,    31,     4,   150,     4,
       1,   171,    49,     7,    51,    22,    54,    14,    18,    14,
     107,     4,    53,    22,    99,    68,    69,    70,    71,    13,
      64,     2,   133,   164,   165,    54,   158,    13,    13,     1,
      63,     9,   119,    66,    67,   155,   156,    84,    95,    94,
      14,    51,   103,    49,    64,   108,    49,    49,    14,    14,
     168,   177,     1,     6,   181,   157,   184,   -83,   182,   183,
     112,   113,   114,   115,   120,   121,    25,   166,   122,    39,
      47,   190,    48,   106,    52,    95,   132,   117,   136,   117,
     138,   139,    56,    58,    59,   125,    61,    62,   108,    28,
      86,    87,    49,    49,    49,    49,   145,   121,    53,   121,
     122,   151,   122,     9,    88,   153,   154,   192,   142,   160,
       1,   132,   116,   136,    89,   129,    18,   159,   121,   106,
     107,   122,   131,   162,   163,    49,   121,   140,    56,   122,
      51,   146,    54,     0,    10,     0,     0,     0,     0,   172,
     167,     0,   169,    23,    24,     0,     0,    49,     0,    49,
     180,   185,   173,    49,    49,    49,   174,   175,   189,   147,
       0,   186,     0,     0,    60,    74,    75,    49,    49,     0,
      64,    49,     0,     0,     0,     0,   187,   188,     9,    76,
      51,   191,     0,     0,    78,    90,    78,     0,    97,    77,
      78,    78,     0,    85,   128,    85,     0,   134,   137,    85,
      85,     0,   143,   144,     0,     1,     0,     0,     0,     0,
       0,    78,    25,    26,     0,     0,    27,    28,     0,     9,
      85,   152,     0,     0,     0,    78,     0,    78,    78,     0,
       0,    29,     2,    30,    85,     0,    85,    85,     0,     0,
       0,     0,     0,     0,     0,   149,     0,     0,    78,     0,
       0,     0,    78,    78,     0,    90,    90,    85,     0,     0,
      78,    85,    85,     0,    78,     0,     0,   176,     0,    85,
      78,    78,     0,    85,     0,     0,    78,     0,     0,    85,
      85,     0,     1,    74,    75,    85,    78,     0,     0,   -53,
      11,     0,     1,     0,     0,    85,     9,    76,    51,   -53,
     -53,     0,   125,   -53,   -53,   -53,   -53,    77,    78,     0,
       0,    -2,    11,     0,     1,   -53,   -53,    85,   -53,   -53,
     -53,   -53,   -53,     0,     0,   -53,   -53,     0,   -53,     0,
       0,     0,     0,   -37,    11,     0,     1,    12,     0,     0,
     -53,     2,   -53,   -37,   -37,     0,     0,   -37,   -37,     0,
     -37,     0,     0,     0,     0,   -36,    11,     0,     1,    12,
       0,     0,   -37,     2,   -37,   -36,   -36,     0,     0,   -36,
     -36,     0,   -36,     0,     0,     0,     0,   -40,    11,     0,
       1,   -36,     0,     0,   -36,   -36,   -36,   -40,   -40,     0,
       0,   -40,   -40,     0,   -40,     0,     0,     0,     0,   -41,
      11,     0,     1,    12,     0,     0,   -40,     2,   -40,   -41,
     -41,     0,     0,   -41,   -41,     0,   -41,     0,     0,     0,
       0,   -39,    11,     0,     1,    12,     0,     0,   -41,     2,
     -41,   -39,   -39,     0,     0,   -39,   -39,     0,   -39,     0,
       0,     0,     0,     0,    11,     0,     1,    12,     0,     0,
     -39,     2,   -39,   -53,   -53,     0,     0,   -53,   -53,   -53,
     -53,     0,     0,     0,     0,     0,    11,     0,     1,     0,
     -53,     0,   -53,     0,   -53,   -53,   -53,     1,     0,   -53,
     -53,   -53,   -53,     0,    25,    26,     0,     0,    27,    28,
     103,     9,     0,     0,   -53,     0,   -53,     0,     0,     1,
       0,     0,     0,    29,     0,    30,    25,    26,     1,     0,
      27,    28,     0,     9,     0,    25,    26,     0,     0,    27,
      28,     0,     9,   178,     0,    29,     0,    30,     1,    74,
      75,     0,     0,     0,    29,     0,    30,    74,    75,     0,
       0,     0,     9,    76,    51,   117,     0,     0,   125,     0,
       9,    76,    51,    77,     0,     0,     0,     0,    18,     0,
       0,    77
};

static const yytype_int16 yycheck[] =
{
       0,    64,    62,    11,     4,    60,     6,    96,     8,   139,
     110,    90,    91,     8,     3,    23,    16,    17,   118,    19,
       3,   151,    22,     0,    19,    13,    21,     6,    25,     8,
      13,    31,     8,    21,    60,    43,    44,    45,    46,    39,
      40,    30,   131,   143,   144,    21,   135,    47,    48,     3,
      38,    17,    78,    41,    42,   126,   127,    55,    58,    57,
      39,    19,    16,    63,    64,    65,    66,    67,    47,    48,
     149,   167,     3,     0,   170,   130,   176,    20,   174,   175,
      68,    69,    70,    71,    82,     6,    10,   147,     9,    16,
      17,   187,    19,    12,    24,    95,    96,    20,    96,    20,
      98,    99,    32,    33,    34,    23,    36,    37,   108,    15,
       4,     5,   112,   113,   114,   115,   104,     6,     8,     6,
       9,   119,     9,    17,    18,   123,   124,   190,   100,   137,
       3,   131,    72,   131,    28,    22,    25,   135,     6,    12,
      13,     9,    95,   141,   142,   145,     6,     7,    78,     9,
      19,   108,    21,    -1,     5,    -1,    -1,    -1,    -1,   157,
     148,    -1,   150,    14,    15,    -1,    -1,   167,    -1,   169,
     170,   179,   160,   173,   174,   175,   164,   165,   186,   109,
      -1,   179,    -1,    -1,    35,     4,     5,   187,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,   184,   185,    17,    18,
      19,   189,    -1,    -1,    55,    56,    57,    -1,    59,    28,
      61,    62,    -1,    55,    93,    57,    -1,    96,    97,    61,
      62,    -1,   101,   102,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    82,    10,    11,    -1,    -1,    14,    15,    -1,    17,
      82,   120,    -1,    -1,    -1,    96,    -1,    98,    99,    -1,
      -1,    29,    30,    31,    96,    -1,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,   119,    -1,
      -1,    -1,   123,   124,    -1,   126,   127,   119,    -1,    -1,
     131,   123,   124,    -1,   135,    -1,    -1,   166,    -1,   131,
     141,   142,    -1,   135,    -1,    -1,   147,    -1,    -1,   141,
     142,    -1,     3,     4,     5,   147,   157,    -1,    -1,     0,
       1,    -1,     3,    -1,    -1,   157,    17,    18,    19,    10,
      11,    -1,    23,    14,    15,    16,    17,    28,   179,    -1,
      -1,     0,     1,    -1,     3,    26,    27,   179,    29,    30,
      31,    10,    11,    -1,    -1,    14,    15,    -1,    17,    -1,
      -1,    -1,    -1,     0,     1,    -1,     3,    26,    -1,    -1,
      29,    30,    31,    10,    11,    -1,    -1,    14,    15,    -1,
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
      29,    30,    31,    10,    11,    -1,    -1,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,    -1,
      27,    -1,    29,    -1,    31,    10,    11,     3,    -1,    14,
      15,    16,    17,    -1,    10,    11,    -1,    -1,    14,    15,
      16,    17,    -1,    -1,    29,    -1,    31,    -1,    -1,     3,
      -1,    -1,    -1,    29,    -1,    31,    10,    11,     3,    -1,
      14,    15,    -1,    17,    -1,    10,    11,    -1,    -1,    14,
      15,    -1,    17,    27,    -1,    29,    -1,    31,     3,     4,
       5,    -1,    -1,    -1,    29,    -1,    31,     4,     5,    -1,
      -1,    -1,    17,    18,    19,    20,    -1,    -1,    23,    -1,
      17,    18,    19,    28,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    30,    33,    34,    40,    63,     0,    63,    17,
      35,     1,    26,    34,    40,    60,    65,    81,    25,    59,
      59,    34,    65,    35,    35,    10,    11,    14,    15,    29,
      31,    34,    35,    36,    38,    46,    47,    50,    56,    63,
      67,    70,    71,    72,    77,    80,    82,    63,    63,    34,
      59,    19,    52,     8,    21,    44,    52,    54,    52,    52,
      35,    52,    52,    65,    34,    68,    65,    65,    59,    59,
      59,    59,    73,    74,     4,     5,    18,    28,    35,    37,
      39,    51,    52,    62,    64,    82,     4,     5,    18,    28,
      35,    41,    75,    76,    64,    34,    79,    35,    44,    54,
      64,    66,    66,    16,    57,    68,    12,    13,    34,    48,
      49,    69,    65,    65,    65,    65,    46,    20,    53,    54,
      64,     6,     9,    42,    45,    23,    58,    58,    53,    22,
      55,    79,    34,    51,    53,    58,    64,    53,    64,    64,
       7,    43,    45,    53,    53,    65,    69,    52,    56,    35,
      56,    64,    53,    64,    64,    75,    75,    44,    51,    64,
      59,    55,    64,    64,    56,    56,    66,    65,    58,    65,
      78,    55,    64,    65,    65,    65,    53,    57,    27,    61,
      34,    57,    57,    57,    56,    59,    64,    65,    65,    59,
      57,    65,    68
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
#line 46 "t2parser.y"
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
#line 59 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, "newline");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 61 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 63 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 66 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 68 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 70 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 73 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 75 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 76 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 77 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 78 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 82 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 85 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 88 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 91 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 94 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 97 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, "if");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 100 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, "elif");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 103 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, "else");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 106 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL,"while");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 109 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 112 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 115 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 118 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 121 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 124 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 127 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 130 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 136 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 139 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 142 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 145 "t2parser.y"
    {(yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 151 "t2parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "empty"); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 152 "t2parser.y"
    { 
        printf("Parser found input-eol\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "input-eol");
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 160 "t2parser.y"
    { 
        printf("Parser found eol-input\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "eol-input");
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 168 "t2parser.y"
    { 
        printf("Parser found input-import-id-;\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "input-import-id-;");
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 178 "t2parser.y"
    { 
        printf("Parser found import-id-;-input\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "import-id-;-input");
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 188 "t2parser.y"
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

  case 41:

/* Line 1455 of yacc.c  */
#line 197 "t2parser.y"
    { 
        printf("Parser found input-functionDec-input\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd; 
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "input-funDec-input");
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 215 "t2parser.y"
    {
                    printf("Parser found int\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = (yyvsp[(1) - (1)].nd_obj).nd;  
                    (yyval.nd_obj).nd = mknode(num_children, children, "INT");
                ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 222 "t2parser.y"
    {
                    printf("Parser found float\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = (yyvsp[(1) - (1)].nd_obj).nd;  
                    (yyval.nd_obj).nd = mknode(num_children, children, "FLOAT");
                ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 229 "t2parser.y"
    {
                    printf("Parser found character\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = (yyvsp[(1) - (1)].nd_obj).nd;  
                    (yyval.nd_obj).nd = mknode(num_children, children, "CHAR");
                ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 236 "t2parser.y"
    {
                    printf("Parser found string\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = (yyvsp[(1) - (1)].nd_obj).nd;  
                    (yyval.nd_obj).nd = mknode(num_children, children, "STRING");
                ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 243 "t2parser.y"
    {
                    printf("Parser found identifier\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = (yyvsp[(1) - (1)].nd_obj).nd;  
                    (yyval.nd_obj).nd = mknode(num_children, children, "ID");
                ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 250 "t2parser.y"
    {
                    printf("Parser found funcCall\n");
                    int num_children = 1;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = (yyvsp[(1) - (1)].nd_obj).nd;  
                    (yyval.nd_obj).nd = mknode(num_children, children, "funcCall");
                ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 257 "t2parser.y"
    {
                    printf("Parser found id[exp]\n");
                    int num_children = 4;  // Number of children
                    struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
                    children[0] = (yyvsp[(1) - (4)].nd_obj).nd;  
                    children[1] = (yyvsp[(2) - (4)].nd_obj).nd; 
                    children[2] = (yyvsp[(3) - (4)].nd_obj).nd; 
                    children[3] = (yyvsp[(4) - (4)].nd_obj).nd; 
                    (yyval.nd_obj).nd = mknode(num_children, children, "ID[exp]");
                ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 267 "t2parser.y"
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

  case 50:

/* Line 1455 of yacc.c  */
#line 281 "t2parser.y"
    { 
        printf("Parser found exp-arithmeticOp-exp\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        
        // Assigning children nodes
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;  // Assuming $1 represents the parse tree node for symbol1
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd;  // Assuming $2 represents the parse tree node for symbol2
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd;
        // Assign more children if needed
        
        // Create the parse tree node for the production rule
        (yyval.nd_obj).nd = mknode(num_children, children, "AthematicOp");
        
        // Free the memory allocated for the array of children
        //free(children);
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 298 "t2parser.y"
    { 
        printf("Parser found exp-logicalOp-exp\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd; 
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "LogicalOp");
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 307 "t2parser.y"
    { 
        printf("Parser found id[exp]\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd; 
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd;
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "id[exp]");
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 321 "t2parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "empty"); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 322 "t2parser.y"
    { 
        printf("Parser found EOL-bunch\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "eol-bunch");
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 330 "t2parser.y"
    { 
        printf("Parser found bunch-EOL\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "bunch-eol");
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 338 "t2parser.y"
    { 
        printf("Parser found bunch_of_statement if_else_ladder bunch\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "bunch-IfElse-bunch");
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 347 "t2parser.y"
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

  case 58:

/* Line 1455 of yacc.c  */
#line 360 "t2parser.y"
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

  case 59:

/* Line 1455 of yacc.c  */
#line 369 "t2parser.y"
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

  case 60:

/* Line 1455 of yacc.c  */
#line 379 "t2parser.y"
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

  case 61:

/* Line 1455 of yacc.c  */
#line 389 "t2parser.y"
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

  case 62:

/* Line 1455 of yacc.c  */
#line 399 "t2parser.y"
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

  case 63:

/* Line 1455 of yacc.c  */
#line 410 "t2parser.y"
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

  case 64:

/* Line 1455 of yacc.c  */
#line 420 "t2parser.y"
    {
        printf("PARSER ERROR: syntax error \n");
        int num_children = 0;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        (yyval.nd_obj).nd = mknode(num_children, children, "error-;");
;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 428 "t2parser.y"
    { 
        printf("Parser found exp\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (1)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "condition");
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 435 "t2parser.y"
    { 
        printf("Parser found exp-compareOp-exp\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd; 
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "condition");
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 444 "t2parser.y"
    { 
        printf("Parser found exp-logicalOp-exp\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd; 
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "condition");
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 455 "t2parser.y"
    { 
        printf("Parser found if(cond){bunch}\n");
        int num_children = 7;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (7)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (7)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (7)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (7)].nd_obj).nd;
        children[4] = (yyvsp[(5) - (7)].nd_obj).nd;
        children[5] = (yyvsp[(6) - (7)].nd_obj).nd;
        children[6] = (yyvsp[(7) - (7)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "if(cond){bunch}");
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 470 "t2parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "empty"); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 471 "t2parser.y"
    { 
        printf("Parser found eol elif_repeat\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "EOL-elifrepeat");
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 479 "t2parser.y"
    { 
        printf("Parser found elif(cond){bunch}\n");
        int num_children = 9;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (9)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (9)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (9)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (9)].nd_obj).nd;
        children[4] = (yyvsp[(5) - (9)].nd_obj).nd;
        children[5] = (yyvsp[(6) - (9)].nd_obj).nd;
        children[6] = (yyvsp[(7) - (9)].nd_obj).nd;
        children[7] = (yyvsp[(8) - (9)].nd_obj).nd;
        children[8] = (yyvsp[(9) - (9)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "elif(cond){bunch}");
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 496 "t2parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "empty"); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 497 "t2parser.y"
    { 
        printf("Parser found EOL-else\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "EOL-else");
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 505 "t2parser.y"
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

  case 75:

/* Line 1455 of yacc.c  */
#line 517 "t2parser.y"
    { 
        printf("Parser found ifElseLadder\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "ifElseLadder");
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 526 "t2parser.y"
    {    // without the else statement
        printf("Parser found ifElseLadder\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "ifElseLadder");
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 536 "t2parser.y"
    { 
        printf("Parser found while(cond){bunch}\n");
        int num_children = 7;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (7)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (7)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (7)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (7)].nd_obj).nd;
        children[4] = (yyvsp[(5) - (7)].nd_obj).nd;
        children[5] = (yyvsp[(6) - (7)].nd_obj).nd;
        children[6] = (yyvsp[(7) - (7)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "while(cond){bunch}");
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 551 "t2parser.y"
    { 
        printf("Parser found datatypeId=exp\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "datatypeId=exp");
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 561 "t2parser.y"
    { 
        printf("Parser found datatype Id\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "datatypeId");
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 569 "t2parser.y"
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

  case 81:

/* Line 1455 of yacc.c  */
#line 583 "t2parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "empty"); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 584 "t2parser.y"
    { 
        printf("Parser found paramRepDatatypeIdComma\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "paramRepDatatypeIdComma");
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 596 "t2parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "empty"); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 597 "t2parser.y"
    { 
        printf("Parser found parameters_line\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "paramLine");
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 608 "t2parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "empty"); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 609 "t2parser.y"
    { 
        printf("Parser found lastparam\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (1)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "paramEnd");
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 616 "t2parser.y"
    { 
        printf("Parser found lastparam\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (1)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "paramEnd");
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 623 "t2parser.y"
    { 
        printf("Parser found id-comma-prep\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "paramRep");
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 632 "t2parser.y"
    { 
        printf("Parser found const-comma-prep\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "paramRep");
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 643 "t2parser.y"
    {
        printf("Parser found idLine\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (1)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "idline");
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 652 "t2parser.y"
    { 
        printf("Parser found equation\n");
        int num_children = 3;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (3)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (3)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (3)].nd_obj).nd; 
        (yyval.nd_obj).nd = mknode(num_children, children, "id=exp");
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 661 "t2parser.y"
    { 
        printf("Parser found id[exp]=exp\n");
        int num_children = 6;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (6)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (6)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (6)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (6)].nd_obj).nd;
        children[4] = (yyvsp[(5) - (6)].nd_obj).nd;
        children[5] = (yyvsp[(6) - (6)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "id[exp]=exp");
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 675 "t2parser.y"
    { 
        printf("Parser found funContentEOL\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "funContentEOL");
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 683 "t2parser.y"
    { 
        printf("Parser found bunch_function_content\n");
        int num_children = 1;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (1)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "content-bunch");
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 690 "t2parser.y"
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

  case 96:

/* Line 1455 of yacc.c  */
#line 700 "t2parser.y"
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

  case 98:

/* Line 1455 of yacc.c  */
#line 714 "t2parser.y"
    { 
        printf("Parser found print_contentEOL\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "print_content-EOL");
    ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 722 "t2parser.y"
    {    // take care of infinite loop
        printf("Parser found EOL-print_content\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "EOL-printContent");
    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 730 "t2parser.y"
    { 
        printf("Parser found print_content-String\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "printContent-String");
    ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 738 "t2parser.y"
    { 
        printf("Parser found print_content-exp\n");
        int num_children = 2;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (2)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (2)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "printContent-exp");
    ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 746 "t2parser.y"
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

  case 103:

/* Line 1455 of yacc.c  */
#line 755 "t2parser.y"
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

  case 104:

/* Line 1455 of yacc.c  */
#line 766 "t2parser.y"
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

  case 105:

/* Line 1455 of yacc.c  */
#line 778 "t2parser.y"
    { 
        printf("Parser found equation\n");
        int num_children = 8;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (8)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (8)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (8)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (8)].nd_obj).nd;
        children[4] = (yyvsp[(5) - (8)].nd_obj).nd;
        children[5] = (yyvsp[(6) - (8)].nd_obj).nd;
        children[6] = (yyvsp[(7) - (8)].nd_obj).nd;
        children[7] = (yyvsp[(8) - (8)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "func-id-(param){content}");
    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 794 "t2parser.y"
    { 
        printf("Parser found id(idLine)Finish\n");
        int num_children = 4;  // Number of children
        struct node **children = (struct node **)malloc(num_children * sizeof(struct node *));
        children[0] = (yyvsp[(1) - (4)].nd_obj).nd;
        children[1] = (yyvsp[(2) - (4)].nd_obj).nd;
        children[2] = (yyvsp[(3) - (4)].nd_obj).nd; 
        children[3] = (yyvsp[(4) - (4)].nd_obj).nd;
        (yyval.nd_obj).nd = mknode(num_children, children, "id(idLine)Finish");
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2918 "t2parser.tab.c"
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
#line 804 "t2parser.y"


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



