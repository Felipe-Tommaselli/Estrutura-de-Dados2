//* Aula 3 da 6 semana, insercao simples
// mesmo projeto das priemrias aulas

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void cria(lista *l) {
    l->tamanho = 0;
    l->elementos = malloc(sizeof(elem)*TAM);
    l->contagens = malloc(sizeof(long)*TAM);
    l->copia = malloc(sizeof(elem)*TAM);
    return;
}


void destroi(lista *l) {
    free(l->elementos);
    free(l->copia);
    free(l->contagens);
    l->tamanho = 0;
}

int insere(lista *l, elem e) {
    if (l->tamanho == TAM)
        return 1; //? erro, lista cheia
    l->elementos[l->tamanho] = e;
    l->tamanho++;
    return 0; //? sucesso
}

void imprime(lista *l) {
    long i = 0;
    if (l->tamanho == 0) 
        printf("( )\n");
    else {
        printf("(");
        for (; i < l->tamanho-1; i++)
            printf("%d, ", l->elementos[i]);
        printf("%d)\n", l->elementos[i]);
    }
}

void ordena_recursivo_mergesort(lista *l, long ini, long fim) {
    long meio, l1, l2, lc;
    if (ini == fim)
        return; //? criterio de parada; lista unitaria
    
    //? ordena metades inferior e superior por recursividade
    meio = ini + (fim - ini) / 2;
    ordena_recursivo_mergesort(l, ini, meio);
    ordena_recursivo_mergesort(l, meio + 1, fim);
    
    //? une as metades ordenadas
    l1 = lc = ini;
    l2 = meio + 1;
    while (l1 <= meio && l2 <= fim)
        l->copia[lc++] = (l->elementos[l1] < l->elementos[l2]) ? l->elementos[l1++] : l->elementos[l2++];
        /*if (l->elementos[l1] < l->elementos[l2]) {
            l->copia[lc] = l->elementos[l1];
            l1++;
        } else {
            l->copia[lc] = l->elementos[l2];
            l2++;
        }
        lc++;*/
    //? copia elementos restantes da metade inferior, se existentes
    for (; l1 <= meio; l1++, lc++)
        l->copia[lc] = l->elementos[l1];
    //? copia elementos restantes da metade superior, se existentes
    for (; l2 <= fim; l2++, lc++)
        l->copia[lc] = l->elementos[l2];
    
    //? sobrescreve lista nao ordenada pela copia ordenada
    for (lc = ini; lc <= fim; lc++)
        l->elementos[lc] = l->copia[lc];
}

void ordena_mergesort(lista *l) {
    // custo nlogn
    if (l->tamanho > 1)
        ordena_recursivo_mergesort(l, 0, l->tamanho-1);
}

void ordena_selecaodireta(lista *l){
    //* algoritmo de ordenaçao quadrado
    //? encontra o menor element, coloca ele na 1 posição
    //? ignora esse elemento, pega o segundo menor, coloca na 2 pos
    //? etc

    //? processa uma posição por vez
    for(long i = 0; i < l->tamanho; i++){
        //? encontrar menor entre o i-esimo e o ultimo
        int IDmenor = i; //? assume que o i-esimo é o menor 
        for(long j = i + 1; j < l->tamanho; j++)
            if(l->elementos[j] < l->elementos[IDmenor])
                IDmenor = j;
        //? coloca menor na i-esima posicao
        elem aux;
        aux = l->elementos[i];
        l->elementos[i] = l->elementos[IDmenor];
        l->elementos[IDmenor] = aux;
    }
}

void ordena_bubblesort(lista *l){
    //? quadratico
    long iteracao = 0;
    elem aux;
    while (iteracao < l->tamanho-1){
        for (long i = 0; i < l->tamanho-1; i++)
            if (l->elementos[i] > l->elementos[i+1]) { //? faz (n-1)*(n-1) => O(n^2) comparacoes para troca 
                //? faz a troca
                aux = l->elementos[i];
                l->elementos[i] = l->elementos[i+1];
                l->elementos[i+1] = aux;
            }
        iteracao++;
    }
}
void ordena_bubblesort_aprimorado(lista *l){
    long continua = 1, iteracao = 1;
    elem aux;
    while (continua == 1) {
        continua = 0;
        for (long i = 0; i < l->tamanho-iteracao; i++)
            if (l->elementos[i] > l->elementos[i+1]) { //? comparacao para troca 
                //? faz a troca
                aux = l->elementos[i];
                l->elementos[i] = l->elementos[i+1];
                l->elementos[i+1] = aux;
                continua = 1;
            }
        iteracao++;
    }
}

