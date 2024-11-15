#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha*p) {
    return p->topo == -1;
}

void empilhar(Pilha*p, int valor) {
    if (p->topo < MAX - 1) {
        p->itens[++(p->topo)] = valor;
    } else {
        printf("Pilha cheia!\n");
    }
}

int desempilha(Pilha *p) {
    if (!vazia(p)) {
        return p->itens[(p->topo)--];
    } else {
        printf("Pilha vazia!\n");
        return -1;
    }
}

void inverter(Pilha *p) {
    int aux[MAX];
    int i = 0;
    
    while (!vazia(p)) {
        aux[i++] = desempilha(p);
    }
    
    for (int j = 0; j < i; j++) {
        empilhar(p, aux[j]);
    }
}

int main() {
    Pilha pilha;
    inicializar(&pilha);

    empilhar(&pilha, 1);
    empilhar(&pilha, 2);
    empilhar(&pilha, 3);
    
    printf("Pilha original: ");
    for (int i = 0; i <= pilha.topo; i++) {
        printf("%d ", pilha.itens[i]);
    }
    printf("\n");

    inverter(&pilha);

    printf("Pilha invertida: ");
    for (int i = 0; i <= pilha.topo; i++) {
        printf("%d ", pilha.itens[i]);
    }
    printf("\n");

    return 0;
}
