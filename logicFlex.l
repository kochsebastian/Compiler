

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
            yylval.var = strdup(yytext);
           return VAR;
           /*ausgabe wieder hinzufügen*/
        }

{P_PRAE}{P_DIGIT}* {
            yylval.var = strdup(yytext);
            return PRAE;
        }

{P_FUNCT}{P_DIGIT}* {
            yylval.var = strdup(yytext);
            return FUNC;
        }

top {
            yylval.var = strdup(yytext);
            return TOPI;
}
bottom {
            yylval.var = strdup(yytext);
            return BOTTOMI;
}

\& {
   return AND;
}

\| {
   return OR;
}

\~ {
   return NOT;
}

\, {
   return KOMMA;
}

(->) {
   return PFEIL;
}

(<->) {
   return DOPPELPFEIL;
}

all {
   yylval.var = strdup(yytext);
   return ALLI;
}

ex {
   yylval.var = strdup(yytext);
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
