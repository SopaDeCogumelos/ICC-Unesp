#ifndef PROG4_C
#define PROG4_C

#include "prog4.h"


int prog4main(void){
	float		inputV;
	int		error;	
	
	printf("Digite um n�mero qualquer:\n");
	error =  scanf("%f", &inputV);
	if (inputV == 0)
		printf("%f � nulo.\n", inputV);
	else if (inputV < 0)
		printf("%f � negativo.\n", inputV);
	else if (inputV > 0)
		printf("%f � positivo.\n", inputV);

	return 0;
}

#endif
