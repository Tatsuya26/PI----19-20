#include <stdio.h>
#include <stdlib.h>
typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

LInt initList() {
    LInt l = NULL;
    return l;
}

LInt insertHead(LInt l,int valor) {
    LInt l2 = malloc(sizeof(LInt));
    l2->valor = valor;
    l2->prox = l;
    return l2;
}


//51 
int length (LInt l) {
    int i, length = 0;
    for(LInt pt = l;pt ;pt = pt->prox) length++;
    return length;
}

//52
void freeL (LInt l) {
    while(l) {
        LInt pt = l;
        l = l->prox;
        free(pt);
    }
}

//53
void imprimeL (LInt l) {
    for(LInt pt = l;pt ;pt = pt->prox){
        printf("%d\n",l->valor);
    }
} 

//54 
LInt reverseL(LInt l) {
    if(l != NULL) {
        LInt l2 = l->prox;
        l->prox = NULL;
        while(l2) {
            LInt temp = l2->prox;
            l2->prox = l;
            l = l2;
            l2 = temp;
        }
    }
    return l;
}  

// 55
void insertOrd (LInt *l, int x) {
    LInt novo, aux = (*l), anterior = NULL;
    novo = malloc(sizeof(struct lligada));
    novo->valor = x;
    novo->prox = NULL;
    while(aux && aux->valor < x) {
      anterior = aux;      
      aux = aux->prox;
    }
    if(anterior == NULL) {
      novo->prox = (*l);
      *l = novo;
    } else {
      anterior->prox = novo;
      novo->prox = aux;
    }
    l = &aux;
}   

// 56
int removeOneOrd (LInt *l, int x){
  LInt aux = (*l), ant = NULL;
  for(; aux && aux->valor != x; ant = aux, aux = aux->prox);
    if(!aux) return 1;
    else if(!ant) (*l) = (*l)->prox;
    else ant->prox = aux->prox;
  return 0;
}  

//57
void merge (LInt *r, LInt l1, LInt l2) {
  if(!l1 && !l2) return;
  if(l2 == NULL || l1 != NULL && l1->valor < l2->valor) {
    (*r) = l1;
    merge(&((*r)->prox), l1->prox,l2);
  }
  else {
    (*r) = l2;
    merge(&((*r)->prox), l1,l2->prox);
    }
}

//58
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
        if(!l) return;
        if(l->valor < x) {
            (*mx) = l;
            (*Mx) = NULL;
            splitQS(l->prox,x,&((*mx)->prox),Mx);
        } else {
            (*Mx) = l;
            (*mx) = NULL;
            splitQS(l->prox,x,mx,&((*Mx)->prox));
        }
}

//59 
LInt parteAmeio (LInt *l){
    int metade = length(*l)/2, i = 0;
    if(metade == 0) return NULL;
    LInt new = (*l),fim;
    for(i = 0;i < metade; i++) {
        fim = *l;
        (*l) = (*l)->prox;
    }
    fim->prox = NULL;
    return new;
}

//60
int removeAll (LInt *l, int x){
    int numr = 0;
    LInt anterior = NULL, aux = (*l);
    while(*l) {
        if((*l)->valor == x) {
            if(!anterior) (*l) = (*l)->prox;
            else anterior->prox = (*l)->prox;
            numr++;
        } else {
            anterior = (*l);
            l = &((*l)->prox);
        }
    }
    return numr;
}

//61
int removeDups (LInt *l) {
    LInt next = (*l)->prox, anterior = (*l);
    int removidos = 0;
    while(*l) {
        anterior = (*l);
        next = (*l)->prox;
        while (next) {
            if(next->valor == (*l)->valor) {
                anterior->prox = next->prox;
                removidos++;
                free(next);
                next = anterior->prox;
            } else {
                anterior = next;
                next = next->prox;
            }
        }
        l= &((*l)->prox);
    }
    return removidos;
}

//62
int removeMaiorL (LInt *l){
    int num = (*l)->valor;
    LInt antMaior = NULL, ant = NULL, maior = (*l),lista = (*l);
    while (lista) {
        if(lista->valor > num) {
            num = lista->valor;
            antMaior = ant;
            maior = lista;
        }
        ant = lista;
        lista = lista->prox;
    }
    if(!antMaior) (*l) = (*l)->prox;
    else antMaior->prox = maior->prox;
    return num;
}

//63
void init (LInt *l){
    LInt anterior= NULL;
    for(; (*l)->prox ;anterior = (*l), l = &((*l)->prox));
    if(!anterior) {
        free(*l);
        *l = NULL;
    } else {
        anterior->prox = NULL;
        free(*l);
    }
}

//64
void appendL (LInt *l, int x) {
    LInt novo;
    novo = malloc(sizeof(struct lligada));
    novo->valor = x;
    novo->prox = NULL;
    for(;*l;l = &((*l)->prox));
    if(!(*l)) *l = novo;
    else (*l)->prox = novo;
}

