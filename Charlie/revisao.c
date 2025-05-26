#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 


 {
 int num,maior,menor,pmaior,pmenor,cont=0,d,contd,contp;
 float produto,fatorial,k,soma,somaprimo,contprimo,mediaprimo;
 
 printf("\n escreva um numero \n");
 scanf("%d",&num);
 while(num>0)
 {
 
 	cont=cont+1;
 	if(cont==1)
 	{
 		maior=num;
 		menor=num;
 		pmaior=cont;
 		pmenor=cont;
	 }
        if (num>maior)
        {
        	maior=num;
        	pmaior=cont;
	}
        if (num<menor)
        { 
           menor=num;
           pmenor=cont;
	}
    scanf("%d",&num);
    
    }
    	printf("\n maior= %d \n", maior);
    	printf("\n menor= %d \n", menor );
    	printf("\n pmaior= %d \n", pmaior);
    	printf("\n pmenor=%d \n", pmenor);
    
    // fatorial do menor numero
    produto=1;
    for (k=1;k<=menor;k=k+1)
    {
    	produto=produto*k;
    }
    fatorial=produto;
    printf("\n o fatorial do menor numero eh %f\n",fatorial);
    // a soma dos divisores do maior numero
    soma=0;
    contd=0;
    for(d=1;d<=maior;d=d+1);
    {
    	if(maior%d==0)
    	{
	    
    	printf("\n d eh divisor de maior \n");
    	soma=soma+d;
    	contd=contd+1;
    }   }


    
    
    printf("\n a soma dos divisores de maior eh,soma\n");
    printf("\n maior,tem,contd,divisores \n");
    
    // media dos numeros primos
    contp=0;
    for(d=1;d<=maior;d=d+1);
    {
    	if(num%d==0)
    	{ contp=contp+1;
    	
	}
	    
    
    
    
    
    }
    
    
	if(contprimo==2)
	{
	  somaprimo=somaprimo+1;
	  contprimo=contprimo+1;
	
	}
	if(contprimo!=0)
	{ 
	   mediaprimo=somaprimo/contprimo;
	   printf("a media dos numeros primos %f,mediaprimo);
	   
	}
	else
	{ 
	  printf(" nao foi digitado nenhum numero primo");
	}
	return 0; 
	
}  


	

