#ifndef	VETOR_MATRIZ_C
#define VETOR_MATRIZ_C

#include <stdlib.h>
#include <stdio.h>

#include "vetor_matriz.h"

// Constantes para melhorar a legibilidade e facilitar manutenções futuras
#define NUM_NOTAS 4          // Número de notas por aluno
#define INDICE_MEDIA NUM_NOTAS // O índice onde a média será armazenada
#define NUM_COLUNAS (NUM_NOTAS + 1) // Número total de colunas (notas + média)

/* BEGIN parNoVetor */
int parNoVetor(void) {
    int *vetor = NULL;    // Vetor principal
    int *pares = NULL;    // Vetor para números pares
    int *impares = NULL;  // Vetor para números ímpares
    int tamanho, numPares = 0, numImpares = 0;
    char ch_buf;
	
    // Solicita o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);	//Limpar buffer
    if (scanf("%d", &tamanho) != 1 || tamanho <= 0) {
        printf("Tamanho inválido!\n");
        while (getchar() != '\n'); // Limpa buffer
        return 1; // Erro
    }

    // Aloca vetor principal
    vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1; // Erro
    }

    // Lê os números e conta pares/ímpares
    printf("Digite %d números inteiros:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
    	while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);	//Limpar buffer
        if (scanf("%d", &vetor[i]) != 1) {
            printf("Entrada inválida!\n");
            free(vetor);
            while (getchar() != '\n'); // Limpa buffer
            return 1; // Erro
        }
        if (vetor[i] % 2 == 0) {
            numPares++;
        } else {
            numImpares++;
        }
    }

    // Aloca vetores para pares e ímpares
    if (numPares > 0) {
        pares = (int *)malloc(numPares * sizeof(int));
        if (pares == NULL) {
            printf("Erro de alocação de memória!\n");
            free(vetor);
            return 1; // Erro
        }
    }
    if (numImpares > 0) {
        impares = (int *)malloc(numImpares * sizeof(int));
        if (impares == NULL) {
            printf("Erro de alocação de memória!\n");
            free(vetor);
            free(pares);
            return 1; // Erro
        }
    }

    // Separa os números em pares e ímpares
    int idxPares = 0, idxImpares = 0;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 0) {
            pares[idxPares++] = vetor[i];
        } else {
            impares[idxImpares++] = vetor[i];
        }
    }

    // Exibe os resultados
    printf("\nVetor original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("\nNúmeros pares (%d):\n", numPares);
    if (numPares > 0) {
        for (int i = 0; i < numPares; i++) {
            printf("%d ", pares[i]);
        }
    } else {
        printf("Nenhum número par encontrado.");
    }
    printf("\n");

    printf("\nNúmeros ímpares (%d):\n", numImpares);
    if (numImpares > 0) {
        for (int i = 0; i < numImpares; i++) {
            printf("%d ", impares[i]);
        }
    } else {
        printf("Nenhum número ímpar encontrado.");
    }
    printf("\n");

    // Libera memória
    free(vetor);
    free(pares);
    free(impares);

    return 0; // Sucesso
}
/* END parNoVetor */

