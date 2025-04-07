#ifndef PROG3_C
#define PROG3_C

#include "prog3.h"

int prog3main(void){
	int idade;
	char nome[20];
	printf("Digite seu nome:\n");
	scanf("%s", &nome);
	printf("Digite sua idade: \n");
	scanf("%d", &idade);
	printf("Seu nome eh %s e sua idade eh %d\n", nome, idade);
	return 0;
}

#endif
