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
/* 
O radix sort é um algoritmo de ordenação rapido e estavel. 
Ele possui complexidade linear no pior caso.
Seu funcionamento é baseado na ordenaçação por meio dos algoritmos (digitos individuais), que
constituem a cadeira de caracteres que foram o numero na i-esima posicao a ser ordenado.
Essa ordenacao é baseada por chaves unicas de indexação que garantem a ordenação final dos elementos 
*/

void Counting_sort(list *l, elem tam, elem pos){
    // Declaracoes
    int i = 0; // variavel para percorrer os loops
    elem key = 0; // atribui 0 para a varaivel chave por enquanto
    // inicia dinamicamente o vetor B com 10 elementos ja atribuindo 0 nele inteiro
    long* B = calloc(10, sizeof(long)); 
    // inicia dinamicamente o vetor C com o tamanho de elementos da lista, atribuindo 0 tambem
    long* C = calloc(tam, sizeof(long));
    
    // loop percorrendo o vetor inteiro
    for(int i = 0; i <= tam - 1; i++){
        // variavel chave recebe o valor do elemento em relacao a sua posicao
        key = l->elementos[i]/pos;
        // a propria chave recebe o resto por 10 da antiga relacao entre elemento e pos 
        // isto é, no decorrer das iteracoes separamos os digitos do valor querido
        // (unidade, dezena, centena ...) 
        key = key % 10;
        // o valor atual de B na chave é incrementado 
        B[key] += 1;
    }

    // looping de 1 a 9
    for(i = 1; i <= 9; i++)
        // o elemento de B na i-ésima posicao recebe o valor acumulado ate a essa posicao
        // ou seja, o elemento é montado novamente
        B[i] = B[i] + B[i - 1];

    // looping percorrendo o vetor de forma descrescente
    for(i = tam - 1; i >= 0; i--){
        // variavel chave recebe o valor do elemento em relacao a sua posicao
        key = l->elementos[i]/pos;
        // a propria chave recebe o resto por 10 da antiga relacao entre elemento e pos 
        // isto é, no decorrer das iteracoes separamos os digitos do valor querido
        // (unidade, dezena, centena ...) 
        key = key % 10;
        // o valor atual de C na chave é decrementado 
        B[key] = B[key] - 1;
        // o elemento de C na posicao dada pelo valor de B na posicao atual da chave
        // recebe o elemento da posicao i, ou seja, apos abrirmos os algoritmos do valor
        // que sera ordenado, ele é comparado e montado novamente, para assim ser ordenao
        // a partir das comparações entre seus alogoritimos. No final desse processo, C tera
        // recebido os elementos do vetor inicial na posicao correta e estara ordenado
        C[B[key]] = l->elementos[i];
    }

    // loop percorrendo o vetor de forma crescente
    for(i = 0; i <= tam - 1; i++)
        // a lista recebe o valor de C na posicao i, uma vez que C ja esta com o vetor ordenado
        l->elementos[i] = C[i];
}

void radixsort(list *l){
    // Declaracoes
    elem tam = l->tamanho; //atribui a vraivel tamanho o tamanho do vetor
    elem maior = l->elementos[0]; //atribui a varaivel maior o primeiro elemento
    elem pos = 1; //atribui a varaivel pos valor 1 
    
    // loop percorrendo o vetor todo
    for(int i = 0; i < tam; i++)
        // procura o maior elemento
        if (l->elementos[i] > maior)
    	    // atrbui para maior o maior valor ate o momento
            maior = l->elementos[i];
    
    // loop enquanto maior for maior que pos
    while((maior/pos) > 0){
        Counting_sort(l, tam, pos); // funcao de ordenacao do radixsort
        pos *= 10; // aumenta a pos em potencias de 10
    }
}

//* HEAPSORT

void Heapify(list *l,elem tam,int i){
    // Declaracoes
    elem maior = i; // define o elemento maior como i por enquanto 
    elem aux = 0;  // variavel de troca
    elem esq = (2*i) + 1; // declara e atribue valor para variavel da esquerda  
    elem dir = (2*i) + 2; // declara e atribue valor para variavel da esquerda
    
    // comparação entre o elemento da esquerda e o maior elemento 
    if(esq < tam && l->elementos[esq] > l->elementos[maior])
        // se o elemento da esquerda relmente for o maior, maior recebe ele
        maior = esq; 

    // comparação entre o elemento da direita e o maior elemento 
    if(dir < tam && l->elementos[dir] > l->elementos[maior])
        // se o elemento da direita relmente for o maior, maior recebe ele
        maior = dir;

    //  compara se maior é diferente de i
    if(maior > i || maior < i){
        // nesse caso trocamos o elemento da posicao i com o elemento da maior posicao
        aux = l->elementos[i];
        l->elementos[i] = l->elementos[maior];
        l->elementos[maior] = aux;
        // o algoritmo entao é chamado recursivamente, com o proximo sendo o nosso atual maior
        Heapify(l, tam, maior);
    }
}

void heapsort(list *l){
    // Declarações
    elem tam = l->tamanho; // tam é iniciado com o tamanho do vetor lista
    elem aux; // elemento auxiliar para trocas
    int i = 0; // operador de iteração para os loopings

    // Looping varrendo a metade esquerda do vetor (partindo da metade ate o inicio)
    for(i = (tam/2) - 1; i >= 0; i--)
        Heapify(l, tam, i); // função com a ordenação 

    // looping varrendo quase todo o vetor (partindo do fim ate o segundo elemento)
    for(i = tam - 1; i >= 1; i--){
        // troca entre o primeiro elemento e o i-ésimo elemento da iteracao
        aux = l->elementos[0];
        l->elementos[0] = l->elementos[i];
        l->elementos[i] = aux;
        Heapify(l, i, 0); // função com a ordenação 
    }
}