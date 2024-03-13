#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Pila.h"

#define ESC 27


int main()
{
    char opcion;
    int nro;

    Pila datos;
    Pila aux;
    Pila aux1;
    inicpila(&datos);
    inicpila(&aux);
    inicpila(&aux1);

    /// Cargo la pila con intervencion del usuario
    while(opcion!=ESC){
        printf("Ingrese un nro: ");
        scanf("%d",&nro);
        apilar(&datos, nro);

        printf("\n\nPresione ESC para salir o cualquier tecla para continuar...");
        opcion=getch();
        system("cls");
    }


    /// Invierto los datos de la pila
    while(!pilavacia(&datos)){
        apilar(&aux, desapilar(&datos));
    }

    while(!pilavacia(&aux)){
        apilar(&aux1, desapilar(&aux));
    }

    while(!pilavacia(&aux1))
        apilar(&datos, desapilar(&aux1));

    /// Muestro los datos de la pila
    while(!pilavacia(&datos)){
        printf("%d - ", tope(&datos));
        apilar(&aux, desapilar(&datos));
    }

    while(!pilavacia(&aux)){
        apilar(&datos, desapilar(&aux));
    }

    return 0;
}
