#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "pilaAlumnos.h"
#include "alumno.h"
#include "mock.h"

typedef struct{
    char calle[30];
    char nro[6];
    char localidad[30];
    char provincia[30];
}stDomicilio;


#define DIM 100
#define AR_ALUMNOS "alumnos.dat"

int cargaAlumnos(stAlumno a[], int v, int dim);
void muestraAlumnos(stAlumno a[], int v);
stAlumno buscaMenorLegajo(stAlumno a[], int v);
stAlumno buscaMenorApellido(stAlumno a[], int v);
void cargaArchAlumnosRandom(char nombreArchivo[], int cant);
void muestraArchivoAlumnos(char nombreArchivo[]);
stAlumno buscaAlumnoPorLegajo(char nombreArchivo[], int legajo);
stAlumno* buscaAlumnoPorLegajoPuntero(char nombreArchivo[], int legajo);
stAlumno* archivoCompleto2arregloP(char nombreArchivo[], int* v);
void muestraArregloAlumnos(stAlumno a[], int v, int i);


int main()
{
    srand(time(NULL));
    //stAlumno* alumnoPuntero = NULL;
    //cargaArchAlumnosRandom(AR_ALUMNOS, 10);
    //printf("\n Listado de Alumnos del archivo | cant: %d\n", cuentaRegistrosArchivo(AR_ALUMNOS, sizeof(stAlumno)));
    //muestraArchivoAlumnos(AR_ALUMNOS);

    //alumnoPuntero = buscaAlumnoPorLegajoPuntero(AR_ALUMNOS, 10);
    /*if(alumnoPuntero)
        muestraUnAlumno(*alumnoPuntero);
    else
        printf("\nEl legajo no existe");

    PilaAlumnos p;
    inicpila(&p);
*/
   // cargaPilaAlumnosRandom(&p);
 //   printf("\n Listado de Alumnos de la Pila \n");
 //   muestraPilaAlumnos(&p);

    srand(time(NULL));
    stAlumno alumnos[DIM];
    int vAlumnos = 0;

    stAlumno alumnoMenor;

    vAlumnos = cargaAlumnos(alumnos, vAlumnos, DIM);
    //vAlumnos = mockArreglo(alumnos);
    printf("\n Listado de Alumnos %d - %d - vAlumnos: %d - %d\n", sizeof(stAlumno), sizeof(alumnos), vAlumnos, (vAlumnos==8));
    //muestraAlumnos(alumnos, vAlumnos);

    muestraArregloAlumnos(alumnos, vAlumnos, 0);

    alumnoMenor = buscaMenorApellido(alumnos, vAlumnos);
    if(alumnoMenor.legajo > -1){
        printf("\n Alumno con menor apellido \n");
        muestraUnAlumno(alumnoMenor);
    }

    alumnoMenor = buscaMenorLegajo(alumnos, vAlumnos);
    if(alumnoMenor.legajo > -1){
        printf("\n Alumno con menor legajo \n");
        muestraUnAlumno(alumnoMenor);
    }

    return 0;
}

int cargaAlumnos(stAlumno a[], int v, int dim){
    char opcion = 0;

    while(v < dim && opcion != 27){
        system("cls");
        a[v] = cargaUnAlumno();
        v++;
        printf("\nESC para salir o cualquier tecla para continuar...");
        opcion = getch();
    }

    return v;
}

void muestraAlumnos(stAlumno a[], int v){
    for(int i=0;i<v;i++){
        muestraUnAlumno(a[i]);
    }
}

stAlumno buscaMenorLegajo(stAlumno a[], int v){
    stAlumno alumnoMenor;
    alumnoMenor.legajo = -1;
    int i = 0;
    if(v>0){
        alumnoMenor = a[i];
        i++;
        while(i<v){
           if(a[i].legajo < alumnoMenor.legajo){
                alumnoMenor = a[i];
           }
           i++;
        }
    }

    return alumnoMenor;
}

