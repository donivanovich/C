#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

//Procedimiento que pinte un mensaje por pantalla enmarcado en asteriscos
void darMensaje(char mensaje[50], int longitud){
	int i;
	for(i=0; i<=longitud+1; i++){
		printf("*");
	}
	printf("\n*%s*\n", mensaje);

	for(i=0; i<=longitud+1; i++){
		printf("*");
	}
	printf("\n");
}
//Función que devuelva la media de dos números.
float mediaNumeros(float n1, float n2){
	float suma;
	suma = n1 + n2;
	return suma / 2;
}
//Función que devuelva la media de un array de números (quizás necesites un parámetro que diga cuantos números de ese array intervengan en esa media)
float mediaArray(int numeros[], int n){
	float cantidad, todo = 0;
	int i;
	for(i=0; numeros[i] != '\0'; i++){
		todo += numeros[i];
	}
	cantidad = n;
	return todo / cantidad;
}
//Función que devuelva el último caracter de una palabra.
void ultimoCaracter(char mensaje[], int longitud){
	printf("%c\n", mensaje[longitud-1]);
}
//Procedimiento que Imprima cualquier tablero de caracteres de un array doble (puedes especificar con parámetros de entrada aparte las filas/columnas del array).
void imprimirTablero(char tablero[][10], int filas, int columnas, int eleccion) {
    int seleccion = 0, i = 0;
    
    if(eleccion == 1) {
        printf("Cual fila quieres imprimir (0-9)? ");
        do {
            scanf("%d", &seleccion);
        } while(seleccion < 0 || seleccion >= filas);
        
        for(i = 0; i < columnas; i++) {
            printf("%c", tablero[seleccion][i]);
        }
        printf("\n");
        
    } else if(eleccion == 2) {
        printf("Cual columna quieres imprimir (0-9)? ");
        do {
            scanf("%d", &seleccion);
        } while(seleccion < 0 || seleccion >= columnas);
        
        for(i = 0; i < filas; i++) {
            printf("%c", tablero[i][seleccion]);
        }
        printf("\n");
        
    } else {
        printf("Eleccion no valida\n");
    }
}
//Función que devuelva verdadero o falso si un número es divisible por otro.
bool esDivisible(int n1, int n2){
	if(n1 % n2 == 0){
		return true;
	} else{
		return false;
	}
}
//Función que devuelva verdadero o falso si un número es primo.
bool esPrimo(int n){
	int i;
	if(n == 1){
		return true;
	}
	for(i=2; i<n; i++){
		if(n % i == 0){
			return false;
		} 	
	}
	return true;
}
//Función que devuelva el menor número de un array.
int menorNumero(int numeros[], int n){
	int i, menor = 10;
	for(i=0; i<n; i++){
		if(numeros[i]<menor){
			menor = numeros[i];
		}
	}
	return menor;
}
//Encapsula en una función el algoritmo del Palíndromo.
bool esPalindromo(char mensaje[], int longitud){
	int i, j = 0;
	for(i=longitud-1; i>=0; i--){
		if(mensaje[i] != mensaje[j]){
			return false;
		}
		j++;
	}
	return true;
}
//Procedimiento que reciba una palabra y se sustituyan sus vocales por otra letra pasada por parámetro.
void sustituirLetra(char mensaje[], int longitud, char c){
	int i;
	for(i=0; i<longitud; i++){
		if(mensaje[i] == 'a' || mensaje[i] == 'e' ||  mensaje[i] == 'i' ||  mensaje[i] == 'o' ||  mensaje[i] == 'u' || mensaje[i] == 'A' ||  mensaje[i] == 'E' ||  mensaje[i] == 'I' ||  mensaje[i] == 'O' ||  mensaje[i] == 'U'){
			printf("%c", c);
		}else{
			printf("%c", mensaje[i]);
		}	
	}
	printf("\n");
	return true;
}
//Función/Procedimiento que ordene un array de números de menor a mayor
void ordenarArray(int numeros[], int n){
	int orden[10], i, j;
	for(i=0; i<10; i++){
		orden[i] = 0;
	}
	for(i=0; i<n; i++){
		for(j=0; j<10; j++){
			if(numeros[i] == j){
				orden[j]++;
			}	
		}
	}
	for(i=0; i<10; i++){
		if(orden[i] != 0){
			for(j=0; j<orden[i]; j++){
				printf("%d", i);
			}
		}
	}
	printf("\n");
}

