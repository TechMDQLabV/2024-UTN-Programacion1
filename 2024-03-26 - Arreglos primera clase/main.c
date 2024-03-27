#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define DIM 100
#define ESC 27

int cargaArregloRandom(int a[], int dim);
void muestraArreglo(int a[], int v);
int cuentaDigitos(int nro);
int cargaArreglo(int a[], int dim, int v, char label[]);

int main()
{
    srand(time(NULL));

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
    if(nro=0){
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

    while(v<dim && opcion != ESC){
        printf("%s",label);
        scanf("%d",&a[v]);
        v++;

        printf("ESC para salir o cualquier tecla para continuar...");
        opcion=getch();
        system("cls");
    }

    return v;
}
