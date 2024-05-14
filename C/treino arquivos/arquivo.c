#include <stdio.h>
void ler() {
  FILE *fp;
  fp = fopen("arquivoo.txt", "r"); // Abre o arquivo em modo leitura ("r")
  char ch;
  
  if (fp != NULL) {  // Verifica se o arquivo foi aberto com sucesso
    while ((ch = fgetc(fp)) != EOF) { // Lê e imprime caractere por caractere
      putchar(ch);
    }

    fclose(fp);  // Fecha o arquivo após a leitura
  } else {
    printf("Falha ao abrir o arquivo.\n");
  }
}



void escrever()
{
  FILE *fp;
  fp = fopen("arquivoo.txt", "w");
  char ch;
  
  if (fp != NULL) {  // Verifica se o arquivo foi aberto com sucesso
    fprintf(fp, "Hello, this is a test!\n");
    fputs("Hello, this is a test!\n", fp);

    fseek(fp, -50, SEEK_END);  // Move o ponteiro 50 bytes a partir do final
    while ((ch = fgetc(fp)) != EOF) { // Lê e imprime a partir da posição atual até o final
      putchar(ch);
    }

    fclose(fp);  // Fecha o arquivo após o uso
  } else {
    printf("Falha ao abrir o arquivo.\n");
  }
  
}


int main(void) {
  escrever();
  ler();
  return 0;
}

