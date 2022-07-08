/**
 * =========================================================================
 * 						   Proyecto Programado 2
 * =========================================================================
 */


/// Incluir librerias necesarias para el funcionamiento del codigo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>


#define V 14
#define MAX 50


/// Incluir structs del archivo: Progra2.h
#include "Proyecto2.h" 


/**
 * =========================================================================
 *                    Funcion para copiar el string
 * =========================================================================
 */
char* copiar_str(char* str){
	
	/**
	 * Se define el largo del string
	 */
	int len_texto = strlen(str);
	
	/**
	 * Se reserva el espacio de memoria en el HEAP
	 */
	char* mem_texto = (char*) calloc(len_texto, sizeof(char));
	
	/**
	 * Se leer todo el largo del string
	 */
	for (int i = 0; len_texto > i; i++){
		mem_texto[i] = str[i];
	}
	return mem_texto;
}

/**
 * =========================================================================
 *                  Funcion para buscar el Vertice
 * =========================================================================
 */
struct vertice* buscar_vertice (struct grafo* lista, int id) {
	
	/**
	 * Se define un puntero actual
	 */
	struct nodo_vertice* actual;
	
	/**
	 * El puntero actual apuntará a el inicio de la lista
	 */
	actual = lista->inicio;
	
	while (actual != NULL) {
		
		/**
		 * Si el puntero de id es igual al puntero que estamos buscando
		 * se retorna ese mismo puntero que contendrá el vertice
		 */
		if (actual->Vertice->id == id) {
			return actual->Vertice;
		}
		else {
			/**
			 * Sino sigue avanzado en lso vertices
			 */
			actual = actual->siguiente;
		}
	}
	
	printf("No se encontro el vertice");
	return NULL;
	
}

/**
 * =========================================================================
 *                       Funcion para push Cola
 * =========================================================================
 */
struct cola* push_cola(struct cola* Cola, struct vertice* vertice_insertar) {
	
	/**
	 * Declaracion del puntero actual
	 */
	struct nodo_vertice* actual;
	
	/**
	 * Se crea el nuevo nodo, reservando el espacio en memoria en el HEAP
	 */
	struct nodo_vertice* nuevo_nodo = calloc(1, sizeof(struct nodo_vertice));
	
	/**
	 * El nuevo nodo apuntará al vertice el cual el mismo se va a insertar
	 */
	nuevo_nodo->Vertice = vertice_insertar;
	
	/**
	 * Si el inicio de la cola es NULL
	 */
	if (Cola->inicio == NULL) {
		
		/**
		 * Se agrega el nodo
		 */
		Cola->inicio = nuevo_nodo;
		return Cola;
	}
	
	/**
	 * Si el inicio de la cola es NULL
	 */
	else if (Cola->final == NULL) {
		
		/**
		 * actual sera el inicio de la cola
		 */
		actual = Cola->inicio;
		
		/**
		 * actual apuntara a siguiente
		 */
		actual->siguiente = nuevo_nodo;
		
		/**
		 * Para meter en nuevo nodo
		 */
		Cola->final = nuevo_nodo;
		return Cola;
	}
	else {
		/**
		 * Si no se cumple con ninguna de las 
		 * precondiciones anteriores 
		 * acutal sera la cola apuntado al final
		 */
		actual = Cola->final;
		
		/**
		 * Se agrega el nuevo nodo en el campo de actual siguiente
		 */
		actual->siguiente = nuevo_nodo;
		Cola->final = nuevo_nodo;
		return Cola;
	}
}

/**
 * =========================================================================
 *                    Funcion POP Cola
 * =========================================================================
 */
struct vertice* pop_cola (struct cola* Cola) {
	/**
	 * Se define la variable actual
	 */ 
	struct nodo_vertice* actual;
	
	/**
	 * Apuntará al inicio de la cola
	 */
	actual = Cola->inicio;
	Cola->inicio = actual->siguiente;
	
	return actual->Vertice;
}

/**
 * =========================================================================
 *                    Funcion para push Pila
 * =========================================================================
 */
struct pila* push_pila (struct pila* Pila, struct vertice* vertice_insertar) {
	
	/**
	 * Declaracion del puntero actual
	 */
	struct nodo_vertice* actual;
	
	/**
	 * Se crea el nuevo nodo, reservando el espacio en memoria en el HEAP
	 */
	struct nodo_vertice* nuevo_nodo = calloc(1, sizeof(struct nodo_vertice));
	
