#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* 
Ejercicio 1: (1 Punto)
Implementa una estructura pelicula que permita manejar un id_pelicula, el id de la sala donde se proyectara,
el titulo de la pelicula y dos fechas (lanzamiento y retiro)

Ejercicio 2: (3 Puntos)
Implementa esta funcion de manera que se pueda reservar una butaca libre en la sala pasado por parametro
(la primera butaca libre que se localice). Devolver a la salida el id de la butaca que se ha grabado
como reservada, SI NO existieran butacas libres, devolver -1.
ESCRIBIR LA INVOCACION CORRECTA DESDE EL MAIN EN LA LINEA CORRESPONDIENTE

Ejercicio 3: (1 Punto)
Que cabecera puede tener una funcion CancelarReserva que asigna de nuevo el estado libre a una butaca?
ESCRIBIR LA INVOCACION CORRECTA DESDE EL MAIN EN LA LINEA CORRESPONDIENTE

Ejercicio 4: (2 Puntos)
Implementa de forma completa una funcion que cree y grabe una pelicula y se le asigne una sala concreta.
ESCRIBIR LA INVOCACION CORRECTA DESDE EL MAIN EN LA LINEA CORRESPONDIENTE

Ejercicio 5: (3 Puntos)
Implementa de forma compleata una funcion que libere una sala. Esto significa: desasignar la posible
pelicula que pueda tener y poner todas sus butacas libres
ESCRIBIR LA INVOCACION CORRECTA DESDE EL MAIN EN LA LINEA CORRESPONDIENTE
*/


typedef struct butaca{
	int id_butaca;
	bool estado;
	char fecha_hora[20];
}Butaca;

typedef struct sala{
	int id_sala;
	Butaca butacas[120];
}Sala;

typedef struct pelicula{
	int id_pelicula;
	int id_sala;
	char titulo[50];
	char lanzamiento[8];
	char retiro[8];
}Pelicula;

int MenuPrincipal(){
	int opcion;
		do{
			printf("1. Reservar butaca\n2. Cancelar reserva\n3. Asignacion de pelicula a sala\n4. Liberar sala\n0. Salir\n----> ");
			scanf("%d", &opcion);
			system("cls"); 
		} while(opcion < 0 && opcion > 4);
			
	return opcion;
}

void ReservarButaca(Sala *s, int id_sala, char fecha_hora_reserva[20]){
	int i, sala;
	bool fin = false, butacaReservada = false;
	
	printf("[Reservas de Butacas]\n");
	printf("Selecciona una sala (1-5):\n");
	
	
	for(i=0; i<5;i++){
		printf("Sala %d\n", s[i].id_sala);
	}
		
	scanf("%d", &sala);
	system("cls");
	
	if(sala > 0 && sala < 6){
		sala--;
		
		for(i=0; i<120; i++){
			if(s[sala].butacas[i].estado == 0){
				s[sala].butacas[i].estado = 1;
				printf("Se ha reservado la butaca\nID: %d\nSala: %d\nDia y hora: %s\n\n", s[sala].butacas[i].id_butaca, sala + 1, s[sala].butacas[i].fecha_hora);
				butacaReservada = true;
				break;
			}
				
		}
		
		if(!butacaReservada){
			printf("-1\n\n");
		}
		
	} else {
		printf("Error, no existe la sala\n\n");
	}
	
}

void CancelarReserva(Sala *s, int id_sala, char fecha_hora_reserva[20]){
	int i, sala, butaca;
	bool fin = false, reservaCancelada = false;
	
	printf("[Cancelar Reserva]\n");
	printf("Selecciona una sala (1-5):\n");
	
	
	for(i=0; i<5;i++){
		printf("Sala %d\n", s[i].id_sala);
	}
		
	scanf("%d", &sala);
	system("cls");
	
	do{
		printf("Introduce la butaca (1-120):\n---> ");
		scanf("%d", &butaca);
	} while (butaca < 1 || butaca > 120);
		
	
	if(sala > 0 && sala < 6){
		sala--;
		butaca--;
		
		if(s[sala].butacas[butaca].estado == 1){
			s[sala].butacas[butaca].estado = 0;
			printf("Se ha cancelado la reserva\nID: %d\nSala: %d\n\n", s[sala].butacas[butaca].id_butaca, sala + 1);
			reservaCancelada = true;		
		}
		
		if(!reservaCancelada){
			printf("-1\n\n");
		}
		
	} else {
		printf("Error, no existe la sala\n\n");
	}
}

void AsignarPelicula(Sala *s, Pelicula *p, int *contPeli){
	char nombrePeli[50], lanzamiento[10], retiro[10];
	int sala;
	
	if (*contPeli >= 5) {
        printf("No se pueden asignar mas peliculas\n\n");
        return;
    }
	
	printf("[Asignar Pelicula]\n");
	
	printf("Nombre de la pelicula:\n---> ");
	scanf(" %[^\n]", nombrePeli);
	
	
	do{
		printf("ID de la Sala (1-5):\n---> ");
		scanf("%d", &sala);
	} while (sala < 1 || sala > 5);
	sala--;
	
	strcpy(p[*contPeli].titulo, nombrePeli);
	p[*contPeli].id_sala = sala;
	
	printf("Fecha lanzamiento (DD/MM/AAAA):\n---> ");
	scanf(" %[^\n]", lanzamiento);
	strcpy(p[*contPeli].lanzamiento, lanzamiento);

	printf("Fecha retiro (DD/MM/AAAA):\n---> ");
	scanf(" %[^\n]", retiro);
	strcpy(p[*contPeli].retiro, retiro);
	
	printf("\nPelicula asignada correctamente:\n");
    printf("Titulo: %s\nSala: %d\nLanzamiento: %s\nRetiro: %s\n\n", p[*contPeli].titulo, p[*contPeli].id_sala, p[*contPeli].lanzamiento, p[*contPeli].retiro);
	
	(*contPeli)++;
}

void LiberarSala(Sala *s, Pelicula *p){
	int sala, i;
	
	do{
		printf("ID de la Sala (1-5):\n---> ");
		scanf("%d", &sala);
	} while (sala < 1 || sala > 5);
	sala--;
	
	for(i=0; i<120; i++){
		s[sala].butacas[i].estado = 0;
	}
	
	for(i=0; i<5; i++){
		if(p[i].id_sala == sala + 1){
			p[i].id_sala -= 1;
			printf("Pelicula '%s' desasignada de la Sala %d\n\n", p[i].titulo, sala + 1);
		}
	}
	
	printf("Sala %d liberada correctamente, todas las butacas estan ahora libres\n\n", sala + 1);
}

int main (){
	char fecha_hora_reservada[20];
	int opc, i, j, id_sala, contPeli = 0;
	Sala s[5];
	Pelicula p[5];
	
	for(j=0; j<5; j++){
		s[j].id_sala = j + 1;
		p[j].id_pelicula = j + 1;
		strcpy(p[j].titulo, "");
		for(i=0; i<120; i++){
			s[j].butacas[i].estado = 0;
			s[j].butacas[i].id_butaca = i + 1;
			strcpy(s[j].butacas[i].fecha_hora, "14/02/2025 13:45");
		}	
	}

	do{
		opc = MenuPrincipal();
		
		if(opc == 1){
			ReservarButaca(&s, id_sala, fecha_hora_reservada);
		} else if(opc == 2){
			CancelarReserva(&s, id_sala, fecha_hora_reservada);
		} else if(opc == 3){
			AsignarPelicula(&s, &p, &contPeli);
		} else if(opc == 4){
			LiberarSala(&s, &p);
		}
	} while(opc != 0);
	
	return 0;
}
