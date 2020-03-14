#include <stdio.h> 
void swapM (int *x, int *y) {
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

void swap (int v[], int i, int j) {
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

int soma (int v[], int N) {
    int r = 0;
    for(int i = 0; i < N; i++)
        r = r + v[i];
    return r;
}

int maximum (int v[], int N, int *m) {
    if (N <= 0) { 
        return -1;
    }
    *m = v[0];
    for (int i = 1; i < N; i++){
        if (v[i] > *m)
            *m = v[i];
    }        
    return 0;
}
// mal
void quadrados (int q[], int N) {
    int x = 0;
    for (int i = 1 ; i < N ; i++) {
        q[x] = i * i;
        x++;
    }
}


int main() {
    int x = 5, y = 1 , i;
    int v[] = {1,2,35,4,5};
    int q[x];
    //swapM (&x, &y);
    //printf (" SwapM: %d %d\n", x, y); 
    //swap (v , x, y);
    //for (i = 0; i < 5; i++) {
    //    printf("%d\n",v[i]);
    //}
    //printf ("Narutooooo : %d\n" , soma (v,5));
    quadrados (q,x);
    for (i = 0; i < 5; i++) {
        printf("%d\n",v[i]);
    }
    return 0;
}
