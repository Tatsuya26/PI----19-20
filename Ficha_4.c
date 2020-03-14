#include <stdio.h>
#include <ctype.h>
 #include <string.h>

int contalinhas (char s[]) {
    int  c = s[0] != '\0';
    for (int i = 0 ; s[i] != '\0' ; i++) {
        if (s[i] == '\n') c ++;
    }
    return c;
}

int minisculas (char s[]) {
    int i, acc = 0; 
    for (int i = 0; s[i] != '\0'; i++) { 
        if (  s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32 ;
            acc++;
        }
        printf("%c",s[i]); 
}
    return acc;
}

int contaPal (char s[]) {
    int c = 0;
    for (int i = 0 ; s[i] != '\0' ; i++ ) {
        if ( isspace (s[i]) != 0) {
            c++;    
        } 
    }
    printf ("%d\n", c);
    return c;
}
int procura (char *p , char *ps[], int N) {
    int i;
    for( i = 0 ; i < N ; i++) {
        if (strcmp(p,ps[i])== 0){
            return 1;
        }
    }
    return 0;
}

// Exercicio 5 
#define MAX 100 
typedef struct stack {
    int sp;
    int valores [MAX];
} STACK ;

// a) inicializa uma stack - dizer que o apontador passa zero. 

void initStack (STACK *s) {
    s -> sp = 0; 
}

// b) teste se uma stactk é vazia - o array valores tem de ter dimensão 0. 


// c) 

int push (STACK *s , int x) {
    if (s -> sp >= 100) return 1;
    s -> valores[s -> sp] = x;
    (s -> sp)++;
    return 0;
}

int main () {    
    //contaPal (s);
    //if ((procura (s,g,1)) == 1) printf ("Tem palavras repetidas\n" );
    //else printf("Não tem palavras repetidas.\n");
    return 0;
}
