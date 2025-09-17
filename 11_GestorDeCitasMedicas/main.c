#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Realiza un programa que gestione las citas médicas de los pacientes de un consultorio.
Deben poder darse de alta pacientes
Deben poder darse de alta citas (con id propio, fecha e identificador del paciente que las solicitó)
Deben poder modificarse citas
Deben poder borrarse citas */

//fflush(stdin);      ------------>    sirve para limpiar el buffer de los scanf, se pone encima de estos

typedef struct Pacientes{
	char nombre[50];
	char apellido[50];
	char dni[9];
	int year;
	int month;
	int day;
	int id;
} Paciente;

typedef struct Citas{
	int year;
	int month;
	int day;
	int id;
	int hora;
	int min;
	int idpaciente;
} Cita;

int pintarMenu(){
	int opcion;
	printf("******************************\n");
	printf("* 1. Dar de Alta un Cliente  *\n");
	printf("* 2. Dar de Alta una Cita    *\n");
	printf("* 3. Modificar Cita          *\n");
	printf("* 4. Borrar Cita             *\n");
	printf("* 5. Mostrar Pacientes       *\n");
	printf("* 6. Mostrar Citas           *\n");
	printf("* 7. Salir                   *\n");
	printf("******************************\n");
	
	do{
		printf("---> ");
		scanf("%d", &opcion);	
	} while(opcion < 1 || opcion > 7);
	system("cls");
	return opcion;
}

void altaPaciente(int *contador, Paciente p[]){
	printf("Nombre del Paciente\n---> ");
	scanf("%49s", p[*contador].nombre);
	system("cls");
	printf("Apellido del Paciente\n---> ");
	scanf("%49s", p[*contador].apellido);
	system("cls");
	printf("DNI del Paciente\n---> ");
	scanf("%9s", p[*contador].dni);
	system("cls");
	do{
		printf("Año de Nacimiento\n---> ");
		scanf("%d", &p[*contador].year);
		system("cls");
	} while(p[*contador].year < 1900);
	do{
		printf("Mes de Nacimiento\n---> ");
		scanf("%d", &p[*contador].month);
		system("cls");
	} while(p[*contador].month < 1 || p[*contador].month > 12);
	do{
		printf("Dia de Nacimiento\n---> ");
		scanf("%d", &p[*contador].day);
		system("cls");
	} while(p[*contador].day < 1 || p[*contador].day > 31);
	
	p[*contador].id = *contador;
	
	printf("[Se ha dado de Alta al Paciente correctamente]\n\n");
	printf("%s %s [%s]\n", p[*contador].nombre, p[*contador].apellido, p[*contador].dni);
	printf("%d/%d/%d\n", p[*contador].day, p[*contador].month, p[*contador].year);
	printf("ID: %d\n\n", p[*contador].id);
	(*contador)++;
}
void altaCita(int *contador2, Cita c[]){
	int i = 0;
	
	if (*contador2 >= 50) {
        printf("[No se pueden registrar mas citas]\n");
        return;
    }
    
    for (i = 1; i < 50; i++) {
        if (c[i].idpaciente == -1) {
            break;
        }
    }
    
    if (i == 50) {
        i = *contador2;
    }
    
    do {
        printf("Año de la Cita\n---> ");
        scanf("%d", &c[i].year);
        system("cls");
    } while (c[i].year < 2025);
    do {
        printf("Mes de la Cita\n---> ");
        scanf("%d", &c[i].month);
        system("cls");
    } while (c[i].month < 1 || c[i].month > 12);
    do {
        printf("Dia de la Cita\n---> ");
        scanf("%d", &c[i].day);
        system("cls");
    } while (c[i].day < 1 || c[i].day > 31);
    do {
        printf("Hora de la Cita\n---> ");
        scanf("%d", &c[i].hora);
        system("cls");
    } while (c[i].hora < 0 || c[i].hora > 23);
    do {
        printf("Minuto de la Cita\n---> ");
        scanf("%d", &c[i].min);
        system("cls");
    } while (c[i].min < 0 || c[i].min > 59);
    do {
        printf("ID del Paciente\n---> ");
        scanf("%d", &c[i].idpaciente);
        system("cls");
    } while (c[i].idpaciente < 1 || c[i].idpaciente > 49);
    c[i].id = i;
    printf("[Cita registrada con exito]\n");
    printf("Fecha de la Cita: %d/%d/%d a las %d:%d\n", c[i].day, c[i].month, c[i].year, c[i].hora, c[i].min);
	printf("ID del Paciente: %d\n", c[i].idpaciente);
    if (i == *contador2) {
        (*contador2)++;
    }
}

