#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "colaPrioridad.h"

/*
    Generar un numero aleatorio:
    Primero es necesario importar la libreia time
        #include <time.h>
    Después, a la altura de las declaraciones de variables,
    debemos poner la "semilla" que nos generará sin problemas los
    numeros aleaotrios:
        srand(time(NULL))
    y donde se quiere generar un numero aleatorio, usaremos la siguiente forma
        numero = rand () % (N-M+1) + M;
                    ó
        numero = M + rand () % (N-M+1);
    El cual, el numero aleatorio está entre M y N (N > M), es decir, si quiero un número entre el
    10 y el 100, entonces, quedaría de la siguiente forma:
        numero = rand() % (100-10+1) + 10
    Que tambien quedaría:
        numero = rand() % 91 + 10;
*/
 
int main(){
	Dato *MiDato=(Dato*)malloc(sizeof(Dato));        // Reserva de memoria del Dato de entrada
    Cola *cola00=(Cola*)malloc(sizeof(Cola));        // Reserva de memoria de la variable global
    iniciarCola(cola00);

    while(1){
        printf("\nCola con prioridad, elija una opcion:");
        switch(menu()){
            case 1:
                fflush(stdin);
                printf("\nIngresar nombre\n");
				gets(MiDato->nombre);
				fflush(stdin);
				printf("\nIngresar edad\n");
                scanf("%d",&MiDato->edad);
                meterDato(cola00,MiDato);
            break;
            case 2:
                printf("\n2. Sacar dato\n");
                if(estaVacia(cola00))
                    printf("Cola vacia\n");
                else{
                    MiDato=sacarDato(cola00,MiDato);
					printf("Nombre sacado: %s\n",MiDato->nombre);
					printf("Edad sacada: %d\n",MiDato->edad);
				}
            break;
            case 3:
                printf("\n3. Recorrer cola\nImpresion de datos (del primero al ultimo):\n\t");
                if(estaVacia(cola00))
                    printf("Cola vacia\n");
                else
                    recorrerCola(cola00);
                printf("\n");
            break;        
            case 4:
                destruirCola(cola00);
                exit(0);
            break;
            default:
                printf("\nOpcion no existente, intente de nuevo.\n");
            break;
        }
    }

    return 0;
}