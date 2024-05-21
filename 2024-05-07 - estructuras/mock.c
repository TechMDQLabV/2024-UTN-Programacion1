#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"

int getFileNumber(){
    return (rand()%9000)+100;
}

int getDay(){
    return (rand()%31)+1;
}

int getMonth(){
    return (rand()%12)+1;
}

int getYear(){
    return (rand()%90)+1930;
}

void getName(char name[]){
    char names[][30]={"Juan","Apolonio","Tulio","Maria","Violeta","Amalio","Juan","Roberto","Antonio","Pedro","Fernando","Jacinto","Anibal","Antonio","Atalayo",
                           "Bertino","Anastasio","Amor","Arturo","Diego","Mario","Tamaro","Adolfo","Alfonso","Pedro","Alfredo",
                           "Rolando","Mauro","Amancio","Benicio","Bertin","Ildefonso","Amilcar","Cuchuflito","Jazmino",
                           "Remilgo"};
    strcpy(name,names[rand()%(sizeof(names)/30)]);
}

void getLastName(char lastName[]){
    char lastNames[][30]={"Fernandez","Gomez","Vlick","Argento","Molina","Gomez","Perez","Rodriguez","Latorre","Fernandez","Torquemada", "Marijuan", "Roca", "Mitre", "Rivadavia",
                            "San Martin", "Alvarez", "Comizo", "Borges", "Zama", "Recato", "Olvido", "Gil", "Trapero", "Restinga",
                            "De Antonio", "Ramirez", "Spinetta", "Cortez", "Gonzalez", "Andujar", "San Juan", "Bautista", "Anchorena", "Paso",
                            "Gaboto","Vega","Vargas","Lloret","Linares","Suarez","Sierra","Amenabar","Blanco","White","Black"};
    strcpy(lastName, lastNames[rand()%(sizeof(lastNames)/30)]);
}

char* getNamePro(){
    char* name = (char*) malloc(sizeof(char)*30);
    char names[][30]={"Juan","Apolonio","Tulio","Maria","Violeta","Amalio","Juan","Roberto","Antonio","Pedro","Fernando","Jacinto","Anibal","Antonio","Atalayo",
                           "Bertino","Anastasio","Amor","Arturo","Diego","Mario","Tamaro","Adolfo","Alfonso","Pedro","Alfredo",
                           "Rolando","Mauro","Amancio","Benicio","Bertin","Ildefonso","Amilcar","Cuchuflito","Jazmino",
                           "Remilgo"};
    strcpy(name,names[rand()%(sizeof(names)/30)]);
    return name;
}

stAlumno getAlumnoRandom(){
    stAlumno a;
    a.legajo = getFileNumber();
    a.diaNac = getDay();
    a.mesNac = getMonth();
    a.anioNac = getYear();
    getName(a.nombre);
    strcpy(a.nombre,getNamePro());
    getLastName(a.apellido);

    return a;
}
