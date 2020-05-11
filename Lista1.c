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

void iniciarLista(Lista *list){
	list->pri=NULL;
	list->ult=NULL;
} 

int listaVacia(Lista *list){
	if(list->pri==NULL && list->ult == NULL)	// Te falto ponerle el igual igual a NULL en list->pri
		return 1;
	else
		return 0;
}

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
	
	if(listaVacia(list)){
		list->pri=ptrNuevo;
		list->ult=ptrNuevo;
	}else{
		if(list->pri->dato > ptrNuevo->dato){
			ptrNuevo->ptrSig=list->pri;
			list->pri=ptrNuevo;
		} else if(list->ult->dato < ptrNuevo->dato){
			list->ult->ptrSig=ptrNuevo;
			list->ult=ptrNuevo;
		} else{
			while(auxNodo->ptrSig!=NULL){
			if(auxNodo->ptrSig->dato > ptrNuevo->dato){
				ptrNuevo->ptrSig=auxNodo->ptrSig;
				auxNodo->ptrSig=ptrNuevo;	
			}
			auxNodo=auxNodo->ptrSig;
		}
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
	list00->pri=NULL;
	list00->ult=NULL;
	
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
}