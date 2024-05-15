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

int main()
{
    cargaArchAlumnosRandom(AR_ALUMNOS, 10);
    printf("\n Listado de Alumnos del archivo \n");
    muestraArchivoAlumnos(AR_ALUMNOS);

    PilaAlumnos p;
    inicpila(&p);

    cargaPilaAlumnosRandom(&p);
    printf("\n Listado de Alumnos de la Pila \n");
    muestraPilaAlumnos(&p);

    srand(time(NULL));
    stAlumno alumnos[DIM];
    int vAlumnos = 0;

    stAlumno alumnoMenor;

   // vAlumnos = cargaAlumnos(alumnos, vAlumnos, DIM);
    vAlumnos = mockArreglo(alumnos);
    printf("\n Listado de Alumnos %d - %d - vAlumnos: %d - %d\n", sizeof(stAlumno), sizeof(alumnos), vAlumnos, (vAlumnos==8));
    muestraAlumnos(alumnos, vAlumnos);

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
    stAlumno alumno;
    int i = 0;
    if(archi){
        while(i<cant){
            alumno = getAlumnoRandom();
            fwrite(&alumno, sizeof(stAlumno), 1, archi);
            i++;
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
