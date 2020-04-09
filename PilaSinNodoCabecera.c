/*
    Gloria Oliva Olivares Ménez.
	1CM6.
	Estructuras de Datos. 
	Pila Dinámica sin nodo de cabecera.
	Función Pila Llena. 
*/

#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int dato;
    struct nodo *ptrsig;
};

int menu(){
    int opcion;
    printf("\n\tMenu\n");
    printf("1. Meter en la pila\n");
    printf("2. Sacar de la pila\n");
    printf("3. Visualizar contenido de la pila\n");
    printf("4. Verificar pila llena\n");
    printf("5. Verificar pila vacia\n");
    printf("6. Salir\n");
    printf("Elija una opcion: ");
    scanf("%d",&opcion);
    system("cls");
    return opcion;
}

struct nodo *crearNodo(int datoEnt){
    struct nodo *ptrN=(struct nodo *)malloc(sizeof(struct nodo));
    ptrN->dato=datoEnt;
    ptrN->ptrsig=NULL;
    return(ptrN);
};

void meterPila(struct nodo **ptrCima2, int datoEnt){
    struct nodo *ptrNuevo=crearNodo(datoEnt);
    if(*ptrCima2==NULL)
        (*ptrCima2)=ptrNuevo;
    else{
        ptrNuevo->ptrsig=(*ptrCima2);
        (*ptrCima2)=ptrNuevo;
    }
}

int sacarDePila(struct nodo **ptrCima2){
    struct nodo *ptrBasura=*ptrCima2;
    int datoSal=ptrBasura->dato;
	*ptrCima2=ptrBasura->ptrsig;
    free(ptrBasura);
    return datoSal;
}

void recorrerPila(struct nodo **ptrCima2){
    struct nodo *ptrRec=*ptrCima2;
    while(ptrRec!=NULL){
        printf("El dato es %d\n",ptrRec->dato);
        ptrRec=ptrRec->ptrsig;
    }
}

int pilaVacia(struct nodo **ptrCima2){
	if((*ptrCima2)==NULL)
		return 1;
	else 
		return 0;     
}

int pilaLlena(struct nodo **ptrCima2){
	if((*ptrCima2)!=NULL)
        return 1;
	else 
		return 0;   
}

int main(){
    struct nodo *miPtrCima1;
    struct nodo **miPtrCima2;
    
	miPtrCima1=NULL;
    miPtrCima2=&miPtrCima1;
    int datoEnt=0,est=0;
    
    do{
    	switch (menu()){
            case 1:
                printf("Ingrese dato:\n ");
                scanf("%d",&datoEnt);
                meterPila(miPtrCima2,datoEnt);
            break;
            case 2:
            	if(pilaVacia(miPtrCima2))
            		printf("Pila vacia");
            	else 
            		printf("El dato es %d\n",sacarDePila(miPtrCima2));
            break;
            case 3:
                recorrerPila(miPtrCima2);
            break;
            case 4:
            	if(pilaLlena(miPtrCima2))
            		printf("La pila esta llena\n");
            break;
            case 5:
            	if(pilaVacia(miPtrCima2))
            		printf("La pila esta vacia\n");	
            break;
            case 6:
            	est=1;
            break;
            default:
            	printf("Elija una opcion\n");
            break;
        }
    }while(est==0);
}
