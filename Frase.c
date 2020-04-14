#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct nodo{
	char dato;
	struct nodo *ptrSig;
};

struct nodo *Crear_nodo(char caracter){
	struct nodo *ptrNuevo=(struct nodo*)malloc(sizeof(struct nodo));
	ptrNuevo->dato=caracter;
    ptrNuevo->ptrSig=NULL;
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

void imprimir(struct nodo *ptrCima){
    struct nodo *ptrMov=ptrCima;
    while(ptrMov!=NULL){
        printf("El dato es %d\n",ptrMov->dato);
        ptrMov=ptrMov->ptrSig;
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
	int a,i;
	int flag=1; 
	struct nodo *MiPtrCima=(struct nodo*)malloc(sizeof(struct nodo));
	MiPtrCima->ptrSig=NULL;
	
	printf("Este programa sirve para verificar si una frase es o no palindroma.\nIngrese frase sin espacios y todo en minusculas:\n");
	gets(frase);
	a=sizeof(frase);
	printf("%c",&frase);
	
	for(i=0;i<a;i++){
		meter(MiPtrCima,frase[i]);
		imprimir(MiPtrCima);	
	}
	
	for(i=0;i<a;i++){
		if(frase[i]!=sacar(MiPtrCima)){
			flag=0;
			printf("No es un palindromo\n");
		}
	}
	
	if(flag==1){
		printf("Es un palindromo\n");
	}		
}

