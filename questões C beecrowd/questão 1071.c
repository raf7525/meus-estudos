#include<stdio.h>
int main()
{
    int x,y,soma=0;
    scanf("%d %d",&x,&y);
    if(x>y){
        for(int i=y+1;i<x;i++){
            y=i;
            if(i % 2 !=0){
                soma= soma+i;
            }
        }
          
    }
    if(y>x){
        for(int j=x+1;j<y;j++){
            x=j;
            if(j%2!=0){
                soma=soma+j;
            }
        }
    }
    printf("%d",soma);
    return 0;
}
