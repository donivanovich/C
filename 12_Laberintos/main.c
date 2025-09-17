#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>

#define RESET_COLOR    "\x1b[0m"
#define ROJO_T         "\x1b[31m"
#define VERDE_T        "\x1b[32m"
#define AMARILLO_T     "\x1b[33m"
#define MAGENTA_T      "\x1b[35m"

/* Vamos ha desarrollar un programa que sea capaz de:
-Generar laberintos
-Editar laberintos
-Guardar en ficheros de texto dichos laberintos
-Cargar laberintos guardados
-Comprobar si un laberinto tiene solución
-Resolver laberintos con algoritmos devolviendo una ruta

La estructura de un laberinto debe contener un array bidimensional de caracteres cuyas celdas puedan tener valores: Pasillo (' '), Muro ('#'), una entrada ('E') y una salida ('S')
Tener en cuenta dentro de la estructura el tamanno de filas y columnas así como agregar un campo booleano llamado 'Modo Circular' que al activarse hace que el mapa actúe como un "mundo circular" 
(atravesar la fila del norte te saca por la sur, la columna del este te saca por el oeste, etc.)

La estructura de Ruta tiene que ser capaz de almacenar una colección de coordenadas de celdas que digan por donde han pasado desde la Entrada hasta la salida de un laberinto. */

typedef struct{
	char laberinto[10][10];
	int Sx, Sy;
	int Ex, Ey;
	int filas, columnas;
	char lugarS, lugarE;
	bool mundoCircular;
	bool esResolvible;
}Laberinto;

typedef struct {
    int x, y;
} Coordenada;

typedef struct {
    Coordenada *coordenadas;
    int tamanno;
} Ruta;

void cambiarTablero(Laberinto *l){
	int i, j, r;
	int randE, randS; //E == ENTRADA, S == SALIDA
	
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			r = rand() % 5;
			if(r >= 0 && r <= 2){
				l->laberinto[j][i] = ' ';
			} else if(r >=3 && r <= 4){
				l->laberinto[j][i] = '#';
			}	
		}
	}
	
	randE = rand() % 4;
	
	do{
		randS = rand() % 4;
	} while(randS == randE);
	
	
	if(randE == 0){//Norte
		l->Ex = (rand() % 6) + 2;
		l->Ey = 0;
		l->lugarE = 'N';
	} else if(randE == 1){//Sur
		l->Ex = (rand() % 6) + 2;
		l->Ey = 9;
		l->lugarE = 'S';
	} else if(randE == 2){//Oeste 
		l->Ex = 0;
		l->Ey = (rand() % 6) + 2;
		l->lugarE = 'O';
	} else if (randE == 3){//Este
		l->Ex = 9;
		l->Ey = (rand() % 6) + 2;
		l->lugarE = 'E';
	}
	
	if(randS == 0){//Norte
		l->Sx = (rand() % 6) + 2;
		l->Sy = 0;
		l->lugarS = 'N';
	} else if(randS == 1){//Sur
		l->Sx = (rand() % 6) + 2;
		l->Sy = 9;
		l->lugarS = 'S';
	} else if(randS == 2){//Oeste 
		l->Sx = 0;
		l->lugarS = 'O';
		l->Sy = (rand() % 6) + 2;
	} else if (randS == 3){//Este
		l->Sx = 9;
		l->lugarS = 'E';
		l->Sy = (rand() % 6) + 2;
	}
	
	l->laberinto[l->Ey][l->Ex] = 'E';
	l->laberinto[l->Sy][l->Sx] = 'S';
}

