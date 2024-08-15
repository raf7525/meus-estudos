#include <stdio.h>

void calcular_media(int *A, int *B) {
    int media, resto;
    
    if (*A < *B) {
        media = (*A + *B) / 2;
        resto = (*A + *B) % 2;
        *B = media;
    } else {
        media = (*A + *B) / 2;
        resto = (*A + *B) % 2;
        *A = media;
    }
}

int main() {
    int A = 10, B = 20; // Exemplo de valores para A e B
    calcular_media(&A, &B);
    printf("%d %d\n", A, B);
    return 0;
}
