#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

//Q 1
void q1() {
    int num, maior = INT_MIN;
    while(1) {
       scanf("%d",&num);
        if(num == 0) break;
        if(num > maior) maior = num;
    }
    printf("O maior numero inserido é : %d\n", maior);
}


//Q2
void q2() {
    int media = 0, num, counter = 0;
    while(1) {
        scanf("%d",&num);
        if(num == 0)break;
        else media += num;
        counter++;
    }
    media /= counter;
    printf("A média dos números inseridos é %d\n", media);
}


// Q3
void q3() {
    int maior = INT_MIN, scnd = 0, num;
    while(1) {
        scanf("%d",&num);
        if(num == 0)break;
        if(num > maior) {
            scnd = maior;
            maior = num;
        }
    }
    if(scnd == INT_MIN || scnd == 0) printf("Não foram inseridos dois valores :(!\n");
    else printf("O 2º maior numero inserido é : %d\n", scnd);
}

//ex4 
int bitsUm (unsigned int x){
    int r=0;
    while(x) {
        r += x % 2;
        x /= 2;
    }
    return r;
}

//ex 5
int trailingZ (unsigned int n) {
    int acc = 0, i = 0;
    while(i < 32) {
        if(n % 2 == 0) {
            acc++;
            n /= 2;
        } 
        i++;
    }
    return acc;
}

//ex 6
int qDig (unsigned int n) {
    if(n / 10 < 1) return 1;
    else return 1 + qDig(n / 10);
}


//ex 7
char *mystrcat (char s1[], char s2[]) {
    int i;
    for(i = 0; s1[i]; i++);
    for(int j = 0; s2[j]; j++, i++) s1[i] = s2[j]; 
    s1[i] = '\0';
    return s1;
}

//ex 8
char *mystrcpy (char *dest, char source[]) {
    int i;
    for(i = 0; source[i]; i++) dest[i] = source[i];
    dest[i] = '\0';
    return dest;
}

//ex 9
int mystrcmp (char s1[], char s2[]) {
    int i = 0;
    while(s1[i] == s2[i] && s1[i] && s2[i]) i++;
    return (s1[i] - s2[i]);
}

//ex 10
char *mystrstr (char s1[], char s2[]) {
    int inWord = 1, i = 0, j = 0;
    char* inicio = NULL;
    while(s1[i] && s2[j]) {
        if(s1[i] == s2[j]) {
            if(!inWord) {
                inWord = 1;
                inicio = &s1[i];
            } 
            j++;
        }
        if(s1[i] != s2[j]) {
            inWord = 0;
            j = 0;
        }
    i++;
    }
    printf("%s\n", inicio);
    if(inWord && s2[j] == '\0') return inicio;
    else return NULL;
}

