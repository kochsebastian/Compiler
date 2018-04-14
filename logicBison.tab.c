/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "logicBison.y" /* yacc.c:339  */

   #include <stdio.h>
   	extern int yyerror(char *error);
   	extern int yylex(void);
   	extern FILE *yyin;


#line 74 "logicBison.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "logicBison.tab.h".  */
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
#line 11 "logicBison.y" /* yacc.c:355  */

	typedef struct term_s term_s;
	typedef struct atom_s atom_s;
	typedef struct formula_s formula_s;

	typedef struct term_list_s term_list_s;



   enum typ {atom, and, or, not, impl, eql, all, ex, top, bottom};

	struct term_s{
		char* name;
		term_list_s* mylist;
		term_s* next;
	};

   struct term_list_s{
		term_s* first;
	};

	struct atom_s{
		char* name;
		term_list_s* mylist;
		atom_s* next;
	};

	struct formula_s{
		enum typ type;

      atom_s* a;

      formula_s* subformelNOT;

      formula_s* linkeformel;
      formula_s* rechteformel;

      formula_s* subformelQUANT;

      char* var;

      int brackets;

	};







   void printTermList(term_list_s* tl );

   void printFormula(formula_s* f, int aufruf);
   void transformNNF1(formula_s* f);
   void transformNNF2(formula_s* f);
   void transformNNF3(formula_s* f);
   formula_s* createFormulaATOM(unsigned int pType, atom_s* pA); // fuer Atom
   formula_s* createFormulaBOOL(unsigned int pType); //
   formula_s* createFormulaNOT(unsigned int pType,  formula_s* pSubformelNOT);
   formula_s* createFormulaQUANT(unsigned int pType, formula_s* pSubformelQUANT, char* pVar);
   formula_s* createFormulaBRACK(formula_s* pformel, int pBrackets);
   formula_s* createFormulaJUNKT(unsigned int pType,  formula_s* pLinkeformel, formula_s* pRechteformel);
   void printFormulaHladik(formula_s* lala);

   void printAtom(atom_s* a);
   void printTerm(term_s* t);
   formula_s* dieFormel;


#line 175 "logicBison.tab.c" /* yacc.c:355  */

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
#line 85 "logicBison.y" /* yacc.c:355  */

  char* sval;

  term_s* termval;
  atom_s* atomval;
  formula_s* formelval;
  term_list_s* tlistval;


#line 217 "logicBison.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LOGICBISON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 234 "logicBison.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   57

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  20
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  27
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  49

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   274

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   124,   125,   126,   129,   139,   150,   161,
     172,   177,   183,   189,   195,   201,   207,   213,   219,   225,
     231,   239,   246,   255,   262,   269,   279,   285
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOPPELPFEIL", "PFEIL", "OR", "AND",
  "NOT", "EXI", "ALLI", "OPENPAR", "CLOSEPAR", "KOMMA", "NEWLINE", "VAR",
  "PRAE", "FUNC", "TOPI", "BOTTOMI", "ERROR", "$accept", "stmtseq", "NNF3",
  "NNF2", "NNF1", "store", "Formel", "Atom", "Term", "TermL", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274
};
# endif

#define YYPACT_NINF -13

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-13)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      21,     3,    33,    23,    35,    33,    21,    13,   -13,   -13,
      19,    22,   -13,   -13,   -13,    41,   -13,    21,   -13,    33,
      33,     2,   -13,   -12,   -13,    21,    33,    33,    33,    33,
     -13,   -13,   -13,   -13,   -13,    42,    43,    45,   -13,    41,
       5,     9,    47,   -12,   -12,   -13,    46,   -13,   -13
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    22,    11,    12,
       0,     0,     6,     7,     8,     9,    10,     0,    13,     0,
       0,     0,     3,     0,     1,     0,     0,     0,     0,     0,
       5,    20,    19,    14,    23,    25,    27,     0,     4,    18,
      17,    16,    15,     0,     0,    21,     0,    26,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -13,    -5,   -13,   -13,   -13,   -13,    -2,   -13,   -13,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,    15,    16,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      18,    22,    34,    21,    35,    26,    27,    28,    29,    27,
      28,    29,    30,    33,    28,    29,    17,    31,    32,    24,
      38,    -2,     1,    23,    39,    40,    41,    42,     2,     3,
       4,     5,    46,    47,     6,    25,     7,    19,     8,     9,
       2,     3,     4,     5,    26,    27,    28,    29,     7,    20,
       8,     9,    43,    29,     0,    44,    45,    48
};

