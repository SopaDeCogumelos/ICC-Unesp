/*
*	Charlie Main
*	Luis Felipe Marcon Brunhara
*/

/* BEGIN Includes Padr?o */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <stdint.h>
/* END Includes Padr?o */

/* BEGIN Includes User */
#include "vetor_matriz.h"
#include "esc_macros.h"
/* END Includes User */

/* BEGIN Typedefs */

/* END Typedefs */

/* BEGIN Functions */

/* END Functions */

/* BEGIN main */
int main(void) {
	/* BEGIN Localizacao pt-BR */
	#ifdef _WIN32
	if (setlocale(LC_CTYPE, "Portuguese_Brazil.1252") == NULL) {
		fprintf(stderr, "Falha ao definir locale Portuguese_Brazil.1252\n");
		return EXIT_FAILURE;
	}
	#else
	if (setlocale(LC_CTYPE, "pt_BR.UTF-8") == NULL) {
		fprintf(stderr, "Falha ao definir locale pt_BR.UTF-8\n");
		return EXIT_FAILURE;
	}
	#endif
	/* END Localizacao pt-BR */
	
	/* BEGIN Variaveis main */
	unsigned short int	menuIn;
	unsigned short int	returnVar;
	/* END Variaveis main */
	
	/* BEGIN main block 0 */
	char ch_buf;
	/* END main block 0 */
	
	/* BEGIN main loop */
	while (1){
		returnVar = 1;
			
		printf(eraseDisplay);
		printf(	" Selecione uma opção\n"
		FG_BLUE	"=====================\n"RESET
			"1 - Separar números pares do vetor\n"
			"2 - Notas e Média de 10 alunos\n"
			"3 - Organizar em ordem Crescente\n"
			"4 - Transporta matriz\n"
			"5 - Determinante de Matriz\n"
			"0 - Sair\n"
		FG_BLUE	"=====================\n"RESET
		);
		
		if (scanf("%hu", &menuIn) != 1) {
			printf("Entrada inválida!\n");
			while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);	//Limpar buffer
			printf("\nPressione qualquer tecla para continuar...\n");
			GETCH();
			continue;
		}
		
		printf(eraseDisplay);
		
		if (menuIn == 0) return 0; // Saída limpa
		if (menuIn == 1) {
			returnVar = parNoVetor();
			if (returnVar != 0) {
				printf("Erro ao processar números pares!\n");
			}
		} 
		if (menuIn == 2) {
			returnVar = notasMedia();
			if (returnVar != 0) {
				printf("Erro ao processar a notas!\n");
			}
		}
		if (menuIn == 3) {
			returnVar = organizeCrescente();
			if (returnVar != 0) {
				printf("Erro ao executar organizar crescente!\n");
			}
		}
		if (menuIn == 4) {
			returnVar = ler_matriz_op();
			if (returnVar != 0) {
				printf("Erro ao executar organizar crescente!\n");
			}
		}
		if (menuIn == 5) {
			returnVar = det_matriz();
			if (returnVar != 0) {
				printf("Erro ao executar organizar crescente!\n");
			}
		}
		if (menuIn > 5) {
			printf("Opção inválida!\n");
		}
		
		printf("\nPressione qualquer tecla para continuar...\n");
		GETCH();
	}	
	/* END main loop*/
	
	/* BEGIN main block 1 */
	
	/* END main block 1 */
    	
	return 0;
}
/* END main */
