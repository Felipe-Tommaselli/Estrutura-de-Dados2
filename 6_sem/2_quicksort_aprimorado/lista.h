//* Aula 2 da 6 semana, quicksort aprimorad (com duplicatas)
// mesmo projeto das priemrias aulas

#define TAM 1000001

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
void ordena_quadratico(lista *l);
void ordena_bubblesort(lista *l);
void ordena_bubblesort_aprimorado(lista *l);
void ordena_quicksort(lista *l);
