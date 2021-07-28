#include "modules.h"
#include <stdio.h>
#include <stdlib.h>

void inc(int *a){
    (*a)++;
    printf("\n*a = %d", *a);
}

int main(void){

    int a = 0;

    inc(&a);

    printf("\na = %d", a);

    return 0;
}