void ordena_quick_sort_recursivo(lista *l, long ini, long fim){
    // quicksort com partcionamento de Lomuto -- pivo sempre no final
    long i, j;
    elem aux;

    // faz particionamento
    i = ini;
    for (j= ini; j < fim; j++){
        // compara com o pivo
        if (l->elementos[j] < l->elementos[fim]){
            //troca elementos das pos i por j
            aux = l->elementos[j];
            l->elementos[j] = l->elementos[i];
            l->elementos[i] = aux;
            i++; // achpou novo elemento menor que o pivo
        }
    }
    // reposiciona o pivo, ou seja, troca elementos das posicoes i e fim
    aux = l->elementos[fim];
    l->elementos[fim] = l->elementos[i];
    l->elementos[i] = aux;

    // ordenada as duas metades de maneira independente
    if (ini < i - 1)
        ordena_quick_sort_recursivo(l, ini, i - 1);
    if (i + 1 < fim)
        ordena_quick_sort_recursivo(l, i + 1, fim);
}

void ordena_quicksort(lista *l){
    // piro caso: quadratico
    //melhor caso: nlogn 
    return ordena_quick_sort_recursivo(l, 0, l->tamanho - 1);
}

void ordena_insercao_simples(lista *l){
    long i, j;
    elem aux;

    for (i = 1; i < l->tamanho; i++){ // insere i-ésimo elemento no subvetor ordenado entre 0 e i-1
        aux = l->elementos[i]; // guarda elemento a inserir

        // faz shift a direito em todos os elem maiores que o elemento a inserir
        for (j = i - 1; j > 0 && l->elementos[j] > aux; j--)
            l->elementos[j + 1] = l->elementos[j];

        // insere o elemento na posicao correta
        l->elementos[++j] = aux;
    }
}


void ordena_shellsort(lista *l){
    //gera vetor de passos

    //! nao esta funcionando ainda, se pa que euerrei na iniciação com 0 e 1
    
    long i, j, h;
    elem aux;
    long id_maiorpasso = 0; // o prof errou e esse idmaiorpasso nao tera sempre o maior passo
    //mas eu gostei mais desse nome
    long *passos = malloc(sizeof(long));
    passos[id_maiorpasso] = 1;

    while(l->tamanho > passos[id_maiorpasso]){
        id_maiorpasso++;
        passos = realloc(passos, sizeof(long) * (id_maiorpasso + 1));
        passos[id_maiorpasso] = 3*passos[id_maiorpasso - 1] + 1; //Knuth só que o i que ele fe ja esta atualizado
        //mas é a mesma coisa no fim, "idmaiorpasso" é o "i" nos slides 
    }


    for(h = passos[id_maiorpasso]; id_maiorpasso >= 0; id_maiorpasso--){
        h = passos[id_maiorpasso];
        for(i = h; i < l->tamanho; i++){ // insere i-ésimo elemento no subvetor ordenado
            aux = l->elementos[i]; // guarda elemento a inserir

            // faz shift a direito em todos os elem maiores que o elemento a inserir
            for(j = i - h; j > 0 && l->elementos[j] > aux; j -= h)
                l->elementos[j + h] = l->elementos[j];

            // insere o elemento na posicao correta
            l->elementos[j + h] = aux;
        }
    }
    free(passos);
}

