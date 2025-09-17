#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/* Función que devuelva true o false, dependiendo de si el parámetro que le has pasado es una vocal o no lo es */

bool comprobar(char c){
	printf("Dame el caracter\n----> ");
	scanf("%c", &c);
	
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
		return true;
	} else {
		return false;
	}
	
}

int main() {
	char c;
	bool esVocal;
	
	esVocal = comprobar(c);
	
	if(esVocal == true){
		printf("El caracter es una vocal");
	} else {
		printf("El caracter NO es una vocal");
	}
	return 0;
}
