#include "PilaDinamica.h"
#define SUMA '+'
#define RESTA '-'
#define MULT '*'
#define DIV '/'
#define POT '^'

int isNumber(char c){
	if((c>=48 && c<=57) || c==46)
		return 1;
	else 
		return 0;
}

int obtenPrioridad(char operador){
	switch(operador){
		case SUMA: case RESTA:
			return 1;
		break;
		case MULT: case DIV:
			return 2;
		break;
		case POT:
			return 3;
		break; 
	}
}

int main(){
    struct nodo *pila00=(struct nodo*)malloc(sizeof(struct nodo));    // Guardará los operadores
    struct simbolo *simbEnt=(struct simbolo*)malloc(sizeof(struct simbolo));
	struct simbolo *aux=(struct simbolo*)malloc(sizeof(struct simbolo));
    char expresion[100];
	char operador;
    int i, j;
	

    iniciarPila(pila00);
    
    printf("Ingrese la expresion infija: ");
    gets(expresion);

    for(i=0;expresion[i]!='\0';i++){
		
	}

	free(pila00);	
	free(aux);
	free(simbEnt);

	return 0;
}