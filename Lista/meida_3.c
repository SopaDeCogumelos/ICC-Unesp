#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
/*	float A,B,C,media; // declaração das variáveis: Reais
	printf("\n digite tres valores: \n");
	scanf("%f%f%f" ,&A,&B,&C);   // LEITURA DE DADOS
	media=(A+B+C)/3;  //OPERAÇÃO
	printf("\n A=%f, B=%f, C=%f, media=%f \n", A,B,C,media);
*/	
        float x,y,z;
        x=31%4;
        printf("\n x=%f",x);
        y=round(4.5);
        printf("\n y=%f", y);
        z=trunc(2.6)-2*x;
        printf("\n z=%f",z);
        printf("\n x=%f y=%f z=%f \n", x,y,z);
	return 0;
}

