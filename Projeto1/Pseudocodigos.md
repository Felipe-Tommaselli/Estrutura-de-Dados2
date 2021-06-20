# Analise de complexidade pseudocódigos

## Bubble Sort

1: procedimento Main
2:      n ← quantidade de inteiros a serem ordenados; 1 unidade para unicialização de n 
3:      Inicializar A[n] . Array de inteiros de comprimento n; 1 unidade para inicialização do vetor
4:      Bubble_Sort(A, n) . Chamada do algoritmo de ordenação; 1 unidade para chamar a função
5: fim procedimento
...
1: procedimento Bubble_Sort(A, n); Custo total: somando tudo, tem-se n(10n-10i-16) unidades de tempo, ou seja, 
                                   a função tem Big-O O(n^2)
2:      para i ← 0 até n-1 faça; 1 unidade para inicialização de i, n unidades para testar se i < n-1 e n-1 
                                 unidades para incrementar, ou seja, i = 2n
3:          para j ← 0 até n-i-2; 1 unidade para inicialização de j, n-i-1 unidades para testar se j <= n-i-2
                                  e n-i-2 unidades para incrementar, ou seja, j = 2n-2i-2
4:              se A[j] > A[j + 1] então; caso A[j] seja maior que a[j+1] há um tempo de execução constante
                                          igual a 1, que é a comparação entre os valores
5:                  troque(A[j], A[j + 1]); 3 unidades vindas das atribuições feitas para a troca de variáveis,
                                            sendo executada n-i-2 vezes (pelo comando "para"), ou seja, 3n-3i-6
6:              fim se
7:              j ← j + 1
8:          fim para
9:          i ← i + 1
10:     fim para
11: fim procedimento

## Bubble Sort Aprimorado

1: procedimento Main
2:      n ← quantidade de inteiros a serem ordenados; 1 unidade para inicialização de n 
3:      Inicializar A[n] . Array de inteiros de comprimento n; 1 unidade para inicialização do vetor
4:      Optimized_Bubble_Sort(A, n) . Chamada do algoritmo de ordenação; 1 unidade para chamar a função
5: fim procedimento
...
1: procedimento Bubble_Sort(A, n); Custo total: somando tudo, tem-se n(10n-10i-9)-5(i+1) unidades de tempo, ou 
                                   seja, a função tem Big-O O(n^2)
2:      ordenado ← true; 2 unidades, uma para inicialização de ordenado e outra pela atribuição de true
3:      para i ← 0 até n-1 faça; 1 unidade para inicialização de i, n unidades para testar se i < n-1 e n-1 
                                 unidades para incrementar, ou seja, i = 2n
4:          para j ← 0 até n-i-2; 1 unidade para inicialização de j, n-i-1 unidades para testar se j <= n-i-2
                                  e n-i-2 unidades para incrementar, ou seja, j = 2n-2i-2
5:              se A[j] > A[j + 1] então; caso A[j] seja maior que a[j+1] há um tempo de execução constante
                                          igual a 1, que é a comparação entre os valores
6:                  ordenado ← false; 1 unidade pela atribuição de false 
7:                  troque(A[j], A[j + 1]); 3 unidades vindas das atribuições feitas para a troca de variáveis,
                                            sendo executada n-i-2 vezes (pelo comando "para"), ou seja, 3n-3i-6
8:              fim se
9:              j ← j + 1 
10:          fim para
11:         se ordenado = true então; 1 unidade para comparar se ordenado é igual a true 
12:             sair
13:         fim se
14:         i ← i + 1
15:     fim para
16: fim procedimento

## Quicksort

