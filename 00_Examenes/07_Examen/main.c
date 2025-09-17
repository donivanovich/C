#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct {
	int id_mazmorra;
	char nombre[255];
	int n_habitaciones;
}Mazmorra;

typedef struct {
	int id_mazmorra;
	char plano[5][5];
	int id_habitacion;
}Habitacion;

int MenuPrincipal(){
	int opc;
	
	printf("1. Crear Mazmorra\n2. Crear Habitacion en Mazmorra\n3. Habitacion Tiene Puertas\n4. Crear Monstruo\n5. Mostrar\n0. Salir\n---> ");
	do{
		scanf("%d", &opc);
	} while(opc < 0 || opc > 5);
	
	return opc;
}

void AltaMazmorra(Mazmorra *mazmorras, int *n_mazmorras){
	int i;
	
	printf("Nombre de la Mazmorra: ");
	scanf("%s", mazmorras[*n_mazmorras].nombre);
	system("cls");
	
	mazmorras[*n_mazmorras].id_mazmorra = (rand() % 100000) + 1;
	mazmorras[*n_mazmorras].n_habitaciones = 0;
	
	printf("Nombre: %s\n", mazmorras[*n_mazmorras].nombre);
	printf("ID Mazmorra: %d\n", mazmorras[*n_mazmorras].id_mazmorra);
	printf("Numero de Habitaciones: %d\n", mazmorras[*n_mazmorras].n_habitaciones);
	
	(*n_mazmorras)++;
	
	for(i = *n_mazmorras; i<100; i++){
		mazmorras[i].n_habitaciones = 0;
	}
}

int AltaHabitacion(Mazmorra *mazmorra, Habitacion *habitaciones, int id_mazmorra_objetivo){
	int i, j, rng, n_hab = 0;
	
	if(id_mazmorra_objetivo < 0){
		return -1;
	} else {
		for(i=0; i<100; i++){
			n_hab += mazmorra[i].n_habitaciones;
		}
		
		habitaciones[n_hab].id_habitacion = (rand() % 100000) + 1;
		habitaciones[n_hab].id_mazmorra = mazmorra[id_mazmorra_objetivo].id_mazmorra; // en el examen exigia poner = id_mazmorra_objetivo, pero pongo lo otro para poder imprimir luego el resultado
		mazmorra[id_mazmorra_objetivo].n_habitaciones++;
		
		printf("ID Habitacion : %d\n", habitaciones[n_hab].id_habitacion);
		printf("Plano\n");
		
		for(i=0; i<5; i++){
			for(j=0; j<5; j++){
				rng = (rand() % 2);
				
				if(rng == 0){
					habitaciones[n_hab].plano[i][j] = 'P';
				} else if (rng == 1){
					habitaciones[n_hab].plano[i][j] = ' ';
				}
				
				printf("[%c]", habitaciones[n_hab].plano[i][j]);
			}
			printf("\n");
		}
		
		printf("ID Mazmorra: %d\n", habitaciones[n_hab].id_mazmorra);
		
		return 0;
	}
}

bool TienePuertas(Habitacion *habitaciones, int id_habitacion_objetivo){
	int i, j;
	
	if(id_habitacion_objetivo < 0){
		return false;
	} else {
		for(i=0; i<5; i++){
			for(j=0; j<5; j++){
				if(habitaciones[id_habitacion_objetivo].plano[i][j] == 'P'){
					return true;
					
				}
			}
		}
	}
	
	return false;
}

int CrearMonstruo(Habitacion *habitaciones, int id_habitacion_objetivo, int fila, int columna){
	int i, j;
	
	if(id_habitacion_objetivo < 0){
		return -1;
	} else {
		if(habitaciones[id_habitacion_objetivo].plano[columna][fila] == ' '){
			habitaciones[id_habitacion_objetivo].plano[columna][fila] = 'M';
			return 0;
			
		}
		
	}
	
	return -1;
}

void ImprimirMazmorrasYHabitaciones(Mazmorra *mazmorras, int n_mazmorras, Habitacion *habitaciones) {
    int i, j, k, l;
    for (i = 0; i < n_mazmorras; i++) {
        printf("ID Mazmorra: %d\n", mazmorras[i].id_mazmorra);
        printf("Nombre: %s\n", mazmorras[i].nombre);
        printf("Numero de Habitaciones: %d\n", mazmorras[i].n_habitaciones);
        printf("--------");
        
        for (j = 0; j < 100; j++) {
            if (habitaciones[j].id_mazmorra == mazmorras[i].id_mazmorra) {
                printf("\nHabitacion ID: %d\n", habitaciones[j].id_habitacion);
                printf("Plano:\n");
                for (k = 0; k < 5; k++) {
                    for (l = 0; l < 5; l++) {
                        printf("[%c]", habitaciones[j].plano[k][l]);
                    }
                    printf("\n");
                }
            }
        }
        
        printf("--------\n\n");
    }
}

int main() {
	int op, n_mazmorras = 0, id_habitacion_objetivo, id_mazmorra_objetivo, resultado, fila, columna;
	Mazmorra mazmorras[100];
	Habitacion habitaciones[100];
	
	do{
		srand(time(NULL));
		op = MenuPrincipal();
		system("cls");
		
		if(op == 1){
			AltaMazmorra(mazmorras, &n_mazmorras);
			
		} else if(op == 2){
			printf("ID de la Mazmorra: ");
			scanf("%d", &id_mazmorra_objetivo);
			system("cls");
			
			resultado = AltaHabitacion(mazmorras, habitaciones, id_mazmorra_objetivo);
			
			if(resultado == 0){
				printf("Habitacion Creada con exito\n");
			} else if(resultado == -1){
				printf("Error no se ha podido crear la habitacion\n");
			}
			
		} else if(op == 3){
			printf("ID de la Habitacion: ");
			scanf("%d", &id_habitacion_objetivo);
			
			if(TienePuertas(habitaciones, id_habitacion_objetivo) == true){
				printf("La Habitacion tiene puerta\n");
			} else {
				printf("No tiene puerta\n");
			}
			
		} else if(op == 4){
			printf("ID de la Habitacion: ");
			scanf("%d", &id_habitacion_objetivo);
			
			printf("Fila: ");
			scanf("%d", &fila);
			
			printf("Columna: ");
			scanf("%d", &columna);
			
			resultado = CrearMonstruo(habitaciones, id_habitacion_objetivo, fila, columna);
			
			if(resultado == 0){
				printf("El Monstruo ha sido colocado\n");
			} else if (resultado == -1){
				printf("Error, el Monstruo ha sufrio un error\n");
			}
		} else if(op == 5){
			ImprimirMazmorrasYHabitaciones(mazmorras, n_mazmorras, habitaciones);
		} else {
			break;
		}
		
		system("pause");
		system("cls");
		
	} while(true);
	
	return 0;
}
