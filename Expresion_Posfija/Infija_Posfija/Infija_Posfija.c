#include "PilaDinamica.h"
#define SUMA '+'
#define RESTA '-'
#define MULT '*'
#define DIV '/'
#define POT '^'
#define PARENT_IN '('
#define PARENT_OUT ')'

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

char cadenaAux[20];
float arregloFlotante[2];

int main(){
    struct nodo *pila00=(struct nodo*)malloc(sizeof(struct nodo));    // Guardará los operadores
    struct simbolo *simbEnt=(struct simbolo*)malloc(sizeof(struct simbolo));
	struct simbolo *aux=(struct simbolo*)malloc(sizeof(struct simbolo));
    char expresion[100];
	char operador;
    int i, j;
	
	arregloFlotante[0]=0.0;
	arregloFlotante[1]=0.0;

    iniciarPila(pila00);
    
    printf("Ingrese la expresion infija: ");
    gets(expresion);

	j=0;	// Indice de nuestra cadena auxiliar
    for(i=0;expresion[i]!='\0';i++){
		
	}

	if(pila00->ptrSig!=NULL)
		recorrer(pila00);

	free(pila00);	
	free(aux);
	free(simbEnt);

	return 0;
}