#include<stdio.h>
#include<stdlib.h>

struct nodo{
	int contenido;
	struct nodo *ptrIzq;
	struct nodo *ptrDer;
};

struct nodo *crearNodo(int datoEnt){
	struct nodo *ptrNuevo=(struct nodo*)malloc(sizeof(struct nodo));
	ptrNuevo->contenido=datoEnt;
	ptrNuevo->ptrIzq=NULL;
	ptrNuevo->ptrDer=NULL;
	return ptrNuevo;
}

void insertarNodo(struct nodo **ptrRaiz,int datoEnt){
	if(*ptrRaiz==NULL){
		*ptrRaiz=crearNodo(datoEnt);
	}else if(((*ptrRaiz)->contenido)>datoEnt){
		insertarNodo(&((*ptrRaiz)->ptrIzq),datoEnt);
	}else{
		insertarNodo(&((*ptrRaiz)->ptrDer),datoEnt);
	}
}

void imprimirPreorden(struct nodo *ptrRaiz){
	if(ptrRaiz!=NULL){
		printf("Dato: %d\n",ptrRaiz->contenido);
		imprimirPreorden(ptrRaiz->ptrIzq);
		imprimirPreorden(ptrRaiz->ptrDer);
	}
}

void imprimirInorden(struct nodo *ptrRaiz){
	if(ptrRaiz!=NULL){
		imprimirInorden(ptrRaiz->ptrIzq);
		printf("Dato: %d\n",ptrRaiz->contenido);
		imprimirInorden(ptrRaiz->ptrDer);
	}
}

void imprimirPostorden(struct nodo *ptrRaiz){
	if(ptrRaiz!=NULL){
		imprimirPostorden(ptrRaiz->ptrIzq);
		imprimirPostorden(ptrRaiz->ptrDer);
		printf("Dato: %d\n",ptrRaiz->contenido);
	}
}

int menu(){
	int opc;
	printf("Ingrese opcion\n");
	printf("1.- Meter datos\n");
	printf("2.- Imprimir datos en preorden\n");
	printf("3.- Imprimir datos en inorden\n");
	printf("4.- Imprimir datos en postorden\n");
	printf("5.- Salir\n");
	scanf("%d",&opc);
	return opc;
}
int main(){
	struct nodo *ptrRaizBase=NULL,**ptrRaiz;
	int datoEnt;
	ptrRaiz=&ptrRaizBase;
	while(1){
		switch(menu()){
			case 1:
				printf("Ingrese el dato:\n");
				scanf("%d",&datoEnt);
				insertarNodo(ptrRaiz,datoEnt);
			break;
			case 2:
				imprimirPreorden(*ptrRaiz);
			break;
			case 3:
				imprimirInorden(*ptrRaiz);
			break;
			case 4:
				imprimirPostorden(*ptrRaiz);
			break;
			case 5:
				exit(0);
			break;
		}
	}
}