// Pratica: teste do tempo de execução:
// * Complexidade quadrática

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    lista l;

    cria(&l);
    insere(&l, 3);
    insere(&l, 2);
    insere(&l, 1);

    imprime(&l);

    ordena(&l);

    imprime(&l);

    return 0;
}