#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_circular.h" 

struct lista_circular* crear_lista(){

	struct lista_circular* nueva_lista = calloc(1, sizeof(struct lista_circular));
	
	return nueva_lista;
}

struct nodo* crear_nodo(char* string){
	
	//La linea dice compa esta lista de caracteres tiene x largo, pero sumele 1 por el \0'
	int caracteres = strlen(string) + 1; 

	struct nodo* nuevo_nodo = calloc(1, sizeof(struct nodo)); //Tamaño del nodo
	
	nuevo_nodo -> valor = calloc(caracteres, sizeof(char));   //Reserva memoria para la cadena de caracteres
	
	strcpy(nuevo_nodo -> valor,string);                       //Copia lo que tenga    
	
	return nuevo_nodo;
}

struct lista_circular* imprimir_lista(struct lista_circular* lista){

	struct nodo* actual = NULL;
	
	// Lista nula
	if (lista == NULL){
		printf("Lista NULL, no existe\n");
		return 0;
	}

	// Lista vacia
	if (lista->final == NULL){
		printf("Lista vacía existe, pero no hay nada\n");
		return 0;
	}
		
	actual = (lista -> final) -> siguiente;
	
	do {

		printf("%s -> \t", actual->valor);
		actual = actual->siguiente;

	}
	while (actual != lista->final->siguiente);
	
	printf("\n");
	return 0;
}

struct lista_circular* insertar_inicio(struct lista_circular* lista, char* elem){
	
	// Se aputan estos punteros a NULL

	struct nodo* nuevo_nodo = NULL;
	
	//Se crea el nodo
	nuevo_nodo = crear_nodo(elem);
	
	if (lista == NULL){
		return NULL;
	}
	if (lista -> final == NULL){ // Lista vacia
		lista -> final = nuevo_nodo;
		nuevo_nodo -> siguiente = nuevo_nodo;

		
	}else{ // Lista no vacia
		nuevo_nodo -> siguiente = lista -> final -> siguiente;
		lista -> final -> siguiente = nuevo_nodo;
	}
	return lista;
}

struct lista_circular* insertar_final(struct lista_circular* lista, char* elem){
		
	struct nodo* nuevo_nodo = NULL;

	//Se crea el nodo
	nuevo_nodo = crear_nodo(elem);
	
	if (lista == NULL){
		return NULL;
	}
	
	// Si la lista esta vacia
	if (lista->final == NULL){

		lista->final = nuevo_nodo;
		nuevo_nodo->siguiente = nuevo_nodo;

	}else{ // La lista no esta vacia
		nuevo_nodo->siguiente = lista->final->siguiente;
		lista->final->siguiente = nuevo_nodo;
		lista->final = nuevo_nodo;
		
		}

	return lista;
}

int main(){
	struct nodo* resultado       = NULL;
	struct lista_circular* lista = crear_lista();
	printf("Verificar que este vacia \n");
	imprimir_lista(lista);
	printf("------------------\n");


	insertar_inicio(lista, "s");
	insertar_inicio(lista, "e");
	insertar_inicio(lista, "u");
	insertar_inicio(lista, "n");
	insertar_inicio(lista, "u");
	insertar_inicio(lista, "N");

	imprimir_lista(lista);
	printf("------------------\n");

	insertar_final(lista, "m");
	insertar_final(lista, "e");
	insertar_final(lista, "j");
	insertar_final(lista, "o");
	insertar_final(lista, "r");

	imprimir_lista(lista);
	printf("------------------\n");

	return 0;
}

