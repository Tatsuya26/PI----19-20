#include <stdio.h>
#include <stdlib.h>


//Parte B
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

int minheapOK (ABin a) {
    if(!a) return 1;
    else {
        if(a->valor < a->esq->valor) minheapOK(a->esq);
        else if(a->valor < a->dir->valor) minheapOK(a->dir);
        else return 0;
    }
}

int max(int x, int y) {
    return (x > y) ? x : y;
}


int maxHeap (ABin a) {
    int l = a->esq ? maxHeap(a->esq) : a->valor;
    int r = a->dir ? maxHeap(a->dir) : a->valor;
    return max(l,r);
}

void removeMin (ABin *a) {
    if(!((*a)->esq)) {
        ABin aux = (*a);
        free(*a);
        *a = aux->dir;
    }
    else if(!((*a)->dir)) {
        ABin aux = (*a);
        free(*a);
        *a = aux->esq;
    } 
    else if((*a)->esq->valor < (*a)->dir->valor) {
        (*a)->valor = (*a)->esq->valor;
        removeMin(&((*a)->esq));
    }
    else {
        (*a)->valor = (*a)->dir->valor;
        removeMin(&((*a)->dir));
    }
}

void add (ABin*a, int x);


void heapSort (int v[], int N) {
    //criar a minheap auxiliar
    ABin aux = NULL;
    if(N == 0) aux = NULL;
    for(int i = 0; i < N; i++) add(aux,v[i]);
    for(int i = 0; i < N; i++) {
        v[i] = aux->valor;
        removeMin(aux);
    }
}

