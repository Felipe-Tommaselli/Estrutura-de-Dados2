# Aula dia 19/07/2021
>**Paradigmas de programção**

## Paradigmas de programação

* https://www.youtube.com/watch?v=fNKBRt3vdQ0

### Contextualização

* Infelizmente, não existe um paradigma que seja melhor dentre todos!

* Um paradigma pode levar a uma resolução O(n), outro a um O(log n), logo é preferivel o segundo paradigma do ponto de vista do custo de tempo

* Alguns paradigmas:
    * Recursividade
    * Algoritmos tentativa e erro
    * Divisão e conquista
    * Algoritmos gulosos
    * Algoritmos aproximados
    * Programação dinâmica

> Recursividade

* Soluções mais elegantes e claraas
    * Não recomendada as vezes

* obs: não é consenso se é um paradigma ou tecnica de programação

* Critérios fundamentais
    * Definição recursiva do problema
    * Condição de parada
    * Garantia de terminar

> Algoritmos tentativa e erro

* Um Algoritmos tentativa e erro é aquele que testa **exausivamente** todas as soluções possiveis

* As soluções são testadas indiscriminadamente (muito caro normalmente)

* As soluções são enumeradas de modo semelhante ao percurso em uma arvore que possua as soluções
    * muitas vezes o caminho da "arvore" cresce exponencialmente

* Exemplo melhor caminho entre cidades: 25 min

> Divisão e conquista

* Passos básicos
    * Dividir o problema a ser resolvido em subproblemas menores e independentes
    * Encontrar soluções para as partes
    * Combinar as soluções obtidas em uma global

* Podem utilizar a recursão (geralmente é coerente utilizar)

* Exemplos: 43 min

* Mergesort, Quicksort, Fibonacci recursivo, busca binaria...

> Algoritmos gulosos

* Utilizados para problemas de otimização (mas podem nao produzir soluções otimas)

* Por exemplo, o algoritmo para encontrar o caminho mais curto entre duas cidades
    * Um algoritmo guloso escolhe a estrada que parece mais promissora no instante atual e nunca muda essa decisão, independentemente do que pode acontecer depois

* Exemplo: 50 min (Algoritmo de Dijkstra)

> Algoritmos aproximados

* Gera soluções aproximadas, que podem não ser otimas, mas são proximas delas

* Faz-se necessaria uma medida de qualidade

* Exemplos: 
    * Caixero vigiante (menor caminho entre todas as cidades)
    * Tradução automatica
    * Dimensõa intrínseca => Dimensão fractal de correlação D2

> Programação dinâmica

* Programação dinamica é um paradigma que tem como objetivo reduzir o tempo de execuçãpo de um programa utilizando soluções ótimas a partir de subproblemas calculados (basicamente uma otimização de tempo na divisão e conquista)

* Etapas
    * Dividir o problema em subproblemas 
    * Computar os valores de uma solução de forma ascendente e memoriza-los
    * Construir a solução ótima para cada subproblema com os valores computados

Exemplos: Gramatica (1h e 23 min) e Fibonacci (1h e 26 min)