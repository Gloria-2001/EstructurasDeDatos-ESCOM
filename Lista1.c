#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo *ptrSig; 
}Nodo;

typedef struct Lista{
	Nodo *pri;
	Nodo *ult;
}Lista; 

Nodo *crearNodo(int dato1){
	Nodo *ptrNuevo;
	ptrNuevo=(Nodo*)malloc(sizeof(Nodo));
	ptrNuevo->dato=dato1;
	ptrNuevo->ptrSig=NULL;
	return ptrNuevo;
}

void meterDatos(Lista *list,int dato1){
	Nodo *ptrNuevo=crearNodo(dato1);
	Nodo *auxNodo=list->pri;
	if(list->pri>ptrNuevo){
		ptrNuevo->ptrSig=list->pri;
		list->pri=ptrNuevo;
	} 
	else if(list->ult<ptrNuevo){
		list->ult->ptrSig=ptrNuevo;
		list->ult=ptrNuevo;
	}
	else{
		while(auxNodo->ptrSig!=NULL){
			if(auxNodo->ptrSig > ptrNuevo){
				ptrNuevo->ptrSig=auxNodo->ptrSig;
				auxNodo->ptrSig=ptrNuevo;
			}
			auxNodo=auxNodo->ptrSig;
		}
	}
}

void recorrer(Lista *list){
	Nodo *auxNodo=list->pri;
	do{
		printf("Dato: %d\n",auxNodo->dato);
		auxNodo=auxNodo->ptrSig;
	}while(auxNodo!=NULL);
}

int menu(){
	int opc;
	printf("1. Meter\n");
	printf("2. Recorrer\n");
	printf("3. Salir\n");
	printf("La opcion elegida fue:");
	scanf("%d",&opc);
	return opc;
}

int main(){
	Lista *list00=(Lista*)malloc(sizeof(Lista));
	int miDato;
	
	while(1){
		printf("Lista. Elija una opcion.\n");
		switch(menu()){
			case 1:
				printf("Ingrese dato:\n");
				scanf("%d",&miDato);
				meterDatos(list00,miDato);
				break;
			case 2:
				recorrer(list00);
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("\nOpcion no existente, intente de nuevo.\n");
				break;
		}
	}
	return 0;
}