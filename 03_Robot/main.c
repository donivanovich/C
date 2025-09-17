#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(int argc, char *argv[]) {
	
	char movimiento, e;
	int gasolina = 100;
	int bidonfila, bidoncolumna;
	int minafila, minacolumna;
	int i, fila;
	int j, columna;
	int n[10][10] = {0};
	int filanueva = fila;
	int columnanueva = columna;
	bool dash = false;
	
	printf("Bienvenido al juego del robot, en que posicion deseas iniciar: \n");
	printf("\n   0   1   2   3   4   5   6   7   8   9\n");
	for (i = 0; i < 10; i++) {
        printf("%d ", i);
        for (j = 0; j < 10; j++) {
                printf("[ ] ");
            }
        printf("\n");
    }

	printf("\nFila: ");
    scanf("%d", &fila);

    printf("Columna: ");
    scanf("%d", &columna);
    printf("\n");
    
    system("pause");
    system("cls");

	srand(time(NULL));
	bidonfila = rand() % 10;
	bidoncolumna = rand() % 10;
	minafila = rand() % 10;
	minacolumna = rand() % 10;

    if (fila >= 0 && fila < 10 && columna >= 0 && columna < 10) {
        n[fila][columna] = 1; 
		
		printf("\n   0   1   2   3   4   5   6   7   8   9\n");
        for (i = 0; i < 10; i++) {
            printf("%d ", i);
            for (j = 0; j < 10; j++) {
                if (n[i][j] == 1) {
                    printf("[R] "); 
				} else if (i == bidonfila && j == bidoncolumna) {
				    printf("[B] "); 
				} else if (i == minafila && j == minacolumna) { 
				    printf("[M] ");	 
                } else {
                    printf("[ ] ");
                }     
            }
            printf("\n");
        }
    } else {
        printf("Posición no valida. Debes ingresar valores entre 0 y 9.\n");
        return 1;
    }

    while (gasolina > 0) {

        printf("Gasolina restante: %d\n", gasolina);
        printf("Robot en posicion (%d, %d)\n", fila, columna);
        printf("Moverse al Norte (W), Sur (S), Este (D), Oeste (A) + Dash (E): ");
        scanf(" %c%c", &movimiento, &e);
        system("cls");
		
        int filanueva = fila;
        int columnanueva = columna;
		
		if(e == 'e' || e == 'E'){
			dash = true;
		}
		
        switch (movimiento) {
		    case 'W':
		    case 'w':
		        if (dash == true) {
		            filanueva -= 4;
		            gasolina -= 20;
		            dash = false;
		            
		            if (filanueva < 0) {
		                filanueva = 9 + filanueva;
		            }
		        } else {
		            filanueva--; 
		        }
		        break;
		
		    case 'S':
		    case 's':
		        if (dash == true) {
		            filanueva += 4;
		            gasolina -= 20;
		            dash = false;
		            
		            if (filanueva > 9) {
		                filanueva = filanueva - 10; 
		            }
		        } else {
		            filanueva++;
		        }
		        break;
		
		    case 'D':
		    case 'd':
		        if (dash == true) {
		            columnanueva += 4;
		            gasolina -= 20;
		            dash = false;
		            
		            if (columnanueva > 9) {
		                columnanueva = columnanueva - 10;  
		            }
		        } else {
		            columnanueva++; 
		        }
		        break;
		
		    case 'A':
		    case 'a':
		        if (dash == true) {
		            columnanueva -= 4;
		            gasolina -= 20;
		            dash = false;
		            
		            if (columnanueva < 0) {
		                columnanueva = 9 + columnanueva; 
		            }
		        } else {
		            columnanueva--; 
		        }
		        break;
		
		    default:
		        printf("Movimiento no valido. Usa W, A, S, D o E.\n");
		        continue;
		}
        
        fila = filanueva;
        columna = columnanueva;

        gasolina -= 10;

        if (fila == bidonfila && columna == bidoncolumna) {
            printf("Has encontrado un bidon de gasolina\n");
            gasolina = 100;

            bidonfila = (bidonfila + 3) % 10;
            bidoncolumna = (bidoncolumna + 4) % 10;
        }
        
        if (fila == minafila && columna == minacolumna) {
            printf("Has pisado una mina\n");
            gasolina /= 2;

            minafila = (minafila + 3) % 10;
            minacolumna = (minacolumna + 4) % 10;
        }
	
		printf("\n   0   1   2   3   4   5   6   7   8   9\n");
        for (i = 0; i < 10; i++) {
            printf("%d ", i);
            for (j = 0; j < 10; j++) {
                if (i == fila && j == columna) {
                    printf("[R] "); 
                } else if (i == bidonfila && j == bidoncolumna) {
				    printf("[B] "); 
				} else if (i == minafila && j == minacolumna) {
				    printf("[M] ");
                } else {
                    printf("[ ] ");
                }
            }
            printf("\n");
        }
    }

    printf("Te has quedado sin gasolina, fin del juego\n");

    return 0;
}
