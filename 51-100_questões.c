#include <stdio.h>
#include <stdlib.h>
typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

LInt initList() {
    LInt l = NULL;
    return l;
}

LInt insertHead(LInt l,int valor) {
    LInt l2 = malloc(sizeof(LInt));
    l2->valor = valor;
    l2->prox = l;
    return l2;
}


//51 
int length (LInt l) {
    int i, length = 0;
    for(LInt pt = l;pt ;pt = pt->prox) length++;
    return length;
}

//52
void freeL (LInt l) {
    while(l) {
        LInt pt = l;
        l = l->prox;
        free(pt);
    }
}

//53
void imprimeL (LInt l) {
    for(LInt pt = l;pt ;pt = pt->prox){
        printf("%d\n",l->valor);
    }
} 

//54 
LInt reverseL(LInt l) {
    if(l != NULL) {
        LInt l2 = l->prox;
        l->prox = NULL;
        while(l2) {
            LInt temp = l2->prox;
            l2->prox = l;
            l = l2;
            l2 = temp;
        }
    }
    return l;
}  

// 55
void insertOrd (LInt *l, int x) {
    LInt novo, aux = (*l), anterior = NULL;
    novo = malloc(sizeof(struct lligada));
    novo->valor = x;
    novo->prox = NULL;
    while(aux && aux->valor < x) {
      anterior = aux;      
      aux = aux->prox;
    }
    if(anterior == NULL) {
      novo->prox = (*l);
      *l = novo;
    } else {
      anterior->prox = novo;
      novo->prox = aux;
    }
    l = &aux;
}   

// 56
int removeOneOrd (LInt *l, int x){
  LInt aux = (*l), ant = NULL;
  for(; aux && aux->valor != x; ant = aux, aux = aux->prox);
    if(!aux) return 1;
    else if(!ant) (*l) = (*l)->prox;
    else ant->prox = aux->prox;
  return 0;
}  

//57
void merge (LInt *r, LInt l1, LInt l2) {
  if(!l1 && !l2) return;
  if(l2 == NULL || l1 != NULL && l1->valor < l2->valor) {
    (*r) = l1;
    merge(&((*r)->prox), l1->prox,l2);
  }
  else {
    (*r) = l2;
    merge(&((*r)->prox), l1,l2->prox);
    }
}

//58
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
        if(!l) return;
        if(l->valor < x) {
            (*mx) = l;
            (*Mx) = NULL;
            splitQS(l->prox,x,&((*mx)->prox),Mx);
        } else {
            (*Mx) = l;
            (*mx) = NULL;
            splitQS(l->prox,x,mx,&((*Mx)->prox));
        }
}

//59 
LInt parteAmeio (LInt *l){
    int metade = length(*l)/2, i = 0;
    if(metade == 0) return NULL;
    LInt new = (*l),fim;
    for(i = 0;i < metade; i++) {
        fim = *l;
        (*l) = (*l)->prox;
    }
    fim->prox = NULL;
    return new;
}

//60
int removeAll (LInt *l, int x){
    int numr = 0;
    LInt anterior = NULL, aux = (*l);
    while(*l) {
        if((*l)->valor == x) {
            if(!anterior) (*l) = (*l)->prox;
            else anterior->prox = (*l)->prox;
            numr++;
        } else {
            anterior = (*l);
            l = &((*l)->prox);
        }
    }
    return numr;
}