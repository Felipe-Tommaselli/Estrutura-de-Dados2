// semana 13, algoritmo de fibonacci com divisao e conquista e com prog dinamica

#include <stdio.h>

// Aplicação simples da divisao e conquista 
int fib_divconq(int n){

    if(n == 0 || n == 1)
        return n; //condicao de parada
    return fib_divconq(n - 1) + fib_divconq(n - 2);
}

// Aplicacao da programacao dinamica, armazenando os valores ja calculados da seq de
// fibonacci, onde evitamos retrabalhos nas contas internas
int fib_progdin(int n){
    
    int v[n + 1], i;
    
    if(n == 0 || n == 1)
        return n; //condicao de parada
    v[0] = 0;
    v[1] = 1;
    
    for(i = 2; i <= n; i++)
        v[i] = v[i - 1] + v[1 - 2]; // rodada calcuando o fibonacci
    return v[n];
}

int main(void){

    int n, res;
    printf("Entre com o numero que queira calcular a sequencia de FIbonacci (-1 para sair) ");
    scanf("%d", &n);
    
    while(n != -1){
        //res = fib_divconq(n);
        res = fib_progdin(n);
        printf("Resultado: %d\n", res);
        printf("Entre com outro numero que queira calcular a sequencia de FIbonacci (-1 para sair) ");
        scanf("%d", &n);

    }


}