#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;
    int arr, i;
    printf("Digite um numero: ");
    scanf("%d", &arr);
    
    p = (int *)malloc(arr * sizeof(int));
    if (p == NULL) {
      printf("Erro ao alocar memoria.\n");
      return 0;
    }

    printf("Digite %d numeros:\n", arr);
    for (i = 0; i < arr; i++) {
      scanf("%d", &p[i]);
    }

    printf("Numeros digitados:\n");
    for (i = 0; i < arr; i++) {
      printf("%d ", p[i]);
    }
    printf("\n");

  
    free(p);

    return 0;
}
