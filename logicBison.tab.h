/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_LOGICBISON_TAB_H_INCLUDED
# define YY_YY_LOGICBISON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 11 "logicBison.y" /* yacc.c:1915  */
	//Alle folgenden Zeilen werden ins
   //Typedef der Structs vor der konkreten Implementation aufgrund von rekursiven Abhaengigkeiten
	//Benoetigte Structs: Term, Atom und Formel.
	typedef struct term_s term_s;
	typedef struct atom_s atom_s;
	typedef struct formula_s formula_s;
	//Zusaetzlich werden extra Structs fuer die Startzeiger angelegt, um die Uebersichtlichkeit zu bewahren
	typedef struct term_list_s term_list_s;
   typedef struct formula_list_s formula_list_s;


   enum typ {atom, and, or, not, impl, eql, all, ex, top, bottom};

	struct term_s{
		char* name;			//Name
		term_list_s* mylist;	//Eigene Termliste (Bei keiner Verwendung NULL)
		term_s* next;			//Naechstes Element, falls es sich in einer Liste befindet
	};

	struct atom_s{
		char* name;			//Siehe Term
		term_list_s* mylist;
		atom_s* next;
	};

	struct formula_s{
		enum typ type;
      char* operant;

      atom_s* a;
      term_list_s* mylist;

      formula_s* Notsubformel;

      formula_s* linkeformel;
      formula_s* rechteformel;

      char* var;
      formula_s* Quantsubformel;

      char* truefalse;
      int brackets;

	};

	struct term_list_s{
		term_s* first;		//Startknoten der Liste
	};

   struct formula_list_s{
      formula_s* dieFormel;
   };



   void printTermList(term_list_s* tl );
   void printFormulaList(formula_list_s* fl);
   void printFormula(formula_s* f, int aufruf);
   void transformNNF(formula_s* f);

   void printAtom(atom_s* a);
   void printTerm(term_s* t);



#line 110 "logicBison.tab.h" /* yacc.c:1915  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DOPPELPFEIL = 258,
    PFEIL = 259,
    OR = 260,
    AND = 261,
    NOT = 262,
    EXI = 263,
    ALLI = 264,
    OPENPAR = 265,
    CLOSEPAR = 266,
    KOMMA = 267,
    NEWLINE = 268,
    VAR = 269,
    PRAE = 270,
    FUNC = 271,
    TOPI = 272,
    BOTTOMI = 273,
    ERROR = 274
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 80 "logicBison.y" /* yacc.c:1915  */

  char* sval;

  term_s* termval;
  atom_s* atomval;
  formula_s* formelval;
  term_list_s* tlistval;
  formula_list_s* flistval;
  formula_s* nnf;

#line 153 "logicBison.tab.h" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LOGICBISON_TAB_H_INCLUDED  */
