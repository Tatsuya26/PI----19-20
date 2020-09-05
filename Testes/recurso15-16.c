#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

char *mystrcpy(char s1[], const char s2[]) {
    int i = 0;
    for(i = 0; s2[i]; i++) s1[i] = s2[i];
    s1[i] = '\0';
    return s1;
}

void strnoV (char t[]){
    int i = 0, j;
    while(t[i]) {
        if(t[i] == 'A' || t[i] == 'E' || t[i] == 'I' || t[i] == 'O' || t[i] == 'U' ||
           t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u') 
           for(j = i; t[j]; j++) t[j] = t[j + 1];
        else i++;
    }
}

int dumpAbin (ABin a, int v[], int N) {
    if(!a) return 0;
    if(N == 0) return 0;
    int esq = dumpAbin(a->esq,v,N - 1);
    if(esq < N ) {
        int dir = 1 + esq + dumpAbin(a->dir, v + esq + 1,N - esq- 1);  
        return dir;
    }
    else return N;
    
}

int lookupAB (ABin a, int x) {
    while(a) {
        if(a->valor == x) return 1;
        if(a->valor < x) a = a->dir;
        else a = a->esq;
    }
    return 0;
}

///////// PARTE B ////////////

typedef struct listaP{
    char *pal;
    int cont;
    struct listaP *prox;
} Nodo, *Hist;

int inc(Hist *h, char *pal) {
    for(;*h; h = &((*h)->prox)) {
        if(strcmp((*h)->pal,pal) == 0) {
            (*h)->cont++;
            return (*h)->cont;
        }
    }
    if(!(*h)) {
        Hist new = malloc(sizeof(Nodo));
        new->pal = pal;
        new->cont = 1;
        new->prox = NULL;
        (*h) = new;
    }
}

char *remMaisFreq(Hist *h, int *count) {
    Hist maisFreq = *h, ant = NULL, antMaior = NULL;
    int acc = INT_MIN;
    char* s = NULL;
    for(;*h; ant = *h, h = &((*h)->prox)) {
        if(acc < (*h)->cont) {
            acc = (*h)->cont;
            antMaior = ant;
            maisFreq = *h; 
        }
    }
    if(!antMaior) { // caso seja lista singular
        Hist temp = *h;
        *h = (*h)->prox;
        strcpy(s,temp->pal);
        *count = temp->cont;
        free(temp);
        
    } else { // ligar o anteior ao maior com o proximo do maior
        antMaior->prox = maisFreq->prox;
        strcpy(s,maisFreq->pal);
        *count = maisFreq->cont;
        free(maisFreq);
    }
    return s;
}

void convertePal(char * s) {
    int i = 0,j;
    while(s[i]) {
        if(isAlpha(s[i]) == 0) {
            s[i] += 32;
            i++;
        }
        else if(isdigit(s[i]) == 0) for(j = i; s[j]; j++) s[j] = s[j + 1];
        else i++;
    }
}

int main() {
    int i = 0, inicio = 0;
    char texto[60];
    fgets(stdin,60,texto);
    Hist new = NULL,begin = NULL, pt = NULL;
    for(i = 0; texto[i]; i++) {
        if(texto[i] == ' ' || texto[i] == '\n') { // não e o melhor parametro para avaliar o fim de uma palavra, but XD
            inc(&new,texto[inicio]);
            inicio = i + 1;
        }
    }
    begin = new;
    pt = new;
    int len;
    while(pt) {
        convertePal(pt->pal);
        pt = pt->prox;
    }
    for(i = 0; new && i < 10; new = new->prox) {
        char s = remMaisFreq(&new,&len);
        printf("As 10 palavras mais frequentes são :\n");
        if(len > 3) {
            printf("%s\n",s);
            i++;
        }
    }
    while (begin) {
        Hist temp = begin;
        begin = begin->prox;
        free(temp);
    }
    return 0;
}