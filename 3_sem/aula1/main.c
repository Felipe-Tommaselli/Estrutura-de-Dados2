// Pratica: teste do tempo de execução:
// * Busca binaria semana 3

#define repeticoes 1
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
    // conta o tanto de clocks por segundos que o seu pc faz

    // o tempo de uma repetição é muito pequeno, vamos calcular a media varios tempos para varias repeticoes
    for(ordem = 1; pow(10, ordem) <= TAM; ordem++){
    // faz varias rodadas independentes dependendo do tamanho possivel
    soma_tempos = 0;
        for (int i = 0; i < repeticoes; i++){
        // cria, ordena e imprime uma nova lista cada ciclo
            cria(&l);
            
            for (long j = 0; j < pow(10, ordem); j++)
                insere(&l, rand() % TAM); //o % TAM é pros num nao ficarem tao grandes e ruim de visualizar
            // 3 elementos é muiot pouco
            // insere(&l, 3);
            // insere(&l, 2);
            // insere(&l, 1);

            //imprime(&l); // enttrada grande não precisa imprimir não

            tempo_ini = clock();
            ordena(&l);
            soma_tempos += clock() - tempo_ini;

            // printf("Tempo total: %f\n", (clock() - tempo_ini)/ (float) CLOCKS_PER_SEC);
            // feito para 1 repetição
            // clock() por sec da o tempo atual, ele menos o tempo_init nos fornece
            // a estimativa do tempo em clocks, por isso nós dividimos pelo numero de clocks por second padrão da lingaugem C

            imprime(&l); // entrada grande
            
            destroi(&l);
        }
        printf("Tamanho da entrada: %f\n", pow(10, ordem));
        printf("Tempo total: %0.10f\n", (soma_tempos / (float) repeticoes)/ CLOCKS_PER_SEC);
    }

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
    return 0;
}


/*obs: Operando com uma alocação dinamica conseguimso os seguintes resultados:
para uma entrada de 100 000 (Cem mil), para ordenalos quadraticamente com 1 repetição  
foi necessario 14.4218750000 segundos
*/

