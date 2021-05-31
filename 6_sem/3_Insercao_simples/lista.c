//* Aula 3 da 6 semana, insercao simples
// mesmo projeto das priemrias aulas

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void cria(lista *l) {
    l->tamanho = 0;
    l->elementos = malloc(sizeof(elem)*TAM);
    l->copia = malloc(sizeof(elem)*TAM);
    return;
}


void destroi(lista *l) {
    free(l->elementos);
    free(l->copia);
    l->tamanho = 0;
}

int insere(lista *l, elem e) {
    if (l->tamanho == TAM)
        return 1; //? erro, lista cheia
    l->elementos[l->tamanho] = e;
    l->tamanho++;
    return 0; //? sucesso
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

void ordena_recursivo_nlogn(lista *l, long ini, long fim) {
    long meio, l1, l2, lc;
    if (ini == fim)
        return; //? criterio de parada; lista unitaria
    
    //? ordena metades inferior e superior por recursividade
    meio = ini + (fim - ini) / 2;
    ordena_recursivo_nlogn(l, ini, meio);
    ordena_recursivo_nlogn(l, meio + 1, fim);
    
    //? une as metades ordenadas
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
    //? copia elementos restantes da metade inferior, se existentes
    for (; l1 <= meio; l1++, lc++)
        l->copia[lc] = l->elementos[l1];
    //? copia elementos restantes da metade superior, se existentes
    for (; l2 <= fim; l2++, lc++)
        l->copia[lc] = l->elementos[l2];
    
    //? sobrescreve lista nao ordenada pela copia ordenada
    for (lc = ini; lc <= fim; lc++)
        l->elementos[lc] = l->copia[lc];
}

void ordena_nlogn(lista *l) {
    if (l->tamanho > 1)
        ordena_recursivo_nlogn(l, 0, l->tamanho-1);
}

void ordena_quadratico(lista *l){
    //* algoritmo de ordenaçao quadrado
    //? encontra o menor element, coloca ele na 1 posição
    //? ignora esse elemento, pega o segundo menor, coloca na 2 pos
    //? etc

    //? processa uma posição por vez
    for(long i = 0; i < l->tamanho; i++){
        //? encontrar menor entre o i-esimo e o ultimo
        int IDmenor = i; //? assume que o i-esimo é o menor 
        for(long j = i + 1; j < l->tamanho; j++)
            if(l->elementos[j] < l->elementos[IDmenor])
                IDmenor = j;
        //? coloca menor na i-esima posicao
        elem aux;
        aux = l->elementos[i];
        l->elementos[i] = l->elementos[IDmenor];
        l->elementos[IDmenor] = aux;
    }
}

void ordena_bubblesort(lista *l){
    //? quadratico
    long iteracao = 0;
    elem aux;
    while (iteracao < l->tamanho-1){
        for (long i = 0; i < l->tamanho-1; i++)
            if (l->elementos[i] > l->elementos[i+1]) { //? faz (n-1)*(n-1) => O(n^2) comparacoes para troca 
                //? faz a troca
                aux = l->elementos[i];
                l->elementos[i] = l->elementos[i+1];
                l->elementos[i+1] = aux;
            }
        iteracao++;
    }
}
void ordena_bubblesort_aprimorado(lista *l){
    long continua = 1, iteracao = 1;
    elem aux;
    while (continua == 1) {
        continua = 0;
        for (long i = 0; i < l->tamanho-iteracao; i++)
            if (l->elementos[i] > l->elementos[i+1]) { //? comparacao para troca 
                //? faz a troca
                aux = l->elementos[i];
                l->elementos[i] = l->elementos[i+1];
                l->elementos[i+1] = aux;
                continua = 1;
            }
        iteracao++;
    }
}

void ordena_quick_sort_recursivo(lista *l, long ini, long fim){
    // quicksort com partcionamento de Lomuto -- pivo sempre no final
    long i, j;
    elem aux;

    // faz particionamento
    i = ini;
    for (j= ini; j < fim; j++){
        // compara com o pivo
        if (l->elementos[j] < l->elementos[fim]){
            //troca elementos das pos i por j
            aux = l->elementos[j];
            l->elementos[j] = l->elementos[i];
            l->elementos[i] = aux;
            i++; // achpou novo elemento menor que o pivo
        }
    }
    // reposiciona o pivo, ou seja, troca elementos das posicoes i e fim
    aux = l->elementos[fim];
    l->elementos[fim] = l->elementos[i];
    l->elementos[i] = aux;

    // ordenada as duas metades de maneira independente
    if (ini < i - 1)
        ordena_quick_sort_recursivo(l, ini, i - 1);
    if (i + 1 < fim)
        ordena_quick_sort_recursivo(l, i + 1, fim);
}

void ordena_quicksort(lista *l){
    // piro caso: quadratico
    //melhor caso: nlogn 
    return ordena_quick_sort_recursivo(l, 0, l->tamanho - 1);
}

void ordena_insercao_simples(lista *l){
    long i, j;
    elem aux;

    for (i = 1; i < l->tamanho; i++){ // insere i-ésimo elemento no subvetor ordenado entre 0 e i-1
        aux = l->elementos[i]; // guarda elemento a inserir

        // faz shift a direito em todos os elem maiores que o elemento a inserir
        for (j = i - 1; j > 0 && l->elementos[j] > aux; j--)
            l->elementos[j + 1] = l->elementos[j];

        // insere o elemento na posicao correta
        l->elementos[++j] = aux;
    }
}
