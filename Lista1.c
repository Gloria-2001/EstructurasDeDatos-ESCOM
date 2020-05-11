#include <studio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo *ptrSig; 
	int llave;
}Nodo;

typedef struct Lista{
	Nodo *pri;
	Nodo *ult;
}Lista; 

Nodo crearNodo(int dato1){
	Nodo *ptrNuevo;
	ptrNuevo=(Nodo*)malloc(sizeof(Nodo));
	ptrNuevo->ptrSig=NULL;
	ptrNuevo->dato=dato1;
	return dato1;
}

void meterDatos(Lista *list,int dato1){***************
	Nodo *aux=q->ult;
	
	
	
	while(aux->ant!=NULL){
		if(aux->ant->prio>aux->prio){
			aux->ant->sig=aux->sig;
			aux->ant=aux->ant->ant;
			aux->sig=aux->ant->sig;
			aux->sig->ant=aux;
			aux->ant->sig=aux;
			if(aux==q->ult){
				q->ult=aux->sig;
			}else{
				aux->sig->sig->ant=aux->sig;
			}
		}else
			break;
	}
}

void recorrer(){}
