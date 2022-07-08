#ifndef progra2_h
#define progra2_h


/**
 * =========================================================================
 *                     Punteros para el vertice
 * =========================================================================
 */
struct vertice {
	int 					id;
	char* 					habitacion;
	struct lista_aristas* 	aristas;
};

/**
 * =========================================================================
 *                     Punteros para las aristas
 * =========================================================================
 */
 
struct arista {
	int 	id;
	int 	peso;
};

/**
 * =========================================================================
 *                       Puntero para el grafo
 * =========================================================================
 */
struct grafo {
	struct nodo_vertice* inicio;
};

/**
 * =========================================================================
 *                    Puntero para la lista de Aristas
 * =========================================================================
 */
struct lista_aristas {
	struct nodo_arista* 	inicio;
};

/**
 * =========================================================================
 *                Punteros para el nodo de los vertices
 * =========================================================================
 */
struct nodo_vertice {
	struct vertice* 	Vertice;
	struct nodo_vertice* siguiente;
};

/**
 * =========================================================================
 *                Punteros para el nodo de las aristas
 * =========================================================================
 */
struct nodo_arista {
	struct arista* 		Arista;
	struct nodo_arista* 	siguiente;
};

/**
 * =========================================================================
 *                       Puntero para la pila
 * =========================================================================
 */
struct pila {
	struct nodo_vertice* inicio;
};

/**
 * =========================================================================
 *                      Punteros para la cola
 * =========================================================================
 */
struct cola {
	struct nodo_vertice* inicio;
	struct nodo_vertice* final;
};


 





/// Referencia de funciones presentes en el archivo .c

char* copiarStr(char* str);

struct vertice* buscar_vertice (struct grafo* lista, int id);

struct cola* push_cola(struct cola* Cola, struct vertice* vertice_insertar);

struct vertice* pop_cola (struct cola* Cola);

struct pila* push_pila (struct pila* Pila, struct vertice* vertice_insertar);

struct vertice* pop_pila (struct pila* Pila);

int verificar_marcados (struct grafo* lista_marcados, struct vertice* vertice_verificar);

struct grafo* insertar_vertice(struct grafo* lista, struct vertice* elem);

struct lista_aristas* insertar_arista(struct lista_aristas* lista, struct arista* elem);

void imprimir_aristas(struct lista_aristas* lista);

void imprimir_lista_adyacencia(struct grafo* lista);

int len_grafo (struct grafo* lista);

void imprimir_cola (struct cola* Cola);

void imprimir_anchura (struct grafo* lista, int id_inicio);

void imprimir_profundidad (struct grafo* lista, int id_inicio);

struct grafo* crear_lista(FILE* file);

void matriz_adyacencia(struct grafo *lista_adyacencia);

int menu (struct grafo* lista_adyacencia);


#endif
