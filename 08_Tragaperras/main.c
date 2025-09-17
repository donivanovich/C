#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Programar una tragaperras de 3 slots que empiece con un saldo de 100€
//Cada vez que el usuario tira hay que quitar 2€ al saldo y generar
//3 valores aleatorios para los slots
//Si los slots coinciden, añadir 5€ al saldo.
//El usuario puede salir cuando quiera (cash out) o volver a tirar
//Simbolos: ('P')latano, ('C')iruela, ('L')imon y el '7'

int main() {
	int n1, n2, n3;
	char c1, c2, c3, victorias = 0, derrotas = 0, seguir, saldo = 100;
	
	do{
		srand(time(NULL));
		
		n1 = rand()% 4;
		n2 = rand()% 4;
		n3 = rand()% 4;		
		
		if(n1 == 0){
			c1 = 'P';
		} else if(n1 == 1){
			c1 = 'C';
		} else if(n1 == 2){
			c1 = 'L';
		} else if(n1 == 3){
			c1 = '7';
		} 
		
		if(n2 == 0){
			c2 = 'P';
		} else if(n2 == 1){
			c2 = 'C';
		} else if(n2 == 2){
			c2 = 'L';
		} else if(n2 == 3){
			c2 = '7';
		} 
		
		if(n3 == 0){
			c3 = 'P';
		} else if(n3 == 1){
			c3 = 'C';
		} else if(n3 == 2){
			c3 = 'L';
		} else if(n3 == 3){
			c3 = '7';
		} 
		
		printf("La maquina a sacado... \n\n[%c][%c][%c]\n", c1, c2, c3);
		
		if(n1 == n2 && n2 == n3){
			printf("\nEnhorabuena has ganado");
			victorias++;
			saldo += 5;
		} else {
			printf("\nLo siento has perdido");
			derrotas++;
			saldo -= 2;
		}
		
		printf("\nSaldo: %d\n", saldo);
		
		do{
			printf("\nDeseas seguir jugando? (1. SI | 2. NO) ");
			scanf("%d", &seguir);
		} while(seguir < 1 || seguir > 2);
		 
	} while(seguir == 1 && saldo > 0);
	
	printf("\nHas ganado: %d\nHas perdido: %d\nGracias por jugar, hasta la proxima.", victorias, derrotas);
	
	return 0;
}
