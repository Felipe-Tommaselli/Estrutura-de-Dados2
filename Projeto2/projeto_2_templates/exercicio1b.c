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
    
    int pos, aux, aux2, i;

    for(pos = 0; pos < n; pos++)
        if(entradas[pos] == e)
            break;

    if(pos != n){ // elemento encontrado
        aux = entradas[pos];

        for(i = 0; i < pos; i++)
            entradas[i + 1] = entradas[i];
        
        entradas[0] = aux;
    }

    return (pos == n) ? -1 : pos;
}

int main(int argc, char const *argv[]){
    /*
    const int N = 50000;
    unsigned encontrados = 0;

    int* entradas = ler_inteiros("inteiros_entrada.txt", N);
    int* consultas = ler_inteiros("inteiros_busca.txt", N);

    // realiza busca sequencia com realocação
    inicia_tempo();
    for (int i = 0; i < N; i++) {
        // buscar o elemento consultas[i] na entrada
    }
    double tempo_busca = finaliza_tempo();

    printf("Tempo de busca    :\t%fs\n", tempo_busca);
    printf("Itens encontrados :\t%d\n", encontrados);
    */
    int entradas[4] = {9, 6, 4, 3};
    int consultas[4] = {0, 0, 4, 0};
    int res;
    for (int i = 0; i < 4; i++){
        res = busca_sequencial_mpf(entradas, 4, consultas[i]);
        printf("\nres = %d", res);
        // buscar o elemento consultas[i] na entrada
    }
    for (int i = 0; i < 4; i++){
        printf("\nentradas[%d] = %d", i, entradas[i]);
        // buscar o elemento consultas[i] na entrada
    }
    return 0;
}
