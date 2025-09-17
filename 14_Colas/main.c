#include <stdio.h>
#include <stdlib.h>

#define MAX 100
/* 
-Función que adelante al último al primer lugar(cima) en una cola
-Función que retrase al primero al último lugar en una cola
-Función que, dada una cola, extraiga la mitad de atrás de dicha cola y la introduzca en una nueva.
-Dadas dos colas, integrar en una nueva sus elementos de forma intercalada.
 */
 
typedef struct {
    int datos[MAX];
    int frente;
    int fin;
    int cantidad;
} Cola;

void inicializarCola(Cola *c) {
    c->frente = 0;
    c->fin = -1;
    c->cantidad = 0;
}

int colaVacia(Cola *c) {
    return c->cantidad == 0;
}

void enqueue(Cola *c, int valor) {
	if(c->cantidad == MAX){
		return;
	}
	
    c->fin = (c->fin + 1) % MAX;
    c->datos[c->fin] = valor;
    c->cantidad++;
}

void dequeue(Cola *c, int *valor) {
	if(c->cantidad == 0){
		return;
	}
	
    *valor = c->datos[c->frente]; 
    c->frente = (c->frente + 1) % MAX;
    c->cantidad--;
}


// Función para adelantar el último al primer lugar
void adelantarUltimoAlPrimero(Cola *c) {
    if (c->cantidad <= 1) return;

    int ultimo = c->datos[c->fin];
    c->fin = (c->fin - 1 + MAX) % MAX;
    c->frente = (c->frente - 1 + MAX) % MAX;
    c->datos[c->frente] = ultimo;
}

// Función para retrasar el primero al último lugar
void retrasarPrimeroAlUltimo(Cola *c) {
    if (c->cantidad <= 1) return;

    int primero = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->fin = (c->fin + 1) % MAX;
    c->datos[c->fin] = primero;
}

// Función que extrae la mitad trasera de la cola y la introduce en una nueva
void extraerMitadTrasera(Cola *origen, Cola *destino) {
	int i;
    if (origen->cantidad == 0) return;

    int mitad = origen->cantidad / 2;
    int total = origen->cantidad;

    // Inicializamos la cola destino
    destino->frente = 0;
    destino->fin = -1;
    destino->cantidad = 0;

    // Movemos los primeros elementos de la cola original al frente para no perderlos
    for (i = 0; i < total - mitad; i++) {
        retrasarPrimeroAlUltimo(origen);
    }

    // Ahora extraemos la mitad trasera y la metemos en destino
    int valor;
    for (i = 0; i < mitad; i++) {
        valor = origen->datos[origen->frente];
        origen->frente = (origen->frente + 1) % MAX;
        origen->cantidad--;

        // Agregamos a la cola destino
        destino->fin = (destino->fin + 1) % MAX;
        destino->datos[destino->fin] = valor;
        destino->cantidad++;
    }
}

// Función que intercalan dos colas en una nueva
void intercalarColas(Cola *c1, Cola *c2, Cola *cFinal) {
    // Inicializamos la cola resultado
    cFinal->frente = 0;
    cFinal->fin = -1;
    cFinal->cantidad = 0;

    int valor1, valor2;
    while (c1->cantidad > 0 || c2->cantidad > 0) {
        if (c1->cantidad > 0) {
            valor1 = c1->datos[c1->frente];
            c1->frente = (c1->frente + 1) % MAX;
            c1->cantidad--;

            cFinal->fin = (cFinal->fin + 1) % MAX;
            cFinal->datos[cFinal->fin] = valor1;
            cFinal->cantidad++;
        }
        if (c2->cantidad > 0) {
            valor2 = c2->datos[c2->frente];
            c2->frente = (c2->frente + 1) % MAX;
            c2->cantidad--;

            cFinal->fin = (cFinal->fin + 1) % MAX;
            cFinal->datos[cFinal->fin] = valor2;
            cFinal->cantidad++;
        }
    }
}


void imprimirCola(Cola *c) {
	int i, j;
	
    if(c->cantidad == 0) {
        printf("Cola vacia\n");
        return;
    }

    i = c->frente;
    
    for(j = 0; j < c->cantidad; j++) {
        printf("%d ", c->datos[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
	int opc;
	Cola c, c2, resultado;
	
	inicializarCola(&c);
	inicializarCola(&c2);
    inicializarCola(&resultado);
    enqueue(&c, 10);
    enqueue(&c, 20);
    enqueue(&c, 30);
    enqueue(&c, 40);
    enqueue(&c2, 100);
    enqueue(&c2, 200);
    enqueue(&c2, 300);
	
	printf("1. Adelantar el ultimo al primer lugar\n2. Retrasar el primero al ultimo lugar\n3. Introducir la mitad final en otra cola\n4. Intercalar dos colas\n---> ");
	scanf("%d", &opc);
	
	if(opc == 1){
		printf("Cola original: ");
        imprimirCola(&c);
        adelantarUltimoAlPrimero(&c);
        printf("Cola modificada: ");
        imprimirCola(&c);
    
	} else if(opc == 2){
		printf("Cola original: ");
        imprimirCola(&c);
        retrasarPrimeroAlUltimo(&c);
        printf("Cola modificada: ");
        imprimirCola(&c);
        
	} else if(opc == 3){
		printf("Cola original: ");
        imprimirCola(&c);
        extraerMitadTrasera(&c, &resultado);
        printf("Mitad trasera extraida: ");
        imprimirCola(&resultado);
        printf("Cola original actualizada: ");
        imprimirCola(&c);
        
	} else if(opc == 4){
		printf("Cola 1: ");
        imprimirCola(&c);
        printf("Cola 2: ");
        imprimirCola(&c2);
        intercalarColas(&c, &c2, &resultado);
        printf("Cola intercalada: ");
        imprimirCola(&resultado);
        
	}
	return 0;
}
