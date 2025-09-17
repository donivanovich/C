#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

/* 
v1.0
En un mundo circular y bidimensional de 10 x 10, un robot comienza en una posición dada por el usuario.
-El robot, puede moverse en las direcciones: norte, sur, este y oeste.
-El robot comienza con 100 unidades de gasolina.
-Cada vez que se mueve una casilla gasta 10 unidades de gasolina.
-Aleatoriamente, aparece en otra posición del mapa, un bidón de gasolina. Cada vez que el robot tome el bidón, recarga a 100 su depósito de gasolina.

-Se debe imprimir un mapa en caracteres ASCII indicando la posición del robot, así como una interfaz rudimentaria que muestre la posición, la gasolina restante y las opciones de movimiento al usuario.

BONUS(v2.0)
-Implementar el programa utilizando arrays

v3.0
Reimplementar el mundo circular del robot con las condiciones de la versión anterior añadiendo las siguientes características:
-ACCION DE "DASH": Añadir una opción en el movimiento (H), que desplace 4 casillas al robot en la última dirección seleccionada consumiendo 20 unidades de gasolina.
-REALIZAR ENCAPSULACION EN FUNCIONES siempre que se pueda y al nivel en el que estamos (solo paso por valor)
-MINA DE PROXIMIDAD (usar caracter '*'): Similar al Bidon, aparece aleatoriamente en el mapa una mina explosiva. Si el robot pasa por las 8 casillas de alrededor de la mina, esta explota quitándole el 50% de su gasolina restante (si quedan 10 unidades, lo destruye) y la mina 
aparece de nuevo aleatoriamente en otro punto del mapa.
Nota: el DASH puede saltar por encima de la mina sin recibir daño si el robot no cae en su zona de influencia
USAR MEMORIA DINAMICA */
typedef struct {
    char **mapa;
    int posx, posy, columnas, filas;
    float gasolina;
    char mov;
    char dir;  // antes: ultima_direccion
} Robot;

typedef struct {
    int posx, posy;
} Bidon;

typedef struct {
    int posx, posy;
} Mina;

void InicializarMapa(Robot *r, Bidon *b, Mina *m) {
    int i, j;

    printf("Filas del mapa (X): ");
    do {
        scanf("%d", &r->filas);   	
    } while (r->filas < 5);

    printf("Columnas del mapa (Y): ");
    do {
        scanf("%d", &r->columnas);   	
    } while (r->columnas < 5);

    r->mapa = (char**) malloc(r->columnas * sizeof(char*)); 
    for (i = 0; i < r->columnas; i++) {
        r->mapa[i] = (char*) malloc(r->filas * sizeof(char));
    }

    for (i = 0; i < r->columnas; i++) {
        for (j = 0; j < r->filas; j++) {
            r->mapa[i][j] = ' ';
        }
    }

    system("cls"); 

    printf("Posicion Y del Robot (Columnas): ");
    do {
        scanf("%d", &r->posy);
    } while (r->posy <= 0 || r->posy > r->columnas);  
    r->posy--;

    printf("Posicion X del Robot (Filas): ");
    do {
        scanf("%d", &r->posx);
    } while (r->posx <= 0 || r->posx > r->filas); 
    r->posx--;  

    r->mapa[r->posy][r->posx] = 'R';  
    r->gasolina = 100;
    r->dir = 'w';

    system("cls"); 

    do {
        m->posx = rand() % r->filas;
        m->posy = rand() % r->columnas;
    } while ((m->posx == r->posx && m->posy == r->posy));

    r->mapa[m->posy][m->posx] = '*';
    
    do {
	    b->posx = rand() % r->filas;
	    b->posy = rand() % r->columnas;
	} while (
	    (b->posx == r->posx && b->posy == r->posy) || 
	    (
	        ((b->posx + r->filas) % r->filas) >= ((m->posx - 1 + r->filas) % r->filas) &&
	        ((b->posx + r->filas) % r->filas) <= ((m->posx + 1 + r->filas) % r->filas) &&
	        ((b->posy + r->columnas) % r->columnas) >= ((m->posy - 1 + r->columnas) % r->columnas) &&
	        ((b->posy + r->columnas) % r->columnas) <= ((m->posy + 1 + r->columnas) % r->columnas)
	    )
	);
	
	r->mapa[b->posy][b->posx] = 'B';
}

