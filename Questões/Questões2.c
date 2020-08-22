#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

// EX 1
int length (LInt l){
    LInt pt;
    int length = 0;
    for(pt = l;pt; pt = pt->prox) length++;
    return length;
}

//EX 2
void freeL (LInt l) {
    while(l) {
        LInt temp = l;
        l = l->prox;
        free(temp);
    }
}

//EX 3
void imprimeL (LInt l) {
    if(!l) printf("A Lista é vazia\n");
    else {
    LInt pt;
        putchar('[');
        for(pt = l; pt->prox; pt = pt->prox) printf("%d ,", pt->valor);   
        printf("%d]\n",pt->valor);
    }
}

//EX 4
LInt reverseL (LInt l){
    LInt l2 = NULL;
    if(l) {
        l2 = l->prox;
        l->prox = NULL;
        while(l2) {
            LInt temp = l2->prox;//guardar o prox
            l2->prox = l; // colocar o prox a apontar para o anterior
            l = l2;// defenir o inicio no elemento trocado
            l2 = temp; // voltar a variavel de sitio o resto da lista para inverter
        }
    }
    return l;
}

//EX 5
void insertOrd (LInt *l, int x){
    LInt new, ant = NULL;
    new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    for(;*l ; ant = (*l), l =&((*l)->prox)) ;
    if(ant){        
        new->prox = *l;
        ant->prox = new;
    }
    else {
        new->prox = (*l); 
        *l = new;
    }
}

//EX 6
int removeOneOrd (LInt *l, int x){
    int r = 0;
    LInt ant = NULL;
    for(;*l && (*l)->valor != x; ant = *l, l = &((*l)->prox));
    if(!(*l)) r = 1;
    else if(!ant) *l = (*l)->prox;
    else {
        LInt temp = *l;
        ant->prox = (*l)->prox;
        free(temp);
    }
    return r;
}

//ex 7
void merge (LInt *r, LInt l1, LInt l2){
    LInt aux = *r;
    if(!l1 && !l2) return;
    else if(!l1 && l2) *r = l2;
    else if(l1 && !l2) *r = l1;
    else if(l1->valor > l2->valor ||!l1 && l2 ) {
        *r = l2;
        merge(&((*r)->prox),l1,l2->prox);
    }
    else {
        *r = l1;
        merge(&((*r)->prox),l1->prox,l2
        );
    }
}

//ex 8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    if(!l) return;
    else {
        if(l->valor < x) {
            *mx = l;
            *Mx = NULL;
            splitQS(l->prox,x,&((*mx)->prox),Mx);
        } else {
            *Mx = l;
            *mx = NULL;
            splitQS(l->prox,x,mx,&((*Mx)->prox));
        }
    }
}

//EX 9
LInt parteAmeio (LInt *l){
    LInt pt;
    int i,len = 0;
    for(pt = *l; pt; pt = pt->prox) len++;
    if(len < 2) return NULL;
    LInt inicio = *l,fim = NULL;
    for(*l, i = 0; i < len/2; i++, fim = *l, *l = (*l)->prox);
    fim->prox = NULL;
    return inicio;
}

//EX 10
int removeAll (LInt *l, int x){
    int r = 0;
    LInt ant = NULL, aux;
    while(*l) {
        if((*l)->valor == x) {
            if(!ant) *l = (*l)->prox;
            else ant->prox = (*l)->prox;
            r++;
        } else {
            ant = *l;
            l = &((*l)->prox);
        }
    }
    return r;
}

//EX 11
int removeDups (LInt *l){
    int r = 0;
    LInt next,ant = NULL;
    while(*l) {
        ant = *l;
        next = (*l)->prox;
        while(next) {
            if(next->valor == (*l)->valor) {
                ant->prox = next->prox;
                r++;
                next = ant->prox;
            }
            else {
                ant = next;
                next = next->prox;
            }
        }
        l = &((*l)->prox);
    }
    return r;
}

//ex 12
int removeMaiorL (LInt *l){
    LInt antMaior = NULL, Maior = *l, ant = NULL, acc =(*l);
    int num = (*l)->valor;
    for(; acc; ant = acc, acc = acc->prox) {
        if(acc->valor > num) {
            num = acc->valor;
            Maior = acc;
            antMaior = ant;
        }
    }
    if(!ant) *l = (*l)->prox;
    else antMaior->prox = Maior->prox;
    return num;
}

