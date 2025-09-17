#include <stdio.h>
#include <stdlib.h>

/*
-Función que devuelva Verdadero o Falso si una lista enlazada contiene un dato int pasado por párametro de entrada
-Función que devuelva la suma de los datos enteros de una lista enlazada.
-Función que elimine el nodo de orden especificado por parámetro. (Ejemplo: EliminarNodoN(miLE,2); suprime el segundo nodo de la lista)
-Función que inserte un nodo en el orden especificado por parámetro. (Ejemplo: InsertarNodoN(miLE,2,7); inserta detrás del segundo nodo de la lista un nuevo nodo con un nuevo dato 7)
-Función que elimine la mitad final de una lista enlazada. (En caso de haber un numero de impar de nodos, se deja al programador decidir si eliminar o no el nodo central)
-Función que elimine la mitad inicial de una lista enlazada. (En caso de haber un numero de impar de nodos, se deja al programador decidir si eliminar o no el nodo central)
-Función que intercambie de posición el nodo inicial y el nodo final de una lista enlazada.
-Función que intercambie de posición dos nodos cuya posición venga dada por parámetros (Ejemplo: IntercambiarNodos(miLE,3,5); intercambia de posición los nodos tercero y quinto)
-Función que concatene dos listas enlazadas.
-Función que elimine los nodos de una lista enlazada que contengan un número par.
-Función que invierta el orden de los nodos de una lista enlazada.

-Función que invierta el orden de elementos de una pila.
-Función que extraiga el elemento del fondo de una pila.
-Función que mezcle intercaladamente el contenido de dos pilas.
-Función que intercambie el elemento del fondo de una pila con su cima.
-Función que solo permita introducir un elemento en la pila si ese elemento es la suma de los que ya están dentro.

-Función que adelante al último al primer lugar(cima) en una cola
-Función que retrase al primero al último lugar en una cola
-Función que, dada una cola, extraiga la mitad de atrás de dicha cola y la introduzca en una nueva.
-Dadas dos colas, integrar en una nueva sus elementos de forma intercalada. */

typedef struct nodo{ //ESTRUCTURA DE LA LISTA
	int dato; //DATO DEL ELEMENTO DE LA LISTA
	struct nodo *next; //DIRECCION DEL SIGUIENTE ELEMENTO 
}Nodo;

Nodo* AnadirNodo(Nodo *miLE, int d){ //FUNCION ANADIR ELEMENTO A LA LISTA
	Nodo *aux; //CREAMOS UN NODO EXTERNO
	
	aux = (Nodo*) malloc(sizeof(Nodo)); //AMPLIAMOS EL TAMANO DE LA LISTA
	aux->dato = d; //AGREGAMOS EL VALOR AL ELEMENTO DE LA LISTA
	aux->next = miLE; //AGREGAMOS LA DIRECCION DEL SIGUIENTE ELEMENTO
	
	return aux; //DEVOLVEMOS EL NODO AUX
}

void ImprimirLista(Nodo *lista) { //FUNCION QUE IMPRIME LA LISTA
    Nodo *aux = lista;
    
    while (aux != NULL) {
        printf("%d -> ", aux->dato);
        aux = aux->next;
    }
    printf("NULL\n");
}

int tieneDato(Nodo *miLE, int d){
	Nodo *aux = miLE;
	
	while(aux != NULL){
		if(aux->dato == d){
			return 1; //SI ENCUENTRA EL DATO DEVUELVE TRUE
		}
		aux = aux->next; //PASAMOS AL SIGUIENTE ELEMENTO SI EL ANTERIOR NO CONTIENE EL DATO A ENCONTRAR
	}
	
	return 0; //SI NO ENCUENTRA EL DATO DEVUELVE FALSO
}

int sumaLista(Nodo *miLE){
	Nodo *aux = miLE;
	int suma = 0;
	
	while(aux != NULL){
		suma += aux->dato;
		aux = aux->next;
	}
	
	return suma;
}

