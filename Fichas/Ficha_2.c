#include <stdio.h>

float multInt (int n, float m) {
    float r = 0;
    while (n>0) {
        if (n % 2 != 0){
            r = m + r;
        }    
        n = n / 2;
        m = m * 2;
    }   
return r;
}
// exercicio 3
int mdc (int a, int b) {
    int maior = 0, menor = 0, r = 0;
    if (a < b) {
        maior = b;
        menor = a;
    }
    else {
        maior = a;
        menor = b;
    }
    for (r = menor; r > 0; r--){
        if (maior % r == 0 && menor % r == 0){
                 
        }
    }
}

// exercicio 4
int mdc2 (int a, int b) {
    while ( a != 0 && b != 0) {
        if (a > b){
            a = a - b;
        } else {
            b = b - a;
        }
    }
     return (a+b);
}



int main () {
    int x,y;
    printf("%d\n", mdc (30,18));
    return 0;
}