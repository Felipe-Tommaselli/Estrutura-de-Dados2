/*
============== PROJETO DE ESTRTURUAS DE DADOS 2 ==============

Felipe Andrade Garcia Tommaselli 11800910
Gianluca Capezzuto Sardinha 

Explicação projeto:  https://ae4.tidia-ae.usp.br/access/content/attachment/61c65473-dfd7-45e0-9c5b-f83baa36b63d/Atividades/ecbb2c9d-24c5-4329-a2b2-84b2cdca1331/projeto_1.pdf


* Arquivo main
*/

#define repeticoes 10

#include "header.h"
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    // Declarações:
    list l;
    clock_t tempo_ini, soma_tempos;
    
    // looping pricipal, incrementa na ordem 10 as entradas (1000->10000->100000 ...)
    for(int ordem = 1; pow(10,ordem) <= TAM; ordem++){
        soma_tempos = 0; 
        // roda o numero de repeticoes pedidas
        for(int i = 0; i < repeticoes; i++){
            cria(&l); // nova lista

            for(long j = 0; j < pow(10,ordem); j++) 
                insere(&l, rand() % TAM); // insere elementos aleatorios
                //insere_decrescente(&l, TAM);
                //insere_crescente(&l, TAM);

            printf("Original: "); imprime(&l); 

            // realiza a ordenação e calcula o tempo que demorou
            tempo_ini = clock(); // tempo inicial
            //bubblesort(&l);
            //bubblesort_aprimorado(&l);
            //quicksort(&l);
            radixsort(&l);
            //heapsort(&l);

            soma_tempos += clock() - tempo_ini; // considera tempo decorrido desta rodada

            printf("Ordenado: "); imprime(&l); // imprime apos ordenar

            destroi(&l); // apaga a lista
        }
        printf("Entrada: %0.0f; Tempo total: %0.10f\n", pow(10,ordem), (soma_tempos / (double) repeticoes) / CLOCKS_PER_SEC);
    }

    return 0; // sucesso
}