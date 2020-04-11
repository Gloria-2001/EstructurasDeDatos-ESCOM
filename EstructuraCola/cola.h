#include <stdio.h>
#include <stdlib.h>

#define maxCola 10

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

/*
    Cola estática.
    Una cola es una estructura de dato que tiene como característica que
    el primer elemento en entrar es el primero en salir (FIFO - First In, First Out).
    Esta primera parte, tiene las funciones de meter, sacar y recorrer la cola, solo es cuestión de entender
    el programa, una vez entendida, comentar que hacen las funciones, es decir, si hay un if en la función
    escribir en forma de comentarios que recibe ese if, que condición se debe cumplir y si se cumple o no que
    hace, por ejemplo:
        void numPar(num){                           // Función para saber si un número es par o impar.
            if(num%2)                               // Si el modulo 2 del numero entrante es igual a cero
                printf("Es un numero impar");       // entonces imprimira que el número es impar.
            else                                    // De caso contrario, imprimira que dicho 
                printf("Es un numero par");         // número es par.
        }
    Puede ser así o con un comentario largo antes o dentro de la función a explicar.
*/
typedef struct{
    int queue[maxCola];         // Cola de un tamaño de 10 elementos
    int pri;                    // Indice del primer dato de la cola
    int ult;                    // Indice del último dato de la cola
    int elemCola;               // Número de elementos insertados en la cola 
}Cola;

void iniciarQueue(Cola *queue){
    queue->elemCola=0;
    queue->pri=0;
    queue->ult=0;
    for(int i=0;i<maxCola;i++)
        queue->queue[i]=-1;
}

int estaVacia(Cola *queue){
    if(queue->elemCola==0)
        return 1;
    else
        return 0;
}

int estaLlena(Cola *queue){
    if(queue->elemCola==maxCola)
        return 1;
    else
        return 0;
}

void enQueue(Cola *queue, int dato){
    if(estaLlena(queue)){
        printf("\nPila llena\n");
    }else if(estaVacia(queue)){
        queue->queue[0]=dato;
        queue->elemCola++;
    }else{
        queue->queue[queue->elemCola]=dato;
        queue->ult++;
        queue->elemCola++;
    }
}

void deQueue(Cola *queue){
    int aux,i;
    if(estaVacia(queue)){
        printf("\nPila vacia");
    }else{
        printf("Elemento eliminado: %2d",queue->queue[queue->pri]);
        for(i=0;i<queue->elemCola-1;i++)
            queue->queue[i]=queue->queue[i+1];
        queue->elemCola--;
        queue->ult--;
    }
}

void barrelQueue(Cola *queue){
    if(estaVacia(queue))
        printf("\nPila vacia");
    else
        for(int i=0;i<queue->elemCola;i++)
            printf("%3d ",queue->queue[i]);
}