void pintarTablero(Laberinto *l){
	int i,j;
	
	for(i=0; i<10+2; i++){
		printf(AMARILLO_T "[#]" RESET_COLOR);
	}
	printf("\n");
	
	for(i=0; i<10; i++){
		printf(AMARILLO_T "[#]" RESET_COLOR);
		for(j=0; j<10; j++){
			if(l->laberinto[i][j] == 'E'){
				printf(VERDE_T "[%c]" RESET_COLOR, l->laberinto[i][j]);
			} else if(l->laberinto[i][j] == 'S'){
				printf(ROJO_T "[%c]" RESET_COLOR, l->laberinto[i][j]);
			} else if(l->laberinto[i][j] == '#'){
				printf(AMARILLO_T "[%c]" RESET_COLOR, l->laberinto[i][j]);
			} else {
				printf("[%c]", l->laberinto[i][j]);
			}
			
		}
		printf(AMARILLO_T "[#]" RESET_COLOR);
		printf("\n");
	}
	
	for(i=0; i<10+2; i++){
		printf(AMARILLO_T "[#]" RESET_COLOR);
	}
	printf("\n");
}

void generar(Laberinto *l){
	cambiarTablero(l);
	pintarTablero(l);
}

void editar(Laberinto *l){
	int mCircular;
	
	system("cls");
	
	printf("Filas\n---> ");
	do{
		scanf("%d", &l->filas);
	} while(l->filas < 6 || l->filas > 30);
	
	printf("Columnas\n---> ");
	do{
		scanf("%d", &l->columnas);
	} while(l->columnas < 6 || l->columnas > 30);
	
	printf("Activar Modo Circular (1.SI | 2.NO)\n---> ");
	do{
		scanf("%d", &mCircular);
	} while(mCircular < 1 || mCircular > 2);
	
	if(mCircular == 1){
		l->mundoCircular = true;
	} else {
		l->mundoCircular = false;
	}
	
	system("cls");
	
}

void guardar(Laberinto *l) {
    FILE *fp = fopen("laberinto.txt", "w");
    if (fp == NULL) {
        printf("Ha habido algun error al intentar grabar la simulacion\n");
        return;
    } else {
        int i, j;
        
         fprintf(fp, "10 10");
        
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                fprintf(fp, "[%c]", l->laberinto[i][j]);
            }
            fprintf(fp, "");
        }
        
        
        fclose(fp);
        
        printf("Guardado exitosamente.\n");
        sleep(1);
    }
}

void cargar(Laberinto *l) {
    FILE *fp = fopen("laberinto.txt", "r");
    if (fp == NULL) {
        printf("Ha habido algun error al intentar leer la simulacion\n");
        sleep(1);
        system("cls");
    } else {
        int i, j;
        
        fscanf(fp, "10 10");
        
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                fscanf(fp, "[%c]", &l->laberinto[i][j]);
            }
        }
        fclose(fp);
        printf("Cargado exitosamente.\n");
        sleep(1);
        pintarTablero(l);
    }
}

void comprobar(Laberinto *l){
	int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    bool visitado[30][30] = {false};
    Coordenada cola[900];
    int frente = 0, final = 0;
    int i;

    // Encontrar la posición de la entrada
    Coordenada entrada = {l->Ex, l->Ey};
    cola[final++] = entrada;
    visitado[entrada.y][entrada.x] = true;

    while (frente < final) {
        Coordenada actual = cola[frente++];

        // Si llegamos a la salida, el laberinto es resoluble
        if (actual.x == l->Sx && actual.y == l->Sy) {
            l->esResolvible = true;
            printf("El laberinto tiene solucion.\n");
            sleep(1);
            system("cls");
            return;
        }

        // Explorar los vecinos
        for (i = 0; i < 4; i++) {
            int nx = actual.x + dx[i];
            int ny = actual.y + dy[i];

            // Verificar si estamos en modo circular
            if (l->mundoCircular) {
                nx = (nx + l->columnas) % l->columnas;
                ny = (ny + l->filas) % l->filas;
            }

            // Verificar si el vecino es válido y no ha sido visitado
            if (nx >= 0 && nx < l->columnas && ny >= 0 && ny < l->filas &&
                l->laberinto[ny][nx] != '#' && !visitado[ny][nx]) {
                visitado[ny][nx] = true;
                cola[final++] = (Coordenada){nx, ny};
            }
        }
    }

    l->esResolvible = false;
    printf("El laberinto no tiene solucion.\n");
    sleep(1);
    system("cls");
}

