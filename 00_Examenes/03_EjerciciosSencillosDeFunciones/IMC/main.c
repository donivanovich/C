#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <string.h>


/* Función a la que le pases peso y altura y te devuelva el IMC (índice de masa corporal) */


void calcularIMC(float peso, float altura){
	float imc;
	
	printf("Dame peso (en kg)\n---> ");
	scanf("%f", &peso);
	printf("Dame altura (en m)\n---> ");
	scanf("%f", &altura);
	
	imc = peso / (altura * altura);
	printf("%0.2f\n", imc);
}
int main() {
	int peso, altura;
	
	calcularIMC(peso, altura);
	
	return 0;
}