Nodo* eliminarElementoOrden(Nodo *miLE, int n) {
	int i;
	
    if(miLE == NULL || n <= 0) return miLE; //si introducen numero null o <=0 no modifica nada

    if(n == 1) { // casa en el que se introduce el primer elemento
        Nodo *temp = miLE;
        miLE = miLE->next;
        free(temp);
        return miLE;
    }

    Nodo *aux = miLE; // creamos nodo aux
    for(i = 1; aux != NULL && i < n - 1; i++) { //queremos eliminar el elemento en la posicion n asi q nos detenemos en n-1
        aux = aux->next; // vamos inctroduciendo el nodo por nodo hasta encontrar el deseado (n)
    }

    if(aux == NULL || aux->next == NULL) return miLE; // si no se encuentra el nodo no se cambia nada

    Nodo *temp = aux->next; // guardamos nodo en un aux
    aux->next = aux->next->next; //eliminamos el nodo y igualando la direccion del nodo siguiente al actual
    free(temp); //liberamos la memoria de temp
    return miLE; // devolvemos la lista enlazada
}

Nodo* insertarNodoEn(Nodo *miLE, int n, int d) {
	int i;
	
    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo)); //creas un nuevo nodo
    nuevo->dato = d; // el valor solicitado al usuario es introducido en el nodo
    nuevo->next = NULL; // inicializar el nodo siguiente a null

    if(n <= 0 || miLE == NULL) { // si el usuario introduce el primer nodo (si introduce negativo se considera 0)
        nuevo->next = miLE; // anadimos el nodo al principio de la lista
        return nuevo; // devolvemos el nodo (en la direccion de nuevo ahora se encuentra la lista enlazada)
    }

    Nodo *aux = miLE; //crear nuevo nodo
    for(i = 1; aux != NULL && i < n; i++) {// recorremos el nodo hasta n (introducido por el usuario)
        aux = aux->next;
    }

    if(aux == NULL) { // comprobacion de error
        free(nuevo);
        return miLE; // no se pudo insertar
    }

    nuevo->next = aux->next; // introduces la direccion del nodo anterior al nuevo nodo
    aux->next = nuevo; // y la direccion del nodo anterior es introducido en el nuevo nodo
    return miLE; // devuelves la lista
}

Nodo* eliminarMitadFinal(Nodo *miLE) {
	int i, eliminarDesde, total, sn;
    
    if(miLE == NULL || miLE->next == NULL) return miLE; // si la lista esta vacia o solo tiene un nodo devolvemos la lista

    total = 0; 
    Nodo *aux = miLE;
    while(aux != NULL) { // contamos cuantos nodos tiene la lista
        total++;
        aux = aux->next; // asi pasamos de nodo en nodo
    }
    
    if(total % 2 != 0){ // si el impar preguntamos si se desea eliminar el nodo central
    	printf("Desear eliminar nodo central? (0.Si | !0.No)\n---> ");
    	scanf("%d", &sn);
    	if(sn == 0){
    		total++; // de suma 1 en caso de si
		}
	}
	
	eliminarDesde = total / 2;

    aux = miLE; // copiamos la lista en un aux
    for(i = 1; i < eliminarDesde - 1; i++) { //recorremos la lista hasta el primer nodo a eliminar
        aux = aux->next;
    }
    
    Nodo *aEliminar = aux->next; //copiamos el la direccion de primer nodo a eliminar a otro nodo
    aux->next = NULL; //y borramos la direccion del primer nodo a eliminar 

    while(aEliminar != NULL) { //recorremos los nodos a eliminar hasta llegar al NULL
        Nodo *temp = aEliminar;
        aEliminar = aEliminar->next;
        free(temp);
    }

    return miLE; //devolvemos la lista por la mitad
}

Nodo* eliminarMitadInical(Nodo *miLE){
	int i, eliminarHasta, total, sn;
    
    if(miLE == NULL || miLE->next == NULL) return NULL; // si la lista esta vacia o solo tiene un nodo devolvemos la lista

    total = 0; 
    Nodo *aux = miLE;
    while(aux != NULL) { // contamos cuantos nodos tiene la lista
        total++;
        aux = aux->next; // asi pasamos de nodo en nodo
    }
    
    if(total % 2 != 0){ // si el impar preguntamos si se desea eliminar el nodo central
    	printf("Desear eliminar nodo central? (0.Si | !0.No)\n---> ");
    	scanf("%d", &sn);
    	if(sn == 0){
    		total++; // de suma 1 en caso de si
		}
	}
	
	eliminarHasta = total / 2;

    aux = miLE; // copiamos la lista en un aux
    Nodo *aEliminar = NULL;
    for(i = 0; i < eliminarHasta; i++) { //recorremos la lista hasta el primer nodo a eliminar
        aEliminar = aux->next;
        aux = aux->next;
        free(aEliminar);
    }

    return aux; //devolvemos la lista hasta la mitad
}	

