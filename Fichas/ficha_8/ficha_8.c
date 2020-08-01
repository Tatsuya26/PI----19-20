#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entrada{
    char *palavra;
    int ocorr;
    struct entrada *prox;
} *Palavras, pal;

typedef Palavras Dicionario; 

void initDic (Dicionario *d) {
    (*d) = NULL;
}

int acrescenta (Dicionario *d, char *pal) {
    Dicionario pt;
    Palavras new = malloc(sizeof(pal));
            new->ocorr = 1;
            new->palavra = pal;
            new->prox = NULL;
    if(!(*d)) *d = new;
    else {
        for(pt = (*d); pt; pt = pt->prox) {
            if(strcmp(pt->palavra, pal) == 0) {
                pt->ocorr++;
                return pt->ocorr;
            }
        }
        if(!pt) {
            pt->prox = new;
        }
    }
    return 1;
}

char * maisFreq (Dicionario d, int *c) {
    Dicionario pt;
    int max = 0;
    *c = 0;
    char *palfreq; 
    for(pt = d; pt; pt = pt->prox) {
        if(pt->ocorr > *c) {
            max = *c = pt->ocorr; 
            palfreq = pt->palavra;
        }
    }
    return palfreq;
}

int main(int argc, char *argv[]) {
    FILE *input;
    int r = 0, count = 0;
    char word[100];
    Dicionario d = malloc(sizeof(struct entrada));
    d = NULL;
    if (argc == 1) input = stdin;
    else input = fopen(argv[1], "r");
    if (input == NULL) r = 1;
    else {
        while((fscanf(input, "%s", word) == 1)) {
            acrescenta(&d,word);
            count++;
        }
        fclose(input);
        printf("%d palavras\n", count);
    }
    int* c = malloc(sizeof(*c));
    printf("Palavra mais comum: %s - ",maisFreq(d,c));
    printf("aparece %d vez(es)",*c);
    return r;
}
