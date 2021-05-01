# Aula dia 30/04/2021
>**Analise de algoritmos, voltada para a analise de recorrencias (recursividade)**

## Analise de algoritmos

* analise empirica x analise teorica
    * se complementam

* Lembrando que operações simples são conveciadas em gastar uma unidade de tempo

(D:\temp\Captura de tela 2021-04-30 223002.jpg)

* Pela analise teorica normalmente é utilizada a analise por termos de bigOh (limite superior), por isso termos de baixo custo na orem  de grandeza são dsconsiderados

### Por exemplo:

> declare i,j e x numéricos;
declare m uma matriz de n linhas por n colunas;
para i<-q ate n faça
    j<-1;
    enquanto j<n faça
        x<-m[i,j]
        imprima(x)
        j<-j+2;
    imprima(i);

**isso é um O(n^2), pois o maior custo esta nos dois loopings de n repeticções, ou seja n*n**

### Exercicio

> sub-rotina fatorial(n: numérico)
inicio
se n<= 1
    entao  aux<- 1
    senão aux,- n*fatorial(n-1)
retorne aux;
fim

**minha resposta: Pra mim seria O(n), pois é uma repetição de um for n vezes para o calculo do faotiral**