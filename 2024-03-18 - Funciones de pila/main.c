#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "pila.h"

void cargaPila(Pila* p);
void muestraPila(Pila p);
int randomRango(int min, int max);
void cargaPilaRandom(Pila* p);
void cargaPilaRandom1(Pila* p, int cant);
void cargaPilaRandomRango(Pila* p, int cant, int min, int max);
void muestraMenu();
void menu();
int ingresoDato();

int main()
{
    menu();

    return 0;
}

void muestraMenu(){
    printf("\n\t\t Menu de opciones de funciones de pila\n\n");
    printf("\n 1 - Carga Pila Random");
    printf("\n 2 - Carga Pila con intervencion del usuario");
    printf("\n 3 - Muestra pila");
    printf("\n 4 - Busca un dato en la pila");
    printf("\n 5 - Cuenta elementos de una pila");
    printf("\n 6 - Suma los elementos de una pila");
    printf("\n 7 - Busca el menor elemento de una pila");
    printf("\n 8 - Muestra tabla ASCII");

    printf("\n\n\n");
    printf("ESC para salir o cualquier tecla para continuar");
}

void menu(){
    char opcion;
    int existe;
    int dato;
    Pila temperaturas;
    inicpila(&temperaturas);

    do{
        system("cls");
        muestraMenu();

        opcion = getch();

        switch(opcion){
            case 49:
                cargaPilaRandomRango(&temperaturas, 20, -5, 25);
                break;
            case 50:
                cargaPila(&temperaturas);
                break;
            case 51:
                if(!pilavacia(&temperaturas)){
                    muestraPila(temperaturas);
                }else{
                    printf("\n La pila esta vacia");
                }
            case 52:
                dato = ingresoDato();
                existe = buscaElementoEnPila(temperaturas, dato);
                if(existe){  /// if(existe == 1)
                    printf("\n El dato %d existe en la pila", dato);
                }else{
                    printf("\n El dato %d NO existe en la pila", dato);
                }
                break;
            case 53:
                break;
            case 56:
                muestraTablaAscii();
        }
        system("pause");
    }while(opcion!=27);

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

void cargaPilaRandom1(Pila* p, int cant){
    int contador=0;
    while(contador < cant){
        apilar(p, rand()%100);
        contador++;
    }
}

/********************************************//**
 * \brief comentario
 *
 * \param numero minimo
 * \param numero maximo
 * \return entero aleatorio
 *
 ***********************************************/
int randomRango(int min, int max){
    return rand()%(max-min)+min;
}

void cargaPilaRandomRango(Pila* p, int cant, int min, int max){
    int contador = 0;
    while(contador < cant){
        apilar(p, randomRango(min, max));
        contador++;
    }
}

void pasaPila(Pila* origen, Pila* destino){
    while(!pilavacia(origen)){
        apilar(destino, desapilar(origen));
    }
}

int cuentaElementosPila(Pila p){
    Pila aux;
    inicpila(&aux);
    int contador = 0;

    while(!pilavacia(&p)){
        apilar(&aux, desapilar(&p));
        contador = contador + 1; /// contador++
    }

    return contador;
}

int sumaElementosPila(Pila p){
    Pila aux;
    inicpila(&aux);
    int total = 0;

    while(!pilavacia(&p)){
        total = total + tope(&p); /// total += tope(&p)
        apilar(&aux, desapilar(&p));
    }

    return total;
}

int buscaElementoEnPila(Pila p, int dato){
    int flag = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p) && flag == 0){
        if(tope(&p) == dato){
            flag = 1;
        }else{
            apilar(&aux, desapilar(&p));
        }
    }

    return flag;
}

int ingresoDato(){
    int dato;
    printf("\n Ingrese el dato a buscar: ");
    scanf("%d", &dato);
    return dato;
}

void muestraTablaAscii(){
    printf("\n\t\t Tabla ASCII de caracteres");
    for(int i=0; i<257; i++){
        printf("\n Codigo: %d - %c",i,i);
    }
}
