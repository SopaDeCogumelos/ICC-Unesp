/*
 *	Arquivo fonte principal
 *
*/

/*	BEGIN Includes da Biblioteca Padrao */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*	END Includes da Biblioteca Padrao */

/*	BEGIN Includes das minhas bibliotecas */
#include "esc_csi_codes.h"
/*	END Includes das minhas bibliotecas */

/*	BEGIN Definine Lightweight getch() */ 
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#define GETCH _getch
#else
#include <termios.h>
#include <unistd.h>
char GETCH(void) {
    struct termios oldTerminal, newTerminal;
    char ch;
    tcgetattr(STDIN_FILENO, &oldTerminal);
    newTerminal = oldTerminal;
    newTerminal.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newTerminal);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldTerminal);
    return ch;
}
#endif
/*	END Definine Lightweight getch() */ 

/*	BEGIN main() */
int main(void) {
	
	// Muda a localização para pt-BR
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    if (setlocale(LC_CTYPE, "pt-BR") == NULL) {
        fprintf(stderr, "Falha ao definir locale pt-BR\n");
    }
    #else
    if (setlocale(LC_CTYPE, "pt_BR.UTF-8") == NULL) {
        fprintf(stderr, "Falha ao definir locale pt_BR.UTF-8\n");
    }
    #endif
	
	char 	option,
			scan_result;
	
	/* BEGIN main loop */
	while (1){		
		option = 0;
		scan_result = 0;
		
		printf(eraseDisplay);
		ANSI_CURSOR_POS(1, 1);
		printf(
			FG_BLUE	"==============================" "\n"	RESET
					" Digite o número do exercicio " "\n"
			FG_BLUE	"==============================" "\n"	RESET
					"--> "	
		);
		
		fflush(stdout);
		scan_result = scanf("%hhd", &option);
		
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
            while (getchar() != '\n' && getchar() != EOF);	//Limpar buffer
        } else {
            printf(eraseDisplay);
            
            if (option == 0) {
                printf("Saindo do programa...\n");
                break;
            }
            if (option == 1)	ex1();
            
            ANSI_CURSOR_POS(5, 1);
            printf(FG_RED "Opção inválida: %d\n" RESET, option);
        }
		
		ANSI_CURSOR_POS(7, 1);
		printf("Pressione qualquer tecla para continuar...\n");
		fflush(stdout);
		GETCH();
		option = 0;
	}
	/*	END main loop */
	
	return 0;
}
/*	END main() */