/* BEGIN notasMedia */
int notasMedia(void){
    int **notas = NULL;
    int numAlunos;
    int i, j, k; // Declarar variáveis de loop no início ou dentro do escopo do loop (C99+)
    char ch_buf;

    // Solicita quantidade de alunos
    printf("Digite a quantidade de alunos: ");
    if (scanf("%d", &numAlunos) != 1 || numAlunos <= 0) {
        printf("Quantidade inválida!\n");
        // Limpa o buffer de entrada para remover caracteres inválidos
        while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);	//Limpar buffer
        return 1; // Código de erro
    }
    // Limpa o caractere de nova linha ('\n') deixado pelo scanf no buffer
    while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);	//Limpar buffer

    // Aloca memória para as linhas (um ponteiro para cada aluno)
    notas = (int **)malloc(numAlunos * sizeof(int *));
    if (notas == NULL) {
        printf("Erro de alocação de memória para as linhas (alunos)!\n");
        return 1; // Código de erro
    }

    // Inicializa todos os ponteiros de linha para NULL.
    // Isso ajuda a simplificar a limpeza em caso de falha na alocação de uma linha específica.
    for (i = 0; i < numAlunos; i++) {
        notas[i] = NULL;
    }

    // Aloca memória para as colunas (notas e média) para cada aluno
    for (i = 0; i < numAlunos; i++) {
        notas[i] = (int *)malloc(NUM_COLUNAS * sizeof(int));
        if (notas[i] == NULL) {
            printf("Erro na alocação de memória para as notas do aluno %d!\n", i + 1);
            // Libera toda a memória alocada até agora antes de sair
            for (k = 0; k < numAlunos; k++) { // Percorre todos os ponteiros de linha
                free(notas[k]); // free(NULL) é seguro e não faz nada
            }
            free(notas);
            notas = NULL; // Boa prática
            return 1; // Código de erro
        }
    }

    // Lê as notas
    printf("Digite as %d notas para cada um dos %d alunos:\n", NUM_NOTAS, numAlunos);
    for (i = 0; i < numAlunos; i++) {
        printf("Insira as %d notas do aluno %d (separadas por espaço ou enter):\n", NUM_NOTAS, i + 1);
        for (j = 0; j < NUM_NOTAS; j++) {
            // printf("Nota %d: ", j + 1); // Descomente se quiser um prompt para cada nota individual
            if (scanf("%d", &notas[i][j]) != 1) {
                printf("Entrada inválida para a nota %d do aluno %d!\n", j + 1, i + 1);
                // Libera toda a memória alocada
                for (k = 0; k < numAlunos; k++) {
                    free(notas[k]);
                }
                free(notas);
                notas = NULL;
                // Limpa o buffer de entrada após a falha do scanf
                while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);
                return 1; // Código de erro
            }
        }
        // Opcional: limpar o buffer após ler todas as notas de um aluno se elas forem
        // inseridas em uma única linha e houver lixo extra.
        // No entanto, o scanf("%d") subsequente para o próximo aluno irá pular
        // quaisquer espaços em branco, incluindo o '\n' deixado.
        // A limpeza do buffer após *toda* a entrada de notas (abaixo) é geralmente suficiente.
    }
    // Limpa o buffer de entrada uma última vez após todas as notas serem lidas com sucesso.
    // Isso remove o '\n' final deixado pelo último scanf.
    while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);	//Limpar buffer


    // Calcular média (divisão inteira)
    for (i = 0; i < numAlunos; i++) {
        long long sum = 0; // Usar long long para a soma para evitar overflow com muitas notas grandes
        for (j = 0; j < NUM_NOTAS; j++) {
            sum += notas[i][j];
        }
        if (NUM_NOTAS > 0) {
            notas[i][INDICE_MEDIA] = (int)(sum / NUM_NOTAS); // A média será inteira
        } else {
            notas[i][INDICE_MEDIA] = 0; // Caso NUM_NOTAS seja 0 (improvável com define)
        }
    }

    // Exibe Valores
    printf("\n--- Tabela de Notas e Médias ---\n");
    printf("Aluno\t");
    for (j = 0; j < NUM_NOTAS; j++) {
        printf("P%d\t", j + 1);
    }
    printf("Média\n");

    for (i = 0; i < numAlunos; i++) {
        printf("%d\t", i + 1); // Exibe o número do aluno (base 1)
        for (j = 0; j < NUM_COLUNAS; j++) {
            printf("%d\t", notas[i][j]);
        }
        printf("\n");
    }

    // Libera Memória
    for (i = 0; i < numAlunos; i++) {
        free(notas[i]);
    }
    free(notas);
    notas = NULL; // Boa prática para evitar ponteiros pendentes (dangling pointers)

    return 0; // Sucesso	
}
/* END notasMedia */

/* BEGIN Ordenar Vetor */
int organizeCrescente(void){
	
	struct Vetor{
		int size;
		int* values;
	}vetor;
	char ch_buf;
	
	// Solicita o tamanho do vetor
	printf("Digite o tamanho do vetor:\n");
	if (scanf("%d", &vetor.size) != 1 || vetor.size <= 0) {
		printf("Tamanho inválido!\n");
		while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);	//Limpar buffer
		return 1; // Erro
	}
	
	// Aloca vecNum
	vetor.values = (int *)malloc(vetor.size * sizeof(int));
	if (vetor.values == NULL) {
		printf("Erro de alocação de memória!\n");
		return 1; // Erro
	}
	
	// Lê os números
	printf("Digite %d números inteiros:\n", vetor.size);
	for (int i = 0; i < vetor.size; i++) {
		if (scanf("%d", &vetor.values[i]) != 1) {
			printf("Entrada inválida!\n");
			free(vetor.values);
			while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);	//Limpar buffer
			return 1; // Erro
		}
	}
	
	// Ordena o vetor
	for (int i=0; i < vetor.size-1; i++) {
		for (int j=i+1; j<vetor.size; j++){
			if (vetor.values[i] > vetor.values[j]){
				int temp = vetor.values[i];
				vetor.values[i] = vetor.values[j];
				vetor.values[j] = temp;
			}
		}	
	}	
	
	// Printa vetor organizado
	printf("O vetor organizado em ordem crescente fica:\n");
	for (int i=0; i<vetor.size; i++)
		printf("%d\t", vetor.values[i]);
	printf("\n");
	
	// Libera Memória
	free(vetor.values);
	vetor.values = NULL; // Boa prática para evitar ponteiros pendentes (dangling pointers)
	
	return 0;
}
/* END Ordenar Vetor */

/* BEGIN TypeDefs e global vars */
char ch_buf;

typedef struct Vetor{
	int size;
	int* v;
} vetor_t;
	
typedef struct Matriz_sqr{
	int size;
	int** v;
}matriz_sqrt_t;
/* END TypeDefs e global vars */

/* BEGIN funcao operador matriz */

// Função para liberar memoria
void free_matriz(matriz_sqrt_t* matriz){
	for (int k = 0; k < matriz->size; k++)// Percorre todos os ponteiros de linha
		free(matriz->v[k]); // free(NULL) é seguro e não faz nada
	free(matriz->v);
	matriz->v = NULL;
	return;
}