//65
void concatL (LInt *a, LInt b) {
    for(;*a; a = &((*a)->prox));
    if(!(*a)) *a = b;
    else (*a)->prox = b;
}

//66
LInt cloneL (LInt l) {
    LInt novo,aux;
    if(!l) aux = NULL;
    else {
        novo = malloc(sizeof(struct lligada));
        aux = novo;
        for(; l; l = l->prox, novo = novo->prox) {
            novo->valor = l->valor;
            if(!(l->prox)) novo->prox = NULL;
            else novo->prox = malloc(sizeof(struct lligada));
        }
    }
    return aux;
}
// 67
LInt cloneRev (LInt l) {
    LInt list = NULL;
    while(l) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = list;
        list = new;
        l = l->prox;
    }
    return list;
} 

// 68
int maximo (LInt l) {
    int max = l->valor;
    for(;l;l = l->prox) {
        if(l->valor > max) max = l->valor;
    }
    return max;
}

//69
int take (int n, LInt *l) {
    int i;
    for( i = 0; i < n && *l; i++,l = &((*l)->prox));
    if(!(*l)) return i;
    while(*l) {
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }
    return n;
}

//70
int drop (int n, LInt *l) {
    int i;
    for(i = 0; *l && i < n; i++) {
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }
    return i;
}

//21
LInt Nforward (LInt l, int N) {
    int i;
    for(i = 0; i < N && l;l = l->prox, i++);
    return l;
}

//22
int listToArray (LInt l, int v[], int N) {
    int i;
    for(i = 0; l && i < N; l = l->prox , i++) {
        v[i] = l->valor;
    }
    return i;
}

//23
LInt arrayToList (int v[], int N) {
    if(N==0) return NULL;
    LInt novo = malloc(sizeof(struct lligada)), aux = novo;
    for(int i = 0; i < N; i++) {
        novo->valor = v[i];
        if(i == N - 1) novo->prox =NULL;
        else novo->prox = malloc(sizeof(struct lligada));
        novo = novo->prox;
    }
    return aux;
}

//24
LInt somasAcL (LInt l) {
    if(!l) return NULL;
    int anterior = 0;
    LInt novo = malloc(sizeof(struct lligada)), aux = novo;
    if(!l) return NULL;
    for(;l; l = l->prox) {
        novo->valor = l->valor + anterior;
        anterior += l->valor;
        if(!(l->prox)) novo->prox = NULL;
        else novo->prox = malloc(sizeof(struct lligada));
        novo = novo->prox;
    }
    return aux;
}

//25 
void remreps(LInt l) {
    if(l) {
        while(l->prox) {
            if(l->prox->valor == l->valor) {
                LInt temp = l->prox;
                l->prox = temp->prox;
                free(temp);
            }
            else l = l->prox;
        }
    }
}
// 26
LInt rotateL (LInt l) {
    LInt first = l, inicio = l;
    if(!l || !(l->prox)) return l;
    if(l) {
        inicio = l->prox;
        for(; l->prox; l = l->prox);
        l->prox = first;
        first->prox = NULL;
        return inicio;
        }
    return inicio;
}

//27 
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin, tree;

int altura (ABin a) {
    int r;
    if(!a) r = 0;
    else  r = 1 + (altura(a->dir) > altura(a->esq) ? altura(a->dir) : altura(a->esq));
    return r;
}

//29
ABin cloneAB (ABin a) {
    ABin clone;
    if(a == NULL) return NULL;
    else {
        clone = malloc(sizeof(struct nodo));
        clone->valor = a->valor;
        clone->esq = cloneAB(a->esq);
        clone->dir = cloneAB(a->dir);
    }
    return clone;
} 

//30
void mirror (ABin *a) {
    if(*a){
        ABin temp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = temp;
        mirror(&((*a)->esq));
        mirror(&((*a)->dir));
    }
} 

//31
void inorder (ABin a, LInt * l) {
    *l = NULL;
    if (a) {
        inorder(a->esq, l);
        while (*l) l = &(*l)->prox;
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;
        inorder (a->dir, &(*l)->prox);
    }
}

//32
void preorder (ABin a, LInt *l) {
    *l = NULL;
    if(a) {
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;
        preorder(a->esq,&((*l)->prox));
        while (*l) l = &((*l)->prox);
        preorder(a->dir,l);
    }
}

//33
void posorder (ABin a, LInt *l) {
    *l = NULL;
    if(a) {
        posorder(a->esq,l);
        while (*l) l = &((*l)->prox);
        posorder(a->dir,l);
        while (*l) l = &((*l)->prox);
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;
    }
}


// 34
int depth (ABin a, int x) {
    if(!a) return -1;

}

//35
int freeAB (ABin a) {
    int r;
    if(!a) return 0;
    else r = 1 + freeAB(a->dir) + freeAB(a->esq);
    return r;
}




