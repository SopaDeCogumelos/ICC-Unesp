#include <stdio.h>
#include <stdlib.h>


// Reorganizei toda a formatação do código para ficar mais legivel
int main()
{
	/* BEGIN Variaveis main */
	// Removi uma krlhada de variavel inutel
	int 	a[10][10], r[10][10], b[10][10],
			i, j, k,
			la, ca,
			lb, cb;
	/* END Variaveis main */
	
	// TODOS OS INDICES ESTAO ERRADOS DENTRO DOS FORs!
	// Os indices devem começar em 0 e terminar em n-1, era possivel indexar posicoes inexistentes
	
	/* BEGIN ler matriz A */
	printf("Digite as dimensoes de A:\n");
	scanf("%d%d",&la,&ca);
	
	printf("Digite os elementos da matriz A: \n");
	for(i = 0; i < la; i++){
		printf("Linha %d: \n", i+1);
		for(j = 0; j < ca; j++){
			scanf("%d", &a[i][j]);
		}
	}
	/* END ler matriz A */
	
	/* BEGIN ler B */
	printf("Digite as dimensoes de B:\n");
	scanf("%d%d",&lb,&cb);
	
	printf("Digite os elementos da matriz B: \n");
	for(i = 0; i < lb; i++){
		printf("Linha %d: \n", i+1);
		for(j = 0; j < cb; j++){
			scanf("%d", &b[i][j]);
		}
	}
	/* END ler B */
	
	/* BEGIN print A */
	printf("\n A matriz A: \n");
	for(i = 0; i < la; i++){
		for(j = 0; j < ca; j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	/* END print A */
	
	/* BEGIN print B */
	printf("\n A matriz B: \n");
	for(i = 0; i < lb; i++){
		for(j = 0; j < cb; j++){
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	/* END print B */
	
	// Faltava comferir se "ca = lb" antes de iniciar multiplicacao
	/* Verifica se a multiplicacao eh possivel */
    if (ca != lb) {
        printf("Erro: Dimensoes invalidas para multiplicacao!\n");
        return 1;
    }
	
	/* BEGIN Multiplicacao de vetor */
	for(i = 0; i < la; i++){
		// O Primeiro argumento do FOR era "i" invés de "j"
		// Faltava o "j" dentro do 2o argumento do for
		// Variavel Soma é desnecessaria
		for(j = 0; j < cb; j++){
			r[i][j] = 0;
			for(k = 0; k < ca; k++){
				r[i][j] += a[i][k] * b[k][j];
			}
			printf("%d\t", r[i][j]);
		}
		printf("\n");
	}
	/* END Multiplicacao de vetor */
}
