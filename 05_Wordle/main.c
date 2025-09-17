#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Wordle es un juego que consiste en adivinar una palabra de cinco letras.
-Se dispone de seis intentos y en cada uno de ellos se debe poner una palabra válida de cinco letras.
-Después de introducir la palabra y darle a ENTER:
-Si la palabra contiene una letra descolocada correcta se marca como tal, si además de contenerla está en el hueco correcto, se señala como tal, mientras que si la palabra no contiene esa letra, se avisa al jugador.
Hay que pensarlo bien porque puede ser que una letra esté repetida.

BONUS:
-IMPRIMIR por pantalla las letras que no hayan sido utilizadas, sacando aquellas que ya no tengan uso o valor (las intentadas por el usuario) Hay que pensarlo bien porque puede ser que una letra esté repetida.
-Reflejar intentos restantes
-Reflejar eficacia porcentual de partidas, esto es la ratio de partidas ganadas contra el total jugadas.
*/

int main(int argc, char *argv[]) {
	char palabra[5];
    char intento[5];
    char resultado[5]; 
    int vidas = 6;
    int i,j;
    bool acierto = false;
    bool encontrada = false;

    printf("Introduce una palabra de 5 letras: ");
    for (i = 0; i < 5; i++) {
        scanf(" %c", &palabra[i]);
    }

    printf("\nx = letra correcta en su posicion\no = letra correcta fuera de su posicion\nPULSA ENTER PARA JUGAR\n\n");
    system("pause");
   	system("cls");

    while (vidas > 0 && !acierto) {
       	
        printf("Tienes %d vidas\n", vidas);
        printf("---> ");
        for (i = 0; i < 5; i++) {
            scanf(" %c", &intento[i]);
        }

        for (i = 0; i < 5; i++) {
            resultado[i] = ' ';
        }

        acierto = true;
        for (i = 0; i < 5; i++) {
            if (intento[i] == palabra[i]) {
                resultado[i] = 'x';
            } else {
              
                encontrada = false;
                for (j = 0; j < 5; j++) {
                    if (intento[i] == palabra[j] && resultado[j] != 'x') {
                        encontrada = true;
                        break;
                    }
                }
                if (encontrada) {
                    resultado[i] = 'o';
                } else {
                    acierto = false;
                }
            }
        }

        printf("---> ");
        for (i = 0; i < 5; i++) {
            printf("%c", resultado[i]);
        }
        printf("\n");

        if (!acierto) {
            vidas--;
        }
        
    }

    if (acierto) {
        printf("Has ganado\n");
    } else {
        printf("Perdiste, la palabra era: ");
        for (i = 0; i < 5; i++) {
            printf("%c", palabra[i]);
        }
        printf("\n");
    }

    return 0;
}
