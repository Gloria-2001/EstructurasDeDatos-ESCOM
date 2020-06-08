#include<stdio.h>
#include<stdlib.h>

struct nodo{
	int contenido;
	int altura;       
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

int altura(struct nodo *ptr){
	if(ptr==NULL)
		return 0;
	else
		return(ptr->altura);
}

struct nodo *maximo(int altura1, int altura2){
	return(altura1 > altura2 ? altura1 : altura2);
}

void calculaAltura(struct nodo *p){
	p->altura=1+maximo(altura(p->ptrIzq),altura(p->ptrDer));
}

struct nodo *rota_izquierda(struct nodo *ptr){
	struct nodo *temp;
	temp=ptr->ptrDer;
	ptr->ptrDer=temp->ptrIzq;
	temp->ptrIzq=ptr;
	calculaAltura(ptr);
	calculaAltura(temp);
	return temp;
}

struct nodo *rota_derecha(struct nodo *ptr){
	struct nodo *temp;
	temp=ptr->ptrIzq;
	ptr->ptrIzq=temp->ptrDer;
	temp->ptrDer=ptr;
	calculaAltura(ptr);
	calculaAltura(temp);
	return temp;
}

struct nodo *balancear(struct nodo *ptr){
	calculaAltura(ptr);
	if(altura(ptr->ptrIzq)-altura(ptr->ptrDer)==2){
		printf("Se rota\n");
		if(altura(ptr->ptrIzq->ptrDer) > altura(ptr->ptrIzq->ptrIzq))
			ptr->ptrIzq=rota_izquierda(ptr->ptrIzq);
		return rota_derecha(ptr);
	}else if(altura(ptr->ptrDer)-altura(ptr->ptrIzq)==2){
		printf("Se rota\n");
		if(altura(ptr->ptrDer->ptrIzq) > altura(ptr->ptrDer->ptrDer))
			ptr->ptrDer=rota_derecha(ptr->ptrDer);
		return rota_izquierda(ptr);
	}
	printf("%d\n",ptr->altura)
}

void insertarNodo(struct nodo *ptrRaiz,int datoEnt){
	if(ptrRaiz==NULL){
		return crearNodo(datoEnt);
	}else if(datoEnt < ptrRaiz->contenido){
		ptrRaiz->ptrIzq=insertarNodo(ptrRaiz->ptrIzq,datoEnt);
	}else if(datoEnt > ptrRaiz->contenido)
		ptrRaiz->ptrDer=insertarNodo(ptrRaiz->ptrDer,datoEnt);
	else{
		ptrRaiz->contenido=datoEnt;
		return balancear(ptrRaiz);
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