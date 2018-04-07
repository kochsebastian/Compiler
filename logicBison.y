

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
	typedef struct atom_list_s atom_list_s;
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

      char* string;
      atom_s* a;
      term_list_s* mylist;

      formula_s* Notsubformel;

      formula_s* linkeformel;
      formula_s* rechteformel;

      char* var;
      formula_s* Quantsubformel;

      char* boolsch;

      formula_s* next;
	};

	struct term_list_s{
		term_s* first;		//Startknoten der Liste
	};

	struct atom_list_s{
		atom_s* first;
	};

	struct formula_list_s{
		formula_s* first;
	};

};



%union {
  char* sval;

  term_s* termval;
  atom_s* atomval;
  formula_s* formelval;
  term_list_s* tlistval;
  atom_list_s* alistval;
  formula_list_s* flistval;

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
    | error NEWLINE stmtseq {};  /* After an error, start afresh */

Formel:
   Atom {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = atom;
      $<formelval>$->a = $<atomval>1;
      printf("Atom->Formel\n");
   }
   | TOPI {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = top;
      $<formelval>$->boolsch = $<sval>1;
      printf("True->Formel\n");
   }
   | BOTTOMI {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = bottom;
      $<formelval>$->boolsch = $<sval>1;
      printf("False->Formel\n");
   }
   | NOT Formel {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = not;
      $<formelval>$->Notsubformel = $<formelval>2;
      printf("Not Formel->Formel\n");
   }
   | OPENPAR Formel CLOSEPAR {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$ = $<formelval>2;
      printf("(Formel)->Formel\n");
   }
   | Formel AND Formel {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = and;
      $<formelval>$->linkeformel = $<formelval>1;
      $<formelval>$->rechteformel = $<formelval>3;
      printf("FormelandFormel->Formel\n");
   }
   | Formel OR Formel {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = or;
      $<formelval>$->linkeformel = $<formelval>1;
      $<formelval>$->rechteformel = $<formelval>3;
      printf("FormelorFormel->Formel\n");
   }
   | Formel PFEIL Formel {
      $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = impl;
      $<formelval>$->linkeformel = $<formelval>1;
      $<formelval>$->rechteformel = $<formelval>3;
      printf("FormelimplFormel->Formel\n");
   }
   | Formel DOPPELPFEIL Formel {
       $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = eql;
      $<formelval>$->linkeformel = $<formelval>1;
      $<formelval>$->rechteformel = $<formelval>3;
      printf("FormeleqFormel->Formel\n");
   }
   | ALLI VAR Formel {
       $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = all;
      $<formelval>$->var = $<sval>2;
      $<formelval>$->Quantsubformel = $<formelval>3;
      printf("AllVarFormel->Formel\n");
   }
   | EXI VAR Formel {
       $<formelval>$ = (formula_s*) malloc(sizeof(formula_s));
      $<formelval>$->type = ex;
      $<formelval>$->var = $<sval>2;
      $<formelval>$->Quantsubformel = $<formelval>3;
      printf("ExVarFormel->Formel\n");
   };

Atom:
   PRAE OPENPAR TermL CLOSEPAR {
       $<atomval>$ = (atom_s*) malloc(sizeof(atom_s));
      $<atomval>$->name = $<sval>1;
      $<atomval>$->mylist = $<tlistval>3;
      printf("Praedikat(TermListe)->Atom\n");
   };

Term:
   VAR {
      $<termval>$ = (term_s*) malloc(sizeof(term_s));
		$<termval>$->name = $<sval>1;
		$<termval>$->next=NULL;
		$<termval>$->mylist=NULL;
      printf("Variable->Term\n");
   }
   | FUNC OPENPAR TermL CLOSEPAR {
      $<termval>$ = (term_s*) malloc(sizeof(term_s));
		$<termval>$->name = $<sval>1;
		$<termval>$->next=NULL;
		$<termval>$->mylist = $<tlistval>3;
      printf("Funktiom(TermListe)->Term\n");
   }
   | FUNC {
      $<termval>$ = (term_s*) malloc(sizeof(term_s));
		$<termval>$->name = $<sval>1;
		$<termval>$->next=NULL;
		$<termval>$->mylist=NULL;
      printf("Funktion->Term\n");
   };

TermL:
   Term KOMMA TermL {
      $<termval>1->next = $<tlistval>3->first;
      $<tlistval>3->first= $<termval>1;
      $<tlistval>$ = $<tlistval>3;
      printf("Term,TermListe->TermListe\n");
   }
   | Term {
      $<tlistval>$ = (term_list_s*) malloc(sizeof(term_list_s));
	   $<tlistval>$->first = $<termval>1;
      printf("Term->TermListe\n");
   };

%%

   /* void printTermList(term_list_s* tl, int tabs){
   	term_s* myt = tl->first;
   	while(myt != NULL){
   		printTerm(myt,tabs,0);
   		myt = myt->next;
   	}
   }

   void printAtomList(atom_list_s* al, int tabs){
   	atom_s* mya = al->first;
   	while(mya != NULL){
   		printAtom(mya,tabs,0);
   		mya = mya->next;
   	}
   }
   void printAtom(atom_s* a, int tabs, int next){
   	printTabs(tabs-1);
   	printChar('+');
   	printTabs(tabs);
   	printf("ATOM\n");
   	printTabs(tabs-1);
   	printChar('+');
   	printTabs(tabs);
   	printf("Name: %s\n",a->name);
   	printTabs(tabs);
   	printf("Next: ");
   	if(a->next == NULL){
   		printf("NULL\n");
   	}
   	else{
   		printf("%s\n",a->next->name);
   		if(next>0){
   			printTabs(tabs-1);
   			printChar('-');
   			printAtom(a->next,tabs,next);
   		}
   	}
   	if(next<=0){
   		printTabs(tabs);
   		printf("Termliste: ");
   		if(a->mylist == NULL){
   			printf("NULL\n");
   		}
   		else{
   			printf("\n");
   			printTermList(a->mylist,tabs+1);
   		}
   	}
   }

   void printTerm(term_s* t, int tabs, int next){
   	printTabs(tabs-1);
   	printChar('=');
   	printTabs(tabs);
   	printf("TERM\n");
   	printTabs(tabs-1);
   	printChar('=');
   	printTabs(tabs);
   	printf("Name: %s\n",t->name);
   	printTabs(tabs);
   	printf("Next: ");
   	if(t->next == NULL){
   		printf("NULL\n");
   	}
   	else{
   		printf("%s\n",t->next->name);
   		if(next>0){
   			printTabs(tabs);
   			printChar('-');
   			printTerm(t->next,tabs,next);
   		}
   	}
   	if(next<=0){
   		printTabs(tabs);
   		printf("Termliste: ");
   		if(t->mylist == NULL){
   			printf("NULL\n");
   		}
   		else{
   			printf("\n");
   			printTermList(t->mylist,tabs+1);
   		}
   	}
   }

   void printTabs(int tabs){
   	tabs = (tabs>=0?tabs:0);
   	for(int i=0;i<tabs;i++){
   		printf("\t");
   	}
   }

   void printChar(char c){
   	for(int i=0;i<50;i++){
   		printf("%c",c);
   	}
   	printf("\n");
   } */



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
