# Continuação Aula dia 22/04/2021
>**Apresentação da disciplina e conceitos basicos de algoritmo e eficiencia de processamento**

## Analise de Algoritmos

* Assume-se um o uso de um computador tradicional, em que as instruções de um programa são executas sequencialmente,

    * Com **memória infinita** por simplicidade

* Reperttório de instruções simples: soma, multiplicação, comparação, atribuição, etc
    * Assume-se que cada isntrução demora **uma unidade de tempo** pra ser realizada
    * Operações complexas como inversão de matries e ordeação de valores demora mais que uma unidade de tempo (devem ser analisadas a parte)

* Considerando somente o algoritmo e suas entradas (tamanho n)
* T<sub>melhor</sub>(n), T<sub>media</sub>(n) e T<sub>pior</sub>(n) são os tempos de execução
    * T<sub>melhor</sub>(n) <= T<sub>media</sub>(n) <= T<sub>pior</sub>(n)


* Normalmente consideramos a analise do pior caso (T<sub>pior</sub>(n)) como limite superior. 
    * O médio pode ser util para sistemas executaods rotineriametne mas é dificl de ser calculado
    * O melhor não é muito util

## Calculo do tempo de execução

* 2 formas basicas
    * Empiricamente (testes)
    * Teoricamente

* Empricamente envolvendo todas aquelas variaveis de maquina, linguagem e etc

* Supondo que as operações simples demorar uma unidade de tempo para executar, consiere o programa baixo para calcular o resultado do exemplo abaixo:

![Alt text](D:\C_projects\Estrutura-de-Dados2\04_22_2021\Captura de tela 2021-04-24 151056.jpg "a title")

* **Algoritmo**
    * 1. Inicio
    * 2. declare soma_parcial numérico;
    * 3. soma parcial <- 0 
    * 4. para i <- 1 até n faça
    * 5. Soma_parcial <- soma_parcial + i * i * i;
    * 6. escreva(soma_parcial);
    * 7. Fim

* Custo
    * linha 3: 1 unidade de tempo
    * linha 4: 1 unidade para iniciação de i, n + 1 unidades para testar se i = n e n unidades para incrementar i= 2n + 2
    * linha 5: 4 unidades (1 da soma, 2 das multiplicações e 1 da atribuição) executada n vezes (pelo comando "para") = 4n unidades
    * linha 6: 1 unidade para escrita
    * **Custo total:** Somando tudo, tem-se 6n + 4 unidades de tempo, ou seja, a função O(n)!

* Para algoritmos grandes esse procedimento não é eficiente, pois para algoritmos muito grandes a complexidade dessa analise fica mot grande

* Para simplificação, é comum desconsiderar constantes e elementos menores (ja que o resultado é dado em big-oh):
    * no exemplo, a linha 4 que realmente da a grandeza de tempo desejada (a repetição "para i <- 1 até n faça")

## Regras de calculo        

> **Repetições:** O tempo de execução de uma repetição é pelo menos o tempo dos comandos dentro da repetiçaõ (incluindo testes) vezes o numero de vezes que é executada

> **Repetições aninhadas:** A análise é feita de dentro para fora. O tempo de execução total de comandos dentro de um grupo de repetições aninhadas é o tempo de execução dos comandos multiplicando pelo prduto do tamanho de todas as repetições

> **Comandos consecutivos:** É soma dos tempos de cada um, o que pode signifcar o maximo entre eles. 

> **If/else:** Para um condicional, o tempo de execução *nunca* é maior do que o tempo do teste mais o tempo do maior entre os comandos relativos

> **Chamadass a sub-rotinas:** Uma sub-rotina deve ser analisada primeiro e depois ter suas unidades de tempo incorporadas ao programa/sub-rotina que a chamou