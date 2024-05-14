#include <stdio.h>
int main()
{
    int valores[100],maior=0,posicao=0;
    for (int i = 0; i < 100; i++){
        scanf("%d",&valores[i]);
        if (valores[i]>maior)
        {
            maior=valores[i];
            posicao= i+1;
            }   
    }
    printf("%d\n", maior);
    printf("%d\n", posicao); 
    return 0;
}