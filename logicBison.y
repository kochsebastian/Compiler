

%{
   #include <stdio.h>
//test
   	extern int yyerror(char *error);
   	extern int yylex(void);
   	extern FILE *yyin;

%}

%code requires{	//Alle folgenden Zeilen werden ins
   //Typedef der Structs vor der konkreten Implementation aufgrund von rekursiven Abhaengigkeiten
	//Benoetigte Structs: Term, Atom und Formel.
	typedef struct term term;
	typedef struct atom atom;
	typedef struct formula formula;
	//Zusaetzlich werden extra Structs fuer die Startzeiger angelegt, um die Uebersichtlichkeit zu bewahren
	typedef struct term_list term_list;
	typedef struct atom_list atom_list;
	typedef struct formula_list formula_list;

   enum {atom, ...}
	struct term{
		char* name;			//Name
		term_list* mylist;	//Eigene Termliste (Bei keiner Verwendung NULL)
		term* next;			//Naechstes Element, falls es sich in einer Liste befindet
	};

	struct atom{
		char* name;			//Siehe Term
		term_list* mylist;
		atom* next;
	};

	struct formula{
		enum type;

      char* string;

      term_list* mylist;

      formula Notsubformel;

      formula linkeformel;
      formula rechteformel;

      char* var;
      formula Quantsubformel;

      char* boolsch;
	};

	struct term_list{
		term* first;		//Startknoten der Liste
	};

	struct atom_list{
		atom* first;
	};

	struct formula_list{
		formula* first;
	};

};



%union {
  char* sval;

  term* termval;
  atom* atomval;
  formula* formval;
  term_list* tlistval;
  atom_list* alistval;
  formula_list* flistval;

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
      $<formelval>$ = (formel*)malloc(sizeof(formel));
      $<formelval>$->type = atom;

      printf("Atom->Formel\n");}
      | TOPI {printf("True->Formel\n");}
      | BOTTOMI {printf("False->Formel\n");}
      | NOT Formel {printf("Not Formel->Formel\n");}
      | OPENPAR Formel CLOSEPAR {printf("(Formel)->Formel\n");}
      | Formel AND Formel {printf("FormelandFormel->Formel\n");}
      | Formel OR Formel {printf("FormelorFormel->Formel\n");}
      | Formel PFEIL Formel {printf("FormelimplFormel->Formel\n");}
      | Formel DOPPELPFEIL Formel {printf("FormeleqFormel->Formel\n");}
      | ALLI VAR Formel {printf("AllVarFormel->Formel\n");}
      | EXI VAR Formel {printf("ExVarFormel->Formel\n");};



Atom:
   PRAE OPENPAR TermL CLOSEPAR {
      $<atomval>$ = (atom*)malloc(sizeof(atom));
      $<atomval>$->name = $<sval>1;
      $<atomval>$->mylist = $<tlistval>3;
      printf("Praedikat(TermListe)->Atom\n");
   };

Term:
   VAR {
      $<termval>$ = (term*)malloc(sizeof(term));
		$<termval>$->name = $<sval>1;
		$<termval>$->next=NULL;
		$<termval>$->mylist=NULL;
      printf("Variable->Term\n");
   }
   | FUNC OPENPAR TermL CLOSEPAR {
      $<termval>$ = (term*)malloc(sizeof(term));
		$<termval>$->name = $<sval>1;
		$<termval>$->next=NULL;
		$<termval>$->mylist = $<tlistval>3;
      printf("Funktiom(TermListe)->Term\n");
   }
   | FUNC {
      $<termval>$ = (term*)malloc(sizeof(term));
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
      $<tlistval>$ = (term_list*)malloc(sizeof(term_list));
	   $<tlistval>$->first = $<termval>1;
      printf("Term->TermListe\n");
   };

%%

   void printTermList(term_list* tl, int tabs){
   	term* myt = tl->first;
   	while(myt != NULL){
   		printTerm(myt,tabs,0);
   		myt = myt->next;
   	}
   }

   void printAtomList(atom_list* al, int tabs){
   	atom* mya = al->first;
   	while(mya != NULL){
   		printAtom(mya,tabs,0);
   		mya = mya->next;
   	}
   }
   void printAtom(atom* a, int tabs, int next){
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

   void printTerm(term* t, int tabs, int next){
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