void PintarMapa(Robot *r) {
    int i, j;
    system("cls");

    for(i = 0; i < r->columnas; i++) {
        for(j = 0; j < r->filas; j++) {
            printf("[%c]", r->mapa[i][j]);
        }
        printf("\n");
    }
    printf("Gasolina restante: %0.0f\n", r->gasolina);
}

void Ronda(Robot *r, Bidon *b, Mina *m) {
	int dx, dy;
	
    r->mapa[r->posy][r->posx] = ' ';  
    r->mov = getch();

    if (r->mov == 'h' || r->mov == 'H') {
        if (r->dir == 'w') {
            r->posy = (r->posy + r->columnas - 4) % r->columnas;
        } else if (r->dir == 's') {
            r->posy = (r->posy + 4) % r->columnas;
        } else if (r->dir == 'a') {
            r->posx = (r->posx + r->filas - 4) % r->filas;
        } else if (r->dir == 'd') {
            r->posx = (r->posx + 4) % r->filas;
        }
        r->gasolina -= 20;
    } else {
        if (r->mov == 'w' || r->mov == 'W') {
            r->dir = 'w';
            r->posy = (r->posy + r->columnas - 1) % r->columnas;
        } else if (r->mov == 's' || r->mov == 'S') {
            r->dir = 's';
            r->posy = (r->posy + 1) % r->columnas;
        } else if (r->mov == 'a' || r->mov == 'A') {
            r->dir = 'a';
            r->posx = (r->posx + r->filas - 1) % r->filas;
        } else if (r->mov == 'd' || r->mov == 'D') {
            r->dir = 'd';
            r->posx = (r->posx + 1) % r->filas;
        }
        r->gasolina -= 10;
    }

    if (r->posx == b->posx && r->posy == b->posy) {
        r->gasolina = 100;

        do {
		    b->posx = rand() % r->filas;
		    b->posy = rand() % r->columnas;
		} while (
		    (b->posx == r->posx && b->posy == r->posy) || // No sobre el robot
		    (
		        // Evita las 9 posiciones alrededor (y sobre) la mina
		        ((b->posx + r->filas) % r->filas) >= ((m->posx - 1 + r->filas) % r->filas) &&
		        ((b->posx + r->filas) % r->filas) <= ((m->posx + 1 + r->filas) % r->filas) &&
		        ((b->posy + r->columnas) % r->columnas) >= ((m->posy - 1 + r->columnas) % r->columnas) &&
		        ((b->posy + r->columnas) % r->columnas) <= ((m->posy + 1 + r->columnas) % r->columnas)
		    )
		);
		
		r->mapa[b->posy][b->posx] = 'B';
    }

    dx = abs(r->posx - m->posx);
    dy = abs(r->posy - m->posy);
    if (dx > r->filas / 2) dx = r->filas - dx;
    if (dy > r->columnas / 2) dy = r->columnas - dy;

    if (dx <= 1 && dy <= 1) {
    	r->mapa[m->posy][m->posx] = ' ';
    	
        if (r->gasolina <= 10) {
            r->gasolina = 0;
        } else {
            r->gasolina /= 2;
        }

        do {
            m->posx = rand() % r->filas;
            m->posy = rand() % r->columnas;
        } while ((m->posx == r->posx && m->posy == r->posy) || (m->posx == b->posx && m->posy == b->posy));

        r->mapa[m->posy][m->posx] = '*';
    }

    r->mapa[r->posy][r->posx] = 'R';
}

int main() {
    Robot r;
    Bidon b;
    Mina m;
    int i;

    srand(time(NULL));

    do {
        InicializarMapa(&r, &b, &m);

        while (r.gasolina > 0) {
            PintarMapa(&r);
            Ronda(&r, &b, &m);
        }

        printf("\nEl robot se ha quedado sin gasolina\n");
        system("pause");
        system("cls");

        for (i = 0; i < r.columnas; i++) {
            free(r.mapa[i]);
        }
        free(r.mapa);

    } while (1);

    return 0;
}
