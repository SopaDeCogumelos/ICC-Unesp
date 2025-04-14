/* trabalhoICC.c
*	Trabalho 1 ICC
*
* Autores:	Luis Felipe Marcon Brunhara
*		Luiz Felipe Moura Tarifa
*
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(void) {
	
	setlocale(LC_CTYPE, "");
	
	int 	countpar=0, count23=0, x=0;
	float 	sumpar=0;
	
	printf("Insira uma sequência de números positivos:\n");
	while (x >= 0){
		scanf("%d",&x);
		if(!(x%2)){
			countpar++;
			sumpar += x;	
		}
		
		if(x%2==0 && x%3==0){
			count23++;
		}
		
		if(x>=100 && x<1000){
			printf(	
				"\e[1F""A raiz quinta de %d é %.2f\n" 
				, x, pow((float)x,1.0/5.0)
			);
		}	
	}
	
	printf("\nA média dos pares é: %.2f\n", sumpar/(float)countpar);
	printf("A quantidade de números múltiplos, simultaneamente, de 2 e 3 é: %d", count23);
	
	return 0;
}
