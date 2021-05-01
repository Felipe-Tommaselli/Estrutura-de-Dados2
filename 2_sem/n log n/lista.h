// 2 semana (n log n)

#define TAM 101
// tamanho maximo da lista


typedef int elem;
// definir um tipo elemento

typedef struct Lista{
    elem *elementos; // vetor com cada elemento
    elem *copia; // lista auxiliar para a ordenacao
    long tamanho;  
} lista;

void cria(lista *l); 
// é necessario passar o ponteiro para alterar o valor da lista
void destroi(lista *l);
int insere(lista *l, elem e);
//não necessidade de passar e como ponteiro por ter um tamanho pequeno, é mais facil criar outro
void imprime(lista *l);
void ordena(lista *l);
