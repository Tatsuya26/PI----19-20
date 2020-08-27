#include <stdio.h>
#include <stdlib.h>
typedef struct slist {int valor;struct slist *prox;} *LInt;
typedef struct nodo {int valor;struct nodo *esq, *dir;} *ABin;


char *strcat (char s1[], char s2[]) {
    int i = 0, j = 0;
    for(i = 0; s1[i];i++);
    for(j = 0; s2[j]; j++, i++) s1[i] == s2[j];
    return s1;
}

int remRep (char x[]) {
    int i = 0,j,len;
    while(x[i]) {
        if(x[i] == x[i + 1]) for(j = i; x[j]; j++) x[j] = x[j+1];
        else i++;
    }
    for(len = 0;x[len]; len++);
    return len;
}

int nivelV(ABin a, int n, int v[]) {
    if(n == 1) {
        v = a->valor;
        return 1;
    }
    if(!a) return 0;
    else {
        int esq = nivelV(a->esq,n - 1,v);
        int dir = nivelV(a->dir,n - 1,v + esq);
        return esq + dir;
    }
}

int addOrd (ABin *a, int x) {
    while(*a) {
        if((*a)->valor == x) return 1;
        else if((*a)->valor < x) a = &((*a)->dir);
        else a = &((*a)->esq);
    }
    *a = malloc(sizeof(struct nodo));
    (*a)->valor = x;
    (*a)->esq = (*a)->dir = NULL;
    return 0;
}


///////////////Parte B ////////////////////////////
typedef struct listaC {int coluna;float valor;struct listaC *prox;} *Colunas;
typedef struct listaL {int linha;Colunas lcol;struct listaL *prox;} *Mat;

float getEntry (Mat m, int linha, int coluna) {
    for(; m; m = m->prox) {
        if(m->linha == linha) {
            for(;m->lcol; m->lcol = m->lcol->prox) {
                if(m->lcol->coluna == coluna) return m->lcol->valor;
            }
        }
    }
    return 0;
}

//dont now if this shit is correct
void setEntry (Mat *m, int linha, int coluna, float valor) {
    Colunas new = malloc(sizeof(struct listaC));
    new->coluna = coluna;
    new->valor = valor;
    new->prox = NULL;
    Mat newMatrix = malloc(sizeof(struct listaL));
    newMatrix->linha = linha;
    newMatrix->prox = NULL;
    Mat ant = NULL;
    Colunas antNew = NULL;
    for(; m; ant = *m, m = &((*m)->prox)) {
        if((*m)->linha > linha) {
            if(!ant) newMatrix->prox = *m;
            else {
                ant->prox = newMatrix;
                newMatrix->prox = *m;
            }
            for(; (*m)->lcol; ant = (*m)->lcol, m->lcol = &((*m)->lcol->prox)) {
                if((*m)->lcol->coluna > coluna) {
                    if(!antNew) new->prox = (*m)->lcol; 
                    else {
                        antNew->prox = new;
                        new->prox = (*m)->lcol;
                    }
                    break;
                }
            }   
        break;
        }
    }
}

void addTo (Mat *m1, Mat m2) {
    if(!(*m1)) return;
    for(; *m1; m1 = &((*m1)->prox)) {
        for(;(*m1)->lcol; m->lcol = &((*m)->lcol->prox)) {
            float x = getEntry(*m1,(*m1)->linha,(*m1)->lcol->coluna);
            float y = getEntry(m2,(*m1)->linha,(*m1)->lcol->coluna);
            setEntry(m1,(*m1)->linha,(*m1)->lcol->coluna, x + y);
        }
    }
}

void transpose (Mat *m) {
    if(!(*m)) return;
    for(; *m; m = &((*m)->prox)) {
        for(;(*m)->lcol; m->lcol = &((*m)->lcol->prox)) {
            float temp = (*m)->lcol->valor; 
            float change = getEntry(*m, (*m)->lcol->coluna, (*m)->linha);
            setEntry(m, (*m)->lcol->coluna, (*m)->linha, change);
            setEntry(m, (*m)->linha, (*m)->lcol->coluna, temp);
        }
    }
}