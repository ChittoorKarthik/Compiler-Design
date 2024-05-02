
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 174 "t2parser.y"
 
	struct var_name { 
		char name[10000]; 
		struct node* nd;
	} nd_obj; 



/* Line 1676 of yacc.c  */
#line 92 "t2parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


