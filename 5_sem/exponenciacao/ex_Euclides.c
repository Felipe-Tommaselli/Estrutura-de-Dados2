// Aula 1 semana 5, algoritimo linear 
// encontrar a estimativa do alogirtmo de euclides (MDC)

// Computo do maximo dvisor comum entre dois numeros m e n, m >= n
// ex: mdc(50, 15) = 5

#include <stdio.h>
#include <stdlib.h>

int mdc(int m, int n){

    int aux = 0;
    while (n > 0){
        aux = m % n;
        m = n;
        n = aux;
    }
    return(m);

    // * custo debe ser o do looping só, entçao vai da um O(n)
}

int main(void){

    int m, n;
    m = 80;
    n = 12;

    printf("mdc de %d e %d: %d\n", m, n, mdc(m,n));
    return 0;
}