#ifndef MEDIALOOP_C
#define MEDIALOOP_C

#include "mediaLoop.h"

int mediaLoopMain(void){
	float	input = 0, 
		count = 0, 
		sum = 0;
	printf("Digite uma sequ�ncia de n�meros inteiros:\n");
	for(count;; count++){
		scanf("%f", &input);
		if (input < 0) break;
		sum += input;
	}
	if (count<=0){
		printf("Sequ�ncia Inv�lida!\n");
		return 0;
	}
	printf("A soma foi e %f a m�dia foi %f\n", sum, sum/count);
}

#endif
