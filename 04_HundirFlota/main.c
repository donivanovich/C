#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(int argc, char** argv) {
	/*
	Consejo de secuencia:
	-Colocar los barcos J1
	-Colocar los barcos J2
	-Para cada turno:
	    -Seleccionar coordenada de bombardeo
	    -Ver si es TOQUE o AGUA
	    -Actualizar radar de jugador y tocar barco si ha sido acertado
	    -Condición de victoria: Si un jugador alcanza los 17 toques antes que el otro, gana
	    -barco 4 = 1 barco 3 = 2 barco 2 = 3 barco 1 = 1
	*/
	
	char mapaJ1[10][10];
	char mapaJ2[10][10];
	char radarJ1[10][10];
	char radarJ2[10][10];
	char letra, letra2;
	int i, j, posy, posx, x, y, orientacion = 0;
	int numero = 10;
	int toquesJ1, toquesJ2 = 0;
	bool colocado, victoria = false;
	
	//INICIALIZAR MAPA
	
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			mapaJ1[i][j] = '-';
			mapaJ2[i][j] = '-';
			radarJ1[i][j] = '-';
            radarJ2[i][j] = '-';
		}
	}

	// CREAR BARCOS J1
	
	srand(time(NULL));
	
	//BARCO DE 1
	x = rand() % 10;	
	y = rand() % 10;
		
	do{
		if(mapaJ1[x][y] == '-'){
			mapaJ1[x][y] = '@';
			colocado = true;
		}
			
	}while(!colocado);
	
	//BARCOS DE 2
	
	for(i = 1; i <= 3; i++){
		x = rand() % 10;	
		y = rand() % 10;	
		colocado = false;			
		
		do{				
			orientacion = rand() % 4;
			
			switch(orientacion){
				case 0: //norte
					if(y >= 1 && mapaJ1[x][x] == '-' && mapaJ1[x][y - 1] == '-'){
						mapaJ1[x][x - 1] = '@';
						mapaJ1[x][y] = '@';
						colocado = true;
					}
					break;
				case 1: //sur
					if(y <= 8 && mapaJ1[x][y] == '-' && mapaJ1[x][y + 1] == '-'){
						mapaJ1[x][y + 1] = '@';
						mapaJ1[x][y] = '@';
						colocado = true;
					}
					break;
				case 2: //este
					if(x <= 8 && mapaJ1[x][y] == '-' && mapaJ1[x + 1][y] == '-'){
						mapaJ1[x + 1][y] = '@';
						mapaJ1[x][y] = '@';
						colocado = true;
					}
					break;
					
				case 3: //oeste
					if(x >= 1 && mapaJ1[x][y] == '-' && mapaJ1[x - 1][y] == '-'){
						mapaJ1[x - 1][y] = '@';
						mapaJ1[x][y] = '@';
						colocado = true;
					}
					break;
			}
			
		} while(!colocado);
	}
	
	//BARCOS DE 3 
	
	for(i = 1; i <= 2; i++){	
		x = rand() % 10;	
		y = rand() % 10;
		colocado = false;	
		
		do{				
			orientacion = rand() % 4;
			
			switch(orientacion){
				case 0: //norte
					if(y >= 2  && mapaJ1[x][y] == '-' && mapaJ1[x][y - 1] == '-' && mapaJ1[x][y - 2] == '-'){
						mapaJ1[x][y - 1] = '@';
						mapaJ1[x][y - 2] = '@';
						mapaJ1[x][y] = '@';
						colocado = true;
					}
					break;
				case 1: //sur
					if(y <= 7  && mapaJ1[x][y] == '-' && mapaJ1[x][y + 1] == '-' && mapaJ1[x][y + 2] == '-'){
						mapaJ1[x][y + 1] = '@';
						mapaJ1[x][y + 2] = '@';
						mapaJ1[x][y] = '@';
						colocado = true;
					}
					break;
				case 2: //este
					if(x <= 7  && mapaJ1[x][y] == '-' && mapaJ1[x + 1][y] == '-' && mapaJ1[x + 2][y] == '-'){
						mapaJ1[x + 1][y] = '@';
						mapaJ1[x + 2][y] = '@';
						mapaJ1[x][y] = '@';
						colocado = true;
					}
					break;
					
				case 3: //oeste
					if(x >= 2  && mapaJ1[x][y] == '-' && mapaJ1[x - 1][y] == '-' && mapaJ1[x - 2][y] == '-'){
						mapaJ1[x - 1][y] = '@';
						mapaJ1[x - 2][y] = '@';
						mapaJ1[x][y] = '@';
						colocado = true;
					}
					break;
			}
			
		} while(!colocado);
	}
	
	//BARCO DE 4
	
	x = rand() % 10;	
	y = rand() % 10;
	colocado = false;	
	
	do{				
		orientacion = rand() % 4;
		
		switch(orientacion){
			case 0: //norte
				if(y >= 3  && mapaJ1[x][y] == '-' && mapaJ1[x][y - 1] == '-' && mapaJ1[x][y - 2] == '-' && mapaJ1[x][y - 3] == '-'){
					mapaJ1[x][y - 1] = '@';
					mapaJ1[x][y - 2] = '@';
					mapaJ1[x][y - 3] = '@';
					mapaJ1[x][y] = '@';
					colocado = true;
				}
				break;
			case 1: //sur
				if(y <= 6  && mapaJ1[x][y] == '-' && mapaJ1[x][y + 1] == '-' && mapaJ1[x][y + 2] == '-' && mapaJ1[x][y + 3] == '-'){
					mapaJ1[x][y + 1] = '@';
					mapaJ1[x][y + 2] = '@';
					mapaJ1[x][y + 3] = '@';
					mapaJ1[x][y] = '@';
					colocado = true;
				}
				break;
			case 2: //este
				if(x <= 6  && mapaJ1[x][y] == '-' && mapaJ1[x + 1][y] == '-' && mapaJ1[x + 2][y] == '-' && mapaJ1[x + 3][y] == '-'){
					mapaJ1[x + 1][y] = '@';
					mapaJ1[x + 2][y] = '@';
					mapaJ1[x + 3][y] = '@';
					mapaJ1[x][y] = '@';
					colocado = true;
				}
				break;
				
			case 3: //oeste
				if(x >= 3  && mapaJ1[x][y] == '-' && mapaJ1[x - 1][y] == '-' && mapaJ1[x - 2][y] == '-' && mapaJ1[x - 3][y] == '-'){
					mapaJ1[x - 1][y] = '@';
					mapaJ1[x - 2][y] = '@';
					mapaJ1[x - 3][x] = '@';
					mapaJ1[x][y] = '@';
					colocado = true;
				}
				break;
		}
		
	} while(!colocado);	
	
	// CREAR BARCOS J2
	
	srand(time(NULL) + 1);
	
	//BARCO DE 1
	x = rand() % 10;	
	y = rand() % 10;
	
	do{
		if(mapaJ2[x][y] == '-'){
			mapaJ2[x][y] = '@';
			colocado = true;
		}
			
	}while(!colocado);
	
	//BARCOS DE 2
	
	for(i = 1; i <= 3; i++){
		x = rand() % 10;	
		y = rand() % 10;	
		colocado = false;			
		
		do{				
			orientacion = rand() % 4;
			
			switch(orientacion){
				case 0: //norte
					if(y >= 1 && mapaJ2[x][x] == '-' && mapaJ2[x][y - 1] == '-'){
						mapaJ2[x][x - 1] = '@';
						mapaJ2[x][y] = '@';
						colocado = true;
					}
					break;
				case 1: //sur
					if(y <= 8 && mapaJ2[x][y] == '-' && mapaJ2[x][y + 1] == '-'){
						mapaJ2[x][y + 1] = '@';
						mapaJ2[x][y] = '@';
						colocado = true;
					}
					break;
				case 2: //este
					if(x <= 8 && mapaJ2[x][y] == '-' && mapaJ2[x + 1][y] == '-'){
						mapaJ2[x + 1][y] = '@';
						mapaJ2[x][y] = '@';
						colocado = true;
					}
					break;
					
				case 3: //oeste
					if(x >= 1 && mapaJ2[x][y] == '-' && mapaJ2[x - 1][y] == '-'){
						mapaJ2[x - 1][y] = '@';
						mapaJ2[x][y] = '@';
						colocado = true;
					}
					break;
			}
			
		} while(!colocado);
	}
	
	//BARCOS DE 3 
	
	for(i = 1; i <= 2; i++){	
		x = rand() % 10;	
		y = rand() % 10;
		colocado = false;	
		
		do{				
			orientacion = rand() % 4;
			
			switch(orientacion){
				case 0: //norte
					if(y >= 2  && mapaJ2[x][y] == '-' && mapaJ2[x][y - 1] == '-' && mapaJ2[x][y - 2] == '-'){
						mapaJ2[x][y - 1] = '@';
						mapaJ2[x][y - 2] = '@';
						mapaJ2[x][y] = '@';
						colocado = true;
					}
					break;
				case 1: //sur
					if(y <= 7  && mapaJ2[x][y] == '-' && mapaJ2[x][y + 1] == '-' && mapaJ2[x][y + 2] == '-'){
						mapaJ2[x][y + 1] = '@';
						mapaJ2[x][y + 2] = '@';
						mapaJ2[x][y] = '@';
						colocado = true;
					}
					break;
				case 2: //este
					if(x <= 7  && mapaJ2[x][y] == '-' && mapaJ2[x + 1][y] == '-' && mapaJ2[x + 2][y] == '-'){
						mapaJ2[x + 1][y] = '@';
						mapaJ2[x + 2][y] = '@';
						mapaJ2[x][y] = '@';
						colocado = true;
					}
					break;
					
				case 3: //oeste
					if(x >= 2  && mapaJ2[x][y] == '-' && mapaJ2[x - 1][y] == '-' && mapaJ2[x - 2][y] == '-'){
						mapaJ2[x - 1][y] = '@';
						mapaJ2[x - 2][y] = '@';
						mapaJ2[x][y] = '@';
						colocado = true;
					}
					break;
			}
			
		} while(!colocado);
	}
	
	//BARCO DE 4
	
	x = rand() % 10;	
	y = rand() % 10;
	colocado = false;	
	
	do{				
		orientacion = rand() % 4;
		
		switch(orientacion){
			case 0: //norte
				if(y >= 3  && mapaJ2[x][y] == '-' && mapaJ2[x][y - 1] == '-' && mapaJ2[x][y - 2] == '-' && mapaJ2[x][y - 3] == '-'){
					mapaJ2[x][y - 1] = '@';
					mapaJ2[x][y - 2] = '@';
					mapaJ2[x][y - 3] = '@';
					mapaJ2[x][y] = '@';
					colocado = true;
				}
				break;
			case 1: //sur
				if(y <= 6  && mapaJ2[x][y] == '-' && mapaJ2[x][y + 1] == '-' && mapaJ2[x][y + 2] == '-' && mapaJ2[x][y + 3] == '-'){
					mapaJ2[x][y + 1] = '@';
					mapaJ2[x][y + 2] = '@';
					mapaJ2[x][y + 3] = '@';
					mapaJ2[x][y] = '@';
					colocado = true;
				}
				break;
			case 2: //este
				if(x <= 6  && mapaJ2[x][y] == '-' && mapaJ2[x + 1][y] == '-' && mapaJ2[x + 2][y] == '-' && mapaJ2[x + 3][y] == '-'){
					mapaJ2[x + 1][y] = '@';
					mapaJ2[x + 2][y] = '@';
					mapaJ2[x + 3][y] = '@';
					mapaJ2[x][y] = '@';
					colocado = true;
				}
				break;
				
			case 3: //oeste
				if(x >= 3  && mapaJ2[x][y] == '-' && mapaJ2[x - 1][y] == '-' && mapaJ2[x - 2][y] == '-' && mapaJ2[x - 3][y] == '-'){
					mapaJ2[x - 1][y] = '@';
					mapaJ2[x - 2][y] = '@';
					mapaJ2[x - 3][x] = '@';
					mapaJ2[x][y] = '@';
					colocado = true;
				}
				break;
		}
		
	} while(!colocado);
	
	//PEDIR COORDENADA ELEGIDA POR EL USUARIO 2
	
	toquesJ1 = 0;
	
	do{
		printf("Ataca el jugador 2 \nToques: %d\n", toquesJ1);	
		printf("Dame las coordenadas (a-j)(0-9): ");
		scanf(" %c", &letra);
		switch(letra){
			case 'a':
			case 'A':
				posx = 0;
				break;
			case 'b':
			case 'B':
				posx = 1;
				break;
			case 'c': 
			case 'C':
				posx = 2;
				break;
			case 'd': 
			case 'D':
				posx = 3;
				break;
			case 'e': 
			case 'E':
				posx = 4;
				break;
			case 'f':
			case 'F':
				posx = 5;
				break;
			case 'g':
			case 'G':
				posx = 6;
				break;
			case 'h': 
			case 'H':
				posx = 7;
				break;
			case 'i': 
			case 'I':
				posx = 8;
				break;
			case 'j': 
			case 'J':
				posx = 9;
				break;
			default:
				return 0;
				break;		
		}
		
		do{
			scanf("%d", &posy);
			while (getchar() != '\n');
		}while(posy < 0 || posy > 9);
		
		if (mapaJ2[posy][posx] == '@') { 
            radarJ1[posy][posx] = 'X';
            toquesJ1++;
        } else {
            radarJ1[posy][posx] = 'O';
        }
		
		printf("\nMapa Jugador 1\n\n  A B C D E F G H I J\n");
		for(i = 0; i < 10; i++){
			printf("%d", i);
			for(j = 0; j < 10; j++){
				printf(" %c", radarJ1[i][j]);
			}
			printf("\n");
		}
		
		system("pause");
		system("cls");
		
		if(toquesJ1 ==17){
			printf("Jugador 1 gana");
			victoria = true;
			break;
		}
	
		//PEDIR COORDENADA ELEGIDA POR EL USUARIO 1
		
		toquesJ2 = 0;
		
		printf("Ataca el jugador 1 \nToques: %d\n", toquesJ2);	
		printf("Dame las coordenadas (a-j)(0-9): ");
		scanf(" %c", &letra2);
		switch(letra2){
			case 'a':
			case 'A':
				posx = 0;
				break;
			case 'b':
			case 'B':
				posx = 1;
				break;
			case 'c': 
			case 'C':
				posx = 2;
				break;
			case 'd': 
			case 'D':
				posx = 3;
				break;
			case 'e': 
			case 'E':
				posx = 4;
				break;
			case 'f':
			case 'F':
				posx = 5;
				break;
			case 'g':
			case 'G':
				posx = 6;
				break;
			case 'h': 
			case 'H':
				posx = 7;
				break;
			case 'i': 
			case 'I':
				posx = 8;
				break;
			case 'j': 
			case 'J':
				posx = 9;
				break;
			default:
				return 0;
				break;		
		}
		
		do{
			scanf("%d", &posy);
			while (getchar() != '\n');
		}while(posy < 0 || posy > 9);
		
		if (mapaJ1[posy][posx] == '@') {
            radarJ2[posy][posx] = 'X';
            toquesJ2++;
        } else {
            radarJ2[posy][posx] = 'O';
        }
		
		printf("\nMapa Jugador 2\n\n  A B C D E F G H I J\n");
		for(i = 0; i < 10; i++){
			printf("%d", i);
			for(j = 0; j < 10; j++){
				printf(" %c", radarJ2[i][j]);
			}
			printf("\n");
		}	
		
		system("pause");
		system("cls");
		
		if(toquesJ2 == 17){
			printf("Jugador 2 gana");
			victoria = true;
			break;
		}
	} while(!victoria);
	
	return 0;
}


