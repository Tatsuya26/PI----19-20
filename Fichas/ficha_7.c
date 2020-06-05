#include <stdio.h>
#include <stdlib.h>

typedef struct slist *LInt;

typedef struct slist {
    int valor;
    LInt prox;
} Nodo;

// 1)
    //b)
//i)

LInt cons (LInt l, int x) {
    LInt temp = malloc(sizeof(Nodo));
    temp->valor = x;
    temp->prox = l ;
    return temp;
}

//ii) 

LInt tail (LInt l) {
    LInt temp = NULL;
    if(l != NULL) {
        temp = l->prox;
        free(l);
    }
    return temp;
}

//iii)
LInt init (LInt l) {
    LInt temp = NULL,l1 = l;
    while(l && l->prox) {
        temp = l;
        l = l->prox;
    }
    free(l);
    temp->prox = NULL;
    return l1;
}

//iv)

LInt snoc (LInt l, int x) {
    LInt novo = malloc(sizeof(Nodo));
    novo->valor = x;
    novo->prox = NULL;
    while(l->prox) {
        l = l->prox;
    }
    l->prox = novo;
    return l;
}

//V)

LInt concat (LInt a, LInt b) {
    LInt temp = a,pointer;
    if(!a) a = b;
    else {
      while(temp->prox) temp = temp -> prox;
      temp->prox = b;
    }
    return a;
}



// Exercício 2
// ex 2


typedef struct Aluno {
    char nome[6];
    int numero;
    int nota;
}*aluno;

typedef struct Turma {
    aluno a;
    struct Turma * prox;
} Nodo, *turma;

int compareTo(aluno a,aluno b) {
    if(strcmp(a->nome,a->nome) == 0 && a->numero == b->numero && a->nota == b->nota) return 1;
    else return 0;
}

aluno createAluno(char *nome, int numero, int nota) {
    aluno al = malloc(sizeof(struct Aluno));
    strcpy(al->nome,nome);
    al->numero = numero;
    al->nota = nota;
    return al;

}

int acrescentaAluno (turma *t, aluno a) {
    turma pt;
    if(!(*t)) return 1;
    else {
        for(; *t; t = &((*t)->prox)) {
            if(strcmp((*t)->a->nome,a->nome) == 0 && (*t)->a->numero == a->numero && (*t)->a->nota == a->nota) return 1;
        }
        turma new = malloc(sizeof(Nodo));
        aluno novo = createAluno(a->nome,a->numero,a->nota);
        new->a = novo;
        new->prox = NULL;
        pt->prox = new;
        return 0;
    }
}

int aprovados(turma t) {
    int aproved = 0;
    for(turma pt = t; pt; pt = pt->prox) {
        if(pt->a->nota > 10) aproved++;
    }
    return aproved;
}

int main() {
    char s[6] = "Maria", s2[6] = "pedro", s3[3] = "ze",s4[4] = "jbb";
    aluno a1 = createAluno(&s,1,19),
    a2 = createAluno(&s2,2,9),
    a3 = createAluno(&s3,3,0),
    a4 = createAluno(&s4,4,20);
    turma c = NULL;
    turma t = malloc(sizeof(Nodo));
    t->a = a1;
    t->prox = malloc(sizeof(Nodo));
    t->prox->a = a2;
    t->prox->prox = malloc(sizeof(Nodo));
    t->prox->prox->a = a3;
    t->prox->prox->prox = NULL;
    acrescentaAluno(t,a4);
    
    
    return 0;
}