#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/* Implementar un programa para 2 jugadores humanos donde dos dinosaurios luchan en un sistema de turnos clasico.
Los dinosaurios (su estructura raíz) deben ser declarados con su propio Tipo de Dato y contar con un nombre y una vida inicial.
Cada turno el jugador puede decidir entre 1)Morder o 2)Huir.
Huir da la victoria al contrario directamente.
Morder provoca en el contrario la pérdida de 10 puntos de vida.

Obligatorio el uso funciones para el Mordisco y el pintado del menú de combate. */

// sleep(3); 3 segundos y borra el cmd

typedef struct dinos{
	char name[20];
	int hp;
	int movimiento;
	int energia;
	int defensa;
	int ataque;
	int agilidad;
	bool huida;
} Dinos;

typedef struct habilidad{
	int id_habilidad; 
	char nombre_habilidad[20];
	int parametro_modificable;
	int valor;
} Habilidad;

void NombrarDinos(Dinos *dino1, Dinos *dino2){
	printf("[Jugador1]\nIntroduce el nombre de tu dino\n---> ");
	scanf("%19s", dino1->name);
	system("cls");
	printf("[Jugador2]\nIntroduce el nombre de tu dino\n---> ");
	scanf("%19s", dino2->name);
	system("cls");
}

void MovimientoD1(Dinos *dino1, Dinos *dino2){
	
	do{
		printf("[%s] {%d}\n1.Ataque\n2.Huir\n3.Habilidad\n4.Libra\n---> ", dino1->name, dino1->hp);
		scanf("%d", &dino1->movimiento);
		system("cls");
		
		if(dino1->movimiento == 4){
			printf("[%s]\nHP: %d\nEnergia: %d\nDefensa: %d\nAtaque: %d\nAgilidad: %d\n\n", dino2->name, dino2->hp, dino2->energia, dino2->defensa, dino2->ataque, dino2->agilidad);
		}
		
	} while(dino1->movimiento < 1 || dino1->movimiento > 4 || dino1->movimiento == 4);

}

void MovimientoD2(Dinos *dino2, Dinos *dino1){
	do{
		printf("[%s] {%d}\n1.Ataque\n2.Huir\n3.Habilidad\n4.Libra\n---> ", dino2->name, dino2->hp);
		scanf("%d", &dino2->movimiento);
		system("cls");
		
		if(dino2->movimiento == 4){
			printf("[%s]\nHP: %d\nEnergia: %d\nDefensa: %d\nAtaque: %d\nAgilidad: %d\n\n", dino1->name, dino1->hp, dino1->energia, dino1->defensa, dino1->ataque, dino1->agilidad);
		}
		
	} while(dino2->movimiento < 1 || dino2->movimiento > 4 || dino2->movimiento == 4);
	
}

void Ronda(Dinos *dino1, Dinos *dino2, int *rondas, int *prioridad){
	dino1->energia = 1 + rand() % 10;
	dino1->defensa = 1 + rand() % 10;
	dino1->ataque = 1 + rand() % 10;
	dino2->energia = 1 + rand() % 10; 
	dino2->defensa = 1 + rand() % 10;
	dino2->ataque = 1 + rand() % 10;
	dino1->huida = false;
	dino2->huida = false;
	
	dino1->agilidad = 1 + rand() % 10;
    do {
        dino2->agilidad = 1 + rand() % 10;
    } while (dino2->agilidad == dino1->agilidad);
    
	printf("{RONDA %d}\n\n", *rondas);
	
	if(dino1->agilidad > dino2->agilidad){
		
		MovimientoD1(dino1, dino2);
			
		printf("{RONDA %d}\n\n", *rondas);
		
		MovimientoD2(dino2, dino1);
		
		*prioridad = 1;
	} else if(dino2->agilidad > dino1->agilidad) {
		
		MovimientoD2(dino2, dino1);
			
		printf("{RONDA %d}\n\n", *rondas);
	
		MovimientoD1(dino1, dino2);	
		
		*prioridad = 2;
	}
	
	
	if(dino1->movimiento == 1){
		dino2->hp -= 10;
	} else if(dino1->movimiento == 2){
		dino1->agilidad += 1 + rand() % 10;
	    do {
	        dino2->agilidad += 1 + rand() % 10;
	    } while (dino2->agilidad == dino1->agilidad);
	    
	    if(dino1->agilidad > dino2->agilidad){
	    	dino1->huida = true;
		}
	} else if(dino1->movimiento == 3){
		
	}
	
	if(dino2->movimiento == 1){
		dino1->hp -= 10;
	} else if(dino2->movimiento == 2){
		dino1->agilidad += 1 + rand() % 10;
	    do {
	        dino2->agilidad += 1 + rand() % 10;
	    } while (dino2->agilidad == dino1->agilidad);
	    
	    if(dino2->agilidad > dino1->agilidad){
	    	dino2->huida = true;
		}
	} else if(dino2->movimiento == 3){
		
	}
	(*rondas)++;
}

void Leyenda(Dinos *dino1, Dinos *dino2, int *rondas){
	printf("{RONDA %d}\n\n", *rondas);
	
	if(dino1->movimiento == 1){
		printf("[%s] {%d} Ha atacado\n", dino1->name, dino1->hp);
	} else if(dino1->movimiento == 2){
		printf("[%s] {%d} Ha huido\n", dino1->name, dino1->hp);
	}


	if(dino2->movimiento == 1){
		printf("[%s] {%d} Ha atacado\n", dino2->name, dino2->hp);
	} else if(dino2->movimiento == 2){
		printf("[%s] {%d} Ha huido\n", dino2->name, dino2->hp);
	}
	
	printf("\n");
	sleep(3);
	system("cls");
		
}

void DarGanador(Dinos *dino1, Dinos *dino2, int *prioridad){
	if(*prioridad == 2){
		if(dino1->huida == true || dino1->hp <= 0){
			printf("[%s] {%d} Ha ganado\n", dino2->name, dino2->hp);
		}
	}
	
	if(*prioridad == 1){
		if(dino2->huida == true || dino2->hp <= 0){
			printf("[%s] {%d} Ha ganado\n", dino1->name, dino1->hp);
		}
	}
	
}

int main() {
	srand(time(NULL));
	
	int prioridad, rondas = 1;
	Dinos dino1;
	Dinos dino2;
	
	dino1.hp = 100;
	dino2.hp = 100;
	NombrarDinos(&dino1, &dino2);
	
	do{
		
		Ronda(&dino1, &dino2, &rondas, &prioridad);
		Leyenda(&dino1, &dino2, &rondas);
		
	} while (dino1.hp > 0 && dino2.hp > 0 && !dino1.huida && !dino2.huida);
	
	DarGanador(&dino1, &dino2, &prioridad);
	return 0;
}