static const yytype_int8 yycheck[] =
{
       2,     6,    14,     5,    16,     3,     4,     5,     6,     4,
       5,     6,    17,    11,     5,     6,    13,    19,    20,     0,
      25,     0,     1,    10,    26,    27,    28,    29,     7,     8,
       9,    10,    43,    44,    13,    13,    15,    14,    17,    18,
       7,     8,     9,    10,     3,     4,     5,     6,    15,    14,
      17,    18,    10,     6,    -1,    12,    11,    11
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,     8,     9,    10,    13,    15,    17,    18,
      21,    22,    23,    24,    25,    26,    27,    13,    26,    14,
      14,    26,    21,    10,     0,    13,     3,     4,     5,     6,
      21,    26,    26,    11,    14,    16,    28,    29,    21,    26,
      26,    26,    26,    10,    12,    11,    29,    29,    11
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    20,    21,    21,    21,    21,    22,    23,    24,    25,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    27,    27,    28,    28,    28,    29,    29
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     3,     3,     3,     3,
       3,     4,     1,     1,     4,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 124 "logicBison.y" /* yacc.c:1661  */
    {}
#line 1332 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 125 "logicBison.y" /* yacc.c:1661  */
    {}
#line 1338 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 126 "logicBison.y" /* yacc.c:1661  */
    {}
#line 1344 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 129 "logicBison.y" /* yacc.c:1661  */
    {

      transformNNF3(dieFormel);
      printf("\nSchritt 3: ");
      printFormula(dieFormel,0);
      printf("\n");
      printFormulaHladik(dieFormel);
      printf("----------");
   }
#line 1358 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 139 "logicBison.y" /* yacc.c:1661  */
    {

      transformNNF2(dieFormel);
      printf("\nSchritt 2: ");
      printFormula(dieFormel,0);
      printf("\n");
      printFormulaHladik(dieFormel);
      printf("----------");
   }
#line 1372 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 150 "logicBison.y" /* yacc.c:1661  */
    {
      transformNNF1(dieFormel);
      printf("\nSchritt 1: ");
      printFormula(dieFormel,0);
      printf("\n");
      printFormulaHladik(dieFormel);
      printf("----------");

   }
#line 1386 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 161 "logicBison.y" /* yacc.c:1661  */
    {
      dieFormel = (yyvsp[0].formelval);
      printf("\nDie Formel: ");
      printFormula(dieFormel,0);
      printf("\n");
      printFormulaHladik(dieFormel);
      printf(" ---------- ");

}
#line 1400 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 172 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.formelval) = createFormulaATOM(atom, (yyvsp[0].atomval));
      printf("Parser: Atom->Formel\n");
      printFormula((yyval.formelval),0);
   }
#line 1410 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 177 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.formelval) = createFormulaBOOL(top);
      printf("Parser: True->Formel\n");
      printFormula((yyval.formelval),0);

   }
#line 1421 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 183 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.formelval) = createFormulaBOOL(bottom);
      printf("Parser: False->Formel\n");
      printFormula((yyval.formelval),0);

   }
#line 1432 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 189 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.formelval) = createFormulaNOT(not,(yyvsp[0].formelval));
      printf("Parser: Not Formel->Formel\n");
      printFormula((yyval.formelval),0);

   }
#line 1443 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 195 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.formelval) = createFormulaBRACK((yyvsp[-1].formelval), 1);
      printf("Parser: (Formel)->Formel\n");
      printFormula((yyval.formelval),0);

   }
#line 1454 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 201 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.formelval) = createFormulaJUNKT(and,(yyvsp[-2].formelval),(yyvsp[0].formelval));
      printf("Parser: FormelandFormel->Formel\n");
      printFormula((yyval.formelval),0);

   }
#line 1465 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 207 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.formelval) = createFormulaJUNKT(or,(yyvsp[-2].formelval),(yyvsp[0].formelval));
      printf("Parser: FormelorFormel->Formel\n");
      printFormula((yyval.formelval),0);

   }
#line 1476 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 213 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.formelval) = createFormulaJUNKT(impl,(yyvsp[-2].formelval),(yyvsp[0].formelval));
      printf("Parser: FormelimplFormel->Formel\n");
      printFormula((yyval.formelval),0);

   }
