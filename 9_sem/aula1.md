# Aula dia 24/06/2021
>**Analise de algoritmos e complexidade**

## Continuação Countingsort

* aula: https://www.youtube.com/watch?v=ChGPZdD6SI0

### Implementação 

* custo depende da diferença entre maior e menor

* O(n) se (max - min + 1) <= n
    * ou seja, se a diferenca entre o maior eo menor foi pequena comparada com n, ele é linear

* O(maior - menor + 1) se (max - min + 1) >= n
    * o caso em que a diferenca é maior que o tamanho de n

* Na pratica, esse método é extremamente eficiente, uma vez que normalmente essa diferente não sera maior que n para entradas gradnes o suficinete

* NÃO é um algoritmo deordenação por comparação
    * o que o tornamuito eficiente

* Sua maior limitação é a necessdiade de ter-se um dominio discreto de numeros naturais

* Complexidade de espaço: O(n)
    * muito bom tbm

## Radixsort

* ordenação de raízes

* video: https://www.youtube.com/watch?v=ChGPZdD6SI0 (a partir dos 20 min)

### Implementação

* Ideia basica: Ordenar os numeros a partir de seus digitos, do menos significativos ate os mais

* Utilizam-se listas
    * Uma fila para cada digito
    * Os nunmeros vão sendo inseridos na fila em acordo com o digito sendo avaliado
    * A cada iteração os numeros estão mais proximos da ordenaçaõ final 

* Explicacao com exemplo (so da pra entender com exemplo) a partir do min 26

* Ele ordena cada digito por vez, entao pimeiro ele vai da uma ordenada por exemplo se os numeros sao algo parecido com 29, ele vai ordenada as undades (9) e depois vai refazer todo o processo pra dezena (2), no fim vai ta tudo ordenado bontinho

* se tempos elementos diferentes em numeros de gitiso, tipo 298, 34 e 1 nós colocamos o 0 a esquerda: 298, 034 e 001

* serão necessarios m iterações para ordenar o vetor, sendo m o numeros de digitos do maior numero 

> Obs: ele funciona para dominio discreto de numeros naturais. É adapta-lo para numeros negativos, mas seria necessario um pouco mais de processamento.

### Complexidade

* O(m*n), sendo m o num de digitos do maior numero

* na pratica, o m é pequneo comparado com n e assume-se comportamento linear pro algortimo

* Algoritmo mto bom e otimizado, unica limitação é depender do valor de m e exigir um intervalo discreto de numeros naturais (pode ser implementado para numeros negativos, mas o custo aumentará levemente)

* Complexidade de espaço: O(n)

## Comparação entre os métodos

* video: https://www.youtube.com/watch?v=s-bwWOmyOTQ (18 min)

* pra ordem aleatória (tiradno o counting e o radix), o quick é melhor pro caso médio, seguido do quick e o shell

* pro vetor quase ordenado, o insertion é o melhor (mas tem que ta quaseee ordenado)

* pra ordem descendente, o quick continua sendo o melhor

> Resumindo:

* caso vc nao saiba NADA do seu vetor, o quick é a opcao mais safe

* para arranjos pequenos o shell é melhor que o heap (pior que o quick)

* Se o seu dominio é discreto com ctz, radix ou counting são os melhores

* tanto o shellsort e quicksort são sensiveis em relação a ordenações ascendentes e descendentes
    * O heap é praticamente não sensivel a ordem, ou seja, se sua aplicação necessita que os resultados sejam muito constantes, ele é a melhor opção

> Exercicio: Pesquisar sobre Shakesort, Treesort e Bucketsort

## Cota inferior para o caso geral

* Cota (ou limite) inferior de um problema

* Prova-se que é impossivel resolver o problema em menos que C(n) passos apra uma entrada de tamanho n

* algoritmo otimo: resolve o problema em tempo igual (nunca menor, impossivel) que a cota inferior

* Cota inferior pro caso geral (sem exigir nada do conjunto) é C(nlogn) (demonstração a partir dos 30min https://www.youtube.com/watch?v=s-bwWOmyOTQ)