//ex 11
void strrev (char s[]) {
    int len = 0;
    for(len = 0; s[len]; len++);
    for(int i  = 0; i < len/2; i++) {
        int temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

//ex 12
void strnoV (char t[]){
    int i = 0,j;
    while(t[i]) {
        if(t[i] == 'a' ||t[i] == 'e' ||t[i] == 'i' ||t[i] == 'o' ||t[i] == 'u' ||
           t[i] == 'A' ||t[i] == 'E'  ||t[i] == 'I' ||t[i] == 'O' ||t[i] == 'U')
               for(j = i; t[j]; j++) t[j] = t[j+1];
        else i++;
        
    }
}

//ex 13
void truncW (char t[], int n) {
    int  i = 0, j = 0, counter = 0;
    while(t[i]) {
        if(t[i] == ' ' || t[i] == '\n') {
            counter = 0;
            i++;
        }
        else {
            if(counter++ >= n) for(j = i; t[j]; j++) t[j] = t[j+1];
            else i++;
        }
    }
}

// ex 14
char charMaisfreq (char s[]) {
    char charfreq = s[0];
    int freq = 1, acc = 1, i, j;
    for(i = 0; s[i]; i++) {
        for(j = i + 1; s[j]; j++)  if(s[i] == s[j]) acc++;
        if(acc > freq) {
            freq = acc;
            charfreq = s[i];
        }
    }
    return charfreq;
}

//ex 15
int iguaisConsecutivos (char s[]) {
    int i,acc = 1, counter = 0;
    for(i = 0; s[i]; i++) {
        if(s[i] == s[i + 1]) acc++;
        else {
            if(acc > counter) counter = acc;
            acc = 1;
        }
    }
    
    return counter;
}

//ex 16
int difConsecutivos(char s[]) {
    int i, acc = 1,counter = 0;
    for(i = 0; s[i]; i++) {
        if(s[i] != s[i + 1]) acc++;
        else {
            if(counter < acc) counter = acc;
            acc = 1;
        }    
    }
 return counter;   
}

//ex 17
int maiorPrefixo (char s1 [], char s2 []) {
    int i;
    for(i = 0; s1[i] == s2[i]; i++);
    return i;
}

//ex 18
int maiorSufixo (char s1 [], char s2 []) {
    int i,j,k = 0;
    for(i = 0; s1[i]; i++);
    for(j = 0; s2[j]; j++);
    for(; s2[j-1] == s1[i-1] && i >= 0 && j >= 0; i--,j-- ) k++;
    return k;
}

//ex 19
int sufPref (char s1[], char s2[]) {
    int i, j = 0, counter = 0;
    for(i = 0; s1[i]; i++) {
        if(s1[i] == s2[j]) {
            counter++;
            j++;
        }
        else {
            counter = 0;
            j = 0;
        }
    }
    return counter;
}

//ex 20
int contaPal (char s[]) {
    int counter = 0, i, isWord = 0;
    for(i = 0; s[i]; i++) {
        if(s[i] == ' ' || s[i] == '\n') {
            if(isWord) counter++;
            isWord = 0;
            
        }
        else isWord = 1;
        }
    if(isWord) counter++;
    return counter;
}

//ex 21
int contaVogais (char s[]) {
    int i, counter = 0;
    for(i = 0; s[i]; i++)
        switch(s[i]) {
            case 'A': case 'E': case 'I' : case 'O' : case 'U':
            case 'a': case 'e': case 'i' : case 'o' : case 'u':
            counter++;
        }
    return counter;
}

//ex 22
int contida (char a[], char b[]) {
    int i, j, contida;
    for(i = 0; a[i]; i++) {
        contida = 0;
        for(j = 0; b[j]; j++) if(b[j] == a[i]) contida = 1;
        if(!contida) return 0;
    }
    return 1;
}

//ex 23
int palindroma (char s[]) {
    int i, j;
    for(i = 0; s[i]; i++);
    for(j = 0; j < i/2; j++) 
        if(s[j] != s [i - j - 1]) return 0;
    return 1;
}

//ex 24
int remRep (char x[]) {
    int i = 0, j;
    while(x[i]) {
        if(x[i] == x[i + 1]) for(j = i; x[j]; j++) x[j] = x[j + 1];
        else i++;
    }
    return strlen(x);
}

//ex 25
int limpaEspacos (char t[]) {
    int i = 0, j;
    while(t[i]) {
        if(t[i] == t[i + 1] && t[i] == ' ') for(j = i; t[j]; j++) t[j] = t[j + 1];
        else i++;
    }
    return strlen(t);
}

//ex 26
void insere (int v[], int N, int x) {
    int i,j;
    for(i = 0; i <= N; i++) 
        if(v[i] > x) {
            for(j = N; j > i; j--) v[j] = v[j - 1];
            v[i] = x;
            break;
        }
    if(v[i] < x) v[N] = x;
}

//ex27
void merge (int r [], int a[], int b[], int na, int nb){
    int i, ina = 0, inb = 0;      
    for(i = 0; i < na + nb; i++) {
        if((a[ina] < b[inb] && ina < na) || inb >= nb) {
            r[i] = a[ina];
            ina++;
        } else {
            r[i] = b[inb];
            inb++;
        }
    }
}

//ex 28
int crescente (int a[], int i, int j){
    for(int k = i; k < j; k++) if(a[k] > a[k + 1]) return 0;
    return 1;
}

//ex 29
int retiraNeg (int v[], int N){
    int r = N, i  = 0;
    while(i < N) {
        if(v[i] < 0) {
            for(int j = i; j < N; j++) v[j] = v[j + 1];
            N--;
        }
        else i++;
    }
    return N;
}

//ex 30
int menosFreq (int v[], int N){
    int i,acc = 1, freq = N, num = v[0];
    for(i = 0; i < N; i++) {
        if(v[i] == v[i+1]) acc++;
        else {
            if(acc < freq) {
                freq = acc;
                num = v[i];
            }
            acc = 1;
        }
    }
    return num;
}
//ex 31
int maisFreq (int v[], int N){
    int num = v[0], acc = 1, freq = 1,i;
    for(i = 0; i < N; i++) {
        if(v[i] == v[i + 1]) acc++;
        else {
            if(acc > freq) {
                freq = acc;
                num = v[i];
            }
            acc = 1;
        }
    }    
    return num;
}

//ex 32
int maxCresc (int v[], int N) {
    int i , acc = 1, freq = 1;
    for(i = 0; i < N; i++) {
        if(v[i] <= v[i + 1]) acc++;
        else {
            if(acc > freq) freq = acc;
            acc = 1;
        }
    }
    return freq;
}

//ex33
void removeIndex(int v[], int pos,int N) {
    int i;
    for(i = pos; i < N; i++) v[i] = v[i + 1];
}

int elimRep (int v[], int N) {
    int i, j = 0;
    for(i = 0; i < N; i++) {
        j = i + 1;
        while(j < N){
            if(v[i] == v[j]) {
                removeIndex(v,j,N);
                N--;
            }
            else j++;
        }
    }
    return N;
}

//ex 34
int elimRepOrd (int v[], int N) {
    int i = 0;
    while(i < N) {
        if(v[i] == v[i + 1]) {
            if(N == 1) break;
            removeIndex(v,i+1,N);
            N--;
        }
        else i++;
    }
    return N;
}

//EX 35
int comunsOrd (int a[], int na, int b[], int nb){
    int i = 0,j = 0, acc = 0;
    while(i < na && j < nb) {
        if(a[i] > b[j]) j++;
        else if (a[i] < b[j]) i++;
        else {
            acc++;
            i++;
            j++;
        }
    }
    return acc;
}

//ex 36
int comuns (int a[], int na, int b[], int nb){
    int i,j, acc = 0;
    for(i = 0; i < na; i++) 
        for(j = 0; j < nb; j++) {
            if(a[i] == b[j]) {
                acc++;
                break;
            }
        }
    return acc;
}

//ex 37
int minInd (int v[], int n) {
    int minInd = 0, minVal = v[0], i;
    for(i = 1; i < n; i++) 
        if(v[i] < minVal) {
            minVal = v[i];
            minInd = i;
        }
   return minInd;
}

//ex 38
void somasAc (int v[], int Ac [], int N){
   int acc = 0, i;
    for(i = 0; i < N; i++) {
        acc += v[i];
        Ac[i] = acc;
    }
}

//ex 39
int triSup (int N, int m [N][N]) {
    int i,j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < i; j++) {
            if(m[i][j] != 0) return 0;
        }
    }
    return 1;
}

