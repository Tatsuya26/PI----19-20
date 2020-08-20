#include "ficha_7.h"

// 1)
//a)
LInt cons (LInt l, int x) {
    LInt novo = malloc(sizeof(struct slist));
    novo->valor = x;
    novo->prox = l;
    return novo;
}
//b)
LInt tail (LInt l) {
    if(!l) return NULL;
    else {
        LInt temp = l;
        l = l->prox;
        free(temp);
        return l;
    }
}

//c)
LInt init (LInt l) {
    if(!l) return NULL;
    else {
        LInt pt,ant = NULL;
        for(pt = l; pt->prox; ant = pt, pt = pt->prox);
        free(pt);
        ant->prox = NULL; 
        return l;
    }
}


//d)
LInt snoc (LInt l, int x) {
    LInt pt , new = malloc(sizeof(struct slist));
    new->valor = x;
    new->prox = NULL;
    for(pt = l; pt->prox; pt = pt->prox);
    pt->prox = new;
    return l;
}

//e)
LInt concat (LInt a, LInt b) {
    LInt pt;
    for(pt = a; pt->prox;pt = pt->prox);
    pt->prox = b;
    return a;
}

///////////////////////////////////////////////////////  Ex 2    ///////////////////////////////////////////////////////////////////////

int acrescentaAluno (Turma *t, Aluno a) {
    int r = 1;
    Turma* new = malloc(sizeof(struct Turma));
    new->aluno = a;
    new->prox = NULL;
    if(t == NULL) {
        t = new;
        r = 0;
    }
    else {
        Turma *pt, *ant;
        for(pt = t; pt; ant = pt, pt = pt->prox) {
            if(pt->aluno.num > a.num) {
                ant->prox = new;
                new->prox = pt;
                r = 0;
                break;
            }
        }
    }
    if(r == 1) {
        t = new;
        r = 0;
    }
    return r;
}

Aluno *procura (Turma *t, int numero) {
    Aluno *al = 0;
    for(Turma *pt = t; pt; pt = pt->prox) {
        if(numero == pt->aluno.num) {
            al = &(pt->aluno);
            break;
        }
    }
    return al; 
}


//////////////////////////////////////////////////////////////////    EX 3      //////////////////////////////////////////////////////
void initStack (Stack *s) {
    *s = NULL;
}

int isEmptyS (Stack *s) {
    int r = 1;
    if(!(*s)) r = 0;
    return r;
}

Stack push (Stack *s, int x) {
    Stack new = malloc(sizeof(struct slist));
    new->valor = x;
    new->prox = *s;
    return new;
}

int pop (Stack *s, int *x) {
    if(isEmptyS(s)) return 0;
    else {
        *x = (*s)->valor;
        Stack temp = *s;
        *s = (*s)->prox;
        free(temp);
        return 1;
    }
}

int top (Stack *s, int *x) {
    if(isEmptyS(s)) return 0;
    else {
        *x = (*s)->valor;
        return 1;
    }
}


//////////////////////////////////////////////////       EX 5             ////////////////////////////////////////////////////////////////

void inicio (DLInt *l) {
    for(; (*l); l = &((*l)->ant));
}

void fim (DLInt *l) {
    for(; (*l); l = &((*l)->prox));
}


void concat2 (DLInt *a, DLInt b) {
    DLInt pt;
    for(pt = *a; pt->prox; pt->prox);
    pt->prox = b;
    b->ant = pt;
}

LInt toLInt (DLInt l) {
    if(!l) return NULL;
    else {
        LInt new  = malloc(sizeof(struct slist)), inicio = new;
        while(l) {
            new->valor = l->valor;
            if(!(l->prox)) new->prox = NULL;
            else new->prox = malloc(sizeof(struct slist));
            l = l->prox;
            new = new->prox;
        }
        return inicio;
    }
}

DLInt fromLInt (LInt l) {
    if(!l) return NULL;
    else {
        DLInt new  = malloc(sizeof(struct dlist)), inicio = new, ant = NULL;
        while(l) {
            new->valor = l->valor;
            new->ant = ant;
            ant = l;
            if(!(l->prox)) new->prox = NULL;
            else new->prox = malloc(sizeof(struct slist));
            new = new->prox;
            l = l->prox;
        }
        return new;
    }
}


///////////////////////////////////////////////// FUNÇOES AUXILIARES   ///////////////////////////////////////////////////////////

LInt copyList(LInt l) {
    if(l == NULL) return NULL;
    else {
        LInt new = malloc(sizeof(struct slist)), in;
        in = new;
        for(LInt pt = l; pt; pt = pt->prox) {
            new->valor = pt->valor;
            if(pt->prox != NULL) {
                new->prox = malloc(sizeof(struct slist));
                new = new->prox;
            }
            else new->prox = NULL;
        }
    return in;
    }
}

void printList(LInt l) {
    if(!l) printf("A Lista é vazia\n");
    else {
    LInt pt;
        putchar('[');
        for(pt = l; pt->prox; pt = pt->prox) printf("%d ,", pt->valor);   
        printf("%d]\n",pt->valor);
    }
}

LInt createList(int dim) {
    if(dim != 0) {
        int num;
        LInt new = malloc(sizeof(struct slist)),in = new;
        for(int i = 0; i < dim; i++) {
            printf("Insira o %dº elemento:\n",i);
            scanf("%d",&num);
            new->valor = num;
            if(i == dim - 1) new->prox = NULL;
            else new->prox = malloc(sizeof(struct slist));
            new = new->prox;
        }
        return in;
    }
    else return NULL;
}

Aluno createAluno(char s[], int num, int nota) {
    Aluno* new = malloc(sizeof(struct Aluno));
    strcpy(new->nome,s);
    new->nota = nota;
    new->num = num;
    return *new;
}

void printAluno(Aluno a) {
    printf("Nome : %s\n", a.nome);
    printf("Nota: %d\n", a.nota);
    printf("Numero de Aluno: %d\n", a.num);
}

void printTurma(Turma *t) {
    Turma* pt;
    for(pt = t;pt; pt = pt->prox) {
        printf("--------------------------------------------------------------------------------\n");
        printAluno(pt->aluno);
        printf("--------------------------------------------------------------------------------\n");
    }
}

Aluno getAluno(Aluno aluno) {
    char s[60];
    int num,nota;
    printf("Insira o nome :\n");
    fgets(s,60,stdin);
    printf("Introduza sua nota :\n");
    scanf("%d", &nota);
    printf("Introduza o seu numero de aluno :\n");
    scanf("%d", &num);
    strcpy(aluno.nome,s);
    aluno.nota = nota;
    aluno.num = num;
    return aluno;
}

void printStack(Stack s) {
    if(!s) printf("A Lista é vazia\n");
    else {
        LInt pt;
        putchar('[');
        for(pt = s; pt->prox; pt = pt->prox) printf("%d ,", pt->valor);   
        printf("%d]\n",pt->valor);
    }
}