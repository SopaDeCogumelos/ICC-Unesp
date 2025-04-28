#include<stdio.h>
#include<stdlib.h>

int main()
{
	float L1,L2,x;
	printf("este prograa calcula a area de um triangulo. \n\n");
	printf("digite um lado do triangulo:");
	scanf("%f", &L1);
	printf("digite o outro lado do triangulo:");
	scanf("%f", &L2);
	x=L1*L2/2;
	printf("o valor da area e: %f \n\n", x);
	
	system("pause");
	
	
}
