# Aula dia 14/05/2021
>**Analise de algoritmos, complexidade e analise assintótica**

## Analise assintótica 

* A analise assintótica é uma ferramenta fundamental ao projeto, aálise ou escolha de um algoritmo especifico para uma dada aplicação

* No entanto, deve-se ter sempre em mente que essa analise "esconde" fatores "assintoticamente irrelevante", mas que em alguns casos praticos podem ser relevantes

> Exemplo: 

* Algortimo 1: tempo de exec na ordem de (10^100)n, ele é um O(n)
* Algortimo 2: tempo de exec na ordem de (10)nlog n, ele é um O(nlogn)

* Logo seria preferivel escolher o algoritmo 1, porem devemos considerar que 10^100 é muito grande na pratica, seria necessario entradas gigantescas para ele ser mais eficinete que o 2

* obs: 10^100 é o numero de atomos no universo observável estimado

* por isso, a analise empirica pode ser mais viavel, uma vez que ja se estima a ordem de grandeza das entrasdas "grandes"

> .

    * Exercicios:
    
* exercicio 1: Problema da maior soma de subsequencia em um vetor, exemplo:
* (-2, 11, -4, 13, -5, -2) 

* Melhor soma: (11 - 4 + 13) = 20

> primeira implementação:
* cubica O(n^3)

> segunda implementação:
* quadratica O(n^2)

> terceria implementação:
* n log n O(n log n)

> quarta implementação:
* linear O(n)
