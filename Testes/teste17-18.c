#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct slist {int valor;struct slist *prox;} *LInt;
typedef struct nodo {int valor;struct nodo *esq, *dir;} *ABin;

int retiraNeg (int v[], int N) {
    int i = 0, j;
    while(i < N) {
        if(v[i] < 0) {
            for(j = i; j < N; j++) v[j] = v[j + 1];
            N--;
        }
        else i++;
    }
    return N;
}

int difConsecutivos(char s[]) {
    int counter = 1, maiorCounter = 1;
    if(!s) return 0;
    for(int i = 0; s[i]; i++) {
        if(s[i] != s[i + 1]) {
            counter++;
            if(counter > maiorCounter) maiorCounter = counter;
        } 
        else counter = 1;
    }
    return counter;
}

int maximo (LInt l) {
    int max = INT_MIN;
    for(; l; l = l->prox) if(l->valor > max) max = l->valor;
    return max;
}

int removeAll (LInt *l, int x) {
    LInt ant = NULL;
    int deleted = 0;
    while(*l) {
        if((*l)->valor == x) {
            if(!ant) l = &((*l)->prox);
            else ant->prox = (*l)->prox;
            deleted++;
        }
        else {
            ant = *l;
            l = &((*l)->prox);
        }
    }
    return deleted;
} 

LInt arrayToList (int v[], int N) {
    if(N == 0) return NULL;
    LInt new = malloc(sizeof(struct slist)), inicio = new;
    for(int i = 0; i < N; i++) {
        new->valor = v[i];
        if(i == N-1) new->prox = NULL;
        else new->prox = malloc(sizeof(struct slist));
        new = new->prox;
    }
    return inicio;
}

///////////// PARTE B ///////////////////
int minheapOKAux(ABin a, int root) {
    if(!a) return 1;
    else {
        if(a->valor < root) return 0;
        else return 1 && minheapOKAux(a->esq,a->valor) && minheapOKAux(a->dir,a->valor);
    }
}
int minheapOK (ABin a) {
    return minheapOKAux(a,INT_MIN);
}

int maxHeap (ABin a) {
    if(!(a->dir) && !(a->esq)) return a->valor;
    if(!a) return 0;
    else {
        int esq = maxHeap(a->esq);
        int dir = maxHeap(a->dir);
        return ((esq > dir) ? dir : esq);
    }
}


void removeMin (ABin *a) {
    if(!((*a)->dir)) {
        ABin temp = (*a);
        (*a) = (*a)->esq;
        free(temp);
    }
    else if(!((*a)->esq)) {
        ABin temp = (*a);
        (*a) = (*a)->dir;
        free(temp);
    } 
    else if((*a)->esq->valor < (*a)->dir->valor) {
        *a = (*a)->esq;
        removeMin(&((*a)->esq));    
    }
    else {
        *a = (*a)->dir;
        removeMin(&((*a)->dir));    
    }

}

void heapSort (int v[], int N)  {
    ABin new = malloc(sizeof(struct nodo));
    for(int i = 0; i < N; i++) add(&new,v[i]);
    for(int i = 0; i < N; i++) {
        v[i] = new->valor;
        removeMin(&new);
    }
} 

int kMaior (int v[], int N, int k) {
    ABin new = malloc(sizeof(struct nodo));
    for(int i = 0; i < N && i < k; i++) {
        if(i < k) add(&new,v[i]);
        else {
            if(v[i] > new->valor) {
                add(&new,v[i]);
                removeMin(&new);     
            }
        }
    }
    return new->valor;
}