/*
============== PROJETO DE ESTRTURUAS DE DADOS 2 ==============

Felipe Andrade Garcia Tommaselli 11800910
Gianluca Capezzuto Sardinha 

Explicação projeto:  https://ae4.tidia-ae.usp.br/access/content/attachment/61c65473-dfd7-45e0-9c5b-f83baa36b63d/Atividades/ecbb2c9d-24c5-4329-a2b2-84b2cdca1331/projeto_1.pdf


* Arquivo sourcer
*/


#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void cria(list *l) {
    l->tamanho = 0; // inicia a lista com tamanho 0
    l->elementos = malloc(sizeof(elem)*TAM); //inicia a lista dinamicamente com TAM elementos
}


void destroi(list *l) {
    free(l->elementos); // libera o espaço dinamico deixado para a lita
    l->tamanho = 0; // volta o tamanho para 0
}

int insere(list *l, elem e) {
    if(l->tamanho == TAM)
        return 1; // erro, lista cheia
    l->elementos[l->tamanho] = e; //insere o elemento na ultima posição
    l->tamanho++; // aumenta o tamanho da lista
    return 0; // sucesso
}

void imprime(list *l) {
    // Declarações
    long i = 0;
    
    if(l->tamanho == 0)
        printf("( )\n"); // imprimir lista vazia
    else{
        printf("("); // abre as chaves da lista
        for(; i < l->tamanho-1; i++) // percorre cada elemento da lista
            printf("%d, ", l->elementos[i]); // printa cada elemento um por um com a , 
        printf("%d)\n", l->elementos[i]); // fecha as chaves
    }
}

void bubblesort(list *l){
    // Declaracoes
    int i = 0, j = 0;
    int n = l->tamanho;
    elem aux;

    // loop passando pela lista inteira
    for(i = 0; i <= n; i++){
        // loop pelas subsequencias possiveis de troca
       for(j = 0; j <= n - i - 2; j++){
           // condicao de troca
           if(l->elementos[j] > l->elementos[j + 1]){
               // troca
               aux = l->elementos[j + 1];
               l->elementos[j+1] = l->elementos[j];
               l->elementos[j] = aux;
           }
       }
    }
}

void bubblesort_aprimorado(list *l){
    // Declaracoes
    int i = 0, j = 0, ordenado = 1;
    int n = l->tamanho;
    elem aux;

    // loop passando pela lista inteira
    for(i = 0; i <= n; i++){
        // loop pelas subsequencias possiveis de troca
       for(j = 0; j <= n - i - 2; j++){
           // condicao de troca
           if(l->elementos[j] > l->elementos[j + 1]){
               // troca
               aux = l->elementos[j + 1];
               l->elementos[j+1] = l->elementos[j];
               l->elementos[j] = aux;
               // ha troca de posicoes na lista
               ordenado = 0;
           }
        }
        // para se o vetor ja estiver ordenado
        if(ordenado == 1)
            break;
    }
}

/*
int particion(list *l, int ini, int fim){
    int pivo = l->elementos[fim];
    int i = ini - 1, j = 0;
    elem aux;

    while(j <= fim - 1){
        if(l->elementos[j] < pivo){
            i++;
            aux = l->elementos[i];
            l->elementos[i] = l->elementos[j];
            l->elementos[j] = aux;
        } 
        j++;
    }
    aux = l->elementos[i + 1];
    l->elementos[i + 1] = l->elementos[fim];
    l->elementos[fim] = aux;

    return i + 1;
}

int random_particion(list *l, int ini, int fim){
    int k = 0;
    elem aux;

    k = rand() % l->tamanho;

    aux = l->elementos[k];
    l->elementos[k] = l->elementos[fim];
    l->elementos[fim] = aux;
    
    return particion(l, ini, fim);
}

void quicksort_rec(list *l, int ini, int fim){
    int pivo = 0;

    if(ini < fim)
        pivo = random_particion(l, ini, fim);
        quicksort_rec(l, ini, pivo - 1);
        quicksort_rec(l, pivo + 1, fim);
}

void quicksort(list *l){
    quicksort_rec(l, 0, l->tamanho - 1);
}

// quicksort:
// Original: (6, 10, 6, 2, 1, 4, 0, 6, 3, 1)
// Segmentation fault (core dumped)

*/