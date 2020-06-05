#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    int valor;
    struct nodo *esq,*dir;   
} *ABin, Nodo;


ABin fromArray(int v[], int N) {
    ABin r = NULL;
    if(N > 0) {
        r = malloc(sizeof(Nodo));
        r->valor = v[0];
        r->esq = fromArray(v+1,N-1);
        r->dir = fromArray(v+1,N-1);
    }
    return r;
}

int altura(ABin a) {
    int r = 0;
    if(a) r = 1 + (altura(a->dir) > altura(a->esq) ? altura(a->dir) : altura(a->esq)); 
    return r;
}


int size(ABin a) {
    if (!a) return 0;
    else return (1 + size(a->esq) + size(a->dir));
}

ABin insABin(ABin a,int x) {
    ABin aux;
    if(!a) {
        aux = malloc(sizeof(Nodo));
        aux->valor = x;
        aux->esq = NULL;
        aux->dir = NULL;
        return aux;
    }
    else {
        if(a->valor < x) a->dir = insABin(a->dir,x);
        else a->esq = insABin(a->esq,x);
    }
    return a;
}

void inorder(ABin a) {
    if(a) {
        inorder(a->esq);
        printf("%d ",a->valor);
        inorder(a->dir);
    }
}

void preorder(ABin a) {
    if(a) {
        printf("%d ", a->valor);
        preorder(a->esq);
        preorder(a->dir);
    }
}

void posorder(ABin a) {
    if(a) {
        printf("%d", a->valor);
        posorder(a->esq);
        posorder(a->dir);
    }
}

int main() {
    ABin a1 = NULL;
    a1 = insABin(a1,23);
    a1 = insABin(insABin(insABin(insABin(a1,17),2),19),38);
    printf("InOrder: \n");
    inorder(a1);
    printf("\nPreOrder :\n");
    preorder(a1);
    putchar('\n');

    return 0;
}