	/**
	 * El nuevo nodo apuntará al vertice el cual el mismo se va a insertar
	 */
	nuevo_nodo->Vertice = vertice_insertar;
	
	/**
	 * Si el inicio de la pila es NULL
	 */
	if (Pila->inicio == NULL) {
		/**
		 * Se agrega el nuevo nodo
		 */
		Pila->inicio = nuevo_nodo;
		return Pila;
	}
	else {
		
		/**
		 * Si no es NULL pila apunta a inicio
		 */
		actual = Pila->inicio;
		
		/**
		 * Si el siguiente dato es diferente a NULL
		 */
		while (actual->siguiente != NULL) {
			/**
			 * Sigue avanzando
			 */
			actual = actual->siguiente;
		}
		/**
		 * Si es NULL se agrea el nodo y se retorna
		 */
		actual->siguiente = nuevo_nodo;
		return Pila;
	}
}

/**
 * =========================================================================
 *                    Funcion para pop Pila
 * =========================================================================
 */
struct vertice* pop_pila (struct pila* Pila) {
	/**
	 * Se define los punteros
	 */
	struct nodo_vertice* actual;
	struct nodo_vertice* anterior;
	
	/**
	 * Actual apunta al inicio de la pila
	 */
	actual = Pila->inicio;
	
	/**
	 * Si es igual a NULL
	 */
	if (actual->siguiente == NULL) {
		
		/**
		 * el inicio de la pila será null
		 */
		Pila->inicio = NULL;
		return actual->Vertice;
	}
	else {
		/**
		 * Si es diferente a NULL
		 */
		while (actual->siguiente != NULL) {
			/**
			 * anterior sera igual a actual
			 * y se avanza al siguiente dato
			 */
			anterior = actual;
			actual = actual->siguiente;
		}
		anterior->siguiente = NULL;
		return actual->Vertice;
	}
}


/**
 * =========================================================================
 *                    Funcion para verificar_marcados
 * =========================================================================
 */
int verificar_marcados (struct grafo* lista_marcados, struct vertice* vertice_verificar) {
	
	/**
	 * Se define el puntero actual
	 */
	struct nodo_vertice* actual;
	
	/**
	 * La lista de marcados apuntará en el inicio
	 */
	actual = lista_marcados->inicio;
	
	/**
	 * Si es diferente a NULL
	 */
	while (actual != NULL) {
		
		/**
		 * Si son iguales los vertices retorna 1
		 */
		if (actual->Vertice->id == vertice_verificar->id) {
			return 1;
		}
		else {
			/**
			 * Si no, sigue avanzando
			 */
			actual = actual->siguiente;
		}	
	}
	return 0;
}

/**
 * =========================================================================
 *                    Funcion para insertar_vertice
 * =========================================================================
 */
struct grafo* insertar_vertice(struct grafo* lista, struct vertice* elem){

	/**
	 * Define las variables
	 */
	struct nodo_vertice* nuevo_nodo = NULL;
	struct nodo_vertice* actual = NULL;
	
	/**
	 * Verifica que la lista exista
	 */
	if (lista == NULL){
		return NULL;
	}

	/** 
	 * Crea el nodo y le asigna el valor
	 */
	nuevo_nodo = calloc(1, sizeof(struct nodo_vertice));
	nuevo_nodo->Vertice = elem;

	/**
	 * Verifica que la lista no este vacia
	 * En caso, funcionaria de igual manera que "insertar_inicio"
	 */
	 
	if (lista->inicio == NULL){

		lista->inicio = nuevo_nodo;
		return lista;
	}
	
	/**
	 * Inicia con el primer elemento
	 */
	actual = lista->inicio;

	/**
	 * Recorre la lista hasta llegar al ultimo elemento para luego agregarlo
	 */
	while (actual != NULL){
		/**
		 * Si es NULL se agrega el nuevo nodo
		 */
		if (actual->siguiente == NULL){
			actual->siguiente = nuevo_nodo;
			break;
		}

		actual = actual->siguiente;
	}

	return lista;
}

/**
 * =========================================================================
 *                    Funcion para insertar_arista
 * =========================================================================
 */
struct lista_aristas* insertar_arista(struct lista_aristas* lista, struct arista* elem){

	/**
	 * Define las variables
	 */
	struct nodo_arista* nuevo_nodo = NULL;
	struct nodo_arista* actual = NULL;
	
	/** 
	 * Verifica que la lista exista
	 */
	if (lista == NULL){
		return NULL;
	}

