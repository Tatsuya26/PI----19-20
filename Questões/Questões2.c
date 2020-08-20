#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

// EX 1
int length (LInt l){
    LInt pt;
    int length = 0;
    for(pt = l;pt; pt = pt->prox) length++;
    return length;
}

//EX 2
void freeL (LInt l) {
    while(l) {
        LInt temp = l;
        l = l->prox;
        free(temp);
    }
}

//EX 3
void imprimeL (LInt l) {
    if(!l) printf("A Lista é vazia\n");
    else {
    LInt pt;
        putchar('[');
        for(pt = l; pt->prox; pt = pt->prox) printf("%d ,", pt->valor);   
        printf("%d]\n",pt->valor);
    }
}

//EX 4
LInt reverseL (LInt l){
    LInt l2 = NULL;
    if(l) {
        l2 = l->prox;
        l->prox = NULL;
        while(l2) {
            LInt temp = l2->prox;//guardar o prox
            l2->prox = l; // colocar o prox a apontar para o anterior
            l = l2;// defenir o inicio no elemento trocado
            l2 = temp; // voltar a variavel de sitio o resto da lista para inverter
        }
    }
    return l;
}

//EX 5
void insertOrd (LInt *l, int x){
    LInt new, ant = NULL;
    new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    for(;*l ; ant = (*l), l =&((*l)->prox)) ;
    if(ant){        
        new->prox = *l;
        ant->prox = new;
    }
    else {
        new->prox = (*l); 
        *l = new;
    }
}

//EX 6
int removeOneOrd (LInt *l, int x){
    int r = 0;
    LInt ant = NULL;
    for(;*l && (*l)->valor != x; ant = *l, l = &((*l)->prox));
    if(!(*l)) r = 1;
    else if(!ant) *l = (*l)->prox;
    else {
        LInt temp = *l;
        ant->prox = (*l)->prox;
        free(temp);
    }
    return r;
}

//ex 7
void merge (LInt *r, LInt l1, LInt l2){
    LInt aux = *r;
    if(!l1 && !l2) return;
    else if(!l1 && l2) *r = l2;
    else if(l1 && !l2) *r = l1;
    else if(l1->valor > l2->valor ||!l1 && l2 ) {
        *r = l2;
        merge(&((*r)->prox),l1,l2->prox);
    }
    else {
        *r = l1;
        merge(&((*r)->prox),l1->prox,l2
        );
    }
}

//ex 8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    if(!l) return;
    else {
        if(l->valor < x) {
            *mx = l;
            *Mx = NULL;
            splitQS(l->prox,x,&((*mx)->prox),Mx);
        } else {
            *Mx = l;
            *mx = NULL;
            splitQS(l->prox,x,mx,&((*Mx)->prox));
        }
    }
}

//EX 9
LInt parteAmeio (LInt *l){
    LInt pt;
    int i,len = 0;
    for(pt = *l; pt; pt = pt->prox) len++;
    if(len < 2) return NULL;
    LInt inicio = *l,fim = NULL;
    for(*l, i = 0; i < len/2; i++, fim = *l, *l = (*l)->prox);
    fim->prox = NULL;
    return inicio;
}

//EX 10
int removeAll (LInt *l, int x){
    int r = 0;
    LInt ant = NULL, aux;
    while(*l) {
        if((*l)->valor == x) {
            if(!ant) *l = (*l)->prox;
            else ant->prox = (*l)->prox;
            r++;
        } else {
            ant = *l;
            l = &((*l)->prox);
        }
    }
    return r;
}

//EX 11
int removeDups (LInt *l){
    int r = 0;
    LInt next,ant = NULL;
    while(*l) {
        ant = *l;
        next = (*l)->prox;
        while(next) {
            if(next->valor == (*l)->valor) {
                ant->prox = next->prox;
                r++;
                next = ant->prox;
            }
            else {
                ant = next;
                next = next->prox;
            }
        }
        l = &((*l)->prox);
    }
    return r;
}

