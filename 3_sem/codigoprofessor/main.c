// Pratica: teste do tempo de execução:
// * Busca binaria semana 4 aula 1

#define num_listas 1
#define num_buscas 1000000
#include "lista.h"
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    lista l;
    clock_t tempo_ini, soma_tempos;
    long e;
    int achou;
    
    // considera listas de tamanhos cada vez maiores
    for (int ordem = 3; pow(10,ordem) <= TAM; ordem++) {
        soma_tempos = 0;
        // faz varias rodadas independentes
        for (int i = 0; i < num_listas; i++) {
            // nova lista
            cria(&l);
    
            // insere elementos aleatorios
            for (long j = 0; j < pow(10,ordem); j++)
                insere(&l, rand() % TAM);
            
            //imprime(&l); // imprime antes de ordenar
            
            ordena(&l);
            
            for (int j = 0; j < num_buscas; j++) {
                // busca e guarda tempo decorrido
                e = rand() % TAM;
                tempo_ini = clock(); // guarda tempo inicial
                achou = busca(&l, e);
                //achou = busca_repeticao(&l, e);
                soma_tempos += clock() - tempo_ini; // considera tempo decorrido desta rodada
                
                //if (achou == 1)
                //    printf("Elemento %d encontrado\n", e);
                //else
                //    printf("Elemento %d NAO encontrado\n", e);
            }
            
            //imprime(&l); // imprime apos ordenar
            
            // apaga a lista
            destroi(&l);
        }
        printf("Entrada: %0.0f; Tempo total: %0.20lf\n", pow(10,ordem), (soma_tempos / ((double) num_listas * num_buscas)) / CLOCKS_PER_SEC);
    }
    
    //cria(&l);
    //insere(&l, 4);
    //insere(&l, 2);
    //insere(&l, 8);
    //insere(&l, 6);
    //insere(&l, 10);
    //ordena(&l);
    //for (long e = 1; e <= 10; e++)
    //    if (busca(&l, e) == 1)
    //        printf("Elemento %d encontrado\n", e);
    //    else
    //        printf("Elemento %d NAO encontrado\n", e);

    return 0; // sucesso
}