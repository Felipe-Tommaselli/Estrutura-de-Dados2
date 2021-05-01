// 2 semana (n log n)
// No .h: criar um TAD e criar uma lista cabeçalho

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void cria(lista *l){
    l->tamanho = 0; // cria ela setada para 0 ja
    l->elementos = malloc(sizeof(elem)*TAM);
    l->copia = malloc(sizeof(elem)*TAM);
    return; // só pelas boas praticas de programação 
}

void destroi(lista *l){
    free(l->elementos);
    free(l->copia);
    l->tamanho = 0;
}

int insere(lista *l, elem e){
 
    if(l->tamanho == TAM)
        return 1; // erro, lista cheia
    l->elementos[l->tamanho] = e;
    l->tamanho++;
    return 0; // sucesso
}

void imprime(lista *l){

    if(l->tamanho == 0)
        printf("( )\n");
    else{
        printf("(");
        int i;
        for (i = 0; i < l->tamanho - 1; i++)
            printf("%d, ", l->elementos[i]);
        printf("%d)\n", l->elementos[i]);
    }
    
}

void ordena_recursivo(lista *l, int ini, int fim){
    long meio,L1, L2, Lc; // L1 é a lista inferior (metade), L2 a superior 
    // Lc é o resultado da copia, da união 
    
    if(ini == fim)
        return; //criterio de parada, ou seja, chegamos na lista unitaria
    
    // ordena metade inferior e superior por recursidade 
    meio = (ini + (fim - ini))/2;
    ordena_recursivo(l, ini, meio);
    ordena_recursivo(l, meio + 1, fim);

    // une as metades ordenadas
    L1 = Lc = ini;
    L2 = meio + 1; 
    while(L1 <= meio && L2 <= fim){
        l->copia[Lc++] = (l->elementos[L1] < l->elementos[L2]) ? l->elementos[L1++] : l->elementos[L2++];
/* mto grande
       if(l->elementos[L1] < l->elementos[L2]){
            l->copia[Lc] = l->elementos[L1];
            l++;
        } else{
            l->copia[Lc] = l->elementos[L2];
            L2++;
        }
        Lc++; */
    }
    //copia elemetnos restantes da metade inferior, se existentes
    for (; L1 <= meio; L1++, Lc++)
        l->copia[Lc] = l->elementos[L1];
    //copia elemetnos restantes da metade superior, se existentes
    for (; L1 <= fim; L2++, Lc++)
        l->copia[Lc] = l->elementos[L2];

    for(Lc = ini; Lc <= fim; Lc++) //reutilizar Lc é coisa de vagabundo msm
        l->elementos[Lc] = l->copia[Lc];
}

void ordena(lista *l){
    //* algoritmo de ordenaçao n log n
    // dividir a metade da lista, ordenar metade de cima e a de baixo
    // dividir as 2 metades em 4 e etc, até chegar em um element só
    // fazer o merge de 2 listas é de custo liner, então não faz tanta diferenca
    // fazer as dvisiões recursivamente é mais facil
    printf("aquiii");
    if(l->tamanho > 1)
        ordena_recursivo(l, 0, l->tamanho - 1);
}

