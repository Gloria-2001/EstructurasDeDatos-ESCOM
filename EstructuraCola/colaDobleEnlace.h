#include <stdio.h>
#include <stdlib.h>

/*
    Cola dinámica. 
    Una cola es una estructura de dato que tiene como característica que
    el primer elemento en entrar es el primero en salir (FIFO - First In, First Out).
    
        Cola                    nodo
    -------------       --------------------
    | pri | ult |       | ant | elem | sig |
    -------------       --------------------

    Aquí se definen las estrucutras a utilizar al igual que la declaración
    de sus funciones para manipular la cola dinámica
*/

typedef struct Dato{    // Estructura del dato a guardar en el nodo
    char simbolo;
}Dato;

typedef struct Nodo{        // Estrucutra nodo
    struct Nodo *ant;       // Apuntador al nodo anterior
    Dato elem;              // Dato principal
    struct Nodo *sig;       // Apuntador al nodo siguiente
}Nodo;                      // Nombre de la estructura

typedef struct Cola{    // Estructura Cola
    Nodo *pri;          // Primero de la cola
    Nodo *ult;          // Ultimo en la cola
}Cola;                  // Nombre de la estrucutra

void iniciarCola(Cola *q);          // Iniciar cola
void destruirCola(Cola *q);         // Eliminar cola
int estaVacia(Cola *q);             // Devuelve 1 si la pila está vacia y 0 de caso contrario
Nodo *CrearNodo(Dato d);            // Crear nodo nuevo con un dato
void meterDato(Cola *q, Dato d);    // Ingresar datos la cola
Dato sacarDato(Cola *q);            // Sacar dato de la cola
void recorrerCola(Cola *q);         // Muestra los datos en la cola sin sacarlos
int menu();                         // Opciones de la colasss