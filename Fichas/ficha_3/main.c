#include "ficha_3.h"

int main() {
    int x = 3, y = 5, m, a[5] = {1,2,3,4,5};
    
    //ex 2
    swapM (&x, &y);
    printf ("Troca : %d %d\n", x, y);

    //ex 3
    swap(a,2,3);
    printf("Array alterado : ");
    for(int i = 0; i < 5; i++) printf("%d ", a[i]);
    putchar('\n');

   //ex 4
    printf("Somatório do array: %d\n", soma(a,5));

   //ex 5
    maximum(a,5,&m);
    printf("Maior valor do array: %d\n", m);

   //ex 6
    quadrados(a,5);
    printf("Quadrados perfeitos até N: ");
    for(int i = 0; i < 5; i++) printf("%d ", a[i]);
    putchar('\n');

   //ex 7
    pascal(a,4);
    printf("N-ésima linha do triangulo de Pascal: ");
    for(int i = 0; i < 4; i++) printf("%d ", a[i]);
    putchar('\n');


    return 0;
}