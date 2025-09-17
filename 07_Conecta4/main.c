#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	
	int i,j, movJ1, movJ2;
	bool encontrado = false;
	char tablero[6][7];
	
	for(i=0; i<6; i++){
		for(j=0; j<7; j++){
			tablero[i][j] = ' ';
		}
	}
	
	printf("Bienvenido al Conecta 4  <3\n\n");
	for (i = 0; i < 6; i++) {
        printf("+---+---+---+---+---+---+---+\n");
        printf("|   |   |   |   |   |   |   |\n");
    }
    printf("+---+---+---+---+---+---+---+\n\n");
	system("pause");
	system("cls");
	
	do{
		printf("[0][1][2][3][4][5][6]\n");
		for(i=0; i<6; i++){
			for(j=0; j<7; j++){
				printf("[");
				printf("%c", tablero[i][j]);
				printf("]");
			}
			printf("\n");
		}
		printf("\n");
		
		do{
			printf("Mueve el J1: ");
			scanf("%d", &movJ1);
		} while(movJ1 < 0 || movJ1 > 6);
		
		for(i=5; i>=0; i--){
			if(tablero[i][movJ1] == ' '){
				tablero[i][movJ1] = 'X';
				break;
			}		
		}
		
		system("cls");
		
		for(i=0; i<6; i++){
			for(j=0; j<7; j++){
				if(tablero[i][j] == 'X' && tablero[i][j+1] == 'X' && tablero[i][j+2] == 'X' && tablero[i][j+3] == 'X'){
					printf("************************\n");
			        printf("*   Jugador 1 GANA!    *\n");
			        printf("*   Felicidades J1     *\n");
			        printf("************************\n");
					encontrado = true;
					return 0;
				}
				if(tablero[i][j] == 'X' && tablero[i+1][j] == 'X' && tablero[i+2][j] == 'X' && tablero[i+3][j] == 'X'){
					printf("************************\n");
			        printf("*   Jugador 1 GANA!    *\n");
			        printf("*   Felicidades J1     *\n");
			        printf("************************\n");
					encontrado = true;
					return 0;
				}
				if(tablero[i][j] == 'X' && tablero[i-1][j-1] == 'X' && tablero[i-2][j-2] == 'X' && tablero[i-3][j-3] == 'X'){
					printf("************************\n");
				    printf("*   Jugador 1 GANA!    *\n");
				    printf("*   Felicidades J1     *\n");
				    printf("************************\n");
					encontrado = true;
					return 0;
				}
				if(tablero[i][j] == 'X' && tablero[i-1][j+1] == 'X' && tablero[i-2][j+2] == 'X' && tablero[i-3][j+3] == 'X'){
					printf("************************\n");
			        printf("*   Jugador 1 GANA!    *\n");
			        printf("*   Felicidades J1     *\n");
			        printf("************************\n");
					encontrado = true;
					return 0;
				}
			}
		}
		
		printf("[0][1][2][3][4][5][6]\n");
		for(i=0; i<6; i++){
			for(j=0; j<7; j++){
				printf("[");
				printf("%c", tablero[i][j]);
				printf("]");
			}
			printf("\n");
		}
		printf("\n");
		
		do{	
			printf("Mueve el J2: ");
			scanf("%d", &movJ2);
		} while(movJ2 < 0 || movJ2 > 6);
		
		for(i=5; i>=0; i--){
			if(tablero[i][movJ2] == ' '){
				tablero[i][movJ2] = 'O';
				break;
			}	
			
		}
		
		system("cls");
		
		for(i=0; i<6; i++){
			for(j=0; j<7; j++){
				if(tablero[i][j] == 'O' && tablero[i][j+1] == 'O' && tablero[i][j+2] == 'O' && tablero[i][j+3] == 'O'){
					printf("************************\n");
			        printf("*   Jugador 2 GANA!    *\n");
			        printf("*   Felicidades J2     *\n");
			        printf("************************\n");
					encontrado = true;
					return 0;
				}
				if(tablero[i][j] == 'O' && tablero[i+1][j] == 'O' && tablero[i+2][j] == 'O' && tablero[i+3][j] == 'O'){
					printf("************************\n");
			        printf("*   Jugador 2 GANA!    *\n");
			        printf("*   Felicidades J2     *\n");
			        printf("************************\n");
					encontrado = true;
					return 0;
				}
				if(tablero[i][j] == 'O' && tablero[i-1][j-1] == 'O' && tablero[i-2][j-2] == 'O' && tablero[i-3][j-3] == 'O'){
					printf("************************\n");
			        printf("*   Jugador 2 GANA!    *\n");
			        printf("*   Felicidades J2     *\n");
			        printf("************************\n");
					encontrado = true;
					return 0;
				}
				if(tablero[i][j] == 'O' && tablero[i-1][j+1] == 'O' && tablero[i-2][j+2] == 'O' && tablero[i-3][j+3] == 'O'){
					printf("************************\n");
			        printf("*   Jugador 2 GANA!    *\n");
			        printf("*   Felicidades J2     *\n");
			        printf("************************\n");
					encontrado = true;
					return 0;
				}
			}
		}
		
	}while(!encontrado);
	
	return 0;
}