stAlumno buscaMenorApellido(stAlumno a[], int v){
    stAlumno alumnoMenor;
    alumnoMenor.legajo = -1;
    int i = 0;
    if(v>0){
        alumnoMenor = a[i];
        i++;
        while(i<v){
           if(strcmp(a[i].apellido, alumnoMenor.apellido) < 0){
                alumnoMenor = a[i];
           }
           i++;
        }
    }

    return alumnoMenor;
}

int mockArreglo(stAlumno a[]){
    int i;
    for(i=0;i<10;i++){
        a[i] = getAlumnoRandom();
    }
    return i;
}

void cargaArchAlumnosRandom(char nombreArchivo[], int cant){
    FILE* archi = fopen(nombreArchivo, "ab");
    stAlumno alumno, aBuscar;
    int i = 0;
    if(archi){
        while(i<cant){
            alumno = getAlumnoRandom();
            if(buscaAlumnoPorLegajo(nombreArchivo,alumno.legajo).legajo!=alumno.legajo){
                fwrite(&alumno, sizeof(stAlumno), 1, archi);
                i++;
            }
        }
        fclose(archi);
    }
}

void muestraArchivoAlumnos(char nombreArchivo[]){
    stAlumno alumno;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        while(fread(&alumno, sizeof(stAlumno), 1, archi)>0){
            muestraUnAlumno(alumno);
        }
        fclose(archi);
    }
}

stAlumno buscaAlumnoPorLegajo(char nombreArchivo[], int legajo){
    stAlumno a;
    a.legajo = -1;
    int flag = 0;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        while(flag == 0 && fread(&a, sizeof(stAlumno), 1, archi)>0){
            if(a.legajo == legajo){
                flag = 1;
            }
        }
        fclose(archi);
    }
    return a;
}

stAlumno* buscaAlumnoPorLegajoPuntero(char nombreArchivo[], int legajo){
    stAlumno* a = NULL;
    stAlumno alumno;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        while(a==NULL && fread(&alumno,sizeof(stAlumno),1,archi)>0){
            if(alumno.legajo == legajo){
                a = &alumno;
            }
        }
        fclose(archi);
    }

    return a;
}

int cuentaRegistrosArchivo(char nombreArchivo[], int tamEstructura){
    FILE* archi = fopen(nombreArchivo, "rb");
    int total = 0;
    if(archi){
        fseek(archi,0,SEEK_END);
        total = ftell(archi)/tamEstructura;
        fclose(archi);
    }
    return total;
}

int archivo2arreglo(char nombreArchivo[], stAlumno a[], int v, int dim){
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        while(v<dim && fread(&a[v],sizeof(stAlumno),1,archi)>0){
            v++;
        }
        fclose(archi);
    }
    return v;
}

int archivoCompleto2arreglo(char nombreArchivo[], stAlumno a[], int dim){
    FILE* archi = fopen(nombreArchivo, "rb");
    int v = cuentaRegistrosArchivo(nombreArchivo, sizeof(stAlumno));
    if(archi){
        if(v<dim){
            fread(a, sizeof(stAlumno), v, archi);
        }else{
            v=0;
        }
        fclose(archi);
    }
    return v;
}

stAlumno* archivoCompleto2arregloP(char nombreArchivo[], int* v){
    FILE* archi = fopen(nombreArchivo, "rb");
    *v = cuentaRegistrosArchivo(nombreArchivo, sizeof(stAlumno));
    stAlumno* a = (stAlumno*) malloc(sizeof(stAlumno)*(*v));
    if(archi){
        fread(a, sizeof(stAlumno), *v, archi);
        fclose(archi);
    }
    return a;
}

void archivo2pila(char nombreArchivo[], PilaAlumnos* p){
    FILE* archi = fopen(nombreArchivo, "rb");
    stAlumno a;
    if(archi){
        while(fread(&a, sizeof(stAlumno), 1, archi)>0){
            if(a.legajo%2==0)
                apilar(p, a);
        }
        fclose(archi);
    }
}

