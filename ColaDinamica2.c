//Gloria Oliva Olivares Ménez
//Estructuras de Datos
//Cola Dinámica
//1CM6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dato{
	char nombre[30];
	int edad;
	float est;
	char sexo;
};

struct nodo{        
    struct dato *Dato;                 
    struct nodo *sig;       
};                      

struct Cola{    
    struct nodo *pri;          
    struct nodo *ult;          
};                  

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

struct nodo *CrearNodo(struct dato *Dato1){
	struct nodo *ptrnuevo;
	ptrnuevo=(struct nodo*)malloc(sizeof(struct nodo));
	strcpy(ptrnuevo->Dato->nombre,Dato1->nombre);
	ptrnuevo->Dato->edad=Dato1->edad;
	ptrnuevo->Dato->est=Dato1->est;
	ptrnuevo->Dato->sexo=Dato1->sexo;
	ptrnuevo->sig=NULL;
	return ptrnuevo;
}


void iniciarCola(struct Cola *queue){
	queue->pri=NULL;                         
    queue->ult=NULL; 
}
         
int estaVacia(struct Cola *queue){
	if(queue->pri==NULL && queue->ult==NULL)
        return 1;
    else
        return 0;
}             
     
void meterDato(struct Cola *queue, struct dato *datoIn){
	struct nodo *nuevo=CrearNodo(datoIn);
    if(estaVacia(queue)){
        queue->pri=nuevo;
        queue->ult=nuevo;
    }else{
        queue->ult->sig=nuevo;
        queue->ult=nuevo;
    }
}
    
struct dato *sacarDato(struct Cola *queue,struct dato *datoOut){
	struct nodo *temp=queue->pri;
	datoOut=temp->Dato;
	temp=temp->sig;
    return datoOut;   
}            
void recorrerCola(struct Cola *queue){
	struct nodo *temp=queue->pri;
    do{
        printf("%s es el nombre.\n",temp->Dato->nombre);
		printf("%d es la edad\n",temp->Dato->edad);
		printf("%f es la estatura\n",temp->Dato->est);
		printf("%c es el sexo\n",temp->Dato->sexo);
		temp=temp->sig;
    }while(temp!=NULL);    
}         
             
int main(){
    int datoIn;                
	                    
    struct Cola *cola00=(struct Cola*)malloc(sizeof(struct Cola));
	struct dato *midato=(struct dato*)malloc(sizeof(struct dato)); 	
    iniciarCola(cola00);

    while(1){
        printf("\nCola dinamica, elija una opcion:");
        switch(menu()){
            case 1:
                printf("Nombre:");
				fflush(stdin);
				gets(midato->nombre);
				printf("Edad:");
				scanf("%d",&midato->edad);
				printf("Estatura:");
				scanf("%f",&midato->est);
				printf("Sexo:");
				fflush(stdin);
				scanf("%c",&midato->sexo);
				meterDato(cola00,midato);
				break;
            break;
            case 2:
                printf("\n2. Sacar dato\n");
                if(estaVacia(cola00))
                    printf("Cola vacia\n");
                else
                    midato=sacarDato(cola00,midato);
					printf("Salio:\n");
					printf("Nombre:%s\n",midato->nombre);
					printf("Edad:%d\n",midato->edad);
					printf("Estatura:%f\n",midato->est);
					printf("Sexo:%c\n",midato->sexo);
            break;
            case 3:
                printf("\n3. Recorrer cola\nImpresion de datos (del primero al ultimo):\n\t");
                if(estaVacia(cola00))
                    printf("Cola vacia\n");
                else
                    recorrerCola(cola00);
                printf("\n");
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