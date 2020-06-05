typedef struct celula {
    char *palavra;
    int comp;
    struct celula *prox;
} *Palavras;

int daPalavra (char *s, int *e) {
    int spaces = 0, comp = 0;
    for(int i = 0; s[i]; i++);
}