int main() {
	int opc, longitud, n, i, j, numeros[25], eleccion;
	char mensaje[50], tablero[10][10], c;
	float n1, n2, total ;

	do{
		printf("Que quieres hacer: ");
		scanf("%d", &opc);
		if(opc == 1){
			printf("Dame el mensaje: ");
			scanf("%s", mensaje);
			longitud = strlen(mensaje);
			
			darMensaje(mensaje, longitud);
		} else if(opc == 2){
			printf("Dame n1: ");
			scanf("%f", &n1);
			printf("Dame n2: ");
			scanf("%f", &n2);
			total = mediaNumeros(n1, n2);
			printf("%0.2f\n", total);
		} else if(opc == 3){
			printf("Cuantos digitos tiene el array: ");
			scanf("%d", &n);
			numeros[n] = '\0';
			for(i=0; i<n; i++){
				printf("%d: ", i+1);
				scanf("%d", &numeros[i]);
			}
			total = mediaArray(numeros, n);
			printf("%0.2f\n", total);
		} else if(opc == 4){
			printf("Dame el string: ");
			scanf("%s", mensaje);
			longitud = strlen(mensaje);
			
			ultimoCaracter(mensaje, longitud);
		} else if(opc == 5){
			for(i=0; i<10; i++){
				for(j=0; j<10; j++){
					tablero[j][i] = 'a' + i;
				}
			}
			printf("Deseas imprimir una fila (1) o una columna (2)? ");
		    scanf("%d", &eleccion);
		    
		    imprimirTablero(tablero, 10, 10, eleccion);
		} else if(opc == 6){
			printf("Dame numerador: ");
			scanf("%f", &n1);
			printf("Dame dividendo: ");
			scanf("%f", &n2);
			if(esDivisible(n1, n2) == false){
				printf("El numero no es divisible\n");
			} else {
				printf("El numero es divisible\n");
			}
		} else if(opc == 7){
			printf("Dame numero: ");
			scanf("%d", &n);
			if(esPrimo(n) == false){
				printf("El numero no es primo\n");
			} else {
				printf("El numero es primo\n");
			}
		} else if(opc == 8){
			printf("Cuantos digitos tiene el array: ");
			scanf("%d", &n);
			numeros[n] = '\0';
			for(i=0; i<n; i++){
				printf("%d: ", i+1);
				scanf("%d", &numeros[i]);
			}
			total = menorNumero(numeros, n);
			printf("Numero menor = %0.0f\n", total);
		} else if(opc == 9){
			printf("Dame el string: ");
			scanf("%s", mensaje);
			longitud = strlen(mensaje);
			
			if(esPalindromo(mensaje, longitud) == false){
				printf("No es Palindromo\n");
			} else {
				printf("Es Palindromo\n");
			}
		} else if(opc == 10){
			printf("Dame el string: ");
			scanf("%s", mensaje);
			longitud = strlen(mensaje);
			printf("Dame el caracter a sustituir: ");
			scanf(" %c", &c);
			
			sustituirLetra(mensaje, longitud, c);
		} else if(opc == 11){
			printf("Cuantos digitos tiene el array: ");
			scanf("%d", &n);
			numeros[n] = '\0';
			for(i=0; i<n; i++){
				printf("%d: ", i+1);
				scanf("%d", &numeros[i]);
			}
			ordenarArray(numeros, n);
		}
		system("pause");
		system("cls");
	} while(opc > 0 && opc < 11);
	return 0;
}
