#include "exercicio1.h"

typedef struct Scan{
	int value;
	int	result;
} scan_t;

int exercicio1(void) {
    scan_t scan = {0, 0};
    
    printf(eraseDisplay);
	printf("Digite um n�mero inteiro positivo:\n");

    while (scan.value <= 0) {  	    
		ANSI_CURSOR_POS(2, 1);
        printf(eraseLine); // Clear previous input
        fflush(stdout);

        scan.result = scanf("%d", &scan.value);

        if (scan.result < 0) {
            ANSI_CURSOR_POS(3, 1);
            printf(eraseLine);
            fprintf(stderr, FG_RED "ERRO: N�o foi poss�vel ler o valor inserido.\n" RESET);
            fflush(stdout);
            return 1; // Signal EOF error to main
        }
        if (scan.result == 0) {
            ANSI_CURSOR_POS(3, 1);
            printf(eraseLine);
            printf(FG_RED "ERRO: Entrada inv�lida! Digite um n�mero inteiro.\n" RESET);
            fflush(stdout);
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
        } else if (scan.value <= 0) {
            ANSI_CURSOR_POS(3, 1);
            printf(eraseLine);
            printf(FG_RED "ERRO: Digite um n�mero maior que 0!\n" RESET);
            fflush(stdout);
        }
    }

    ANSI_CURSOR_POS(3, 1);
    printf(eraseLine); 
    ANSI_CURSOR_POS(4, 1);
    printf("N�mero v�lido: %d\n", scan.value);
    
    return 0;
}
