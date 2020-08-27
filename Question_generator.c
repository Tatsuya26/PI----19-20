#include <stdio.h>
#include <stdlib.h>
#include<time.h> 

int main() {
    srand(time(0));
    int Question = rand()%100;
    int time = rand()%10;
    int Ficha = 1;
    if(Question > 50) {
      Question -= 50;
      Ficha = 2;  
    } 
    if(time < 3) time += 3;
    printf("Faz a questão %d da ficha %d em %d minutos\n",Question, Ficha, time);
    return 0;
}