//ex 12
int removeMaiorL (LInt *l){
    LInt antMaior = NULL, Maior = *l, ant = NULL, acc =(*l);
    int num = (*l)->valor;
    for(; acc; ant = acc, acc = acc->prox) {
        if(acc->valor > num) {
            num = acc->valor;
            Maior = acc;
            antMaior = ant;
        }
    }
    if(!ant) *l = (*l)->prox;
    else antMaior->prox = Maior->prox;
    return num;
}

//ex 13
void init (LInt *l){
    for(; (*l)->prox; l = &((*l)->prox));
    *l = NULL;
}

//ex 14
void appendL (LInt *l, int x){
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox  = NULL;
    for(;(*l); l = &((*l)->prox));
    (*l) = new;
}

//ex 15
void concatL (LInt *a, LInt b){
    for(; *a; a = &((*a)->prox));
    *a = b;
}

//ex 16
LInt cloneL (LInt l) {
    LInt pt,new, inicio = NULL;
    if(l) {
        new = malloc(sizeof(struct lligada));
        inicio = new;
        for(pt = l; pt; pt = pt->prox) {
            new->valor = pt->valor;
            if(pt->prox == NULL) new->prox= NULL;
            else new->prox =  malloc(sizeof(struct lligada));
            new = new->prox;
        }
    }
    return inicio;
} 

//ex 17
LInt cloneRev (LInt l){
    LInt pt = l, new, ant = NULL;
    for(pt = l; pt; pt = pt->prox) {
        new = malloc(sizeof(struct lligada));
        new->valor = pt->valor;
        new->prox = ant;
        ant = new;
    }
    return ant;
}

//ex 18
int maximo (LInt l){
    int max = INT_MIN;
    for(;l; l = l->prox) if(l->valor > max) max = l->valor;
    return max;
}

//ex 19
int take (int n, LInt *l){
    int i,r = n;
    LInt inicio = *l;
    for(i = 0; i < n && *l; i++,l = &((*l)->prox));
    if(!(*l)) r = i;
    else {
        while(*l) {
            LInt temp = (*l)->prox;
            free(*l);
            *l = temp;
        }
    }
    return r;
}

//ex 20
int drop (int n, LInt *l){
    int i;
    for(i = 0; i < n && *l; i++) {
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }
    return i;
}

//ex 21
LInt NForward (LInt l, int N){
    for(int i = 0; i < N; i++) l = l->prox;
    return l;
}

//ex 22
int listToArray (LInt l, int v[], int N){
    int i;
    for(i = 0; i < N && l; l = l->prox, i++) v[i] = l->valor;
    return i;
}

//ex 23
LInt arrayToList (int v[], int N){
    if(N == 0) return NULL;
    else {
        LInt new = malloc(sizeof(struct lligada)), inicio;
        inicio = new;
        int i = 0;
        for(i = 0; i < N; i++) {
            new->valor = v[i];
            if(i == N - 1) new->prox = NULL;
            else new->prox = malloc(sizeof(struct lligada));
            new = new->prox;
        }
        return inicio;
    }
}

//ex 24
LInt somasAcL (LInt l) {
    if(!l) return NULL;
    else {
        LInt new = malloc(sizeof(struct lligada)), inicio = new;
        int acc = l ->valor;
        for(; l; l = l->prox) {
            new->valor = acc;
            if(!(l->prox)) new->prox = NULL;
            else {
                new->prox = malloc(sizeof(struct lligada));
                acc += l->prox->valor;
            }
            new = new->prox;
        }
        return inicio;
    }
}

//ex 25
void remreps (LInt l){
    if(l) {
        while(l->prox) {
            if(l->valor == l->prox->valor) {
                LInt temp = l->prox;
                l->prox = temp->prox;
                free(temp);
            } else l = l->prox;
        }
    }
}

//ex 26
LInt rotateL (LInt l){
    if(!l || !(l->prox)) return l;
    else {
        LInt troca = l, inicio = l->prox;
        for(; l->prox; l = l->prox);
        troca->prox = NULL;
        l->prox = troca;
        return inicio;
    }
}