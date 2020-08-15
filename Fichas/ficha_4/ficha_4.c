#include "ficha_4.h"
//Ex 1
int minusculas(char s[]) {
    int r = 0;
    for(int i = 0; s[i]; i++)
        if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32; // tabela ASCII
            r++;
        }
    return r;
}

//EX 2
int contalinhas (char s[]) {
    int r = 1;
    for(int i = 0; s[i]; i++) 
            if(s[i] == '\n') r++;
    return r;
}

//Ex 3
int contaPal (char s[]) {
    int pal = 0, i, isPal = 0;
    for(i = 0; s[i]; i++) {
        if(isspace(s[i])) {
            if(isPal) pal++;
            isPal = 0;
        }
        else isPal = 1;
    }
    if(isPal) pal++;
    return pal;
}

//Ex 4
int procura (char *p, char *ps[], int N) {
    int r = 0;
    for(int i = 0; i < N; i++) 
        if(strcmp(p,ps[i]) == 0) r = 1;
    return r;
}

//Ex 5

//a) 
void initStack (STACK *s) {
    s->sp = 0;
}

//b)
int isEmptyS (STACK *s) {
    return (s->sp == 0);
}

//c)
int push (STACK *s, int x) {
    if(s->sp == 100) return 1;
    else {
        s->valores[++s->sp] = x;
        return 0;
    }
}

//d)
int pop (STACK *s, int *x) {
    if(s->sp == 0) return 1; 
    else {
        int temp = s->valores[s->sp--];
        *x = temp;
    }
}

//e)
int top (STACK *s, int *x) {
    int r = 1;
    if(isEmptyS (s)) r = 1;
    else {
        *x = s->valores[s->sp];
        r = 0;
    }
    return r;
}

STACK createSTACK() {
    STACK *s = malloc(sizeof(struct stack));
    int stackPointer;
    printf("Introduza o tamanho de valores para a sua stack: \n");
    scanf("%d", &stackPointer);
    s->sp = stackPointer;
    printf("Introduza %d valores para colocar na stack", stackPointer);
    for(int i = 0; i < stackPointer; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &(s->valores[i]));
    }
}

void printSTACK(STACK *s) {
    printf("Topo da stack: %d", s->sp);
    for(int i = s->sp; i < 0; i--) printf("valor %d da stack: %d", i,s->valores[i]);
}