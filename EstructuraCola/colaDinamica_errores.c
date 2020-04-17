/*
    Cola dinámica. 
    Una cola es una estructura de dato que tiene como característica que
    el primer elemento en entrar es el primero en salir (FIFO - First In, First Out).
    Hay varios errores, arreglarlo.
    TIP. Lea los comentarios como guía de como debe estar implementada la función
    (comprensión lectora).
    Una vez hecho eso, agregar la función sacar,
    recuerde que el primero en entrar es el primero en salir, por eso es que
    ptrCola tiene dos apuntadores al tipo nodo, que son pri y ult, para que sea
    más sencillo identificar cuales son los datos que deben salir.
    La estructura nodo tiene un apuntador a un tipo de estructura nodo y un entero que es el
    dato a almacenar en la fila
    
       ptrCola               nodo
    -------------       --------------
    | pri | ult |       | dato | sig |
    -------------       --------------

    Recuerde que para la función sacar es importare saber como actuan los apuntadores.
	Finalmente, actualizar el repositorio
*/

#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int dato;               // Dato principal
    struct nodo *sig;       // Apuntador al dato siguiente
};

struct ptrCola{
    struct nodo *pri;       // Primero de la cola
    struct nodo *ult;       // Ultimo en la cola
};

struct ptrCola *miPtrCola;      // Apuntador global

struct nodo *CrearNodo(int dato){                           // Crear nodo nuevo con un dato
	struct nodo *ptrnuevo;
	ptrnuevo=(struct nodo*)malloc(sizeof(struct nodo));
    ptrnuevo->sig=NULL;
    ptrnuevo->dato=dato;
    return ptrnuevo; 
}

void meterDato(int dato){                   // Ingresar datoa la cola
    struct nodo *nuevo=CrearNodo(dato);
    if(miPtrCola->pri==NULL && miPtrCola->ult==NULL){   // si el apuntador de el primer y ultimo nodo son vacíos, entonces
        miPtrCola->pri=nuevo;                           // ambos apuntadores se dirigirán para al nuevo elemento
        miPtrCola->ult=nuevo;
    }else{                                              // Si no, vamos a tener que agregar el dato nuevo después del 
        miPtrCola->ult->sig=nuevo;                      // dato existente antes de él, es decir, el ultimo dato 
        miPtrCola->ult=nuevo;                           // para actualizar al nuevo dato y ponerlo como ultimo
    }
}

void recorrerCola(){                        // Recorre la cola 
    struct ptrCola *temp=miPtrCola;         // Auxiliar del apuntador de la cola
    do{                                     // Imprimiremos el dato de cada nodo que
        printf("%3d ",temp->pri->dato);     // se encuentra en la cola, y después nos dirigiremos
        temp->pri=temp->pri->sig;           // al siguiente, siempre y cuando el apuntador siguiente
    }while(temp->pri->sig!=NULL);           // del nodo sea diferente del vacío
    printf("%3d\n",temp->pri->dato);        // Para finalmente impriir el ultimo dato
}

void sacarDato(){									//Funcion para sacar dato.
	struct ptrCola *aux=miPtrCola;
	int i;					
	if(miPtrCola->pri && miPtrCola->ult==NULL)
		printf("La pila est� vacia\n");
	else{
		printf("Elemento eliminado:%d\n",aux->pri->dato);
		for(i=0;i<aux->ult;i++){
			aux->pri=aux->pri->sig;
			printf("Elemento eliminado:%d\n",aux->pri->dato);
			aux->pri--;
		}	
	}
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

int main(){
    int datoIn; // Dato de entrada
    miPtrCola=(struct ptrCola*)malloc(sizeof(struct ptrCola));  // Reserva de memoria de la variable global
    miPtrCola->pri=NULL;    // Indica cola vacía
    miPtrCola->ult=NULL;    // Indica cola vacía
    while(1){
		printf("Cola dinamica, elija una opcion:");
        switch(menu())
        {
            case 1:
                printf("\n1. Ingresar dato\nDato: ");
                scanf("%d",&datoIn);
                meterDato(datoIn);
            break;
            case 2:
                printf("\n2. Sacar dato\n");
                sacarDato();
            break;
            case 3:
                printf("\n3. Recorrer cola\nImpresion de datos (del primero al ultimo):\n\t");
                recorrerCola();
            break;        
            case 4:
                exit(0);
            break;
            default:
                printf("\nOpcion no existente, intente de nuevo.\n");
            break;
        }
    }

    return 0;
}
