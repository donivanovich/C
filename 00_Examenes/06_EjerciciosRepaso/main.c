#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Funcion que reciba una palabra (da igual como esten las letras) y que alterne sus letras entre minusculas y mayusculas
   Ejemplo: eleFanTE ------> ELEfANte
   
   Funcion que detecte la palabra 'taco' dentro de una cadena
   Ejemplo: Espartaco devuelve true
   
   Podrias hacer que la funcion de arriba la particula a detectar dentro de la cadena la puedas proporcionar por parametro de entrada
   
   Hacer una funcion que reciba un array de numeros enteros y devuelva la suma y resta alterna de sus celdas
   Ejemplo: En el array 120 9 5 2 66 4 se operaria 120 - 9 + 5 - 2 + 66 - 4 = 176 
   la funcion devuelve 176
   
   Funcion que reciba un mapa de caracteres, devuelva un codigo de error si las filas 
   o las columnas son pares y en caso de funcionar, pinte un '#' JUSTO EN EL CENTRO del mapa*/
   
void alternarLetras(char *palabra){
	int i;
	
	for(i=0; palabra[i] != '\0'; i++){
		if(palabra[i] >= 'A' && palabra[i] <= 'Z'){
			palabra[i] += 32;
		} else if(palabra[i] >= 'a' && palabra[i] <= 'z'){
			palabra[i] -= 32;
		}
	}
	
	printf("Palabra Alterna: %s\n", palabra);
}

void taco(char *palabra){
	int i;
	bool encontrado = false;
	
	for(i=0; palabra[i] != '\0'; i++){
		if(palabra[i] == 't' && palabra[i+1] == 'a' && palabra[i+2] == 'c' && palabra[i+3] == 'o'){
			encontrado = true;
			break;
		}
	}
	
	if(encontrado){
		printf("True\n");
	} else {
		printf("False\n");
	}
}

void detectarPalabra(char *palabra, char *clave){
	int i, l = 0, l2 = 0, j;
	bool encontrado = false, coincide = true;
	
	while(palabra[l] != '\0'){
		l++;
	}
	
	while(clave[l2] != '\0'){
		l2++;
	}
	
	for(i=0; i<=l - l2; i++){
		coincide = true;
		for(j=0; j<l2; j++){
			if(palabra[i+j] != clave[j]){
				coincide = false;
				break;
			}
		}
		if (coincide) {
			encontrado = true;
            break;
        }
	}
	
	if(encontrado){
		printf("True\n");
	} else {
		printf("False\n");
	}
}

int alternarOperadores(int *numeros, int tamano){
	int resultado = numeros[0], i;

    for (i = 1; i < tamano; i++) {
        if (i % 2 == 0) {
            resultado += numeros[i];  
        } else {
            resultado -= numeros[i]; 
        }
    }

    return resultado;
}

void mapaCaracteres(char **mapa){
	int filas, columnas, i, j;
	
	printf("Filas Columnas: ");
	scanf("%d %d", &filas, &columnas);
	
	for(i=0; i<columnas; i++){
		for(j=0; j<filas; j++){
			mapa[i][j] = 'o';
		}
	}
	
	if(filas % 2 == 0 || columnas % 2 == 0){
		return
	} 
	
	mapa[filas/2][columnas/2] = '#';
	
	for(i=0; i<columnas; i++){
		for(j=0; j<filas; j++){
			printf("%c ", mapa[i][j] = 'o');
		}
		printf("\n");
	}
}

int main() {
	int opc, i, total;
	char palabra[50], clave[50], mapa[25][25];
	int numeros[50], tamano;
	
	do{
		system("pause");
		system("cls");
		printf("1. Alternar Letras\n2. Taco\n3. Detectar Palabra\n4. Alternar operadores\n5.Mapa Caracteres\n6. Salir\n----> ");
		do{
			scanf("%d", &opc);
		} while(opc < 1 || opc > 6);
		system("cls");
		if(opc == 1){
			printf("Palabra: ");
			scanf("%s", palabra);
			alternarLetras(palabra);
		} else if(opc == 2){
			printf("Palabra: ");
			scanf("%s", palabra);
			taco(palabra);
		} else if(opc == 3){
			printf("Palabra: ");
			scanf("%s", palabra);
			printf("Clave: ");
			scanf("%s", clave);
			detectarPalabra(palabra, clave);
		} else if(opc == 4){			
			printf("Ingrese números (0 para finalizar):\n");
                tamano = 0;
                while (tamano < 50) {
                    printf("Numero %d: ", tamano + 1);
                    scanf("%d", &numeros[tamano]);
                    if (numeros[tamano] == 0) {
                        break;
                    }
                    tamano++;
                }
	
				total = alternarOperadores(numeros, tamano);
				
                printf("El resultado es %d\n", total);
                
		} else if(opc == 5){
			mapaCaracteres(mapa);
		}
	} while(opc != 6);
	
	return 0;
}
