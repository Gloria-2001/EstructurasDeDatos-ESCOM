#include <stdio.h>
#include <stdlib.h>

typedef struct Dato{                        // Estructura del dato a guardar en el nodo
    char simbolo;
}Dato;

typedef struct Nodo{                        // Estrucutra nodo
    Dato elem;                              // Dato principal
    struct Nodo *sig;                       // Apuntador al nodo siguiente
}Nodo;                                      // Nombre de la estructura

typedef struct Lista{                       // Estructura Lista
    Nodo *pri;                              // Primero de la lista
    int tamanio;                            // Numero de elementos en la lista
}Lista;                                     // Nombre de la estrucutra

void iniciarLista(Lista *l);                // Iniciar lista
int isEmpty(Lista *l);                      // Si la lista está vacía
Nodo *CrearNodo(Dato d);                    // Crear nodo nuevo con un dato
void Add(Lista *l, Dato d, int indice);     // Agregar a la lista
void RemoveByData(Lista *l, Dato d);        // Elimina un elemento de la lista
Dato RemoveByIndex(Lista *l, int index);       // Elimina un elemento de la lista por su posicion
void Show(Lista *l);                        // Ver lista
void Search(Lista *l, Dato d);              // Busca un elemento
int menu();                                 // Opciones de la lista