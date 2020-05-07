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

void ExpresionPostfija(char expresion){
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
				if(Pila_Vacia(pila00)==1){
					meter(pila00,simbEnt);
				}else{
					while(Pila_Vacia(pila00)==0){
						if(Pila_Vacia(pila00)==1 || simbEnt->prioridad > pila00->ptrSig->simb->prioridad){
							meter(pila00,simbEnt);
							break;
						}else{
							aux=sacar(pila00);
							if(aux->prioridad==simbEnt->prioridad){
								printf("%c",aux->operador);
								meter(pila00,simbEnt);
								break;
							}else if(pila00->ptrSig==NULL){
								meter(pila00,simbEnt);
								break;
							}else if(aux->operador!=PARENT_IN){
								printf("%c",aux->operador);
							}
						}
					}
				}
			break;	
            default:
                printf("%c",expresion[i]);
            break;
        }
}


int main(){
    struct nodo *pila00=(struct nodo*)malloc(sizeof(struct nodo));    // Guardará los operadores
    struct simbolo *simbEnt=(struct simbolo*)malloc(sizeof(struct simbolo));
	struct simbolo *aux=(struct simbolo*)malloc(sizeof(struct simbolo));
    char expresion[100];
	char operador;
    int i;

    iniciarPila(pila00);
    
    printf("Ingrese la expresion infija: ");
    gets(expresion);

    for(i=0;expresion[i]!='\0';i++){
        switch(expresion[i]){

    }

	if(pila00->ptrSig!=NULL)
		recorrer(pila00);

	free(pila00);	
	free(aux);
	free(simbEnt);

	return 0;
}