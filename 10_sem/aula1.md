# Aula dia 01/07/2021
>**Analise de algoritmos de busca e complexidade**

## Busca sequencial com realocação de elementos

* aula: https://www.youtube.com/watch?v=F4eLFeXl04o

### Implementação 

* Reordenar continuamente a tabela de modo que os registros mais acessados sejam deslocados para o inicio
    * **Método mover para frente**: Sempre que uma pesquisa obtiver exito, o registro recuperado é colocado no inicio da lista
    * **Método da transposição**: Um registro recuperado co sucesso é trocado com o registro imediatamente anterior (mais robusto que o mover para frente)

* Ambos se baseiam no fenomeno da "Recuperação recorrente de registros"

> Vantagens e desvantagem Método mover-para-frente

* Desvantagens
    * Uma unica recuperação não implica que o registro sera frequentemente recuperado
        * perda de eficiencia para os outros registros

* Vantagens
    * Possui resultados melhores para quantidades pequenas e média de buscas

* (implementação como exercicio) implementar na busca sequencial ja feita, a busca mover-para-frente e tambem a transposição, depois comparar os resultados

### Complexidade

* Mesma da busca senquencial: O(n), porem traz melhorias de desempenho

## Busca sequencial em tabela ordenada

* aula: https://www.youtube.com/watch?v=F4eLFeXl04o (min 11)

### Implementação 

* A eficiencia da operação de busca melhora se as cahves do registro estão ordenadas
    * No pior caso (quando a chave não é encontrada), são necessários N comparações quando as chaves estão desordenadas
    * No caso médio, N/2 comparações se as chaves estiverem ordenadas, pois a busca é parada assim que uma chave maior do que a procurada é encontrada

* Não vale a pena em custo, ordenar o vetor pra depois buscar

### Complexidade

* Mesma da busca senquencial: O(n), porem traz melhorias de desempenho

## Busca Senquencial indexada

* aula: https://www.youtube.com/watch?v=F4eLFeXl04o (min 29)

### Implementação 

* Para vetor ordenado tambem!!!!!

* existe um tabela auxiliar chamada de tabela de indices, alem do proprio arquivo ordenado

* cada elemento na tabela de indices contem uma chave (kindex) e um indicador no reigstro no arquivo que corresponde a kindex
    * Faz-se a busca a partir do ponto indicado na tabela, sendi que a busca não precisa ser feita desde o começo

* Pode ser implementada como uma lista sequencial ou uma lista encadeada
    * O indicador da posicção na tavela pode ser um ponteiro ou uma variavel inteira

* Exemplo com explicação no minuto 32

* caso a tabela indice fique mto grande, podemos montar uma tbvela de indice PARA a tabela de indice

> Vantagens e desvantagem Busca sequencial indexada

* Vatangens
    * Os items poderão ser examinados sequencialmente sem que todos os registros precisem ser acessados
        * o tempo de busca diminui consideravelemtne

* Desvantagens
    * A tabela tem que estar odenada
    * exige espaço adicional para armazenar as tabelas de indices
    * Perigo de baguncar os indices caso haja inserções e remoções na tabela

> Cuidados com inserção e remoção

* Remoção
    * Primeira estrategia (pior): Tirar o elemento e reorganizar todos os elementso que tiveram indices trocados
    * Segunda estrategia (melhor): Marca-se a posicação do elemento removido indicando um espaço vazio, ou seja, ela fica indicada como uma posição que pode ser ocupada por um outro elemento futuramente

* Inserção
    * Se houver espaço vago (a partir da segunda opção de remoção), rearranja-se os elemetnso localmente
    * Se não ouver espaço vago, reaaranja-se a tabela a partir do ponto apropriado e recostroem-se os indices quase por completo (muito caro)

* Ou seja, muita dor de cabeça e custo quando temos inserções e remoções

> Como montar o indice

* Se a tabela não estiver ordenado, ordene-a (vai ser custoso, mas caso seja necessario usar esse metodo, é a unica opção)

* Divide-se o numero de ekemetnos da tabela tamanho t do indice desejado: n/t

* Para montar o indice, recuperam-se da tabela os elementos 0, n/t, 2*n/t, etc

* Cada elemento do indice representa n/t eleemtnos da tabela

* exemplo numérico: 1h e 01 min

* Para montar o indice secundario é só refazer essa idea quase que recursivamente (raro exigir mais de 2 indices)

### Complexidade

* Mesma da busca senquencial: O(n), porem traz melhorias de desempenho
