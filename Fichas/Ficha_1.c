// Escreva um programa que desenhe no ecran (usando o car-acter#) um quadrado de dimens ̃ao 5. 
// Defina para isso uma funcao que desenha um quadrado de dimensao. Use a funcao putchar.
//  O resultado da invocacao dessa funcao com um ar-gumento5dever ́a ser o que se apresenta `a direita. 
#include <stdio.h>

void quadrado (int n) {
	int i,j;
	for (i=0;i != n; i++) {
		for (j=0; j != n; j++)
			{
				putchar ('#');
	        }
	    
	    putchar ('\n');
	}
}
// exercicio 3 

void tabuleiro (int n){
	int i,j;
	for (i=0; i!= n; i++) {
		for (j=i ; j!= n+i; j++){
			if (j%2 == 0) putchar ('#');
			else putchar ('_');
		}
	putchar ('\n'); 
         }

}

int main () {
	int x; 
	printf("Introduz um número seu cabeçudo : ");
	scanf ("%d", &x);
	tabuleiro (x);
	//quadrado (x); 
	return 0;
}
