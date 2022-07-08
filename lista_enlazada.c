#include <stdio.h>
#include <stdlib.h>

#include "lista_enlazada.h" 

/**
 *
 */
struct lista_enlazada* crear_lista(){

	struct lista_enlazada* nueva_lista = calloc(1, sizeof(struct lista_enlazada));
	return nueva_lista;
}


/**
 *
 */
struct nodo* crear_nodo(){

	struct nodo* nuevo_nodo = calloc(1, sizeof(struct nodo));
	return nuevo_nodo;
}


/**
 *
 */
int imprimir_lista(struct lista_enlazada* lista){

	// Seccion para definir variables
	struct nodo* actual = NULL;

	// Validaciones =*=
	
	// Lista nula
	if (lista == NULL){
		printf("Lista NULL\n");
		return -1;
	}

	// Lista vacia
	if (lista->inicio == NULL){
		printf("Lista vacía\n");
		return -2;
	}

	// pongo un apuntador adicional al inicio.
	actual = lista->inicio;

	while (actual != NULL){

		printf("%d -> \t", actual->valor);
		actual = actual->siguiente;
	}

	printf("\n");
	return 0;
}

/**
 *
 */
struct nodo* buscar_elemento(struct lista_enlazada* lista, int elem){

	struct nodo* actual = NULL;

	// validaciones
	if (lista == NULL || lista->inicio == NULL){
		return NULL;
	}

	actual = lista->inicio;

	while (actual != NULL){

		if (actual->valor == elem){
			return actual;
		}

		actual = actual->siguiente;
	}

	return NULL;
}

/**
 *
 */
struct lista_enlazada* insertar_inicio(struct lista_enlazada* lista, int elem){

	// Definicion de variables
	struct nodo* nuevo_nodo = NULL;
	struct nodo* actual = NULL;
	
	// validaciones
	if (lista == NULL){
		return NULL;
	}

	// Crear el nodo y asignarle el valor
	nuevo_nodo = crear_nodo();
	nuevo_nodo->valor = elem;

	// Si la lista esta vacia
	if (lista->inicio == NULL){

		lista->inicio = nuevo_nodo;

	}else{ // La lista no esta vacia

		nuevo_nodo->siguiente = lista->inicio;
		lista->inicio = nuevo_nodo;
		}

	return lista;
}

/**
 * Inserta el nuevo nodo al final de la lista
 */
struct lista_enlazada* insertar_final(struct lista_enlazada* lista, int elem){


	struct nodo* nuevo_nodo = NULL;
	struct nodo* actual = NULL;
	

	if (lista == NULL){
		return NULL;
	}

	nuevo_nodo = crear_nodo();
	nuevo_nodo->valor = elem;

	// Caso 1: Si la lista esta vacia
	if (lista->inicio == NULL){

		lista->inicio = nuevo_nodo;
		return lista;
	}

	// Caso 2: Si la lista no esta vacia
	actual = lista->inicio;

	while (actual->siguiente != NULL){
		actual = actual->siguiente;
	}

	actual->siguiente = nuevo_nodo;

	return lista;
}

int eliminar_lista(struct
		lista_enlazada* lista){

	struct nodo* actual = NULL;
	struct nodo* anterior = NULL;

	if (lista == NULL){
			return -1;
	}

	actual = lista->inicio;

	while(actual != NULL){
		anterior = actual;
		actual = actual->siguiente;

		free(anterior);
		anterior = NULL;
	}

	free(lista);
	lista = NULL;

	return 0;
}
	

/**
 * Inserta el nuevo nodo al final de la lista
 */
struct lista_enlazada* eliminar_elemento(struct lista_enlazada* lista, int elem){


	struct nodo* nuevo_nodo = NULL;
	struct nodo* actual = NULL;
	struct nodo* anterior = NULL;
	

	if (lista == NULL){
		return NULL;
	}

	nuevo_nodo = crear_nodo();
	nuevo_nodo->valor = elem;

	// Si la lista esta vacia
	if (lista->inicio == NULL){
		return NULL;
	}

	// Verifico el elemento al inicio
	actual = lista->inicio;
	 
	if (actual-> valor == elem){

		lista->inicio = actual->siguiente;
		free(actual);
		actual = NULL;

		return lista;
	}

	// No tengo que volver a verificar el primero
	anterior = actual;
	actual = actual->siguiente;

	// El elemento esta después del inicio
	while(actual != NULL){


		// elimino el elemento pq ya lo encontré
		if (actual->valor == elem){
			anterior->siguiente = actual->siguiente;
			free(actual);
			actual=NULL;

			return lista;
		}

		// paso al siguiente elemento
		anterior = actual;
		actual = actual->siguiente;
	}

	return NULL;
}

struct lista_enlazada* eliminar_primer_elemento(struct lista_enlazada* lista){
		
	struct nodo* actual = NULL; //Puntero apuntado a NULL

	actual = lista->inicio; //El puntero apunta al inicio de la lista enlazada
	//Se hace una conexión del inicio de la lista al segundo elemento del lista
	
	//Se salta el primer elemento por asi decirlo
	lista -> inicio = actual -> siguiente;
	free(actual); //Libera memoria
	actual = NULL; //Actual apunta a siguiente para evitar residuos en el código
	return lista;
}
	
