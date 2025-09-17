#include <stdio.h>
#include <stdlib.h>

/* Función que devuelva el triple de un número */

int AdquirirNumero(int numero){	
	printf("Dame el numero para triplicar\n---> ");
	scanf("%d", &numero);
	
	return numero;
}

int Triplicar(int numero){
	int temp;
	
	return temp = numero * 3;
	
}
int main() {
	int numero, triple;
	
	numero = AdquirirNumero(numero);
	triple = Triplicar(numero);
	
	printf("%d", triple);
	
	return 0;
}
