#include<stdio.h>
#include<string.h>  
struct pontos
    {
        int x;
        int y;
    };
    struct circulo
    {
      struct pontos centro;
      int raio;  
    };
float function(struct circulo c)
{
   return 3.14*c.raio;
}
int main()
{
    struct circulo var1, var2;
    float area;
    printf("Quais os centros dos círculo? \n");
    scanf("%d %d %d %d",&var1.centro.x,&var1.centro.y, &var2.centro.x,&var2.centro.y);
    printf("quais os raios dos circulos: \n");
    scanf("%d %d",&var1.raio,&var2.raio);
    area = function(var1);
    area = function(var2);
    return 0;
}
