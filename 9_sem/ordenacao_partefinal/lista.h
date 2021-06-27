//* Aula 1 da 9 semana
// mesmo projeto das priemrias aulas

#define TAM 1000000001

typedef int elem;

typedef struct {
   elem *elementos; // elementos do vetor (valores)
   long *contagens; // contagens de =s para o ordena_contagem_menores
   elem *copia; //copia do veotr
   long tamanho; // tamanho do vetor
} lista;

void cria(lista *l);
void destroi(lista *l);
int insere(lista *l, elem e);
void imprime(lista *l);
void ordena_mergesort(lista *l); // antigo ordena_nlogn
void ordena_bubblesort(lista *l);
void ordena_bubblesort_aprimorado(lista *l);
void ordena_quicksort(lista *l);
void ordena_insercao_simples(lista *l);
void ordena_selecaodireta(lista *l); // antigo ordena_quadratico
void ordena_heapsort(lista *l);
void ordena_contagem_menores(lista *l);
void ordena_counting_sort(lista *l);
void ordena_radixsort(lista *l);