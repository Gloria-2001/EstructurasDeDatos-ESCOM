#include "PilaDinamica.h"
#define SUMA '+'
#define RESTA '-'
#define MULT '*'
#define DIV '/'
#define POT '^'
#define PARENT_IN '('
#define PARENT_OUT ')'

int obtenPrioridad(char operador);

int main(){
    struct nodo *pila00=(struct nodo*)malloc(sizeof(struct nodo));    // Guardará los operadores
    struct simbolo *simbEnt=(struct simbolo*)malloc(sizeof(struct simbolo));
    char expresion[100];
    int i;

    iniciarPila(pila00);
    
    printf("Ingrese la expresion infija: ");
    gets(expresion);

    for(i=0;expresion[i]!='\0';i++){
        switch(expresion[i]){
            case PARENT_IN:
                simbEnt->operador=expresion[i];
                simbEnt->prioridad=0;
                meter(pila00,simbEnt);
            break;
            default:
                printf("%c",expresion[i]);
            break;
        }
    }
}