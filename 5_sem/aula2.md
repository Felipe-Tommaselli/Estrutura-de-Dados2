# Aula dia 21/05/2021
>**Algoritmos de ordenações, conceitos gerais e exemplos**

## A ordenação (ou classificação)

* Amplamente utilizados

* Muitas vezes vale a pena ordenar uma serie de dados e depois realizar uma busca, do que ja buscar diretamente

* Se a busca é frequente para diferentes elementos, vale a pena ordenar, mesmo que o ganho nãpo seja tao expressivo diretamente

> Terminologia:
 
* Ordenação de registros em que cada registro é ordenado por sua chave

* Ordenação interna (em memoria interna) x externa (em memoria secundaria/ disco)
    * no curso sera o mais utilizado

* Ordenação estavel: Ordenação original de registros com mesma chave é preservada após a ordenação dos registros

* **Dois tipos principais:**

* Ordenação sobre os próprios registros
    * Os registro são trocados de posição

* Ordenação por endereços
    * Mantem-se uma tabela de ponteiros para os registros e alteram-se somente os ponteiros durante a ordenação

* **Os registros a serem ordenados podem ser complexos ou não:**
    * Por exemplo, um aluno pode ter nome, num usp, cpf, nota final... 

* Metodos de ordenação independem disso, a chave é o termo principal

> Comparação de algoritmos de Ordenação 

* Considerar a complexidade

* Operação dominante: Numero de comparações entre elementos (na maioria dos casos)

* Normalmente consideramos a ordem crescente

## Algoritmos de Troca

* Mais classicos

* 2 mais famosos: 
    * Bubble-sort (metodo da bolha)
    * Quick-sort (ordenação rapida) (ordenação por troca de partição)

### Bubble-sort

* mais intuitivo e mais conhecido

* Percorrer o vetor varias vezes
    * A cada iteração, comparar cada elemento com seu sucessor e troca-los caso estejam na ordem incorreta

> Caso geral

* São necessarios n - 1 comparações, sendo n o numero de elementos

* Após a primeira iteração temos uma unica certeza, que o maior elemento esta na posicão correta (ultima)

* Complexidade: O(n^2)

> O Bubblesort pode ser melhorado (foco nos melhores casos)

## Bubblesort aprimado

> Primeira modificação

* há a possiblidade de antes varrermos o vetor inteiro, o vetor ja esteja ordenado

* para isso, caso não haja nenhuma troca para ser feita a ordenação ja pode terminar 

> Segunda modificação

* Como o ultimo elemento a partir da primeira iteração com ctz esta no lugaar certo
    * na segunda iteração, o penultimo e o ultimo estarao corretos com ctz
    * etc

* Não ha a necessidade de percorrer o vetor inteiro toda vez, isso não muda a complecidade, apenas ajuda no tempo de processamento

> Obs: essas modificações melhoram o melhor caso basicamente, o pior e o medio praticamente não sofrem alteração

* Complexidade: O(n^2) para o pior caso

    * Numero de comparações no passo j é n-j: 
    * (n-1) + (n-2) + (n-3) ... = (2kn - k^2 - k)/2

* Para o melhor caso, e exclusivamente para ele, caso o vetor ja esteja ordenado
    * O vetor sera rodado apenas uma vez no aprimorado, portanto sera O(n)