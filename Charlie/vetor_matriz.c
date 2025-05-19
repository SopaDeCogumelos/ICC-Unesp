#ifndef	VETOR_MATRIZ_C
#define VETOR_MATRIZ_C

#include <stdlib.h>
#include <stdio.h>

#include "vetor_matriz.h"

// Constantes para melhorar a legibilidade e facilitar manuten��es futuras
#define NUM_NOTAS 4          // N�mero de notas por aluno
#define INDICE_MEDIA NUM_NOTAS // O �ndice onde a m�dia ser� armazenada
#define NUM_COLUNAS (NUM_NOTAS + 1) // N�mero total de colunas (notas + m�dia)

/* BEGIN parNoVetor */
int parNoVetor(void) {
    int *vetor = NULL;    // Vetor principal
    int *pares = NULL;    // Vetor para n�meros pares
    int *impares = NULL;  // Vetor para n�meros �mpares
    int tamanho, numPares = 0, numImpares = 0;

    // Solicita o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    if (scanf("%d", &tamanho) != 1 || tamanho <= 0) {
        printf("Tamanho inv�lido!\n");
        while (getchar() != '\n'); // Limpa buffer
        return 1; // Erro
    }
    while (getchar() != '\n'); // Limpa buffer

    // Aloca vetor principal
    vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro de aloca��o de mem�ria!\n");
        return 1; // Erro
    }

    // L� os n�meros e conta pares/�mpares
    printf("Digite %d n�meros inteiros:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        if (scanf("%d", &vetor[i]) != 1) {
            printf("Entrada inv�lida!\n");
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

    // Aloca vetores para pares e �mpares
    if (numPares > 0) {
        pares = (int *)malloc(numPares * sizeof(int));
        if (pares == NULL) {
            printf("Erro de aloca��o de mem�ria!\n");
            free(vetor);
            return 1; // Erro
        }
    }
    if (numImpares > 0) {
        impares = (int *)malloc(numImpares * sizeof(int));
        if (impares == NULL) {
            printf("Erro de aloca��o de mem�ria!\n");
            free(vetor);
            free(pares);
            return 1; // Erro
        }
    }

    // Separa os n�meros em pares e �mpares
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

    printf("\nN�meros pares (%d):\n", numPares);
    if (numPares > 0) {
        for (int i = 0; i < numPares; i++) {
            printf("%d ", pares[i]);
        }
    } else {
        printf("Nenhum n�mero par encontrado.");
    }
    printf("\n");

    printf("\nN�meros �mpares (%d):\n", numImpares);
    if (numImpares > 0) {
        for (int i = 0; i < numImpares; i++) {
            printf("%d ", impares[i]);
        }
    } else {
        printf("Nenhum n�mero �mpar encontrado.");
    }
    printf("\n");

    // Libera mem�ria
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
    int i, j, k; // Declarar vari�veis de loop no in�cio ou dentro do escopo do loop (C99+)

    // Solicita quantidade de alunos
    printf("Digite a quantidade de alunos: ");
    if (scanf("%d", &numAlunos) != 1 || numAlunos <= 0) {
        printf("Quantidade inv�lida!\n");
        // Limpa o buffer de entrada para remover caracteres inv�lidos
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        return 1; // C�digo de erro
    }
    // Limpa o caractere de nova linha ('\n') deixado pelo scanf no buffer
    int ch_clear; // Vari�vel separada para evitar conflito se 'ch' for usado posteriormente
    while ((ch_clear = getchar()) != '\n' && ch_clear != EOF);

    // Aloca mem�ria para as linhas (um ponteiro para cada aluno)
    notas = (int **)malloc(numAlunos * sizeof(int *));
    if (notas == NULL) {
        printf("Erro de aloca��o de mem�ria para as linhas (alunos)!\n");
        return 1; // C�digo de erro
    }

    // Inicializa todos os ponteiros de linha para NULL.
    // Isso ajuda a simplificar a limpeza em caso de falha na aloca��o de uma linha espec�fica.
    for (i = 0; i < numAlunos; i++) {
        notas[i] = NULL;
    }

    // Aloca mem�ria para as colunas (notas e m�dia) para cada aluno
    for (i = 0; i < numAlunos; i++) {
        notas[i] = (int *)malloc(NUM_COLUNAS * sizeof(int));
        if (notas[i] == NULL) {
            printf("Erro na aloca��o de mem�ria para as notas do aluno %d!\n", i + 1);
            // Libera toda a mem�ria alocada at� agora antes de sair
            for (k = 0; k < numAlunos; k++) { // Percorre todos os ponteiros de linha
                free(notas[k]); // free(NULL) � seguro e n�o faz nada
            }
            free(notas);
            notas = NULL; // Boa pr�tica
            return 1; // C�digo de erro
        }
    }

    // L� as notas
    printf("Digite as %d notas para cada um dos %d alunos:\n", NUM_NOTAS, numAlunos);
    for (i = 0; i < numAlunos; i++) {
        printf("Insira as %d notas do aluno %d (separadas por espa�o ou enter):\n", NUM_NOTAS, i + 1);
        for (j = 0; j < NUM_NOTAS; j++) {
            // printf("Nota %d: ", j + 1); // Descomente se quiser um prompt para cada nota individual
            if (scanf("%d", &notas[i][j]) != 1) {
                printf("Entrada inv�lida para a nota %d do aluno %d!\n", j + 1, i + 1);
                // Libera toda a mem�ria alocada
                for (k = 0; k < numAlunos; k++) {
                    free(notas[k]);
                }
                free(notas);
                notas = NULL;
                // Limpa o buffer de entrada ap�s a falha do scanf
                while ((ch_clear = getchar()) != '\n' && ch_clear != EOF);
                return 1; // C�digo de erro
            }
        }
        // Opcional: limpar o buffer ap�s ler todas as notas de um aluno se elas forem
        // inseridas em uma �nica linha e houver lixo extra.
        // No entanto, o scanf("%d") subsequente para o pr�ximo aluno ir� pular
        // quaisquer espa�os em branco, incluindo o '\n' deixado.
        // A limpeza do buffer ap�s *toda* a entrada de notas (abaixo) � geralmente suficiente.
    }
    // Limpa o buffer de entrada uma �ltima vez ap�s todas as notas serem lidas com sucesso.
    // Isso remove o '\n' final deixado pelo �ltimo scanf.
    while ((ch_clear = getchar()) != '\n' && ch_clear != EOF && ch_clear != '\0');


    // Calcular m�dia (divis�o inteira)
    for (i = 0; i < numAlunos; i++) {
        long long sum = 0; // Usar long long para a soma para evitar overflow com muitas notas grandes
        for (j = 0; j < NUM_NOTAS; j++) {
            sum += notas[i][j];
        }
        if (NUM_NOTAS > 0) {
            notas[i][INDICE_MEDIA] = (int)(sum / NUM_NOTAS); // A m�dia ser� inteira
        } else {
            notas[i][INDICE_MEDIA] = 0; // Caso NUM_NOTAS seja 0 (improv�vel com define)
        }
    }

    // Exibe Valores
    printf("\n--- Tabela de Notas e M�dias ---\n");
    printf("Aluno\t");
    for (j = 0; j < NUM_NOTAS; j++) {
        printf("P%d\t", j + 1);
    }
    printf("M�dia\n");

    for (i = 0; i < numAlunos; i++) {
        printf("%d\t", i + 1); // Exibe o n�mero do aluno (base 1)
        for (j = 0; j < NUM_COLUNAS; j++) {
            printf("%d\t", notas[i][j]);
        }
        printf("\n");
    }

    // Libera Mem�ria
    for (i = 0; i < numAlunos; i++) {
        free(notas[i]);
    }
    free(notas);
    notas = NULL; // Boa pr�tica para evitar ponteiros pendentes (dangling pointers)

    return 0; // Sucesso	
}
/* END notasMedia */

#endif