1: procedimento Main
2:      n ← quantidade de inteiros a serem ordenados
3:      Inicializar A[n] . Array de inteiros de comprimento n
4:      Quicksort(A, 0, n − 1) . Chamada do algoritmo de ordenação
5: fim procedimento
...
1: procedimento Quicksort(A, inicio, f im)
2:      se inicio < f im então
3:          pivo ← Random_Partition(A, inicio, f im)
4:          Quicksort(A, inicio, pivo − 1)
5:          Quicksort(A, pivo + 1, f im)
6:      fim se
7: fim procedimento
...
1: procedimento Random_Partition(A, inicio, f im)
2:      k ← número inteiro aleatório entre inicio e f im
3:      troque(A[k], A[f im])
4:      devolve Partition(A, inicio, f im)
5: fim procedimento
...
1: função Partition(A, inicio, f im)
2:      pivo ← A[f im]
3:      i ← (inicio − 1)
4:      para j ← inicio até fim-1 faça
5:          se A[j] < pivo então
6:          i ← i + 1
7:          troque(A[i], A[j])
8:          fim se
9:          j ← j + 1
10:     fim para
11:     troque(A[i + 1], A[f im])
12:     devolve (i + 1)
13: fim função

## Radix Sort

1: procedimento Main
2:      n ← quantidade de inteiros a serem ordenados; 2 unidades, sendo 1 para inicialização de n e outra para
                                                      atribuição do tamanho a n
3:      Inicializar A[n]; 1 unidade para inicialização de vetor
4:      Radix_Sort(A, n); 1 Unidade para chamar a função
5: fim procedimento
...
1: procedimento Radix_Sort(A, n); Custo total: somanto tudo, tem-se 43n+7 unidades de tempo, ou seja, a função
                                  tem Big-O O(n)
2:      maior ← maior inteiro armazenado em A; 1 unidade para inicialização de maior, n unidades para testar
                                               se maior < n-1 e n-1 unidades para incrementar, ou seja, maior =
                                               2n
3:      posicao ← 1; 2 unidades, sendo 1 para inicialização e outra para atribuição
4:      enquanto (maior/posicao) > 0 faça; 1 unidade de tempo pela comparação
5:          Counting_Sort(A, n, posicao); 1 unidade por ter chamado a função
6:          posicao ← posicao ∗ 10; 2 unidades, sendo uma da multiplicação e outra da atribuição
7:      fim enquanto
8: fim procedimento
...
1: procedimento Counting_Sort(A, n, posicao)
2:      Inicializar B[10] com zeros; 1 unidade pela inicialização do vetor
3:      para i ← 0 até n-1 faça; 1 unidade para inicialização de i, n unidades para testar se i < n-1 e n-1
                                 unidades para incrementar, ou seja, i = 2n
4:          chave ← A[i]/posicao, 2 unidades, sendo 1 para atribuição e outra para a divisão
5:          chave ← chave mod 10; 2 unidades, sendo 1 para atribuição e outra para o resto da divisão por 10
6:          B[chave] ← B[chave] + 1; 2 unidades, sendo 1 para atribuição e outra para a soma 
7:          i ← i + 1
8:      fim para 
9:      para i ← 1 até 9 faça; 1 unidade para inicialização de i, 9 unidades para testar se i < 9 e 9 unidades 
                               para incrementar, ou seja, i = 19
10:         B[i] ← B[i] + B[i − 1]; 2 unidades, sendo 1 para atribuição e outra para soma
11:         i ← i + 1
12:     fim para
13:     Inicializar C[n]; 1 unidade pela incialização do vetor 
14:     para i ← n-1 até 0 faça; 1 unidade para inicialização de 1, n unidades para testar se n-1 < 0 e n-1 
                                 unidades para decrementar, ou seja, i = 2n 
15:         chave ← A[i]/posicao; 2 unidades, sendo 1 para a atribuição e outra para a divisão
16:         chave ← chave mod 10; 2 unidades, sendo 1 para atribuição e outra para o resto da divisão por 10
17:         B[chave] ← B[chave] − 1; 2 unidades, sendo 1 para atribuição e outra para a subtração
18:         C[B[chave]] ← A[i]; 1 unidade para atribuição
19:         i ← i − 1 
20:     fim para
21:     para i ← 0 até n-1 faça; 1 unidade para inicialização de 1, n unidades para testar se n-1 < 0 e n-1 
                                 unidades para incrementar, ou seja, i = 2n 
22:         A[i] ← C[i]; 1 unidades para atribuição
23:         i ← i + 1; 
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