# Aula dia 15/07/2021
>**Analise de algoritmos de busca e complexidade**

## Busca em Hashing conceitos iniciais

* https://www.youtube.com/watch?v=1sBqqrVm7Fo

### Revisãozinha do que vimos até agr

* Busca sequencial O(n)
    * Torna-se cada vez mais inviavel conforme as estruturas (tabelas, arquivos, etc) crescem

* Busca binária O(logn)
    * Restrtira a arranjos ordenados

* Busca interpolada O(log(logn))
    * Restrita para chaves uniformemente distribuidas, senão O(n)

* Arvores AVL O(logn)
    * Não pede arranjo ordenado, e não importa o tamanho da tabela
    * Necessita de que a arvore esteja balanceada

### Endereçamento direto

* explicação Endereçamento direto: min 8

* Cada chave k é mapead na posição k do arranjo => Tempo de acesso CONSTANTE

* Vatangens do Endereçamento direto:
    * Acesso direto e, portanto, rápido
        * via indexação do arranjo

* Desvantagens do Endereçamento direto:
    * Uso ineficiente do espaço de armazenamento
    * Imagine um vetor com "2" e "9999999", nesse caso teriamos que alocar um espaco de 9999999 - 2 = 9999997 (inviavel)
    * E se o dominio for continuo? da problema
    * E se tivermos que fazr inserções e remoções? mais problema

### Hashing

* Acesso direto, mas enderaçamento indireto
    * função de mapeamento h(k) != k
    * Resolve o uso ineficiente do espaço de armazenamento

* O(c) em média, independente do tamanho do vetor (MUITO MELHOR QUE O(logn))

* Hash significa do ingles: Fazer uma bagunça
    * Vamos "bagunçar" a distribuição das chaves
    * Em portuges, usamos os termos espalhamento ou dispersão

## Busca em Hashing

* https://www.youtube.com/watch?v=1sBqqrVm7Fo (min 20)

### Implementação

* Por meio de uma funçaõ h (chamada de **função hash**), transformamos uma chave k em um endereço
    * O endereço é usado para armazenar e recuperar registros

* Ideia: Particionar um conjunto possivelmente infinito de elementos em um numero finito de classes
    * B classes de 0 a B-1 (dendereços de armazenamento)
    * Classes são chamadas de buckets
    * k pertence ao bucket h(K)

* A fução hash é utilizada para inserir, remover ou buscar um elemento
    * Deve ser "determinística", ou seja, resultar sempre no mesmo valor para uma determinada chave

> Colisão

*  A colisão ocorre quando uma função hash produz o mesmo endereço para chaves diferentes
    * As chaves com mesmo endereço são ditas **sinônimos"

* Queremos que ela não aconteça, mas caso não haja uma distribuição uniforme (muito comulmente não há) teremos que tratar essas colisões

* Precisamos de uma BOA FUNÇÂO HASHING
    * Distribuii uniformemente os dados na medida do possível
    * Evita colisões 
    * Seja facil/rapida de computar

> Tecnica mais utilizada e bem simples de implementação da função Hasing:

* Para chavs inteiras: Caclular o resto da divisão k/B (k % B), sendo que o resto indica a posição de armazenamento
    * k = valor da chave
    * B = taamnaho do espaço de endereçamento

* Para chaves do tipo string: Tratar cada caractere como um valor inteiro (ASCII), soma-los e pegar o resto da divisão por B

* B deve ser primo preferencialmente => Numeros primos tendem  a gerar distribuições mais uniformes
    * Escolher o primeiro primo maior que o valor estipulado de B 

* Exemplo: (min 41)

> Tratamento de colisões

* Supondo que deseja-se armazenar n elementos em uma tabela de B posiç~eos, qual o numero esperado de elementos por posição na tabela? 

* Deve-se analisaro **Fator de carga**: (alfa) = n / B
    * Espera-se que o fator de carga esteja longe de 1 (RObson disse que perto de 0.5 ou 0.25 ja ta de bom tamanho)

> TIpos de Hasing

* Estático
    * Espaco de endereçamento de B não muda

* Dinamico
    * Espaco de endereçamento de B pode mudar

* O Estatico tem 2 tipos:
    * Fechado
        * Permite armazenar um conjunto de inforações de tamanho limitado
    * Aberto 
        * PErmite armazenar um conjunto de informações de tamanho potencialmetne ilimtado

* Tratamento de colisão:

* Estatico
    * Fechado
        * Utilzizar tecnicas de rehash (Overflow progressivo ou segunda funcao de hash)
    * Aberto
        * Encadeamento de elementos para tratamento de colisões

* Dinamico
    * FOra do escopo da disciplina (é aplicado em memoria secundaria)


### Hasing fechado

* Uma tabela de buckets é utilziada para armazenar informações
    * Os elementos são armazenados na própria tabela
    
> Como aplicar o rehash

* Se h(k) está ocupada (lembre-se que h(k) é um indice da tabela), aplicar a técnica de rehashsobre h(k), que deve retornar o p´roximo bucket livre
    * Alem de utilizar o indice resultante de h(k) na tecnica de rehash, pode-se utilizar a prórpai chave k e outras funções hash

* Caracteristicas de uma boa técnica de rehash 
    * Cobrir o maximo de indices entre 0 e B - 1
    * Evitar agrupamentos de dados

> Tecnicas de rehash

* Em vez de fazer o hashing utilizando uma função e uma tecnica de rehash, podemos representar isso em uma unica função dependente do numero da tentativa

* por exemplo: h(k, i) % B, com i = 0, ... B - 1
    * A funcao h depende de 2 parametros: A chave k e a iteração i 
    * Note que i = 0 é a função hash tradicional
    * Quando i = 1, ... B - 1, aplicamos um rehash por **overflow progressivo**

> Overflow progressivo
  
* (re)hash de h(k, i) = (k + i) % B, com i variando de 0 a B - 1
    * i é incrementado a cada tentativa

* Exemplo de problemas na busca (1h e 07 min)

Soldagem linear: (re)hash de h(k,i) = (k + i) % B, com i = 0, ... B
    * Todas as posições da tabela são checadas no pior caso 

* Sondagem quadrático: re(hash) de h(k, i) = (k + (c1 * i) + (c2 * i)), com i = 0, .. B - 1 e constantes c1 e c2
    * Considerada melhor que a linear pois evita "mais" o agrupamento de elementos

* Vatangem
    * simplicidade

* Desvantagens
    * agrupamentos de dados (causa por colisões)
    * Com estrutura cheia, a busca fica lenta [caracteristica do hashing fechado]
    * Dificulta inserções e remoções [caracteristica do hashing fechado]
    

> Segunda função Hash

* Tambem conhecido como hash duplo

* 2 funções
    * h(k) hash primaria
    * haux(k) hash secundaria

* Boas funções de exemplo: (re)hash de h(k, i) = (k + i*haux(k)) % B
    * i = 0, ... B - 1
    * haux(k) = 1 +k % (B - 1)

* Vantagens
    * Evita agrupamentos de dados em geral

* Desvantagens 
    * Dificl achar funcoes hash que satisfaçam ao mesmo tempo criteiros de cobrir o maximo de indices da tabela e evitem agrupamentos de dados (no geral podemos usar o exemplo anterior)
    * Dificulta inserções e remoções [caracteristica do hashing fechado]

> aula: https://youtu.be/_VtFboXVrlw
> 1h e 12 ele mostra como o hashing funciona com overflow progressivo