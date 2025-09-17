#include <stdio.h>
#include <stdlib.h>

/* Realiza tu propia función LONGITUD, que devuelva el número de caracteres de una cadena */

int calcLongitud(char c[100]){
	int i, temp = 0;
	
	printf("Dame la cadena\n----> ");
	scanf("%s", c);
	
	for(i=0; c[i] != '\0'; i++){
		temp++;
	}
	
	return temp;
}

int main() {
	char c[100];
	int longitud;
	
	longitud = calcLongitud(c);
	
	printf("%d", longitud);
	
	return 0;
}
