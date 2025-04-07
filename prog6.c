#ifndef PROG6_C
#define PROG6_C

#include "prog6.h"

int prog6main(void){
	struct pessoa{
		char 	nome[20];
		int	idade;
	}pessoa;
	
	printf("Digite seu nome:\n");
	scanf("%s", &pessoa.nome);
	printf("Digite sua idade:\n");
	scanf("%d", &pessoa.idade);
	
	if (pessoa.idade < 18)
		printf("%s é menor de idade.\n", pessoa.nome, pessoa.idade);
	else
		printf("%s é maior de idade.\n", pessoa.nome, pessoa.idade);
}

#endif
