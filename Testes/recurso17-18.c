#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct posicao {
    int x, y;
} Posicao;

typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

char *strstr (char s1[], char s2[]) {
    int i = 0, j = 0;
    char *inicio = NULL;
    for(;s1[i] && s2[j]; i++) {
        if(s1[i] == s2[j]) {
            inicio = &s1[i];
            j++;
        }
        else j = 0;
    }
    if(s1[i] == '\0' && s2[j]) return NULL;
    else return inicio;
}

void truncW (char t[], int n) {
    int i = 0, counter = 0, j;
    while(t[i]) {
        if(t[i] == ' ' || t[i] == '\n') counter = 0;
        else if(counter == n) for(j = i; t[j] && t[j] != ' '; j++) t[j] = t[j+1]; 
        else counter++;
    }
}

int dist(int x, int y) {
    return sqrt(pow(x,2)+ pow(y,2));
}

int maisCentral (Posicao pos[], int N) {
    int menorDist = INT_MAX, indice = 0;
    for(int i = 0; i < N; i++) {
        int temp = dist(pos[i].x, pos[i].y);
        if(temp < menorDist) {
            menorDist = temp;
            indice = i;
        }
    }
    return indice;
}

LInt somasAcL (LInt l) {
    if(!l) return NULL;
    int acl = 0;
    LInt new = malloc(sizeof(struct slist)), inicio = new;
    for(; l; l = l->prox) {
        acl += l->valor;
        new->valor = acl;
        if(!(l->prox)) new->prox = NULL;
        else new->prox =  malloc(sizeof(struct slist)), inicio = new;
        new = new->prox;
    }
    return inicio;
}

int addOrd (ABin *a, int x) {
    while(*a) {
        if((*a)->valor == x) return 1;
        else if((*a)->valor > x) a = &((*a)->esq);
        else  a = &((*a)->dir);
    }
    ABin new = malloc(sizeof(struct nodo));
    new->valor = x;
    new->dir = new->esq = NULL;
    return 0;
}
 

 //////////////////////////// PARTE B ////////////////////

typedef struct celula {
    char *palavra;
    int comp;
    struct celula *prox;
} *Palavras;

int daPalavra (char *s, int *e) {
    int i,counter = 0, numSpace = 0;
    *e = 0;
    for(i = 0; s[i]; i++) {
        if(isSpace(s[i]) && counter != 0) {
            *e = numSpace;
            return counter; 
        }
        else if(isSpace(s[i])) numSpace++;
        else counter++;
    }
    return counter;
}


Palavras words (char *texto) {
    if(!texto) return NULL;
    int i = 0, z,temp = 0;
    Palavras new = malloc(sizeof(struct celula)), inicio = new;
    while(texto[i]) {
        temp = 0;
        temp = daPalavra(texto, &z);
        temp += z;
        i += temp;
        new->comp = temp;
        new->palavra = &(texto[z + 1]); // sendo z o numero de espaços antes sabemos que a seguir ao num de espaços temos o inicio da palavra
        if(texto[i] != '\0') new->prox = malloc(sizeof(struct celula));
        else new->prox = NULL;
        new = new->prox;
    }
    return inicio;
}

Palavras daLinha (Palavras t, int n) {
    int len = 0;
    Palavras inicio = NULL;
    while(t) {
        if(len >= n) { 
            inicio = t->prox;
            t->prox = NULL;
            break;
        }
        else len += t->comp;
        t = t->prox;
    }
    return inicio;
}

