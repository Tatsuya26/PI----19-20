// Ex 1
float multInt (int n, float m) {
    float r = 0;
    for(int i = n; i > 0; i--) r += m;
    return r;
}

// Ex 2
float multIntOP (int n, float m) {
    float r = 0;
    while(n > 1) {
        if(n % 2 != 0) r += n;
        n /= 2;
        m *= 2;
    }
    return r;
}

// Ex 3
int mdc (int a, int b) {
    int r = 0, divisor = (a < b) ? b : a;
    for(int i = 1; i <= divisor; i++) {
        if(a % i == 0 && b % i == 0) r = i;
    }
    return r;
}

// Ex 4
int mdcOP (int a, int b) {
    int maior = (a < b) ? b : a, menor = (a > b) ? b : a;
    while(maior > 0) {
        if(maior >= menor) maior -= menor;
        else menor -= maior;
    }
    return menor;
}

// Ex 6

//a) Recursivo
int fibRec (int n) {
    if(n < 3) return 1;
    else return fibRec(n -1) + fibRec(n-2);
}   

//b) iterativo
int fib(int n) {
    int ant = 1, atual = 1;
    for(int i = 3; i <= n; i++) {
        int temp = atual;
        atual += ant;
        ant = temp;
    }
    return atual;
}
