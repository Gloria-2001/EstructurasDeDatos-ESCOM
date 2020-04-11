#include <stdio.h>
#include <stdlib.h>
#include "cola.h"           // Librería donde se encuentra la cola estática

int main(){
    int datoIn;
    Cola cola00;
    iniciarQueue(&cola00);

    while(1){
        printf("\nCola estatica, elija una opcion:");
        switch(menu()){
            case 1:
                printf("\n1. Ingresar dato\nDato: ");
                scanf("%d",&datoIn);
                enQueue(&cola00,datoIn);
            break;
            case 2:
                printf("\n2. Sacar dato\n");
                deQueue(&cola00);
                printf("\n");
            break;
            case 3:
                printf("\n3. Recorrer cola\nImpresion de datos (del primero al ultimo):\n");
                barrelQueue(&cola00);
                printf("\n");
            break;        
            case 4:
                printf("\nFin del programa\n");
                exit(0);
            break;
            default:
                printf("\nOpcion no existente, intente de nuevo.\n");
            break;
        }
    }

    return 0;
}