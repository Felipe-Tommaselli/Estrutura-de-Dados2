// Aula 1 da sem 4, teste do algoritmo cubico

#define TAM 10000
#define repeticoes 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maior_subsequencia_n3(int vet[], int tam){

    int soma, maior_soma;
    for (int i= 0; i< tam; i++){ // inicio da subsequencia, custo: tam
        for (int j=i; j<tam; j++){ // final da subsequencia, custo: tam/2 
            soma = 0;
            for (int k = i; k <= j; k++) //custo: tam/4 (eu acho)
                soma += vet[k];
            if (soma > maior_soma)
                maior_soma = soma;
        }
    }
    return maior_soma;
} 

int main(void){

    // int vet[TAM] = { -2, 11, -4, 13, -5, -2};
    // printf("Maior subsequencia: %d\n", maior_subsequencia_n3(vet, 6));
    
    clock_t soma_tempo, tempo_ini;
    int vet[TAM];

    for (int i = 1000; i <= TAM; i+= 1000){ // tamanhos cada vez maiores do vetor
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
            maior_subsequencia_n3(vet, i);
            soma_tempo += clock() - tempo_ini;
        }

        // exibe tempo medio decorrido
        printf("%d\t%0.1lf\n", i, soma_tempo / (double) repeticoes);
    }
    return 0; // sucesso

}

/*
* entradas de 1k ate 10k, demora horas quando chego perto do 8k e 10k
* mto demorado slc, ate pras entradas pequenas ele ja é mais devagarzinho
    1000    523437.5
    2000    4167187.5
    3000    13512500.0
    4000    31150000.0
    5000    58445312.5
* é tortura fica esperando essa merda, ja parei ele de rodar
*/