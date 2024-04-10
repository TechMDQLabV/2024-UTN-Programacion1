#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define DIM_NOTAS 100
#define ESC 27

int cargaArregloNotas(int a[], int v, int dim);
int sumaArreglo(int a[], int v);
float promedioNotas(int a[], int v);
void muestraArreglo(int a[], int v);
void copiaArregloEnPilas(int a[], int v, Pila* aprobados, Pila* desaprobados);
void muestraPila(Pila p);

int main()
{
    int notas[DIM_NOTAS];
    int vNotas=0;
    Pila aprobados;
    Pila desaprobados;
    inicpila(&aprobados);
    inicpila(&desaprobados);
    float promedio;

    printf("\n Carga Notas ");
    vNotas = cargaArregloNotas(notas, vNotas, DIM_NOTAS);

    printf("\n Listado de  Notas ");
    muestraArreglo(notas, vNotas);

    promedio = promedioNotas(notas, vNotas);
    printf("\n El promedio de las notas es: %.2f", promedio);

    copiaArregloEnPilas(notas, vNotas, &aprobados, &desaprobados);

    printf("\n Listado de  Aprobados ");
    muestraPila(aprobados);

    printf("\n Listado de  Desaprobados ");
    muestraPila(desaprobados);

    return 0;
}

/**
Hacer una función que cargue un arreglo con intervención del usuario validando
el ingreso de notas que estén en un rango de 1 a 10.
*/

int cargaArregloNotas(int a[], int v, int dim){
    char opcion=0;
    int nota;

    while(v<dim && opcion!=ESC){
        printf("\n Ingrese una nota (1 a 10): ");
        scanf("%d", &nota);

        if(nota>0 && nota < 11){
            a[v] = nota;
            v++;
        }else{
            printf("\n La nota ingresada no es valida!!!");
            getch();
        }
        printf("\n ESC para salir o cualquier tecla para continuar...");
        opcion=getch();
        system("cls");
    }

    return v;
}

/**
Hacer una función que sume las notas del arreglo
*/
int sumaArreglo(int a[], int v){
    int total = 0;

    for(int i=0; i<v; i++){
        total += a[i];
    }

    return total;
}

/**
Hacer una función calcule el promedio de las notas;
*/
float promedioNotas(int a[], int v){
    float promedio = 0;

    if(v > 0)
        promedio = (float) sumaArreglo(a, v) / v;

    return promedio;
}

/**
Hacer una función que muestre el arreglo pero solo 10 notas por línea.
*/
void muestraArreglo(int a[], int v){
    for(int i=0;i<v;i++){
        if(i%10==0){
            printf("\n");
        }
        printf(" %d ", a[i]);
    }
}

/**
Hacer una función que copie en una pila las notas mayores a 5 (aprobados)
 y en otra los menores o iguales a 5 (desaprobados).
*/
void copiaArregloEnPilas(int a[], int v, Pila* aprobados, Pila* desaprobados){
    for(int i=0;i<v;i++){
        if(a[i]>5){
            apilar(aprobados, a[i]);
        }else{
            apilar(desaprobados, a[i]);
        }
    }
}

/**
Hacer una función que muestre una pila sin usar la función mostrar de pila,
 mostrando solo 15 notas por línea.
*/
void muestraPila(Pila p){
    Pila aux;
    inicpila(&aux);
    int cont = 0;
    while(!pilavacia(&p)){
        if(cont%15==0){
            printf("\n");
        }
        printf(" %d ", tope(&p));
        apilar(&aux, desapilar(&p));
        cont++;
    }
}
