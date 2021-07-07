// Aula semana 10 sobre arvores binarias

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef int elem;

// cria as estrutura da arvore
typedef struct no{
    elem info;
    struct no *esq, *dir;
} No;

typedef struct{
    No *raiz;
} Arvore;

// cria a arvore
void cria(Arvore *a){
    a->raiz = NULL;
}

void destroi_rec(No *p){

    if(p != NULL){
        destroi_rec(p->esq);
        destroi_rec(p->dir);
        free(p);
    }
}

void destroi(Arvore *a){
    destroi_rec(a->raiz);
    a->raiz = NULL;
}

void emOrdem_rec(No *p){

    if(p != NULL){
        emOrdem_rec(p->esq);
        printf(" %d ", p->info);
        emOrdem_rec(p->dir);
    }
}

void emOrdem(Arvore *a){
    emOrdem_rec(a->raiz);
}

No *busca_rec(No *p, elem e){
    if(p == NULL || e == p->info)
        return p; //sucesso ou nao achou
    // busca recursivamente na sub arvore apropriada
    return (e < p->info) ? busca_rec(p->esq, e) : busca_rec(p->dir, e);
}

No *busca(Arvore *a, elem e){
    return busca_rec(a->raiz, e);
}

int insere_rec(No **p, elem e){
    // p => No **
    // *p => No *
    // **p => No

    if( *p == NULL){
        // cria nova caixa e insere
        *p = malloc(sizeof(No));
        ( *p)->info = e;
        ( *p)->esq = ( *p)->dir = NULL; //novo nó é folha, por isso tem filhos nulos
        return 0;
    }
    if(e == ( *p)->info)
        return 1; //erro, elemento repetido
    return (e < ( *p)->info) ? insere_rec(&(( *p)->esq), e) : insere_rec(&(( *p)->dir), e);
}  

int insere(Arvore *a, elem e){
    return insere_rec(&(a->raiz), e);
}

int main(void){

    Arvore a;
    int i;

    cria(&a);

    for(i = 0; i < 10; i++)
        insere(&a, rand() % 100);
    
    printf("Elementos ordenados(");
    emOrdem(&a);
    printf(")\n");

    for(i = 0; i < 100; i++)
        if(busca(&a, i) != NULL)
            printf("Achou o elemento: %d\n", i);

    destroi(&a);

    return 0;
}