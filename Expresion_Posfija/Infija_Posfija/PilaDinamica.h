#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct simbolo{
    char operador;  // Operador de la expresion
    int prioridad;  // Prioridad del operador
};

struct nodo{
    struct simbolo *simb;
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

void iniciarPila(struct nodo *ptrCima){
    ptrCima->ptrSig=NULL;
}

struct nodo *CrearNodo(struct simbolo *s){
	struct nodo *ptrNuevo;
	ptrNuevo=(struct nodo*)malloc(sizeof(struct nodo));
    ptrNuevo->simb=(struct simbolo*)malloc(sizeof(struct simbolo));
    ptrNuevo->simb->operador=s->operador;
    ptrNuevo->simb->prioridad=s->prioridad;
    ptrNuevo->ptrSig=NULL;
}

void meter(struct nodo *ptrCima,struct simbolo *dato){
	struct nodo *nuevo;
	nuevo=CrearNodo(dato);
	if(ptrCima->ptrSig==NULL) 
		ptrCima->ptrSig=nuevo;
	else{
		nuevo->ptrSig=ptrCima->ptrSig;
		ptrCima->ptrSig=nuevo;
	}
}

struct simbolo *sacar(struct nodo *ptrCima){ 
	struct nodo *temp=ptrCima->ptrSig;
	struct simbolo *datoOut=temp->simb;
	if(ptrCima->ptrSig->ptrSig==NULL){
		free(temp);
		ptrCima->ptrSig=NULL;
	}
	else{
		ptrCima->ptrSig=temp->ptrSig;
		free(temp);
	}
	return datoOut;//regresa el dato
}

void recorrer(struct nodo *ptrCima){
	struct nodo *temp;
	temp=ptrCima;
    while(temp->ptrSig!=NULL){
        temp=temp->ptrSig;
        printf("%c",temp->simb->operador);
    }
}

int Pila_Vacia(struct nodo *ptrCima){
	if(ptrCima->ptrSig==NULL)
		return 1;
	else 
		return 0;
}