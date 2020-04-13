#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Frase{
	char frase[50];
};

struct nodo{
	struct Frase *frase1;
	struct nodo *ptrSig;
};

struct nodo *Crear_nodo(struct Frase *frase1){
	struct nodo *ptrNuevo=(struct nodo*)malloc(sizeof(struct nodo));
	ptrNuevo->frase1=(struct Frase*)malloc(sizeof(struct Frase));  
	strcpy(ptrNuevo->frase1->frase,frase1->frase);
	ptrNuevo->ptrSig=NULL;
	return ptrNuevo;
}

void meter(struct nodo *ptrCima,struct Frase *frase1){
	struct nodo *nuevo=Crear_nodo(frase1);
	if(ptrCima->ptrSig==NULL) 
		ptrCima->ptrSig=nuevo;
	else{
		nuevo->ptrSig=ptrCima->ptrSig; 
		ptrCima->ptrSig=nuevo;
	}
}

struct Frase *sacar(struct nodo *ptrCima, struct Frase *frase1){
	struct nodo *temp=ptrCima->ptrSig;
	frase1=temp->frase1; 
	if(ptrCima->ptrSig->ptrSig==NULL){
		free(temp);
		ptrCima->ptrSig=NULL;
	}
	else{
		ptrCima->ptrSig=temp->ptrSig;
		free(temp);
	}
	return frase1;
}

int main(){
	struct Frase *MiPtrFrase=(struct Frase*)malloc(sizeof(struct Frase));
	struct nodo *MiPtrCima=(struct nodo*)malloc(sizeof(struct nodo));
	MiPtrCima->ptrSig=NULL;
	
	printf("Este programa sirve para verificar si una frase es o no palindroma.\nIngrese frase sin espacios y todo en minusculas:\n");
	fflush(stdin);
	gets(MiPtrFrase->frase);	
	meter(MiPtrCima,MiPtrFrase);
	
	if(MiPtrFrase!=sacar(MiPtrCima,MiPtrFrase)){
		printf("No es una frase palindroma\n");
	}
		
	else 
		printf("La frase es palindroma\n");
}

