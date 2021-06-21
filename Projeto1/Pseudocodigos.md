# Analise de complexidade pseudocódigos

## Bubble Sort

1: procedimento Main; por fim, tem-se que -10n^2-14n+2 unidades de tempo rege esse algoritmo
2:      n ← quantidade de inteiros a serem ordenados; 1 unidade para inicialização de n 
3:      Inicializar A[n] . Array de inteiros de comprimento n; 1 unidade para inicialização do vetor
4:      Bubble_Sort(A, n) . Chamada do algoritmo de ordenação
5: fim procedimento
...
1: procedimento Bubble_Sort(A, n); Custo total: somando tudo, tem-se -10n^2-14n unidades de tempo, ou seja, 
                                   a função tem Big-O O(n^2)
2:      para i ← 0 até n-1 faça; 1 unidade para inicialização de i, n unidades para testar se i < n-1 e n-1 
                                 unidades para incrementar, ou seja, i = 2n 
3:          para j ← 0 até n-i-2; 1 unidade para inicialização de j, n-i-1 unidades para testar se j <= n-i-2
                                  e n-i-2 unidades para incrementar, ou seja, j = -2n-2
4:              se A[j] > A[j + 1] então; caso A[j] seja maior que a[j+1] há um tempo de execução constante
                                          igual a 1, que é a comparação entre os valores
5:                  troque(A[j], A[j + 1]); 3 unidades vindas das atribuições feitas para a troca de variáveis,
                                            sendo executada n-i-2 vezes (pelo comando "para"), ou seja, -3n-6
6:              fim se
7:              j ← j + 1
8:          fim para
9:          i ← i + 1
10:     fim para
11: fim procedimento

## Bubble Sort Aprimorado

1: procedimento Main; por fim, tem-se que -10n^2-17n-2 unidades de tempo rege esse algoritmo
2:      n ← quantidade de inteiros a serem ordenados; 1 unidade para inicialização de n 
3:      Inicializar A[n] . Array de inteiros de comprimento n; 1 unidade para inicialização do vetor
4:      Optimized_Bubble_Sort(A, n) . Chamada do algoritmo de ordenação; 
5: fim procedimento
...
1: procedimento Bubble_Sort(A, n); Custo total: somando tudo, tem-se -10n^2-17n-4 unidades de tempo, ou 
                                   seja, a função tem Big-O O(n^2)
2:      ordenado ← true; 2 unidades, uma para inicialização de ordenado e outra pela atribuição de true
3:      para i ← 0 até n-1 faça; 1 unidade para inicialização de i, n unidades para testar se i < n-1 e n-1 
                                 unidades para incrementar, ou seja, i = 2n
4:          para j ← 0 até n-i-2; 1 unidade para inicialização de j, n-i-1 unidades para testar se j <= n-i-2
                                  e n-i-2 unidades para incrementar, ou seja, j = -2n-2
5:              se A[j] > A[j + 1] então; caso A[j] seja maior que a[j+1] há um tempo de execução constante
                                          igual a 1, que é a comparação entre os valores
6:                  ordenado ← false; 1 unidade pela atribuição de false 
7:                  troque(A[j], A[j + 1]); 3 unidades vindas das atribuições feitas para a troca de variáveis,
                                            sendo executada n-i-2 vezes (pelo comando "para"), ou seja, -3n-6
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

1: procedimento Main; Custo total: somando tudo, tem-se 16nlog(n)+38log(n)+3 unidades de tempo, ou 
                                   seja, a função tem Big-O O(nlog(n))
2:      n ← quantidade de inteiros a serem ordenados; 1 unidade para inicialização de n
3:      Inicializar A[n] . Array de inteiros de comprimento n; 1 unidade para inicialização do vetor 
4:      Quicksort(A, 0, n − 1) . Chamada do algoritmo de ordenação; 
5: fim procedimento
...
1: procedimento Quicksort(A, inicio, fim)
2:      se inicio < fim então; 1 unidade para comparação  
3:          pivo ← Random_Partition(A, inicio, fim); 1 unidade para atribuição e outra por chamar a função de 
                                                     complexidade (n)
4:          Quicksort(A, inicio, pivo − 1); chamando recursivamente a própria função, ou seja, complexidade
                                            de log(n), porém é passado como um dos parâmetros da função o 
                                            pivo que atribui uma função de complexidade n; por fim, tem-se  
                                            que a complexidade fica de nlog(n)
5:          Quicksort(A, pivo + 1, fim); o mesmo serve para ordenar a outra parte
6:      fim se
7: fim procedimento
...
1: procedimento Random_Partition(A, inicio, fim)
2:      k ← número inteiro aleatório entre inicio e fim; 5 unidades, sendo 1 da atribuição e as outras das 
                                                         operações matemáticas
3:      troque(A[k], A[fim]); 3 unidades vindas das atribuições feitas para a troca de variáveis
4:      devolve Partition(A, inicio, fim); chamanda a função de complexidade (n)
5: fim procedimento
...
1: função Partition(A, inicio, fim)
2:      pivo ← A[fim]; 2 unidades, sendo 1 para inicialização e outra para atribuição
3:      i ← (inicio − 1); 3 unidades, sendo 1 para inicialização, 1 para atribuição e outra para subtração
4:      para j ← inicio até fim-1 faça; 1 unidade para inicialização de j, n unidades para testar se i < n-1 e
                                        n-1 unidades para incrementar, ou seja, j = 2n