//ex 40
void transposta (int N, float m [N][N]) {
    int i,j;
    for(i = 0; i < N; i++)
        for(j = i; j < N; j++) {
            float temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
}

//ex 41
void addTo(int N, int M, int a [N][M], int b[N][M]) {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) a[i][j] += b[i][j];

}

//ex 42
   int unionSet (int N, int v1[N], int v2[N], int r[N]){
       int i;
       for(i = 0; i < N; i++) r[i] = v1[i] || v2[i];
       return i;
   }

//ex 43
int intersectSet (int N, int v1[N], int v2[N], int r[N]){
       int i;
       for(i = 0; i < N; i++) r[i] = v1[i] && v2[i];
       return i;
}

//ex 44
int intersectMSet (int N, int v1[N], int v2[N],int r[N]) {
    int i;
    for(i = 0; i < N; i++) r[i] = v1[i] < v2[i] ? v1[i] : v2[i];
    return i;
}

//ex 45

int unionMSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i = 0; i < N; i++) r[i] = v1[i] + v2[i];
    return i;
}

// ex 46

int cardinalMSet (int N, int v[N]){  
    int acc = 0;
    for(int i = 0; i < N; i++) acc += v[i];
    return acc;
}

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct posicao {
    int x, y;
} Posicao;

// ex 47
Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;
    for(i = 0; i < N; i++) {
        if(mov[i] == Norte) inicial.y++;
        if(mov[i] == Sul) inicial.y--;
        if(mov[i] == Este) inicial.x++;
        if(mov[i] == Oeste) inicial.x--;
    }
    return inicial;
}

// ex 48
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i;
    for(i = 0; i < N; i++) {
        if(inicial.y < final.y) {
            mov[i] = Norte;
            inicial.y++;
        }
        else if(inicial.y > final.y) {
            mov[i] = Sul;
            inicial.y--;
        }
        else if(inicial.x < final.x) {
            mov[i] = Este;
            inicial.x++;
        }
        else if(inicial.x > final.x) {
            mov[i] = Oeste;
            inicial.x--;
        }
        else break;
    }
    if(inicial.x != final.x || inicial.y != final.y) return -1;
    else return i;
}

//ex 49
double distO(Posicao pos, Posicao fin) {
    return sqrt(pow((pos.x - fin.x),2) + pow((pos.y - fin.y),2));
}

int maiscentral (Posicao pos[], int N) {
    int i, ind = 0;
    Posicao org;
    org.x = 0; org.y = 0;
    double dist = distO(pos[0],org);
    for(i = 1; i < N; i++) {
        double acc = distO(pos[i],org);
        if(acc < dist){
            dist = acc;
            ind = i;
        } 
    }
    return ind;
}

//50
int vizinhos (Posicao p, Posicao pos[], int N) {
    int i, acc = 0;
    for(i = 0; i < N; i++) 
        if(distO(p,pos[i]) == 1) acc++;
    return acc;
}


