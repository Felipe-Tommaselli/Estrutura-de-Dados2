# Aula dia 15/06/2021
>**Analise de algoritmos de ordenação e complexidade, mais exemplos**

## Implementaçaõ shell sort

* auala no coemco (bem no 1 min msm) ele revisa o insertion sort e o shell sort
* https://www.youtube.com/watch?v=PHK6whK06b8

* para a implementação vamos seguir uma sugestão de chute do h para o shell sort do "Knuth (1973)"
    * defina uma funcao recursiva h tal que 
        * h(1) = 1
        * h(i + 1) = 3*h(i) + 1

* complexidade do shellsort: O(n*(log n)^2)

## Ordenação por seleção

* Ideia basica: Os elemetnos são selecionados e dispostos em suas posições corretas finais

* Seleção direta (ou simples), ou cclassificação de deslocamento descendente

* Heap-sort, ou método do monte

### Seleção direta 

> Método

* Selecionar o elemento que apresenta o menor valor
* Trocar o elemetno de lugar com o prmeiro element oda sequencia, x[0]
* Repetir as operações 1 e 2m envolvendo agora apenas os n - 1 elemetnos restantes, depois os n - 2 elementos, etc ...,até restar somente um,o maior deles

* Explicação (min 7):
https://www.youtube.com/watch?v=hYa367wrNOE
(é bem facinho confia)

* O ORDENA_QUADRATICO É O SELEÇÃO DIRETA

> Complexidade

* (n - 1) + (n - 2) + ... 1 = n*(n - 1)/2 
    * O(n2)

* nao melhora ou piora para entradsa mais ou menos ordenadas

* é melhor que o bubblesort, pois faz menos operações
    * talve melhor que o insertionsort

* se o n é pequeno e sua aplicação nao exige nada sofisticado, ele é bem bom. FORA ISSO NÃO.

### Heap-sort

> Método

* Utiliza um heap para ordenar os elementos 
    * NÃO é a mesma heap que falamos para espaço de armazenamento de variaveis dinamicas

* Um heap nesse contexto é uma estrutura de dados em que há uma ordenação entre lementos: representação via arvore binaria (cada nó tem 2 filhos)

* Explicação (a partir dos 29 min)
https://www.youtube.com/watch?v=hYa367wrNOE

* Um heap observa cocnetios de ordem e de forma

* **Ordem**: O item de qualquer nó deve satisfazer uma relação de ordem com os itens dos nós filhos

* 2 possiblidades de escolha analogas:
    * Heap maximo (ou descendente): pai >= filho, sendo que a raiz é maior elemento
    * Heap minimo (ou ascendente): pai <= filho, sendo que a raiz é menor elemento
    
* **Forma**: A arvore binaria tem seus nó-folha, no maximo, em dois nvieis, sendo que as folhas devem ser o maximo a esquerda possivel

* Exemplos de arvores que não são heaps (min 35)
https://www.youtube.com/watch?v=hYa367wrNOE

* Obs: O heap pode ser representado por um vetor