// Aula 2 da sem 4, teste do algoritmo n log n
#define TAM 1000000
#define repeticoes 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maior_subsequencia_nlogn_rec(int vet[], int ini, int fim){

    int maior_esquerda, maior_direita, maior_ambos;
    int meio;
    int soma, maior_soma_parcial_esquerda, maior_soma_parcial_direita;

    if (ini == fim)
        return (vet[ini] < 0) ? 0 : vet[ini]; // criterio de parada: vetor unitario

    // dividir o problea em 3 partes, a partir da metade
    // procesa recursivamente e independemnete a metade inferior e a metade superior
    meio = ini + (fim - ini)/2;
    maior_esquerda = maior_subsequencia_nlogn_rec(vet, ini, meio);
    maior_direita = maior_subsequencia_nlogn_rec(vet, meio + 1, fim);
    //? CUSTO:
    //? T(n) = c, se n = 1
    //? T(n) = c + 2T(n/2) + n, se n > 1
    //? portanto, pela arvore de reccorencia chegamos em 
    //? T(n) = nlogn + n, logo ele é O(nlogn) de fato

    // descobrir a maior subsequencia que termina no meio
    // calcula toda as subsequencias a partir do meio ate o inicio procurando  a maior
    soma = maior_soma_parcial_esquerda = 0;
    for (int i = meio; i >= ini; i--){
        soma += vet[i];
        if (soma > maior_soma_parcial_esquerda)
            maior_soma_parcial_esquerda = soma;
    }

    // descobrir a maior subsequencia que coemca no meio + 1 e vai ate o fim
    // calcula toda as subsequencias a partir do meio ate o fim procurando  a maior
    soma = maior_soma_parcial_direita = 0;
    for (int i = meio + 1; i <= fim; i++){
        soma += vet[i];
        if (soma > maior_soma_parcial_direita)
            maior_soma_parcial_direita = soma;
    }

    // descobre a maior subsequencia que envolve as duas metades
    maior_ambos = maior_soma_parcial_esquerda + maior_soma_parcial_direita;

    // se a soma da subseq da esquerda for maior, retornmaos ela como a maior global, 
    // analogo para a direita, no fim ele retorna sempre o "maior global"
    if (maior_esquerda > maior_direita) 
        return (maior_esquerda > maior_ambos) ? maior_esquerda : maior_ambos;
    return (maior_direita > maior_ambos) ? maior_direita : maior_ambos;
    
}

int maior_subsequencia_nlogn(int vet[], int tam){

    return maior_subsequencia_nlogn_rec(vet, 0, tam - 1);
} 

int main(void){

    //int vet[TAM] = { -2, 11, -4, 13, -5, -2};
    //printf("Maior subsequencia: %d\n", maior_subsequencia_nlogn(vet, 6));
    
    
    clock_t soma_tempo, tempo_ini;
    //int vet[TAM]; 
    // entrada mto grande precisamos de uma implementação dinamica
    int *vet = malloc(sizeof(int) * TAM);

    for (int i = 100000; i <= TAM; i+= 100000){ // tamanhos cada vez maiores do vetor
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
            maior_subsequencia_nlogn(vet, i);
            soma_tempo += clock() - tempo_ini;
        }

        // exibe tempo medio decorrido
        printf("%d\t%0.1lf\n", i, soma_tempo / (double) repeticoes);
    }
    free(vet);
    return 0; // sucesso

}

/*
* fez do 10k ate o 100k brincado, foi em segundos tudo (uns 3 s)
* meti do 100k ate 1M fez bricnando tbm, nem 10 s no total
* ta loco mano, demoro uns 2 segundos para o 1M
    10000   1562.5
    20000   0.0
    30000   3125.0
    40000   3125.0
    50000   3125.0
    60000   4687.5
    70000   7812.5
    80000   6250.0
    90000   7812.5
    100000  10937.5
    
    100000  7812.5
    200000  20312.5
    300000  31250.0
    400000  42187.5
    500000  53125.0
    600000  64062.5
    700000  75000.0
    800000  85937.5
    900000  101562.5
    1000000 109375.0
*/