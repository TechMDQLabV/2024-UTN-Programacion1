#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "pila.h"

void cargaPila(Pila* p);
void muestraPila(Pila p);
void cargaPilaRandom(Pila* p);
void cargaPilaRandomRango(Pila* p, int min, int max);

int main()
{
    Pila temperatuas;
    inicpila(&temperatuas);
    Pila tempLondon;
    inicpila(&tempLondon);

    cargaPila(&temperatuas);

    printf("\n Muestra Temperaturas \n");
    muestraPila(temperatuas);

    cargaPilaRandom(&tempLondon);

    printf("\n Muestra Temperaturas de Londres \n");
    muestraPila(tempLondon);


    return 0;
}

void cargaPila(Pila* p)
{
    char opcion;
    int dato;

    while(opcion != 27)
    {
        printf("\nIngrese un nro: ");
        scanf("%d", &dato);
        apilar(p, dato);

        printf("ESC para salir o cualquier tecla para continuar...");
        opcion=getch();
        system("cls");
    }
}

void muestraPila(Pila p)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p))
    {
        printf("%d - ",tope(&p));
        apilar(&aux, desapilar(&p));
    }
}

void cargaPilaRandom(Pila* p){
    for(int i=0;i<50;i++){
        apilar(p, rand());
    }
}

void cargaPilaRandomRango(Pila* p, int min, int max){

}
