

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
           return VAR;
        }

{P_PRAE}{P_DIGIT}* {
            yylval.sval = strdup(yytext);
            return PRAE;
        }

{P_FUNCT}{P_DIGIT}* {
            yylval.sval = strdup(yytext);
            return FUNC;
        }

top {
            yylval.sval = strdup(yytext);
            return TOPI;
}
bottom {
            yylval.sval = strdup(yytext);
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
   yylval.sval = strdup(yytext);
   return ALLI;
}

ex {
   yylval.sval = strdup(yytext);
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