Nodo* intercambiarExtremos(Nodo *miLE) {
    if (miLE == NULL || miLE->next == NULL) return miLE; // Lista vacía o de 1 nodo, nada que hacer

    Nodo *prevUltimo = NULL;
    Nodo *ultimo = miLE;

    // 1. Buscar el último nodo y su anterior
    while (ultimo->next != NULL) {
        prevUltimo = ultimo;
        ultimo = ultimo->next;
    }

    // 2. Si solo hay dos nodos, intercambiar es directo
    if (miLE->next == ultimo) {
        ultimo->next = miLE;
        miLE->next = NULL;
        return ultimo;
    }

    // 3. Si hay más de dos nodos:
    Nodo *segundo = miLE->next;

    // El anterior al último ahora debe apuntar al primero
    prevUltimo->next = miLE;

    // El último nodo se convierte en nuevo head, y apunta al segundo
    ultimo->next = segundo;

    // El antiguo primero ahora apunta a NULL (porque será el nuevo último)
    miLE->next = NULL;

    return ultimo; // Nuevo inicio de la lista
}

Nodo* intercambiarNodos(Nodo *miLE, int pos1, int pos2) {
    if (miLE == NULL || pos1 == pos2) return miLE;

    if (pos1 > pos2) { // siempre trabajamos con pos1 < pos2
        int temp = pos1;
        pos1 = pos2;
        pos2 = temp;
    }

    Nodo *prev1 = NULL, *prev2 = NULL;
    Nodo *curr1 = miLE, *curr2 = miLE;
    int i;

    // Buscar nodo en pos1
    for (i = 1; curr1 != NULL && i < pos1; i++) {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    // Buscar nodo en pos2
    for (i = 1; curr2 != NULL && i < pos2; i++) {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    if (curr1 == NULL || curr2 == NULL) return miLE; // posiciones inválidas

    // Si curr1 no es cabeza
    if (prev1 != NULL)
        prev1->next = curr2;
    else
        miLE = curr2;

    // Si curr2 no es cabeza
    if (prev2 != NULL && prev2 != curr1)
        prev2->next = curr1;
    else if (prev2 == curr1)
        prev2->next = curr1; // nodos consecutivos, nada cambia aquí

    // Intercambiar punteros next
    Nodo *temp = curr2->next;
    curr2->next = curr1->next;

    if (prev2 == curr1)
        curr1->next = curr2; // caso especial: consecutivos
    else
        curr1->next = temp;

    return miLE;
}

Nodo* concatenarListas(Nodo* lista1, Nodo* lista2) {
    if (lista1 == NULL) return lista2;  // Si la primera lista está vacía, devolvemos la segunda
    if (lista2 == NULL) return lista1;  // Si la segunda lista está vacía, devolvemos la primera

    Nodo* aux = lista1;
    while (aux->next != NULL) {         // Recorremos hasta el final de la primera lista
        aux = aux->next;
    }

    aux->next = lista2;                 // Enlazamos el último nodo de la primera con el inicio de la segunda

    return lista1;                      // Devolvemos la lista combinada
}

Nodo* eliminarPares(Nodo* miLE) {
    Nodo* aux = miLE;
    Nodo* anterior = NULL;

    while (aux != NULL) {
        if (aux->dato % 2 == 0) {  // Si el dato es par
            Nodo* temp = aux;
            if (anterior == NULL) {
                // Eliminamos el nodo cabeza
                miLE = aux->next;
                aux = miLE;
            } else {
                // Eliminamos un nodo intermedio o final
                anterior->next = aux->next;
                aux = aux->next;
            }
            free(temp);
        } else {
            // Avanzamos normalmente
            anterior = aux;
            aux = aux->next;
        }
    }

    return miLE;
}

Nodo* invertirLista(Nodo* miLE) {
    Nodo* anterior = NULL;
    Nodo* actual = miLE;
    Nodo* siguiente = NULL;

    while (actual != NULL) {
        siguiente = actual->next;   // Guardamos el siguiente nodo
        actual->next = anterior;    // Invertimos el puntero
        anterior = actual;          // Avanzamos 'anterior'
        actual = siguiente;         // Avanzamos 'actual'
    }

    return anterior;  // 'anterior' es la nueva cabeza
}

int main() {
	int opc, numero, valor;
	Nodo *listaE = NULL;
	
	listaE = AnadirNodo(listaE, 9);
	listaE = AnadirNodo(listaE, 5);
    listaE = AnadirNodo(listaE, 3);
		
    do{
    	printf("Que deseas hacer\n1. Esta el dato en la lista?\n2. Suma de la lista\n3. Eliminar elemento por su orden\n4. Insertar un elemento detras de otro elemento\n5. Eliminar la mitad de la lista final\n6. Eliminar la mitad de la lista inicial\n7. Cambiar el primer elemento por el ultimo\n8. Intercambiar un elemento por otro a elegir\n9. Juntar dos listas enlazadas\n10. Eliminar elemento con datos pares\n11. Invertir orden de la lista enlazada\n---> ");
	    scanf("%d", &opc);
	    
	    system("cls");
	    
	    if(opc == -1){
	    	ImprimirLista(listaE);
	    	
		} else if(opc == 0){
	    	printf("Dame numero a anadir\n---> ");
	    	scanf("%d", &numero);
	    	
	    	listaE = AnadirNodo(listaE, numero);
	    	
		} else if(opc == 1){
	    	printf("Dame numero a buscar\n---> ");
	    	scanf("%d", &numero);
	    	
	    	if(tieneDato(listaE, numero)){
	    		printf("Verdadero");
			} else {
				printf("Falso");
			}
			
			printf(" (%d)\n", numero);
			
		} else if(opc == 2){
			numero = sumaLista(listaE);
			printf("La lista suma %d\n", numero);
			
		} else if(opc == 3){
			printf("Dame elemento a eliminar\n---> ");
	    	scanf("%d", &numero);
			
			listaE = eliminarElementoOrden(listaE, numero);
			
		} else if(opc == 4){
		    printf("Dame posicion donde insertar\n---> ");
		    scanf("%d", &numero);
		    printf("Dame valor a insertar\n---> ");
		    scanf("%d", &valor);
		    listaE = insertarNodoEn(listaE, numero, valor);
		    
		} else if(opc == 5){
			listaE = eliminarMitadFinal(listaE);
    		system("pause");
    		system("cls");
    		ImprimirLista(listaE);
    		
		} else if(opc == 6){ //MAL
			listaE = eliminarMitadFinal(listaE);
    		system("pause");
    		system("cls");
    		ImprimirLista(listaE);
    		
		} else if(opc == 7){ //MAL
			listaE = intercambiarExtremos(listaE);
			ImprimirLista(listaE);
			
		} else if(opc == 8){ // MAL AL PONER POSICIONES CONSECUTIVAS
			printf("Dame dos posiciones a intercambiar\n---> ");
		    scanf("%d %d", &numero, &valor);
		    listaE = intercambiarNodos(listaE, numero, valor);
		    ImprimirLista(listaE);
		    
		} else if(opc == 9){
			Nodo* listaExtra = NULL;
		    listaExtra = AnadirNodo(listaExtra, 100);
		    listaExtra = AnadirNodo(listaExtra, 200);
		    listaExtra = AnadirNodo(listaExtra, 300);
		    listaE = concatenarListas(listaE, listaExtra);
		    ImprimirLista(listaE);
		    
		} else if(opc == 10){
			listaE = eliminarPares(listaE);
			ImprimirLista(listaE);
			
		} else if(opc == 11){
			listaE = invertirLista(listaE);
			ImprimirLista(listaE);
			
		}
		
		else printf("ERROR\n");
		
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		system("pause");
		system("cls");
		
	} while(1);
    
	return 0;
}
