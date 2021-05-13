// 3 semana (busca binaria) aula 2

#define TAM 101
// tamanho maximo da lista

typedef int elem;
// definir um tipo elemento

typedef struct Lista{
    elem *elementos; // vetor com cada elemento
    elem *copia; // lista auxiliar para a ordenacao
    long tamanho;
    int ordenado;   
} lista;

void cria(lista *l); 
// é necessario passar o ponteiro para alterar o valor da lista
void destroi(lista *l);
int insere(lista *l, elem e);
//não necessidade de passar e como ponteiro por ter um tamanho pequeno, é mais facil criar outro
void imprime(lista *l);
void ordena(lista *l);
int busca_repeticao(lista *l, elem e);
int busca(lista *l, elem e); // com recursao
// espera-se que a busca com repetição seja um pouco mais rapida 
// que a com recursao, mas o custo no fim sera praticamente igual

// é possivel passar so lista l e ai criar uma copia com a lista, ai ela não pode ser alterada,
// porem pasar por referencia lista *l é melhor para o uso de memoria do pc, só tomar cuidado 