	/**
	 * Crea el nodo y le asigna el valor
	 */
	nuevo_nodo = calloc(1, sizeof(struct nodo_vertice));
	nuevo_nodo->Arista = elem;

	/** 
	 * Verifica que la lista no este vacia
	 * En caso, funcionaria de igual manera que "insertar_inicio"
	 */
	 
	if (lista->inicio == NULL){
		
		/**
		 * Se agrega el nuevo nodo para que deje de ser NULL
		 */
		lista->inicio = nuevo_nodo;
		return lista;
	}
	
	/**
	 * Inicia con el primer elemento
	 */
	actual = lista->inicio;

	/**
	 * Recorre la lista hasta llegar al ultimo elemento para luego agregarlo
	 */
	while (actual != NULL){

		if (actual->siguiente == NULL){
			actual->siguiente = nuevo_nodo;
			break;
		}
		/**
		 * Pasa al siguiente dato
		 */
		actual = actual->siguiente;
	}

	return lista;
}

/**
 * =========================================================================
 *                    Funcion para imprimir_aristas
 * =========================================================================
 */
void imprimir_aristas(struct lista_aristas* lista){

	/** 
	 * Define las variables
	 */
	struct nodo_arista* actual = NULL;

	/**
	 * Verifica que la lista no sea nula
	 */
	if (lista == NULL){
		printf("Lista NULL\n");
		return;
	}

	/**
	 * Verifica que la lista no este vacia
	 */
	if (lista->inicio == NULL){
		printf("Lista vacía\n");
		return;
	}
	
	/**
	 * Se posiciona en el elemento inicial
	 */
	actual = lista->inicio;

	printf("Aristas: \n");
	
	/**
	 * Va a recorrer cada elemento de la lista y asimismo imprimiendolos
	 */
	while (actual != NULL){
		
		printf("ID: %d, Peso: %d\n", actual->Arista->id, actual->Arista->peso);
		
		actual = actual->siguiente;
	}
	
	printf("\n");
}

/**
 * =========================================================================
 *                Funcion para imprimir_lista_adyacencia
 * =========================================================================
 */	
void imprimir_lista_adyacencia(struct grafo* lista){

	/**
	 * Define las variables
	 */
	struct nodo_vertice* actual = NULL;

	/**
	 * Verifica que la lista no sea nula
	 */
	if (lista == NULL){
		printf("Lista NULL\n");
		return;
	}

	/**
	 * Verifica que la lista no este vacia
	 */
	if (lista->inicio == NULL){
		printf("Lista vacía\n");
		return;
	}
	
	/**
	 * Se posiciona en el elemento inicial
	 */
	actual = lista->inicio;

	/**
	 * Va a recorrer cada elemento de la lista y asimismo imprimiendolos
	 */
	while (actual != NULL){

		printf("%s - ID: %d\n", actual->Vertice->habitacion, actual->Vertice->id);
		imprimir_aristas(actual->Vertice->aristas);
		actual = actual->siguiente;
	}
	
	printf("\n");
}
/**
 * =========================================================================
 *                Funcion para largo del grafo
 * =========================================================================
 */	
int len_grafo (struct grafo* lista) {
	/**
	 * Se definen las variables
	 */
	int cant_vertices = 0;
	struct nodo_vertice* actual;
	
	/**
	 * Se inicaliza actual al inicio de la lista
	 */
	actual = lista->inicio;
	
	/**
	 * Si la lista no esta vacía
	 */
	while (actual != NULL) {
		/**
		 * Se suma el vertice y se continua con el siguiente vertice
		 */
		cant_vertices++;
		actual = actual->siguiente;
	}
	
	return cant_vertices;
}

/**
 * =========================================================================
 *                      Funcion para imprimir_cola
 * =========================================================================
 */	
void imprimir_cola (struct cola* Cola) {
	
	/**
	 * Apuntador actual
	 */
	struct nodo_vertice* actual;
	
	/**
	 * Si la cola esta vacia
	 */
	if (Cola->inicio == NULL) {
		printf("Cola vacia\n");
	}
	else {
		printf("Cola: ");
		
		/**
		 * Apuntador al inicio de la cola
		 */
		actual = Cola->inicio;
		
		/**
		 * Si no esta vacia
		 */
		while (actual != NULL) {
			
			printf("%d, ", actual->Vertice->id);
			
			/**
			 * Sigue con el proximo dato
			 */
			actual = actual->siguiente;
		}
	}
	printf("\n");
}

/**
 * =========================================================================
 *                      Funcion para imprimir_anchura
 * =========================================================================
 */	
