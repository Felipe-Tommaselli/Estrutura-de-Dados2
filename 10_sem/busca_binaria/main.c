// Aula busca binaria semana 10

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef int elem;

// indice da bsuca sequencial indexada
typedef struct{
    elem kindex;
    int pos;
} elemi;

int busca_sequencial(elem tabela[], int n, elem e){
    // vetor exemplo: {2, 3, 5, 1, 7, 9, 4, 0, 6, 8}

    int i;
    for(i = 0; i < n; i++)
        if(tabela[i] == e)
            break;
    
    return (i == n) ?-1 : i;
}

int busca_sequencial_sentinela(elem tabela[], int n, elem e){
    // vetor exemplo: {2, 3, 5, 1, 7, 9, 4, 0, 6, 8, -1}

    int i;
    // insere copia de e no ultimo elemento (deve ter um elem -1 no fim da lista)
    //essa condicao da uma simplificada, pois nao precisamos add no codigo esse espaco extra
    tabela[n] = e;
    // varre elementos
    for(i = 0; tabela[i] != n; i++);
    //assume que nao encontrou se chegou ate o sentinela 
    return (i == n) ? -1 : i;
}

int busca_sequencial_ordenada(elem tabela[], int n, elem e){
    // vetor exemplo: {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, -1}

    //obs nao tem problema manter o sentinela se mantivermos n = 10, pois essa ultima pos 
    // o -1 seria a posicao 11, porem é possivel unir as duas ideias p/+ eficiencia ainda
    int i;
    // critério de parada
    for(i = 0; i < n; i++)
        if(tabela[i] >= e)
            break;

    // sucesso para encontrar o elemento 
    if(i != n && tabela[i] == e)
        return i;
    return -1; // insucesso para encontraro elemento
}

int busca_sequencial_indexada(elem tabela[], int n, elem e, elemi tabela_i[], int t){
    // tabela de valores exemplo: {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, -1};
    int i;

    // busca sequencial no indice
    for(i = 0; i < t && tabela_i[i].kindex; i++); 
    
    // caso elemento buscado menor ou igual ao primeiro
    if(i == 0)
        if(e == tabela_i[i].kindex)
            return i;

    // varre tabela de dados
    for(i = tabela_i[i - 1].pos; i < n && e > tabela[i]; i++);

    //! Não ta funcionado, o i ta dando diferente do e
    printf("i: %d\ne: %d\n", i, e);
    if(i < n && e == tabela[i])
        return i;

    return -1;
}

int busca_binaria_recursiva(elem tabela[], int inf, int sup, int e){
    int meio;

    if(inf >= sup) //busca invlida ou em vetor unitario
        return (inf == sup && e == tabela[inf]) ? inf : -1;

    meio = inf + (sup - inf)/2;
    if(e == tabela[meio])
        return meio; // elemento encontrado
    
    // busca recursivamente na metade inferior ou superior
    return (e < tabela[meio]) ? busca_binaria_recursiva(tabela, inf, meio - 1, e) : busca_binaria_recursiva(tabela, meio + 1, sup, e);

}

int busca_binaria(elem tabela[], int n, elem e){
    // exemplo de tabela: {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, -1}
    return busca_binaria_recursiva(tabela, 0, n - 1, e);
}

int busca_binaria_iterativa(elem tabela[], int n, elem e){
    // exmplo de tabela: {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, -1}

    int inf = 0, sup = n - 1, meio;
    meio = inf + (sup - inf)/2;

    while(1){
        // caso do vetor unitario
        if(inf == sup && e == tabela[inf])
            return (e == tabela[meio]) ? inf : -1; 
        
        // elemento achado ser o do meio, ou elemento nao encotnrado
        if(e == tabela[meio] || inf >= sup)
            return (e == tabela[meio]) ? meio : -1;
        
        //elemento a esquerda do atual meio
        if(e < tabela[meio])
            sup = meio - 1;

        //elemento a direita do atual meio
        if(e > tabela[meio])
            inf = meio + 1;

        //atualiza o meio
        meio = inf + (sup - inf)/2;
    }
}

int main(void){
    
    elem tabela[] =  {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, -1}; //tabela de valores
    int retorno, n = 10; //varaivel de retorno, e n para o num de valores da tabela
    int t = 3; // tamanho da tabela de indices da bsuca sequencial indexada
    elem e = 33; // elemento a ser buscado
    elemi tabela_i[t]; //tabela de indices

    // cria tabela de indices
    for(int i = 0; i < t; i++){
        // identificar e guardar a posicao
        tabela_i[i].pos = i*(n/t); //i = 0,1,2 ...     
        // guardar o valor
        tabela_i[i].kindex = tabela[tabela_i[i].pos];
    }

    //retorno = busca_sequencial(tabela, n, e);
    //retorno = busca_sequencial_sentinela(tabela, n, e);
    //retorno = busca_sequencial_ordenada(tabela, n, e);
    //retorno = busca_sequencial_indexada(tabela, n, e, tabela_i, t);
    //retorno = busca_binaria(tabela, n, e);
    retorno = busca_binaria_iterativa(tabela, n, e);

    if(retorno != -1)
        printf("Elemento %d encontrado na posicao %d\n", e, retorno);
    else
        printf("Elemento %d NAO encontrado\n", e);

    return 0; 
}
