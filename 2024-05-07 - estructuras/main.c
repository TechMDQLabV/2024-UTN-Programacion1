#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "alumno.h"

typedef struct{
    char calle[30];
    char nro[6];
    char localidad[30];
    char provincia[30];
}stDomicilio;


#define DIM 100

int cargaAlumnos(stAlumno a[], int v, int dim);
void muestraAlumnos(stAlumno a[], int v);
stAlumno buscaMenorLegajo(stAlumno a[], int v);
stAlumno buscaMenorApellido(stAlumno a[], int v);

int main()
{
    stAlumno alumnos[DIM];
    int vAlumnos = 0;
    stAlumno alumnoMenor;

    vAlumnos = cargaAlumnos(alumnos, vAlumnos, DIM);

    printf("\n Listado de Alumnos \n");
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
        printf("\n=================================================\n");
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
