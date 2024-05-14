#include<stdio.h>
#include<string.h>
void somar10(int *p, int i) {
    p = &i;  // Atribui o endereço de i a p
    *p = *p + 10;  // Adiciona 10 ao valor apontado por p
    printf("%d\n", *p);  // Imprime o valor apontado por p
}

int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    somar10(&a, b);  // Chama a função somar10 com o endereço de a e o valor de a
    return 0;
}
