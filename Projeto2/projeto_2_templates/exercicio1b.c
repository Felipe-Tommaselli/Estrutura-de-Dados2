#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição das variaveis que controlam a medição de tempo
clock_t _ini, _fim;

// Definição do tipo booleano
unsigned char typedef bool;
#define TRUE  1
#define FALSE 0


int* ler_inteiros(const char * arquivo, const int n){
    FILE* f = fopen(arquivo, "r");

    int * inteiros = (int *) malloc(sizeof(int) * n);

    for (int i = 0; !feof(f); i++)
        fscanf(f, "%d\n", &inteiros[i]);

    fclose(f);

    return inteiros;
}

void inicia_tempo(){
    srand(time(NULL));
    _ini = clock();
}

double finaliza_tempo(){
    _fim = clock();
    return ((double) (_fim - _ini)) / CLOCKS_PER_SEC;
}

int busca_sequencial_mpf(int entradas[], int n, int e){

    // iterador que conterá a posicao do elemento e procurado, caso seja encontrado 
    int pos;
    // variaveis que armazenam a posicao anterior e proxima durante a movimentacao de 
    // elementos para frente, funcionam como um carry que vai sendo atualizado a cada iteracao
    int prox, ant;
    // iterador auxiliar
    int i;

    // procura o elemento em todas as posições do vetor
    for(pos = 0; pos < n; pos++) 
        // testa se o elemento da posição atual é o elemento procurado de um por um
        if(entradas[pos] == e) 
            // para a busca segunrando a posição pos do elemento
            break;

    if(pos != n){ //elemento encontrado
        // seta a posicao do primeiro ant
        ant = entradas[0]; 
        // roda ate a posicao do elemento encontrado
        for(i = 0; i < pos; i++){
            // guarda o proximo elemento que sera adiantado uma posicao
            prox = entradas[i + 1];
            // empurra os elementos ate o trocado uma posicao para frente
            entradas[i + 1] = ant;
            // atualiza o anterior com o elemento guardado 
            ant = prox;
        }
        // move o elemento procurado para frente
        entradas[0] = e;
    }

    // retorna a posicao caso o elemento seja encontrado, cc retorna -1
    return (pos == n) ? -1 : pos;
}

int main(int argc, char const *argv[]){
    
    const int N = 50000;
    unsigned encontrados = 0;

    int* entradas = ler_inteiros("inteiros_entrada.txt", N);
    int* consultas = ler_inteiros("inteiros_busca.txt", N);

    // realiza busca sequencia com realocação
    inicia_tempo();
    for (int i = 0; i < N; i++) {
        if(busca_sequencial_mpf(entradas, N, consultas[i]) != -1)
            encontrados++;
        // buscar o elemento consultas[i] na entrada
    }
    double tempo_busca = finaliza_tempo();

    printf("Tempo de busca    :\t%fs\n", tempo_busca);
    printf("Itens encontrados :\t%d\n", encontrados);

    return 0;
}
