#include <stdio.h>
#include <stdlib.h>

/*
    Cola dinámica. 
    Una cola es una estructura de dato que tiene como característica que
    el primer elemento en entrar es el primero en salir (FIFO - First In, First Out).
    
        Cola                 nodo
    -------------       --------------
    | pri | ult |       | elem | sig |
    -------------       --------------

    Aquí se definen las estrucutras a utilizar al igual que la declaración
    de sus funciones para manipular la cola dinámica
*/

typedef struct dato{    // Estructura del dato a guardar en el nodo
    // Pueden ir más de un tipo de dato
    // por lo que es más abstracta esta estructura
    // es decir, que dato puede tener un char, flotante, etc.
    int dato;
}dato;

typedef struct nodo{        // Estrucutra nodo
    dato d;                 // Dato principal
    struct nodo *sig;       // Apuntador al dato siguiente
}nodo;                      // Nombre de la estructura

typedef struct Cola{    // Estructura Cola
    nodo *pri;          // Primero de la cola
    nodo *ult;          // Ultimo en la cola
}Cola;                  // Nombre de la estrucutra

void iniciarCola(Cola *q);          // Iniciar cola
void destruirCola(Cola *q);         // Eliminar cola
int estaVacia(Cola *q);             // Devuelve 1 si la pila está vacia y 0 de caso contrario
nodo *CrearNodo(dato dato);         // Crear nodo nuevo con un dato
void meterDato(Cola *q, dato d);    // Ingresar datos la cola
dato sacarDato(Cola *q);            // Sacar dato de la cola
void recorrerCola(Cola *q);         // Muestra los datos en la cola sin sacarlos
int menu();                         // Opciones de la cola

/*
    typedef se usa para crear sinónimos, es dcir, que podemos referenciarnos a variables
    o a estructuras con un nombres especial-
    Digamos que quiero "programar" todo en español, por lo que quiero llamar a todas las variables
    en español, es decir, que int no tenga ese nombre, si no, entero. y que float, tenga el nombre
    de flotante, entonces quedaría de la siguiente forma:
        typedef int entero;
        typedef float flotante;
    Entonces, para cuando quiera quiera declarar una variable entera o flotante ya no sería:
        float a;
        int b;
    Sino, de esta forma:
        flotante a;
        entero b;
    Lo mismo es con la estrucutra, que es lo que estamos haciendo, en lugar de poner:
        struct Cola=(struct Cola*)malloc(sizeof(struct Cola))
    Lo cambiariamos po lo siguiente:
        Cola *cola00=(Cola*)malloc(sizeof(Cola));
*/