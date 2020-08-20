#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct slist *LInt;

typedef struct slist {
    int valor;
    LInt prox;
} Nodo;

//////////////////////////////////////////       ex 1       /////////////////////////////////////////

//a) 
LInt cons (LInt l, int x) ;

//b)
LInt tail (LInt l) ;

//c)
LInt init (LInt l);

//b)
LInt snoc (LInt l, int x);

//e)
LInt concat (LInt a, LInt b);

//////////////////////////////////////////       ex 2       /////////////////////////////////////////

typedef struct Aluno {
    char nome[60];
    int num;
    int nota;
} Aluno;

typedef struct Turma {
    Aluno aluno;
    struct Turma *prox;
} Turma;

int acrescentaAluno (Turma *t, Aluno a);

//////////////////////////////////////////       ex 3        /////////////////////////////////////////
typedef LInt Stack;

void initStack (Stack *s);
int isEmptyS (Stack *s);
int top (Stack *s, int *x);
Stack push (Stack *s, int x);
int pop (Stack *s, int *x);

//////////////////////////////////////////       ex 5       /////////////////////////////////////////
typedef struct dlist *DLInt;

typedef struct dlist {
    int valor;
    DLInt ant, prox;
} NodoD;

void inicio (DLInt *l);
void fim (DLInt *l);
void concat2 (DLInt *a, DLInt b);


// funções aux
void printList(LInt l);
LInt copyList(LInt l) ;
LInt createList(int dim);
Aluno createAluno(char s[], int num, int nota);
void printTurma(Turma *t);
void printAluno(Aluno a);
Aluno getAluno(Aluno aluno);
Aluno *procura (Turma *t, int numero);
void printStack(Stack s);