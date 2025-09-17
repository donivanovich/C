#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define RESET_COLOR    "\x1b[0m" 
#define ROJO_F         "\x1b[41m" 
#define VERDE_T        "\x1b[32m" 
#define VERDE_F        "\x1b[42m" 
#define AMARILLO_T     "\x1b[33m" 

typedef struct Bosques{
	int altura;
	int ancho;
	int ft;
	int tc;
	int ca;
	int af;
	int tiempoActualizado;
}Bosque;

void Autocargado(FILE *fp, Bosque *b, char mapa[][20]){
	
	int i, j;
	char guardado;
	if(fp == NULL){
		ConfigurarBosque(b);
		InicializarMapa(mapa, *b);
	} else {
		do{
			printf("Se ha detectado una partida mediante el autoguardado\nDeseas cargarla?\n(1.SI | 2.NO)\n---> ");
			guardado = getch();
		} while(guardado != '1' && guardado != '2');
			
		system("cls");
		
		if(guardado == '2'){
			ConfigurarBosque(b);
			InicializarMapa(mapa, *b);
		} else if(guardado == '1'){
			fp = fopen("autoguardado.txt","r");
			
			if(fp == NULL){ // !fp
				printf("Ha habido algun error al intentar leer la simulacion ");
				sleep(1);
				system("cls");
			} else {
				fscanf(fp,"%d %d %d %d %d %d\n", &b->altura, &b->ancho, &b->af, &b->ft, &b->tc, &b->ca);
				
				for(i=0; i<b->altura; i++){
					for(j=0; j<b->ancho; j++){
						fscanf(fp, " [%c]", &mapa[i][j]);
					}
				}
				
				fclose(fp);
				printf(".");
				sleep(1);
				printf(".");
				sleep(1);
				printf(".");
				sleep(1);
				system("cls");
				printf("Se ha cargado la partida correctamente ");
				sleep(1);
				system("cls");
			}
		}
	}
}

void SimulacionBosque(Bosque *b, char mapa[][20], bool *fin, FILE *fp) {
    int opc;
    
    while (!kbhit()) {
        PintarMapa(mapa, *b);
        NuevoMapa(mapa, *b);
        ExtenderFuego(mapa, *b);
        Timer(&opc);
    }
    
    Opciones(fin, b, mapa, fp);
}

void Autoguardado(FILE *fp, Bosque *b, char mapa[][20]){
	
	int i, j;
	fp = fopen("autoguardado.txt","w");
	if(fp == NULL){ // !fp
	} else {
		fprintf(fp,"%d %d %d %d %d %d\n", b->altura, b->ancho, b->af, b->ft, b->tc, b->ca);
		
		for(i=0; i<b->altura; i++){
			for(j=0; j<b->ancho; j++){
				fprintf(fp, "[%c]", mapa[i][j]);
			}
			fprintf(fp, "\n");
		}
		
		fclose(fp);
		system("cls");
		printf("Gracias por jugar\n");
		printf("        ^\n");
	    printf("       ^^^\n");
	    printf("      ^^^^^\n");
	    printf("     ^^^^^^^\n");
	    printf("    ^^^^^^^^^\n");
	    printf("   ^^^^^^^^^^^\n");
	    printf("  ^^^^^^^^^^^^^\n");
	    printf("       |||\n");
	    printf("       |||\n");
		sleep(1);
	}
}

void InicializarMapa(char mapa[][20], Bosque b){
	int i, j;
	int random;
	
	for(i=0; i<b.altura; i++){
		for(j=0; j<b.ancho; j++){
			random = rand() % 4;
			
			if(random == 0){
				mapa[i][j] = 'A'; //ARBOL
			} else if(random == 1){
				mapa[i][j] = 'C'; //CESPED
			} else if(random == 2){
				mapa[i][j] = 'T'; //TIERRA
			} else if(random == 3){
				mapa[i][j] = 'F'; //FUEGO
			}
			
		}
	}
	
}

