//* Aula 1 da 7 semana
// mesmo projeto das priemrias aulas

#define TAM 10000001

typedef int elem;

typedef struct {
   elem *elementos;
   elem *copia;
   long tamanho;
} lista;

void cria(lista *l);
void destroi(lista *l);
int insere(lista *l, elem e);
void imprime(lista *l);
void ordena_nlogn(lista *l);
void ordena_bubblesort(lista *l);
void ordena_bubblesort_aprimorado(lista *l);
void ordena_quicksort(lista *l);
void ordena_insercao_simples(lista *l);
void ordena_shellsort(lista *l);
void ordena_selecaodireta(lista *l); // antigo ordena_quadratico