#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* 
-Función que invierta el orden de elementos de una pila.
-Función que extraiga el elemento del fondo de una pila.
-Función que mezcle intercaladamente el contenido de dos pilas.
-Función que intercambie el elemento del fondo de una pila con su cima.
-Función que solo permita introducir un elemento en la pila si ese elemento es la suma de los que ya están dentro.
 */
 
typedef struct{
	int dato[MAX];
	int tamano;
}Pila;

void push(Pila *p, int n){
	if(p->tamano >= MAX - 1) return;
	else {
		p->dato[++(p->tamano)] = n;
	}
}

int pop(Pila *p){
	if(p->tamano == -1) return -1;
	else {
		return p->dato[(p->tamano)--];
	}
}

void inicializarPila(Pila *p){
	p->tamano = -1;
	push(p, 23);
	push(p, 4);
	push(p, 78);
	push(p, 26);
}

void invertirOrden(Pila *p){
	int i, temp, j;
	
	j = p->tamano;
	
	for(i=0; i<j; i++){
		temp = p->dato[i];
		p->dato[i] = p->dato[j];
		p->dato[j] = temp;
		j--;
	}
}

void extraerUltimo(Pila *p){
	if(p->tamano == -1) return;
	
	int i;
	
	for(i=0; i< p->tamano; i++){
		p->dato[i] = p->dato[i + 1];
	}
	
	p->tamano--;
}

void mezclarPilas(Pila *p1, Pila *p2, Pila *pr){

	while (p1->tamano != -1 || p2->tamano != -1) {
		if (p1->tamano != -1) {
			push(pr, pop(p1));
		}
		if (p2->tamano != -1) {
			push(pr, pop(p2));
		}
	}

	invertirOrden(pr);
}

void cambiarPrimeroPorUltimo(Pila *p){
	int primero, ultimo;
	
	if (p->tamano <= 0) return;
	
	primero = p->dato[0];
	ultimo = p->dato[p->tamano];
	p->dato[0] = ultimo;
	p->dato[p->tamano] = primero;	
}

void introducirSoloSuma(Pila *p){
	int suma = 0, n, i;
	
	printf("Dame numero\n---> ");
	scanf("%d", &n);
	
	for(i=0; i<=p->tamano; i++){
		suma += p->dato[i];
	}
	
	if(n == suma){
		printf("Pila original:  ");
		imprimir(p);
		push(p, n);
		printf("Pila resultado: ");
		imprimir(p);
	} else {
		printf("La suma de la pila es %d y tu numero es %d\n", suma, n);
	}
	
}

void imprimir(Pila *p){
	int i;
	
	for(i=0; i<=p->tamano; i++){
		printf("%d ", p->dato[i]);
	}
	printf("\n");
}

int main() {
	int opc;
	Pila p, p2, pr;
	
	inicializarPila(&p);
	inicializarPila(&p2);
	pr.tamano = -1;
	
	printf("1. Invertir orden de elementos\n2. Extraer el elemento del fondo\n3. Mezclar intercaladamente el contenido de dos pilas\n4. Intercambiar el primero por el ultimo\n5. Solo permitir introducir la suma de toda la pila\n---> ");
	scanf("%d", &opc);
	
	if(opc == 1){
		printf("Pila original:  ");
		imprimir(&p);
		invertirOrden(&p);
		printf("Pila resultado: ");
		imprimir(&p);
		
	} else if(opc == 2){
		printf("Pila original:  ");
		imprimir(&p);
		extraerUltimo(&p);
		printf("Pila resultado: ");
		imprimir(&p);
		
	} else if(opc == 3){
		printf("Pila 1 original:  ");
		imprimir(&p);
		printf("Pila 2 original:  ");
		imprimir(&p2);
		mezclarPilas(&p, &p2, &pr);
		printf("Pila resultado: ");
		imprimir(&pr);
		
	} else if(opc == 4){
		printf("Pila original:  ");
		imprimir(&p);
		cambiarPrimeroPorUltimo(&p);
		printf("Pila resultado: ");
		imprimir(&p);
		
	} else if(opc == 5){
		introducirSoloSuma(&p);
	}
	
	return 0;
}