// Função para alocar memoria
int aloc_matriz(matriz_sqrt_t* matriz){
	// Aloca memória para as linhas da matriz
	matriz->v = (int **)malloc(matriz->size * sizeof(int *));
	if (matriz->v == NULL) {
		printf("Erro de alocação de memória para as linhas da matriz!\n");
		return 1; // Código de erro
	}
	
	// Inicializa todos os ponteiros de linha para NULL.
	// Isso ajuda a simplificar a limpeza em caso de falha na alocação de uma linha específica.
	for (int i = 0; i < matriz->size; i++)
		matriz->v[i] = NULL;	

	// Aloca memória para as colunas da matriz
	for (int i = 0; i < matriz->size; i++) {
		matriz->v[i] = (int *)malloc(matriz->size * sizeof(int));
		if (matriz->v[i] == NULL) {
			printf("Erro na alocação de memória para as colunas da linha %d!\n", i + 1);
			// Libera toda a memória alocada até agora antes de sair
			free_matriz(matriz);
			return 1; // Código de erro
		}
	}
	
	return 0;
}

// Função para ler os valores da matriz
int read_matriz(matriz_sqrt_t* matriz){
	for (int i = 0; i < matriz->size; i++){
		printf("Insira os %d valores da linha %d da matriz\n", matriz->size, i+1);
		for (int j = 0; j < matriz->size; j++){
			if (scanf("%d", &matriz->v[i][j]) != 1) {
				printf("Entrada inválida para coluna %d do linha %d!\n", j + 1, i + 1);
				// Libera toda a memória alocada
				free_matriz(matriz);
				// Limpa o buffer de entrada após a falha do scanf
				while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);
				return 2; // Código de erro
			}	
		}
	}
	return 0;
}

// Função para encontrar diagonal princial
void find_matriz_dp(matriz_sqrt_t* matriz, vetor_t* vetor){
	for (int i = 0; i < matriz->size; i++)
		vetor->v[i] = matriz->v[i][i];
	return;
}

// Função para encontrar diagonal secundaria
void find_matriz_ds(matriz_sqrt_t* matriz, vetor_t* vetor){
	for (int i = 0; i < matriz->size; i++)
		vetor->v[i] = matriz->v[i][matriz->size -1 - i];
	return;
}
/* END funcao operador matriz */

/* BEGIN Operação Matriz */
int ler_matriz_op(void){
	
	matriz_sqrt_t matriz_A, matriz_B;
	vetor_t	diag_p = {0, NULL}, diag_s = {0,NULL};
	
	// Solicita o tamanho das matrizes
	printf("Digite o tamanho das matrizes:\n");
	if (scanf("%d", &matriz_A.size) != 1 || matriz_A.size <= 0) {
		printf("Tamanho inválido!\n");
		while ((ch_buf = getchar()) != '\n' && ch_buf != EOF);	//Limpar buffer
		return 2; // Erro
	}
	
	// Aloca A
	if (aloc_matriz(&matriz_A) != 0)
		return 1;
	
	// Aloca B
	if (aloc_matriz(&matriz_B) != 0)
		return 1;
	
	// Lê os valores da matriz A
	if (read_matriz(&matriz_A) != 0)
		return 2;
	
	// Imprimir matriz A
	printf("\nA matriz A é:\n");
	for (int i = 0; i < matriz_A.size; i++){
		for (int j = 0; j < matriz_A.size; j++)
			printf("%d\t", matriz_A.v[i][j]);
		printf("\n");
	}
	
	// Aloca Vetor diagonal principal
	diag_p.size = matriz_A.size;
	diag_p.v = (int *)malloc(diag_p.size * sizeof(int));
	if (diag_p.v == NULL) {
		printf("Erro de alocação de memória para o vetor diagonal p!\n");
		return 1; // Código de erro
	}
	
	// Aloca Vetor diagonal secundaria
	diag_s.size = matriz_A.size;
	diag_s.v = (int *)malloc(diag_s.size * sizeof(int));
	if (diag_s.v == NULL) {
		printf("Erro de alocação de memória para o vetor diagonal s!\n");
		return 1; // Código de erro
	}
	
	// Transporta diagonal principal de A para vetor e imprime
	find_matriz_dp(&matriz_A, &diag_p);
	printf("\nA diagonal principal de A é:\n");
	for (int i = 0; i < diag_p.size; i++)
		printf("%d\t", diag_p.v[i]);
	printf("\n");
	
	// Transporta diagonal secundaria  de A para vetor e imprime
	find_matriz_ds(&matriz_A, &diag_s);
	printf("\nA diagonal secundaria de A é:\n");
	for (int i = 0; i < diag_s.size; i++)
		printf("%d\t", diag_s.v[i]);
	printf("\n");
	
	// Libera Memória
	free_matriz(&matriz_A);
	free_matriz(&matriz_B);
	free(diag_p.v);
	diag_p.v = NULL;
	free(diag_s.v);
	diag_s.v = NULL;
	
	return 0; // Sucesso
}
/* END Operação Matriz */

#endif
