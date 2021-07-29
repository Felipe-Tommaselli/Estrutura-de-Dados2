#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#define h(x, i, B) (h_mul(x, 0, B) + i * h_div(x, 0, B)) % B

//funcao hash primario: (h_mul(x, 0, B)
//funcao hash secundario: (h_mul(x, 0, B) + 2 * h_div(x, 0, B)) % B
//funcao hash "terceriario": (h_mul(x, 0, B) + 3 * h_div(x, 0, B)) % B
//...

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
    string *vet; // vetor com B elementos, sendo B = 150001
    // string vet[150001];
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
        // printf("\ntabela[%d] = %s", i, tabela->vet[i]);
    }
}

// inserir(&tabela, B, insercoes[i]) != -1
int inserir(hash *tabela, unsigned B, string e){
    
    int pos, i, aux;

    aux = converter(e);
    
    for(i = 0; i < B; i++){

        pos = h(aux, i, B); //! implementar hashing duplo

        if(((int) strcmp(tabela->vet[pos], "-")) == 0){ 
            tabela->vet[pos] = calloc(MAX_STRING_LEN, sizeof(string));
            strcpy(tabela->vet[pos], e);
            return pos;
        }
        
        if(strcmp(tabela->vet[pos], e) == 0){
            return -1;
        }
    }
    return -1;
}

int buscar(hash *tabela, unsigned B, string e){
    unsigned pos, i, aux;

    // printf(" e = %s", e);

    aux = converter(e);

    for (i = 0; i < B; i++){

        pos = h(aux, i, B);

        if(strcmp(tabela->vet[pos], e) == 0)
            return pos;
        if(tabela->vet[pos] == "-")
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

    string *insercoes = ler_strings("strings_entrada.txt", N);
    string *consultas = ler_strings("strings_busca.txt", M);

    hash tabela;
    
    // cria tabela hash com hash por hash duplo
    printf("\ncomeco criar");    
    criar(&tabela, B);
    printf("\nfim criar");
    // inserção dos dados na tabela hash
    
    inicia_tempo();

    printf("\ncomeco insercao");
    for (int i = 0; i < N; i++) //! rever a questão dos elementos repetidos
        if(inserir(&tabela, B, insercoes[i]) > 0) // inserir insercoes[i] na tabela hash
            colisoes++;
    printf("\nfim insercao");
    

    double tempo_insercao = finaliza_tempo();
    
    // busca dos dados na tabela hash
    inicia_tempo();
    for (int i = 0; i < M; i++){ //! rever a questão dos elementos repetidos
        //printf("\ni = %d", i);
        if(buscar(&tabela, B, consultas[i]) != -1) // buscar consultas[i] na tabela hash
            encontrados++;
    }
    // itens encontrados: 27411
    double tempo_busca = finaliza_tempo();

    printf("Colisoes na insercao: %d\n", colisoes);
    printf("Tempo de insercao   : %fs\n", tempo_insercao);
    printf("Tempo de busca      : %fs\n", tempo_busca);
    printf("Itens encontrados   : %d\n", encontrados);

    free(insercoes);
    free(consultas);

    return 0;
}