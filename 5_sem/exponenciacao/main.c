// Aula 1 semana 5, algoritimo linear 
// encontrar x^n

#define TAM 10000000000
#define repeticoes 100

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long exponenciacao_n(int x, int n){
    long res = 1;
    for (int i = 0; i < n; i++)
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
    // mesma recorrencia da busca binaria
    if (n == 0)
        return 1; // criterio de parada
    if ((n % 2) == 0)
        return exponenciacao_logn(x * x, n / 2);
    else
        return exponenciacao_logn(x * x, n / 2) * x;
}

int main(void){

    /*
    int x = 3;
    int n = 2;
    printf("O valor de %d elevado a %d: %ld\n", x, n, exponenciacao_n(x, n));
    */
    int x = 2;
    clock_t soma_tempo, tempo_ini;
    //o resultado não depende mto de x, mas corremos o risco de estoura o long em memoria
    //por isso é melhorutilizar valores baixos de x
    
    for (long i = 100000000; i <= TAM; i += 100000000){
        soma_tempo = 0;
        for (int j = 0; j < repeticoes; j++){
            tempo_ini = clock();
            exponenciacao_logn(x, i);
            soma_tempo += clock() - tempo_ini;
        }
        printf("%ld\t%0.2lf\n", i, (soma_tempo / (double) repeticoes));
    }
    return 0;
}

/*
* Linear: do 10k ao 100k pra demora alguns segs
Entrada           Tempo
10 000 000        25000.00
20000000          48437.50
30000000          70312.50
40000000          95312.50
50000000          118750.00
60000000          142187.50
70000000          165625.00
80000000          192187.50
90000000          214062.50
100 000 000       242187.50
* Logaritmico
não foi possivel medir, a limitação da maquinanão consegue fazer n grande o bastante
*/