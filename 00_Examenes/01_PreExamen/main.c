#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Crea un programa en C que implemente una codificación basada en invertir las palabras de una frase. El programa debe:

Definir una variable palabra[50] =
"Hola mundo desde C";
Dividir la frase en palabras (considera los espacios como separadores).Invertir cada palabra individualmente.Mostrar la frase codificada con las palabras invertidas, pero en el mismo orden.

palabra[50]: "Hola mundo desde C"
Salida: "aloH odnum edsed C"
Usa funciones para modularizar el código:
Una función para invertir una palabra.
Una función para dividir la frase en palabras y procesarlas. */

void leerCadena(char cadena[], int tam) {
    fgets(cadena, tam, stdin);
    int longitud = strlen(cadena);
    if (cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0';
    }
}

void invertirPalabras(char origen[], char destino[]) {
    int i = 0, j = 0, k = 0;
    int inicioPalabra = 0, finalPalabra = 0;
    int longitud = strlen(origen);

    while (i <= longitud) {
        if (origen[i] == ' ' || origen[i] == '\0') {
            finalPalabra = i - 1;

            for (k = finalPalabra; k >= inicioPalabra; k--) {
                destino[j++] = origen[k];
            }
            if (origen[i] == ' ') {
                destino[j++] = ' ';
            }
            inicioPalabra = i + 1;
        }
        i++;
    }
    destino[j] = '\0'; 
}

void imprimirCadena(char cadena[]) {
    printf("%s", cadena);
}

int main() {
    char palabra[50], frase[50];

    printf("Dame la cadena: ");
    leerCadena(palabra, sizeof(palabra));

    invertirPalabras(palabra, frase);

    printf("\n");
    imprimirCadena(frase);

    return 0;
}
