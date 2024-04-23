#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "gotoxy.h"

int main()
{
    char opcion;
    int x = 2;
    int y = 25;
    int i = 0;
    char c = 178;

    char msg[]="ESC para salir - F1 a F5 para cambiar color - flechas para moverse";
    char despedida[]="Gracias por usar nuestro sistema...";

    color(6);
    gotoxy(x, y);
    printf("%s",msg);
    x=0;
    y=0;
    gotoxy(x,y);

    do{
        opcion = getch();

        switch(opcion){
            case 27:
                while(!kbhit()){
                    gotoxy(rand()%50,rand()%25);
                    color(i);
                    printf("%s",despedida);
                    Sleep(500);
                    i++;
                }
                break;
            case 59:
                color(33);
                break;
            case 60:
                color(45);
                break;
            case 61:
                color(78);
                break;
            case 62:
                color(15);
                break;
            case 63:
                color(133);
                break;

            case 64:
                while(!kbhit()){
                    Beep((rand()%800)+200,(rand()%300)+200);
                }

            case 72: /// arriba
                if(y>0){
                    y--;
                    gotoxy(x,y);
                    printf("%c", c);
                }else{
                    Beep(550,550);
                }

                break;

            case 75: /// izq
                if(x>0){
                    x--;
                    gotoxy(x,y);
                    printf("%c", c);
                }else{
                    Beep(550,550);
                }
                break;

            case 77: /// der
                if(x<80){
                    x++;
                    gotoxy(x,y);
                    printf("%c", c);
                }else{
                    Beep(550,550);
                }
                break;

            case 80: /// abajo
                if(y<24){
                    y++;
                    gotoxy(x,y);
                    printf("%c", c);
                }else{
                    Beep(550,550);
                }

                break;
        }

    }while(opcion!=27);

    return 0;
}
