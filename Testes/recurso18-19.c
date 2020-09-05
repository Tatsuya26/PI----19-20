#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>





typedef struct nodo {
    int nlesq;
    char* linha;
    struct nodo *esq, *dir;
} *Rope;

int nlinhas(Rope r) {
    int acc = 0;
    while(r) {
        acc += r->nlesq + 1;
        r = r->dir;
    }
    return acc;
}

void print(Rope r) {
    if(!r) return;
    print(r->esq);
    printf("%s\n",r->linha);
    printf(r->dir);
}

char index(int l, int c, Rope r) {
    if(!r) return NULL;
    if(r->nlesq == l) {
        int i = 0, len = strlen(r->linha);
        char aux[len];
        strcpy(aux,r->linha);
        if(c > len) return NULL;
        while(i != c) i++;
        return aux[i];
    }
    else {

    }
}

Rope concat(Rope r1, Rope r2) {
    if(!r1 && !r2) return NULL;
    if(!r1 && r2) r1 = r2;
    else if(!r2) r2 = r1;
    else {
        strcat(r1->linha,r2->linha);
        r1->esq = concat(r1->esq,r2->esq);
        r1->dir = concat(r1->dir, r2->dir);
    }
}

int insereLinha(int l, char *str, Rope *r) {
    
}