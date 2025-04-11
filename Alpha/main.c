#include "main.h"

int modoLSD(void){
	while (1){
		for (int i=0; i < 256; i++)
			printf(BG"%dm\n", i);
	}
	printf(RESET LIMPA);
	return 0;
}

/* Menu principal de Sel��o de programas */
int main(void) {
	/* Define variaveis de Debug	
	*	i8_errorHandleVar 	-> variavel que recebe o return das chamadas de fun��o
	*	p_i8_errorHandleVar	-> mesmo de error, porem para ponteiros
	*	i8_userInput	-> variavel para sele��o de programa
	*/
	uint8_t 	ui8_errorHandle 		= 0;
	uint8_t* 	p_ui8_errorHandle 	= &ui8_errorHandle;
	uint8_t 	i8_userInput 			= 0;
	
	/* Define idioma escrito para PT-Br */
	setlocale(LC_CTYPE, "");
	
	while(1){
		printf(	
		CAZUL	"===================================================="	"\n"	
		CBRAN	"        Selecione o programa a ser executado"			"\n"
		CAZUL	"===================================================="	"\n"
		CBRAN	" 1- helloWorld - 	Printa Hello World!"				"\n"
				" 2- Prog2 - 		Printa exemplos de variaveis"		"\n"
				" 3- Prog3 - 		L� nome e idade e printa"			"\n"
				" 4- Prog4 - 		Nulo Positivo Negativo"				"\n"
				" 5- Prog5 - 		Calcula f(x)"						"\n"
				" 6- Prog6 - 		Maior ou menor de idade"			"\n"
				" 7- Senha - 		Testa input de senha"				"\n"
				" 8- M�dia - 		Calcula m�dia de 3 n�meros"			"\n"
				" 9- Compara String - 	Compara o tamanho de strings"	"\n"
				" 10-Tarefas - 		Bloco de Tarefas"					"\n"
				" 11-M�dia de n�meros Positivos"						"\n"
				" 12-Imprime uma sequ�cia a partir de N"				"\n"
				" 13-Modo LSD"											"\n"
				" 0-Exit"												"\n"
		CAZUL	"===================================================="	"\n"
		RESET);
		
		ui8_errorHandle = scanf("%d",&i8_userInput);
		printf(LIMPA);
		
		if (i8_userInput == 0) 		exit(0);
		if (i8_userInput == 1) 		ui8_errorHandle = mainHelloWorld();
		if (i8_userInput == 2) 		ui8_errorHandle = prog2main();
		if (i8_userInput == 3) 		ui8_errorHandle = prog3main();
		if (i8_userInput == 4) 		ui8_errorHandle = prog4main();
		if (i8_userInput == 5) 		ui8_errorHandle = prog5main();
		if (i8_userInput == 6) 		ui8_errorHandle = prog6main();
		if (i8_userInput == 7) 		ui8_errorHandle = senhaMain();
		if (i8_userInput == 8) 		ui8_errorHandle = med10main();
		if (i8_userInput == 9) 		ui8_errorHandle = stringCompare();
		if (i8_userInput == 10) 	ui8_errorHandle = tarefasMain();
		if (i8_userInput == 11) 	ui8_errorHandle = mediaLoopMain();
		if (i8_userInput == 12) 	ui8_errorHandle = sequenciaN();
		if (i8_userInput == 13) 	ui8_errorHandle = modoLSD();

		printf("\nPressione qualquer tecla para continuar...\n");
		p_ui8_errorHandle = gets(&i8_userInput);
		printf(LIMPA);
	}
	
	return 0;
}
