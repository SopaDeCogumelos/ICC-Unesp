#ifndef PROG5_C
#define PROG5_C

#include "prog5.h"

int prog5main(void){
	float x, fx;
	
	printf("Insira o valor de x\n");
	scanf("%f", &x);
	
	if (x>=7)
		fx = 2.0 * x;
	else if(x>=-5 && x<7)
		fx = x + 10.0;
	else if(x<-5)
		fx = x - 5.0;
	
	printf("f(%f)=%f\n", x, fx);
}

#endif
