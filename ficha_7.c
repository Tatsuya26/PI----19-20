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
    //a)

typedef struct aluno *a; //apontador para a struct do aluno

typedef struct aluno {  //struct com as informações do aluno
    char nome[4];
    int numAluno, nota;
} Aluno;

typedef struct turma *tp; // apontador para a struct Da turma

typedef struct turma {    // struct da turma que aponta para uma struct de alunos 
    Aluno alunoAtual;
    tp proximoAluno;  
} Nodoturma;

// b) 

int acrescentaAluno (Nodoturma *t, Aluno a) {
    tp temp = t, novo = malloc(sizeof(Nodoturma));
    novo->alunoAtual = a;
    novo->proximoAluno = NULL;
    while(temp->proximoAluno) temp = temp->proximoAluno;   
    temp->proximoAluno = novo; 
    return t;
}

// c)
Aluno *procura (Nodoturma t, int numero) {
    tp r = NULL;
    while(t.proximoAluno) 
        if(t.alunoAtual.numAluno == numero) r = t.alunoAtual.numAluno;
    return r;
}

int main() {
  Aluno a1 = {"JBB",1,14};
  Aluno a2 = {"JCR",1,14};
  Aluno a3 = {"TLA",1,14};
  tp turma;
  turma = malloc(sizeof(Nodoturma));
  turma->alunoAtual = a1;
  turma->proximoAluno = malloc(sizeof(Nodoturma));
  turma->proximoAluno->alunoAtual = a2;
  turma->proximoAluno->proximoAluno = NULL;
  
  acrescentaAluno(turma,a3);
  free(turma);
  
  return 0;
}