//ex 13
void init (LInt *l){
    for(; (*l)->prox; l = &((*l)->prox));
    *l = NULL;
}

//ex 14
void appendL (LInt *l, int x){
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox  = NULL;
    for(;(*l); l = &((*l)->prox));
    (*l) = new;
}

//ex 15
void concatL (LInt *a, LInt b){
    for(; *a; a = &((*a)->prox));
    *a = b;
}

//ex 16
LInt cloneL (LInt l) {
    LInt pt,new, inicio = NULL;
    if(l) {
        new = malloc(sizeof(struct lligada));
        inicio = new;
        for(pt = l; pt; pt = pt->prox) {
            new->valor = pt->valor;
            if(pt->prox == NULL) new->prox= NULL;
            else new->prox =  malloc(sizeof(struct lligada));
            new = new->prox;
        }
    }
    return inicio;
} 

//ex 17
LInt cloneRev (LInt l){
    LInt pt = l, new, ant = NULL;
    for(pt = l; pt; pt = pt->prox) {
        new = malloc(sizeof(struct lligada));
        new->valor = pt->valor;
        new->prox = ant;
        ant = new;
    }
    return ant;
}

//ex 18
int maximo (LInt l){
    int max = INT_MIN;
    for(;l; l = l->prox) if(l->valor > max) max = l->valor;
    return max;
}

//ex 19
int take (int n, LInt *l){
    int i,r = n;
    LInt inicio = *l;
    for(i = 0; i < n && *l; i++,l = &((*l)->prox));
    if(!(*l)) r = i;
    else {
        while(*l) {
            LInt temp = (*l)->prox;
            free(*l);
            *l = temp;
        }
    }
    return r;
}

//ex 20
int drop (int n, LInt *l){
    int i;
    for(i = 0; i < n && *l; i++) {
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }
    return i;
}

//ex 21
LInt NForward (LInt l, int N){
    for(int i = 0; i < N; i++) l = l->prox;
    return l;
}

//ex 22
int listToArray (LInt l, int v[], int N){
    int i;
    for(i = 0; i < N && l; l = l->prox, i++) v[i] = l->valor;
    return i;
}

//ex 23
LInt arrayToList (int v[], int N){
    if(N == 0) return NULL;
    else {
        LInt new = malloc(sizeof(struct lligada)), inicio;
        inicio = new;
        int i = 0;
        for(i = 0; i < N; i++) {
            new->valor = v[i];
            if(i == N - 1) new->prox = NULL;
            else new->prox = malloc(sizeof(struct lligada));
            new = new->prox;
        }
        return inicio;
    }
}

//ex 24
LInt somasAcL (LInt l) {
    if(!l) return NULL;
    else {
        LInt new = malloc(sizeof(struct lligada)), inicio = new;
        int acc = l ->valor;
        for(; l; l = l->prox) {
            new->valor = acc;
            if(!(l->prox)) new->prox = NULL;
            else {
                new->prox = malloc(sizeof(struct lligada));
                acc += l->prox->valor;
            }
            new = new->prox;
        }
        return inicio;
    }
}

//ex 25
void remreps (LInt l){
    if(l) {
        while(l->prox) {
            if(l->valor == l->prox->valor) {
                LInt temp = l->prox;
                l->prox = temp->prox;
                free(temp);
            } else l = l->prox;
        }
    }
}

//ex 26
LInt rotateL (LInt l){
    if(!l || !(l->prox)) return l;
    else {
        LInt troca = l, inicio = l->prox;
        for(; l->prox; l = l->prox);
        troca->prox = NULL;
        l->prox = troca;
        return inicio;
    }
}

//ex 27
LInt parte (LInt l){
    if(!l || !(l->prox)) return NULL;
    int i = 0;
    LInt inicio = l->prox, impares, ant = NULL;
    while(l) {
        if(i % 2 != 0) {
            impares = l;
            impares= impares->prox;
            ant->prox = l->prox; 
        }
        else {
             ant = l;
             l = l->prox;
        }
        i++;
    }
    return inicio;
}



typedef struct nodo {
	int valor;
	struct nodo *esq, *dir;
} *ABin;


