#include "ficha_7.h"

int main (){
    LInt l1,l2,l3;
    l1 = NULL;
    l1 = cons (l1, 10);
    l1 = cons (l1, 20);
    l1 = cons (l1, 30);
    printList(l1);
    l2 = tail(l1);
    printList(l2);
    l3 = init(l1);
    printList(l3);
    return 0;
}