void imprimir_anchura (struct grafo* lista, int id_inicio) {
	
	/**
	 * Declaración de las variables
	 */
	
	/**
	 * Variables que ocupan su reserva de espacio en el HEAP
	 */
	struct grafo* lista_marcados = calloc(1, sizeof(struct grafo));
	
	struct cola* Cola = calloc(1, sizeof(struct cola));
	
	/**
	 * Las variables que nos rervian como punteros
	 */
	struct vertice* vertice_actual;
	struct nodo_arista* arista_actual;
	struct vertice* arista_encontrada;
	
	/**
	 * Se buscaa el vertice
	 */
	vertice_actual = buscar_vertice(lista, id_inicio);
	
	/**
	 * Se le hace push a la cola
	 */
	Cola = push_cola(Cola, vertice_actual);
	
	/**
	 * Y se inserta
	 */
	lista_marcados = insertar_vertice(lista_marcados, vertice_actual);
	
	/**
	 * Si no está vacía
	 */
	while (Cola->inicio != NULL) {
		vertice_actual = pop_cola(Cola);
		arista_actual = vertice_actual->aristas->inicio;
		
		/**
		 * Si la arista actual no esta vacia
		 */
		while (arista_actual != NULL) {
			arista_encontrada = buscar_vertice(lista, arista_actual->Arista->id);
			
			/**
			 * Si es el caso que no esten marcados
			 */
			if (verificar_marcados(lista_marcados, arista_encontrada) == 0){
				
				push_cola(Cola, buscar_vertice(lista, arista_actual->Arista->id));
				lista_marcados = insertar_vertice(lista_marcados, buscar_vertice(lista, arista_actual->Arista->id));
				arista_actual = arista_actual->siguiente;
			}
			else {
				/**
				 * Avanza con la siguiente arista
				 */
				arista_actual = arista_actual->siguiente;
			}
		}
		printf("%d -> ", vertice_actual->id);
	}
	printf("\n");
	
}

/**
 * =========================================================================
 *                   Funcion para imprimir_profundidad
 * =========================================================================
 */
void imprimir_profundidad (struct grafo* lista, int id_inicio) {
	
	/**
	 * Declaración de las variables
	 */
	
	/**
	 * Variables que ocupan su reserva de espacio en el HEAP
	 */
	struct grafo* lista_marcados = calloc(1, sizeof(struct grafo));
	struct pila* Pila = calloc(1, sizeof(struct pila));
	
	/**
	 * Las variables que nos rervian como punteros
	 */
	struct vertice* vertice_actual;
	struct nodo_arista* arista_actual;
	struct vertice* arista_encontrada;
	
	/**
	 * Se busca el vertice
	 */
	vertice_actual = buscar_vertice(lista, id_inicio);
	
	/**
	 * Push a la pila
	 */
	Pila = push_pila(Pila, vertice_actual);
	
	/**
	 * Se inserta
	 */
	lista_marcados = insertar_vertice(lista_marcados, vertice_actual);
	
	while (Pila->inicio != NULL) {
		
		vertice_actual = pop_pila(Pila);
		arista_actual = vertice_actual->aristas->inicio;
		
		/**
		 * Si la arista actual no esta vacia
		 */
		while (arista_actual != NULL) {
			arista_encontrada = buscar_vertice(lista, arista_actual->Arista->id);
			
			/**
			 * Si es el caso que no esten marcados
			 */
			if (verificar_marcados(lista_marcados, arista_encontrada) == 0){
				
				push_pila(Pila, buscar_vertice(lista, arista_actual->Arista->id));
				lista_marcados = insertar_vertice(lista_marcados, buscar_vertice(lista, arista_actual->Arista->id));
				arista_actual = arista_actual->siguiente;
			}
			else {
				/**
				 * Avanza con la siguiente arista
				 */
				arista_actual = arista_actual->siguiente;
			}
		}
		printf("%d -> ", vertice_actual->id);
	}
	printf("\n");
}

/**
 * =========================================================================
 *                 Funcion para crear_lista del archivo
 * =========================================================================
 */
struct grafo* crear_lista(FILE* archivo) {
	
	/**
	 * Se definen las variables
	 */
	int  id;
    int  id_arista;
    int  peso;
    char habitacion[30];
    
    /**
     * La lectura las las variables del archivo
     */
    const char* lectura_vertice = "[%d]\n\"habitacion\" : \"%[^\"]\"\n\"aristas\" ";
	const char* lectura_aristas = "%d:%d";
	
