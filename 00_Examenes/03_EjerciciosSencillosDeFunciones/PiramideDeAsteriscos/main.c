#include <stdio.h>
#include <stdlib.h>

/* Convierte en un procedimiento el problema de la pirámide de asteriscos (Pasa su altura por parámetro) */

void imprimirPiramide(int altura){
	int i, j, k;
	printf("Dame la altura\n----> ");
	scanf("%d", &altura);
	
	for(i=1; i<=altura; i++){
		for(k=altura; k>=i; k--){
			printf("  ");
		}
		for(j=1; j<=i; j++){
			printf("* ");
		}
		for(j=1+1; j<=i; j++){
			printf("* ");
		}
		printf("\n");
	}
}

int main() {
	int altura;
	
	imprimirPiramide(altura);
	return 0;
}
