# Analise de complexidade pseudocódigos

## Bubblesort

* 

## Quicksort

*

## Radixsort

1: procedimento Main
2:      n ← quantidade de inteiros a serem ordenados // +1
3:      Inicializar A[n] // +1
4:      Radix_Sort(A, n) // +1
5: fim procedimento
...
1: procedimento Radix_Sort(A, n)
2:      maior ← maior inteiro armazenado em A //+n
3:      posicao ← 1 // +1
4:      enquanto (maior/posicao) > 0 faça // +1
5:          Counting_Sort(A, n, posicao) // +1
6:          posicao ← posicao ∗ 10 // +2
7:      fim enquanto
8: fim procedimento
...
1: procedimento Counting_Sort(A, n, posicao)
2:      Inicializar B[10] com zeros //+1
3:      para i ← 0 até n-1 faça //n - 1
4:          chave ← A[i]/posicao // +1
5:          chave ← chave mod 10 // +1
6:          B[chave] ← B[chave] + 1 // +2
7:          i ← i + 1 //+2
8:      fim para 
9:      para i ← 1 até 9 faça //+9
10:         B[i] ← B[i] + B[i − 1] //2
11:         i ← i + 1 // +2
12:     fim para
13:     Inicializar C[n] //+1
14:     para i ← n-1 até 0 faça // n - 1
15:         chave ← A[i]/posicao // 1
16:         chave ← chave mod 10 // 2
17:         B[chave] ← B[chave] − 1 // +2
18:         C[B[chave]] ← A[i] // 2
19:         i ← i − 1 // 2
20:     fim para
21:     para i ← 0 até n-1 faça // n - 1
22:         A[i] ← C[i] //+1
23:         i ← i + 1 // +2
24:     fim para
25: fim procedimento

## Heapsort

1: procedimento Main 
2:      n ← quantidade de inteiros a serem ordenados // +1
3:      Inicializar A[n] // + 1
4:      Heapsort(A, n) // +1
5: fim procedimento 
...
1: procedimento Heapsort(A, n) // +1
2:      para i ← (n/2)-1 até 0 faça 
3:          Heapify(A, n, i)
4:          i ← i − 1
5:      fim para
6:      para i ← n-1 até 1 faça
7:          troque(A[0], A[i])
8:          Heapify(A, i, 0)
9:          i ← i − 1
10:     fim para
11: fim procedimento
...
1: procedimento Heapify(A, n, i)
2:      maior ← i
3:      esquerda ← (2 ∗ i) + 1
4:      direita ← (2 ∗ i) + 2
5:      se esquerda < n & A[esquerda] > A[maior] então
6:          maior ← esquerda
7:      fim se
8:      se direita < n & A[direita] > A[maior] então
9:          maior ← direita
10:     fim se
11:     se maior <> i então
12:         troque(A[i], A[maior])
13:         Heapify(A, n, maior)
14:     fim se
15: fim procedimento