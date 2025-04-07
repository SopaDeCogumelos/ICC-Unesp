#ifndef	TAREFAS_C
#define	TAREFAS_C

#include "tarefas.h"

/*
*	Programa que executa as 5 tarefas pedidas em Aula
*	o programa possui 5 funcoes, uma por tarefa
*	a main() está no final.
*	O programa tambem inclui alguns macros.
*/

/* Funcao da Tarefa 1 */
int swapXY(void){
	/* 	As variaveis "x" e "y" sao para a leitura da entrada do usuario
	* 	"temp" eh uma variavel auxiliar para a inversao de x e y
	*/
	int x, y, temp;
	
	printf("Insira dois números inteiros:\n");
	scanf("%d %d", &x, &y);
	
	printf("Os valores inseridos foram x=%d e y=%d\n", x, y);
	
	/* INICIO da logica de inversao */
	temp = x;
	x = y;
	y = temp;
	/* FIM da logica de inversao */
	
	printf("Os valores após inversão são x=%d e y=%d\n", x, y);
	return 0;
}

/* Funcao da Tarefa 2 */
int sqrt5(void){
	float x;
	printf("Insira um número:\n");
	scanf("%f", &x);
	
	printf("A raiz quinta de %f ? %.2f\n", x, pow(x, 0.2));
	/* 			A raiz quinta a calculada aqui ^^^^^^ */
	
	return 0;
}

/* Funcao da Tarefa 3 */
int ydex(void){
	float x;
	printf("Insira um número:\n");
	scanf("%f", &x);
	
	/* Calculo da funcao y=(1)/(x+x^2) + (x^3)/(x^(1/3)) 
	*	calculo foi divido em dois termos, t1 e t2
	*/
	float t1 = 1.0/(x+pow(x,2.0));
	float t2 = pow(x, 8.0/3.0);
	
	printf("y=f(%.2f)=%.2f\n", x, t1 + t2);
	/* 							  ^^^^^^
	*	Soma t1 e t2 para obter resultado final, dentro do printf
	*/
	
	return 0;
}

/* Funcao da Tarefa 4 */
int orgOrdCres(void){
	/*
	*	Utilizo a matriz "x" para armazenar os n?meros
	*	x0 eh uma variavel auxiliar
	*/
	float x[3];
	float x0;
	
	printf("Insira 3 numeros:\n");
	
	/* Loop para ler os numeros e armazenar eles na matriz x */
	for (int i = 0; i < 3; i++){
		scanf("%f", &x[i]);
		//printf("%f\n", x[i]); //Debug
	}
	
	/* Exibe ao usuário a sequencia original */
	printf("A sequencia digitada foi:\n");
	for (int i = 0; i < 3; i++)
		printf("%f ", x[i]);
		
	/* INICIO Loop logico para reorganizar a sequencia numerica
	*	Esse metodo utiliza um loop dentro de outro loop e
	*	permite expansao da sequencia para tamanho infinito
	*/
	int len = sizeof(x)/sizeof(x[0]);
	for (int i = 0; i < len;i++){
		for (int j = 0; j < len; j++){
			if (x[i] < x[j]){
				x0 		= x[j];
				x[j] 	= x[i];
				x[i]	= x0;
			}
		}
	}
	/* FIM Loop lagico para reorganizar a sequencia numerica */
	
	/* Exibe ao usuario a sequencia reorganizada */
	printf("\n\nA sequencia re-organizada ?:\n");
	for (int i = 0; i < 3; i++)
		printf("%f ", x[i]);
	printf("\n");

	return 0;
}

/* Funcao da Tarefa 5 */
int ler3somaDig(void){
	/*	num -> string para armazenar os 3 digitos
	*	sum -> armazena a soma
	*/	
	char num[3];
	int	sum = 0;
	
	
	printf("Insira um numero de 3 digitos:\n");
	scanf("%s", &num);
	
	/* INICIO Logica para verificar se o n?mero digitado tem 3 digitos */
	if (strlen(num) != 3){
		printf("Numero invalido!\n");
		return 0;
	}
	/* FIM Logica para verificar se o n?mero digitado tem 3 digitos */
	
	/* INICIO Soma os digitos */
	for (int i = 0; i < 3; i++){
		/* Esse "if" serve para verificar se o numero digitado eh valido,
		*	ou seja, um numero inteiro com 3 digitos.
		*	O 48 e 57 que aparecem na logica s?o os valores dos characteres 
		*	0 e 9 na tabela ASCII. O 48 tb eh utilizado para converter char em int
		*/
		if (!(num[i]<48 || num[i]>57 ))
			sum += num[i]-48;
		else{
			printf("Número inválido!\n");
			return 0;
		}	
	}
	/* FIM Soma os digitos */
	
	printf("A soma dos digitos é %d", sum);
	
	return 0;
}

int tarefasMain(void){
	//Variavel para selecao das options do menu
	char select;
	
	/* INICIO do Loop do Menu 
	*	utiliza o while(1) para gerar loop infinito
	*/
	while(1){
		/* printa o menu utilizando macros para a formatacao de texto */
		printf(	
		CAZUL	"===================================================="	"\n"	
		CBRAN	"        Selecione a tarefa a ser executada"			"\n"
		CAZUL	"===================================================="	"\n"
		CBRAN	" A- Tarefa 1 - 	Trocar 2 números inteiros"			"\n"
			" B- Tarefa 2 - 	Calcula a raiz quinta"				"\n"
			" C- Tarefa 3 - 	Le x e retorna f(x)"				"\n"
			" D- Tarefa 4 - 	Organiza 3 valores"					"\n"
			" E- Tarefa 5 - 	Ler numero e somar digitos"			"\n"
			" 0- Voltar para menu anterior"									"\n"
		CAZUL	"===================================================="	"\n"
		RESET);
		
		/* Le o valor de entrada */
		scanf("%s", &select);
		
		/* INICIO do Seletor de opcoes do menu */
		if(strcmp(&select, "0") == 0) return 0;
		if(strcmp(&select, "A") == 0 || strcmp(&select, "a") == 0) swapXY();
		if(strcmp(&select, "B") == 0 || strcmp(&select, "b") == 0) sqrt5();
		if(strcmp(&select, "C") == 0 || strcmp(&select, "c") == 0) ydex();
		if(strcmp(&select, "D") == 0 || strcmp(&select, "d") == 0) orgOrdCres();
		if(strcmp(&select, "E") == 0 || strcmp(&select, "e") == 0) ler3somaDig();
		/* FIM do Seletor de opcoes do menu */
		
		/* Espera input do usuario antes de resetar o loop */
		printf("\nPressione qualquer tecla para continuar...\n");
		gets(&select); gets(&select);
		printf(LIMPA); // <-- Limpa a tela
	}
	/* FIM do Loop do Menu */
	
	return 0;
}

#endif
