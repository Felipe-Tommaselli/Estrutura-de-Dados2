// No .h: criar um TAD e criar uma lista cabeçalho

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void cria(lista *l){
    l->tamanho = 0; // cria ela setada para 0 ja
    return; // só pelas boas praticas de programação 
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

void ordena(lista *l){
    // algoritmo de ordenaçao quadrado
    // encontra o menor element, coloca ele na 1 posição
    // ignora esse elemento, pega o segundo menor, coloca na 2 pos
    //etc

    // processa uma posição por vez
    for(int i = 0; i < l->tamanho; i++){
        // encontrar menor entre o i-esimo e o ultimo
        int IDmenor = i; // assume que o i-esimo é o menor 
        for(int j = i + 1; j < l->tamanho; j++)
            if(l->elementos[j] < l->elementos[IDmenor])
                IDmenor = j;
        // coloca menor na i-esima posicao
        elem aux;
        aux = l->elementos[i];
        l->elementos[i] = l->elementos[IDmenor];
        l->elementos[IDmenor] = aux;
    }
}

