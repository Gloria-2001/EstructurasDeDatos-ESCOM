#include<stdio.h>
#include<string.h>

int contarVocales(char *expresion){
	int i,vocal=0;
	for(i=0;expresion[i]!='\0';i++){
		char a=expresion[i];
		if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
			vocal++;
	}
	return vocal;
}

int vocal_A(char *expresion){
	int i,A=0;
	for(i=0;expresion[i]!='\0';i++){
		char a=expresion[i];
		if(a=='a')
			A++;
	}
	return A;
}

int vocal_E(char *expresion){
	int i,E=0;
	for(i=0;expresion[i]!='\0';i++){
		char a=expresion[i];
		if(a=='e')
			E++;
	}
	return E;
}

int vocal_I(char *expresion){
	int i,I=0;
	for(i=0;expresion[i]!='\0';i++){
		char a=expresion[i];
		if(a=='i')
			I++;
	}
	return I;
}

int vocal_O(char *expresion){
	int i,O=0;
	for(i=0;expresion[i]!='\0';i++){
		char a=expresion[i];
		if(a=='o')
			O++;
	}
	return O;
}

int vocal_U(char *expresion){
	int i,U=0;
	for(i=0;expresion[i]!='\0';i++){
		char a=expresion[i];
		if(a=='u')
			U++;
	}
	return U;
}

int main(){
	int numVoc,A=0,E=0,I=0,O=0,U=0;
	char expresion[50];
	printf("En este programa se introducira una frase,\n");
	printf("se mostrara cuantas vocales hay en total, asi como el numero de cada vocal.\n");
	printf("Es decir, el numero de a's, e's, i's, o's y u's.\n");
	printf("Ingrese frase en minusculas\n");
	gets(expresion);
	numVoc=contarVocales(expresion);
	printf("El numero de vocales es %d\n",numVoc);
	A=vocal_A(expresion);
	printf("El numero de a's es %d\n",A);
	E=vocal_E(expresion);
	printf("El numero de e's es %d\n",E);
	I=vocal_I(expresion);
	printf("El numero de i's es %d\n",I);
	O=vocal_O(expresion);
	printf("El numero de o's es %d\n",O);
	U=vocal_U(expresion);
	printf("El numero de u's es %d\n",U);
	printf("Fin del programa\n");
	return 0;
}