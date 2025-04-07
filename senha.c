#ifndef SENHA_C
#define SENHA_C

#include "senha.h"

int senhaMain(void){
	const char senhaV[] = "229";
	char	senha[3];
	int	tentativa = 3;
	
	while (tentativa > 0){	
		printf("Digite sua senha:\n");
		scanf("%s", &senha);
		if (senha[0] == senhaV[0] && senha[1] == senhaV[1] && senha[2] == senhaV[2]) break;
		if (senha[0] != senhaV[0] || senha[1] != senhaV[1] || senha[2] != senhaV[2]){
			tentativa--;
			printf("Senha inválida! Restam %d tentativas.\n", tentativa);
		}
	}
	
	if (tentativa > 0){
		printf("Login efetuado com sucesso.\n");		
	}
	if (tentativa < 1){
		printf("Muitas tentativas incorretas!\n");
		return 1;
	}
	
	return 1;
}

#endif
