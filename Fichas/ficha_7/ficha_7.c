#include "ficha_7.h"

// 1)
//a)
LInt cons (LInt l, int x) {
    LInt novo = malloc(sizeof(struct slist));
    novo->valor = x;
    novo->prox = l;
    return novo;
}
//b)
LInt tail (LInt l) {
    LInt temp = l;
    l = l->prox;
    free(temp);
    return l;
}

//c)
LInt init (LInt l) {
    LInt pt,ant = NULL;
    for(pt = l; pt->prox; pt = pt->prox, ant = pt);
    ant->prox = NULL;
    free(pt); 
    return l;
}



void printList(LInt l) {
    LInt pt;
    putchar('[');
    for(pt = l; pt->prox; pt = pt->prox) printf("%d ,", pt->valor);   
    printf("%d]\n",pt->valor);
}
