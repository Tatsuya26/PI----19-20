#ifndef ___ficha4___
#define ___ficha4___
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//ex 1
int minusculas(char s[]);

//ex 2
int contalinhas (char s[]);

//Ex 3
int contaPal (char s[]);
//ex 4
int procura (char *p, char *ps[], int N);

// Tipo de dados ex 5
#define MAX 100
typedef struct stack {
    int sp;
    int valores [MAX];
} STACK;

//a)
void initStack (STACK *s);

//b)
int isEmptyS (STACK *s);

//c)
int push (STACK *s, int x);

//d)
int pop (STACK *s, int *x);

//e)
int top (STACK *s, int *x);

#endif