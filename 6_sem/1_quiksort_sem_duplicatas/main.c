//* Aula 2 da 6 semana, quicksort
// projeto diferente

#define repeticoes 2
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef int elem;

void quick_sort_sem_duplicatas_recursivo(elem vet[], int ini, int fim){
    int i = ini;
    int j = fim;
    elem pivo, aux;

    if (ini < fim){ // chamou o vetor com duplicata,retorna erro

    pivo = vet[ini + (fim - ini)/2]; // pivo é sempre o elemento central

    while (1){
        //posiciona i;
        for (i; vet[i] < pivo; i++);

        //posiciona j;
        for (j; vet[j] > pivo; j--);

        if (i == j)
            break;

        // troca 
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
    }

    quick_sort_sem_duplicatas_recursivo(vet, ini, i - 1);
    quick_sort_sem_duplicatas_recursivo(vet, i + 1, fim);
    
    }
}

void quick_sort_sem_duplicatas(elem vet[], int n){
    return quick_sort_sem_duplicatas_recursivo(vet, 0, n-1);

}

int main(void) {
    int n = 8;
    elem vet[] = {25, 57, 35, 37, 12, 86, 92, 33};

    printf("Orignial: ");
    for (int i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n");
    
    quick_sort_sem_duplicatas(vet, n);

    printf("Ordenado: ");
    for (int i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n");
    
    return 0;

}