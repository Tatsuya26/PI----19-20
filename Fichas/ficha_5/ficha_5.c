#include <stdio.h>

// Exercício 1
void insere (int v[], int N, int x) {
    for(int i = 0; i < N; i++) {
        if(v[i] > 3) {
            for(int j = N; j > i; j--) v[j] = v[j - 1];
            v[i] = x;
            break;
        }
    }
}

//ex 2
void iSort (int v[], int N) {
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(v[i] > v[j]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

// ex 3
int maxInd (int v[], int N) {
    int maxIndice = 0;
    for(int i = 1; i < N; i++) if(v[maxIndice] < v[i]) maxIndice = i;
    return maxIndice;
}

int main() {
    int arr[2] = {6};
    insere(arr,1,3);
    for(int i = 0; i < 2; i++) printf("%d ,", arr[i]);
    putchar('\n');
    printf("o maior elemento tem indice é: %d\n", maxInd(arr,2));
    return 0;
}