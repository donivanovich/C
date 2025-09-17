#include <stdio.h>

int main() {
    double espacio, tiempo, velocidad;
    double sumaEspacio = 0, sumaTiempo = 0, sumaVelocidad = 0;
    int contadorEspacio = 0, contadorTiempo = 0, contadorVelocidad = 0;
    double mediaEspacio, mediaTiempo, mediaVelocidad;
    int opcion, seguir;

    do {
    	
    	system("cls");
    	
        printf("Que dos variables tienes?\n");
        printf("1. ESPACIO Y TIEMPO\n");
        printf("2. TIEMPO Y VELOCIDAD\n");
        printf("3. VELOCIDAD Y ESPACIO\n");
        do{
	        printf("Elige una opcion: ");
	        scanf("%d", &opcion);
		}while(opcion < 1 || opcion > 3);
		system("cls");
		
        switch (opcion) {
            case 1:
                printf("Dame el espacio en metros: ");
                scanf("%lf", &espacio);
                printf("Dame el tiempo en segundo: ");
                scanf("%lf", &tiempo);

                if (tiempo > 0) {
                    velocidad = espacio / tiempo;
                    printf("\nVelocidad = %.2lf m/s\n", velocidad);
                } else {
                    printf("\nError, el tiempo no puede ser 0\n");
                    continue;
                }

                sumaVelocidad += velocidad;
                contadorVelocidad++;
                break;

            case 2:
                printf("Dame el tiempo en segundos: ");
                scanf("%lf", &tiempo);
                printf("Dame la velocidad en m/s: ");
                scanf("%lf", &velocidad);

                espacio = velocidad * tiempo;
                printf("\nEspacio = %.2lf metros\n", espacio);

                sumaEspacio += espacio;
                contadorEspacio++;
                break;

            case 3:
                printf("Dame el espacio en metros: ");
                scanf("%lf", &espacio);
                printf("Dame la velocidad en m/s: ");
                scanf("%lf", &velocidad);

                if (velocidad > 0) {
                    tiempo = espacio / velocidad;
                    printf("\nTiempo = %.2lf en segundos\n", tiempo);
                } else {
                    printf("\nError, la velocidad no puede ser 0\n");
                    continue;
                }

                sumaTiempo += tiempo;
                contadorTiempo++;
                break;
        }

        printf("\nMedias:\n");

        if (contadorEspacio > 0) {
            mediaEspacio = sumaEspacio / contadorEspacio;
            printf("Media del Espacio: %.2lf metros\n", mediaEspacio);
        }
        if (contadorTiempo > 0) {
            mediaTiempo = sumaTiempo / contadorTiempo;
            printf("Media del Tiempo: %.2lf segundos\n", mediaTiempo);
        }
        if (contadorVelocidad > 0) {
            mediaVelocidad = sumaVelocidad / contadorVelocidad;
            printf("Media de la Velocidad: %.2lf m/s\n", mediaVelocidad);
        }

        do {
            printf("\nQuieres seguir calculando? (0 = si, 1 = no): ");
            scanf("%d", &seguir);
        } while (seguir < 0 || seguir > 1);

    } while (seguir == 0);

    return 0;
}