void resolver(Laberinto *l){
	int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    bool visitado[30][30] = {false};
    Coordenada cola[900];
    int frente = 0, final = 0;
    Coordenada padre[30][30];
    int i;

    // Encontrar la posición de la entrada
    Coordenada entrada = {l->Ex, l->Ey};
    cola[final++] = entrada;
    visitado[entrada.y][entrada.x] = true;

    while (frente < final) {
        Coordenada actual = cola[frente++];

        // Si llegamos a la salida, reconstruir el camino
        if (actual.x == l->Sx && actual.y == l->Sy) {
            Ruta ruta;
            ruta.coordenadas = malloc(900 * sizeof(Coordenada));
            ruta.tamanno = 0;

            // Reconstruir el camino desde la salida hasta la entrada
            Coordenada actualCamino = actual;
            while (actualCamino.x != l->Ex || actualCamino.y != l->Ey) {
                ruta.coordenadas[ruta.tamanno++] = actualCamino;
                actualCamino = padre[actualCamino.y][actualCamino.x];
            }
            ruta.coordenadas[ruta.tamanno++] = entrada;

            // Invertir la ruta para que vaya de la entrada a la salida
            for (i = 0; i < ruta.tamanno / 2; i++) {
                Coordenada temp = ruta.coordenadas[i];
                ruta.coordenadas[i] = ruta.coordenadas[ruta.tamanno - i - 1];
                ruta.coordenadas[ruta.tamanno - i - 1] = temp;
            }

            // Marcar el camino en el laberinto
            for (i = 0; i < ruta.tamanno; i++) {
                if (l->laberinto[ruta.coordenadas[i].y][ruta.coordenadas[i].x] != 'E' &&
                    l->laberinto[ruta.coordenadas[i].y][ruta.coordenadas[i].x] != 'S') {
                    l->laberinto[ruta.coordenadas[i].y][ruta.coordenadas[i].x] = '.';
                }
            }

            // Mostrar el laberinto con la ruta
            pintarTablero(l);
            free(ruta.coordenadas);
            return;
        }

        // Explorar los vecinos
        for (i = 0; i < 4; i++) {
            int nx = actual.x + dx[i];
            int ny = actual.y + dy[i];

            // Verificar si estamos en modo circular
            if (l->mundoCircular) {
                nx = (nx + l->columnas) % l->columnas;
                ny = (ny + l->filas) % l->filas;
            }

            // Verificar si el vecino es válido y no ha sido visitado
            if (nx >= 0 && nx < l->columnas && ny >= 0 && ny < l->filas &&
                l->laberinto[ny][nx] != '#' && !visitado[ny][nx]) {
                visitado[ny][nx] = true;
                cola[final++] = (Coordenada){nx, ny};
                padre[ny][nx] = actual;
            }
        }
    }

    printf("No se pudo encontrar una solucion.\n");
    sleep(1);
    system("cls");
}

void opciones(bool *salir, Laberinto *l){
	char opc;
	printf("1. Generar\n2. Editar\n3. Guardar\n4. Cargar\n5. Comprobar\n6. Resolver\nPulsa Cualquier Tecla Para Salir\n---> ");
	opc = getch();
	if(opc == '1'){
		system("cls");
		generar(l);
	} else if(opc == '2'){
		editar(&l);
		system("cls");
	} else if(opc == '3'){
		system("cls");
		guardar(&l);
	} else if(opc == '4'){
		system("cls");
		cargar(&l);
	} else if(opc == '5'){
		system("cls");
		comprobar(&l);
	} else if(opc == '6'){
		system("cls");
		resolver(&l);
	} else {
		*salir = true;
	}
	
}

int main() {
	Laberinto l;
	bool salir = false;
	srand(time(NULL));
	
	do{
		opciones(&salir, &l);
	} while(!salir);
	
	return 0;
}
