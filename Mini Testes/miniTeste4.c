#include <miniTeste4.h>

//ex 1
void listar( Cinema c ) {
    printf("Filmes disponíveis são: \n");
    for(;c; c = c->seg) {
        printf("-> %s \n" ,c->s.filme);
    }
}

//ex 2
int procuraLugar(Sala *s, int lugar) {
    for(;s->vendidos; s->vendidos = s->vendidos->seg) {
         if(s->vendidos->lugar == lugar) return 1; 
    }
    return 0;
}

int disponivel(Cinema c, Filme f, int lugar) {
    int r = 0;
    for(;c; c = c->seg) {
        if(strcmp(&f,(c->s.filme)) == 0) {
            r = procuraLugar(&(c->s),lugar);
            break;
        }
    }
    return r;
}

//ex 3
int acrescentaLugar(Sala *s, int lugar) {
    for(; s->vendidos->seg; s = s->vendidos->seg);
    s->vendidos->seg = malloc(sizeof(NLBilhete));
    s->vendidos->seg->lugar = lugar;
    s->vendidos->seg->seg = NULL;
    return 1;
}



Cinema vendebilhete(Cinema c, Filme f, int lugar) {
    Cinema aux = c;
    for(aux = c; aux; aux = aux->seg) {
        if(strcmp(aux->s.filme,&f) == 0) {
            acrescentaLugar(&(aux->s),lugar);
        }
    }
    return c;
}


//ex 4
int length(Sala *s) {
    int len = 0;
    for(; s; s = s->vendidos->seg) len++;
    return len;
}

void listardisponibilidades(Cinema c) {
    for(;c; c = c->seg) {
        printf("Filme : %s\n", c->s.filme);
        printf("Numero de lugares disponíveis: %d\n", (c->s.nlugares -length(&(c->s))));
    }
}

