#include "pila.h"


void inicpila(P_Pila p)
{
       int *aux;
       aux = (int *)malloc(50*sizeof(int));
       p->valores = aux;
       p->postope=0;
}

void apilar(P_Pila p, int dato)
{
    int index = (*p).postope;
    (*p).valores[index]=dato;
    (*p).postope = (*p).postope + 1;
}

int desapilar(P_Pila p)
{
       int z = p->valores[p->postope -1];
       p->postope--;
       return z;
}

int tope(P_Pila p)
{
       return p->valores[p->postope - 1];
}

int pilavacia(P_Pila p)
{
       return (p->postope == 0);
}

void leer (P_Pila p)
{
    int aux = 0;
    if (p->postope < 50)
    {
        printf("Ingrese un valor entero: ");
        fflush(stdin);
        scanf("%d", &aux);
        apilar(p, aux);
    }
    else
        printf("Error: la pila esta llena");
}

void mostrar(P_Pila p)
{
    int i;
    printf("\nBase .............................................. Tope\n");
    for(i=0; i < p->postope; i++)
        printf("| %d ", p->valores[i]);
    printf("\nBase .............................................. Tope\n");
}

void intercalar(P_Pila p1,P_Pila p2,P_Pila p3)
{
       while (!pilavacia(p1) && !pilavacia(p2))
       {
               if(tope(p1)<tope(p2))
               {
                       apilar(p3, desapilar(p1));
               }
               else
               {
                       apilar(p3, desapilar(p2));
               }
       }
       if(!pilavacia(p1))
       {
               while(!pilavacia(p1))
               {
                       apilar(p3, desapilar(p1));
               }
       }
       else
  {
               while(!pilavacia(p2))
               {
                       apilar(p3, desapilar(p2));
               }
       }
}