#line 1487 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 219 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.formelval) = createFormulaJUNKT(eql,(yyvsp[-2].formelval),(yyvsp[0].formelval));
      printf("Parser: FormeleqFormel->Formel\n");
      printFormula((yyval.formelval),0);

   }
#line 1498 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 225 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.formelval) = createFormulaQUANT(all,(yyvsp[0].formelval),(yyvsp[-1].sval));
      printf("Parser: AllVarFormel->Formel\n");
      printFormula((yyval.formelval),0);

   }
#line 1509 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 231 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.formelval) = createFormulaQUANT(ex,(yyvsp[0].formelval),(yyvsp[-1].sval));
      printf("Parser: ExVarFormel->Formel\n");
      printFormula((yyval.formelval),0);

   }
#line 1520 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 239 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.atomval) = (atom_s*) malloc(sizeof(atom_s));
      (yyval.atomval)->name = (yyvsp[-3].sval);
      (yyval.atomval)->mylist = (yyvsp[-1].tlistval);

      printf("Parser: Praedikat(TermListe)->Atom\n");
   }
#line 1532 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 246 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.atomval) = (atom_s*) malloc(sizeof(atom_s));
      (yyval.atomval)->name = (yyvsp[0].sval);
      (yyval.atomval)->mylist = NULL;

      printf("Parser: Praedikat->Atom\n");
   }
#line 1544 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 255 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.termval) = (term_s*) malloc(sizeof(term_s));
		(yyval.termval)->name = (yyvsp[0].sval);
		(yyval.termval)->next=NULL;
		(yyval.termval)->mylist=NULL;
      printf("Parser: Variable:->Term\n");
   }
#line 1556 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 262 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.termval) = (term_s*) malloc(sizeof(term_s));
		(yyval.termval)->name = (yyvsp[-3].sval);
		(yyval.termval)->next=NULL;
		(yyval.termval)->mylist = (yyvsp[-1].tlistval);
      printf("Parser: Funktiom(TermListe)->Term\n");
   }
#line 1568 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 269 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.termval) = (term_s*) malloc(sizeof(term_s));
		(yyval.termval)->name = (yyvsp[0].sval);
		(yyval.termval)->next=NULL;
		(yyval.termval)->mylist=NULL;
      printf("Parser: Funktion->Term\n");
   }
#line 1580 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 279 "logicBison.y" /* yacc.c:1661  */
    {
      (yyvsp[-2].termval)->next = (yyvsp[0].tlistval)->first;
      (yyvsp[0].tlistval)->first= (yyvsp[-2].termval);
      (yyval.tlistval) = (yyvsp[0].tlistval);
      printf("Parser: Term,TermListe->TermListe\n");
   }
#line 1591 "logicBison.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 285 "logicBison.y" /* yacc.c:1661  */
    {
      (yyval.tlistval) = (term_list_s*) malloc(sizeof(term_list_s));
	   (yyval.tlistval)->first = (yyvsp[0].termval);
      printf("Parser: Term->TermListe\n");
   }
#line 1601 "logicBison.tab.c" /* yacc.c:1661  */
    break;


