#include <stdio.h>

void lerMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void calcularTotalBitcoins(int G, int A, int M, int C, int a[G][A], int m[A][M], int p[M][C]) {
    for (int i = 0; i < G; i++) {
        for (int j = 0; j < C; j++) {
            int total_bitcoins = 0;
            for (int k = 0; k < A; k++) {
                int a_val = a[i][k];
                for (int l = 0; l < M; l++) {
                    total_bitcoins += a_val * m[k][l] * p[l][j];
                }
            }
        printf("%d", total_bitcoins);
            if (j < C - 1) {
                printf(" ");
            }
        }
        printf("\n");
       break;
    }
}

int main() {
    int G, A, M, C;
    scanf("%d %d %d %d", &G, &A, &M, &C);

    int a[G][A], m[A][M], p[M][C];
   
    lerMatriz(G, A, a);
    lerMatriz(A, M, m);
    lerMatriz(M, C, p);

    calcularTotalBitcoins(G, A, M, C, a, m, p);
    
    return 0;
}
