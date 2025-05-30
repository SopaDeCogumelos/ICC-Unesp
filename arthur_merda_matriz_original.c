#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[10][10], la, ca, dp[100], i, j, cont, n, l, conts, contpar, k, r[10][10], dpar[100], ds[100], b[10][10], lb, cb, soma = 0;
    printf("digite as dimensoes de a: \n");
    scanf("%d%d", &la, &ca);
    ///////////////////////////////////////////////////////////////////////////////// matriz a
    printf("digite os elementos da matriz a: \n");
    for (i = 1; i <= la; i = i + 1)
    {
        for (j = 1; j <= ca; j = j + 1)
        {
            scanf("%d", &a[i][j]);
        }
    }
    ////////////////////////////////////////////////////////////////////////////////// matriz a
    printf("a matriz lida: \n\n");
    for (i = 1; i <= la; i = i + 1)
    {
        for (j = 1; j <= ca; j = j + 1)
        {
            printf("\t%d", a[i][j]);
        }
        printf("\n\n");
    }
    ////////////////////////////////////////////////////////////////////////////////// matriz b
    printf("digite as dimensoes de b: \n");
    scanf("%d%d", &lb, &cb);
    printf("digite os elementos da matriz b: \n");
    for (i = 1; i <= lb; i = i + 1)
    {
        for (j = 1; j <= cb; j = j + 1)
        {
            scanf("%d", &b[i][j]);
        }
    }
    ///////////////////////////////////////////////////////////////////////////////// matriz b
    printf("a matriz lida: \n\n");
    for (i = 1; i <= lb; i = i + 1)
    {
        for (j = 1; j <= cb; j = j + 1)
        {
            printf("\t%d", b[i][j]);
        }
        printf("\n\n");
    }
    ///////////////////////////////////////////////////////////////////////////////// murtiplicação
    for (i = 1; i <= la; i = i + 1)
    {
        for (i = 1; <= cb; i = i + 1)
        {
            soma = 0;
            for (k = 1; k <= ca; k = k + 1)
            {
                soma = soma + a[i][k] * b[k][j];
            }
            r[i][j] = soma;
            printf("%d", r[i][j]);
        }
    }
}