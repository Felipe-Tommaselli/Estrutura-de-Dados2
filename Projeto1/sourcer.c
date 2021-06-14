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

void cria(list *l){
    l->tamanho = 0; // inicia a lista com tamanho 0
    l->elementos = malloc(sizeof(elem)*TAM); //inicia a lista dinamicamente com TAM elementos
}


void destroi(list *l) {
    free(l->elementos); // libera o espaço dinamico deixado para a lita
    l->tamanho = 0; // volta o tamanho para 0
}

int insere(list *l, elem e){
    if(l->tamanho == TAM)
        return 1; // erro, lista cheia
    l->elementos[l->tamanho] = e; //insere o elemento na ultima posição
    l->tamanho++; // aumenta o tamanho da lista
    return 0; // sucesso
}

int insere_crescente(list *l, elem e){
    if(l->tamanho == TAM)
        return 1; // erro, lista cheia
    while(l->tamanho < e){
        l->elementos[l->tamanho] = l->tamanho; //insere o elemento na ultima posição
        l->tamanho++; // aumenta o tamanho da lista    
        return 0; // sucesso
    }
}

int insere_decrescente(list *l, elem e){
    if(l->tamanho == TAM)
        return 1; // erro, lista cheia
    while(l->tamanho < e){
        l->elementos[l->tamanho] = e - l->tamanho; //insere o elemento na ultima posição
        l->tamanho++; // aumenta o tamanho da lista    
        return 0; // sucesso
    }
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

//* BUBBLESORT

void bubblesort(list *l){
    // Declaracoes
    int i = 0, j = 0;
    int tam = l->tamanho;
    elem aux;

    // loop passando pela lista inteira
    for(i = 0; i <= tam; i++){
        // loop pelas subsequencias possiveis de troca
       for(j = 0; j <= tam - i - 2; j++){
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

//* BUBBLESORT_APRIMORADO

void bubblesort_aprimorado(list *l){
    // Declaracoes
    int i = 0, j = 0, ordenado = 1;
    elem tam = l->tamanho;
    elem aux;

    // loop passando pela lista inteira
    for(i = 0; i <= tam; i++){
        // loop pelas subsequencias possiveis de troca
       for(j = 0; j <= tam - i - 2; j++){
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

//* QUICKSORT

int particion(list *l, int ini, int fim){

    elem pivo = l->elementos[fim];
    int i = ini - 1, j = ini;
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
    int k =  ini + rand() % (fim - ini + 1);
    // printf("l->tamanho: %ld\n", l->tamanho);
    // printf("fim - ini + 1: %d\n", fim - ini + 1);

    elem aux;

    aux = l->elementos[k];
    l->elementos[k] = l->elementos[fim];
    l->elementos[fim] = aux;
    
    return particion(l, ini, fim);
}

void quicksort_rec(list *l, int ini, int fim){
    int pivo = 0;
    if(ini < fim){
        pivo = random_particion(l, ini, fim);
        quicksort_rec(l, ini, pivo - 1);
        quicksort_rec(l, pivo + 1, fim);
    }
}

void quicksort(list *l){
        quicksort_rec(l, 0, l->tamanho - 1);
}

//* RADIX SORT

void Counting_sort(list *l, elem tam, elem pos){
    int i = 0;
    elem key = 0;
    long* B = calloc(10, sizeof(long)); 

    for(int i = 0; i <= tam - 1; i++){
        key = l->elementos[i]/pos;
        key = key % 10;
        B[key] = B[key] + 1;
    }
    for(i = 1; i <= 9; i++)
        B[i] = B[i] + B[i - 1];

    long* C = calloc(tam, sizeof(long));
    
    for(i = tam - 1; i >= 0; i--){
        key = l->elementos[i]/pos;
        key = key % 10;
        B[key] = B[key] - 1;
        C[B[key]] = l->elementos[i];
    }

    for(i = 0; i <= tam - 1; i++)
        l->elementos[i] = C[i];
}

void radixsort(list *l){
    elem tam = l->tamanho, maior = l->elementos[0], pos = 1;
    
    for(int i = 0; i < tam; i++)
        if (l->elementos[i] > maior)
    	    maior = l->elementos[i];
    

    while((maior/pos) > 0){
        Counting_sort(l, tam, pos);
        pos *= 10;
    }
}

//* HEAPSORT

void Heapify(list *l,elem tam,int i){
    elem maior = i, aux = 0; 
    elem esq = (2*i) + 1, dir = (2*i) + 2;
    
    if(esq < tam && l->elementos[esq] > l->elementos[maior])
        maior = esq; 

    if(dir < tam && l->elementos[dir] > l->elementos[maior])
        maior = dir;

    if(maior > i || maior < i){
        aux = l->elementos[i];
        l->elementos[i] = l->elementos[maior];
        l->elementos[maior] = aux;
        Heapify(l, tam, maior);
    }
}

void heapsort(list *l){
    elem tam = l->tamanho, aux;
    int i = 0;

    for(i = (tam/2) - 1; i >= 0; i--)
        Heapify(l, tam, i);

    for(i = tam - 1; i >= 1; i--){
        aux = l->elementos[0];
        l->elementos[0] = l->elementos[i];
        l->elementos[i] = aux;
        Heapify(l, i, 0);
    }
}