/*
    Gloria Oliva Olivares Ménez.
	1CM6.
	Estructuras de Datos. 
	Pilas Encontradas.  
*/

#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int dato;
    struct nodo *sig;
    struct nodo *ant;
};

int menu(){
    int opcion;
    printf("\n\tMENU\n");
    printf("1. Meter por la Izquierda\n");
    printf("2. Meter por la Derecha\n");
    printf("3. Sacar por la Izquierda\n");
    printf("4. Sacar por la Derecha\n");
    printf("5. Verificar Pila Llena\n");
    printf("6. Verificar Pila Vacia\n");
    printf("7. Salir\n");
    printf("Elija una opcion: ");
    scanf("%d",&opcion);
    system("cls");
    return opcion;
}

struct nodo *CrearNodo(int dato1){
	struct nodo *ptrnuevo;
	ptrnuevo=(struct nodo*)malloc(sizeof(struct nodo));
    ptrnuevo->ant=NULL;
    ptrnuevo->sig=NULL;
    ptrnuevo->dato=dato1;
    return ptrnuevo; 
}

void meterPorIzquierda(struct nodo *ptrCimaIzq, struct nodo *ptrCimaDer, int dato){
	struct nodo *nuevo=CrearNodo(dato);
	if(ptrCimaIzq==ptrCimaDer){
		ptrCimaIzq->sig=nuevo;
		nuevo->sig=ptrCimaDer;
		ptrCimaDer->ant=nuevo;
		nuevo->ant=ptrCimaIzq;
	}
	else{
		nuevo->sig=ptrCimaIzq->sig;
		ptrCimaIzq->sig->ant=nuevo;
		nuevo->ant=ptrCimaIzq;
		ptrCimaIzq->sig=nuevo;
	}
}

void meterPorDerecha(struct nodo *ptrCimaDer, struct nodo *ptrCimaIzq,int dato){
	struct nodo *nuevo=CrearNodo(dato);
	if(ptrCimaIzq==ptrCimaDer){
		ptrCimaIzq->sig=nuevo;
		nuevo->sig=ptrCimaDer;
		ptrCimaDer->ant=nuevo;
		nuevo->ant=ptrCimaIzq;
	}
	else{
		nuevo->ant=ptrCimaDer->ant;
		ptrCimaDer->ant->sig=nuevo;
		nuevo->sig=ptrCimaDer;
		ptrCimaDer->ant=nuevo;
	}
}

int sacarPorIzquierda(struct nodo *ptrCimaIzq, int dato){//recorrer ida 
	struct nodo *temp=ptrCimaIzq->sig;
	dato=temp->dato;
	if(ptrCimaIzq->sig->sig==NULL){
		free(temp);
		ptrCimaIzq->sig=NULL;
	}
	else{
		ptrCimaIzq->sig=temp->sig;
		free(temp);
	}
	return dato;
}

int sacarPorDerecha(struct nodo *ptrCimaDer, int dato){//recorrer vuelta 
	struct nodo *temp=ptrCimaDer->ant;
	dato=temp->dato;
	if(ptrCimaDer->ant->ant==NULL){
		free(temp);
		ptrCimaDer->ant=NULL;
	}
	else{
		ptrCimaDer->ant=temp->ant;
		free(temp);
	}
	return dato;
}

void pilaVacia(struct nodo *ptrCimaIzq, struct nodo *ptrCimaDer){
    if(ptrCimaIzq==ptrCimaDer) 
        printf("La pila esta Vacia\n");
}

void pilaLlena(struct nodo *ptrCimaIzq, struct nodo *ptrCimaDer){
	if(ptrCimaIzq!=ptrCimaDer)
        printf("La pila esta Llena\n"); 
}

int main(){
    int dato;
    struct nodo *MiPtrCimaIzq=(struct nodo*)malloc(sizeof(struct nodo));
    struct nodo *MiPtrCimaDer=(struct nodo*)malloc(sizeof(struct nodo));
	MiPtrCimaIzq->sig=NULL;
	MiPtrCimaDer->ant=NULL;
	MiPtrCimaIzq->ant=NULL;
	MiPtrCimaDer->sig=NULL;
    
    while (1){
        switch (menu()){
            // Meter por la Izquierda. 
            case 1:
                printf("\nDato: ");
                scanf("%d",&dato);
                meterPorIzquierda(MiPtrCimaIzq,MiPtrCimaDer,dato);
            break;
            // Meter por la Derecha. 
            case 2:
                printf("\nDato: ");
                scanf("%d",&dato);
                meterPorDerecha(MiPtrCimaDer,MiPtrCimaIzq,dato);
            break;
            // Sacar por la Izquierda.
            case 3:
				if(MiPtrCimaIzq->sig==NULL)
                    printf("\n\tPila vacia\n");
                else
                    printf("\nSe saco el dato: %d\n",sacarPorIzquierda(MiPtrCimaIzq,dato));
            break;
            //Sacar por la Derecha.
            case 4:
            	if(MiPtrCimaDer->ant==NULL)
                    printf("\n\tPila vacia\n");
                else
                    printf("\nSe saco el dato: %d\n",sacarPorDerecha(MiPtrCimaDer,dato));
            break;
            //Pila Llena.
            case 5:
            	pilaLlena(MiPtrCimaIzq,MiPtrCimaDer);
            break;
            //Pila Vacia.
            case 6:
            	pilaVacia(MiPtrCimaIzq,MiPtrCimaDer);
            break;
            case 7:
            	exit(0);
            break;
        }
    }

    return 0;    
}

