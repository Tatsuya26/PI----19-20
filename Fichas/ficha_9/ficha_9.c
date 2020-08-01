#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct abin {
    char *pal;
    int ocorr;
    struct abin *esq, *dir;
} *Dicionario, nodo;

//1
//void initDic (Dicionario *d)que inicializa o dicion ́ario a vazio..

void initDic (Dicionario *d) {
    d = NULL;
}

inserTree(Dicionario d,Dicionario novo) {
    if(!d) d = novo;
    else {
        inserTree(d->esq,novo);
        inserTree(d->dir,novo);
    }
}


int acrescenta (Dicionario d, char *pal) {
    int existe = 0, num = 0;
    Dicionario novo = malloc(sizeof(nodo));
    novo->pal = pal;
    novo->ocorr = 1;
    novo->esq = NULL;
    novo->dir = NULL;
    if(!d){
      d = novo;
      return 1;
    }
    if(strcmp(pal,d->pal) == 0) {
        d->ocorr++;
        existe = 1;
        return d->ocorr;
    }
    else {
        acrescenta(d->esq,pal);
        acrescenta(d->dir,pal);
    }

}
//EX2

typedef struct arvore {
    int valor;
    struct arvore *esq,*dir;
} *tree;

typedef struct lista {
    int valor;
    struct lista *prox;
} *LInt;

int length(LInt l) {
    int length = 0;
    for(LInt pt = l; pt; pt = pt->prox) length++;
    return length;
}

ABin fromList (LInt l) {
    if(!l) return NULL;
    else

}


Lint fromListN(LInt l, int N, ABin *a) {
    int length = length(l);
    if(!l) return NULL;
    
}



// exercicio 2

int main() {
    char *s = malloc(4), *c = malloc(4), *a = malloc(6),*b = malloc(4);
    s= "Ola";
    c = "xau";
    a = "ate ja"; 
    Dicionario d = malloc(sizeof(nodo));
    d->pal = s;
    d->ocorr = 1;
    d->dir = malloc(sizeof(nodo));
    d->esq = malloc(sizeof(nodo));
    d->dir->pal = c;
    d->dir->ocorr = 1;
    d->dir->dir = NULL;
    d->dir->esq = NULL;
    d->esq->pal = a;
    d->esq->ocorr = 1;
    d->esq->dir = NULL;
    d->esq->esq = NULL;
    b = "aaa";
    acrescenta(d,b);
    return 0;
}