//* Aula 1 da 9 semana
// mesmo projeto das priemrias aulas
#define repeticoes 10
#include "lista.h"
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    lista l;
    clock_t tempo_ini, soma_tempos;
    
    //? considera listas de tamanhos cada vez maiores
    for(int ordem = 1; pow(10,ordem) <= TAM; ordem++){
        soma_tempos = 0;
        //? faz varias rodadas independentes
        for(int i = 0; i < repeticoes; i++){
            //? nova lista
            cria(&l);
    
            //? insere elementos aleatorios 
            for(long j = 0; j < pow(10,ordem); j++)
                insere(&l, rand() % 100);
            
            //imprime(&l); //? imprime antes de ordenar
    
            //? ordena e guarda tempo decorrido
            tempo_ini = clock(); //? guarda tempo inicial
            //ordena_nlogn(&l);
            //ordena_bubblesort(&l);
            //ordena_bubblesort_aprimorado(&l);
            //ordena_quicksort(&l);
            //ordena_insercao_simples(&l);
            //ordena_shellsort(&l);
            //ordena_selecaodireta(&l);
            //ordena_heapsort(&l);
            //ordena_contagem_menores(&l);
            //ordena_counting_sort(&l);
            ordena_radixsort(&l);

            soma_tempos += clock() - tempo_ini; //? considera tempo decorrido desta rodada 
    
            //imprime(&l); //? imprime apos ordenar
            
            //? apaga a lista
            destroi(&l);
        }
        printf("Entrada: %0.0f; Tempo total: %0.10f\n", pow(10,ordem), (soma_tempos / (double) repeticoes) / CLOCKS_PER_SEC);
    }

    return 0; //? sucesso
}

/* 
* Countingsort O(n) ou O(maior - menor + 1):
Esse algoritmo é extremamente eficiente, porem quando aumentamos as entradas, tambem aumentamos
a varaivao entre maior e menor numero (essa implementação feita) o que na vdd gasta mais tempo

[10 repeticoes] entradas ate 10^5
Entrada: 10; Tempo total: 0.0015625000
Entrada: 100; Tempo total: 0.0031250000
Entrada: 1000; Tempo total: 0.0015625000
Entrada: 10000; Tempo total: 0.0015625000
Entrada: 100000; Tempo total: 0.0031250000

[10 repeticoes] entradas ate 10^7
Entrada: 10; Tempo total: 0.1171875000
Entrada: 100; Tempo total: 0.1296875000
Entrada: 1000; Tempo total: 0.1171875000
Entrada: 10000; Tempo total: 0.1312500000
Entrada: 100000; Tempo total: 0.1328125000
Entrada: 1000000; Tempo total: 0.1843750000
Entrada: 10000000; Tempo total: 0.6640625000

* Radixsort O(mn), sendo m o num de digitos do maior numero:

[10 repeticoes] entradas ate 10^8
Entrada: 10; Tempo total: 0.0000000000
Entrada: 100; Tempo total: 0.0000000000
Entrada: 1000; Tempo total: 0.0000000000
Entrada: 10000; Tempo total: 0.0000000000
Entrada: 100000; Tempo total: 0.0078125000
Entrada: 1000000; Tempo total: 0.0375000000
Entrada: 10000000; Tempo total: 0.4062500000
Entrada: 100000000; Tempo total: 3.9000000000
*/