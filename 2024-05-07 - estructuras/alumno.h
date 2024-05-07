#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct{
    int legajo;
    char nombre[30];
    char apellido[40];
    int diaNac;
    int mesNac;
    int anioNac;
}stAlumno;

stAlumno cargaUnAlumno();
void muestraUnAlumno(stAlumno a);

#endif // ALUMNO_H_INCLUDED
