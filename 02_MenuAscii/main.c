#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int opcion = 0;
	int altura = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	
	printf("|-------------------------------------------------------------|\n");
	printf("| Bienvenido al menu ascii, selecciona la figura a imprimir   |\n");
	printf("|-------------------------------------------------------------|\n");
	printf("| 1.  Cuadrado                                                |\n");
	printf("| 2.  Cuadrado sin relleno                                    |\n");
	printf("| 3.  Medio triangulo                                         |\n");
	printf("| 4.  Medio triangulo invertido                               |\n");
	printf("| 5.  Medio triangulo invertido sin relleno                   |\n");
	printf("| 6.  Medio triangulo boca a abajo sin relleno                |\n");
	printf("| 7.  Triangulo                                               |\n");
	printf("| 8.  Triangulo sin relleno                                   |\n");
	printf("| 9.  Triangulo invertido sin relleno                         |\n");
	printf("| 10. Rombo                                                   |\n");
	printf("| 11. Rombo sin relleno                                       |\n");
	printf("| 12. Circulo con aspa                                        |\n");
	printf("| 13. Calabaza                                                |\n");
	printf("|_____________________________________________________________|\n");
	scanf("%d", &opcion);
	
	do {
		switch (opcion){
			
			case 1:
				printf("Introduce la altura del 'Cuadrado': \n");
				scanf("%d", &altura);
				
				for (i = 0; i < altura; i++){
					for (j = 0; j < altura; j++){
						printf("* ");
					}
					printf("\n");
				}
				break;
				
			case 2:
				printf("Introduce la altura del 'Cuadrado sin relleno': \n");
				scanf("%d", &altura);
				
				for (i = 0; i < altura; i++){
					for (j = 0; j < altura; j++){					
						if(i == 0 || i == altura - 1 || j == 0 || j == altura - 1){
							printf("* ");
						} else {
							printf("  ");
						}
					}
					printf("\n");
				}
				break;
				
			case 3:
				printf("Introduce la altura del 'Medio triangulo': \n");
				scanf("%d", &altura);
				
				for (i = 1; i <= altura; i++){
					for (j = 1; j <= i; j++){
						printf("* ");
					}
					printf("\n");
				}
				break;
				
			case 4:
				printf("Introduce la altura del 'Medio triangulo invertido': \n");
				scanf("%d", &altura);
				
				for (i = 1; i <= altura; i++){
					for(j = 1; j <= altura - i; j++){
						printf("  ");
					}
					for (j = 1; j <= i; j++){
						printf(" *");
					}
					printf("\n");
				}
				break;
				
			case 5:
				printf("Introduce la altura del 'Medio triangulo invertido sin relleno': \n");
				scanf("%d", &altura);
				
				for (i = 1; i <= altura; i++){
					for (j = 1; j <= altura - i; j++){
						printf("  ");
					}	
					for (j = 1; j <= i; j++){
						if(j == 1 || j == i || i == altura){
							printf(" *");
						} else {
							printf("  ");
						}
					}
					printf("\n");
				}
				break;
				
			//ESTA MAL	
			case 6:
				printf("Introduce la altura del 'Medio triangulo boca a abajo sin relleno': \n");
				scanf("%d", &altura);
				for (i = altura; i > 0; i--) {
			        for (j = 0; j < altura - i; j++) {
			            printf(" ");
			        }
			        for (j = 0; j < i; j++) {
			            if (j == 0 || j == i - 1) {
			                printf("*");
			            } else {
			                printf(" ");
			            }
			        }
			        printf("\n");
			    }
				break;
				
			case 7:
				printf("Introduce la altura del 'Triangulo': \n");
				scanf("%d", &altura);
				
				for (i = 1; i <= altura; i++){
					for(j = 1; j <= altura - i; j++){
						printf("   ");
					}
					for(k = 1; k <= (2 * i) - 1; k++){
						printf(" * ");
					}
					printf("\n");
				}
				break;
				
			case 8:
				printf("Introduce la altura del 'Triangulo sin relleno': \n");
				scanf("%d", &altura);
				for (i = 1; i <= altura; i++) {
			        for (j = 1; j <= altura - i; j++) {
			            printf("   ");
			        }
			
			        for (j = 1; j <= (2 * i) - 1; j++) {
			            if (j == 1 || j == (2 * i) - 1 || i == altura) {
			                printf(" * ");
			            } else {
			                printf("   ");
			            }
			        }
			        printf("\n");
			    }
				break;
			
			//ESTA MAL
			case 9:
				printf("Introduce la altura del 'Triangulo invertido sin relleno': \n");
				scanf("%d", &altura);
				for (i = altura; i > 0; i--) {
			        for (j = 0; j < altura - i; j++) {
			            printf(" ");
			        }
			        printf("*");
			        if (i > 1) {
			            for (j = 0; j < (i - 1) * 2 - 1; j++) {
			                printf(" ");
			            }
			            printf("*");
			        }
			        printf("\n");
			    }
				
				break;
				
			case 10:
				printf("Introduce la altura del 'Rombo': \n");
				scanf("%d", &altura);
				
				for (i = 1; i <= altura; i++){
					for(j = 1; j <= altura - i; j++){
						printf("   ");
					}
					for (k = 1; k <= (2 * i) - 1; k++){
						printf(" * ");
					}
					printf("\n");
				}
				for (i = altura - 1; i >= 1; i--){
					for (j = altura; j - i >= 1; j--){
						printf("   ");
					}
					for (k = 1; k <= (2 * i) - 1; k++){
						printf(" * ");
					}
					printf("\n");
				}
				break;
				
			case 11:
				printf("Introduce la altura del 'Rombo sin relleno': \n");
				scanf("%d", &altura);
			    for (i = 1; i <= altura; i++) {
       				for (j = 1; j <= altura - i; j++) {
            			printf(" ");
        			}
        			for (j = 1; j <= (2 * i - 1); j++) {
          				if (j == 1 || j == (2 * i - 1)) {
                			printf("*");
            			} else {
                			printf(" ");
            			}
        			}
        			printf("\n");
			    }
			
			    for (i = altura - 1; i >= 1; i--) {
			        for (j = 1; j <= altura - i; j++) {
			            printf(" ");
			        }
			        for (j = 1; j <= (2 * i - 1); j++) {
			            if (j == 1 || j == (2 * i - 1)) {
			                printf("*");
			            } else {
			                printf(" ");
			            }
			        }
			        printf("\n");
			    }	
				break;
				
			case 12:
				printf("Introduce la altura del 'Circulo con aspa': \n");
				scanf("%d", &altura);
				break;	
				
			case 13:
				printf("Introduce la altura del 'Calabaza': \n");
				scanf("%d", &altura);
				break;
	
		}

if (opcion != 13){
	printf("\nPresiona ENTER para continuar...");
	getchar();
	getchar();
	system("cls");
	}	
	} while (opcion != 13);
			
			
			
		return 0;
			
}