//ex 28
int altura (ABin a){
    if(!a) return 0;
	return 1 + (altura(a->dir) > altura(a->esq) ? altura(a->dir) : altura(a->esq));
}

//ex 29
ABin cloneAB (ABin a) {
    if(!a) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->valor = a->valor;
    new->dir = cloneAB(a->dir);
    new->esq = cloneAB(a->esq);
    return new;
}

//ex 30
void mirror (ABin *a) {
    if(!(*a)) return;
    ABin temp = (*a)->esq;
    (*a)->esq = (*a)->dir;
    (*a)->dir = temp;
    mirror(&((*a)->esq));
    mirror(&((*a)->dir));
}

//ex 31
void inorder (ABin a, LInt * l) {
    if(!a) return;
    inorder(a->esq,l);
    while(*l) l = &((*l)->prox);
    *l = malloc(sizeof(struct lligada));
    (*l)->valor = a->valor;
    (*l)->prox = NULL;
    inorder(a->dir,&((*l)->prox));
}

//ex 32
void preorder (ABin a, LInt * l) {
    *l = NULL;
    if(!a) return;
    *l = malloc(sizeof(struct lligada));
    (*l)->valor = a->valor;
    (*l)->prox = NULL;
    preorder(a->esq,&((*l)->prox));
    while(*l) l = &((*l)->prox);
    preorder(a->dir, l);
}

//ex 33
void posorder (ABin a, LInt * l) {
    *l = NULL;
    if(!a) return;
    posorder(a->esq,l);
    while(*l) l = &((*l)->prox);
    posorder(a->dir,l);
    while(*l) l = &((*l)->prox);
    *l = malloc(sizeof(struct lligada));
    (*l)->valor = a->valor;
    (*l)->prox = NULL;
}

//ex 34
int depth (ABin a, int x) {
    if(!a) return -1;
    if(a->valor == x) return 1;
    int esq = depth(a->esq,x);
    int dir = depth(a->dir,x);
    
    if(esq == -1 && dir == -1) return -1;
    if(dir == -1) return 1 + esq;
    if(esq == -1) return 1 + dir;
    else return (esq > dir) ? 1 + dir : 1 + esq;
}

//ex 35
int freeAB (ABin a) {
    if(!a) return 0;
    int r = 1 + freeAB(a->esq) + freeAB(a->dir);
    free(a);
    return r;
}

//ex 36
int pruneAB (ABin *a, int l) {
     int r ;
     if(!(*a)) return 0;
     if(l == 0) {
         r = 1 + pruneAB(&((*a)->esq),0) + pruneAB(&((*a)->dir),0);
         free(*a);
         *a = NULL;
     }
     else  r = pruneAB(&((*a)->esq),l - 1) + pruneAB(&((*a)->dir), l - 1);
     return r;
}

//ex 37
int iguaisAB (ABin a, ABin b) {
    if(!a && !b ) return 1;
    if(!a && b || a && !b || a->valor != b->valor ) return 0;
    else return 1 && iguaisAB(a->dir,b->dir) && iguaisAB(a->esq,b->esq);
    
}

//ex 38
LInt nivelL (ABin a, int n) {
    if(!a) return NULL;
    if(n == 1) {
        LInt l = malloc(sizeof(struct lligada));
        l->valor = a->valor;
        l->prox =NULL;
        return l;
    }
    else {
        LInt esq, dir, temp;
        esq = nivelL(a->esq, n - 1);
        dir = nivelL(a->dir, n - 1);
        temp = esq;
        if(!esq) return dir;
        while(temp->prox) temp = temp->prox;
        temp->prox = dir;
        return esq;
    }
}

//ex 39
int nivelV (ABin a, int n, int v[]) {
    int esq, dir;
    if(!a || n == 0) return 0;
    if(n == 1) {
        *v = a->valor;
        return 1;
    }
    else {
        esq = nivelV(a->esq,n - 1, v);
        dir = nivelV(a->dir,n - 1, v+esq);
        return esq + dir;
        
    }
}

//40
int dumpAbin (ABin a, int v[], int N) {
    int esq, dir;
    if(N == 0 || !a) return 0;
    else {
        esq = dumpAbin(a->esq,v,N);
        if(esq < N) {
            v[esq] = a->valor;
            dir= 1 + esq + dumpAbin(a->dir,v + esq + 1, N - esq  -1);
            return dir;
        }
        else return N;
    }
}

