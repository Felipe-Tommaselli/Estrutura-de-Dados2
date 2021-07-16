// Aula busca hashing semana 11

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

# define B 11
# define h(k, i) ((k + i) % B) //overflow progressivo (tambem usada no hashing duplo)
//? # define haux(k) = 1 + k%(B - 1) //2 funcao hashing

typedef int elem;

typedef struct{
    elem vet[B];
} hash;

// -1 indica psoicao vazia, nunca utilizada
void inicializar(hash *tabela){
    for(int i = 0; i < B; i++)
        tabela->vet[i] = -1;
}

int inserir(hash *tabela, elem k){
    int pos;
    for(int i = 0; i < B; i++){
        pos = h(k, i); // calcula endereco pelo hash
        //? i > 1? pos = haux(k, i) : pos = h(k, i); //hashing duplo
        // -1 indica posicao vazia nunca utilizada
        // -2 indica posicao vazia ja utilizada
        if(tabela->vet[pos] == -1 || tabela->vet[pos] == -2) { 
            tabela->vet[pos] = k; //copia registro
            return pos;
        }
        if(tabela->vet[pos] == k)
            return -1; //erro, elemento repetido
    }
    return -1; // erro, tabela cheia
}

int remover(hash *tabela, elem k){
    int pos;
    for(int i = 0; i < B; i++){
        pos = h(k, i); //calcula endereco
        if(tabela->vet[pos] == k){
            tabela->vet[pos] = -2;
            return pos; // sucesso
        }
        if (tabela->vet[pos] == -1)
            return - 1; // erro, elemtnonao encontrado (tabela com espaco)
    }
    return -1; // erro, elemento nao encontrado (tabela cheia)
}

int buscar(hash *tabela, elem k){
    int pos;
    for(int i = 0; i < B; i++){
        pos = h(k, i); //calcula endereco
        if(tabela->vet[pos] == k)
            return pos; //sucesso
        if(tabela->vet[pos] == -1)
            return -1; //erro, elemento nao encontrado (tabela com espaco)
    }
    return -1; // erro, elemento nao encontrado (tabela cheia)
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