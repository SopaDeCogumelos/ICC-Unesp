/*
 *	Arquivo fonte principal
*/

/*	BEGIN Includes da Biblioteca Padrao */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*	END Includes da Biblioteca Padrao */

/*	BEGIN Includes das minhas bibliotecas */
#include "esc_csi_codes.h"
#include "exercicio1.h"
/*	END Includes das minhas bibliotecas */

/*	BEGIN main() */
int main(void) {
	
	/*	BEGIN Localizacao pt-BR */
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
    /*	END Localizacao pt-BR */
	
	/*	BEGIN Variaveis main() */
	int 	option,
			scan_result;
	/* END Variaveis main() */
	
	/* BEGIN main loop */
	while (1){
	
		//Reset variaveis		
		option = 0;
		scan_result = 0;
		
		/*	BEGIN print menu */
		printf(eraseDisplay);
		ANSI_CURSOR_POS(1, 1);
		printf(
			FG_BLUE	"==============================" "\n"	RESET
					" Digite o número do exercicio " "\n"
			ITALIC	" (0 - Para sair)"				"\n"	RESET
			FG_BLUE	"==============================" "\n"	RESET
					"--> "	
		);
		/*	END print menu */
		
		fflush(stdout);
		scan_result = scanf("%d", &option);
		
		/*	BEGIN Testes do scanf */
		if (scan_result < 0) {
            ANSI_CURSOR_POS(5, 1);
            fprintf(stderr, FG_RED "ERRO: " RESET
                    "Não foi possível ler o valor inserido.\n"
                    "Finalizando o programa...\n");
            return EXIT_FAILURE;
        }
        if (scan_result == 0) {
            ANSI_CURSOR_POS(5, 1);
            fprintf(stderr, FG_RED "ERRO: " RESET "Valor inválido!\n");
            int ch;
			while ((ch = getchar()) != '\n' && ch != EOF);	//Limpar buffer
        } else {     	
			/* BEGIN Seletor do Menu */
            printf(eraseDisplay);
            
            if (option == 0) {
                printf("Saindo do programa...\n");
                break;
            } else if (option == 1){
            	exercicio1();
			} else {
	            ANSI_CURSOR_POS(5, 1);
	            printf(FG_RED "Opção inválida: %d\n" RESET, option);
	        }
            /* END Seletor do Menu */
        }
        /*	END Testes do scanf */
		
		printf("\nPressione qualquer tecla para continuar...\n");
		fflush(stdout);
		GETCH();
	}
	/*	END main loop */
	
	return 0;
}
/*	END main() */