//41
ABin somasAcA (ABin a) {
    if(!a) return NULL;
    else {
        ABin new = malloc(sizeof(struct nodo));
        new->esq = somasAcA(a->esq);
        new->dir = somasAcA(a->dir);
        new->valor = a->valor + (new->dir ? new->dir->valor : 0) + (new->esq ? new->esq->valor : 0);
        return new;
    }
}

//42
int contaFolhas (ABin a) {
    if(!a) return 0;
    if(!(a->esq) && !(a->dir)) return 1;
    else return contaFolhas(a->esq) + contaFolhas(a->dir);
}

//43
ABin cloneMirror (ABin a) {
    if(!a) return NULL;
    else {
        ABin new = malloc(sizeof(struct nodo));
        new->valor = a->valor;
        new->esq = cloneMirror(a->dir);
        new->dir = cloneMirror(a->esq);
        return new;
    }
}

//44
int addOrd (ABin *a, int x) {
    while(*a) {
        if((*a)->valor == x) return 1;
        else if((*a)->valor < x) a = &((*a)->dir); // caso menor ir para a direita
        else a = &((*a)->esq); // caso maior ir a esquerda
    } // tendo no fim do ciclo o sirio onde inserir
    ABin novo = malloc(sizeof(struct nodo));
    novo->valor = x;
    novo->esq = NULL;
    novo->dir = NULL;
    (*a) = novo;
    return 0;
}

//45
int lookupAB (ABin a, int x) {
    while(a) {
        if(a->valor == x) return 1;
        else if(a->valor > x) a = a->esq;
        else a = a->dir;
    }
    return 0;
}

//46
int depthOrd (ABin a, int x) {
    if(!a) return -1;
    if(a->valor == x) return 1;
    else {
        int acc = 0;
        if(a->valor > x) acc = depthOrd(a->esq,x);
        else acc = depthOrd(a->dir,x);
        if(acc == -1) return acc;
        else return acc + 1;
    }
}

//47
int maiorAB (ABin a) {
    int maior = a->valor;
    while(a) {
        if(a->valor > maior) {
            maior = a->valor;
        }
        if(a->dir == NULL) a = a->esq;
        else a = a->dir;
    }
    return maior;
}

//48
void removeMaiorA (ABin *a) {
    while((*a)->dir != NULL) a = &((*a)->dir);
    ABin temp = *a;
    *a = (*a)->esq;
    free(temp);
}

//49
int quantosMaiores (ABin a, int x) {
    if(!a) return 0;
    else {
        int acc = 0;
        if(a->valor > x) acc++;
        return acc + quantosMaiores(a->esq, x)+ quantosMaiores(a->dir, x);

    }
}

//50
void listToBTree (LInt l, ABin *a) {
    if(!l) return;
    LInt aux, ant = NULL;
    int len,i;
    for(aux = l, len = 0; aux; aux = aux->prox, len++);     // tamanho da lista para descobrir o meio
    for(aux = l, i = 0; i < len/2; ant = aux, aux = aux->prox, i++); // descobrir elemento no meio da lista
    
    *a = malloc(sizeof(struct nodo));      // criar nodo com o elementto que se encontra no meio
    (*a)->valor = aux->valor;
    (*a)->esq = (*a)->dir = NULL;
    
    if(ant) ant->prox = NULL;             // "Apagar" o elemento do meio e ter duas listas novas uma da esquerda(desde l até ant) e outra da direita(desde aux->prox até NULL)
    if(l != aux) listToBTree(l,&((*a)->esq));
    if(aux->prox) listToBTree(aux->prox,&((*a)->dir));
}

//51
//Criar um intervalo [MIN, MAX] em que na recursão se o valor estiver fora desse range a arvore não é de procura
int isBST(ABin a, int max, int min) {
    if(!a) return 1;
    else if(a->valor > max || a->valor < min) return 0;
    else return isBST(a->dir,max,a->valor) && isBST(a->esq,a->valor,min);
}

int deProcura (ABin a) {
    return isBST(a,INT_MAX, INT_MIN);
}