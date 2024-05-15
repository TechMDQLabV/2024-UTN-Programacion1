#include <malloc.h>
#include "pilaAlumnos.h"
#include "mock.h"

void inicpila(PilaAlumnos* p){
    p->dim = 50;
    p->v = 0;
    p->a = (stAlumno*) malloc(sizeof(stAlumno)*p->dim);
}

void apilar(PilaAlumnos* p, stAlumno dato){
    if(p->v == p->dim){
        p->dim = p->dim + 50;
        p->a = realloc(p->a,sizeof(stAlumno)*p->dim);
    }
    p->a[p->v]=dato;
    p->v++;
}

stAlumno tope(PilaAlumnos* p){
    return p->a[p->v-1];
}

stAlumno desapilar(PilaAlumnos* p){
    p->v--;
    return p->a[p->v];
}

int pilaVacia(PilaAlumnos* p){
    int flag = 0;
    if(p->v == 0){
        flag = 1;
    }
    return flag;
}

int pilaVaciaTernario(PilaAlumnos* p){
    return (p->v == 0) ? 1 : 0;
}

int pilaVaciaBool(PilaAlumnos* p){
    return (p->v == 0);
}

void cargaPilaAlumnosRandom(PilaAlumnos *p){
    int i = 0;
    while(i<10){
        apilar(p, getAlumnoRandom());
        i++;
    }
}

void muestraPilaAlumnos(PilaAlumnos *p){
    for(int i=0;i<p->v;i++){
        muestraUnAlumno(p->a[i]);
        printf("\n=================================================\n");
    }
}
