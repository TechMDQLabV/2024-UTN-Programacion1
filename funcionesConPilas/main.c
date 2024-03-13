#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Pila.h"

void cargaPila(Pila* p);
void muestraPila(Pila p);

int main()
{
    Pila temperaturas;
    Pila tempLondres;
    inicpila(&temperaturas);
    inicpila(&tempLondres);

    cargaPila(&temperaturas);
    printf("\n Listado de Temperaturas");
    muestraPila(temperaturas);

    cargaPila(&tempLondres);
    printf("\n Listado de Temperaturas de Londres");
    muestraPila(tempLondres);
    return 0;
}

void cargaPila(Pila* p){
    char opcion;
    int dato;

    do{
        printf("\nIngrese una temperatura: ");
        scanf("%d", &dato);
        if(dato>60){
            printf("\n La temperatura no es valida");
            system("pause");
            system("cls");
        }else{
            apilar(p, dato);
        }


        printf("\n\nESC para salir o cualquier tecla para continuar..");
        opcion=getch();
        system("cls");
    }while(opcion != 27);
}

void muestraPila(Pila p){
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&p)){
        printf("\n %d", tope(&p));
        apilar(&aux, desapilar(&p));
    }
}
