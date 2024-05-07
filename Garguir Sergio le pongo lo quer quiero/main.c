#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

int main()
{
    Pila temperaturas;
    Pila tempMenores;
    Pila tempMayores;
    inicpila(&temperaturas);
    inicpila(&tempMayores);
    inicpila(&tempMenores);

    int total;
    int cont;

    int arreglo[100];
    int v=0;

    cargaPila(&temperaturas);
    printf("\n listado de temperaturas");
    muestraPila(temperaturas);

    cont = cuentaPila(temperaturas, 3);
    total = sumaPila(temperaturas, 3);

    copiaAPilas(temperaturas, &tempMenores, &tempMayores);
    printf("\n listado de temperaturas %d - %d", cont, total);
    muestraPila(temperaturas);

    printf("\n listado de temperaturas menores");
    muestraPila(tempMenores);

    printf("\n listado de temperaturas mayores");
    muestraPila(tempMayores);

    v = pila2arreglo(temperaturas, arreglo, v, 100);
    printf("\n listado de temperaturas");
    muestraArreglo(arreglo, v);


    printf("Hello world!\n");
    return 0;
}
/**
Hacer una función para cargar una pila de temperaturas con intervención del usuario validando que estén dentro del rango de valores elegido por el usuario.
 Las temperaturas deben ser de tipo entero y estar en el rango de -10 a 40.
*/

void cargaPila(Pila *p){
    char opcion = 0;
    int temp;

    while(opcion != 27 ){
        system("cls");
        printf("\n Ingrese una temperatura entre (-10 y 40): ");
        scanf("%d",&temp);

        if(temp >= -10 && temp <= 40){
            apilar(p, temp);
        }else{
            printf("\n Dato incorrecto...");
            getch();
        }

        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion = getch();
    }
}

/**
Hacer una función que muestre la pila de las temperaturas (sin utilizar la función mostrar() de la librería de pilas)
 Se deberán mostrar 15 temperaturas por línea.
*/

void muestraPila(Pila p){
    Pila aux;
    inicpila(&aux);
    int i = 0;

    while(!pilavacia(&p)){
        if(i%4 == 0){
            printf("\n");
        }
        printf(" %d - ", tope(&p));
        apilar(&aux, desapilar(&p));
        i++;
    }
}

/**
Hacer una función que copie a una pila menores las temperaturas <= 0 y a una pila mayores el resto
 de las temperaturas. No se deben perder los datos de la pila original.
*/

void copiaAPilas(Pila origen, Pila *men, Pila *may){
    while(!pilavacia(&origen)){
        if(tope(&origen) <= 0){
            apilar(men, desapilar(&origen));
        }else{
            apilar(may, desapilar(&origen));
        }
    }
}

/**
    Hacer una función que encuentre la temperatura mínima en la pila
     y la retorne (la temperatura mínima debe quitarse de la pila).
*/
/// es responsabilidad del programador controlar que la pila tenga datos
int buscaMenor(Pila *p){
    Pila aux;
    inicpila(&aux);
    int menor;

    menor = desapilar(p);

    while(!pilavacia(p)){
        if(tope(p) < menor){
            apilar(&aux, menor);
            menor = desapilar(p);
        }else{
            apilar(&aux, desapilar(p));
        }
    }

    while(!pilavacia(&aux)){
        apilar(p, desapilar(&aux));
    }

    return menor;
}

/**
Hacer una función que cuente las temperaturas de una pila, mayores
 a un valor dado y lo retorne. (el valor se recibe por parámetro).
*/
int cuentaPila(Pila p, int valor){
    Pila aux;
    inicpila(&aux);
    int cont = 0;

    while(!pilavacia(&p)){
        if(tope(&p) > valor){
            cont ++;
        }
        apilar(&aux, desapilar(&p));
    }

    return cont;
}

/**
Hacer una función que sume las temperaturas de una pila, mayores
 a un valor dado y lo retorne. (el valor se recibe por parámetro).
*/
int sumaPila(Pila p, int valor){
    Pila aux;
    inicpila(&aux);
    int total = 0;

    while(!pilavacia(&p)){
        if(tope(&p) > valor){
            total+=tope(&p);
        }
        apilar(&aux, desapilar(&p));
    }
    return total;
}

/**
Hacer una función que cargue un arreglo de temperaturas ordenado
 de menor a mayor a partir de la pila de temperaturas.
*/
int pila2arreglo(Pila p, int a[], int v, int dim){
    while(!pilavacia(&p) && v < dim){
        a[v] = buscaMenor(&p);
        v++;
    }
    return v;
}

/**
Hacer una función que muestre un arreglo de temperaturas pero solo 20 por línea.
*/
void muestraArreglo(int a[], int v){
    for(int i=0;i<v;i++){
        if(i%3==0){
            printf("\n");
        }
        printf(" %d - ", a[i]);
    }
}
