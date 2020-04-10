#include <stdio.h>
#include <string.h>


// faz scan de uma sequencia e diz o maior

void maior (){
    int x , num=0;
    while (1) {
        scanf("%d", &x);
        if ( x == 0) break;
        if ( x > num ) num = x;
    }
    printf(" O maior é %d.\n",num);
}


void media () {
    int x,ciclos = 0;
    double soma = 0, media; 
    while (1){
        scanf ("%d",&x);
        if ( x == 0) break;
        soma += x;
        ciclos++;
    }
    media = soma / ciclos;
    printf (" A media é : %.5f\n",media) ;   
}

// inserida uma sequencia lẽ o segundo maior;
void second () {
    int num,maior = 0, maior2 = 0;
    while (1) {
        scanf("%d", &num);
        if (num == 0) break ;
        if (num > maior ) {
            maior2 = maior;
            maior = num;
        }
        else if ( num > maior2) {
            maior2 = num;
        } 
    }
    printf ("O segundo maior é: %d\n", maior2);
}

// converte um numero decimal para binario.
int bitsUm (unsigned int n) {
    int r = 0;
    while (n > 0) {
        r += n % 2;
        n = n / 2;
        }
    printf("%d",r);
    return r;
} 

// que calcula o numero de bits a 0 no final da representacao binaria de um numero (i.e., o expoente da maior potencia de 2 
//que e divisor desse numero).

int trailingZ (unsigned int n) {
    if(n % 2) return 0;
    else return 1 + trailingZ(n / 2);
}

int qDig (unsigned int n) {
    if (n / 10 < 1) return 1;
    else return 1 + qDig ( n / 10);
}

char *Mystrcpy (char *dest, char source[]) {
    int i;
    for (  i = 0 ; source[i] != '\0'; i++ ) {
        dest [i] = source [i];
    }
    dest[i] = '\0';
    return dest;
}

char *mystrcat (char s1[], char s2[]) {
    int i , j;
    for (i = 0 ; s1[i] != '\0' ; i++);
    for (j = 0 ; s2[j] != '\0' ; j++,i++) {
        s1[i] = s2[j];
        
    }
    s1[i] = '\0';
    return s2 ;
}