void ConfigurarBosque(Bosque *b){
	int altura, ancho, ft, tc, ca, af;

	system("cls");
	
	do{
		printf("Altura(1-20)\n---> ");
		scanf("%d", &altura);
		system("cls");
	} while (altura < 1 || altura > 20);
	b->altura = altura;
	
	do{	
		printf("Ancho(1-20)\n---> ");
		scanf("%d", &ancho);
		system("cls");
	} while (ancho < 1 || ancho > 20);
	b->ancho = ancho;
	
	do{	
		printf("Probabilidad de propagacion del fuego (1-100)\n---> ");
		scanf("%d", &af);
		system("cls");
	} while (af < 1 || af > 100);
	b->af = af;
		
	do{	
		printf("Probabilidad de extincion del fuego (1-100)\n---> ");
		scanf("%d", &ft);
		system("cls");
	} while (ft < 1 || ft > 100);
	b->ft = ft;
	
	do{	
		printf("Probabilidad de crecimiento de cesped (1-100)\n---> ");
		scanf("%d", &tc);
		system("cls");
	} while (tc < 1 || tc > 100);
	b->tc = tc;
	
	do{	
		printf("Probabilidad de cremiento de arboles (1-100)\n---> ");
		scanf("%d", &ca);
		system("cls");
	} while (ca < 1 || ca > 100);
	b->ca = ca;	
}

void PintarMapa(char mapa[20][20], Bosque b){
	int i, j;
	
	for(i=0; i<b.altura; i++){
		for(j=0; j<b.ancho; j++){
			
			if(mapa[i][j] == 'A'){
				printf(VERDE_F "[%c]" RESET_COLOR, mapa[i][j]);//ARBOL
				printf("  ");
			} else if(mapa[i][j] == 'C'){
				printf(VERDE_T "[%c]" RESET_COLOR, mapa[i][j]);//CESPED
				printf("  ");
			} else if(mapa[i][j] == 'T'){
				printf(AMARILLO_T "[%c]" RESET_COLOR, mapa[i][j]);//TIERRA
				printf("  ");
			} else if(mapa[i][j] == 'F'){
				printf(ROJO_F "[%c]" RESET_COLOR, mapa[i][j]);//FUEGO
				printf("  ");
			}
			
		}
		
		printf("\n\n");
	}
	printf("1.Salir\n2.Pausa\n3.Reconfigurar Bosque\n4.Cargar Simulacion\n5.Guardar Simulacion\n---> ");
}

void NuevoMapa(char mapa[][20], Bosque b){
	int i, j, random;
	
	for(i=0; i<b.altura; i++){
		for(j=0; j<b.ancho; j++){
			random = (rand() % 100) + 1;
			
			if(random >= 1 && random <= b.ca  && mapa[i][j] == 'C'){
				mapa[i][j] = 'A';
			} else if(random >= 1 && random <= b.tc  && mapa[i][j] == 'T'){
				mapa[i][j] = 'C';
			} else if(random >= 1 && random <= b.ft  && mapa[i][j] == 'F'){
				mapa[i][j] = 'T';
			}
		}
	}
}

void ExtenderFuego(char mapa[][20], Bosque b){
	int i, j, k, random;
    char nuevoMapa[20][20];
    
    memcpy(nuevoMapa, mapa, sizeof(nuevoMapa));
    
    for(i = 0; i < b.altura; i++){
        for(j = 0; j < b.ancho; j++){
            if(mapa[i][j] == 'F'){
                int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
                int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
                
                for(k = 0; k < 8; k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    
                    if(ni >= 0 && ni < b.altura && nj >= 0 && nj < b.ancho && mapa[ni][nj] == 'A'){
                        random = (rand() % 100) + 1;
                        if(random <= b.af){
                            nuevoMapa[ni][nj] = 'F';
                        }
                    }
                }
            }
        }
    }
    
    memcpy(mapa, nuevoMapa, sizeof(nuevoMapa));
}

void Timer(int *opc){
	int random = (rand() % 5) + 1;
	sleep(1);
	system("cls");
}

