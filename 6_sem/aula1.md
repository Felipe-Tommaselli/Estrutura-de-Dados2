# Aula dia 29/05/2021
>**Algoritmos de ordenações, conceitos gerais e exemplos**

## Quicksort

* Algoritmo mais conhecido e utilizado no mundo 

* Melhoramento do bublle-sort 
    * troca de elementos distantes são mais efetivas

* Ideia basica: Dividir e conquistar
    * Dividir o vetor em dois vetores menores que serão ordenados independentemente para produzir o resultado final

* Considerando um vetor v de n posições

* Primerio passo:
    * Elemento pivô: x (importante!!!)
    * Ordenar de forma que os elementos a esquerda do pivo são <= a ele, e os elementos a direita são >= a ele
        * Percorre ro vetor v da esquerda para a adireita até v[i] >= x; e da direita pra esquerda até v[i] <= x
            * Troca v[i] com v[j]
        * Quando i e j se cruzarem, a iteraçaõ finaliza de forma que v[0]... v[j] são menores ou iguais a x e v[i]... v[n-1] são maiores ou iguais a x

* Segundo passo:
    * Ordenar sub-vetores abaixo e acima do elemetno pivô

> Exemplo

v = {25 57 35 37 12 86 92 33}

* pivo: elemento do meio (só pra ficar + facil)

* meio ruim de ver, mas é facil de entender: 
https://www.youtube.com/watch?v=39h3sXOKC2E
(min 12)

* não funciona com duplicatas (se o pivo tiver uma duplicata ele fica em looping infinito)

> Complexidade

* A complexidade depende muito do pivo

* Pior caso: Escolha do vetor pegar os extremos (maior ou menor)
    * O(n^2) igual do bubblesort

* Caso ideal: Escolha do pivo divide o vetor bem no meio
    * O(n log n), log base 2??nao sei pq

* Caso médio: Sedgewick e Flajelot (1996)
    * T(n) = 1.386 log n - 0.846n
    * Continua sendo O(n log n), mas pelas constatnes pequenas elas fazem uma certa diferenca
    * (log na base 2)

obs: Para evitar o pior caso uma boa escolha é, escoher 3 elementos quaisquer do vetor e usar a mediana deles como pivo. Não é perfeita, mas estatisticamente é muito melhor do que ir no aleatorio


