// Teste de conceitos e sintaxe em C
// programa que 

#include <stdio.h>
#include <stdlib.h>

int sum(int *a, int *b, int *soma){

    *soma = *a + *b;
    return 0;
}

int main(int argc, char *argv[]) {

    int a, b, soma;
    int *pa = &a, *pb = &b, *psoma = &soma;

    scanf("%d %d", &a, &b);
    printf("\npa= %d\npb= %d\npsoma=%d\na=%d\nb=%d\nsoma=%d\n", pa, pb, psoma, a, b, soma);
    sum(pa, pb, psoma);
    printf("\npa= %d\npb= %d\npsoma=%d\na=%d\nb=%d\nsoma=%d\n", pa, pb, psoma, a, b, soma);
    
    printf("\n%d + %d= %d", pa, pb, psoma);
    printf("\n%d + %d = %d", a, b, soma);
    return 0;
}