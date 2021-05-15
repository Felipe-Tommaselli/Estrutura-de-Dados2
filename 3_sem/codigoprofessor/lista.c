// Pratica: teste do tempo de execução:
// * Busca binaria semana 4 aula 1

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void cria(lista *l) {
    l->tamanho = 0;
    l->elementos = malloc(sizeof(elem)*TAM);
    l->copia = malloc(sizeof(elem)*TAM);
    l->ordenado = 0;
    return;
}


void destroi(lista *l) {
    free(l->elementos);
    free(l->copia);
    l->tamanho = 0;
}

int insere(lista *l, elem e) {
    if (l->tamanho == TAM)
        return 1; // erro, lista cheia
    l->elementos[l->tamanho] = e;
    l->tamanho++;
    l->ordenado = 0;
    return 0; // sucesso
}

void imprime(lista *l) {
    long i = 0;
    if (l->tamanho == 0) 
        printf("( )\n");
    else {
        printf("(");
        for (; i < l->tamanho-1; i++)
            printf("%d, ", l->elementos[i]);
        printf("%d)\n", l->elementos[i]);
    }
}

void ordena_recursivo(lista *l, long ini, long fim) {
    long meio, l1, l2, lc;
    if (ini == fim)
        return; // criterio de parada; lista unitaria
    
    // ordena metades inferior e superior por recursividade
    meio = ini + (fim - ini) / 2;
    ordena_recursivo(l, ini, meio);
    ordena_recursivo(l, meio + 1, fim);
    
    // une as metades ordenadas
    l1 = lc = ini;
    l2 = meio + 1;
    while (l1 <= meio && l2 <= fim)
        l->copia[lc++] = (l->elementos[l1] < l->elementos[l2]) ? l->elementos[l1++] : l->elementos[l2++];
        /*if (l->elementos[l1] < l->elementos[l2]) {
            l->copia[lc] = l->elementos[l1];
            l1++;
        } else {
            l->copia[lc] = l->elementos[l2];
            l2++;
        }
        lc++;*/
    // copia elementos restantes da metade inferior, se existentes
    for (; l1 <= meio; l1++, lc++)
        l->copia[lc] = l->elementos[l1];
    // copia elementos restantes da metade superior, se existentes
    for (; l2 <= fim; l2++, lc++)
        l->copia[lc] = l->elementos[l2];
    
    // sobrescreve lista nao ordenada pela copia ordenada
    for (lc = ini; lc <= fim; lc++)
        l->elementos[lc] = l->copia[lc];
}

void ordena(lista *l) {
    if (l->tamanho > 1)
        ordena_recursivo(l, 0, l->tamanho-1);
    l->ordenado = 1;
}

int busca_repeticao(lista *l, elem e) {
    long ini, fim, meio;
    if (l->ordenado == 1) {
        ini = 0;
        fim = l->tamanho-1;
        meio = fim/2;
        while (l->elementos[meio] != e && ini < fim) {
            if (l->elementos[meio] > e)
                fim = meio - 1;
            else
                ini = meio + 1;
            meio = ini + (fim - ini) / 2;
        }
        return l->elementos[meio] == e;
    }
    return -1; // erro, nao eh possivel a busca em vetor desordenado 
}

int busca_recursivo(lista *l, elem e, long ini, long fim) {
    long meio = ini + (fim - ini) / 2;
    if (l->elementos[meio] == e || ini >= fim)
        return (l->elementos[meio] == e); // parada, encontrando ou nao o elemento buscado
    return (l->elementos[meio] > e) ? busca_recursivo(l, e, ini, meio-1) : busca_recursivo(l, e, meio+1, fim);
    //if (l->elementos[meio] > e)
    //    return busca_recursivo(l, e, ini, meio-1);
    //return busca_recursivo(l, e, meio+1, fim);
}

int busca(lista *l, elem e) {
    if (l->ordenado == 1)
        return busca_recursivo(l, e, 0, l->tamanho -1);
    return -1; // erro, nao eh possivel a busca em vetor desordenado 
}
