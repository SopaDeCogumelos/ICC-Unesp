#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	 int x[11][11], i, j, l , c, cont=0,contp=0, soma=0, par[11][11], impar[11][11];
	 printf ("\ndigite as dimensoes da matriz\n");
	 scanf ("%d%d", &l, &c);
	 printf ("\n digite os elementos da matriz\n");
	 for (i=1; i<=l; i=i+1)
	 {
	      for (j=1; j<=c; j=j+1)
	 	{
	 		scanf("%d",&x[i][j]);
		}
	 	
	 }
	 printf("\n a matriz lida eh' \n \n");
	 for (i=1; i<=l; i=i+1)
	 { 
	        for (j=1; j<=c; j=j+1)
	        {
	            	printf ("%d \t",x[i][j]);
		}
		printf("\n");
	 }
	 for (i=1; i<=l; i=i+1)
	 {
	 	for (j=1; j<=c; j=j+1)
	 	{
	 		soma=soma+x[i][j];
	 		if (x[i][j]%2==0)
	 		{
	 			contp=contp+1;
	 			par[i][j]=x[i][j];
	 			else 
	 			{
				 
	 				cont=cont+1;
	 				impar[cont]=x[i][j];
			        }
			 }
		 }
	 }
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
