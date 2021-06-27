//* Aula 1 da 7 semana, shell sort O(n(logn)^2)
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
            ordena_counting_sort(&l);

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
* Heapsort O(nlogn):

[10 repeticoes]
Entrada: 1000; Tempo total: 0.0000000000
Entrada: 10000; Tempo total: 0.0046875000
Entrada: 100000; Tempo total: 0.0281250000
Entrada: 1000000; Tempo total: 0.6234375000
Entrada: 10000000; Tempo total: 9.4546875000

* Contagem menores O(n2):

[10 repeticoes]
Entrada: 100; Tempo total: 0.0000000000
Entrada: 1000; Tempo total: 0.0046875000
Entrada: 10000; Tempo total: 0.3671875000
Entrada: 100000; Tempo total: 38.4828125000

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
*/