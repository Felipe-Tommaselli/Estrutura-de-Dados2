/*
============== PROJETO DE ESTRTURUAS DE DADOS 2 ==============

Felipe Andrade Garcia Tommaselli 11800910
Gianluca Capezzuto Sardinha 

Explicação projeto:  https://ae4.tidia-ae.usp.br/access/content/attachment/61c65473-dfd7-45e0-9c5b-f83baa36b63d/Atividades/ecbb2c9d-24c5-4329-a2b2-84b2cdca1331/projeto_1.pdf


* Arquivo main
*/

// Define o numero de repetições para um mesmo valor de entrada, dessa forma é possivel
// obter medições de tempo para cada entrada coerentes
#define repeticoes 10

// Include das bibiliotecas necessarias, incluindo o TAD
#include "header.h"
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// função main
int main(int argc, char *argv[]){
    // Declarações:
    list l;
    clock_t tempo_ini, soma_tempos, entrada_pequena;
    
    // loop pricipal, incrementa na ordem 10 as entradas (1000->10000->100000...) 
    // até o tamanaho max (TAM) definido no header.h
    for(int ordem = 1; pow(10,ordem) <= TAM; ordem++){
        // zerar a varaivel a cada vez que a entrada mudar
        soma_tempos = 0; 
        // loop pelo numero de repeticoes pedidas
        for(int i = 0; i < repeticoes; i++){
            // cria uma nova lista
            cria(&l);
            //loop pela list criada
            for(long j = 0; j < pow(10,ordem); j++) 
                // Insere elementos aleatorios na lista
                insere(&l, rand() % TAM);
                // Insere elementos em ordem decrescente na lista
                //insere_decrescente(&l, TAM);
                // Insere elementos em ordem crescente na lista
                //insere_crescente(&l, TAM);

            // função criada para identificar se o valor da entrada é "pequeno"
            // para valore até 101 de entrada é possivel fazer o print para analisar
            // se a ordenação esta correta, para valores maiores provavelmente apenas
            // estamos preocupados com a analise do tempo de execução
            if(TAM <= 101)
                entrada_pequena = 1;
            // se a entrada é "pequena" o vetor originial é impresso na tela
            if(entrada_pequena == 1){ 
                printf("Original: "); 
                imprime(&l); 
            }
            
            // tempo inicial é iniciado com o clock bem antes de rodar a ordenação, dessa
            // forma impedimos que processos anteriores a esse entrem na conta do tempo 
            tempo_ini = clock();
            
            // ESCOLHA DO ALGORITMO DE ORDENAÇÃO
            //bubblesort(&l);
            //bubblesort_aprimorado(&l);
            quicksort(&l);  
            //radixsort(&l);
            //heapsort(&l);

            // soma tempos é o tempo atual (após a ordenação), menos o tempo inicial, ou seja
            // é o tempo da decorrida para ordenação de todaas as repetições acumuladas
            soma_tempos += clock() - tempo_ini;

            // se a entrada é "pequena" o vetor após a ordenação é impresso na tela
            if(entrada_pequena == 1){
                printf("Ordenado: "); 
                imprime(&l);
            }
            // apaga a lista, liberando todo o espaço alocado dinamicamente
            destroi(&l);
        }
        // Nesse momento para cada ordem de entrada feita é impresso na tela o tempo de
        // ordenação. Entre as repetições é feita uma media para garantir valores consistentes.
        //  Por isso o valor do soma_tempos deve ser divido pelo numero de repeticoes.
        // Alem disso, o valor do soma_tempos est em clocks do computador, o que não é um valor
        // adequado apara analise, por isso dividimos ele por CLOCKS_PER_SEC. No fim teremos um
        // valor em segundos para a média de tempo para uma dada entrada.
        printf("Entrada: %0.0f; Tempo total: %0.10f\n", pow(10,ordem), (soma_tempos / (double) repeticoes) / CLOCKS_PER_SEC);
    }
    return 0;
}