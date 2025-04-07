#ifndef STRINGCOMPARE_C
#define	STRINGCOMPARA_C

#include "stringCompare.h"

int stringCompare(void){
	char nome[2][20];
	int dLen = 0;
	printf("Digite dois nomes:\n");
	scanf("%s %s", &nome[0], &nome[1]);
	dLen = strcmp(nome[0],nome[1]);
	if (dLen == 0)
		printf("%s é igual a %s.\n",nome[0],nome[1]);
	else if (dLen < 0)
		printf("%s é menor de que %s.\n",nome[0],nome[1]);
	else if (dLen > 0)
		printf("%s é menor de que %s.\n",nome[0],nome[1]);
	
	return 0;
}

#endif
