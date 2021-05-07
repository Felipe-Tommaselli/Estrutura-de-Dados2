# Aula dia 30/04/2021
>**Analise de algoritmos, voltada para a analise de recorrencias (recursividade)**

## Regras para calculo das recursividades

* Se a recursão é um "disfarce" da repetição (e, portanto, a recursão esta mal empregada em geral), basta analisa-la como tal

> Exemplo da aula passada:

> sub-rotina fatorial(n: numérico)
inicio
se n<= 1
    entao  aux<- 1
    senão aux,- n*fatorial(n-1)
retorne aux;
fim

* obs: podemos reescrever o codigo retirando a recursão, e adiconando um processo iterativo

> sub-rotina fatorial(n: numérico)
inicio
se n<= 1
enquanto n>1 faca
    aux<- aux*n
    n<- n - 1
retorne aux;
fim

* Em muitos casos (incluindo casos em que a recursividade é bem empregada), é dificil transforma-la em repetição
    * Nesse caso a analise pode ser feita pela **analise de recorrencia**

* **Recorrencia**: Equação ou desigualdade que descreve uma função em termos de seu valor em entradas menores

> Exemplo Fibonacci:
sub-rotina fib(n: numérico)
inicio
declare aux numérico
se <= 1
    então  
        aux <- 1
    senão
        aux <- fib(n-1) + fib(n-2);
retorne aux;
fim

* Resolução: Analisar caso a caso

    * **Caso 1:** se n=0 ou 1, o tempo de execução é constante, que é o tempo de testar o valor de n no comando se, mais atribuir po valor 1 a variavel aux, mais o retornoo, ou seja T(0) = T(1) = 3
    
    * **Caso 2:** Se n>1, o tempo consiste em testar o valor de n no comando se, mais o trabalho a ser executado no senão (que é uma soma, uma atribuição, 2 subtrações e 2 chamadas recursivas), mais o retorno da função, ou seja T(n) = T(n-1) + T(n-2) + 6 (função de recorrencia)

*  Com a formula de recorrencia do problema temos que utilizar métodos para resolver:
    * Método da substituição
    * Método da arvore de recursão
    * Método mestre

## Resolução de recorrências: Métodos

* **MÉTODO DA SUBSTITUIÇÃO**

* Supõe-se ("chute") um limite superior para a função e verifica-se se ela não extrapola esse limite
    * Indução baseada em um palpite
    * Método bom para ser combinado com algum outro que dê um palpite inicial: como o da arvore de recursão

* **ARVORE DE RECURSÃO**

* Esboça-se uma arvore que , nivel a nivel, representa as recursções sendo chamadas

* Em seguid, em cada nivel/nó da arvore, são acumulados os tempos necessarios
    No final, tem-se a estimativa de tempo do problema

* Este método pode se rutilizaado para fazer um suposição mais informada no método da substituição

> Exemplo: Algoritmo de ordenaçõa de arranjos por intercalação (dividir e conquistar)

Passo 1: Divide-se um arranjo não ordenado em dois subarranjos

Passo 2: Se os subarranjos não são unitarios, cada subarranjo é submetido ao passo 1 anterior; caso contrario, eles são ordenados por intercalação dos elementos e isso é propagado para os subarrnajos anteriorres

* Rotina principal (após analisar o código):
    * Se n = 1 elemeneto no arranjo, ordenação não é necessaria: 1 unidade de tempo
    * Se n>1
        *  O problema é divido em subproblemas: 3 operações constantes
        * Os subproblemas são processados: 2 subproblemas, sendo que cada um tem metade do tamanho original = 2T(n/2)
        * As soluções são combinadas O(n)

Equações de complexidade do algoritmo:
    
    * T(n) = O(c) = 1, se n = 1
    * T(n) = 2T(n/2) + O(c) + O(n), se n > 1

Como O(c) << O(n):

    * T(n) = O(c) = 1, se n = 1
    * T(n) = 2T(n/2) + O(n), se n > 1

Como quremso uma equação de limite superior, ou seja, o pior caso possivel sendo previsto, O(n) = n:

    * T(n) = O(c) = 1, se n = 1
    * T(n) = 2T(n/2) + n, se n > 1

* Após analisar a arvore de recursão chegamos que na resolução da recorrencia
> como resultado, tem-se **n log n + n**
, ou seja:

> **O(n log n)**

> Exemplo 2: Busca binária em um vetor ordenado, pesquisa por numero 3

* implementação experiemtnal 