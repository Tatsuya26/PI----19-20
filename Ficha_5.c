#include <stdio.h>
// Exercício 1

// Função que insere um elemento num array ordenado na posição correta de modo a que o array continue ordenado
void insere (int v[], int N, int x) {
    for (int i = 0; i <= N ; i++) {
        if(v[i] > x) {
            for( int j = N ; j > i ; j--) v[j] = v[j-1];
            v[i] = x;
            break; 
        }
    }
    if (v[N-1] < x) v[N] = x;
}

// Exercicio 2

void ordenaVetor (int v[],int n) {
    int acc;
    for( int i = 0; i < n ; i++) {
        for(int j = n-1 ; j > i; j--) {
            if(v[j] < v[i]) {
                acc = v[i];
                v[i] = v[j];
                v[j] = acc;
            }
        }
    }
}

// Exercício 3 
 
//calcula o indice do maior inteiro. Efeciente em alguns casos ,menos efecientes em arrays ordenados.

int maxInd (int v[], int N) {
    int i = 0 ,j, acc = 0;
    while (i < N -1) {
        for (j = i + 1; j < N ;j++) {
            if (v[j] > v[i]) {
                acc = j;
                i = j;
                break;
            }
        }
        if ( j == N) break;
    }
    return acc;
}

// exercício 4

void ordenaVetor_max (int v[],int n) {
    int temp,l = n;
    for(int i = n-1; i >= 0 ; i--,l--) {
        temp = v[i];
        v[i] = v[maxInd(v,l)];
        v[maxInd(v,l)] = temp;    
    }
}

// Exercício 7

// Função que troca dois valores da posição i para a posição j.
void swap (int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// Função que move o elemento maior de um array para a ultima posição.
void bubble (int v[], int n) {
    int i;
    for (i = 1;(i < n); i++)
        if (v[i-1] > v[i]) swap (v, i-1, i);
}

//Ordenação de um array com a função bubble.
void bubbleSort (int v[], int n) {
    for(int i = n; i >= 0; i--) bubble(v,i);
}

// Exercicio 8 

// Função que ve se um array esta ordenado.
int isSorted (int v[], int n) {
    for (int i = 1 ; i < n ;i++) {
        if(v[i-1] > v[i]) return 0;
    }
    return 1;
}

// A Função de ordenação para caso o array esteja ordenado.
void bubbleSort_OP (int v[], int n) {
    for(int i = n; i >= 0; i--) {
        if(isSorted(v,n)) break;
        else bubble(v,i);
    }
}

