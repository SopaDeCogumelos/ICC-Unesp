#include <stdio.h>
#include <stdlib.h>
#include <math.h>




int main()
{
float valor, preco, troco;
printf("\n informe um valor: \n");
scanf("%f", &valor);
printf("\n informe o preco: \n");
scanf("%f", &preco);
  if(valor>preco)
  {
  	troco= valor-preco;
  	printf("o troco eh:%f", troco);
  }
    else if(valor<preco)
    {
    	printf("o valor eh insuficiente \n");
    }



	return 0;
}
