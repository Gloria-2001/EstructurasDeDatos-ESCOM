#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct simbolo{
    char operador;  // Operador de la expresion
    int prioridad;  // Prioridad del operador
};

struct nodo{
	struct nodo *ptrAnt;
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
    ptrCima->ptrAnt=NULL;
    ptrCima->ptrSig=NULL;
}

struct nodo *CrearNodo(struct simbolo *s){
	struct nodo *ptrNuevo;
	ptrNuevo=(struct nodo*)malloc(sizeof(struct nodo));
    ptrNuevo->simb=(struct simbolo*)malloc(sizeof(struct simbolo));
    ptrNuevo->simb->operador=s->operador;
    ptrNuevo->simb->prioridad=s->prioridad;
    ptrNuevo->ptrSig=NULL;
    ptrNuevo->ptrAnt=NULL;
}

void meter(struct nodo *ptrCima,struct simbolo *dato){
	struct nodo *nuevo;
	nuevo=CrearNodo(dato);
	if(ptrCima->ptrSig==NULL) 
		ptrCima->ptrSig=nuevo;
	else{
		nuevo->ptrSig=ptrCima->ptrSig;
        ptrCima->ptrSig->ptrAnt=nuevo; 
		ptrCima->ptrSig=nuevo;
	}
}

struct simbolo *sacar(struct nodo *ptrCima){ 
	struct nodo *temp=ptrCima->ptrSig;
	struct simbolo *datoOut=temp->simb;
	if(ptrCima->ptrSig->ptrSig==NULL){
		free(temp);
		ptrCima->ptrSig=NULL;
        ptrCima->ptrAnt=NULL;
	}
	else{
		ptrCima->ptrSig=temp->ptrSig;
        ptrCima->ptrSig->ptrAnt=NULL;
		free(temp);
	}
	return datoOut;//regresa el dato
}

void recorrer(struct nodo *ptrCima){
	struct nodo *temp;
	temp=ptrCima;
	if(ptrCima->ptrSig==NULL)
		printf("Pila Vacia\n");
	else{
		while(temp->ptrSig!=NULL){
			temp=temp->ptrSig;
			printf("%c-%d ",temp->simb->operador,temp->simb->prioridad);
		}
	}
}

int Pila_Vacia(struct nodo *ptrCima){
	if(ptrCima->ptrSig==NULL)
		return 1;
	else 
		return 0;
}