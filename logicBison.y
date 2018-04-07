

%{
   #include <stdio.h>
   	extern int yyerror(char *error);
   	extern int yylex(void);
   	extern FILE *yyin;

%}

 %code requires{	//Alle folgenden Zeilen werden ins
   //Typedef der Structs vor der konkreten Implementation aufgrund von rekursiven Abhaengigkeiten
	//Benoetigte Structs: Term, Atom und Formel.
	typedef struct term_s term_s;
	typedef struct atom_s atom_s;
	typedef struct formula_s formula_s;
	//Zusaetzlich werden extra Structs fuer die Startzeiger angelegt, um die Uebersichtlichkeit zu bewahren
	typedef struct term_list_s term_list_s;


   enum typ {atom, and, or, not, impl, eql, all, ex, top, bottom, brackets};

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

      formula_s* next;
	};

	struct term_list_s{
		term_s* first;		//Startknoten der Liste
	};



   void printTermList(term_list_s* tl );

   void printFormula(formula_s* f, int aufruf);
   void createFormulaList(formula_s* f);
   void printAtom(atom_s* a);
   void printTerm(term_s* t);



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

%token VAR
%token PRAE
%token FUNC
%token TOPI
%token BOTTOMI

%token ERROR


%%

stmtseq: /* Empty */
    | NEWLINE stmtseq       {}
    | Formel  NEWLINE stmtseq {}
    | error NEWLINE stmtseq {};  /* After an error start afresh */

Formel:
   Atom {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = atom;
      $<formelval>$->a = $<atomval>1;
      printf("Parser: Atom->Formel\n");
      printFormula($<formelval>$,0);
      createFormulaList($<formelval>$);
   }
   | TOPI {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = top;
      $<formelval>$->truefalse = $<sval>1;
      printf("Parser: True->Formel\n");
      printFormula($<formelval>$,0);
      createFormulaList($<formelval>$);
   }
   | BOTTOMI {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = bottom;
      $<formelval>$->truefalse = $<sval>1;
      printf("Parser: False->Formel\n");
      printFormula($<formelval>$,0);
      createFormulaList($<formelval>$);
   }
   | NOT Formel {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = not;
      $<formelval>$->operant = $<sval>1;
      $<formelval>$->Notsubformel = $<formelval>2;
      printf("Parser: Not Formel->Formel\n");
      printFormula($<formelval>$,0);
      createFormulaList($<formelval>$);
   }
   | OPENPAR Formel CLOSEPAR {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$ = $<formelval>2;
      $<formelval>$->type = brackets;
      printf("Parser: (Formel)->Formel\n");
      printFormula($<formelval>$,0);
      createFormulaList($<formelval>$);
   }
   | Formel AND Formel {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = and;
      $<formelval>$->operant = $<sval>2;
      $<formelval>$->linkeformel = $<formelval>1;
      $<formelval>$->rechteformel = $<formelval>3;
      printf("Parser: FormelandFormel->Formel\n");
      printFormula($<formelval>$,0);
      createFormulaList($<formelval>$);
   }
   | Formel OR Formel {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = or;
      $<formelval>$->operant = $<sval>2;
      $<formelval>$->linkeformel = $<formelval>1;
      $<formelval>$->rechteformel = $<formelval>3;
      printf("Parser: FormelorFormel->Formel\n");
      printFormula($<formelval>$,0);
      createFormulaList($<formelval>$);
   }
   | Formel PFEIL Formel {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = impl;
      $<formelval>$->operant = $<sval>2;
      $<formelval>$->linkeformel = $<formelval>1;
      $<formelval>$->rechteformel = $<formelval>3;
      printf("Parser: FormelimplFormel->Formel\n");
      printFormula($<formelval>$,0);
      createFormulaList($<formelval>$);
   }
   | Formel DOPPELPFEIL Formel {
       $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = eql;
      $<formelval>$->operant = $<sval>2;
      $<formelval>$->linkeformel = $<formelval>1;
      $<formelval>$->rechteformel = $<formelval>3;
      printf("Parser: FormeleqFormel->Formel\n");
      printFormula($<formelval>$,0);
      createFormulaList($<formelval>$);
   }
   | ALLI VAR Formel {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = all;
      $<formelval>$->operant = $<sval>1;
      $<formelval>$->var = $<sval>2;
      $<formelval>$->Quantsubformel = $<formelval>3;
      printf("Parser: AllVarFormel->Formel\n");
      printFormula($<formelval>$,0);
      createFormulaList($<formelval>$);
   }
   | EXI VAR Formel {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = ex;
      $<formelval>$->operant = $<sval>1;
      $<formelval>$->var = $<sval>2;
      $<formelval>$->Quantsubformel = $<formelval>3;
      printf("Parser: ExVarFormel->Formel\n");
      printFormula($<formelval>$,0);
      createFormulaList($<formelval>$);
   };

Atom:
   PRAE OPENPAR TermL CLOSEPAR {
      $<atomval>$ = (atom_s*) malloc(sizeof(atom_s));
      $<atomval>$->name = $<sval>1;
      $<atomval>$->mylist = $<tlistval>3;
      printf("Parser: Praedikat(TermListe)->Atom\n");
   };

Term:
   VAR {
      $<termval>$ = (term_s*) malloc(sizeof(term_s));
		$<termval>$->name = $<sval>1;
		$<termval>$->next=NULL;
		$<termval>$->mylist=NULL;
      printf("Parser: Variable->Term\n");
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

    void printTermList(term_list_s* tl ){
   	term_s* myt = tl->first;
   	while(myt != NULL){
   		printTerm(myt);
   		myt = myt->next;
   	}
   }


   void printAtom(atom_s* a  ){

   	printf("%s(",a->name);

   	if(a->mylist == NULL){
   			printf("NULL\n");
   	}
   	else{
   	   printTermList(a->mylist);
   	}
      printf(")");
   }

   void printTerm(term_s* t){

   	printf("%s",t->name);
   	if(t->next == NULL){

   	}
   	else{
         printf(",");
   	}
   }





   void printFormula(formula_s* f, int aufruf){

      switch(f->type){
         case atom: printAtom(f->a);break;
         case and: printFormula(f->linkeformel,1);printf(" & ");printFormula(f->rechteformel,1);break;
         case or: printFormula(f->linkeformel,1);printf(" | ");printFormula(f->rechteformel,1);break;
         case not: printf(" ~ "); printFormula(f->Notsubformel,1); break;
         case impl:printFormula(f->linkeformel,1);printf(" -> ");printFormula(f->rechteformel,1);break;
         case eql:printFormula(f->linkeformel,1);printf(" <-> ");printFormula(f->rechteformel,1);break;
         case all: printf(" all "); printf("%s ",f->var); printFormula(f->Quantsubformel,1); break;
         case ex: printf(" ex "); printf("%s ",f->var); printFormula(f->Quantsubformel,1);break;
         case top:printf(" top ");break;
         case bottom:printf(" bottom ");break;
         default: printf("ERROR");break;
      }
      if(aufruf==0)
         printf("\n");
   }

   void createFormulaList(formula_s* f){
      if(dieFormel == NULL){
         dieFormel = (formula_s*) malloc(sizeof(formula_s));
         dieFormel = f;
      }else{
         while(dieFormel->next != NULL){
            dieFormel = dieFormel->next;
         }
         dieFormel->next = (formula_s*) malloc(sizeof(formula_s));
         dieFormel = dieFormel->next;
         dieFormel = f;
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