#line 1605 "logicBison.tab.c" /* yacc.c:1661  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 291 "logicBison.y" /* yacc.c:1906  */





   void printAtom(atom_s* a  ){


      printf("%s",a->name);
   	if(a->mylist == NULL){

   	}
   	else{
         printf("(");
   	   printTermList(a->mylist);
         printf(")");
   	}

   }

   void printTermList(term_list_s* tl ){
     term_s* myt = tl->first;

     while(myt != NULL){
        printTerm(myt);
        if(myt->mylist != NULL){
           printf("(");
         printTermList(myt->mylist);
         printf(")");
       }
        myt = myt->next;
     }

  }

   void printTerm(term_s* t){

   	printf("%s",t->name);
   	if(t->next == NULL){

   	}
   	else{
         printf(",");
   	}
   }


   formula_s* createFormulaATOM(unsigned int pType, atom_s* pA){
      formula_s* returnFormula = (formula_s*) malloc(sizeof(formula_s));
      returnFormula->type = pType;
      returnFormula->a = pA;
      return returnFormula;
   }

   formula_s* createFormulaBOOL(unsigned int pType){
      formula_s* returnFormula = (formula_s*) malloc(sizeof(formula_s));
      returnFormula->type = pType;

      return returnFormula;
   }

   formula_s* createFormulaNOT(unsigned int pType,  formula_s* pSubformelNOT){
      formula_s* returnFormula = (formula_s*) malloc(sizeof(formula_s));
      returnFormula->type = pType;

      returnFormula->subformelNOT = pSubformelNOT;
      return returnFormula;
   }

   formula_s* createFormulaQUANT(unsigned int pType, formula_s* pSubformelQUANT, char* pVar){
      formula_s* returnFormula = (formula_s*) malloc(sizeof(formula_s));
      returnFormula->type = pType;

      returnFormula->subformelQUANT = pSubformelQUANT;
      returnFormula->var = pVar;
      return returnFormula;
   }

   formula_s* createFormulaBRACK(formula_s* pFormel, int pBrackets){
      formula_s* returnFormula = (formula_s*) malloc(sizeof(formula_s));
      returnFormula = pFormel;
      returnFormula->brackets = pBrackets;
      return returnFormula;
   }
   formula_s* createFormulaJUNKT(unsigned int pType,  formula_s* pLinkeformel, formula_s* pRechteformel){
      formula_s* returnFormula = (formula_s*) malloc(sizeof(formula_s));
      returnFormula->type = pType;

      returnFormula->linkeformel = pLinkeformel;
      returnFormula->rechteformel = pRechteformel;
      return returnFormula;
   }

   void printFormula(formula_s* f, int aufruf){
      if(f->brackets == 1){
         printf("(");
      }
      switch(f->type){
         case atom: printAtom(f->a);break;
         case and: printFormula(f->linkeformel,1);printf(" & ");printFormula(f->rechteformel,1);break;
         case or: printFormula(f->linkeformel,1);printf(" | ");printFormula(f->rechteformel,1);break;
         case not: printf(" ~ "); printFormula(f->subformelNOT,1); break;
         case impl:printFormula(f->linkeformel,1);printf(" -> ");printFormula(f->rechteformel,1);break;
         case eql:printFormula(f->linkeformel,1);printf(" <-> ");printFormula(f->rechteformel,1);break;
         case all: printf(" all "); printf("%s ",f->var); printFormula(f->subformelQUANT,1); break;
         case ex: printf(" ex "); printf("%s ",f->var); printFormula(f->subformelQUANT,1);break;
         case top:printf(" top ");break;
         case bottom:printf(" bottom ");break;
         default: printf("ERROR in printFormula");break;
      }
      if(f->brackets == 1){
      printf(")");
      }
      if(aufruf== 0)
         printf("\n");

   }

   void printFormulaHladik(formula_s* f){

      switch(f->type){
         case atom: printAtom(f->a);break;
         case and: printf("AND\n");printFormulaHladik(f->linkeformel);printf("\n");printFormulaHladik(f->rechteformel);printf("\n");break;
         case or: printf("OR\n");printFormulaHladik(f->linkeformel);printf("\n");printFormulaHladik(f->rechteformel);printf("\n");break;
         case impl: printf("IMPL\n");printFormulaHladik(f->linkeformel);printf("\n");printFormulaHladik(f->rechteformel);printf("\n");break;
         case eql: printf("EQL\n");printFormulaHladik(f->linkeformel);printf("\n");printFormulaHladik(f->rechteformel);printf("\n");break;
         case not: printf("NOT\n"); printFormulaHladik(f->subformelNOT); printf("\n");break;
         case all: printf("ALL "); printf("%s \n",f->var); printFormulaHladik(f->subformelQUANT);printf("\n"); break;
         case ex: printf("EX "); printf("%s \n",f->var); printFormulaHladik(f->subformelQUANT);printf("\n");break;
         case top:printf("TOP\n");break;
         case bottom:printf("BOTTOM\n");break;
         default: printf("ERROR in printFormula");break;
      }


   }


   void transformNNF1(formula_s* f){
      formula_s* tmp1;
      formula_s* tmp2;
      formula_s* tmp3;
      switch(f->type){
         case atom:
            break;// do nothing
         case and:
            transformNNF1(f->linkeformel);transformNNF1(f->rechteformel);break;
         case or:
            transformNNF1(f->linkeformel);transformNNF1(f->rechteformel);break;
         case not:
            transformNNF1(f->subformelNOT); break;
         case impl:
            tmp1 = createFormulaNOT(not, f->linkeformel);
            f->type = or;
            f->linkeformel = tmp1;
            transformNNF1(f->linkeformel);transformNNF1(f->rechteformel); break;
            break;

         case eql:
            tmp1 = createFormulaJUNKT(and,  f->linkeformel, f->rechteformel);
            tmp2 = createFormulaNOT(not, f->rechteformel);
            tmp3 = createFormulaNOT(not, f->linkeformel);
            f->type = or;
            f->linkeformel = tmp1;
            f->linkeformel->brackets = 1;
            tmp1 = createFormulaJUNKT(and,  f->linkeformel, f->rechteformel);
            f->rechteformel = tmp1;
            f->rechteformel->brackets = 1;
            f->rechteformel->linkeformel = tmp3;
            f->rechteformel->rechteformel = tmp2;
            transformNNF1(f->linkeformel);transformNNF1(f->rechteformel);
            break;

         case all: transformNNF1(f->subformelQUANT); break;
         case ex: transformNNF1(f->subformelQUANT);break;
         case top:break;
         case bottom:break;
         default: printf("ERROR in transformNNF");break;
      }


   }

   void transformNNF2(formula_s* f){
      formula_s* tmp1;
      formula_s* tmp2;

      switch(f->type){
         case atom:break;// do nothing
         case and:transformNNF2(f->linkeformel);transformNNF2(f->rechteformel);break;
         case or:transformNNF2(f->linkeformel);transformNNF2(f->rechteformel);break;
         case not:
            if(f->subformelNOT->type == or){// nichtformel->oderformel
               f->type = and;
               tmp1 = createFormulaNOT(not,f->subformelNOT->linkeformel);
               tmp2 = createFormulaNOT(not,f->subformelNOT->rechteformel);
               f->linkeformel = tmp1;
               f->rechteformel = tmp2;
               f->brackets = 0;
               transformNNF2(f->linkeformel);transformNNF2(f->rechteformel);
            }
            else if(f->subformelNOT->type == and){// nichtformel->oderformel
               f->type = or;
               tmp1 = createFormulaNOT(not,f->subformelNOT->linkeformel);
               tmp2 = createFormulaNOT(not,f->subformelNOT->rechteformel);
               f->linkeformel = tmp1;
               f->rechteformel = tmp2;
               f->brackets = 0;
               transformNNF2(f->linkeformel);transformNNF2(f->rechteformel);
            }
            else{
               transformNNF2(f->subformelNOT);
            }
            break;
         case all: transformNNF2(f->subformelQUANT); break;
         case ex: transformNNF2(f->subformelQUANT);break;
         case top:break;
         case bottom:break;
         default: printf("ERROR in transformNNF");break;
      }


   }
   void transformNNF3(formula_s* f){
      formula_s* tmp;
      switch(f->type){
      case atom:break;// do nothing
      case and:transformNNF3(f->linkeformel);transformNNF3(f->rechteformel);break;
      case or:transformNNF3(f->linkeformel);transformNNF3(f->rechteformel);break;
      case not:
         if(f->subformelNOT->type == not){
            tmp = (formula_s*) (formula_s*) malloc(sizeof(formula_s));
            tmp = f->subformelNOT->subformelNOT;
            *(f) = *(tmp);
            transformNNF3(f);
         }else if(f->subformelNOT->type == top){
            f->type = bottom;
            break;
         }else if(f->subformelNOT->type == bottom){
            f->type = top;
            break;
         }else if(f->subformelNOT->type == all){
            f->type = ex;
            f->var = f->subformelNOT->var;
            f->subformelQUANT = createFormulaNOT(not,f->subformelNOT->subformelQUANT);
            transformNNF3(f->subformelQUANT);
         }else if(f->subformelNOT->type == ex){
            f->type = all;
            f->var = f->subformelNOT->var;
            f->subformelQUANT = createFormulaNOT(not,f->subformelNOT->subformelQUANT);
            transformNNF3(f->subformelQUANT);
         }else
            transformNNF3(f->subformelNOT);
         break;
      case all: transformNNF3(f->subformelQUANT); break;
      case ex: transformNNF3(f->subformelQUANT);break;
      case top: break;
      case bottom: break;
      default: printf("ERROR in transformNNF");break;
   }
}


 int yyerror(char* err){
 	printf("Error: %s\n",err);
 	return 0;
 }


int main(int argc,char** argv){
	++argv, --argc;
   if ( argc > 0 )
      yyin = fopen( argv[0], "r" );
   else{
   	  yyin = stdin;
    }
   return yyparse();
}
