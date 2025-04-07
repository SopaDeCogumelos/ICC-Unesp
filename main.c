#include "main.h"

/* Menu principal de Sel��o de programas */

int main(void) {
	/* Define variaveis de Debug	
	*	error 	-> variavel que recebe o return das chamadas de fun��o
	*	pError	-> mesmo de error, porem para ponteiros
	*	input	-> variavel para sele��o de programa
	*/
	uint8_t 	error 	= 0;
	uint8_t* 	pError 	= &error;
	uint8_t 	input 	= 0;
	
	/* Define idioma escrito para PT-Br */
	setlocale(LC_CTYPE, "");
	
	while(1){
		printf(	
		CAZUL	"===================================================="	"\n"	
		CBRAN	"        Selecione o programa a ser executado"		"\n"
		CAZUL	"===================================================="	"\n"
		CBRAN	" 1- helloWorld - 	Printa Hello World!"		"\n"
			" 2- Prog2 - 		Printa exemplos de variaveis"	"\n"
			" 3- Prog3 - 		L� nome e idade e printa"	"\n"
			" 4- Prog4 - 		Nulo Positivo Negativo"		"\n"
			" 5- Prog5 - 		Calcula f(x)"			"\n"
			" 6- Prog6 - 		Maior ou menor de idade"	"\n"
			" 7- Senha - 		Testa input de senha"		"\n"
			" 8- M�dia - 		Calcula m�dia de 3 n�meros"	"\n"
			" 9- Compara String - 	Compara o tamanho de strings"	"\n"
			" 10-Tarefas - 		Bloco de Tarefas"		"\n"
			" 0-Exit"						"\n"
		CAZUL	"===================================================="	"\n"
		RESET);
		
		//printf("Debug: error = %d pError = %d->%d\n", error, pError, *pError);
		
		error = scanf("%d",&input);
		printf(LIMPA);
		
		if (input == 0) exit(0);
		if (input == 1) error = mainHelloWorld();
		if (input == 2) error = prog2main();
		if (input == 3) error = prog3main();
		if (input == 4) error = prog4main();
		if (input == 5) error = prog5main();
		if (input == 6) error = prog6main();
		if (input == 7) error = senhaMain();
		if (input == 8) error = med10main();
		if (input == 9) error = stringCompare();
		if (input == 10) error = tarefasMain();

		printf("\nPressione qualquer tecla para continuar...\n");
		pError = gets(&input); pError = gets(&input);
		printf(LIMPA);
	}
	
	return 0;
}
