#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int media;
    struct node *next;
} node;

void adicionar(node **head, node **tail, int n) {
    node *novo = (node *)malloc(sizeof(node));
    if (novo != NULL) {
        novo->media = n;
        novo->next = NULL;

        if (*head == NULL) {
            *head = novo;
            *tail = novo;
        } else {
            (*tail)->next = novo;
            *tail = novo;
        }
    }
}

int ordenarBouble(node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return 0;
    }

    int troca;
    node *atual;
    node *fim = NULL;
    int cont=0;
    int preg =0;
    do {
        troca = 0;
        atual = *head;
        while (atual->next != fim) {
            
            if (atual->media < atual->next->media) {
                int temp = atual->media;
                atual->media = atual->next->media;
                atual->next->media = temp;
                troca = 1;
            }
            else{
                cont++;
            }
            atual = atual->next;
            preg++;
        }
        fim = atual;
        
    } while (troca);

    
    return preg - cont;
}


void liberarLista(node **head) {
    node *atual = *head;
    while (atual != NULL) {
        node *temp = atual;
        atual = atual->next;
        free(temp);
    }
    *head = NULL;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        node *head = NULL;
        node *tail = NULL;
        
        int M;
        scanf("%d", &M);
        
        for (int j = 0; j < M; j++) {
            int n;
            scanf("%d", &n);
            adicionar(&head, &tail, n);
        }

        int trocas = ordenarBouble(&head);
        printf("%d",trocas);
        liberarLista(&head); 
        
    }

    return 0;
}














