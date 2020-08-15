#include <stdio.h>
#include <stdlib.h>

typedef struct slist *LInt;

typedef struct slist {
    int valor;
    LInt prox;
} Nodo;

//ex 1
//a) 
LInt cons (LInt l, int x) ;

//b)
LInt tail (LInt l) ;

//c)
LInt init (LInt l);

// funções aux
void printList(LInt l);