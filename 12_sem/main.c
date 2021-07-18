// Aula busca hashing ABERTO semana 12

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "arv_bin_busca.h"

# define B 11
# define h(k) k % B //hashing aberto nao precisa de rehash

typedef int elem;

typedef struct{
    Arvore vet[B];
} hash;

// -1 indica psoicao vazia, nunca utilizada
void inicializar(hash *tabela){
    for(int i = 0; i < B; i++)
        cria_abb(&(tabela->vet[i]));
}

int inserir(hash *tabela, elem k){
    int pos = h(k);
    return (insere_abb(&(tabela->vet[pos]), k) == 0) ? pos : -1; 
}

int remover(hash *tabela, elem k){
    int pos = h(k);
    return (remover_abb(&(tabela->vet[pos]), k) == 0) ? pos : -1; 
}

int buscar(hash *tabela, elem k){
    int pos = h(k);
    return (busca_abb(&(tabela->vet[pos]), k) != NULL) ? pos : -1; 
}

int main(void){

    hash tabela;
    elem k;

    int opcao, pos;

    inicializar(&tabela);

    do{
        // apresenta menu
        printf("Escolha uma opcao, entre:\n");
        printf("\t 1- insercao\n");
        printf("\t 2- remocao\n");
        printf("\t 3- busca\n");
        printf("\t 4- sair\n");
        scanf("%d", &opcao);

        // le chave (considerando ela inteira)
        if(opcao != 4){
            printf("Digite a chave: ");
            scanf("%d", &k);
        }

        // menu operante
        switch(opcao){
            case 1: // insercao
                pos = inserir(&tabela, k);
                if(pos == -1)
                    printf("Erro: elemento %d nao inserido [tabela cheia]\n", k);
                else
                    printf("Sucesso: elemento %d inserido na posicao %d\n\n", k, pos);
                break;
            case 2: // remocao
                pos = remover(&tabela, k);
                if(pos == -1)
                    printf("Erro: elemento %d nao removido\n", k);
                else
                    printf("Sucesso: elemento %d removido da posicao %d\n", k, pos);
                break;
            case 3: // busca
                pos = buscar(&tabela, k);
                if(pos == -1)
                    printf("Erro: elemento %d nao encontrado\n", k);
                else
                    printf("Sucesso: elemento %d encontrado na posicao %d\n", k, pos);
                break;

        }

    } while(opcao != 4);


    return 0;
}