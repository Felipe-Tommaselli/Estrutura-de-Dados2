# Aula dia 18/06/2021
>**Analise de algoritmos de ordenação e complexidade**

## Continuação Heapsort

* aula: https://www.youtube.com/watch?v=g0v12ZOfEkw

### Implementação 

* Representar a arvore binaria do heap com um vetor
    * a arvore precisa da bem feita (todos elementos ordenados e pela esquerda)

* em um nó k
    * filho esquerdo: 2k + 1
    * filho direito: 2k + 2
    * pai do nó k: (k - 1)/2

* outra propriedade mto boa é que as folhas estão sempre de n/2 em diante entre elas

* exemplo no minuto 12 da aula

* procedimentos principais: construir o heap e rearranjar o heap

### Complexidade

* O(nlogn), para caso medio e pior

* para o melhor é O(n) 

* Ele não é muiot util para pequenos registros, uma vez que o custo de construir a heap é basicamente o mesmo

## Ordenaçaõ por contagem de menores

video: https://www.youtube.com/watch?v=pxudwHDmWiA

### ideia principal

* se soubermos quantos elemetnos sao menores que um determinado valor, saberemos sua posicção correta para ordenação
    * se num veotr de 8 elementos sabemos que ha 5 valores menor que 7, sabemos que ele deve ocupar a 6º posição

* explicaçaõ no min 7

### Compelxidade

* Quadratico, basicamente roda 2 for aninhados (tirando outros for independentes), ou seja, é um algoritmo bem caro e não tão intuitivo quanto outros quadraticos como o bubble
    * O(n^2) 

* serve apenas de base para a ordenaçaõ por tipos, que é mais eficiente

* para a compelxidade de espaço tbm nao é boa, uma vez que ele tem que realocar 3 vezes uma coopia, um O(3n)

## Counting sort (contagem de tipos)

https://www.youtube.com/watch?v=uxFkJOr50bI

### Implementação

* Ideia básica: conta-se o numero de vezes que cada elemento ocorre no arranjo; se há k elementos antes dele, ele seá inserido na posição k + 1 do arranjo
    * elemenetos devem estar contido em um intervado de numeros inteiros positvios

* Usa-se um arranjo auxiliar para manter a contagem de tipos e um outro para montar o arranjo ordenado

* explicação 7 min ( é bem intuitivo)

### Complexidade

