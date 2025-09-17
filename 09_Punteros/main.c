#include <stdio.h>
#include <stdlib.h>

/* Intercambiar el valor de los variables mediante funciones con punteros */

void intercambiar(int *a, int *b){
	int aux;
	
	aux = *a;
	*a = *b;
	*b = aux;
}

int main() {
	int a = 3, b = 5;
	
	printf("%d | %d\n", a, b); 
	intercambiar(&a, &b);
	printf("%d | %d", a, b); 
	return 0;
}
