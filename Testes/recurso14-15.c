#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef  struct nodo {
     char nome[50];
     int numero ;
     int nota;//>=0,<=20structnodo∗e s q ,∗d i r ;} ∗Alunos ;
     struct nodo *esq ,*dir ;
} *Alunos ;


int searchTree(Alunos a, int nota) {
    if(a->nota == nota) return 1 + searchTree(a->esq, nota) + searchTree(a->dir, nota);
    if(!a) return 0;
    return searchTree(a->esq, nota) + searchTree(a->dir, nota);
}

int fnotas (Alunos a, int notas [21]) {
    int i = 0, acc = 0;
    for(i = 0; i < 21; i++) notas[i] = searchTree(a,i);
    for(i = 0; i < 21; i++) acc += notas[i];
    return acc;
}

Alunos getAluno(Alunos a, int numero) {
    if(!a) return NULL;
    if(a->numero == numero) return a;
    if(a->numero > numero) return getAluno(a->esq,numero);
    else return getAluno(a->dir,numero);
}

int rankNota (int nota, int fnotas[21]) {
    int rank = 0, len = 0 ;
    for(int i = 0; i < nota; i++) {
        rank+= fnotas[i];
    }
    if(nota != 0) rank++;
    else return 0;
    for(int i = 0; i < 21; i++) len += fnotas[i];
    return len - rank;

}

int rankAluno (Alunos a, int numero, int fnotas[21]) {
    Alunos al = getAluno(a,numero);
    if(!al) return 0;
    return rankNota(al->nota,fnotas);
}


typedef struct strlist {
    char *string;
    struct strlist *prox;   
} *StrList;


int comNota (Alunos a, int nota, StrList *l)  {
    if(!a) return 0;
    if(a->nota == nota) {
       *l = malloc(sizeof(struct strlist));
       (*l)->string = a->nome;
       (*l)->prox = NULL;
        int esq = comNota(a->esq,nota,&((*l)->prox));
        while(*l) l = &((*l)->prox);
        int dir = comNota(a->esq,nota,l);
        return 1 +  dir + esq;
    }
    else {
        int esq = comNota(a->esq,nota,l);
        while(*l) l = &((*l)->prox);
        int dir = comNota(a->esq,nota,l);
        return dir + esq;
}

Alunos getAlunoNota(Alunos a, int nota) {
    if(!a) return NULL;
    if(a->nota == numero) return a;
    Aluno a1 = getAlunoNota(a->dir,nota);
    Aluno a2 = getAlunoNota(a->esq,nota);
    if(!a1) return a2;
    else return a1;
}

void preenche (Alunos a, Alunos t[], int freq[21]) {
    int quantos = fnotas(a,freq),i = quantos;
    int nota = 20;
    while(i < quantos) {
        while(freq[nota] < 0) {
            t[i] = getAlunoNota(a,nota);
            i++;
        }
        nota--; 
    }
}