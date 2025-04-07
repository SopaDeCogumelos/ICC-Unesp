#ifndef MED10_C
#define MED10_C

#include "med10.h"

int med10main(){
	int	num[3];
	printf("Digite 3 n�meros de 0 a 10:\n");
	for (int i = 0; i < 3; i++) {
		scanf("%d", &num[i]);
		if(num[i]<0 || num[i]>10){
			printf("N�mero inv�lido!\n");
			return 0;
		}
	}
	printf ("A m�dia de %d, %d e %d � %f\n", num[0], num[1], num[2], (num[0]+num[1]+num[2])/3.0);
	return 0;
}

#endif
