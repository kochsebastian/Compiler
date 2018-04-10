logic: 
	bison -d logicBison.y
	flex-t logikFlex.l > logicFlex.c
	gcc -c -o logicFlex.o logicFlex.c
	gcc -c -o logicBison.tab.o logicBison.tab.c
	gcc logicFlex.o logicBison.tab.o -o logic
