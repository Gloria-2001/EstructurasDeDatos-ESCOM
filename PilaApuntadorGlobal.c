/*
    Gloria Oliva Olivares Ménez.
    1CM6.
    Estructuras de Datos. 
    Pila dinámica con apuntador global en la cima simple y con enlace sencillo. 
*/

#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int dato;
    struct nodo *ptrSig;
};

struct nodo *ptrCima1=NULL;
struct nodo **ptrCima2=&ptrCima1;
int dato=0;

int menu(){
    int opcion;
    printf("\n\tMenu\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Recorrer\n");
    printf("4. Salir\n");
    printf("Elija una opcion: ");
    scanf("%d",&opcion);
    system("cls");
    return opcion;
}

void meter(){
    struct nodo *nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->ptrSig=NULL;
    nuevo->dato=dato;
    if(ptrCima1==NULL)
        (ptrCima1)=nuevo;
    else{
        nuevo->ptrSig=(ptrCima1);
        (ptrCima1)=nuevo;
    }
}

int sacar(){
    struct nodo *temp=ptrCima1;
    dato=(ptrCima1)->dato;
    if(temp->ptrSig==NULL){
		free(temp);
		ptrCima1=NULL;
	}
   else{
 		ptrCima1=temp->ptrSig;
    	free(temp);
    }
    return dato;
}

void recorrer (){
    struct nodo *temp=ptrCima1;
    if(temp==NULL)
        printf("PILA VACIA\n");
    else{
        printf("%d", temp->dato);
        while(temp->ptrSig !=NULL){
            temp=temp->ptrSig;
	    	printf("%d", temp->dato);
         }
    }
}

int main(){
    while(1){
    	switch (menu()){
           	//METER
			case 1:{
                printf("Dato:\n ");
                scanf("%d",&dato);
 		    	meter();
            break;
            }
		    //SACAR
            case 2:{
    			if(ptrCima1==NULL)
            		printf("La pila esta vacia");
            	else 
                	printf("El dato es %d\n",sacar());
            break;
			}
			//RECORRER
            case 3:{
                recorrer();
            break;
			}
            case 4:{
              exit(0);
			break;
			}
    	}
	}
}

