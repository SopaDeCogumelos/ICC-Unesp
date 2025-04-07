#ifndef	TAREFAS_C
#define	TAREFAS_C

#include "tarefas.h"

int tarefasMain(void){
	char select;
	while(1){
		printf(	
		CAZUL	"===================================================="	"\n"	
		CBRAN	"        Selecione a tarefa a ser executada"		"\n"
		CAZUL	"===================================================="	"\n"
		CBRAN	" A- Tarefa 1 - 	Printa Hello World!"		"\n"
			" B- Tarefa 2 - 	Printa exemplos de variaveis"	"\n"
			" C- Tarefa 3 - 	Lê nome e idade e printa"	"\n"
			" D- Tarefa 4 - 	Nulo Positivo Negativo"		"\n"
			" E- Tarefa 5 - 	Calcula f(x)"			"\n"
			" 0- Voltar para menu anterior"				"\n"
		CAZUL	"===================================================="	"\n"
		RESET);
		
		scanf("%s", &select);
		if(strcmp(&select, "0") == 0) return 0;
		if(strcmp(&select, "A") == 0) return 0;
		if(strcmp(&select, "B") == 0) return 0;
		if(strcmp(&select, "C") == 0) return 0;
		if(strcmp(&select, "D") == 0) return 0;
		if(strcmp(&select, "E") == 0) return 0;
		
		printf("\nPressione qualquer tecla para continuar...\n");
		gets(&select); gets(&select);
		printf(LIMPA);
	}
	
	return 0;
}

#endif
