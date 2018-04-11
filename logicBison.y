

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

      formula_s* subformelNOT;

      formula_s* linkeformel;
      formula_s* rechteformel;

      formula_s* subformelQUANT;

      char* var;

      char* trueFalse;

      int brackets;

	};

	struct term_list_s{
		term_s* first;		//Startknoten der Liste
	};





   void printTermList(term_list_s* tl );

   void printFormula(formula_s* f, int aufruf);
   void transformNNF(formula_s* f);
   formula_s* createFormulaATOM(unsigned int pType, atom_s* pA); // fuer Atom
   formula_s* createFormulaBOOL(unsigned int pType, char* pTrueFalse); //
   formula_s* createFormulaNOT(unsigned int pType, char* pOperant, formula_s* pSubformelNOT);
   formula_s* createFormulaQUANT(unsigned int pType, char* pOperant, formula_s* pSubformelQUANT, char* pVar);
   formula_s* createFormulaBRACK(formula_s* pformel, int pBrackets);
   formula_s* createFormulaJUNKT(unsigned int pType, char* pOperant, formula_s* pLinkeformel, formula_s* pRechteformel);


   void printAtom(atom_s* a);
   void printTerm(term_s* t);


};




%union {
  char* sval;

  term_s* termval;
  atom_s* atomval;
  formula_s* formelval;
  term_list_s* tlistval;

  formula_s* nnf;
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
/*
 NNF:
    Formel {

      // transformNNF($<formelval>$);
         printFormula($<formelval>$,0);

};*/

Formel:
   Atom {
      $<formelval>$ = createFormulaATOM(atom, $<atomval>1);
      printf("Parser: Atom->Formel\n");
      printFormula($<formelval>$,0);
   }
   | TOPI {
      $<formelval>$ = createFormulaBOOL(top, $<sval>1);
      printf("Parser: True->Formel\n");
      printFormula($<formelval>$,0);

   }
   | BOTTOMI {
      $<formelval>$ = createFormulaBOOL(bottom, $<sval>1);
      printf("Parser: False->Formel\n");
      printFormula($<formelval>$,0);

   }
   | NOT Formel {
      $<formelval>$ = createFormulaNOT(not,$<sval>1,$<formelval>2);
      printf("Parser: Not Formel->Formel\n");
      printFormula($<formelval>$,0);

   }
   | OPENPAR Formel CLOSEPAR {
      $<formelval>$ = createFormulaBRACK($<formelval>2, 1);
      printf("Parser: (Formel)->Formel\n");
      printFormula($<formelval>$,0);

   }
   | Formel AND Formel {
      $<formelval>$ = createFormulaJUNKT(and,$<sval>2,$<formelval>1,$<formelval>3);
      printf("Parser: FormelandFormel->Formel\n");
      printFormula($<formelval>$,0);

   }
   | Formel OR Formel {
      $<formelval>$ = createFormulaJUNKT(or,$<sval>2,$<formelval>1,$<formelval>3);
      printf("Parser: FormelorFormel->Formel\n");
      printFormula($<formelval>$,0);

   }
   | Formel PFEIL Formel {
      $<formelval>$ = createFormulaJUNKT(impl,$<sval>2,$<formelval>1,$<formelval>3);
      printf("Parser: FormelimplFormel->Formel\n");
      printFormula($<formelval>$,0);

   }
   | Formel DOPPELPFEIL Formel {
      $<formelval>$ = createFormulaJUNKT(eql,$<sval>2,$<formelval>1,$<formelval>3);
      printf("Parser: FormeleqFormel->Formel\n");
      printFormula($<formelval>$,0);

   }
   | ALLI VAR Formel {
      $<formelval>$ = createFormulaQUANT(all,$<sval>1,$<formelval>3,$<sval>2);
      printf("Parser: AllVarFormel->Formel\n");
      printFormula($<formelval>$,0);

   }
   | EXI VAR Formel {
      $<formelval>$ = createFormulaQUANT(ex,$<sval>1,$<formelval>3,$<sval>2);
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


      printf("%s",a->name);
   	if(a->mylist == NULL){

   	}
   	else{
         printf("(");
   	   printTermList(a->mylist);
         printf(")");
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

   formula_s* createFormulaBOOL(unsigned int pType, char* pTrueFalse){
      formula_s* returnFormula = (formula_s*) malloc(sizeof(formula_s));
      returnFormula->type = pType;
      returnFormula->trueFalse = pTrueFalse;
      return returnFormula;
   }

   formula_s* createFormulaNOT(unsigned int pType, char* pOperant, formula_s* pSubformelNOT){
      formula_s* returnFormula = (formula_s*) malloc(sizeof(formula_s));
      returnFormula->type = pType;
      returnFormula->operant = pOperant;
      returnFormula->subformelNOT = pSubformelNOT;
      return returnFormula;
   }

   formula_s* createFormulaQUANT(unsigned int pType, char* pOperant, formula_s* pSubformelQUANT, char* pVar){
      formula_s* returnFormula = (formula_s*) malloc(sizeof(formula_s));
      returnFormula->type = pType;
      returnFormula->operant = pOperant;
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
   formula_s* createFormulaJUNKT(unsigned int pType, char* pOperant, formula_s* pLinkeformel, formula_s* pRechteformel){
      formula_s* returnFormula = (formula_s*) malloc(sizeof(formula_s));
      returnFormula->type = pType;
      returnFormula->operant = pOperant;
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

   /*void transformNNF(formula_s* f){
      formula_s* tmp1;
      formula_s* tmp2;
      switch(f->type){
         case atom:
            break;// do nothing
         case and:
            transformNNF(f->linkeformel);transformNNF(f->rechteformel);break;
         case or:
            transformNNF(f->linkeformel);transformNNF(f->rechteformel);break;
         case not:
            transformNNF(f->subformelNOT); break;
         case impl:

         /*   tmp1 = (formula_s*) malloc(sizeof(f->linkeformel));
            *(tmp1) = *(f->linkeformel);

            f->type = or;
            f->linkeformel->type = not;

            f->linkeformel->Notsubformel = (formula_s*) malloc(sizeof(tmp1));
            f->linkeformel->Notsubformel = tmp1;
            transformNNF(f->linkeformel);transformNNF(f->rechteformel); break; // kommentar beenden
            break;

         case eql:
            //tmp1 = (formula_s*) malloc(sizeof(f->linkeformel));
            //tmp2 = (formula_s*) malloc(sizeof(f->rechteformel));
            //*(tmp1) = *(f->linkeformel);
            //*(tmp2) = *(f->rechteformel);

            f->type = or;
            f->linkeformel->type = not;
            //f->linkeformel->brackets = 1;
         //   f->linkeformel->type = not;
         /*   f->linkeformel->linkeformel = (formula_s*) malloc(sizeof(tmp1));
            f->linkeformel->linkeformel = tmp1;
            f->linkeformel->rechteformel = (formula_s*) malloc(sizeof(tmp2));
            f->linkeformel->rechteformel = tmp2;

            //f->rechteformel->brackets = 1;
            f->rechteformel->type = and;
            f->rechteformel->linkeformel = (formula_s*) malloc(sizeof(tmp1));
            f->rechteformel->linkeformel = tmp1;
            f->rechteformel->rechteformel = (formula_s*) malloc(sizeof(tmp2));
            f->rechteformel->rechteformel = tmp2;

            transformNNF(f->linkeformel);transformNNF(f->rechteformel); // kommentar beenden
            break;

         case all: transformNNF(f->subformelQUANT); break;
         case ex: transformNNF(f->subformelQUANT);break;
         case top:break;
         case bottom:break;
         default: printf("ERROR in transformNNF");break;
      }
      //f->type = top; // test


   }*/




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
