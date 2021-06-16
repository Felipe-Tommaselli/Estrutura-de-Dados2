/*
============== PROJETO DE ESTRTURUAS DE DADOS 2 ==============

Felipe Andrade Garcia Tommaselli 11800910
Gianluca Capezzuto Sardinha 

Explicação projeto:  https://ae4.tidia-ae.usp.br/access/content/attachment/61c65473-dfd7-45e0-9c5b-f83baa36b63d/Atividades/ecbb2c9d-24c5-4329-a2b2-84b2cdca1331/projeto_1.pdf

* Arquivo header
*/

#define TAM 100000001

typedef int elem; // inicia o tipo elemento como int

typedef struct{
   elem *elementos; 
   long tamanho;
} list;

void cria(list *l);
void destroi(list *l);
int insere(list *l, elem e);
int insere_crescente(list *l, elem e);
int insere_decrescente(list *l, elem e);
void imprime(list *l);
void bubblesort(list *l);
void bubblesort_aprimorado(list *l);
void quicksort(list *l);
void radixsort(list *l);
void heapsort(list *l);
