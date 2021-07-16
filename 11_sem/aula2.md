# Aula dia 15/07/2021
>**Analise de algoritmos de busca e complexidade**

## Hashing estático

* https://www.youtube.com/watch?v=_VtFboXVrlw (1h e 20 min)

### Hashing aberto 

* A tabela de buckets indo de 0 a B - 1, contem apenas ponteiros para uma lista de elementos 
* Quando há uma colisão, o sinônimo é inserido no bucket como um novo nó da lista
* Busca debve percorrer a lista

* se as listas estiverem ordenadas, reduz-se o tempo de busca (normalmente é mais comunm aplicar buscas sequennciais ou em arvore, binaria nao vai dar mto certo)

>  Vantagens e desvantagens

* Vantagens
    * A tabela pode receber mais itens mesmo quando o bucket ja foi ocupado
    * Permite percorrer a tabela por ordem de valor hash

*  Desvantagens
    * Espaço extra para listas
    * Listas longas implicam em muito tempo gasto na busca
        * Se as listas estiverem ordenadas, reduz-se o tempo de busca
        * CUsto extra com a ordenação
        * POssivel solução: Trocar listas por arvores binarias de busca balanceadas

### Complexidade

(Hashing Estatico)

* Hashing Fechado
    * Depende da tecnica de rehash
        * com overflow progressivo, após varias inserções e remoções o numero de acessos aumenta
    * A tabela pode ficar cheia
    * Pode haver mais espaço para a tabela, pois não são necessarios ponteiros e campos extras como no aberto

* Hashing Aberto
    * Depende do tamanho das listas e da função hash
    * Listas longas degradam o desempenho
        * Problema amenizadotrocando-se listas por arvores
    * Poucas colisoes implicam listas pequenas

### Outras funções boas para Hashing

> Tradicional: 
* h(k) = (k*A % 1) % B, A uma constante entre 0 e 1, e B um numero primo
    * (k*A % 1) recupera a parte fracionária de k * A
    * Knuth sugere: A = (sqrt(5) - 1)/2 = 0.6180...

> Hash universal

* A função hash é escolhida aleatoriamente no inicio de cada execução, de forma que minimize tendencias das chaves

* exemplo: h(k) = ((A*k + C)%P)%B => (h é chamado de coleção universal)
    * P é um primo maior que a maior chave k (vale a pena superestimar)
    * A é uma constante escolhida aleatoriamente de um conjunto de constatnes {0, 1, 2, ... P - 1}
    * B é igual A só que comecã no 1: {1, 2, ... P - 1}
    * B é um num primo indicando o tamanho da tabela

### Desvantagens do Hashing

* Principal desvantagem: Os elementos da tabela não são armazenados sequencialmente e nem sequer existe um medo prático para percorrê-los em sequência (arvore balanceada de bsuca faz isso)

