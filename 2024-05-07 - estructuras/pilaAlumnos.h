#ifndef PILAALUMNOS_H_INCLUDED
#define PILAALUMNOS_H_INCLUDED

#include "alumno.h"

typedef struct{
    stAlumno* a;
    int dim;
    int v;
}PilaAlumnos;

void inicpila(PilaAlumnos* p);
void apilar(PilaAlumnos* p, stAlumno dato);
stAlumno tope(PilaAlumnos* p);
stAlumno desapilar(PilaAlumnos* p);
int pilaVacia(PilaAlumnos* p);
int pilaVaciaTernario(PilaAlumnos* p);
int pilaVaciaBool(PilaAlumnos* p);
void cargaPilaAlumnosRandom(PilaAlumnos* p);
void muestraPilaAlumnos(PilaAlumnos* p);

#endif // PILAALUMNOS_H_INCLUDED
