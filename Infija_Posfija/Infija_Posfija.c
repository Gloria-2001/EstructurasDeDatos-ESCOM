#include "PilaDinamica.h"
#define SUMA '+'
#define RESTA '-'
#define MULT '*'
#define DIV '/'
#define POT '^'
#define PARENT_IN '('
#define PARENT_OUT ')'


int main(){
    struct nodo *pila00=(struct nodo*)malloc(sizeof(struct nodo));    // Guardará los operadores
    struct simbolo *simbEnt=(struct simbolo*)malloc(sizeof(struct simbolo));
	// simbEnt->simbolo=operador;   // Esto no lo podemos hacer, ni siquiera existe la variable operados, borrarlo
    char expresion[100];
    int i;

    iniciarPila(pila00);
    
    printf("Ingrese la expresion infija: ");
    gets(expresion);

    for(i=0;expresion[i]!='\0';i++){
       switch(expresion[i]){                 // El que nos interesa es el caracter de la cadena
		case PARENT_IN:
            /*
                Igualamos el operador al caracter de entrada, en este caso el parentesis izquierdo,
                ya que estamos dentro de esta opcion 
            */
            simbEnt->operador=expresion[i];
            simbEnt->prioridad=4;
            meter(pila00,simbEnt);
		break;
		   
	   }
    }
}