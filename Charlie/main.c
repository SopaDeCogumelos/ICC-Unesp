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
/* END Includes User */

/* BEGIN Macros do CSI */
#define CSI "\033["

/* Select Graphic Rendition */
#define SGR(n) 	CSI #n "m"
#define RESET 	SGR(0)
#define BOLD 	SGR(1)
#define ITALIC 	SGR(3)

/* 256 Color Codes */
#define FGC(c) 	SGR(38;5;c)
#define BGC(c) 	SGR(48;5;c)

/* 16 Color Palette */
#define FG_BLACK 		FGC(0)
#define FG_RED 			FGC(1)
#define FG_GREEN 		FGC(2)
#define FG_YELLOW 		FGC(3)
#define FG_BLUE 		FGC(4)
#define FG_MAGENTA 		FGC(5)
#define FG_CYAN 		FGC(6)
#define FG_WHITE 		FGC(7)
#define FG_BRIGHT_BLACK 	FGC(8)
#define FG_BRIGHT_RED 		FGC(9)
#define FG_BRIGHT_GREEN 	FGC(10)
#define FG_BRIGHT_YELLOW 	FGC(11)
#define FG_BRIGHT_BLUE 		FGC(12)
#define FG_BRIGHT_MAGENTA 	FGC(13)
#define FG_BRIGHT_CYAN 		FGC(14)
#define FG_BRIGHT_WHITE 	FGC(15)

#define BG_BLACK 		BGC(0)
#define BG_RED 			BGC(1)
#define BG_GREEN 		BGC(2)
#define BG_YELLOW 		BGC(3)
#define BG_BLUE 		BGC(4)
#define BG_MAGENTA 		BGC(5)
#define BG_CYAN 		BGC(6)
#define BG_WHITE 		BGC(7)
#define BG_BRIGHT_BLACK 	BGC(8)
#define BG_BRIGHT_RED 		BGC(9)
#define BG_BRIGHT_GREEN 	BGC(10)
#define BG_BRIGHT_YELLOW 	BGC(11)
#define BG_BRIGHT_BLUE 		BGC(12)
#define BG_BRIGHT_MAGENTA 	BGC(13)
#define BG_BRIGHT_CYAN 		BGC(14)
#define BG_BRIGHT_WHITE 	BGC(15)

/* Posicionamento de cursor */
#define ANSI_CURSOR_POS(l,c) printf(CSI "%d;%dH", l, c)

/* Controle de linha e tela */
#define eraseLine 	CSI "2K" 
#define eraseDisplay 	CSI "2J" CSI "H"
/* END Macros do CSI */

/* BEGIN Define Lightweight getch() */ 
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
/* END Define Lightweight getch() */ 

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
	
	/* END main block 0 */
	
	/* BEGIN main loop */
	while (1){
		returnVar = 1;
			
		printf(eraseDisplay);
		printf(	" Selecione uma opção\n"
		FG_BLUE	"=====================\n"RESET
			"1 - Separar números pares do vetor\n"
			"2 - Notas e Média de 10 alunos\n"
			"0 - Sair\n"
		);
		
		if (scanf("%hu", &menuIn) != 1) {
			printf("Entrada inválida!\n");
			while (getchar() != '\n'); // Limpa buffer
			printf("\nPressione qualquer tecla para continuar...\n");
			GETCH();
			continue;
		}
		while (getchar() != '\n'); // Limpa buffer
		
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
		if (menuIn > 2) {
			printf("Opção inválida!\n");
		}
		
		while (getchar() != '\n'); // Limpa buffer
		printf("\nPressione qualquer tecla para continuar...\n");
		GETCH();
	}	
	/* END main loop*/
	
	/* BEGIN main block 1 */
	
	/* END main block 1 */
    	
	return 0;
}
/* END main */
