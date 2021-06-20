/*
============== PROJETO DE ESTRTURUAS DE DADOS 2 ==============

Felipe Andrade Garcia Tommaselli 11800910
Gianluca Capezzuto Sardinha 

Explicacao projeto:  https://ae4.tidia-ae.usp.br/access/content/attachment/61c65473-dfd7-45e0-9c5b-f83baa36b63d/Atividades/ecbb2c9d-24c5-4329-a2b2-84b2cdca1331/projeto_1.pdf

* Arquivo main
*/

// Define o numero de repeticoes para um mesmo valor de entrada, dessa forma eh possivel
// obter medicoes de tempo para cada entrada coerentes
#define repeticoes 10

// Include das bibiliotecas necessarias, incluindo o TAD
#include "header.h"
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// funcao main
int main(int argc, char *argv[]){
    // Declaracoes:
    int ordem, i, p; // variaveis para rodar no loop
    long j; // outra variavel para rodar no loop
    list l; // lista de elemetnos principal (declarado no header)
    clock_t tempo_inicial, soma_tempos, dp[repeticoes] = {0}, dp_valor; // variaveis de medicao de tempo
    int entrada_pequena; // variavel para averiguar se vai ser possivel printar as entradas
    int alg = 0; // variavel para escolher o algoritmo de ordenacao

    // Input do usuario para escolher qual algoritmo
    printf("\n============== PROJETO 1 ED2 ==============\n");
    while(1){    
        printf("\nQual agoritmo de ordenacao voce deseja utilizar?\n");
        printf("1. Bubblesort\n2. Bubblesort aprimorado\n3. Quicksort\n4. Radixsort\n5. Heapsort\n");
        setbuf(stdin, NULL);
        scanf("%d", &alg);
        if(alg == 1 || alg == 2 || alg == 3 || alg == 4 || alg  == 5)
            break;
    }

    // loop pricipal, incrementa na ordem 10 as entradas (1000->10000->100000...) 
    // ate o tamanaho max (TAM) definido no header.h
    for(ordem = 1; pow(10, ordem) <= TAM; ordem++){
        // zerar a varaivel a cada vez que a entrada mudar
        soma_tempos = 0; 
        for(p = 0; p < repeticoes; p++)
            dp[p] = 0;        
        // loop pelo numero de repeticoes pedidas
        for(i = 0; i < repeticoes; i++){
            // cria uma nova lista
            cria(&l);
            //loop pela list criada
            for(j = 0; j < pow(10, ordem); j++) 
                // Insere elementos aleatorios na lista
                insere(&l, rand() % TAM);
                // Insere elementos em ordem decrescente na lista
                //insere_decrescente(&l, TAM);
                // Insere elementos em ordem crescente na lista
                //insere_crescente(&l, TAM);

            // funcao criada para identificar se o valor da entrada eh "pequeno"
            // para valore ate 101 de entrada eh possivel fazer o print para analisar
            // se a ordenacao esta correta, para valores maiores provavelmente apenas
            // estamos preocupados com a analise do tempo de execucao
            if(TAM <= 101)
                entrada_pequena = 1;
            // se a entrada eh "pequena" o vetor originial eh impresso na tela
            if(entrada_pequena == 1){ 
                printf("Original: "); 
                imprime(&l); 
            }
            
            // tempo inicial eh iniciado com o clock bem antes de rodar a ordenacao, dessa
            // forma impedimos que processos anteriores a esse entrem na conta do tempo 
            tempo_inicial = clock();

            // ESCOLHA DO ALGORITMO DE ORDENACAO
            switch(alg){
                case 1:
                    bubblesort(&l);
                    break;
                case 2:
                    bubblesort_aprimorado(&l);
                    break;
                case 3:
                    quicksort(&l);  
                    break;
                case 4:
                    radixsort(&l);
                    break;
                case 5:
                    heapsort(&l);
                    break;
            }
            // soma tempos eh o tempo atual (apos a ordenacao), menos o tempo inicial, ou seja
            // eh o tempo da decorrida para ordenacao de todaas as repeticoes acumuladas
            dp[i] = clock() - tempo_inicial;

            // se a entrada eh "pequena" o vetor apos a ordenacao eh impresso na tela
            if(entrada_pequena == 1){
                printf("Ordenado: "); 
                imprime(&l);
            }
            // apaga a lista, liberando todo o espaco alocado dinamicamente
            destroi(&l);
        }
        printf("\n::::\n");
        for(p = 0; p < repeticoes; p++){
            printf("%li, ", dp[p]);
            soma_tempos = soma_tempos + dp[p];
            printf("(somatempos: %li)", soma_tempos);
        }
        printf("somatempos: %li", soma_tempos);
        for(p = 0; p < repeticoes; p++)
            dp[p] = pow((dp[p] - (soma_tempos / (double) repeticoes))/ CLOCKS_PER_SEC, 2);

        for(p = 0; p < repeticoes; p++)
            printf("\ndp[p]: %li", dp[p]);
            dp_valor += dp[p];

        dp_valor = pow(dp_valor / repeticoes, (1/2));

        // Nesse momento para cada ordem de entrada feita eh impresso na tela o tempo de
        // ordenacao. Entre as repeticoes eh feita uma media para garantir valores consistentes.
        //  Por isso o valor do soma_tempos deve ser divido pelo numero de repeticoes.
        // Alem disso, o valor do soma_tempos est em clocks do computador, o que nao eh um valor
        // adequado apara analise, por isso dividimos ele por CLOCKS_PER_SEC. No fim teremos um
        // valor em segundos para a media de tempo para uma dada entrada.
        printf("\nEntrada: %0.0f   ", pow(10,ordem));
        printf("Tempo total: %0.10f   ", (soma_tempos / (double) repeticoes) / CLOCKS_PER_SEC);
        printf("Desvio padrao: %0.5li\n", dp_valor);
    }
    return 0;
}