#include "PilaDinamica.h"
#define SUMA '+'
#define RESTA '-'
#define MULT '*'
#define DIV '/'
#define POT '^'
#define PARENT_IN '('
#define PARENT_OUT ')'

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
    char expresion[100];
	char operador;
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
			case PARENT_OUT:
				while(Pila_Vacia(pila00)==0){
					simbEnt=sacar(pila00);
					if(simbEnt->operador!=PARENT_IN)
						printf("%c",simbEnt->operador);
					else 
						break; 
				}
			break; 
			case SUMA: case RESTA: case MULT: case DIV: case POT:
				simbEnt->operador=expresion[i];
				simbEnt->prioridad=obtenPrioridad(expresion[i]);
			break;	
            default:
                printf("%c",expresion[i]);
            break;
        }
    }
}