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
    pila00->ptrSig=NULL;
    char expresion[100];
}