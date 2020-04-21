#include <stdio.h>
#include <stdlib.h>
#include "colaCircular.h"           

int main(){
    int dato;
    Cola cola00;
    iniciarCola(&cola00);

    while(1){
        printf("\nCola circular, elija una opcion:\n");
        switch(menu()){
            case 1:
                printf("\n1. Ingresar dato\nDato: ");
                scanf("%d",&dato);
                meterCola(&cola00,dato);
            break;
            case 2:
                printf("\n2. Sacar dato\n");
                sacarCola(&cola00);
                printf("\n");
            break;
            case 3:
                printf("\n3. Recorrer cola\nImpresion de datos (del primero al ultimo):\n");
                recorrer(&cola00);
                printf("\n");
            break;        
            case 4:
                printf("\nFin del programa\n");
                exit(0);
            break;
            default:
                printf("\nOpcion invalida. Por favor coloque una valida.\n");
            break;
        }
    }

    return 0;
}