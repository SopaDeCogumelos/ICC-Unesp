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

    // Solicita o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    if (scanf("%d", &tamanho) != 1 || tamanho <= 0) {
        printf("Tamanho inválido!\n");
        while (getchar() != '\n'); // Limpa buffer
        return 1; // Erro
    }
    while (getchar() != '\n'); // Limpa buffer

    // Aloca vetor principal
    vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1; // Erro
    }

    // Lê os números e conta pares/ímpares
    printf("Digite %d números inteiros:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
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
    while (getchar() != '\n'); // Limpa buffer

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

    // Solicita quantidade de alunos
    printf("Digite a quantidade de alunos: ");
    if (scanf("%d", &numAlunos) != 1 || numAlunos <= 0) {
        printf("Quantidade inválida!\n");
        // Limpa o buffer de entrada para remover caracteres inválidos
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        return 1; // Código de erro
    }
    // Limpa o caractere de nova linha ('\n') deixado pelo scanf no buffer
    int ch_clear; // Variável separada para evitar conflito se 'ch' for usado posteriormente
    while ((ch_clear = getchar()) != '\n' && ch_clear != EOF);

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
                while ((ch_clear = getchar()) != '\n' && ch_clear != EOF);
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
    while ((ch_clear = getchar()) != '\n' && ch_clear != EOF && ch_clear != '\0');


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

#endif
