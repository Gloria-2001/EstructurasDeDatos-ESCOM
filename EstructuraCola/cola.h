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

void iniciarQueue(Cola *queue){ // Función para incializar la cola. 
    queue->elemCola=0;          // El número de elementos ingresados hasta ahora en la cola es 0. 
    queue->pri=0;               // El índice del primer dato de la cola estará inicializado en 0. 
    queue->ult=0;               // El índice del último dato de la cola estará inicializado en 0. 
    for(int i=0;i<maxCola;i++)  // 
        queue->queue[i]=-1;     //
}

int estaVacia(Cola *queue){     // Función para verificar si la cola está vacía. 
    if(queue->elemCola==0)      // Si el número de elementos ingresados es 0,
        return 1;               // entonces se cumple.
    else                        // De lo contrario,
        return 0;               // no es verdadero, no se cumple. 
}

int estaLlena(Cola *queue){     // Función para verificar cola está llena. 
    if(queue->elemCola==maxCola)// Si el número de elementos ingresados es igual a lo máximo que admite la cola,
        return 1;               // entonces se cumple esta función. 
    else                        // De lo contrario, 
        return 0;               // no es verdadero, no se cumple. 
}

void enQueue(Cola *queue, int dato){  // Función para meter datos en la cola. 
    if(estaLlena(queue)){             // Si se cumple la función estaLlena, 
        printf("\nPila llena\n");     // se imprimirá que la pila está llena. 
    }else if(estaVacia(queue)){       // De lo contrario y si se cumple la función estaVacia, 
        queue->queue[0]=dato;         // el elemento cero del arreglo va a ser el dato. 
        queue->elemCola++;            // Después, el número de elementos ingresados va a aumentar de uno por uno, 
    }else{                            // De no cumplirse los if anteriores (si la cola no está vacía ni llena),  
        queue->queue[queue->elemCola]=dato; // se va a agregar un elemento y ese será el nuevo dato; 
        queue->ult++;                       // el índice del último elemento va a aumentar de uno por uno, conforme se metan los datos. 
        queue->elemCola++;                  // También el número de elementos ingresados aumentará. 
    }
}

void deQueue(Cola *queue){      // Función para sacar datos de la Cola. 
    int aux,i;                  // Se declaran 2 variables enteras, una auxiliar. 
    if(estaVacia(queue)){       // Si se cumple la función estaVacia, 
        printf("\nPila vacia"); // entonces se va a imprimir que la Cola está vacía. 
    }else{                      // De lo contrario,
        printf("Elemento eliminado: %2d",queue->queue[queue->pri]); // Se va a imprimir, el elemento eliminado es x, y va a ser primer elemento metido.
        for(i=0;i<queue->elemCola-1;i++)         // 
            queue->queue[i]=queue->queue[i+1];   //
        queue->elemCola--;      // Los elementos ingresados disminuirán uno por uno. 
        queue->ult--;           // También el que esté catalogado como último elemento va a irse recorriendo. 
    }
}

void barrelQueue(Cola *queue){      // Función para recorrer datos en la Cola. 
    if(estaVacia(queue))            // Si se cumple la función estaVacia, 
        printf("\nPila vacia");     // entonces se imprime que Pila vacia. 
    else                            // De lo contrario, 
        for(int i=0;i<queue->elemCola;i++)      // 
            printf("%3d ",queue->queue[i]);     //
}
