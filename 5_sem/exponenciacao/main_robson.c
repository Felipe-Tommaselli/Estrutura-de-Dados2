#define TAM 100000000
#define repeticoes 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long exponenciacao_n(long x, long n) {
    long res = 1;
    for (long i = 0; i < n; i++)
        res *= x;
    return res;
}
        
long exponenciacao_logn(long x, long n) {
    // ideia geral
    // n par:   2^4 = (2*2)^2
    // n impar: 2^5 = ((2*2)^2)*2             
    
    // recorrencia
    // T(n) = c, se n = 0
    // T(n) = T(n/2) + c, se n > 0
    if (n == 0)
        return 1; // criterio de parada
    if ((n % 2) == 0)
        return exponenciacao_logn(x * x, n / 2);
    else
        return exponenciacao_logn(x * x, n / 2) * x;
}

int main(void) {
    //int x = 3;
    //int n = 3;
    //printf("O valor de %d elevado a %d eh: %ld\n", x, n, exponenciacao_logn(x, n));
    
    clock_t soma_tempo, tempo_ini;
    int x = 2;
    for (long i = 10000000; i <= TAM; i += 10000000) {
        soma_tempo = 0;
        for (int j = 0; j < repeticoes; j++) {
            tempo_ini = clock();
            exponenciacao_n(x, i);
            soma_tempo += clock() - tempo_ini;
        }
        printf("%ld\t%0.20lf\n", i, soma_tempo / (double) repeticoes);
    }
    
    return 0; // sucesso
}