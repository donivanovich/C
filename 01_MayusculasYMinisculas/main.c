#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {	
int num;
int num1;
int num2;
char letra;
char suma;
char resta;

do{
	printf("1. Convertir de mayuscula a minuscula\n");
	printf("2. Convertir de minuscula a mayuscula\n");
	printf("3. Sumas 2 numeros\n");
	printf("4. Restar 2 numeros\n");
	printf("5. Dividir 2 numeros\n");
	printf("6. Multiplicar 2 numeros\n");
	printf("7. Salir\n");
	scanf("%d", &num);

	switch(num){
		case 1:
			printf("Introduce una letra mayuscula: \n");
			scanf(" %c", &letra);
			suma = letra + 32;
			printf("La letra convertida es: %c\n", suma);
		break;
		case 2:
			printf("Introduce una letra minuscula: \n");
			scanf(" %c", &letra);
			resta = letra - 32;
			printf("La letra convertida es: %c", resta);
		break;
		case 3:
			printf("Introduce un numero: \n");
			scanf("%d", &num1);
			printf("Introduce otro numero: \n");
			scanf("%d", &num2);
			printf("La suma de los numeros es: %d", num1 + num2 );
		break;
		case 4:
			printf("Introduce un numero: \n");
			scanf("%d", &num1);
			printf("Introduce otro numero: \n");
			scanf("%d", &num2);
			printf("La resta de los numeros es: %d", num1 - num2 );
		break;
		case 5:
			printf("Introduce un numero: \n");
			scanf("%d", &num1);
			printf("Introduce otro numero: \n");
			scanf("%d", &num2);
			printf("La division de los numeros es: %d", num1 / num2 );
		break;
		case 6:
			printf("Introduce un numero: \n");
			scanf("%d", &num1);
			printf("Introduce otro numero: \n");
			scanf("%d", &num2);
			printf("La multiplicacion de los numeros es: %d", num1 * num2 );
		break;
		case 7:
			printf("Pues adios...");
		break;

}

if (num != 7){
	printf("\nPresiona ENTER para continuar...");
	getchar();
	getchar();
	system("cls");
}

}while(num != 7);


	return 0;
}
