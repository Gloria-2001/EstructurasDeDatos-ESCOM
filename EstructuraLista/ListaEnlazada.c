#include "ListaEnlazada.h"

void iniciarLista(Lista *l){
    l->pri=NULL;
    l->tamanio=0;
}

int isEmpty(Lista *l){
    if(l->pri==NULL)
        return 1;
    else
        return 0;
}

Nodo *CrearNodo(Dato d){
    Nodo *nueNodo;
    nueNodo=(Nodo *)malloc(sizeof(Nodo));
    nueNodo->elem=d;
    nueNodo->sig=NULL;
    return nueNodo;
}

void Add(Lista *l, Dato d, int indice){
    Nodo *nuevo=CrearNodo(d);
    Nodo *aux;
    int i;
    if(isEmpty(l))
        l->pri=nuevo;
    else{
        if(indice==0){
            nuevo->sig=l->pri;
            l->pri=nuevo;
        }else if(indice>l->tamanio){
            aux=l->pri;
            while(aux->sig!=NULL){
                aux=aux->sig;
            }
            aux->sig=nuevo;
        }else{
            aux=l->pri;
            i=1;
            do{
                if(i==indice){
                    nuevo->sig=aux->sig;
                    aux->sig=nuevo;
                    break;
                }
                aux=aux->sig;
                i++;
            }while(aux!=NULL);
        }
    }
    l->tamanio++;
}

void RemoveByData(Lista *l, Dato d){
    Nodo *aux00=l->pri,*aux01=l->pri;
    int noEsta=1;
    if(aux00->elem.simbolo==d.simbolo){
        l->pri=aux00->sig;
        noEsta=0;
    }else{
        do{
            if(aux00->sig->elem.simbolo==d.simbolo){
                aux00=aux00->sig;
                aux01->sig=aux00->sig;
                noEsta=0;
                break;
            }
            aux00=aux00->sig;
            aux01=aux01->sig;
        }while(aux00->sig!=NULL);
    }
    if(noEsta)
        printf("\nDato \'%c\' no encontrado\n",d.simbolo);
    else{
        free(aux00);
        printf("\nDato sacado\n");
    }
}

Dato RemoveByIndex(Lista *l, int index){
    Nodo *aux00=l->pri,*aux01=l->pri;
    Dato rdato=l->pri->elem;
    int i=0, noEsta=1;
    if(index==0){
        l->pri=aux00->sig;
        noEsta=0;
    }else{
        do{
            if(i+1==index){
                aux00=aux00->sig;
                rdato=aux00->elem;
                aux01->sig=aux00->sig;
                noEsta=0;
                break;
            }
            aux00=aux00->sig;
            aux01=aux01->sig;
            i++;
        }while(aux00->sig!=NULL);
    }
    if(noEsta)
        printf("\nDato no encontrado\n");
    else
        free(aux00);

    return rdato;
}

void Show(Lista *l){
    Nodo *aux=l->pri;
    printf("\t[");
    do{
        printf("%c->",aux->elem.simbolo);
        aux=aux->sig;
    }while(aux!=NULL);
    printf("]\n");
}

void Search(Lista *l, Dato d){
    Nodo *aux=l->pri;
    int i=0;
    do{
        if(aux->elem.simbolo==d.simbolo){
            printf("Dato \'%c\' encontrado, posicion %2d",d.simbolo,i);
            i=0;
            break;
        }
        aux=aux->sig;
        i++;
    }while(aux!=NULL);
    if(i==l->tamanio)
        printf("\nDato \'%c\' no encontrado\n",d.simbolo);
}

int menu(){
    int opc;
    printf("\nEstructura Lista Enlazada");
    printf("\n1. Meter dato");
    printf("\n2. Sacar elemento por dato");
    printf("\n3. Sacar elemento por posicion");
    printf("\n4. Mostrar Lista");
    printf("\n5. Buscar dato");
    printf("\n6. Salir");
    printf("\nOpcion: ");
    scanf("%d",&opc);
    return opc;
}

int main(){
    int indice;
    Dato datoIn;                                    // Dato de entrada
    Lista *lista00=(Lista*)malloc(sizeof(Lista));       // Reserva de memoria de la variable global
    iniciarLista(lista00);
    while(1){
        switch(menu()){
            case 1:
                fflush(stdin);
                printf("\n1. Ingresar dato\nDato: ");
                scanf("%c",&datoIn.simbolo);
                fflush(stdin);
                if(isEmpty(lista00))
                    Add(lista00,datoIn,0);
                else{
                    printf("Indice: ");
                    scanf("%d",&indice);
                    Add(lista00,datoIn,indice);
                }
            break;
            case 2:
                fflush(stdin);
                printf("\n2. Sacar elemento por dato\n");
                if(isEmpty(lista00))
                    printf("Pila vacia\n");
                else{
                    printf("Dato a sacar: ");
                    scanf("%c",&datoIn.simbolo);
                    RemoveByData(lista00,datoIn);
                }
            break;
            case 3:
                fflush(stdin);
                printf("\n3. Sacar elemento por posicion\n");
                if(isEmpty(lista00))
                    printf("Pila vacia\n");
                else{
                    printf("Indice a sacar: ");
                    scanf("%d",&indice);
                    if(indice>=lista00->tamanio)
                        printf("\nIndice no existente\n");
                    else
                        printf("Dato sacado: %c\n",RemoveByIndex(lista00,indice).simbolo);
                }
            break;
            case 4:
                printf("\n3. Mostrar Lista:\n");
                if(isEmpty(lista00))
                    printf("Pila vacia\n");
                else
                    Show(lista00);
            break;
            case 5:
                fflush(stdin);
                printf("Buscando dato: ");
                scanf("%c",&datoIn.simbolo);
                Search(lista00,datoIn);
            break;
            case 6:
                printf("\nFin del programa\n");
                exit(0);
            break;
            default:
                printf("\nOpcion no existente, intente de nuevo\n");
            break;
        }
    }
    return 0;
}