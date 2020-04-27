#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct nodo{
	int simbolo;
	struct nodo *ptrSig;
};

int menu(){
	int a;
	printf("MENU\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Recorrer\n");
	printf("4. Exit\n");
	printf("Elija una opcion:\n");
	scanf("%d",&a);
	system("cls");
	return a;
}

struct nodo *CrearNodo(int simbolo){
	struct nodo *ptrNuevo;
	ptrNuevo=(struct nodo*)malloc(sizeof(struct nodo));
	ptrNuevo->simbolo=simbolo;
    ptrNuevo->ptrSig=NULL;
}

void meter(struct nodo *ptrCima, int dato){
	struct nodo *nuevo;
	nuevo=CrearNodo(dato);
	if(ptrCima->ptrSig==NULL) 
		ptrCima->ptrSig=nuevo;
	else{
		nuevo->ptrSig=ptrCima->ptrSig; 
		ptrCima->ptrSig=nuevo;
	}
}

int sacar(struct nodo *ptrCima){ 
	struct nodo *temp=ptrCima->ptrSig;
	int dato=temp->simbolo; 
	if(ptrCima->ptrSig->ptrSig==NULL){
		free(temp);
		ptrCima->ptrSig=NULL;
	}
	else{
		ptrCima->ptrSig=temp->ptrSig;
		free(temp);
	}
	return dato;//regresa el dato
}

void recorrer(struct nodo *ptrCima){
	struct nodo *temp;
	temp=ptrCima;
	if(ptrCima->ptrSig==NULL)
		printf("Pila Vacia\n");
	else{
		while(temp->ptrSig!=NULL){
			temp=temp->ptrSig;
			printf("%d",temp->simbolo);
		}
	}
}

int Pila_Vacia(struct nodo *ptrCima){
	if(ptrCima->ptrSig==NULL)
		return 1;
	else 
		return 0;
}

int Pila_Vacia(struct nodo *ptrCima){
	if(ptrCima->ptrSig!=NULL)
		return 1;
	else 
		return 0;
}