	/**
	 * Se reserva la memoria para la lista
	 */
	struct grafo* lista = calloc(1, sizeof(struct grafo));
	
	/**
	 * Apuntadores inicalizados en NULL
	 */
	struct vertice* vertice1 = NULL;
	struct arista* arista1 = NULL;
	
	/**
	 * Se reserva la memoria para las aristas
	 */
	struct lista_aristas* aristas = calloc(1, sizeof(struct lista_aristas));
    
    
    fseek(archivo, 0, SEEK_SET);
    
    /**
     * Se abre el archivo
     */
    while(!feof(archivo)) {
		id_arista = 0;
		peso = 0;
		
		
		fscanf(archivo, lectura_vertice, &id, habitacion);
		
		fseek(archivo, 2, SEEK_CUR);
		fscanf(archivo, lectura_aristas, &id_arista, &peso, id);
		
		/**
		 * Si no estas vacios
		 */
		if (id_arista != 0 && peso != 0){ 

			arista1 = calloc(1, sizeof(struct arista));
			arista1->id = id_arista;
			arista1->peso = peso;
			
			insertar_arista(aristas, arista1);
			
		}
		else {
		
			vertice1 = calloc(1, sizeof(struct vertice));
			vertice1->id = id;
			
			vertice1->habitacion = copiar_str(habitacion);
			vertice1->aristas = aristas;
			
			insertar_vertice(lista, vertice1);
			
			aristas = calloc(1, sizeof(struct lista_aristas));
		}
			
	}
	
	free(aristas);
	aristas = NULL;
	
	return lista;
}


/**
 * =========================================================================
 *                 Funcion para ordenar matriz
 * =========================================================================
 
void Cambio_nodo(struct nodo_arista *a, struct nodo_arista *b)
{
	int temp = a->arista->peso;
	a->arista->peso = b->arista->peso;
	b->arista->peso = temp;
}

/** Se crea el ordenamiento burbuja para la matriz
void Orden(struct nodo_arista *inicio)
{
	int intercambio, i;
	struct nodo_arista *parte;
	struct nodo_arista *actual = NULL;

	/**Revisa si la lista es NULL
	if (inicio == NULL)
		return;

	do
	{
		intercambio = 0;
		parte = inicio;

		while (parte->siguiente != actual)
		{
			if (parte->Arista->peso > parte->siguiente->Arista->peso)
			{
				Cambio_nodo(parte, parte->siguiente);
				intercambio = 1;
			}
			parte = parte->siguiente;
		}
		actual = parte;
	} while (intercambio);
}

/**
 * =========================================================================
 *                    Funcion de matriz_adyacencia
 * =========================================================================
 
void matriz_adyacencia(struct grafo *lista_adyacencia) //, struct listaAristas *matriz[])
{
	/**
	 * Se definen las variables
	 
	struct nodo_vertice *vertice_actual;
	struct nodo_arista *arista_actual;
	
	/**
	 * Definicion de punteros
	 
	vertice_actual = lista_adyacencia->inicio;
	int cant_vertices = lenGrafo(lista_adyacencia);
	struct lista_aristas *matriz[cant_Vertices];

	int contador = 0;

	/**
	 * Si no esta vacia
	 
	while (vertice_actual != NULL)
	{
		arista_actual = vertice_actual->vertice->arista->inicio;
		
		/**
		 * Se reserva el espacio en memoria
		 
		struct lista_aristas *arista = calloc(1, sizeof(struct lista_aristas));

		while (arista_actual != NULL) /**se verific que la arista sea diferente de null
		{
			aristas = insertar_arista(aristas, arista_actual->Arista);
			arista_actual = arista_actual->siguiente;
		}
		Orden(aristas->inicio);      /**Se ordena y se dan valores
		matriz[contador] = aristas;
		vertice_actual = vertice_actual->siguiente;

		contador++;
	}

	for (int i = 0; i < cant_Vertices; i++) /**Itera por cantidad de vertices
	{
		imprimir_aristas(matriz[i]);
	}
}*/

/**
 * =========================================================================
 *                    Funcion de arbol_expansion_minima
 * =========================================================================
 */

int min_Key(int llave[], bool mstSet[]) /** busca vertice con menor valor*/
{ 
    int min = INT_MAX, indice_minimo; 

    for (int v = 0; v < V; v++)  /** inicializa valor minimo*/
        if (mstSet[v] == false && llave[v] < min) 
            min = llave[v], indice_minimo = v; 

    return indice_minimo; 
} 

