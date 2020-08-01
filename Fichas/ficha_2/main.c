#include "ficha_2.h"

int main() {
    //ex 1
    printf("Multiplicação por parcelas 5 * 6,7 : %f\n", multInt(5,(6,7)));

    //ex 2
    printf("Multiplicação otimizada 5 * 6,7 : %f\n", multIntOP(5,(6,7)));

    //ex 3
    printf("MDC entre 18 12 : %d\n", mdc(12,18));

    //ex 4
    printf("MDC entre 18 12 otimizado : %d\n", mdcOP(12,18));

    //ex 6
    //a)
    printf("5º numero da sequencia fibonacci recursivo : %d\n", fibRec(5));
    //b)
    printf("5º numero da sequencia fibonacci iterativo : %d\n", fib(5));



    return 0;
}