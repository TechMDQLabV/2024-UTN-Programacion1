#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"

stAlumno cargaUnAlumno(){
    stAlumno a;
    printf("\nIngrese nro de Legajo: ");
    scanf("%d", &a.legajo);
    printf("Ingrese Nombre del alumno: ");
    fflush(stdin);
    gets(a.nombre);
    printf("Ingrese Apellido del alumno: ");
    fflush(stdin);
    gets(a.apellido);
    printf("Ingrese dia de nacimiento: ");
    scanf("%d", &a.diaNac);
    printf("Ingrese mes de nacimiento: ");
    scanf("%d", &a.mesNac);
    printf("Ingrese a%co de nacimiento: ", 164);
    scanf("%d", &a.anioNac);

    return a;
}

void muestraUnAlumno(stAlumno a){
    printf("\n Legajo No.............: %d", a.legajo);
    printf("\n Nombre................: %s", a.nombre);
    printf("\n Apellido..............: %s", a.apellido);
    printf("\n Fecha de nacimiento...: %d/%d/%d", a.diaNac, a.mesNac, a.anioNac);
    printf("\n=================================================\n");
}