struct lista_enlazada* eliminar_ultimo_elemento(struct lista_enlazada* lista){
	
	struct nodo* actual = NULL;
	struct nodo* anterior = NULL;

	actual = lista -> inicio;
	
	while(actual -> siguiente != NULL){
		// paso al siguiente elemento
		anterior = actual;
		actual = actual->siguiente;
	}
	// Se cambia la condicion para que sea si el siguiente es NULL se elimine el actual
	anterior->siguiente = NULL; // NULL por que es el ultimo digito

	return lista;
}
/**
 *Está función retorna la posición de un dato de una lista enlazada
 */

struct lista_enlazada* retornar_porsicion(struct lista_enlazada* lista, int elem){

	struct nodo* actual = NULL;
	int contador = 0;
	if(elem == 0){ //Es el primer elemento de la lista
		printf("La posición de %d: ", actual -> valor); //El valor de actual
		return 0;
	}

	while(actual != NULL){ //Diferente a NULL

		actual = actual -> siguiente;
		contador++; //El contador va sumandose
		
		if(contador == elem) // Si el contador es igual al elemento ya esta en la posicion que quieres
		{
			printf("La posición es %d:", actual->valor);
		}
	}
}

struct lista_enlazada* actualiza_por_indice(struct lista_enlazada* lista, int indice, int nuevo_valor){
	
	struct nodo* actual = NULL; //Puntero a NULL
	
	actual = lista-> inicio; //Actual se apunta a inicio

	int contador = 0; //Declarar un contador
	
	while(actual!= NULL){ //Actual diferente a NULL
		if (contador == indice){ // Si son iguales para todo el desorden
			actual -> valor = nuevo_valor; //El valor de actual se lo dan a nuevo_nodo
		}
		actual = actual -> siguiente; //Avanza en la lista en alzada 
		contador ++; //Aumenta el contador
	}
	return 0;
}

/**
 *Función para agregar un dato en una lista enlazada, pero ordenadamente
 *Ejemplo:
 * 1->2->4->NULL
 * Se agrega el 3: 
 * 1->2->3->4->NULL
*/
 
struct lista_enlazada* insertar_ordenado(struct lista_enlazada* lista, int elem){
	
	//Se crean dos punteros, me siento mas comodo asi
	struct nodo* actual = NULL;
	struct nodo* anterior = NULL;
	
	struct nodo* nuevo_nodo = NULL;

	
	if(lista == NULL){ //Si la lista esta vacia
		return NULL;
	}
	nuevo_nodo = crear_nodo(); //Se crea el nodo, en otras palabras la caja para meter el numero
	nuevo_nodo->valor = elem;  //A la caja se le asigna el valor que uno quiera
	
	if(lista -> inicio == NULL){
		lista->inicio = nuevo_nodo; 
		return lista;
	}
	
	actual = lista -> inicio;//Se define que es el actual
	
	while(actual != NULL){ //Actual diferente a NULL para que se haga el ciclo

		if(((actual->siguiente)->valor) > elem){
			nuevo_nodo -> siguiente = actual -> siguiente; //Concecto el lazo del elemento anterior al elemento
			actual -> siguiente = nuevo_nodo;   //Concecto el lazo del elemento nodo que esta adelante
			return lista;
		}
		//Se avanza al siguiente elemento si es el caso que no cumpla con la condicion del if
		anterior = actual;
		actual = actual -> siguiente;
	}
	return NULL;
}

int main(){

	struct nodo* resultado       = NULL;
	struct lista_enlazada* lista = crear_lista();

	imprimir_lista(lista);
	printf("------------------\n");

	insertar_inicio(lista, 1);
	insertar_inicio(lista, 2);
	insertar_inicio(lista, 3);
	insertar_inicio(lista, 4);
	insertar_inicio(lista, 5);

	imprimir_lista(lista);
	printf("------------------\n");
/*
	insertar_final(lista, 2);
	insertar_final(lista, 3);
	insertar_final(lista, 4);
	insertar_final(lista, 5);

	imprimir_lista(lista);

	printf("------------------\n");

	resultado = buscar_elemento(lista, 1);
	printf("Este es el resultado de la búsqueda 1: %d \n", resultado->valor);
	printf("------------------\n");
	
	resultado = buscar_elemento(lista, 9);
	printf("Este es el resultado de la búsqueda 2: %p\n", resultado);

	imprimir_lista(lista);
	printf(" Eliminar 2 ------------------\n");
	retornar_porsicion(lista, 2);
	imprimir_lista(lista);

	printf(" Eliminar 5 ------------------\n");
	retornar_porsicion(lista, 5);
	imprimir_lista(lista);

	printf(" Eliminar 5 ------------------\n");
	retornar_porsicion(lista, 5);
	imprimir_lista(lista);

	printf(" Eliminar 1 ------------------\n");
	retornar_porsicion(lista, 1);
	imprimir_lista(lista);

	printf(" Eliminar 4 ------------------\n");
	retornar_porsicion(lista, 4);
	imprimir_lista(lista);
*/
	insertar_ordenado(lista,2);
	imprimir_lista(lista);
	return 0;
}

