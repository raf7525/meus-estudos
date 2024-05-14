#include<stdio.h>
#include<string.h>

struct key {
   char nome[10];
   int cont;
};

int main() {
    struct key mala[2][2]; // Array bidimensional de estruturas key

    // Preenchendo as estruturas com alguns valores de exemplo
    strcpy(mala[0][0].nome, "Chave 1");
    mala[0][0].cont = 1;

    strcpy(mala[0][1].nome, "Chave 2");
    mala[0][1].cont = 2;

    strcpy(mala[1][0].nome, "Chave 3");
    mala[1][0].cont = 3;

    strcpy(mala[1][1].nome, "Chave 4");
    mala[1][1].cont = 4;

    // Exibindo os valores das estruturas
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Nome: %s, Cont: %d\n", mala[i][j].nome, mala[i][j].cont);
        }
    }

    return 0;
}
