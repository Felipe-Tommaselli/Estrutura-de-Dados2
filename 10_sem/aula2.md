# Aula dia 01/07/2021
>**Analise de algoritmos de busca e complexidade**

## Busca binária

* aula: https://www.youtube.com/watch?v=y6MU2uOxewY

### Implementação

* Exige que a tabela esteja ordenada

* Divisão recursiva ou iterada do intervalo: O elemento buscado é comparado ao elemento do meio do arranjo
    * Se forem iguais, busca bem sucedida
    * Se for menor que o meio, busca-se na metade inferior do arranjo
    * Se for maior que o meio, busca-se na metade superior do arranjo

* Exemplo min 7

* A cada passo o tamanjp dp arranjo é divido por 2

> Exercicio: Implementar esse algoritmo de forma iterativa

### Complexidade

* A busca binaria é O(log n), pois os candidatos a serem buscados diminuem de 2 em 2

> Vantagens

* Muito eficiente

* Facil implementação

> Desvantagens

* Nem todo arranjo esta ordenado

* Exige o uso de uma lista sequencial para armazenar os dados

* Inserção e remoção de elementos são ineficientes

### Atenção

* A busca binaria pode ser usada com a organização de tabela sequencial indexada
    * em vez de pesquisaro indice sequencialmente, pode-se usar uma busca binaria

* A busca inaria TEM relação com a arvore binaria

## Busca por interpolação

* video: https://www.youtube.com/watch?v=y6MU2uOxewY min 41

### Implementação

* Se as chaves estiverem uniformemente distribuidas, esse metodo pode ser mais eficiente que a busca binaria

* Com chaves unif. distribuidas, pode-se esperar que x esteja aproximadamente na posição:
    * meio = inf + (sup - inf)*((x - A[inf])/(A[sup] - A[inf]))
        * sendo que inf e sup são redefinidos iterativamente como na busca binaria

* Exemplo min 46

### Complexidade

* Se as chaves estiverem uniformemente distribuidas, custo: O(log(log n)) 
    * Só confia

* Caso não haja uma distribuicao uniformemente, o custo pode ser bem ruim como da busca sequencial simples (O(n))

* Em situações praticas, é difcil haver essa distribuicao
    * exemplo: Há mais nomes com "S" do que com "Q"

> Exercicio: Implementar a busca por interpolação, com recursividade e sem recursividade

## Busca em arvores

* video: https://www.youtube.com/watch?v=y6MU2uOxewY min 55

### Implementação