void pila2archivo(PilaAlumnos p, char nombreArchivo[]){
    FILE* archi = fopen(nombreArchivo, "ab");
    stAlumno a;
    if(archi){
        while(!pilaVacia(&p)){
            a = desapilar(&p);
            fwrite(&a,sizeof(stAlumno),1,archi);
        }

        fclose(archi);
    }
}

int factorial(int x){
    int rta;
    if(x==0){
        rta=1;
    }else{

        rta=x*factorial(x-1);

    }

    return rta;
}

int factorial1(int x){
    int rta=1;
    if(x>0){
        rta=x*factorial1(x-1);
    }

    return rta;
}

int factorialT(int x){
    return (x>0)?x*factorialT(x-1):1;
}

int sumaArreglo(int a[], int v, int i){
    int suma;
    if(i==v-1){
        suma = a[i];
    }else{
        suma = a[i] + sumaArreglo(a, v, i+1);
    }

    return suma;
}

int sumaArregloImp(int a[], int v, int i){
    int suma=0;
    if(i<v){
        suma = a[i] + sumaArreglo(a, v, i+1);
    }

    return suma;
}

int sumaArregloTer(int a[], int v, int i){
    return (i<v)?a[i]+sumaArregloTer(a, v, i+1):0;
}

void muestraArreglo(int a[], int v, int i){
    if(i<v){
        printf("\n %d", a[i]);
        muestraArreglo(a, v, i+1);
    }
}

void muestraArregloAlumnos(stAlumno a[], int v, int i){
    if(i<v){
        muestraArregloAlumnos(a,v,i+1);
        muestraUnAlumno(a[i]);
    }
}

stAlumno buscaAlumnoPorLegajoRecursivo(stAlumno a[], int v, int i){
    stAlumno menor;
    if(i==v-1){
       menor = a[i];
    }else{
        menor = buscaAlumnoPorLegajoRecursivo(a, v, i+1);
        if(a[i].legajo < menor.legajo ){
            menor = a[i];
        }
    }
    return menor;
}

int buscaPosAlumno(char nombreArchivo[], int legajo){
    stAlumno a;
    int cont = 0;
    int pos = -1;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        while(pos == -1 && fread(&a, sizeof(stAlumno), 1, archi)>0){
            if(a.legajo == legajo){
                pos = cont;
            }
            cont++;
        }

        fclose(archi);
    }
    return pos;
}

int buscaPosAlumnoFtell(char nombreArchivo[], int legajo){
    stAlumno a;
    int pos = 0;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        while(pos == 0 && fread(&a, sizeof(stAlumno), 1, archi)>0){
            if(a.legajo == legajo){
                pos = ftell(archi)/sizeof(stAlumno);
            }
        }

        fclose(archi);
    }
    return pos;
}

void modificaAlumno(char nombreArchivo[], stAlumno alumno, int pos){
    stAlumno a;

    if(pos <= cuentaRegistrosArchivo(nombreArchivo, sizeof(stAlumno))){
        FILE* archi = fopen(nombreArchivo, "r+b");
        if(archi){
            fseek(archi, pos * sizeof(stAlumno), 0);
            fread(&a, sizeof(stAlumno), 1, archi);
            a = editAlumno(a, alumno);
            fseek(archi, -1 * sizeof(stAlumno), 1);
            fwrite(&a, sizeof(stAlumno),1, archi);

            fclose(archi);
        }
    }
}

stAlumno editAlumno(stAlumno origen, stAlumno nuevo){
    if(nuevo.legajo != 0){
        origen.legajo = nuevo.legajo;
    }
    if(strlen(nuevo.nombre)>0){
        strcpy(origen.nombre, nuevo.nombre)
    }
    if(strlen(nuevo.apellido)>0){
        strcpy(origen.apellido, nuevo.apellido)
    }
    if(nuevo.dia != 0){
        origen.dia = nuevo.dia;
    }
    if(nuevo.mes != 0){
        origen.mes = nuevo.mes;
    }
    if(nuevo.anio != 0){
        origen.anio = nuevo.anio;
    }
    return origen;
}
