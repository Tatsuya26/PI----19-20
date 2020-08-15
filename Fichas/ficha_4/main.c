#include "ficha_4.h"

int main() {
    char s[100];
    printf("Insire uma string :\n");
    fgets(s,100,stdin);
    char temp[100];
    strcpy(temp,s);
    //ex 1
    minusculas(temp);
    printf("Output primeiro ex: %s\n", temp);
    
    //ex 2
    printf("Output segundo ex: %d\n", contalinhas(s));

    //ex 3
    printf("Output terceiro ex: %d\n",contaPal(s));
   
   //ex 5

//    printf("%d\n", contalinhas(s));
    return 0;
}