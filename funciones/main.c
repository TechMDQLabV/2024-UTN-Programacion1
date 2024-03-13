#include <stdio.h>
#include <stdlib.h>

void intercambio(int*, int*);
void intercambioSinAux(int *a, int *b);

int main()
{
    int a = 1;
    int b = 5;
    intercambioSinAux(&a, &b);
    printf("En el main A: %d - B: %d", a, b);

    return 0;
}

void intercambio(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
    printf("En la funcion A: %d - B: %d", *a, *b);
}

void intercambioSinAux(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    printf("En la funcion A: %d - B: %d", *a, *b);
}
