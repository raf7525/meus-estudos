#include <stdio.h>
//Codigo adaptado de (com mais explicacoes sobre fseek) - https://www.geeksforgeeks.org/fseek-in-c-with-example/ e https://www.educba.com/fseek-in-c/ 

int main(void) {
  FILE *fp;
  fp = fopen("arquivoo.txt","r");
  char ch;
  //movendo o ponteiro para o final do arquivo
  fseek(fp,0,SEEK_SET);
  //printando o numero de bytes
  printf("%ld\n", ftell(fp));
  //movendo agora o ponteiro para una distancia de 20 bytes do inicio do arquivo
  fseek(fp,-50,SEEK_END);
  while((ch=fgetc(fp)) != EOF){ //lendo tudo a partir do 20 caracter e imprimindo na tela 
    putchar(ch);
  }

 /* while(ftell(fp) <= 110){ //lendo tudo a partir do 20 caracter e imprimindo na tela 
    ch = fgetc(fp);
    putchar(ch);
  }*/
  
  return 0;
}