#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "pila.h"

#define DIM 100
#define SDIM 30
#define ESC 27

int cargaArregloRandom(int a[], int dim);
void muestraArreglo(int a[], int v);
int cuentaDigitos(int nro);
int cargaArreglo(int a[], int dim, int v, char label[]);
int esCapicua(int a[], int v);
void invierteArregloInt(int a[], int v);
void intercambio(int *a, int *b);
void insertaOrdenado(int d, char a[][d], int v, char dato[]);
void ordenaPorInsercion(int d, char a[][d], int v);

int main()
{
    int numeros[100];
    int vNumeros=0;
    vNumeros=cargaArregloRandom(numeros, 100);
    ordenaPorInsercionInt(numeros, vNumeros);
    muestraArreglo(numeros, vNumeros);
    srand(time(NULL));
    char nombres[DIM][SDIM];
    int vNombres = 0;
    int posMenor;

    vNombres = cargaArregloString(SDIM, nombres, vNombres, DIM, "Ingrese un nombre: ");
    printf("\n <<<<< Listado de Nombres >>>>>\n");
    muestraArregloString(SDIM, nombres, vNombres);

    //ordenaArregloStrSel(SDIM, nombres, vNombres);
    ordenaPorInsercion(SDIM, nombres, vNombres);

    printf("\n <<<<< Listado de Nombres >>>>>\n");
    muestraArregloString(SDIM, nombres, vNombres);

    posMenor = buscaPosMenorArregloString(SDIM, nombres, vNombres);
    if(posMenor>-1){
        printf("\n Menor: %s", nombres[posMenor]);
    }
    int filas=10;
    int columnas=8;
    int matriz[filas][columnas];

    cargaMatrizRandom(filas, columnas, matriz);
    printf("\n Listado de la Matriz \n\n");
    muestraMatriz(filas, columnas, matriz);

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

void cargaMatrizRandom(int fil, int col, int m[fil][col]){
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            m[i][j]=rand()%200;
        }
    }
}

void cargaMatrizUsuario(int fil, int col, int m[fil][col]){
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            printf("\n Ingrese una nota: ");
            scanf("%d", &m[i][j]);
        }
    }
}

void muestraMatriz(int fil, int col, int m[fil][col]){
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            printf(" %4d | ", m[i][j]);
        }
        printf("\n");
    }
}

int sumaMatriz(int fil, int col, int m[fil][col]){
    int total = 0;
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            total += m[i][j];
        }
    }
    return total;
}

void muestraArregloString(int d, char a[][d], int v){
    for(int i=0;i<v;i++){
        printf("\n %s", a[i]);
    }
    printf("\n================================================");
}

int cargaArregloString(int d, char a[][d], int v, int dim, char label[]){
    char opcion = 0;
    char s[d+10];
    while(v<dim && opcion != 27){
        printf("\n %s", label);
        fflush(stdin);
        gets(s);
        s[d+10]='\0';
        if(strlen(s)<d){
            strcpy(a[v],s);
            v++;
        }else{
            printf("\n Se paso de la dimension");
            getch();
        }
        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion=getch();
        system("cls");
    }
    return v;
}

int buscaPosMenorArregloString(int d, char a[][d], int v){
    int posMenor = -1;
    if(v>0){
        posMenor=0;
    }
    for(int i=1;i<v;i++){
        if(strcmp(a[i],a[posMenor])<0){
            posMenor = i;
        }
    }
    return posMenor;
}

int buscoStringEnArreglo(int d, char a[][d], int v, char dato[]){
    int flag = 0;
    int i = 0;
    while(i<v && flag == 0){
        if(strcmp(a[i],dato)==0){
            flag = 1;
        }else{
            i++;
        }
    }
    return flag;
}

void intercambioStrings(char s1[], char s2[]){
    char aux[100];
    strcpy(aux, s1);
    strcpy(s1, s2);
    strcpy(s2, aux);
}

/// Busca la posicion del menor elemento en el arreglo
/// para se usada en la funcion de ordenacion por seleccion
int buscaPosMenorArregloStringOrd(int d, char a[][d], int v, int c){
    int posMenor = c;
    for(int i=c+1;i<v;i++){
        if(strcmp(a[i],a[posMenor])<0){
            posMenor = i;
        }
    }
    return posMenor;
}

void ordenaArregloStrSel(int d, char a[][d], int v){
    int posMenor;
    for(int i=0;i<v-1;i++){
        posMenor = buscaPosMenorArregloStringOrd(d, a, v, i);
        intercambioStrings(a[i],a[posMenor]);
    }
}
/// Funcion para ser usada con el algoritmo de insercion
void insertaOrdenado(int d, char a[][d], int v, char dato[]){
    int i = v;
    while(i >= 0 && strcmp(dato, a[i])<0){
        strcpy(a[i+1], a[i]);
        i--;
    }
    strcpy(a[i+1], dato);
}

void ordenaPorInsercion(int d, char a[][d], int v){
    muestraArregloString(d, a, v);
    for(int i=0; i<v-1 ;i++){
        printf("%d - %s", i, a[i]);
        insertaOrdenado(d, a, i, a[i+1]);
    }
}

/// Funcion para ser usada con el algoritmo de insercion
void insertaOrdenadoInt(int a[], int v, int dato){
    int i = v;
    while(i >= 0 && dato < a[i]){
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = dato;
}

void ordenaPorInsercionInt(int a[], int v){
    for(int i=0;i<v-1;i++){
        insertaOrdenadoInt(a, i, a[i+1]);
    }
}