void modificarCita(Cita c[]){
	int temp;
	printf("[Modificar los datos]\n");
	printf("ID de la Cita a modificar\n---> ");
	scanf("%d", &temp);
	system("cls");
	
	do{
		printf("Fecha de la Cita: %d/%d/%d a las %d:%d\n", c[temp].day, c[temp].month, c[temp].year, c[temp].hora, c[temp].min);
		printf("ID del Paciente: %d\n", c[temp].idpaciente);
		printf("Año de la Cita ---> ");
		scanf("%d", &c[temp].year);
		system("cls");
	} while(c[temp].year < 2025);
	do{
		printf("Fecha de la Cita: %d/%d/%d a las %d:%d\n", c[temp].day, c[temp].month, c[temp].year, c[temp].hora, c[temp].min);
		printf("ID del Paciente: %d\n", c[temp].idpaciente);
		printf("Mes de la Cita ---> ");
		scanf("%d", &c[temp].month);
		system("cls");	
	} while(c[temp].month < 1 || c[temp].month > 12);
	do{
		printf("Fecha de la Cita: %d/%d/%d a las %d:%d\n", c[temp].day, c[temp].month, c[temp].year, c[temp].hora, c[temp].min);
		printf("ID del Paciente: %d\n", c[temp].idpaciente);
		printf("Dia de la Cita ---> ");
		scanf("%d", &c[temp].day);
		system("cls");
	} while(c[temp].day < 1 || c[temp].day > 31);
	do{
		printf("Fecha de la Cita: %d/%d/%d a las %d:%d\n", c[temp].day, c[temp].month, c[temp].year, c[temp].hora, c[temp].min);
		printf("ID del Paciente: %d\n", c[temp].idpaciente);
		printf("Hora de la Cita ---> ");
		scanf("%d", &c[temp].hora);
		system("cls");	
	} while(c[temp].hora < 0 || c[temp].hora > 23);
	do{
		printf("Fecha de la Cita: %d/%d/%d a las %d:%d\n", c[temp].day, c[temp].month, c[temp].year, c[temp].hora, c[temp].min);
		printf("ID del Paciente: %d\n", c[temp].idpaciente);
		printf("Minuto de la Cita ---> ");
		scanf("%d", &c[temp].min);
		system("cls");
	} while(c[temp].min < 0 || c[temp].min > 59);
	do{
		printf("Fecha de la Cita: %d/%d/%d a las %d:%d\n", c[temp].day, c[temp].month, c[temp].year, c[temp].hora, c[temp].min);
		printf("ID del Paciente: %d\n", c[temp].idpaciente);
		printf("ID del Paciente ---> ");
		scanf("%d", &c[temp].idpaciente);
		system("cls");
	} while(c[temp].idpaciente < 1);
	
	printf("[Se ha modificado la cita correctamente]\n\n");
	printf("Fecha de la Cita: %d/%d/%d a las %d:%d\n", c[temp].day, c[temp].month, c[temp].year, c[temp].hora, c[temp].min);
	printf("ID del Paciente: %d\n", c[temp].idpaciente);
	printf("ID de la Cita: %d\n\n", c[temp].id);
}

void borrarCita(Cita c[]){
	int temp, i;
	printf("ID de la Cita a eliminar: ");
	scanf("%d", &temp);
	system("cls");
	
	printf("[Se ha eliminado la cita correctamente]\n\n");
	printf("Fecha de la Cita: %d/%d/%d\n", c[temp].day, c[temp].month, c[temp].year);
	printf("ID del Paciente: %d\n", c[temp].idpaciente);
	printf("ID de la Cita: %d\n\n", c[temp].id);
	
	c[temp].year = -1;
	c[temp].month = -1;
	c[temp].day = -1;
	c[temp].hora = -1;
	c[temp].min = -1;
	c[temp].idpaciente = -1;
	c[temp].id = -1;
	
}

void mostrarPacientes(Paciente p[], int *contador){
	int i;
	for(i=0; i<*contador; i++){
		if(p[i].id > 0){
			printf("[ID Paciente: %d]", p[i].id);
			printf("\nNombre del Paciente: %s", p[i].nombre);
			printf("\nApellido del Paciente: %s", p[i].apellido);
			printf("\nDNI del Paciente: %s", p[i].dni);
			printf("\nFecha Nacimiento: %d/%d/%d\n\n", p[i].day, p[i].month, p[i].year);	
		}
	}
}

void mostrarCitas(Cita c[], int *contador2){
	int i;
	for(i=0; i<*contador2; i++){
		if(c[i].id >= 0 && c[i].id < 50){
			printf("[ID Cita: %d]", c[i].id);
			printf("\nID del Paciente: %d", c[i].idpaciente);
			printf("\nFecha de la Cita: %d/%d/%d a las %d:%d\n\n", c[i].day, c[i].month, c[i].year, c[i].hora, c[i].min);
		}
	}
}

int main() {
	int opc;
	int contador = 1, contador2 = 1;
	Paciente p[50];
	Cita c[50];
	
	strcpy(p[0].nombre, "Javier");
	strcpy(p[0].apellido, "Jimenez");
	strcpy(p[0].dni, "83749510F");
	p[0].year = 2006;
	p[0].month = 12;
	p[0].day = 4;
	p[0].id = 0;
	
	c[0].year = 2025;
	c[0].month = 3;
	c[0].day = 28;
	c[0].hora = 10;
	c[0].min = 15;
	c[0].idpaciente = 0;
	c[0].id = 0;
	
	do{
		opc = pintarMenu();
		
		if(opc == 1){
			altaPaciente(&contador, p);
		} else if(opc == 2){
			altaCita(&contador2, c);
		} else if(opc == 3){
			modificarCita(c);
		} else if(opc == 4){
			borrarCita(c);
		} else if(opc == 5){
			mostrarPacientes(p, &contador);
		} else if(opc == 6){
			mostrarCitas(c, &contador2);
		}
	} while(opc > 0 && opc < 7);
	
	printf("Saliendo del programa...\n");
	return 0;
}