void rearranja_heap(lista *l, long i, long tam_heap){
    // custo total: f(n) = (logn) - 1 => O(logn), com n= tamanho do heap
    long filhoesq, filhodir, filhomaior;
    elem aux;
    // identificfa filhos esquerda e direito 

    if(2*i + 1 < tam_heap)
        filhoesq = 2*i + 1;
    else
        filhoesq = -1;

    if(2*i + 2 < tam_heap)
        filhodir = 2*i + 2;
    else
        filhodir = -1;
    
    // se i for folha temrina
    if(filhoesq == -1)
        return; // nenhum filho, heap esta ok 

    // identifica maior filho
    if(filhodir == -1 || l->elementos[filhoesq] > l->elementos[filhodir])
        filhomaior = filhoesq;
    else
        filhomaior = filhodir;

    // se o valor do nó i for maior que o do maior filho termina
    if(l->elementos[i] >= l->elementos[filhomaior])
        return; //raiz >= do que os filhos, logo heap esta ok 

    // troca elemento da posicao i pelo maior filho

    aux = l->elementos[i];
    l->elementos[i] = l->elementos[filhomaior];
    l->elementos[filhomaior] = aux;
    //rearranja recursivamente a partir da pos do maior filho
    rearranja_heap(l, filhomaior, tam_heap); //arruma proximo nivel

    // essa subrotina tem tamanho logn uma vez que a altura maxima da arvore binaria é logn
}

void constroi_heap(lista *l){
    // custo toal: f(n) = (n / 2 - 1)(log(n) - 1) => O(n log n), com n = l->tamanho
    for(long i = l->tamanho/2 - 1; i >= 0; i--)
        rearranja_heap(l, i, l->tamanho);
    
}

void ordena_heapsort(lista *l){
    // custo total: f(n) = (n / 2 - 1)(log(n) - 1) + (log(n/2) - 1) => O(nlogn), com n = l->tamanho
    long tam_heap;
    elem aux;

    // constroi heap
    constroi_heap(l);
    // remove um por vez em ordem
    tam_heap = l->tamanho;
    
    while(tam_heap > 1){
        //troca raiz por ultima folha
        aux = l->elementos[tam_heap - 1];
        l->elementos[tam_heap - 1] = l->elementos[0];
        l->elementos[0] = aux;
        // diminuir heap
        tam_heap--;
        // reaaranjar hea´p
        rearranja_heap(l, 0, tam_heap);
    }
}

void ordena_contagem_menores(lista *l){
    // custo: O(n^2)
    long i, j;

    // inicializa vetor de contagens
    for(i = 0; i < l->tamanho; i++)
        l->contagens[i] = 0;
    
    //conta menores, com essa implementação ele evita o problema das duplicatas
    for(i = 1; i < l->tamanho; i++)
        for(j = 0; j < i; j++)
            if(l->elementos[i] > l->elementos[j])
                l->contagens[i]++;
            else
                l->contagens[j]++;

    // monta a copia
    for(i = 0; i < l->tamanho; i++)
        l->copia[l->contagens[i]] = l->elementos[i];
    
    // sobrescreve opia no vetor original
    for(i = 0; i < l->tamanho; i++)
        l->elementos[i] = l->copia[i];
}

void ordena_counting_sort(lista *l){
    elem maior;
    long i, j;

    // encontra maior
    maior = l->elementos[0];
    for(i = 1; i < l->tamanho; i++)
        if(l->elementos[i] > maior)
            maior = l->elementos[i];

    // inicializa vetor de contagens
    // ele nao usou o ->contagens pq ia dar problema com o tipo dele ser long
    // para faciitar a implementaçaõ assumimos que o elemento menor é 0 ou mto perto dele
    //o melhor seria achar a menr elemento, para garantir que a diferneca entre maior e menor
    //é a menor possivel na implementação
    elem *contagens = malloc(sizeof(elem)*(maior + 1));
    for(i = 0; i < maior + 1; i++)
        contagens[i] = 0;

    // faz contagem
    for(i = 0; i < l->tamanho; i++)
        contagens[(int) l->elementos[i]]++; 

    // monta vetor ordenado 
    j = 0;
    for(i = 0; i < maior + 1; i++)
        while(contagens[i] > 0){
            l->elementos[j++] = i;
            contagens[i]--;
        }

    // desaloca o vetor contagens
    free(contagens);

}