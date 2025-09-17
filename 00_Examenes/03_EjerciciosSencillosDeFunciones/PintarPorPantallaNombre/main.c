#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Procedimiento que pinte por pantalla un nombre pasado por parámetro seguido de la expresión “buen amigo, mejor persona */

void pedirNombre(char nombre[10]){
	
	printf("Dame el nombre\n-----> ");
	scanf("%s", nombre);
}

void imprimirExpresion(char nombre[10]){
	printf("%s buen amigo, mejor persona.", nombre);
}
int main() {
	char nombre[10]; 
	
	pedirNombre(nombre);
	imprimirExpresion(nombre);
	
	return 0;
}
