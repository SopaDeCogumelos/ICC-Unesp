/*
*	PROVA 2
*	Luis Felipe Marcon Brunhara
*	Leonardo Seiji Onohara
*/

/* BEGIN Includes Padr?o */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
/* END Includes Padr?o */

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
#define FG_BRIGHT_BLUE F	GC(12)
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

// Define Epsilon para calculo de 0 de float
#define EPSILON 1e-9
#define PI		3.14159265358979323846

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
typedef struct Vetor{
	int	s;
	double	v[20];
}vetor_t;

/*
*	Typedef Matriz_2x2
*		l 	-> linhas
*		c	-> colunas
*		v	-> valores da matriz
*		p	-> propriedades da matriz (bit flags)
*		{
*			p<<0	-> flag matriz quadrada
*			p<<1	-> flag quadrado magico
*		}
*				
*/
typedef struct Matriz_2d{
	int	l,
		c;
	double	v[10][10];
	int	p;
}matriz_2d_t;
/* END Typedefs */

/* BEGIN Global Vars */
char 	ch_buf;
/* END Global Vars*/

/* BEGIN Functions */

// Funcao de leitura de matriz
int read_matriz(matriz_2d_t* matriz){
	for (int i = 0; i < matriz->l; i++){
		printf("Insira %d valores reais para a linha %d\n", matriz->c, i+1);
		for (int j = 0; j < matriz->c; j++){
			if (scanf("%lf", &matriz->v[i][j]) != 1) {
				printf("Entrada inv?lida para coluna %d do linha %d!\n", j + 1, i + 1);
				// Limpa o buffer de entrada apos a falha do scanf
				while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);
				return 2; // C?digo de erro
			}	
		}
	}
	return 0;
}

void test_for_matriz_sq(matriz_2d_t* matriz){
	if (matriz->c == matriz->l)
		matriz->p = matriz->p | (1<<0);
	else
		matriz->p = matriz->p & (0<<0);
	return;
}

int bloco_1(matriz_2d_t* A, matriz_2d_t* B){
	B->c = A->c;
	B->l = A->l;
	
	for (int i = 0; i < A->l; i++){
		for (int j = 0; j < A->c; j++)
			B->v[i][j] = pow(A->v[i][j], (1.0/3.0));
	}
	printf("A matriz B é:\n");
	for (int i = 0; i < B->l; i++){
		for (int j = 0; j < B->c; j++)
			printf("%0.2lf\t", B->v[i][j]);
		printf("\n");
	}
	return 0;
}

int bloco_2(matriz_2d_t* A, vetor_t* V){
	if (!(A->p>>0) & (1<<0))
		return 1;
		
	V->s = 0;
	
	for (int i = 0; i < A->l; i++){
		if (A->v[i][i] > EPSILON){
			V->v[V->s] = A->v[i][i];
			V->s++;
		}
		if (A->v[i][A->c - i - 1] > EPSILON){
			V->v[V->s] = A->v[i][A->c - i - 1];
			V->s++;
		}	
	}

	printf("O vetor V das diagonais de A é:\n");
	for (int i = 0; i < V->s; i++){
		printf("%0.2lf\t", V->v[i]);
	}

	return 0;
}

int bloco_3(matriz_2d_t* A, matriz_2d_t* C){
	C->c = A->c;
	C->l = A->l;
	
	for (int i = 0; i < A->l; i++){
		for (int j = 0; j < A->c; j++){
			double	val = (A->v[i][j]/180)*PI;
			C->v[i][j] = cos(val);
		}
	}
	printf("A matriz C é:\n");
	for (int i = 0; i < C->l; i++){
		for (int j = 0; j < C->c; j++)
			printf("%0.2lf\t", C->v[i][j]);
		printf("\n");
	}
	return 0;
}

int bloco_4(matriz_2d_t* A){
	if (!(A->p>>0) & (1<<0))
		return 1;
	
	unsigned char is_identidade = 1;
	
	for (int i = 0; i < A->l; i++){
		for (int j = 0; j < A->c; j++){
			if ((j = i) && (A->v[i][j]-1 > EPSILON)){
				is_identidade = 0;
				break;	
			} else if (A->v[i][j] > EPSILON){
				is_identidade = 0;
				break;	
			}
		}
		if (is_identidade == 0)
			break;
	}
	
	if (is_identidade == 0){
		printf("A matriz A não é uma matriz identidade!\n");
	} else {
		printf("A matriz A é uma matriz identidade!\n");
	}
	
	return 0;
}
/* END Functions */

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
	int	menuIn;
	int	returnVar;
	
	matriz_2d_t	matriz_A, matriz_B, matriz_C;
	vetor_t		vetor_d;
	/* END Variaveis main */
	
	printf("Insira a quantidade de linhas e colunas para a Matriz A, respectivamente (maximo 10):\n");
	if (scanf("%d%d", &matriz_A.l, &matriz_A.c) != 2) {
		printf("Entrada inválida!\n");
		while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);	//Limpar buffer
		printf("\nPressione qualquer tecla para continuar...\n");
		GETCH();
		return 0;
	}
	if ((matriz_A.l >= 10)||(matriz_A.l >= 10)){
		printf("Tamanho inválido!\n");
		printf("\nPressione qualquer tecla para continuar...\n");
		GETCH();
		return 0;	
	}
	read_matriz(&matriz_A);
	
	while (1){
		returnVar = 1;
		matriz_A.p = 0;
		matriz_B.p = 0;
		matriz_C.p = 0;
		printf(eraseDisplay);
		printf("A matriz A é:\n");
		for (int i = 0; i < matriz_A.l; i++){
			for (int j = 0; j < matriz_A.c; j++)
				printf("%0.2lf\t", matriz_A.v[i][j]);
			printf("\n");
		}
		test_for_matriz_sq(&matriz_A);
		
		printf(	" Selecione uma opção\n"
		FG_BLUE	"=====================\n"RESET
			"0 - Sair\n"
			"1 - Bloco 1\n"
			"2 - Bloco 2\n"
			"3 - Bloco 3\n"
			"4 - Bloco 4\n"
		FG_BLUE	"=====================\n"RESET
		);
		
		if (scanf("%d", &menuIn) != 1) {
			printf("Entrada inválida!\n");
			while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);	//Limpar buffer
			printf("\nPressione qualquer tecla para continuar...\n");
			GETCH();
			continue;
		}
		
		printf(eraseDisplay);
		
		if (menuIn == 0) return 0; // Saida limpa
		if (menuIn == 1) {
			returnVar = bloco_1(&matriz_A, &matriz_B);
			if (returnVar != 0) {
				printf("Erro ao processar Bloco 1!\n");
			}
		} 
		if (menuIn == 2) {
			returnVar = bloco_2(&matriz_A, &vetor_d);
			if (returnVar != 0) {
				printf("Erro ao processar Bloco 2!\n");
				if (returnVar = 1)
					printf("A matriz não é quadrada!\n");	
			}
		}
		if (menuIn == 3) {
			returnVar = bloco_3(&matriz_A,&matriz_C);
			if (returnVar != 0) {
				printf("Erro ao processar Bloco 3!\n");
			}
		}
		if (menuIn == 4) {
			returnVar = bloco_4(&matriz_A);
			if (returnVar != 0) {
				printf("Erro ao processar Bloco 4!\n");
				if (returnVar = 1)
					printf("A matriz não é quadrada!\n");
			}
		}
		if (menuIn > 4) {
			printf("Opção inválida!\n");
		}
		
		printf("\nPressione qualquer tecla para continuar...\n");
		GETCH();
	}	
	/* END main loop*/
    	
	return 0;
}