void Opciones(bool *fin, Bosque *b, char mapa[][20], FILE *fp){
	char opcion;
	
	do{
		opcion = getch();
	} while (opcion != '1' && opcion != '2' && opcion != '3' && opcion != '4' && opcion != '5');
		
	system("cls");
	if(opcion == '1'){
		*fin = true;
	} else if(opcion == '2'){
		PausaMapa(mapa, *b);
	} else if(opcion == '3'){
		ConfigurarBosque(b);
		InicializarMapa(mapa, *b);
	} else if(opcion == '4'){
		CargarSimulacion(&fp, *b, mapa);
	} else if(opcion == '5'){
		GuardarSimulacion(&fp, *b, mapa);
	}
}

void PausaMapa(char mapa[20][20], Bosque b){
	int i, j;
	
	for(i=0; i<b.altura; i++){
		for(j=0; j<b.ancho; j++){
			
			if(mapa[i][j] == 'A'){
				printf(VERDE_F "[%c]" RESET_COLOR, mapa[i][j]);//ARBOL
				printf("  ");
			} else if(mapa[i][j] == 'C'){
				printf(VERDE_T "[%c]" RESET_COLOR, mapa[i][j]);//CESPED
				printf("  ");
			} else if(mapa[i][j] == 'T'){
				printf(AMARILLO_T "[%c]" RESET_COLOR, mapa[i][j]);//TIERRA
				printf("  ");
			} else if(mapa[i][j] == 'F'){
				printf(ROJO_F "[%c]" RESET_COLOR, mapa[i][j]);//FUEGO
				printf("  ");
			}
			
		}
		
		printf("\n\n");
	}
	
	system("pause");
	system("cls");
}

void CargarSimulacion(FILE *fp, Bosque *b, char mapa[][20]){
	int i, j;
	fp = fopen("simulacion.txt","r");
	if(fp == NULL){ // !fp
		printf("Ha habido algun error al intentar leer la simulacion ");
		sleep(1);
		system("cls");
	} else {
		fscanf(fp,"%d %d %d %d %d %d\n", &b->altura, &b->ancho, &b->af, &b->ft, &b->tc, &b->ca);
		
		for(i=0; i<b->altura; i++){
			for(j=0; j<b->ancho; j++){
				fscanf(fp, " [%c]", &mapa[i][j]);
			}
		}
		
		fclose(fp);
		printf(".");
		sleep(1);
		printf(".");
		sleep(1);
		printf(".");
		sleep(1);
		system("cls");
		printf("Se ha cargado la partida correctamente ");
		sleep(1);
		system("cls");
	}
}

void GuardarSimulacion(FILE *fp, Bosque *b, char mapa[][20]){
	int i, j;
	fp = fopen("simulacion.txt","w");
	if(fp == NULL){ // !fp
		printf("Ha habido algun error al intentar grabar la simulacion ");
				sleep(1);
				system("cls");
	} else {
		fprintf(fp,"%d %d %d %d %d %d\n", b->altura, b->ancho, b->af, b->ft, b->tc, b->ca);
		
		for(i=0; i<b->altura; i++){
			for(j=0; j<b->ancho; j++){
				fprintf(fp, "[%c]", mapa[i][j]);
			}
			fprintf(fp, "\n");
		}
		
		fclose(fp);
		printf(".");
		sleep(1);
		printf(".");
		sleep(1);
		printf(".");
		sleep(1);
		system("cls");
		printf("Se ha guardado la partida correctamente ");
		sleep(1);
		system("cls");
	}
}

int main() {
	char mapa[20][20];
	bool fin = false;
	int opc;
	Bosque b;
	FILE *fp = NULL;
	
	srand(time(NULL));
	
	Autocargado(&fp, &b, mapa);
	
	do{
		SimulacionBosque(&b, mapa, &fin, fp);
	} while(!fin);
	
	Autoguardado(&fp, &b, mapa);
	
	return 0;
}
