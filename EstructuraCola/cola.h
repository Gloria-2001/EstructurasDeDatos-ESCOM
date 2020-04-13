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
    int queue[maxCola];         // Cola de un tama�o de 10 elementos
    int pri;                    // Indice del primer dato de la cola
    int ult;                    // Indice del ultimo dato de la cola
    int elemCola;               // Numero de elementos insertados en la cola 
}Cola;

void iniciarQueue(Cola *queue){ // Funcion para incializar la cola. 
	int i;
    queue->elemCola=0;          // El numero de elementos ingresados hasta ahora en la cola es 0. 
    queue->pri=0;               // El indice del primer dato de la cola estara inicializado en 0. 
    queue->ult=0;               // El indice del ultimo dato de la cola estara inicializado en 0. 
    for(i=0;i<maxCola;i++)  // Mientras el indice de los elementos se mantenga entre el 0 y el maximo que admite (10) y aumente uno por uno,
        queue->queue[i]=-1;     // la cola se va a inicializar en -1. 
}

int estaVacia(Cola *queue){     // Funcion para verificar si la cola esta vacia. 
    if(queue->elemCola==0)      // Si el numero de elementos ingresados es 0,
        return 1;               // entonces se cumple.
    else                        // De lo contrario,
        return 0;               // no es verdadero, no se cumple. 
}

int estaLlena(Cola *queue){     // Funcion para verificar cola esta llena. 
    if(queue->elemCola==maxCola)// Si el numero de elementos ingresados es igual a lo maximo que admite la cola,
        return 1;               // entonces se cumple esta funcion. 
    else                        // De lo contrario, 
        return 0;               // no es verdadero, no se cumple. 
}

void enQueue(Cola *queue, int dato){  // Funcion para meter datos en la cola. 
    if(estaLlena(queue)){             // Si se cumple la funcion estaLlena, 
        printf("\nPila llena\n");     // se imprimirá que la pila esta llena. 
    }else if(estaVacia(queue)){       // De lo contrario y si se cumple la funcion estaVacia, 
        queue->queue[0]=dato;         // el elemento cero del arreglo va a ser el dato. 
        queue->elemCola++;            // Despues, el numero de elementos ingresados va a aumentar de uno, 
    }else{                            // De no cumplirse los if anteriores (si la cola no esta vacia ni llena),  
        queue->queue[queue->elemCola]=dato; // se va a agregar un elemento y ese sera el nuevo dato; 
        queue->ult++;                       // el indice del ultimo elemento va a aumentar de uno, conforme se metan los datos. 
        queue->elemCola++;                  // Tambien el numero de elementos ingresados aumentara.
    }
}

void deQueue(Cola *queue){      // Funcion para sacar datos de la Cola. 
    int aux,i;                  // Se declaran 2 variables enteras, una auxiliar. 
    if(estaVacia(queue)){       // Si se cumple la funcion estaVacia, 
        printf("\nPila vacia"); // entonces se va a imprimir que la Cola esta vacia. 
    }else{                      // De lo contrario,
        printf("Elemento eliminado: %2d",queue->queue[queue->pri]); // Se va a imprimir, el elemento eliminado es x, y va a ser primer elemento metido.
        for(i=0;i<queue->elemCola-1;i++)         // Para cuando los elementos de la Cola se mantengan en 0 y se haya retirado el elemento mencionado anteriormente, 
            queue->queue[i]=queue->queue[i+1];   // El apuntador de la cola ahora se va a dirigir al otro elemento para sacarlo.
        queue->elemCola--;      // Los elementos ingresados disminuiran en uno. 
        queue->ult--;           // Tambien el que esta catalogado como ultimo elemento va a irse recorriendo. 
    }
}

void barrelQueue(Cola *queue){      // Funcion para recorrer datos en la Cola. 
	int i;
    if(estaVacia(queue))            // Si se cumple la funcion estaVacia, 
        printf("\nPila vacia");     // entonces se imprime que Pila vacia. 
    else                            // De lo contrario, 
        for(i=0;i<queue->elemCola;i++)      // Para los elementos insertados en la cola, aumentando uno por uno, 
            printf("%3d ",queue->queue[i]);     // van a imprimirse con un espacio  de 3 numeros. 
}
