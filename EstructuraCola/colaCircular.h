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
	int elemCola;
}Cola;

void iniciarCola(Cola *queue){
	int i;
    queue->elemCola=0;          
    queue->pri=0;               
    queue->ult=0;                
    for(i=0;i<MaxCola;i++)  
        queue->queue[i]=0;
}

int ColaVacia(Cola *queue){
	if(queue->elemCola==0)
		return 1;
	else 
		return 0; 
}

int ColaLlena(Cola *queue){
	if(queue->elemCola==MaxCola)
		return 1;
	else 
		return 0;
}

void meterCola(Cola *queue, int dato){   
    int i;
	if(ColaLlena(queue)){              
        printf("\nPila llena\n");      
    }else if(ColaVacia(queue)){        
        queue->queue[0]=dato; 
    }else{                              
		queue->queue[queue->elemCola]=dato;
		queue->queue[i]=((queue->ult)+1)%6;
    }
}

void recorrer(Cola *queue){      
	int i;
    if(ColaVacia(queue))             
        printf("\nPila vacia");     
    else                            
		for(i=0;i<MaxCola;i++){
			printf("%d",queue->queue[i]);
		}
	}
 
void sacarCola(Cola *queue){
	int aux,i;                   
    if(ColaVacia(queue)){        
        printf("\nPila vacia");  
    }else{                      
        printf("Elemento eliminado: %d",queue->pri); 
        queue->queue[i]=queue->queue[i+1];
		queue->queue[i]=((queue->pri)+1)%6;
    }
}












