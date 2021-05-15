// Aula 2 da sem 4, teste do algoritmo linear (n)
#define TAM 10000000
#define repeticoes 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maior_subsequencia_n(int vet[], int tam){

    //comeco padrao do n2 e n3
   int soma = 0, maior_soma = 0;
   for (int i = 0; i < tam; i++){
       soma += vet[i];
        if (soma > maior_soma)
            maior_soma = soma;
        // desconsideramos os possiveis incios negativos pois eles não contribuem pra soma
        else
            if (soma < 0)
                soma = 0;
   } 
   //? CUSTO:
   // T(n) = 5*n, portanto é O(n)
}

int main(void){

    //int vet[TAM] = { -2, 11, -4, 13, -5, -2};
    //printf("Maior subsequencia: %d\n", maior_subsequencia_n(vet, 6));
    
    
    clock_t soma_tempo, tempo_ini;
    //int vet[TAM]; 
    // entrada mto grande precisamos de uma implementação dinamica
    int *vet = malloc(sizeof(int) * TAM);

    for (int i = 1000000; i <= TAM; i+= 1000000){ // tamanhos cada vez maiores do vetor
        soma_tempo = 0;
        // repete varias vezes para obter tempo medio
        for (int j = 0; j < repeticoes; j++){
            // cria vetor
            for (int k = 0; k < i; k++){
                vet[k] = rand() % TAM; // gera numeros aleatoris, mas todos positivos
                if (vet[k] % 2)
                    vet[k] *= -1; // deixa todos os pares negativos, pra garantir que existam num negativos
            }

            tempo_ini = clock();
            maior_subsequencia_n(vet, i);
            soma_tempo += clock() - tempo_ini;
        }

        // exibe tempo medio decorrido
        printf("%d\t%0.1lf\n", i, soma_tempo / (double) repeticoes);
    }
    free(vet);
    return 0; // sucesso

}

/*
* entradas do 10k ate 100k demora alguns segundos, no maaximo minutos para processar
* codigo pequenininho mas parrudo em slc
    10.000   0.0
    20000   0.0
    30000   0.0
    40000   1562.5
    50000   0.0
    60000   0.0
    70000   0.0
    80000   0.0
    90000   1562.5
    100.000  0.0
* KKKKK DEU NEM GRACA MENOS QUE 100K
    100.000  0.0
    200000  1562.5
    300000  0.0
    400000  4687.5
    500000  1562.5
    600000  3125.0
    700000  0.0
    800000  0.0
    900000  4687.5
    1.000.000 3125.0
* vsf kkk
    1.000.000 3125.0
    2000000 4687.5
    3000000 6250.0
    4000000 10937.5
    5000000 18750.0
    6000000 17187.5
    7000000 17187.5
    8000000 18750.0
    9000000 21875.0
    10.000.000        28125.0
* do 1M ate 10 M deu uma graça até, chegando nos 10M demorou uns 3s, no total deve ter dado uns 10s
*/