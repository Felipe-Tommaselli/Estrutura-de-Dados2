# Aula dia 29/05/2021
>**Algoritmos de ordenações, conceitos gerais e exemplos**

## Ordenção por inserção

* Inserir um dado element em sua posição correta em um subconjunto ja ordenado

* 2 metodos princiapis
    * Inserção simples (direta)
    * Shell Sort (classificação de shell, ou classificação de incremento descrescente)

## Inserção simples

* Ordenar o conjunto inserido os elementos em um subconjunto ja ordenado

* No i-ésimo passo, inserir o i-ésimo elemento na posição correta entre x[0],...[x-1] ja ordenado
    * Elementos são realocados

> Complexidade

* Melhor caso: Rodar o vetor uma vez e ele ja estar ordenado
    * O(n)

* Pior caso: Rodar o vetor quadraticamente se ele estiver em ordem inversa

* Complexidade: O(n)

> Portanto...

    * A inserção simples é eficiente para arquivos "quase ordenados", estara mais perto do linear. Caso não seja possivel garantir isso, é melhor optar por um metodo mais "seguro"

## Shell-sort

* Melhoria da inserção simples

* inserção simples movimenta elementos adjacente
    * se o menor elemento estiver na posição mais a direita, n - 1 comparações e movimentos são necessarios

* Shell-sort permite a troca de elementos distantes
    * elementos separados por h posições são ordenados de tal forma que todo h-ésimo elemento esta em uma sequencia ordenada
        * esta sequencia é dia estar h-ordenada
        * h é a distancia entre os elementos

* Explicação é meio complicadinha: 
https://www.youtube.com/watch?v=6yCj-b3Gxls (min 58)

> Ideia basica

* divdir a entrada em sub-cnjuntos de elemetnos de distancia h e aplicar a inserção simpls a cada um, sendo que h é reduzido sucetivamente
    * a cada nova iteração, o vetor original está "mais ordenado"

* Exemplo:
https://www.youtube.com/watch?v=6yCj-b3Gxls (1h)

* começamos com h > 1, quando h chegar em 1, aplicamos uma inserção simples (insertion sort é a mesma coisa que o shell sort só que para h = 1), ou seja, apenas ordemos o vetor para a inserção simples ser feita em um caso mais perto do linear

* formula para chegar nos diferentes tamanhos de h:
    * o i-ésimo elemetno do j-ésimo conjunto é: x[(i - 1)*h + j - 1]

