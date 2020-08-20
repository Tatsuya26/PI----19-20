#include "ficha_7.h"

int main (){
    int num;
    printf("Qual exercicio quer?\n");
    scanf("%d",&num);
    if(num == 1) {
        printf("Qual a dimensão da sua lista?\n");
        scanf("%d",&num);
        LInt l1,l2,l3,l4,a,b;
        l1 = createList(num);
        printf("Lista Inserida: ");
        printList(l1);
        l2 = copyList(l1);
        l3 = copyList(l1);
        l4 = copyList(l1);
        a = copyList(l4);

        printf("Tail da Lista inserida : ");
        l2 = tail(l2);
        printList(l2);

        printf("Init da Lista inserida : ");
        l3 = init(l3);
        printList(l3);

        printf("Snoc da Lista inserida : ");
        l4 = snoc(l4, 5);
        printList(l4);

        printf("Introduza outra Lista inserida com dimensão %d : \n", num);
        b = createList(num);
        
        printf("Concat das Listas inseridas : ");
        a = concat(a,b);
        printList(a);

        free(l1);
        free(l2);
        free(l3);
        free(l4);
        free(a);
        free(b);
    }
    else if(num == 2) {
    //EX 2
        Aluno a1,a2,a3, a4;
        a1 = createAluno("Ana",1,4);
        a2 = createAluno("Zeca",2,16);
        a3 = createAluno("JBB",23,20);
        a4 = createAluno("Joao Tadeu",85846,15);
        Turma *t = malloc(sizeof(struct Turma)), *pt;
        pt = t;
        pt->aluno = a1;
        pt->prox = malloc(sizeof(struct Turma));
        pt->prox->aluno = a2;
        pt->prox->prox = malloc(sizeof(struct Turma));
        pt->prox->prox->aluno = a3;
        pt->prox->prox->prox = malloc(sizeof(struct Turma));
        pt->prox->prox->prox->aluno = a4;
        pt->prox->prox->prox->prox = NULL;
        printf("Considere a seguinte Turma!\n");
        printTurma(t);
        printf("Introduza o seu aluno.\n");
        Aluno *a5 = malloc(sizeof(struct Aluno));
        getAluno(*a5);
        acrescentaAluno(t,*a5);
        printTurma(t);
        printf("Introduza um numero de aluno para procurar na turma.\n");
        scanf("%d", &num);
        Aluno *b1 = procura(t,num);
        if(b1 == 0) printf("O aluno não existe\n");
        else {
            printf("Aluno Encontrado!\n");
            printAluno(*b1);
        }
        free(t);
    } else if(num == 3) {
        Stack s;
        initStack(&s);
        if(isEmptyS(&s) == 0) printf("LIsta Vazia!\n");
        pritntf("Considere a Stack\n");
        for(int i = 0; i < 5; i++) s = push(&s,i);
        printStack(s);
    }
    return 0;
}