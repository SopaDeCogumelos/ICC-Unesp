#ifndef SEQUENCIAN_C
#define SEQUENCIAN_C

#include "sequenciaN.h"

int sequenciaN(void){
	int numero;
	while (1){
		printf(LIMPA "Insira um número inteiro positivo:\n");
		scanf("%d", &numero);
		if (numero > 0) break;		
	}
	for (int i = 0; i < numero; i++)
		printf("%d\n",i+1);
	return 0;
}

#endif
