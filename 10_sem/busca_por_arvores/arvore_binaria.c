// Aula semana 10 sobre arvores binarias

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef int elem;



int main(void){

    Arvore a;
    int i;

    cria(&a);

    for(i = 0; i < 10; i++)
        insere(&a, rand() % 100);
    
    printf("Elementos ordenados(")
    emOrdem(&a);
    print(")\n")

    for(i = 0; i < 100; i++)
        if(busca(&a, i) != NULL)
            printf("Achou o elemento: %d\n", i);

    destroi(&a);

    return 0;
}