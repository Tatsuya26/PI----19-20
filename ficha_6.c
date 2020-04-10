#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct queue {
    int inicio, tamanho;
    int valores [MAX];
} QUEUE;

//Exercício 1

// a)
void initQueue (QUEUE *q) {
    q->inicio = 0;
    q->tamanho = 0;
}

// b)
int isEmptyQ (QUEUE *q) {
    return (q->tamanho == 0);
}

int isFullQ (QUEUE *q) {
    return (q->tamanho == MAX);
}



// c)
int enqueue (QUEUE *q, int x) {
    int pos;
    if(isFullQ(q)) return 0;
    else {
        pos = (q->inicio + q->tamanho) % MAX;
        q->valores[pos] = x;
        q->tamanho++;
        return 1;
    }
}

//d)
int dequeue (QUEUE *q, int *x) {
    int i;
    if(isEmptyQ(q)) return 1;
    else {
        *x = q->valores[q->inicio];
        q->inicio = (q->inicio+1)% MAX;
        q->tamanho--;
        return 0;
    }
}

//e) 

int front (QUEUE *q, int *x) {
    int n = q->tamanho;
    if(isEmptyQ(q)) return 1;
    else *x = q->valores[q->inicio];
    return 0;
}


// Exercicio 2 - mallocs 

typedef struct queue {
int size; // guarda o tamanho do array valores
int inicio, tamanho;
int *valores;
} QUEUE2;

// a) 
void initQueue2 (QUEUE2 *q) {
    q->size = 10;
    q->inicio = 0;
    q->tamanho = 0;
    q->valores = (int*)malloc(q->size *sizeof(int));
}

// b)
int isEmptyQ2 (QUEUE2 *q) {
    return (q->tamanho == 0);
}

int isFullQ (QUEUE2 *q) {
    return (q->tamanho == q->size);
}


// c) 
// Função que duplica uma queue atraves do uso de um apontador auxiliar t no qual é allocado o dobro da memoria da queue passada como parametro.
int duplicateQueue (QUEUE2 *q) {
    int r = 1,i;
    int *t = malloc(2*q->size*sizeof(int));
    if(*t == NULL) r = 0;
    else {
        for(i = 0;i < q->tamanho++; i++) t[i] = q->valores[i]; // Passagem do conteudo do array da queue antiga para a variavel temp
         free(q->valores);                                    // Libertar o espaço em memoria antigo utilizado pelo array
         q->valores = t;                                     // Colocar o apontador antigo a apontar para o novo apontador
         q->size *=2;                                       // Duplicar o tamanho
    }
    return r;
}


int enqueue (QUEUE2 *q, int x) {
    int pos,r = 0;
    if(isFullQ(q)) r = duplicateQueue(q);           // verifica se a queue está cheia, caso esteja duplica a queue e coloca em r se a operação foi bem sucedida ou não
    if(r) {                                        // Caso a duplicação tenha corrido bem 
        pos = (q->inicio + q->tamanho) % q->size; // calculo da posição a inserir
        q->valores[pos] = x; 
        q->tamanho++;
    }
    return r;
}

//d) 
int dequeue2 (QUEUE2 *q, int *x) {
    int r = 1;
    if(!isEmptyQ(q)) {
        r = 0;
       *x = q->valores[q->inicio];
        q->inicio = (q->inicio+1) % q->size;
        q->tamanho--;
    }
    return r;       
}