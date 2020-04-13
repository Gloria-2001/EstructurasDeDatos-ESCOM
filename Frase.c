#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct nodo{
	char dato;
	struct nodo *ptrSig;
};

struct nodo *Crear_nodo(char caracter){
	struct nodo *ptrNuevo=(struct nodo*)malloc(sizeof(struct nodo));
	/*
		Completar el código de nuevo nodo
	*/
	return ptrNuevo;
}

void meter(struct nodo *ptrCima,char caracter){	// Se recibe un caracter, no tiene sentido ingresar una frase
	struct nodo *nuevo=Crear_nodo(caracter);
	if(ptrCima->ptrSig==NULL) 
		ptrCima->ptrSig=nuevo;
	else{
		nuevo->ptrSig=ptrCima->ptrSig; 
		ptrCima->ptrSig=nuevo;
	}
}

char sacar(struct nodo *ptrCima){		// Solamente se recibe el apuntador como parámetro
	struct nodo *temp=ptrCima->ptrSig;
	char caracter=temp->dato; 
	if(ptrCima->ptrSig->ptrSig==NULL){
		free(temp);
		ptrCima->ptrSig=NULL;
	}
	else{
		ptrCima->ptrSig=temp->ptrSig;
		free(temp);
	}
	return caracter;
}

int main(){
	char *frase;	// Variable donde guardará la frase
	struct nodo *MiPtrCima=(struct nodo*)malloc(sizeof(struct nodo));
	MiPtrCima->ptrSig=NULL;
	
	printf("Este programa sirve para verificar si una frase es o no palindroma.\nIngrese frase sin espacios y todo en minusculas:\n");
	fflush(stdin);
	gets(frase);

	/*
		Como el nodo solo guarda caracter por caracter (Ese era el secreto o el punto importante)
		Debe recorrer la cadena paso a paso para guardarla en la pila, estoy quiere decir que si mi frase es:
			asdfghj
		Lo que hermos es guardar carcater por caracter esta frase y se vería así:
			jhgfdsa
		Para despues comparar si ambas son iguales.
	*/

	meter(MiPtrCima,);
	

	/*
		Solo se usa un apuntador a la pila, es decir, que solo existe una pila
		No es necesario un apuntador a la frase, se puede almacenar normal
	*/
	
	if(MiPtrFrase!=sacar(MiPtrCima,MiPtrFrase)){	// Esto puede ir de otra forma, corregir.
		printf("No es una frase palindroma\n");
	}
		
	else 
		printf("La frase es palindroma\n");
}

