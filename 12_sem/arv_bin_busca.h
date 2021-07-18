
typedef int elem;

// cria as estrutura da arvore
typedef struct no{
    elem info;
    struct no *esq, *dir;
} No;

typedef struct{
    No *raiz;
} Arvore;

void cria_abb(Arvore *a);
void destroi_abb(Arvore *a);
void emOrdem_abb(Arvore *a);
No *busca_abb(Arvore *a, elem e);
int insere_abb(Arvore *a, elem e);
int remover_abb(Arvore *a, elem e);