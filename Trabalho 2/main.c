/*
*	Trabalho 2
*	Luis Felipe Marcon Brunhara
*	
*/

/* BEGIN Std Includes */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <stdint.h>
/* END Std Includes */

/* BEGIN User Includes */

/* END User Includes */

/* BEGIN Macros */
#define EPSILON 1e-9

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

/* END Macros */

/* BEGIN Typedefs */
typedef struct Vetor{
	int	s;
	int	v[];
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
typedef struct Matriz_2x2{
	int	l,
		c;
	double	v[10][10];
	int	p;
}matriz_2x2_t;
/* END Typedefs */

/* BEGIN Global Vars */
char 	ch_buf;
/* END Global Vars*/

/* BEGIN Functions */

// Funcao de leitura de matriz
int read_matriz(matriz_2x2_t* matriz){
	for (int i = 0; i < matriz->l; i++){
		printf("Insira %d valores reais para a linha %d\n", matriz->c, i+1);
		for (int j = 0; j < matriz->c; j++){
			if (scanf("%lf", &matriz->v[i][j]) != 1) {
				printf("Entrada inválida para coluna %d do linha %d!\n", j + 1, i + 1);
				// Limpa o buffer de entrada apos a falha do scanf
				while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);
				return 2; // Código de erro
			}	
		}
	}
	return 0;
}

// Funcao pra teste de quadrado magico
int test_for_magic_sq(matriz_2x2_t* matriz){
	double	key = 0.0,
		sum;
	
	for (int j = 0; j < matriz->c; j++){
		key += matriz->v[0][j];	
	}
	
	// Testa se é valido para todas as linhas
	for (int i = 0; i < matriz->l; i++){
		sum = 0.0;
		for (int j = 0; j < matriz->c; j++){
			sum += matriz->v[i][j];
		}
		if (fabs(sum - key) > EPSILON)
			return 0;	
	}
	
	// Testa se é valido para todas as colunas
	for (int i = 0; i < matriz->c; i++){
		sum = 0.0;
		for (int j = 0; j < matriz->l; j++){
			sum += matriz->v[j][i];
		}
		if (fabs(sum - key) > EPSILON)
			return 0;	
	}
	
	// Testa diagonal principal
	sum = 0.0;
	for (int i = 0; i < matriz->l; i++) {
		sum += matriz->v[i][i];
	}
	if (fabs(sum - key) > EPSILON)
		return 0;
	
	// Testa diagonal secundária
	sum = 0.0;
	for (int i = 0; i < matriz->l; i++) {
		sum += matriz->v[i][matriz->l - 1 - i];
	}
	if (fabs(sum - key) > EPSILON)
		return 0;
	
	// Retorna resultado verdadeiro
	matriz->p = matriz->p | (1<<1);
	return 1;
}

// Funcao tranfere soma dos divisores proprios dos valores da matriz origem para matriz destino
void sum_from_div_matriz_idx(matriz_2x2_t* in, matriz_2x2_t* out){
	for (int i = 0; i < in->l; i++){
		for (int j = 0; j < in->c; j++){
			out->v[i][j] = 0.0;
			int valor_inteiro = (int)round(in->v[i][j]); // Pega a parte inteira, arredondando

			// Exclui valores inválidos
			if (valor_inteiro <= 0) {
				out->v[i][j] = 0.0;
				continue;
			}

			for (int k = 1; k < valor_inteiro; k++){
				if (!(valor_inteiro % k))
					out->v[i][j] += k;
			}
		}
	}
}

// Funcao que salva na matriz destino o exponencial dos valores da matriz origem
void exp_from_matriz_idx(matriz_2x2_t* in, matriz_2x2_t* out){
	for (int i = 0; i < in->l; i++){
		for (int j = 0; j < in->c; j++)
			out->v[i][j] = exp(in->v[i][j]);
	}	
}
/* END Functions */

/* BEGIN Main */
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
	matriz_2x2_t matriz_A, matriz_B, matriz_C;
	/* END Variaveis main */
	
	/* BEGIN main block 0 */
	
	/* END main block 0 */
	
	/* BEGIN main loop */
	while (1){
		printf(eraseDisplay);
		matriz_A.p = 0;
		matriz_B.p = 0;
		matriz_C.p = 0;
		
		/* BEGIN Ler tamanho matriz A */
		printf("Insira o tamanho da matriz A (Linhas x Colunas) separados por espaço (Tamanho maximo 10x10).\n"
			"(Insira 0 ou um valor inválido para finalizar o programa)\n"
		);
		if (scanf("%d%d", &matriz_A.l, &matriz_A.c) != 2) {
			printf("Entrada inválida!\n"
				"Finalizando programa...\n"
			);
			while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);	//Limpar buffer
			return 1;
		}
		/* END Ler tamanho matriz A */
		
		/* BEGIN Testa validade matriz A */
		if ((matriz_A.l <= 0 || matriz_A.c <= 0) || (matriz_A.l > 10 || matriz_A.c > 10)){
			printf("Finalizando programa...\n"
			);
			while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);	//Limpar buffer
			return 1;
		}
		/* END Testa validade matriz A */
		
		/* BEGIN Verifica se matriz A eh quadrada */
		if (matriz_A.c == matriz_A.l)
			matriz_A.p = matriz_A.p | (1<<0);
		else
			matriz_A.p = matriz_A.p & ~(1<<0);
		/* END Verifica se matriz A eh quadrada */
		
		/* BEGIN Ler matriz A */
		if (read_matriz(&matriz_A) != 0){
			printf("Reiniciando programa...\n"
			);
			while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);	//Limpar buffer
			continue;
		}
		/* END Ler matriz A */
		
		/* BEGIN print matriz A */
		printf("\nA matriz A é:\n");
		for (int i = 0; i < matriz_A.l; i++){
			for (int j = 0; j < matriz_A.c; j++)
				printf("%.2f\t", matriz_A.v[i][j]);
			printf("\n");
		}
		/* END print matriz A */
		
		if ((matriz_A.p & (1<<0)) && (test_for_magic_sq(&matriz_A))){
			printf("A matriz A é um quadrado mágico.\n");
		}
		else {
			printf("A matriz A não é um quadrado mágico.\n");
			
			// Inicializa as matrizes B e C
			matriz_B.l = matriz_A.l;
			matriz_B.c = matriz_A.c;
			matriz_B.p = matriz_A.p;
			matriz_C.l = matriz_A.l;
			matriz_C.c = matriz_A.c;
			matriz_C.p = matriz_A.p;
			
			sum_from_div_matriz_idx(&matriz_A, &matriz_B);
			exp_from_matriz_idx(&matriz_A, &matriz_C);
			
			/* BEGIN print matriz B */
			printf("\nA matriz B é:\n");
			for (int i = 0; i < matriz_B.l; i++){
				for (int j = 0; j < matriz_B.c; j++)
					printf("%.2f\t", matriz_B.v[i][j]);
				printf("\n");
			}
			/* END print matriz B */
			
			/* BEGIN print matriz C */
			printf("\nA matriz C é:\n");
			for (int i = 0; i < matriz_C.l; i++){
				for (int j = 0; j < matriz_C.c; j++)
					printf("%.2f\t", matriz_C.v[i][j]);
				printf("\n");
			}
			/* END print matriz C */
		}
		
		printf("\nPressione qualquer tecla para continuar...\n");
		GETCH();
	}	
	/* END main loop*/
	
	/* BEGIN main block 1 */
	
	/* END main block 1 */
	
	return 0;
}
/* END Main */
