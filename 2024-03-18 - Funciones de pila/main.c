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

int main()
{
    int algo;
    printf("\n Probando var sin inicializar %d", algo);

    Pila temperatuas;
    inicpila(&temperatuas);

    Pila tempLondon;
    inicpila(&tempLondon);

    cargaPilaRandomRango(&temperatuas, 6, -10, 35);
    cargaPila(&temperatuas);

    printf("\n Muestra Temperaturas \n");
    muestraPila(temperatuas);

    cargaPilaRandom1(&tempLondon, 3);

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
