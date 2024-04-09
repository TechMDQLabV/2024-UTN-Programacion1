#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "pila.h"

#define DIM 100
#define ESC 27

int cargaArregloRandom(int a[], int dim);
void muestraArreglo(int a[], int v);
int cuentaDigitos(int nro);
int cargaArreglo(int a[], int dim, int v, char label[]);
int esCapicua(int a[], int v);
void invierteArregloInt(int a[], int v);
void intercambio(int *a, int *b);

int main()
{
    srand(time(NULL));

    char letras[]={'a','b','c','d'};
    char salludo[]="Hello World";

    printf("Letras: %s", letras);

    Pila algo;
    inicpila(&algo);

    int notas[DIM];
    int validosNotas = 0;
    ///validosNotas = cargaArregloRandom(notas, DIM);
    validosNotas = cargaArreglo(notas, DIM, validosNotas, "Ingrese una nota: ");
    printf("\n Listado de notas\n");
    muestraArreglo(notas, validosNotas);
    validosNotas = cargaArreglo(notas, DIM, validosNotas, "Ingrese una temperatura: ");
    printf("\n Listado de notas\n");
    muestraArreglo(notas, validosNotas);
    validosNotas = 0;
    validosNotas = cargaArreglo(notas, DIM, validosNotas, "Ingrese una edad: ");
    printf("\n Listado de notas\n");
    muestraArreglo(notas, validosNotas);
    printf("\n El nro 0 tiene %d digitos", cuentaDigitos(0));
    printf("\n El nro 1999 tiene %d digitos", cuentaDigitos(1999));
    printf("\n El nro 3000000 tiene %d digitos", cuentaDigitos(3000000));


    return 0;
}

int cargaArregloRandom(int a[], int dim){
    int i;
    for(i=0;i<dim;i++){
        a[i] = rand()%1000;
    }
    return i;
}

void muestraArreglo(int a[], int v){
    for(int i=0;i<v;i++){
        if(i%10==0){
            printf("\n");
        }
        printf("%5d | ", a[i]);
    }
}

int cuentaDigitos(int nro){
    int digitos = 0;
    if(nro==0){
        digitos = 1;
    }
    while(nro > 0){
        digitos++;
        nro = nro / 10;
    }
    return digitos;
}

int cargaArreglo(int a[], int dim, int v, char label[]){
    char opcion;
    int nro;

    while(v<dim && opcion != ESC){
        printf("%s",label);
        scanf("%d",&nro);
        a[v]=nro;
        v++;

        printf("ESC para salir o cualquier tecla para continuar...");
        opcion=getch();
        system("cls");
    }

    return v;
}

void arreglo2pilaWhile(int a[], int v, Pila* p){
    int i=0;
    while(i<v && i<50){
        if(a[i]%2==0){
            apilar(p, a[i]);
        }
        i++;
    }
}

/** \brief Copiamos datos de una arreglo en una pila
 * sin verificar que no se pase de la dimension de la pila
 *
 * \param El arreglo
 * \param sus validos
 * \param Puntero a pila
 * \return
 *
 */
void arreglo2pilaFor(int a[], int v, Pila* p){
    for(int i=0;i<v;i++){
        if(a[i]%2==0){
            apilar(p, a[i]);
        }
    }
}

int esCapicua(int a[], int v){
    int flag = 1;
    int inicio = 0;
    int fin = v - 1;

    while(inicio < fin && flag == 1){
        if(a[inicio] == a[fin]){
            inicio++;
            fin--;
        }else{
            flag = 0;
        }

    }
    return flag;
}

void invierteArregloInt(int a[], int v){
    int inicio = 0;
    int fin = v - 1;
    while(inicio < fin){
        intercambio(&a[inicio], &a[fin]);
        inicio++;
        fin--;
    }
}

void intercambio(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
