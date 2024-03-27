#include <stdio.h>
#include <stdlib.h>

#define DIM 100

int cargaArregloRandom(int a[], int dim);
void muestraArreglo(int a[], int v);

int main()
{
    int notas[DIM];
    int validosNotas = 0;
    validosNotas = cargaArregloRandom(notas, DIM);
    printf("\n Listado de notas\n");
    muestraArreglo(notas, validosNotas);
    return 0;
}

int cargaArregloRandom(int a[], int dim){
    int i;
    for(i=0;i<50;i++){
        a[i] = rand()%10;
    }
    return i;
}

void muestraArreglo(int a[], int v){
    for(int i=0;i<v;i++){
        if(i%10==0){
            printf("\n");
        }
        printf("%d | ", a[i]);
    }
}
