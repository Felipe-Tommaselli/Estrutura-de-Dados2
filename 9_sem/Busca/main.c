// Aula busca sequencial semana 9

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef int elem;

int busca_sequencial(elem tabela[], int n, elem e){
    
    int i;
    for(i = 0; i < n; i++)
        if(tabela[i] == e)
            break;
    
    return (i == n) ?-1 : i;
}

int busca_sequencial_sentinela(elem tabela[], int n, elem e){

    int i;
    // insere copia de e no ultimo elemento (deve ter um elem -1 no fim da lista)
    //essa condicao da uma simplificada, pois nao precisamos add no codigo esse espaco extra
    tabela[n] = e;
    // varre elementos
    for(i = 0; tabela[i] != n; i++);
    //assume que nao encontrou se chegou ate o sentinela 
    return (i == n) ? -1 : i;
}

int main(void){
    
    elem tabela[] = {2, 3, 5, 1, 7, 9, 4, 0, 6, 8, -1}; //tabela de valores
    int retorno, n = 11; //varaivel de retorno, e n para o num de valores da tabela
    elem e = 8; // elemento a ser buscado

    //retorno = busca_sequencial(tabela, n, e);
    retorno = busca_sequencial_sentinela(tabela, n, e);

    if(retorno != -1)
        printf("Elemento %d encontrado na posicao %d\n", e, retorno);
    else
        printf("Elemento %d NAO encontrado\n", e);

    return 0; 
}
