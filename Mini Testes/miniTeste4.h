#include <string.h>
typedef char Filme[60];

typedef struct sLBilhete{
    int lugar;
    struct sLBilhete *seg;
} *LBilhete, NLBilhete;


typedef struct sSala{
    int nlugares;
    LBilhete vendidos;
    Filme filme;
}  Sala;


typedef struct sCinema{
    Sala s;
    struct sCinema *seg;
} *Cinema, NCinema;



void listar(Cinema c);
int disponivel( Cinema c, Filme f, int lugar );
Cinema vendebilhete( Cinema c, Filme f, int lugar );