int mystrcmp (char s1[], char s2[]) {
    int i ; 
    for(i = 0 ; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' ; i++) ;
    printf ("%d\n", (s1[i] - s2[i]));
    return (s1[i] - s2[i]);
}

/*
  Defina uma função "void strrev (char s[])" que inverte uma string.
*/
void strrev (char s[]) {
    int i,pos = -1;
    for (i = 0 ; s[i] != '\0' ; i++ ) pos++;
    char aux[pos+1];
    for(i = 0 ; i < pos ; i++) aux [pos-i] = s[i];
    for(i = 0 ; i < pos ; i++) s[i] = aux [i];
}



void removeIndex (char s[] , int n ) {
    int i ;
    for (i = n; s[i] ; i++) 
        s[i] = s[i+1];
}

void strnoV (char t[]){
    int i; 
    char c;
    for(i = 0 ; c = t[i] ; i++ ) {
        if(t[i] == 'A' || t[i] == 'E' || t[i] == 'I' || t[i] == 'O' || t[i] == 'U' || t[i] == 'a'
        || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u')
        removeIndex (t,i);
    }
    t[i] ='\0';
}

void truncW (char t[], int n){
    int l, e, contador;
    l=e=0;
    contador=0;
    
    while(t[l]!='\0'){
        if (t[l]==' ') contador = 0;
        else {contador++;}
        
        if (contador > n) l++;
        else {t[e++]=t[l++];}
    }
    t[e]='\0';
}

int contaChar (char x, char s[]) {
    int i , acc = 0;
    for(i = 0; s[i] != '\0' ; i++)
        if (s[i] == x) acc++;
    return acc;
}
char charMaisfreq (char s[]) {
    int i, acc = 0 ,pos, t = 0;
    for ( i = 0 ; s[i] != '\0'; i++ ){
        acc = contaChar ( s[i], s);
        if ( acc > t) {
            t = acc;
            pos = i;
        }
    }
    printf("%c\n",s[pos]);
    return s[pos];
}

int iguaisConsecutivos (char s[]) {
    int i, acc = 1, t = 0;
    if (s[0] == '\0' ) return 0;
    if (s[0] == '\n' || s[0] == '\t') return 1;
    for(i = 1; s[i] != '\0' ; i++) {
        if ( s[i] == s[i-1]) {
            acc++;
            if( acc > t ) t = acc;
        }
        else acc = 1;
    }
    return t;
}


int maiorSufixo (char s1 [], char s2 []) {
    int i,j,k;
    for (i = 0 ; s1[i] !='\0'; i++);
    for (j = 0 ; s2[j] !='\0'; j++);
    i--; j--;
    k = i;
    while (s1[i] == s2[j] && s1[i] != '\0' && s2[j] != '\0') {
        i--;
        j--;
    }
    printf ("%d", (k-i));
    return (k-i);
}

int sufPref (char s1[], char s2[]) {
    int i, j = 0, r = 0;
    for ( i = 0 ; s1[i] != '\0' ; i++ ) {
        if(s1[i] == s2[j]) {
            r++;
            j++;
        }
        else {
            r = 0;
            j = 0;
        }
    }    
    
    return r;
}

// 20
int contaPal (char s[]) {
    int conta = 0,i,isword = 0;
    if (s[0] == '\0') return 0;
    for (i = 0; s[i] != '\0'; i++){ 
        if (s[i] == '\n' || s[i] == ' ' || s[i] == '\t') { 
            if (isword) conta++;
            isword = 0;
        }    
        else isword = 1;
    }
    if(isword) conta++;
return conta;
}

// 22 

int contida (char a[], char b[]) {
    int count = 0,i,j;
    for(i = 0; a[i]; i++) {
        for(j = 0; b[j]; j++) {
            if ( a[i] == b[j]) {
                count++;
                break;
            }
        }
    }
    if(count == strlen(a)) return 1;
    else return 0;
}

// 23

int palindroma (char s[]) {
    int i ,j,length = -1;
    for(i = 0; s[i];i++) length++;
    for(i = 0; s[i];i++) if (s[i] != s[length - i]) return 0;
    return 1;
}

// 24 

int remRep (char x[]) {
    int i;
    while (x[i]) {
        if (x[i] == x[i+1]) {
            removeIndex(x,i);
            i = 0;
        } else i++;
    }
    return strlen(x);
}

// 25 

int limpaEspacos (char t[]) {
    int  i = 0;
    while(t[i]) { 
        if(t[i]== ' ' && t[i+1] == ' ') {
            removeIndex(t,i);
            i = 0; 
        } else i++;
    }
    return i;
}

// 26 

void insere (int v[], int N, int x) {
    int i,j,temp;
    for (i = 0; i < N ; i++) {
        if (v[i] > x) {
            temp = v[i];
            v[i] = x;
            x = temp;
        }     
    }
    v[N] = x;
}

// 27 

void merge (int r [], int a[], int b[], int na, int nb) {
    int i,j,temp;
    // juntar ambos os vetores em r.
    for (i = 0 ; i < na ; i++) r[i] = a[i];
    for (j = 0 ; j < nb ; j++,i++) r[i] = b[j];
    // ordenar o vetor.
    for (i = 0; i < na+nb ; i++) {
        for (j = i+1; j < na+nb ; j++) {
            if(r[j] < r[i]) {
                temp = r[i];
                r[i] = r[j];
                r[j] = temp;
            }
        }
    }
}   


void merge2 (int r [], int a[], int b[], int na, int nb) {
    int i = 0,j = 0,k = 0;
    while (k < na + nb) {
        if ((a[i] < b[j] && i < na ) || j >= nb) {
            r[k] = a[i];
            k++;
            i++;
        } else {
            r[k] = b[j];
            j++;
            k++;
        }
    }
    
}

// 28
 int crescente (int a[], int i, int j) {
     while (i < j) {
         if(a[i] > a[i+1]) return 0;
         i++;
     }
     return 1;
}

// 29 
void removeIndexInt (int v[], int N, int n) {
    int i;
    for(i = n ; i < N; i++ ) {
        v[i] = v[i+1];
    }
}

int retiraNeg (int v[], int N) {
    int i =  0, n = N;
    for (i = 0; i < N; i++) {
        if (v[i] < 0) {
            removeIndexInt(v,N,i);
            N--;
            i--;
        }
    }
    return N;
}

// 30 

int menosFreq (int v[], int N){
       int r = v[0];
       int min = N; //Assumir que no limite tudo é repetido
       int freq = 1; //Só sabemos com certeza que v[0] ocorre 1 vez
       int i;
       for (i = 1; i < N; i++) {
           if (v[i] == v[i-1]) freq++;
           else {
               if(freq < min) { //Verificar sequencia anterior apos começar uma nova
                   min = freq;
                   r = v[i - 1];
               }
                freq = 1;
           }
       }
       if(freq < min) { //verificar ultima sequencia
            min = freq;
            r = v[i - 1];
        }
       return r;
   }


// 32 

int maxCresc (int v[], int N) {
    int i,j = 0,length_controlo = 1,lengthMaior = 0;
    for(i = 1; i < N;i++) {
        if(v[i] >= v[i - 1]) length_controlo++;
            else {
                if(length_controlo > lengthMaior ) lengthMaior = length_controlo;
                length_controlo = 1;
            }
        if( length_controlo > lengthMaior && i == N - 1) lengthMaior = length_controlo;
    }
    return lengthMaior;
}

// 33 

int elimRep (int v[], int n) {
    int i , j;
    for(i = 0; i < n ; i++) {
        for(j = i + 1; j < n; j++) {
            if(v[i] == v[j]) {
                removeIndexInt(v,n,j);
                n--;
                j--;
            }
        }
    }
    return n; 
}

// 34

int elimRepOrd (int v[], int n) {
    int i , j;
    for(i = 0; i < n ; i++) {
        for(j = i + 1; j < n; j++) {
            if(v[i] == v[j]) {
                removeIndexInt(v,n,j);
                n--;
                j--;
            }
        }
    }
    return n; 
}

// 35 

int comunsOrd (int a[], int na, int b[], int nb) {
    int i = 0,j = 0,comuns = 0;
    while(i < na && j < nb) {
            if (a[i] == b[j]) {
            comuns++;
            i++;
            j++;
            } else if( a[i] > b[j]) j++;
            else i++;
        }
    return comuns;
}

//36 

int comuns (int a[], int na, int b[], int nb) {
    int i = 0, j = 0,ans = 0;
    for( i = 0; i < na; i++) {
        int belongs = 0;
        for(j = 0; j < nb; j++) if(a[i] == b[j]) belongs = 1;
        if(belongs) ans++;
    }
    return ans;
}

//37


int minInd (int v[], int n) {
    int i = 0, acc = v[0],indiceMin = 0;
    for(i = 1; i < n; i++) {
        if(v[i] < acc) {
            acc = v[i];
            indiceMin = i;
        }
    }
    return indiceMin;
}
// 38 
void somasAc (int v[], int Ac [], int N) {
    int i,j;
    int acc = 0;
    Ac[0] = v[0];
    for (i = 1; i <  N ;i++) {
        for(j = 0; j <= i; j++) {
            Ac[i] = v[j] + acc;
            acc = Ac[i];  
        }
        acc= 0;
    }

}

//39
int triSup (int N, float m [N][N]) {
    int i,j;
    for(i = 0; i < N;i++) 
        for(j = 0; j < i;j++) {
            if(m[i][j] != 0) return 0; 
            }
    return 1;
    
}


// 40 
void transposta (int N, float m [N][N]) {
    float temp;
    int i,j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < i; j++) {
            temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

// 41 
void addTo (int N, int M, int a [N][M], int b[N][M]) {
    int i,j;
    for(i = 0; i < N; i++) 
        for(j = 0; j < M; j++) a[i][j] += b[i][j];
}

//42
int unionSet (int N, int v1[N], int v2[N], int r[N]) {
    int i,len = 0;
    for(i = 0; i < N; i++) {
        r[i] = v1[i] || v2[i];
        len += r[i];
    }
}

//43
int intersectSet (int N, int v1[N], int v2[N],int r[N]) {
    int i,len = 0;
    for(i = 0; i < N; i++) {
        r[i] = v1[i] && v2[i];
        len += r[i];
    }
}

//44
int intersectMSet (int N, int v1[N], int v2[N], int r[N]) {
    int i,len = 0; 
    for(i = 0; i < N; i++) {
        if(v1[i] > v2[i]) r[i] = v2[i];
        else r[i] = v1[i];
        len += r[i];
    }
    return len;
}

//45
int unionMSet (int N, int v1[N], int v2[N], int r[N]) {
    int i,len = 0; 
    for(i = 0; i < N; i++) {
        if(v1[i] > v2[i]) r[i] = v1[i];
        else r[i] = v2[i];
        len += r[i];
    }
    return len;
}


//46
int cardinalMSet (int N, int v[N]) {
    int i,len = 0;
    for(i = 0; i < N; i++) if(v[i]) len += v[i];
    return len;
}

//47
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N) {
    int i;
    for(i = 0; i < N; i++) {
        if(mov[i] == Norte) inicial.y++;
        if(mov[i] == Oeste) inicial.x--;
        if(mov[i] == Sul) inicial.y--;
        if(mov[i] == Este) inicial.x++;
        }
    return inicial;

}

//48 
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N) {
    int i = 0;
    for(i = 0; i < N; i++) {
        if(inicial.x > final.x) {
            mov[i] = Oeste;
            inicial.x--;
        } else if(inicial.x < final.x) {
            mov[i] = Este;
            inicial.x++;
        } else if(inicial.y < final.y) {
            mov[i] = Norte;
            inicial.y++;
        } else if(inicial.y > final.y) {
            mov[i] = Sul;
            inicial.y--;
        } else if(inicial.x == final.x && inicial.y == final.y) break;
    }
    if(inicial.x == final.x && inicial.y == final.y) return i;
    else return -1;
}

int main () {
    int j[7] = {1,2,3,4,5,6,7};
    int r[7];
    for(int i = 0; i < 7;i++) printf ("%d " ,r[i]);
    putchar ('\n');
    return 0;
}