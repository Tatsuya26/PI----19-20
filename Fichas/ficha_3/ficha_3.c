#include "ficha_3.h"

// ex 2
void swapM (int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// ex 3
void swap (int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

//ex 4
int soma (int v[], int N) {
    int result = 0;
    for(int i = 0; i < N; i++) result += v[i];
    return result;
}

//ex 5
int maximum (int v[], int N, int *m) {
    int max = v[0];
    for(int i = 1; i < N; i++) 
        if(v[i] > max) max = v[i];
    *m = max;
    return max;
}

//ex 6
void quadrados (int q[], int N) {
    int quadrados = 1;
    for(int i = 0; i < N; i++, quadrados++) q[i] = pow(quadrados,2);
}

//ex 7
int factorial(int x) {
    int result = 1;
    for(int i = 1; i <= x; i++)  result *= i;
    return result;
}
void pascal (int v[], int N) {
    int indice = N - 1;
    for(int i = 0; i < N; i++) 
        v[i] = factorial(indice) / (factorial(i) * factorial(indice - i));   
}
