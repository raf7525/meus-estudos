#include<stdio.h>
int main()
{
    float media;
    int a=3,b=3,soma=0;
    char escolha;
    int matriz[a][b];

    printf("media ou soma? ");
    scanf("%c",&escolha);

    if(escolha=='S'){
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                printf("coloque os numeros: \n");
                scanf("%d",&matriz[i][j]);
                if(i<j){
                    soma=matriz[i][j]+soma;
                }
            }
        }
        printf("%d",soma);
        printf("\n");
    }

    if(escolha=='M'){
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                printf("coloque os numeros: \n");
                scanf("%d",&matriz[i][j]);
                if(i<j){
                    soma=matriz[i][j]+soma;
                    media=soma/3;
                }
            }
        }
        printf("\n");
        printf("%f",media);
    }
    
    return 0;
}
