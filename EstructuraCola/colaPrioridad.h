#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Dato{    
    char nombre[30];
	int edad;	
}Dato;

typedef struct Nodo{        
    struct Nodo *ant;                 
    struct Nodo *sig;
	Dato *dato;
	int prio;
}Nodo;                      

typedef struct Cola{    
    Nodo *pri;          
    Nodo *ult;          
}Cola;                  

void iniciarCola(Cola *q){
	q->pri=NULL;                         
    q->ult=NULL;
}
         
void destruirCola(Cola *q){
    free(q);                             
}         

int estaVacia(Cola *q){
	if(q->pri==NULL && q->ult==NULL)
        return 1;
    else
        return 0;
}   
          
Nodo *CrearNodo(Dato *d){
	Nodo *ptrnuevo;
	ptrnuevo=(Nodo*)malloc(sizeof(Nodo));
	ptrnuevo->dato=(Dato*)malloc(sizeof(Dato)); 
    ptrnuevo->sig=NULL;
    ptrnuevo->ant=NULL;
    strcpy(ptrnuevo->dato->nombre,d->nombre);
	ptrnuevo->dato->edad=d->edad;
}
 
void ordenarCola(Cola *q){
	Nodo *aux=q->ult;
	while(aux->ant!=NULL){
		if(aux->ant->prio>aux->prio){
			aux->ant->sig=aux->sig;
			aux->ant=aux->ant->ant;
			aux->sig=aux->ant->sig;
			aux->sig->ant=aux;
			aux->ant->sig=aux;
			if(aux==q->ult){
				q->ult=aux->sig;
			}else{
				aux->sig->sig->ant=aux->sig;
			}
		}else
			break;
	}
}

void insert(Cola *q,Dato *d){
	Nodo *nuevo=CrearNodo(d);
	if(estaVacia(q)){
        q->pri=nuevo;
        q->ult=nuevo;
    }else{
        nuevo->ant=q->ult;
        q->ult->sig=nuevo;
        q->ult=nuevo;
    }
}
 
void meterDato(Cola *q, Dato *d){
	insert(q,d);
	ordenarCola(q);
}
    
Dato *sacarDato(Cola *q, Dato *datoOut){
	Nodo *aux=q->pri;
    datoOut=aux->dato;
    aux=aux->sig;
    return datoOut;
}

void recorrerCola(Cola *q){
	Nodo *temp=q->pri;
    do{
        printf("Nombre:%s\n",temp->dato->nombre);
		printf("Edad:%d\n",temp->dato->edad);
        temp=temp->sig;
    }while(temp!=NULL);
}         
int menu(){
	int opc;
    printf("\n1. Meter dato");
    printf("\n2. Sacar dato");
    printf("\n3. Recorrer cola");
    printf("\n4. Salir");
    printf("\nOpcion: ");
    scanf("%d",&opc);
    return opc;
}                    