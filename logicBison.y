

%{
   #include <stdio.h>
   	extern int yyerror(char *error);
   	extern int yylex(void);
   	extern FILE *yyin;

%}

 %code requires{
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

};




%union {
  char* sval;

  term_s* termval;
  atom_s* atomval;
  formula_s* formelval;
  term_list_s* tlistval;

}


%start stmtseq

%precedence DOPPELPFEIL
%precedence PFEIL
%precedence OR
%precedence AND
%precedence NOT
%precedence EXI
%precedence ALLI

%token OPENPAR
%token CLOSEPAR
%token KOMMA

%token NEWLINE

%left VAR
%token PRAE
%token FUNC
%token TOPI
%token BOTTOMI

%token ERROR


%%

stmtseq: /* Empty */
    | NEWLINE stmtseq       {}
    | NNF3 NEWLINE stmtseq {}
    | error NEWLINE stmtseq {};  /* After an error start afresh */

NNF3:
   NNF2 {

      transformNNF3(dieFormel);
      printf("\nSchritt 3: ");
      printFormula(dieFormel,0);
      printf("\n");
      printFormulaHladik(dieFormel);
      printf("----------");
   };
NNF2:
   NNF1 {

      transformNNF2(dieFormel);
      printf("\nSchritt 2: ");
      printFormula(dieFormel,0);
      printf("\n");
      printFormulaHladik(dieFormel);
      printf("----------");
   };

NNF1:
   store {
      transformNNF1(dieFormel);
      printf("\nSchritt 1: ");
      printFormula(dieFormel,0);
      printf("\n");
      printFormulaHladik(dieFormel);
      printf("----------");

   };

store:
    Formel {
      dieFormel = $<formelval>1;
      printf("\nDie Formel: ");
      printFormula(dieFormel,0);
      printf("\n");
      printFormulaHladik(dieFormel);
      printf(" ---------- ");

};

Formel:
   Atom {
      $<formelval>$ = createFormulaATOM(atom, $<atomval>1);
      printf("Parser: Atom->Formel\n");
      printFormula($<formelval>$,0);
   }
   | TOPI {
      $<formelval>$ = createFormulaBOOL(top);
      printf("Parser: True->Formel\n");
      printFormula($<formelval>$,0);

   }
   | BOTTOMI {
      $<formelval>$ = createFormulaBOOL(bottom);
      printf("Parser: False->Formel\n");
      printFormula($<formelval>$,0);

   }
   | NOT Formel {
      $<formelval>$ = createFormulaNOT(not,$<formelval>2);
      printf("Parser: Not Formel->Formel\n");
      printFormula($<formelval>$,0);

   }
   | OPENPAR Formel CLOSEPAR {
      $<formelval>$ = createFormulaBRACK($<formelval>2, 1);
      printf("Parser: (Formel)->Formel\n");
      printFormula($<formelval>$,0);

   }
   | Formel AND Formel {
      $<formelval>$ = createFormulaJUNKT(and,$<formelval>1,$<formelval>3);
      printf("Parser: FormelandFormel->Formel\n");
      printFormula($<formelval>$,0);

   }
   | Formel OR Formel {
      $<formelval>$ = createFormulaJUNKT(or,$<formelval>1,$<formelval>3);
      printf("Parser: FormelorFormel->Formel\n");
      printFormula($<formelval>$,0);

   }
   | Formel PFEIL Formel {
      $<formelval>$ = createFormulaJUNKT(impl,$<formelval>1,$<formelval>3);
      printf("Parser: FormelimplFormel->Formel\n");
      printFormula($<formelval>$,0);

   }
   | Formel DOPPELPFEIL Formel {
      $<formelval>$ = createFormulaJUNKT(eql,$<formelval>1,$<formelval>3);
      printf("Parser: FormeleqFormel->Formel\n");
      printFormula($<formelval>$,0);

   }
   | ALLI VAR Formel {
      $<formelval>$ = createFormulaQUANT(all,$<formelval>3,$<sval>2);
      printf("Parser: AllVarFormel->Formel\n");
      printFormula($<formelval>$,0);

   }
   | EXI VAR Formel {
      $<formelval>$ = createFormulaQUANT(ex,$<formelval>3,$<sval>2);
      printf("Parser: ExVarFormel->Formel\n");
      printFormula($<formelval>$,0);

   };

Atom:
   PRAE OPENPAR TermL CLOSEPAR {
      $<atomval>$ = (atom_s*) malloc(sizeof(atom_s));
      $<atomval>$->name = $<sval>1;
      $<atomval>$->mylist = $<tlistval>3;

      printf("Parser: Praedikat(TermListe)->Atom\n");
   }
   | PRAE {
      $<atomval>$ = (atom_s*) malloc(sizeof(atom_s));
      $<atomval>$->name = $<sval>1;
      $<atomval>$->mylist = NULL;

      printf("Parser: Praedikat->Atom\n");
   };

Term:
   VAR {
      $<termval>$ = (term_s*) malloc(sizeof(term_s));
		$<termval>$->name = $<sval>1;
		$<termval>$->next=NULL;
		$<termval>$->mylist=NULL;
      printf("Parser: Variable:->Term\n");
   }
   | FUNC OPENPAR TermL CLOSEPAR {
      $<termval>$ = (term_s*) malloc(sizeof(term_s));
		$<termval>$->name = $<sval>1;
		$<termval>$->next=NULL;
		$<termval>$->mylist = $<tlistval>3;
      printf("Parser: Funktiom(TermListe)->Term\n");
   }
   | FUNC {
      $<termval>$ = (term_s*) malloc(sizeof(term_s));
		$<termval>$->name = $<sval>1;
		$<termval>$->next=NULL;
		$<termval>$->mylist=NULL;
      printf("Parser: Funktion->Term\n");
   };


TermL:
   Term KOMMA TermL {
      $<termval>1->next = $<tlistval>3->first;
      $<tlistval>3->first= $<termval>1;
      $<tlistval>$ = $<tlistval>3;
      printf("Parser: Term,TermListe->TermListe\n");
   }
   | Term {
      $<tlistval>$ = (term_list_s*) malloc(sizeof(term_list_s));
	   $<tlistval>$->first = $<termval>1;
      printf("Parser: Term->TermListe\n");
   };

%%




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
