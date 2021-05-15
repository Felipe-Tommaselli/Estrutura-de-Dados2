// Aula 1 da sem 4, teste do algoritmo quadratico

#define TAM 10000
#define repeticoes 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maior_subsequencia_n2(int vet[], int tam){

    int soma, maior_soma;
    for (int i= 0; i< tam; i++){ // inicio da subsequencia, custo: tam
        soma = 0;        
        for (int j=i; j<tam; j++){ // final da subsequencia, custo: tam/2 
                soma += vet[j];
            if (soma > maior_soma)
                maior_soma = soma;
        }
    }
    return maior_soma;
} 

int main(void){

    // int vet[TAM] = { -2, 11, -4, 13, -5, -2};
    // printf("Maior subsequencia: %d\n", maior_subsequencia_n2(vet, 6));
    
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
            maior_subsequencia_n2(vet, i);
            soma_tempo += clock() - tempo_ini;
        }

        // exibe tempo medio decorrido
        printf("%d\t%0.1lf\n", i, soma_tempo / (double) repeticoes);
    }
    return 0; // sucesso

}

/*
* entradas de 1k ate 10k, bem mais eficiente que o cubico mas não tanka mais de 50k
* do 1k ate o 10k rodou em alguns poucos segundos tudo
    1000    1562.5
    2000    9375.0
    3000    15625.0
    4000    28125.0
    5000    48437.5
    6000    70312.5
    7000    100000.0
    8000    123437.5
    9000    145312.5
    10000   201562.5
    
    10000   146875.0
    20000   600000.0
    30000   1326562.5
    40000   2442187.5
    50000   3743750.0
    60000   5767187.5
    70000   8565625.0
    80000   11160937.5
    90000   12706250.0
    100000  16831250.0
*/