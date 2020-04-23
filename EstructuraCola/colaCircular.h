#include<stdio.h>
#include<stdlib.h>
#define MaxCola 6

int menu(){
	int opcion;
	printf("1. Meter Dato\n");
	printf("2. Sacar Dato\n");
	printf("3. Recorrer Cola\n");
	printf("4. Salir\n");
	scanf("%d",&opcion);
	return opcion;	
}

typedef struct{
	int queue[MaxCola];
	int pri;
	int ult;
	int datosIngresados;
}Cola;

void iniciarCola(Cola *queue){
	int i;
    queue->datosIngresados=0;          
    queue->pri=0;               
    queue->ult=0;                
    for(i=0;i<MaxCola;i++)  
        queue->queue[i]=0;
}

int ColaVacia(Cola *queue){
	if(queue->datosIngresados==0)
		return 1;
	else 
		return 0; 
}

int ColaLlena(Cola *queue){
	if(queue->datosIngresados==MaxCola)
		return 1;
	else 
		return 0;
}

void meterCola(Cola *queue, int dato){   
    int i;
	if(ColaLlena(queue)){              
        printf("\nCola llena\n");      
    }else if(ColaVacia(queue)){        
        queue->queue[0]=dato; 
		queue->datosIngresados++;
    }else{
		/*
			Error:
			i=((queue->datosIngresados)+(queue->datosIngresados))%MaxCola;

			Corrección:
			Te dije que era pri+datos, además, estaba en la imagen y el video que te pasé
			Ponte más abusada, el video te estaba dando todo el algoritmo
		*/
		i=((queue->pri)+(queue->datosIngresados))%MaxCola;
		queue->queue[i]=dato;
		queue->datosIngresados++;
    }
}

void recorrer(Cola *queue){      
	int i;
    if(ColaVacia(queue))             
        printf("\nCola vacia");     
    else                            
		for(i=0;i<(queue->datosIngresados);i++){
			/*
				Error:
				printf("%d\t",queue[(i+(queue->pri))%(queue->datosIngresados)]);

				Correccion:
				Recuerda que el valor en el que nos basamos es el tamaño de la cola,
				por lo que el modulo debe de ser con respecto al MaxCola.
				Ademas, no estabas dirigiendote al arreglo, solo decías que
				el apuntador en una posición[j] tenía algo y lo debía imprimir
			*/
			printf("%d\t",queue->queue[i+((queue->pri))%(MaxCola)]);
		}
	}
 
int sacarCola(Cola *queue){                  
    int dato;
	if(ColaVacia(queue)){        
        printf("\nCola vacia");  
    }else{                      
        dato=queue->queue[queue->pri];
		queue->queue[queue->pri]=-1; 
		queue->pri=((queue->pri)+1)%MaxCola; 
		queue->datosIngresados--;
	}
	return dato;
}