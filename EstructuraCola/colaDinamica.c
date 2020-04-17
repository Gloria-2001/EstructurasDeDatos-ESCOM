#include <stdio.h>
#include <stdlib.h>
#include "colaDinamica.h"

void iniciarCola(Cola *q){
    q->pri=NULL;                         // Indica cola vacía
    q->ult=NULL;                         // Indica cola vacía
}

void destruirCola(Cola *q){
    free(q);                             // Libera memoria
}

int estaVacia(Cola *q){
    if(q->pri==NULL && q->ult==NULL)
        return 1;
    else
        return 0;
}

nodo *CrearNodo(dato d){
	nodo *ptrnuevo;
	ptrnuevo=(nodo*)malloc(sizeof(nodo));
    ptrnuevo->sig=NULL;
    ptrnuevo->d=d;
    return ptrnuevo; 
}

void meterDato(Cola *q, dato d){
    nodo *nuevo=CrearNodo(d);
    if(estaVacia(q)){
        q->pri=nuevo;
        q->ult=nuevo;
    }else{
        q->ult->sig=nuevo;
        q->ult=nuevo;
    }
}

dato sacarDato(Cola *q){
    dato datoOut;
    datoOut=q->pri->d;
    q->pri=q->pri->sig;
    return datoOut;
}

void recorrerCola(Cola *q){
    nodo *temp=q->pri;
    do{
        printf("%3d ",temp->d.dato);
        temp=temp->sig;
    }while(temp!=NULL);
}

int menu(){
    int opc;
    printf("\n1. Meter dato");
    printf("\n2. Sacar dato");
    printf("\n3. Recorrer cola");
    printf("\n4. Salir");
    printf("\nOpcion: ");
    scanf("%d",&opc);
    return opc;
}

int main(){
    dato datoIn;                                    // Dato de entrada
    Cola *cola00=(Cola*)malloc(sizeof(Cola));       // Reserva de memoria de la variable global
    iniciarCola(cola00);

    while(1){
        printf("\nCola dinamica, elija una opcion:");
        switch(menu()){
            case 1:
                printf("\n1. Ingresar dato\nDato: ");
                scanf("%d",&datoIn.dato);
                meterDato(cola00,datoIn);
            break;
            case 2:
                printf("\n2. Sacar dato\n");
                if(estaVacia(cola00))
                    printf("Cola vacia\n");
                else
                    printf("Dato sacado: %3d\n",sacarDato(cola00).dato);
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