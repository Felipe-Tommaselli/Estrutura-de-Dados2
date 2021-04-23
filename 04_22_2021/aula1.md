# Aula dia 22/04/2021
>**Apresentação da disciplina e conceitos basicos de algoritmo e eficiencia de processamento**

## Eficiencia e problemas dificeis

* Resolver em tempo hábil: Otimização de algoritmo

* Existem problemas para os quais não se conhece nenhuum algoritmo eficiente para obter solução: NP-completos, Np-dificeis tbm são bem complicados (não sei ao certo se elles podem ser solucionados tambem)

* Recursos necessariso para a execução de um programa:    
    => Tempo (+ importante)    
    => Memória

* Comparar algoritmos != Comparar programas

* Os algortimos independem de variaveis como:               
    => Hardware    
    => Linguagem de programação     
    => Habilidade do programador
    => etc     
// Ou seja, exclui as diferenças de implementação

* Como prpocessar 1000 numeros leva mais tempo do que 100 numeros, ou seja, deve-se analisar a efiencia de uma açlgoritmo com base no tamanho do problema     
=> n = tamanho do problema, ou numero elementos processados

## Analise assintótica

* quando n for grande, devemos nos preocupar com a eficiencia do algoritmo   
=> Definição: A eficiencia assintótica de um algoritmo descreve a sua eficiencia relativa quando n torna-se grande    
.: para comparar 2 algoritmos, determinam-se as taxas de crescimento de cada um: o algortimo com **MENOR TAXA DE CRESCIMENTO** rodará **MAIS RAPIDO** quando o tamanho do problema for grande

* analise de memória para analise assintótica não é tão util: Dificil estimar detalhes estimados e como os computadores atuais possuem muita meória disponivel, não é tão necessario quanto a analise de tempo.

### NOTAÇÃO

=> dado duas funções f(n) [funçao que estimamos para nosso algoritmo] e g(n) [função que descreve o custo do algoritmo]

-> f(n) é a **"da ordem de big-oh"** g(n) ou que  f(n)= O(g(n)), se existirem ctes postivias c e n0 tais que: f(n) <= c*g(n), pq todo n>= n0. (limite superior da função)
> A taxa de crescimento de f(n) é "menor ou igual" que a taxa de g(n)

-> f(n) é **"omega"** g(n) ou que f(n) = Ω(g(n)), se existirm constantes positivas c e n0 tais que f(n) >= c*g(n) p/ todo n>= n0. (limite inferior da função)
> A taxa de crescimento de f(n) é "maior ou igual" que a taxa de g(n)

-> f(n) é **"theta"** g(n) ou que f(n) = θ(g(n)), sse f(n) = O(g(n)) e f(n) = Ω(g(n)) 
> A taxa de crescimento de f(n) é "igual" a taxa de g(n)

Ou seja:

-> Big-oh: f(n) esta sempre abaixo do c*g(n) [Bom]

-> Omega: f(n) esta sempre acima do c*g(n) [Ruim]

-> Theta: f(n) esta no meio do c1*g(n) e do c2*g(n) [Depende]

Exemplos:

> n^2 = O(n^3), n ao cubo cresce mais rapido que n ao quadrado e por isso limita ela

> n^3 = Ω(n^2), n ao cubo cresce mais devagar que n ao quadrado e por isso limita ela

> n^2 = θ(2n^2), n ao quadrado e dois vezes n ao quadrado tem a msm taxa de crescimento (quadraticas)

## Taxas de crescimento

* T1(n) = O(f(n)) e T2(n) = O(g(n))
    
    -> T1(n) + T2(n) = max(O(f(n)), o(g(n)))
    
    -> T1(n)*T2(n) = O(f(n)*g(n))
* Se T(x) é um polinomio de grau n, então T(x) = θ(x^n)
* logk_n (log de k na base n) = O(n) p/ qualquer cte k, pois logaritmos crescem muito vagorosamente

* Funções mais comuns:
[- custo computacional] 
| c          |  constante               |
| log n      | logaritmica              |
| log n ^2   | logaritmica ao quadrado  |
| n          | linear                   |
| n log n    | ?                        |
| n^2        | quadratica               |
| n^3        | cubica                   |
| 2^n ou a^n | exponencial              |
[+ custo computacional] 

* Conforme o n cresce, as constantes somadas ou multiplicadas a função podem ser desprezadas:

T1(n) = O(2*n^2)   

                    ==> T(n) = O(n^2)

T2(n) = O(n^2 + n)

> obs: isso é valido para O, Ω e θ