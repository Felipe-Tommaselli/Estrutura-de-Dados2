#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#define h(x, i, B) (h_mul(x, i, B) + i * h_div(x, i, B)) % B

// Definição das variaveis que controlam a medição de tempo
clock_t _ini, _fim;

// Definição do tipo booleano
typedef unsigned char bool;
#define TRUE 1
#define FALSE 0

// Definição do tipo string
typedef char *string;

#define MAX_STRING_LEN 20

typedef struct{
  string *v;
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

    tabela->v = calloc(B, sizeof(string));
    for (i = 0; i < B; i++){
        tabela->v[i] = NULL;
    }
}

int inserir(string x, unsigned B, hash *tabela)
{
    unsigned pos, i, aux, aux1;

    aux = converter(x);

    for (i = 0; i < B; i++)
    {
    pos = h(aux, i, B);

    if (tabela->v[pos] == NULL){
        tabela->v[pos] = calloc(MAX_STRING_LEN, sizeof(string));
        strcpy(tabela->v[pos], x);
        return pos;
    }
    if (!strcmp(tabela->v[pos], x))
        return -1;
    }
    return -1;
}

int buscar(string x, unsigned B, hash *tabela)
{
    unsigned pos, i, aux;

    aux = converter(x);
    int AA;
    for (i = 0; i < B; i++){

        pos = h(aux, i, B);

        tabela->v[pos] = calloc(MAX_STRING_LEN, sizeof(string));

        if (strcmp(tabela->v[pos], x))
            return pos;
        if (tabela->v[pos] == NULL)
            return -1;
    }
    return -1;
}

int main(int argc, char const *argv[]){
    const int N = 50000;
    const int M = 70000;
    const int B = 150001;

    unsigned colisoes = 0;
    unsigned encontrados = 0;

    int AA;
    string *insercoes = ler_strings("strings_entrada.txt", N);
    string *consultas = ler_strings("strings_busca.txt", M);

    hash tabela;

    // cria tabela hash com hash por hash duplo
    criar(&tabela, B);

    // inserção dos dados na tabela hash
    inicia_tempo();
    for (int i = 0; i < N; i++){
        if(inserir(insercoes[i], B, &tabela) != -1) // inserir insercoes[i] na tabela hash
            colisoes++;
    }

    printf(">>>>>>>>1<<<<<<<<<<");
    for (int i = 0; i < 10; i++){
        printf("tabela[%d] = %d", i, &tabela[i]);
    }
    scanf("%d", &AA);
    double tempo_insercao = finaliza_tempo();
    
    // busca dos dados na tabela hash
    inicia_tempo();
    for (int i = 0; i < N; i++){
        if(buscar(insercoes[i], B, &tabela) != -1) // buscar consultas[i] na tabela hash
            encontrados++;
    }
    double tempo_busca = finaliza_tempo();


    printf("Colisões na inserção: %d\n", colisoes);
    printf("Tempo de inserção   : %fs\n", tempo_insercao);
    printf("Tempo de busca      : %fs\n", tempo_busca);
    printf("Itens encontrados   : %d\n", encontrados);

    free(insercoes);
    free(consultas);

    return 0;
    }