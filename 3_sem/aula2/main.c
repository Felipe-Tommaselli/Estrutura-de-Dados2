// Pratica: teste do tempo de execução:
// * Busca binaria semana 3 aula 2

#define num_listas 1
#define num_buscas 1001
#include "lista.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// para tirar a influencia de elementos externoss na eficiencia do codigo o melhor é rodar ele
// varias vezes sob entradas diferentes e pegar a media
int main(void){
    lista l;
    clock_t tempo_ini, soma_tempos = 0;
    int ordem = 0;
    long e;
    int achou;
    // conta o tanto de clocks por segundos que o seu pc faz

    // o tempo de uma repetição é muito pequeno, vamos calcular a media varios tempos para varias repeticoes
    for(ordem = 5; pow(10, ordem) <= TAM; ordem++){
    // faz varias rodadas independentes dependendo do tamanho possivel
        soma_tempos = 0;
        for (int i = 0; i < num_listas; i++){
        // cria, ordena e imprime uma nova lista cada ciclo
            cria(&l);
            
            for (long j = 0; j < pow(10, ordem); j++)
                insere(&l, rand() % TAM); //o % TAM é pros num nao ficarem tao grandes e ruim de visualizar

            //imprime(&l); // enttrada grande não precisa imprimir não

            ordena(&l);
            
            for (int j = 0; j < num_buscas; j++){
                e = rand() % TAM;
                tempo_ini = clock();
                achou = busca(&l, e);
                soma_tempos += clock() - tempo_ini;

                if (achou == 1)
                    printf("elemento %d encontrado\n", e);
                else
                    printf("elemento %d NAO encontrado\n", e);
            }
                        
            destroi(&l);
        }
        printf("Tamanho da entrada: %f\n", pow(10, ordem));
        printf("Tempo total: %0.20lf\n", (soma_tempos / (double) num_listas * num_buscas)/ CLOCKS_PER_SEC);
    }

    /*
    cria(&l);
    insere(&l, 6);
    insere(&l, 8);
    insere(&l, 2);
    insere(&l, 4);
    insere(&l, 10);
    
    for (long e = 1; e <= 10; e++){
        if(busca(&l, 1) == 1)
            printf("ELemento %d Encontrado\n", 1);
        else
            printf("ELemento %d NAO Encontrado\n", 1);
        }
    */
    return 0;
}


/*obs: Operando com uma alocação dinamica conseguimso os seguintes resultados:
para uma entrada de 100 000 (Cem mil), para ordenalos quadraticamente com 1 repetição  
foi necessario 14.4218750000 segundos
*/

