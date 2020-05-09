#include<stdio.h>
#include<string.h>

int contarVocales(char *expresion){
	int i,vocal=0,A=0,E=0,I=0,O=0,U=0;
	for(i=0;expresion[i]!='\0';i++){
		char a=expresion[i];
		if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u'){
			vocal++;
			if(a=='a'){
				A++;
			}
			if(a=='e'){
				E++;
			}
			if(a=='i'){
				I++;
			}
			if(a=='o'){
				O++;
			}
			if(a=='u'){
				U++;
			}		
		}
	}
	printf(" a's=%d\n e's=%d\n i's=%d\n o's=%d\n u's=%d\n",A,E,I,O,U);
	return vocal;
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
	
	printf("Fin del programa\n");
	return 0;
}