#ifndef	PROG2_C
#define	PROG2_C

#include "prog2.h"

int prog2main(void){
	
	int n_int 	= 28;
	float n_float	= 13.5687;
	char v[10]	= "Texto";
	printf(
		"Valor caractere: %s\n"
		"Valor inteiro: %d\n"
		"Valor real: %7.4f\n",
		v, n_int, n_float
	);
	
	return 0;
}

#endif
