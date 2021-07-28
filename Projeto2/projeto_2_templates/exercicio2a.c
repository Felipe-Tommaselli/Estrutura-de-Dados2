#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>

// Definição das variaveis que controlam a medição de tempo
clock_t _ini, _fim;

// Definição do tipo booleano
typedef unsigned char bool;
#define TRUE 1
#define FALSE 0

// Definição do tipo string
typedef char *string;

#define MAX_STRING_LEN 20

// struct com vetor de strings 
typedef struct{
    string *vet; 
} hash;

unsigned converter(string s){
    unsigned h = 0;
    for (int i = 0; s[i] != '\0'; i++)
        h = h * 256 + s[i];
    return h;
}

string *ler_strings(const char *arquivo, const int n){
    FILE *f = fopen(arquivo, "r");

    string *strings = (string *)malloc(sizeof(string) * n);

    for (int i = 0; !feof(f); i++){
        strings[i] = (string)malloc(sizeof(char) * MAX_STRING_LEN);
        fscanf(f, "%s\n", strings[i]);
    }

    fclose(f);

    return strings;
}

void inicia_tempo(){
    srand(time(NULL));
    _ini = clock();
}

double finaliza_tempo(){
    _fim = clock();
    return ((double)(_fim - _ini)) / CLOCKS_PER_SEC;
}

unsigned h_div(unsigned x, unsigned i, unsigned B){
    return ((x % B) + i) % B;
}

unsigned h_mul(unsigned x, unsigned i, unsigned B){
    const double A = 0.6180;
    return ((int)((fmod(x * A, 1) * B) + i)) % B;
}

void criar(hash *tabela, unsigned B){
    int i;

    tabela->vet = (string *) calloc(B, sizeof(string));

    for(i = 0; i < B; i++){
        tabela->vet[i] = "-";
    }
}

int inserir(hash *tabela, unsigned *colisoes, unsigned B, string e, unsigned (*fHash)(unsigned, unsigned, unsigned)){
    
    unsigned pos, i, aux;

    aux = converter(e);
    
    for(i = 0; i < B; i++){

        pos = fHash(aux, i, B);

        //if(i == 1)
        //    (*colisoes)++;

        if(((int) strcmp(tabela->vet[pos], "-")) == 0){ 
            tabela->vet[pos] = calloc(MAX_STRING_LEN, sizeof(string));
            strcpy(tabela->vet[pos], e);
            //return pos;
            return i;
        }
        
        if(strcmp(tabela->vet[pos], e) == 0)
            return -1;

        //(*colisoes)++;
    }
    return -1;
}

int buscar(hash *tabela, unsigned B, string e, unsigned (*fHash)(unsigned, unsigned, unsigned)){
    unsigned pos, i, aux;

    aux = converter(e);

    for (i = 0; i < B; i++){

        pos = fHash(aux, i, B);

        if(strcmp(tabela->vet[pos], e) == 0)
            return pos;
        if(tabela->vet[pos] == "-")
            return -1;
    }
    return -1;
}

void limpar(hash *tabela, unsigned B){
    int pos;

    tabela->vet = (string *) calloc(B, sizeof(string));

    for(pos = 0; pos < B; pos++){
        tabela->vet[pos] = "-";
    }
}

int main(int argc, char const *argv[]){
    unsigned N = 50000;
    unsigned M = 70000;
    unsigned B = 150001;

    unsigned colisoes_h_div = 0;
    unsigned colisoes_h_mul = 0;

    unsigned encontrados_h_div = 0;
    unsigned encontrados_h_mul = 0;

    string* insercoes = ler_strings("strings_entrada.txt", N);
    string* consultas = ler_strings("strings_busca.txt", M);

    hash tabela;

    // cria tabela hash com hash por divisão
    criar(&tabela, B);

    // inserção dos dados na tabela hash usando hash por divisão
    inicia_tempo();
    for (int i = 0; i < N; i++){
        if(inserir(&tabela, &colisoes_h_div, B, insercoes[i], &h_div) > 0); // inserir insercoes[i] na tabela hash
            colisoes_h_div++;    
    }
    double tempo_insercao_h_div = finaliza_tempo();

    // consulta dos dados na tabela hash usando hash por divisão
    inicia_tempo();
    for (int i = 0; i < M; i++){
        if(buscar(&tabela, B, consultas[i], &h_div) != -1) // buscar consultas[i] na tabela hash
            encontrados_h_div++;// buscar consultas[i] na tabela hash
    }

    double tempo_busca_h_div = finaliza_tempo();

    // limpa a tabela hash com hash por divisão
    limpar(&tabela, B);

    // inserção dos dados na tabela hash usando hash por multiplicação
    inicia_tempo();
    for (int i = 0; i < N; i++){
        if(inserir(&tabela, &colisoes_h_mul, B, insercoes[i], &h_mul) > 0); // inserir insercoes[i] na tabela hash
            colisoes_h_mul++;
    }
    double tempo_insercao_h_mul = finaliza_tempo();

    // busca dos dados na tabela hash com hash por multiplicação
    inicia_tempo();
    for (int i = 0; i < M; i++){
        if(buscar(&tabela, B, consultas[i], &h_mul) != -1) // buscar consultas[i] na tabela hash
            encontrados_h_mul++;
    }
    double tempo_busca_h_mul = finaliza_tempo();

    // limpa a tabela hash com hash por multiplicação
    limpar(&tabela, B);

    printf("Hash por Divisão\n");
    printf("Colisões na inserção: %d\n", colisoes_h_div);
    printf("Tempo de inserção   : %fs\n", tempo_insercao_h_div);
    printf("Tempo de busca      : %fs\n", tempo_busca_h_div);
    printf("Itens encontrados   : %d\n", encontrados_h_div);
    printf("\n");
    printf("Hash por Multiplicação\n");
    printf("Colisões na inserção: %d\n", colisoes_h_mul);
    printf("Tempo de inserção   : %fs\n", tempo_insercao_h_mul);
    printf("Tempo de busca      : %fs\n", tempo_busca_h_mul);
    printf("Itens encontrados   : %d\n", encontrados_h_mul);

    free(insercoes);
    free(consultas);

    return 0;
}