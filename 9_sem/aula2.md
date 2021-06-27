# Aula dia 24/06/2021
>**Analise de algoritmos de busca e complexidade**

## Algoritmos de busca

* aula: https://www.youtube.com/watch?v=gqsHTkB138M

### A busca (pesquisa)

* A tarefa de buscar é muito comum

* o que é a busca: "Dado um conjunto de elementos, onde cada um é identificado por uma chave, o objetivo da busca é localizar, nesse conjunto, o elemento que corresponde a uma chave especifica"

* Alguns termos:
    * **Tabela**: termo genérico, pode ser qualquer estrutura de dados usada para armazenamento e organização de dados
    * Uma tabela é um conjunto de elementos chamados **registros**
    * **Chave**, elemento associadoa a cada registro que diferencia cada registro entre si

> Tipos de chaves (onde ela esta armazenada): 

* **Chave interna**: Chave esta contida dentro do registro em uma localização especifica

* **Chave externa**: Chave esta contida em uma tabela de chaves separadas que inclui ponteiros para o registro

> Tipos de chaves (identificação de registros): 

* **Chave primária**: Para todo arquivo existe pelo menos um conjunto exclusivo de chaves
    * dois registros não tem o mesmo valor de chave

* **Chave secundária**: São quaisquer outras chaves não primárias
    * não garantem valores exlclsivos, adimitem duplicatas

> Tipos de busca dependem do tipo de tabela

* A tabela pode ser:
    * Arranjo tradicional (sequencial ou estatico) de registros
    * Lista encadeada
    * Arvore
    * ...

* A tabela pode ficar:
    * Totalmente na memória (busca intena) >> FOCO DO CURSO <<
    * Totalmente no armazenamento auxiliar (busca externa)
    * Dividida entre ambos

### Implementação de buscas

* Algumas tenicas de busca interna mais comuns são:
    * Busca sequencial
    * Busca binaria
    * Nusca por interpolação
    * Busca em arvores
    * Hashing
    * ...

* Cada tecnica tem vantagens e desvantagens, a ideia é dentro de um conjunto de dados encontrar a busca mais otimizada
    * Apenas no Hashing o custo de memoria é relevante, no resto deve-se naalisar apenas o tempo 

## Busca sequencial

video: https://www.youtube.com/watch?v=gqsHTkB138M (27 min)

### Implementação

* A busca sequencial é a forma mais simles de busca
    * É aplicavel a uma tabela organizado como uma lista sequencial ou como uma lista encadeada
    * Percorre-se registro por registro em busca da chave

* Limitações do arranjo tradicional
    * tamanho fixo pode desperdiçar espaço

* Uma alternativa é a Lista encadeada

### Complexidade

* Se o registro for o primeiro: 1 comparação

* Se for o ultimo: N comparações

* Se for igualmente provável que o arguento apareça em qualquer posição da tabela, em média: N/2 comparações

* Se a busca for mal sucedida: N comparações

Logo, a busca sequencial é, no pior caso, O(N)

## Busca sequencial com sentinela

video: https://www.youtube.com/watch?v=gqsHTkB138M (55 min)

### Implementação

* Uma maneira de tornar a busca sequencial mais eficiente pe usar um sentinela

* Sentilena: Adicionar um elemento de valor x no final da tabela

* O sentinela garante que o elemento será encontrado o que elimina um teste melhorando a performance da busca

### Complexidade 

* Mesma analise da bsuca sequencial O(n)

* Apenas ha uma melhora de perfomance