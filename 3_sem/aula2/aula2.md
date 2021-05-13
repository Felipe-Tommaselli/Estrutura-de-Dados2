# Aula dia 07/05/2021
>**Analise de algoritmos, complexidade e implementação da busca binaria**

## Busca binaria

> o 1 o 2 o 5 o 11 o 58 o 59 o 70 o 71 o 72 o
> elemento procurado: 2

* O vetor precisa estar ordenado
* Escolhe-se o elemento do meio, no caso o 58
* 58 == 2? NÃO
* 2 < 58, portanto todos os numeros após o 58 são descartados

> o 1 o 2 o 5 o 11 o
> elemento procurado: 2

* 5 é o elemento procuraod? NÃO

> o 1 o 2 o 

> elemento procurado: 2

* 2 é o elemento procuraod? SIM


## Analise do tempo na busca binaria

* Se n = 1, então o tempo constante O(c), não importando se achou um nbão o elemento

* Se n > 1, então
    * Comparações e divisão/diminuição do problema: tempo constante O(c)
    * Processamento do subproblema: T(n/2)

> Equação de recorrencia/ complexidade de tempo:
> * T(n) = c, se n = 1
> * T(n) = T(n/2) + c, se n>1

* T(n) = c*(logn + 1) = c*logn + c =

    * O(logn)

![Alt text](D:\C_projects\Estrutura-de-Dados2\3_sem\Capturadetela2021-05-13115847.jpgaula2\ "a title")

## Método mestre

* método fornece limites para recorrencias na forma: **T(n) = aT(n/b) + f(n)**, em  que a>= 1, b>= 1 e f(n) é uma funcao de n dada

* Envolve a memorização de alguns **casos basicos** que podem ser aplicados para muitas recorrencias simples

* Tarefa: Estudar método mestre e testar