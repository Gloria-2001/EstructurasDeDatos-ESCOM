#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Dato{
	char nombre[30];
	int edad;
	float estatura;
	char sexo;
};

struct nodo{
	struct Dato *dato;
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

struct nodo *CrearNodo(struct nodo *dato){
	struct nodo *ptrNuevo;
	ptrNuevo=(struct nodo*)malloc(sizeof(struct nodo));
	ptrNuevo->dato=(struct Dato*)malloc(sizeof(struct Dato));  
	strcpy(ptrNuevo->dato->nombre,dato->nombre);
	ptrNuevo->dato->edad=dato->edad;
	ptrNuevo->dato->estatura=dato->estatura;
	ptrNuevo->dato->sexo=dato->sexo;
}

void meter(struct nodo *ptrCima, struct dato *dato){
	struct nodo *ptrN;
	ptrN=CrearNodo(dato);
	if(ptrCima->ptrSig==NULL) 
		ptrCima->ptrSig=nuevo;
	else{
		nuevo->ptrSig=ptrCima->ptrSig; 
		ptrCima->ptrSig=nuevo;
	}
}

struct Dato *sacar(struct nodo *ptrCima,struct Dato *dato){ 
	struct nodo *temp=ptrCima->ptrSig;
	dato=temp->dato; 
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
		printf("Pila Vacía\n");
	else{
		while(temp->ptrSig!=NULL){
			temp=temp->ptrSig;
			printf("Nombre:%s\n",temp->dato->nombre);
			printf("Edad:%d\n",temp->dato->edad);
			printf("Estatura:%f\n",temp->dato->estatura);
			printf("Sexo:%c\n",temp->dato->sexo);
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



int main(){
	struct Dato *MiPtrDato=(struct Dato*)malloc(sizeof(struct Dato));
	struct Dato *MiPtrCima=(struct nodo*)malloc(sizeof(struct nodo));
	MiPtrCima->ptrSig=NULL;
	while(1){
		switch(menu()){
			//meter pila//
			case 1:{
				
				printf("Nombre:");
				fflush(stdin);
				gets(MiPtrDato->nombre);
				printf("Edad:");
				scanf("%d",&MiPtrDato->edad);
				printf("Estatura:");
				scanf("%f",&MiPtrDato->estatura);
				printf("Sexo:");
				fflush(stdin);
				scanf("%c",&MiPtrDato->sexo);
				meter(MiPtrCima,MiPtrDato);
				break;
			}
			//sacar de la pila// 
			case 2:{
				if(MiPtrCima->ptrSig==NULL) //basada en esta idea para el punto 3//
					printf("Pila Vacia\n");
				else{
					MiPtrDato=sacar(MiPtrCima,MiPtrDato);
					printf("Salio:\n");
					printf("Nombre:%s\n",MiPtrDato->nombre);
					printf("Edad:%d\n",MiPtrDato->edad);
					printf("Estatura:%f\n",MiPtrDato->estatura);
					printf("Sexo:%c\n",MiPtrDato->sexo);
				}
				break;
			}
			//recorrer pila//
			case 3:
				recorrer(MiPtrCima);
				break;
			case 4:
				exit(0);
		}
	}
}
