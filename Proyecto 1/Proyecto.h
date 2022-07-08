#ifndef LISTA_H
#define LISTA_H
/**
 * ========================================================================
 *                    Punteros para la lista dobles
 * ========================================================================
 */
struct lista_doble{
	struct nodo_doble* inicio;
	char*              nombre; 
};
    
struct nodo_doble{
	int                valor;
	char*              nombre; 
		            
	/**
	 * Punteros para listas dobles
	 */
	struct nodo_doble* siguiente;
	struct nodo_doble* previo;
};

/**
 * ========================================================================
 *                  Punteros para la lista de listas
 * ========================================================================
 */

struct listaDeListas{
	struct nodo*	    inicio;
};

struct nodo{
	struct lista_doble*  apuntador;
	struct nodo*	     siguiente;
	char*				 nombreLista;
};


/**
 * ========================================================================
 *                       Punteros para el arbol
 * ========================================================================
 */
 
struct arbol{
	struct nodo_arbol* raiz;
};

struct nodo_arbol{
	
	char*                 institucion;
	struct nodo_arbol*    izquierda;
	struct nodo_arbol*    derecha;
	struct listaDeListas* listaDeListas;

};

/**
 * ==========================================================================
 *               Declaraciones de las funciones (enunciados)
 * ==========================================================================
 */
struct lista_doble* crear_lista();

struct nodo_doble* crear_nodo();

int imprimir_lista(struct lista_doble* lista);

struct lista_doble* insertar_final(struct lista_doble* lista, int elem, char* nombre);

struct lista_doble* insertar_inicio(struct lista_doble* lista, int elem, char* nombre);

struct lista_doble* eliminar_inicio(struct lista_doble* lista);

struct listaDeListas* crear_lista_de_lista();

struct nodo* crear_nodo_listas();

struct listaDeListas* insertar_listas(struct listaDeListas* listaDeListas, struct lista_doble* lista);

int imprimir_lista_de_listas(struct listaDeListas* lista);

int imprimir_institucion(struct lista_doble* listas, char* datosInstitucion);

struct lista_doble* datosDeAreasFormacion(struct lista_doble* lista, int indice);



/**
 * ========================================================================
 *                      Finaliza el archivo ".h"
 * ========================================================================
 */
#endif

