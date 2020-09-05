#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>


typedef struct slist {int valor;struct slist *prox;} *LInt;
typedef struct nodo {int valor;struct nodo *esq, *dir;} *ABin;

void strrev(char s[]) {
    int len = 0,i;
    for(len = 0; s[len]; len++);
    for(i = 0; i < len/2; i++) {
        char temp = s[i];
        s[i] = s[len - i- 1];
        s[len - i - 1] = temp;
    }
}

int remRep(char x[]) {
    int i = 0,j, len = 0;
    while(x[i]) {
        if(x[i] == x[i + 1]) for(j = i + 1; x[j]; j++) x[j] = x[j + 1];
        else i++;
    }
    for(len = 0; x[len]; len++);
    return len;
}

void merge(int r[], int a[], int b[], int na, int nb) {
    int ia = 0, ib = 0, ir = 0;
    for(ir = 0; ir < na+nb; ir++) {
        if(a[ia] > b[ib] || ia == na) {
            r[ir] = b[ib];
            ib++;
        }
        else {
            r[ir] = a[ia];
            ia++;
        }
    }
}

int deProcuraAux(ABin a, int max, int min) {
    if(!a) return 1;
    if(a->valor > max || a->valor < min) return 0;
    else return deProcuraAux(a->esq,a->valor,min) && deProcuraAux(a->dir,max, a->valor);
}


int deProcura(ABin a) {
    return deProcuraAux(a,INT_MAX,INT_MIN);
}

int pruneAB(ABin *a, int l) {
    if(!a) return 0;
    int r;
    if(l == 0) {
        r = 1 + pruneAB(&((*a)->esq), 0) + pruneAB(&((*a)->dir), 0);
        free(*a);
        *a = NULL;
    }
    else r = pruneAB(&((*a)->esq), l - 1) + pruneAB(&((*a)->dir), l - 1);
    return r;
}


///////////////////////////////////////// Parte B ////////////////////////////////////////////7
typedef struct digito {
    unsigned char val;
    struct digito *prox;
} *Num;

Num fromInt(unsigned int i) {
    int num = i;
    num = num % 10;
    i = i / 10;
    Num new = malloc(sizeof(struct digito));
    new->val = num;
    if(i > 0) new->prox = fromInt(i);
    else new->prox = NULL;
    return new;
}

unsigned int toInt(Num n) {
    int i = 0, r = 0;
    for(; n; n = n->prox , i++) {
        if(i == 0) r += n->val;
        else r += n->val * pow(10,i);
    }
    return r;
}

Num addNum(Num a, Num b) {
    unsigned int aN = toInt(a);
    unsigned int bN = toInt(b);
    unsigned int r = aN + bN;
    return fromInt(r);
}

Num mulDig(unsigned char dig, Num a) {
    unsigned int x = toInt(a);
    unsigned int y = dig;
    x *= y;
    return fromInt(x);
}

Num mulNum(Num a, Num b) {
    return fromInt(toInt(a) * toInt(b));
}

int main() {
    Num a = fromInt(987);
    Num b = fromInt(9876);
    putchar('[');
    for(Num pt = a; pt; pt = pt->prox) printf("%d -> ",pt->val); 
    putchar(']');
    putchar('\n');

    putchar('[');
    for(Num pt = b; pt; pt = pt->prox) printf("%d -> ,",pt->val); 
    putchar(']');
    putchar('\n');

    Num r = addNum(a,b);
    putchar('[');
    for(Num pt = r; pt; pt = pt->prox) printf("%d -> ,",pt->val); 
    putchar(']');
    putchar('\n');

    Num r2 = mulDig(3,a);
    putchar('[');
    for(Num pt = r2; pt; pt = pt->prox) printf("%d -> ,",pt->val); 
    putchar(']');
    putchar('\n');

    Num r3 = mulNum(a,b);
    putchar('[');
    for(Num pt = r3; pt; pt = pt->prox) printf("%d -> ,",pt->val); 
    putchar(']');
    putchar('\n');




    return 0;
}