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
    for (int ordem = 1; pow(10,ordem) <= TAM; ordem++) {
        soma_tempos = 0;
        //? faz varias rodadas independentes
        for (int i = 0; i < repeticoes; i++) {
            //? nova lista
            cria(&l);
    
            //? insere elementos aleatorios 
            for (long j = 0; j < pow(10,ordem); j++)
                insere(&l, rand() % TAM);
            
            //imprime(&l); //? imprime antes de ordenar
    
            //? ordena e guarda tempo decorrido
            tempo_ini = clock(); //? guarda tempo inicial
            //ordena_nlogn(&l);
            //ordena_bubblesort(&l);
            //ordena_bubblesort_aprimorado(&l);
            //ordena_quicksort(&l);
            //ordena_insercao_simples(&l);
            ordena_shellsort(&l);
            //ordena_selecaodireta(&l);

            soma_tempos += clock() - tempo_ini; //? considera tempo decorrido desta rodada 
    
            //imprime(&l); //? imprime apos ordenar
            
            //? apaga a lista
            destroi(&l);
        }
        printf("Entrada: %0.0f; Tempo total: %0.10f\n", pow(10,ordem), (soma_tempos / (double) repeticoes) / CLOCKS_PER_SEC);
    }

    return 0; //? sucesso
}

/* Shellsort:

[10 repeticoes]
Entrada: 1000; Tempo total: 0.0000000000
Entrada: 10000; Tempo total: 0.0015625000
Entrada: 100000; Tempo total: 0.0171875000
Entrada: 1000000; Tempo total: 0.4062500000

obs: O do selecaosiples tem la no comeco quando ele era chamado de quadratico
*/