5:          se A[j] < pivo então; 1 unidade para comparação 
6:              i ← i + 1; 2 unidades, sendo 1 da soma e outra da atribuição
7:              troque(A[i], A[j]); 3 unidades vindas das atribuições feitas para a troca de variáveis
8:          fim se
9:          j ← j + 1
10:     fim para
11:     troque(A[i + 1], A[fim]); 3 unidades vindas das atribuições feitas para a troca de variáveis
12:     devolve (i + 1); 2 unidades, sendo 1 da soma e outra pelo fato de devolver um valor 
13: fim função

## Radix Sort

1: procedimento Main; por fim, tem-se que 22n+29 unidades de tempo rege esse algoritmo
2:      n ← quantidade de inteiros a serem ordenados; 2 unidades, sendo 1 para inicialização de n e outra para
                                                      atribuição do tamanho a n
3:      Inicializar A[n]; 1 unidade para inicialização de vetor
4:      Radix_Sort(A, n); 1 Unidade para chamar a função
5: fim procedimento
...
1: procedimento Radix_Sort(A, n); Custo total: somanto tudo, tem-se 22n+27 unidades de tempo, ou seja, a função
                                  tem Big-O O(n)
2:      maior ← maior inteiro armazenado em A; 1 unidade para inicialização de maior, n unidades para testar
                                               se maior < n-1 e n-1 unidades para incrementar, ou seja, maior =
                                               2n
3:      posicao ← 1; 2 unidades, sendo 1 para inicialização e outra para atribuição
4:      enquanto (maior/posicao) > 0 faça; 1 unidade de tempo pela comparação
5:          Counting_Sort(A, n, posicao); 
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
9:      para i ← 1 até 9 faça; 1 unidade para inicialização de i, 9 unidades para testar se i < 9 e 8 unidades 
                               para incrementar, ou seja, i = 18
10:         B[i] ← B[i] + B[i − 1]; 2 unidades, sendo 1 para atribuição e outra para soma
11:         i ← i + 1
12:     fim para
13:     Inicializar C[n]; 1 unidade pela incialização do vetor 
14:     para i ← n-1 até 0 faça; 1 unidade para inicialização de 1, n unidades para testar se n-1 < i e n-1 
                                 unidades para decrementar, ou seja, i = 2n 
15:         chave ← A[i]/posicao; 2 unidades, sendo 1 para a atribuição e outra para a divisão
16:         chave ← chave mod 10; 2 unidades, sendo 1 para atribuição e outra para o resto da divisão por 10
17:         B[chave] ← B[chave] − 1; 2 unidades, sendo 1 para atribuição e outra para a subtração
18:         C[B[chave]] ← A[i]; 1 unidade para atribuição
19:         i ← i − 1 
20:     fim para
21:     para i ← 0 até n-1 faça; 1 unidade para inicialização de i, n unidades para testar se n-1 < i e n-1 
                                 unidades para incrementar, ou seja, i = 2n 
22:         A[i] ← C[i]; 1 unidades para atribuição
23:         i ← i + 1; 
24:     fim para
25: fim procedimento

## Heapsort

1: procedimento Main 
2:      n ← quantidade de inteiros a serem ordenados; 1 unidade para inicialização de n 
3:      Inicializar A[n]; 1 unidade para inicialização do vetor
4:      Heapsort(A, n); 1 unidade para chamar a função 
5: fim procedimento 
...
1: procedimento Heapsort(A, n) Custo total: somando tudo, tem-se (3nlog(n)+57n-2log(n)-30)/2 unidades de tempo,
                                            ou seja, a função tem Big-O (nlog(n))
2:      para i ← (n/2)-1 até 0 faça; 1 unidade para inicialização de i, n/2 unidades para testar se (n/2)-1 < i
                                     e (n/2)-1 unidades para decrementar, ou seja, i = n 
3:          Heapify(A, n, i); chamando a função que possui log(n) de complexidade
4:          i ← i − 1
5:      fim para
6:      para i ← n-1 até 1 faça; n-1 unidades para testar se n-1 < i e n-1 unidades para decrementar, ou seja,
                                 i = 2n-2
7:          troque(A[0], A[i]); 3 unidades vindas das atribuições feitas para a troca de variáveis
8:          Heapify(A, i, 0) chamando a função que possui log(n) de complexidade
9:          i ← i − 1
10:     fim para
11: fim procedimento
...
1: procedimento Heapify(A, n, i)
2:      maior ← i; 1 unidade para atribuição 
3:      esquerda ← (2 ∗ i) + 1; 3 unidades, sendo uma para atribuição, uma para multiplicação e outra para soma
4:      direita ← (2 ∗ i) + 2; 3 unidades, sendo uma para atribuição, uma para multiplicação e outra para soma
5:      se esquerda < n & A[esquerda] > A[maior] então; 2 unidades pelas comparações feitas
6:          maior ← esquerda; 1 unidades para atribuição
7:      fim se
8:      se direita < n & A[direita] > A[maior] então; 2 unidades pelas comparações feitas
9:          maior ← direita; 1 unidades para atribuição 
10:     fim se
11:     se maior <> i então; 2 unidades pelas comparações feitas
12:         troque(A[i], A[maior]); 3 unidades vindas das atribuições feitas para a troca de variáveis
13:         Heapify(A, n, maior); Caso a comparação feita seja verdadeira, há a chamada recursiva da função 
                                  Heapify, mais o retorno da função, ou seja, fazendo a árvore de recorrência
                                  é possível concluir que T(n)=log(n)
14:     fim se
15: fim procedimento