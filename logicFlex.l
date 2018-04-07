

%option noyywrap

%{
  #include "logicBison.tab.h"
%}

P_VAR [n-z]
P_FUNCT [a-m]
P_PRAE [A-Z]
P_DIGIT [0-9]

%%


"(" {return OPENPAR;}
")" {return CLOSEPAR;}
\n  {return NEWLINE;}



{P_VAR}{P_DIGIT}* {
            yylval.sval = strdup(yytext);
         //   printf("Lexer: Variable:%s \n",yylval.sval);
            return VAR;
        }

{P_PRAE}{P_DIGIT}* {
            yylval.sval = strdup(yytext);
         //   printf("Lexer: Predikat:%s \n",yylval.sval);
            return PRAE;
        }

{P_FUNCT}{P_DIGIT}* {
            yylval.sval = strdup(yytext);
         //   printf("Lexer: Funktion:%s \n",yylval.sval);
            return FUNC;
        }

top {
            yylval.sval = strdup(yytext);
         //   printf("Lexer: Boolean:%s \n",yylval.sval);
            return TOPI;
}
bottom {
            yylval.sval = strdup(yytext);
         //   printf("Lexer: Boolean:%s \n",yylval.sval);
            return BOTTOMI;
}

\& {
   yylval.sval = strdup(yytext);
   return AND;
}

\| {
   yylval.sval = strdup(yytext);
   return OR;
}

\~ {
   yylval.sval = strdup(yytext);
   return NOT;
}

\, {

   return KOMMA;
}

(->) {
   yylval.sval = strdup(yytext);
   return PFEIL;
}

(<->) {
   yylval.sval = strdup(yytext);
   return DOPPELPFEIL;
}

all {
   yylval.sval = strdup(yytext);
   //printf("Lexer: Quantor:%s \n",yylval.sval);
   return ALLI;
}

ex {
   yylval.sval = strdup(yytext);
   //printf("Lexer: Quantor:%s \n",yylval.sval);
   return EXI;
}



\n|\r\n {
  return  NEWLINE;
}

[ ] {
  /* Skip */
}

. ;
%%
