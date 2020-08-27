#include <stdio.h>
#include <stdlib.h>

// Parte A
int limpaEspacos (char t[]) {
    int i = 0, j;
    while(t[i]) {
        if(t[i] == t[i + 1] && t[i] == ' ') for(j = i; t[j];j++) t[j] = t[j + 1];
        else i++;
    }
}

void transposta(int N, float m [N][N]) {
    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++) {
            float temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
}

LInt cloneL (LInt l) {
    if(!l) return NULL;
    else {
        LInt new = malloc(sizeof(struct slist)), inicio = new;
        for(; l; l = l->prox) {
            new->valor = l->valor;
            if(l->prox == NULL) new->prox = NULL;
            else new->prox = malloc(sizeof(struct slist));
            new = new->prox;
        }
    return inicio;
    }
}

int nivelV (ABin a, int n, int v[]) {
    if(!a) return 0;
    if(n == 1) {
        *v = a->valor;
        return 1;
    }
    else {
        int esq = nivelV(a->esq,n-1,v);
        int dir = nivelV(a->dir,n-1,v+esq);
        return esq + dir;
    }
}

void removeMaiorA (ABin *a) {
    while((*a)->dir) a = &((*a)->dir);
    ABin temp = *a;
    *a = (*a)->esq;
    free(temp);
}

//////////////////  PARTE B ////////////////////////////
typedef struct chunk {
    int vs [MAXc];
    struct chunk *prox;
} *CList;

typedef struct stackC {
    CList valores;
    int sp;
} StackC;

int push (StackC *s, int x) {
    if(s->sp >= MAXc) { // criar um novo array
        CList new = malloc(sizeof(struct chunk));
        new->vs[0] = x;
        new->prox = s->valores;
        s = &new;
        s->sp = 1;
    } else {
        s->valores->vs[s->sp] = x;
        s->sp++;
    }
}

int pop(StackC *s, int *x) {
    if(!(*s) || !((*s)->valores)) return 1;
    else {
        if(s->sp == 0) {
            *x = s->valores->vs[0];
            StackC temp = s;
            s->valores = s->valores->prox;
            free(temp);
        } else {
            *x = s->valores->vs[s->sp];
            s->sp--;
        }
        return 0;
    }
}

int size(StackC s) {
    if(!s) return 0;
    else {
        acc = s.sp;
        s.valores = s.valores->prox;
        for(;s; s.valores = s.valores->prox) acc += MAXc;
    }
    return acc;
}

void reverse (StackC *s) {
    
}