//Gloria Oliva Olivares Ménez.
//Estructuras de Datos.
//1CM6.
//Lista, parte 1.

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
	if(list->pri==NULL && list->ult == NULL)	
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

int buscarDato(Lista *list){
	int datoBuscado;
	Nodo *auxNodo=list->pri;
	printf("Introduzca el dato que quiere buscar\n");
	scanf("%d",&datoBuscado);
	while(auxNodo!=NULL){
		if(datoBuscado == auxNodo->dato){
			return 1;
			continue;
		}
		auxNodo=auxNodo->ptrSig;
	}
}

int sacarDato(Lista *list){
	Nodo *auxNodo=list->pri;
	int datoBuscado,dato1;
	printf("El dato a sacar es:");
	scanf("%d",&datoBuscado);
	if(list->pri->dato == datoBuscado)
		auxNodo=auxNodo->ptrSig;
	while(auxNodo->ptrSig!=NULL){
		if(datoBuscado==auxNodo->ptrSig->dato){
			auxNodo=list->pri;
			auxNodo->ptrSig=auxNodo->ptrSig->ptrSig;
			dato1=auxNodo->dato;
		}
		auxNodo=auxNodo->ptrSig;
		
	}
	return dato1;
}

int menu(){
	int opc;
	printf("1. Meter\n");
	printf("2. Recorrer\n");
	printf("3. Buscar\n");
	printf("4. Sacar\n");
	printf("5. Salir\n");
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
				if(buscarDato(list00))
					printf("El dato si se encuentra\n");
				else
					printf("Error. El dato no esta en la lista\n");
				break;
			case 4:
				printf("El dato sacado es: %d\n",sacarDato(list00));
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("\nOpcion no existente, intente de nuevo.\n");
				break;
		}
	}
}