int imprimir_arbol_de_extension_minima(int pnt[], int grafico[V][V]) //* forma constructiva de impresion*/
{ 
    printf("Arista \t Peso\n"); 
    for (int i = 1; i < V; i++) 
        printf("%d - %d \t%d\n ", pnt[i], i, grafico[i][pnt[i]]); 
} 

void primMST(int grafico[V][V]) { 
    int pnt[V]; 
    int llave[V]; 
    bool mstSet[V]; 

    for (int i = 0; i < V; i++) { /**inicializa las llaves*/
        llave[i] = INT_MAX, mstSet[i] = false; 
	}
    llave[0] = 0; 
    pnt[0] = -1;

    for (int count = 0; count < V - 1; count++) {  /** busca llave mas pequeña*/

        int u = min_Key(llave, mstSet); 

        mstSet[u] = true; 

        for (int v = 0; v < V; v++) { /** actualiza valores y busca por numeros que no se encuentran incluidos por el recorrdio aun*/

            if (grafico[u][v] && mstSet[v] == false && grafico[u][v] < llave[v]) 

                pnt[v] = u, llave[v] = grafico[u][v]; 
		}
    } 

    imprimir_arbol_de_extension_minima(pnt, grafico); 
} 

int arbol()  /** se brinda la matriz*/
{ 

    int grafico[V][V] = { { 0, 6, 9, 6, 0, 3, 0, 0, 9, 0, 0, 0, 0, 0}, 
                        { 6, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                        { 9, 7, 0, 7, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                        { 6, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                        { 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0},
                        { 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0}, 
                        { 0, 0, 0, 0, 5, 0, 0, 7, 0, 1, 0, 0, 0, 0}, 
                        { 0, 0, 0, 0, 0, 0, 7, 0, 6, 0, 0, 0, 0, 0}, 
                        { 9, 0, 0, 0, 0, 2, 0, 6, 0, 0, 0, 0, 4, 0}, 
                        { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0},
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 7}, 
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                        { 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 1, 0, 4}, 
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 4, 0}}; 

     
    primMST(grafico); 

    return 0; 
} 


/**
 * =========================================================================
 *                    Funcion menu principal
 * =========================================================================
 */
int menu (struct grafo* lista_adyacencia) {
	
	int input_opcion;
	
	printf("----------------------------------------------------------\n");
	printf("------------------ Proyecto 2: Grafos --------------------\n");
	printf("----------------------------------------------------------\n");
	printf("1. Grafo\n");
	printf("2. Recorrido en anchura\n");
	printf("3. Recorrido en profundidad\n");
	printf("4. Arbol de expancion minima\n");
	printf("5. Salir A VACACIONEEEEES\n");
	printf("----------------------------------------------------------\n");
	printf("Seleccione un numero: ");
	
	scanf("%d", &input_opcion);
	
	printf("----------------------------------------------------------\n");
	
	if (input_opcion == 1) {
		imprimir_lista_adyacencia(lista_adyacencia);
	}
	else if(input_opcion == 2) {
		printf("Ingrese el ID del vertice por el que quiere iniciar (1-14): ");
		scanf("%d", &input_opcion);
		printf("----------------------------------------------------------\n");
		imprimir_anchura(lista_adyacencia, input_opcion);
	}
	else if (input_opcion == 3) {
		printf("Ingrese el ID del vertice por el que quiere iniciar (1-14): ");
		scanf("%d", &input_opcion);
		printf("----------------------------------------------------------\n");
		imprimir_profundidad(lista_adyacencia, input_opcion);
	}
	else if (input_opcion == 4) {
		printf("Arbol de Expansion Minima\n");
		arbol();
	}
	else if (input_opcion == 5) {
		printf("Hasta Luego!");
		return 1;
	}
	else {
		printf("Opcion introducida Invalida\n");
	}
	return 0;
	
}

/**
 * =========================================================================
 *                 Funcion para abrir el archivo
 * =========================================================================
 */
int main() {
	
	struct grafo* lista;
	int fin = 0;
	
    FILE *fp;
    
    /**
     * Nombre del archivo del grafo
     */
    char* filename = "archivo.txt";
    
    fp = fopen(filename, "r");
    
    /**
     * Si no existe
     */
    if (fp == NULL){
        printf("No se encontro el archivo: %s",filename);
        return 1;
    }
    else {
		/**
		 * En caso que exista se crea la lista
		 */
		lista = crear_lista(fp);
		while (fin == 0) {
			fin = menu (lista);
		}
	}
    fclose(fp);
    return 0;
}
