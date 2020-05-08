#include "PilaDinamica.h"
#include <math.h>
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

double hacerOperacion(double a, double b, char operador){
	switch(operador){
		case SUMA: 
			return a+b;
		case RESTA:
			return a-b;
		break;
		case MULT: 
			return a*b;
		case DIV:
			return a/b;
		break;
		case POT:
			return pow(a,b);
		break; 
	}
}

char cadenaAux[10];

void limpiarCadAux(){
	int i;
	for(i=0;i<10;i++)
		cadenaAux[i]='0';
}

int main(){
    struct nodo *pila00=(struct nodo*)malloc(sizeof(struct nodo));    // Guardará los operadores
    struct simbolo *simbEnt=(struct simbolo*)malloc(sizeof(struct simbolo));
	struct simbolo *aux=(struct simbolo*)malloc(sizeof(struct simbolo));
    char expresion[100];
	char operador;
	double a,b;
    int i,j,tam;
	
    iniciarPila(pila00);
	limpiarCadAux();	// Se llena de ceros el caracter auxiliar

	printf("\tRPN\nForma de uso:\n");
	printf("Este programa solo recibe numeros flotantes, por lo que la expresion debe escribirse \n");
	printf("con puntos decimales y seguido de espacios, ejemplo:\n");
	printf("\t 20.22 4.0 * 3.141516 +\n\n");
    
    printf("Ingrese la expresion RPN: ");
    gets(expresion);
	
	for(i=0;expresion[i]!='\0';i++)	// Contador de caracteres en la cadena

	tam=i+1;	// Numero de caracteres contados mas uno

	j=0;		// Indice de la cadena auxilar
    for(i=0;i<tam;i++){
		if(isNumber(expresion[i])){		// Si es un numero, se guarda en la cadena auxiliar el caracter
			cadenaAux[j]=expresion[i];	// y aumenta en uno el incide de la cadena auxiliar
			j++;
		}else if(expresion[i]==32){				// Si el caracter es un espacio (32 ASCII), entonces convertiremos
			simbEnt->operando=atof(cadenaAux);	// la cadena auxiliar en un número double (flotante)
			limpiarCadAux();					// Llenamos de ceros la cadena auxiliar
			// printf("Entra a la pila %f\n",simbEnt->operando);
			meter(pila00,simbEnt);				// Metenos a la pila el número dobule
			j=0;								// El indice de cadena auxiliar lo regresamos a cero
		}else{									// Si el caracter es un operador
			if(numElementos(pila00)>=2){		// Si es un numero mayor o igual a dos
				// Hacer operacion
				b=sacar(pila00)->operando;		// Se sacan los dos primeros elementos de la pila
				a=sacar(pila00)->operando;
				// printf("Salen de la pila %f y %f\n",a,b);
				simbEnt->operando=hacerOperacion(a,b,expresion[i]);	// Se hace la operacion con los datos sacados
				// printf("Entra a la pila %f\n",simbEnt->operando);
				meter(pila00,simbEnt);			// El resultado se mete a la pila
				i++;							// Se incrementa el indice en uno
			}else{								// Si no hay mas de dos elementos en la pila, error.
				printf("Error, no hay más de dos numeros en la pila\n");
				exit(0);
			}
		}
	}

	printf("\nResultado de la expresion: %f\n",sacar(pila00)->operando);	// Se saca el elemento de la pila y se imprime el resultado
	printf("\nPrograma terminado\n");
		
	free(pila00);	
	free(aux);
	free(simbEnt);

	return 0;
}