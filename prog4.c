#ifndef PROG4_C
#define PROG4_C

#include "prog4.h"


int prog4main(void){
	float		inputV;
	int		error;	
	
	printf("Digite um número qualquer:\n");
	error =  scanf("%f", &inputV);
	if (inputV == 0)
		printf("%f é nulo.\n", inputV);
	else if (inputV < 0)
		printf("%f é negativo.\n", inputV);
	else if (inputV > 0)
		printf("%f é positivo.\n", inputV);

	return 0;
}

#endif
