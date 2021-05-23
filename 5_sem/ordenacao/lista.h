//* Aula 2 da 5 semana, bubblesort
// mesmo projeto das priemrias aulas

#define TAM 11

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
