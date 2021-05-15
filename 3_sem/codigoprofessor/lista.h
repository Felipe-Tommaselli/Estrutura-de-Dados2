// Pratica: teste do tempo de execução:
// * Busca binaria semana 4 aula 1

#define TAM 100000001

typedef int elem;

typedef struct {
   elem *elementos;
   elem *copia;
   long tamanho;
   int ordenado;
} lista;

void cria(lista *l);
void destroi(lista *l);
int insere(lista *l, elem e);
void imprime(lista *l);
void ordena(lista *l);
int busca_repeticao(lista *l, elem e);
int busca(lista *l, elem e);
