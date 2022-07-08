
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Proyecto.h"


/**
 * ========================================================================
 *                 Se reserva el espacio para la lista
 * ========================================================================
 */
 
 
struct lista_doble* crear_lista(){

	/**
	 * Se reserva el espacio de la lista
	 */
	struct lista_doble* nueva_lista = calloc(1, sizeof(struct lista_doble));
	return nueva_lista;
}


/**
 * ========================================================================
 *                   Se reserva el espacio para el nodo
 * ========================================================================
 */
 
 
struct nodo_doble* crear_nodo(){
	/**
	 * Se reserva memoria para el nuevo nodo en la lista
	 */
	struct nodo_doble* nuevo_nodo = calloc(1, sizeof(struct nodo_doble));
	return nuevo_nodo;
}


/**
 * ========================================================================
 *                   Se imprime la lista con datos base
 * ========================================================================
 */
 
int imprimir_lista(struct lista_doble* lista){
	
	/**
	 * Seccion para definir variables
	 */
	struct nodo_doble* actual = NULL;
	
	/**
	 * Lista es nula
	 */ 
	if (lista == NULL){
		printf("Lista NULL\n");
		return -1;
	}

	/**
	 * La lista está vacía
	 */ 
	if (lista->inicio == NULL){
		printf("Lista vacía\n");
		return -2;
	}

	/**
	 * Pongo un apuntador adicional al inicio.
	 */
	actual = lista->inicio;

	while (actual != NULL){
		
		/**
		 * Se hace una cocatenacion del nombre de el valor
		 */
		printf("%s = ", actual->nombre);
		printf("%d \n", actual->valor);

		/**
		 * Se sigue con el dato siguiente
		 */
		actual = actual->siguiente;

	}
	printf("\n");
	return 0;
}

/**
 * ======================================================================================
 *                     Algoritmo de insertar al final de la lista
 * ======================================================================================
 */
 
struct lista_doble* insertar_final(struct lista_doble* lista, int elem, char* nombre){

	/**
	 * Se crea el nuevo nodo
	 * 
	 * Se apunta actual para inicalizarlo a NULL
	 */
	struct nodo_doble* nuevo_nodo = crear_nodo();
	struct nodo_doble* actual = NULL;
	
	/**
	 * Lista no existe
	 */
	if (lista == NULL){
		return NULL;
	}

	/**
	 * Valor se guardara en elem
	 * 
	 * Luego se reserva la memoria a nombre 
	 * Para luego copiarlo en nombre
	 */
	nuevo_nodo-> valor  = elem;
	nuevo_nodo-> nombre  = calloc(strlen(nombre),sizeof(char));
	strcpy(nuevo_nodo -> nombre, nombre);

	/**
	 * Caso 1: Si la lista esta vacia
	 * 
	 * Solo seria agregar al inicio el nodo a insertar
	 */
	if (lista->inicio == NULL){

		lista->inicio = nuevo_nodo;
		return lista;
	}

	/**
	 * Caso 2: Si la lista no esta vacia
	 * 
	 * Se localiza el puntero actual al inicio de la lista
	 */
	actual = lista->inicio;

	/**
	 * Si el nodo siguiente es diferente a NULL se agrega el nodo respectivo
	 */
	while (actual->siguiente != NULL){
		
		/**
		 * Se conecta los punteros respectivos de 
		 * las listas dobles
		 */
		actual = actual->siguiente;
		nuevo_nodo -> previo = actual;
		
	}
	/**
	 * Se agrega el nuevo nodo a siguiente
	 */
	actual->siguiente = nuevo_nodo;

	return lista;
}


/**
 * ======================================================================================
 *                    Algoritmo de insertar al inicio de la lista
 * ======================================================================================
 */
 
struct lista_doble* insertar_inicio(struct lista_doble* lista, int elem, char* nombre){

	/**
	 * Hace que el nuevo nodo apunte a NULL
	 * 
	 * Se apunta actual para inicalizarlo a NULL
	 */
	 
	struct nodo_doble* nuevo_nodo = NULL;
	struct nodo_doble* actual = NULL;

	/**
	 * Lista no existe
	 */
	if (lista == NULL){
		return NULL;
	}

	/**
	 * Se crea el nuevo nodo
	 * 
	 * Valor se guardara en elem
	 * 
	 * Luego se reserva la memoria a nombre 
	 * Para luego copiarlo en nombre
	 */
	 
	nuevo_nodo = crear_nodo();
	nuevo_nodo-> valor  = elem;
	nuevo_nodo-> nombre  = calloc(strlen(nombre),sizeof(char));
	strcpy(nuevo_nodo -> nombre, nombre);

	/**
	 * Si el inicio de la lista es NULL se agrega el nodo
	 */
	if (lista->inicio == NULL){

		lista->inicio = nuevo_nodo;

	}else{ // La lista no esta vacia

		/**
		 * Juego con los punteros segun las listas dobles
		 * 
		 * Con los dos punteros que tiene cada nodo
		 * Previo
		 * Siguiente
		 */
		nuevo_nodo->siguiente = lista->inicio;
		nuevo_nodo -> previo = actual;
		lista->inicio = nuevo_nodo;
	}

	return lista;
}

 
struct lista_doble* eliminar_inicio(struct lista_doble* lista){
	struct nodo_doble* actual = NULL;
	actual = lista -> inicio;
	
	/*Asigna el inicio al segundo nodo*/
	//previo = actual -> siguiente; 
	lista -> inicio = actual -> siguiente;
	/*Libera el nodo del inicio*/
	free(actual);
	actual = NULL;
	return lista;
}


/**
 *===================================================================================================================
 *                           Algoritmos para la crear una lista de las listas
 *===================================================================================================================
 */
 
/**
 * Se crea la lista de listas
 */
 
struct listaDeListas* crear_lista_de_lista(){
	/**
	 * Se reserva el espacio de la lista que contendrá las listas
	 */
	struct listaDeListas* nueva_lista = calloc(1, sizeof(struct listaDeListas));
	return nueva_lista;
}

/**
 * Crear nodo para la lista que contendra las listas
 */
struct nodo* crear_nodo_listas(){

	struct nodo* nuevo_nodo = NULL;
	/**
	 * Se reserva memoria de la lista para meter las listas dobles
	 */
	nuevo_nodo = calloc(1, sizeof(struct nodo));
	return nuevo_nodo;
}


/**
 * ==========================================================================
 *                    Insertar listas a la lista madre
 * ==========================================================================
 */
struct listaDeListas* insertar_listas(struct listaDeListas* listaDeListas, struct lista_doble* lista){

	/**
	 * Se crea el nodo de listas y se inicaliza actual en NULL
	 */
    struct nodo* nuevo_nodo = crear_nodo_listas();;
    struct nodo* actual = NULL;

	/**
	 * Cuando al lista no existe
	 */
    if (lista == NULL){
        return NULL;
    }

	/**
	 * El nuevo nodo apunta a nombre se le asigna a lista
	 * 
	 * El nuevo nodo apunta a nombreInstitucion que sera igual a la lista que apunta nombre
	 */
    nuevo_nodo -> apuntador = lista;
    nuevo_nodo -> nombreLista = lista -> nombre;

    /**
     * Si la lista esta vacia 
     */
    if (listaDeListas -> inicio == NULL){
		
		/**
		 * Si no hay nada en la lista de listas 
		 * se agrega el nodo que es una lista
		 */
        listaDeListas -> inicio = nuevo_nodo;
        return listaDeListas;
    }

    /**
     * El puntero actual va a apuntar al inicio de la lista de listas
     */
    actual = listaDeListas -> inicio;

	/**
	 * Si la lista no esta vacia se recorre la lista para ingresar el nodo
	 */
    while (actual -> siguiente != NULL){
        actual = actual -> siguiente;
    }
	/**
	 * Sigue con el elemento siguiente
	 */
    actual -> siguiente = nuevo_nodo;

    return listaDeListas;
}

/**
 *==============================================
 *           Imprime la Lista madre
 *==============================================
 */


int imprimir_lista_de_listas(struct listaDeListas* lista){

	char nombreInstitucion;
	
	scanf("%s", &nombreInstitucion);

	/**
	 * El puntero actual apunta a NULL
	 */
	struct nodo* actual = NULL;
	/**
	 * Validaciones de los estados de la lista
	 * 
	 * Lista NULA
	 */
	if (lista == NULL){
		
		printf("Lista NULL\n");
		return -1;
	}

	/**
	 * Lista vacia
	 */
	if (lista -> inicio == NULL){
		printf("Lista vacía\n");
		return -2;
	}

	/**
	 * Actual apunta al inicio de la lista
	 */
	actual = lista->inicio;
	
	while (actual != NULL){
	
		printf("%s : \n", actual -> nombreLista);
		
		imprimir_institucion(actual -> apuntador, nombreInstitucion);
		
		actual = actual -> siguiente;
		
	}

	printf("\n");
	return 0;
}
/**
 * Esta funcion deberia de imrpimir la aread de formacion respectiva
 */

int imprimir_institucion(struct lista_doble* lista, char* nombreInstitucion){
	
	/**
	 * Actual es igual a NULL
	 * 
	 * Actual es un puntero
	 */
	struct nodo_doble* actual = NULL;
	
	/**
	 * Se imprime la la area de formacion
	 */
	printf("%s=", nombreInstitucion);

	/**
	 * Si la lista no existe
	 */
	if (lista == NULL){
		printf("Lista NULL\n");
		return -1;
	}

	/**
	 * Si la lista esta vacia
	 */
	if (lista->inicio == NULL){
		printf("Lista vacía\n");
		return -2;
	}

	/**
	 * Actual se inializa en el inicio de la lista
	 */
	actual = lista->inicio;

	/**
	 * Siempre entra en el ciclo hasta que se acabe la lista y que
	 * el ultimo nodo apunte a NULL y sea el actual
	 */
	while (actual != NULL){
		
		/**
		 * Con strcoll se compara la institucion con el puntero
		 * que lo contiene y si es igual a 0 es que son iguales y se 
		 * imprimen
		 */
		if (strcoll(nombreInstitucion, actual -> nombre) == 0){
			printf("%d \n========================== \n", actual -> valor);
		} 
		actual = actual->siguiente;
	}
	return 0;
}


/**

 *==================================================================================
 *           Funciones para crear el arbol e ingresar datos en el mismo
 * 
 * NOTA: Dichos algoritmos no sirven, pero con sigo esta la idea general del 
 * funcionamiento de los mismos en esta progra y debidamente explicados
 *==================================================================================


 * Está función se encargará de crear el arbol
 

struct arbol* crear_arbol(){

	 * Se reserva espacio para el arbol

	struct arbol* nuevo_arbol = calloc(1,sizeof(struct arbol));
	return nuevo_arbol;
}


struct nodo_arbol* crear_nodo_arbol(char* institucion, struct listaDeListas* listaDeListas){

	 * Se reserva memoria para el nuevo nodo de arbol

	struct nodo_arbol* nuevo_nodo = calloc(1, sizeof(struct nodo_arbol));
		
	return nuevo_nodo;
}

 *============================================================================
 * Este algoritmo en santa teoria deberia de darle forma al arbol
 * poniedo os valores mayores a la derecha y los menores a la izquierda
 * pero estaremos trabajando con string y como definimos si es mayor o menor 
 * 
 * Pues con el strcoll nos va a dar un numero negativo o positivo
 * 
 * Si es negativo va para la izquierda
 * 
 * Si es positivo va para la derecha 
 * 
 * Y si es 0 significa que son iguales
 * 
 *============================================================================



struct nodo_arbol* insertar_arbol(struct nodo_arbol raiz, char* institucion){
	
	struct nodo_arbol* nuevo_nodo = NULL;
	struct nodo_arbol* actual = NULL;
		
	if(actual == NULL){
		nuevo_nodo = crear_nodo_arbol(institucion);
		
		return nuevo_nodo;
		
	}
	
	 * Si es negativo se inserta a la izquierda del arbol

	if(strcoll(actual -> institucion, institucion) < 0){
		actual -> izquierda = insertar_arbol(raiz -> izquierda, institucion);
		
	}else{

		 * Si es positivo se inserta a la derecha del arbol

		actual -> derecha = insertar_arbol(raiz -> derecha, institucion);
	}
	return actual;
}

 *=========================================================================
 * Asi deberia ser el preorden en sana teoria, pero implementarlo
 * a la progra se me complico
 * 
 * Pre-orden 
 * Empieza a partir de la raiz y despues imprime el lado izquiedo del arbol
 * y de ese lado izquierdo imprime el lado izquiedo si es que tiene
 *=========================================================================
 
struct nodo_arbol* pre_orden(struct nodo_arbol* raiz){
	
	if(raiz == NULL){
		return NULL;
	}
	

	 * Se imprime el valor de la raiz y se adentra en el lado izquierdo del 
	 * arbol

	printf("%s \n", raiz -> valor);
	pre_orden(raiz -> izquierda);
	pre_orden(raiz -> derecha);
}


 *===================================================================================
 * Retorna el dato mas a la izquierda el arbol por el cual por ser un arbol binario
 * sera el menor
 *===================================================================================

struct nodo_arbol* minimo(struct nodo_arbol* raiz){
	
	if(raiz == NULL){
		return NULL;
	}

	 * Si el lado izquiedo analizado del arbol es NULL eso significa que 
	 * en el nodo en el que estamos es el menor y se procede a retornar 
	 * la raiz

	if(raiz -> izquierda == NULL){
		return raiz;
	
	}else{

		 * El minimo del arbol se localiza en el nodo mas a la izquierda

		return minimo(raiz -> izquierda);
	}
}

struct nodo_arbol* buscar(struct nodo_arbol* raiz, char* institucion){
	

	 * Si la raiz es nula el arbol no existe

	if(raiz == NULL){
		return NULL;
	}
	
	 * Se compara los string con strcoll y si es negativo va para
	 * la izquierda y si es positivo va para la derecha


	if(strcoll(raiz -> nombre, institucion) < 0){
		
		return buscar(raiz -> izquierda, institucion);
	}
	
	if(strcoll(raiz -> nombre, institucion) > 0){
		
		return buscar(raiz -> derecha, institucion);
	}
	
	 * Se retorna la raiz

	return raiz;
	
}
*/

 
/**
 * Está función se encargará de contener los datos de las instituciones
 */
 
struct lista_doble* datosDeAreasFormacion(struct lista_doble* lista, int indice){
	
	/**
	 * 
	 * Todas las instituciones tendran el mismo formato, se crea una lista en la cual
	 * se le asignara el nombre de la institucion para consecuente meterle los datos
	 * con el algoritmo de insetar al final insertando asi en numero y el String
	 * 
	 */
	 
	/**
	 * Datos de la institucion INA
	 */
	if(indice == 0){
		struct lista_doble* INA = crear_lista("INA");
		printf("-----------------------------------------INA-----------------------------------------\n");
		insertar_final(INA,1061,  "Educación");
		insertar_final(INA,43858, "Humaniades y artes");
		insertar_final(INA,48192, "Ciencias sociales, educación comercial y derecho");
		insertar_final(INA,66039, "Ciencias");
		insertar_final(INA,184459,"Ingeniería, industria y construcción");
		insertar_final(INA,16817, "Agricultura");
		insertar_final(INA,6546,  "Salud y servicios sociales");
		insertar_final(INA,23264, "Otros servicios");
		insertar_final(INA,1468,  "Ignorada");
		imprimir_lista(INA);
	}

	/**
	 * Datos de la institucion InstitutoPrivado
	 */
	if(indice == 1){
		struct lista_doble* InstitutoPrivado = crear_lista("InstitutoPrivado");
		printf("-----------------------------------------Instituto Privado-----------------------------------------\n");
		insertar_final(InstitutoPrivado,2578,  "Educación");
		insertar_final(InstitutoPrivado,47651, "Humaniades y artes");
		insertar_final(InstitutoPrivado,36340, "Ciencias sociales, educación comercial y derecho");
		insertar_final(InstitutoPrivado,32942, "Ciencias");
		insertar_final(InstitutoPrivado,37532, "Ingeniería, industria y construcción");
		insertar_final(InstitutoPrivado,2078,  "Agricultura");
		insertar_final(InstitutoPrivado,7512,  "Salud y servicios sociales");
		insertar_final(InstitutoPrivado,25295, "Otros servicios");
		insertar_final(InstitutoPrivado,447,   "Ignorada");
		imprimir_lista(InstitutoPrivado);
	}
	
	/**
	 * Datos de la institucion ColegioUniversitario
	 */
	if(indice == 2){
		struct lista_doble* ColegioUniversitario = crear_lista("ColegioUniversitario");
		printf("-----------------------------------------Colegio Universitario-----------------------------------------\n");
		insertar_final(ColegioUniversitario,0,     "Educación");
		insertar_final(ColegioUniversitario,2515,  "Humaniades y artes");
		insertar_final(ColegioUniversitario,4283,  "Ciencias sociales, educación comercial y derecho");
		insertar_final(ColegioUniversitario,754,   "Ciencias");
		insertar_final(ColegioUniversitario,1335,  "Ingeniería, industria y construcción");
		insertar_final(ColegioUniversitario,0,     "Agricultura");
		insertar_final(ColegioUniversitario,258,   "Salud y servicios sociales");
		insertar_final(ColegioUniversitario,1515,  "Otros servicios");
		insertar_final(ColegioUniversitario,0,     "Ignorada");
		imprimir_lista(ColegioUniversitario);
	}
	
	/**
	 * Datos de la institucion UniversidadPublica
	 */
	if(indice == 3){
		struct lista_doble* UniversidadPublica = crear_lista("UniversidadPublica");
		printf("-----------------------------------------Universidad Pública-----------------------------------------\n");
		insertar_final(UniversidadPublica,3285,  "Educación");
		insertar_final(UniversidadPublica,12077, "Humaniades y artes");
		insertar_final(UniversidadPublica,15585, "Ciencias sociales, educación comercial y derecho");
		insertar_final(UniversidadPublica,17980, "Ciencias");
		insertar_final(UniversidadPublica,1992,  "Ingeniería, industria y construcción");
		insertar_final(UniversidadPublica,1949,  "Agricultura");
		insertar_final(UniversidadPublica,3365,  "Salud y servicios sociales");
		insertar_final(UniversidadPublica,1489,  "Otros servicios");
		insertar_final(UniversidadPublica,563,   "Ignorada");
		imprimir_lista(UniversidadPublica);
	}
	
	/**
	 * Datos de la institucion UniversidadPrivada
	 */
	if(indice == 4){
		struct lista_doble* UniversidadPrivada = crear_lista("UniversidadPrivada");
		printf("-----------------------------------------Universidad Privada-----------------------------------------\n");
		insertar_final(UniversidadPrivada,2327,  "Educación");
		insertar_final(UniversidadPrivada,6468,  "Humaniades y artes");
		insertar_final(UniversidadPrivada,8567,  "Ciencias sociales, educación comercial y derecho");
		insertar_final(UniversidadPrivada,4039,  "Ciencias");
		insertar_final(UniversidadPrivada,1516,  "Ingeniería, industria y construcción");
		insertar_final(UniversidadPrivada,126,   "Agricultura");
		insertar_final(UniversidadPrivada,4870,  "Salud y servicios sociales");
		insertar_final(UniversidadPrivada,1922,  "Otros servicios");
		insertar_final(UniversidadPrivada,0,     "Ignorada");
		imprimir_lista(UniversidadPrivada);
	}
	
	/**
	 * Datos de la institucion InstitucionPublica
	 */
	if(indice == 5){
		struct lista_doble* InstitucionPublica = crear_lista("InstituciónPublica");
		printf("-----------------------------------------Institución Pública-----------------------------------------\n");
		insertar_final(InstitucionPublica,4581,  "Educación");
		insertar_final(InstitucionPublica,12853, "Humaniades y artes");
		insertar_final(InstitucionPublica,29857, "Ciencias sociales, educación comercial y derecho");
		insertar_final(InstitucionPublica,26661, "Ciencias");
		insertar_final(InstitucionPublica,23652, "Ingeniería, industria y construcción");
		insertar_final(InstitucionPublica,3125,  "Agricultura");	
		insertar_final(InstitucionPublica,13815, "Salud y servicios sociales");
		insertar_final(InstitucionPublica,16339, "Otros servicios");
		insertar_final(InstitucionPublica,279,   "Ignorada");
		imprimir_lista(InstitucionPublica);
	}
	
	/**
	 * Datos de la institucion EmpresaPrivada
	 */
	if(indice == 6){
		struct lista_doble* EmpresaPrivada = crear_lista("EmpresaPrivada");
		printf("-----------------------------------------Empresa Privada-----------------------------------------\n");
		insertar_final(EmpresaPrivada,2147,  "Educación");
		insertar_final(EmpresaPrivada,16962, "Humaniades y artes");
		insertar_final(EmpresaPrivada,29910, "Ciencias sociales, educación comercial y derecho");
		insertar_final(EmpresaPrivada,24692, "Ciencias");
		insertar_final(EmpresaPrivada,33103, "Ingeniería, industria y construcción");
		insertar_final(EmpresaPrivada,2687,  "Agricultura");
		insertar_final(EmpresaPrivada,9405,  "Salud y servicios sociales");
		insertar_final(EmpresaPrivada,28724, "Otros servicios");
		insertar_final(EmpresaPrivada,1572,  "Ignorada");
		imprimir_lista(EmpresaPrivada);
	}
	
	/**
	 * Datos de la institucion Extranjero
	 */
	if(indice == 7){
		struct lista_doble* Extranjero = crear_lista("Extranjero");
		printf("-----------------------------------------Extranjero-----------------------------------------\n");
		insertar_final(Extranjero,1942,  "Educación");
		insertar_final(Extranjero,6208,  "Humaniades y artes");
		insertar_final(Extranjero,10793, "Ciencias sociales, educación comercial y derecho");
		insertar_final(Extranjero,2246,  "Ciencias");
		insertar_final(Extranjero,6470,  "Ingeniería, industria y construcción");
		insertar_final(Extranjero,1224,  "Agricultura");
		insertar_final(Extranjero,1882,  "Salud y servicios sociales");
		insertar_final(Extranjero,4866,  "Otros servicios");
		insertar_final(Extranjero,258,   "Ignorada");
		imprimir_lista(Extranjero);
	}
	
	/**
	 * Datos de la institucion Otro
	 */
	if(indice == 8){
		struct lista_doble* Otro = crear_lista("Otro");
		printf("-----------------------------------------Otro-----------------------------------------\n");
		insertar_final(Otro,0,     "Educación");
		insertar_final(Otro,268,   "Humaniades y artes");
		insertar_final(Otro,1036,  "Ciencias sociales, educación comercial y derecho");
		insertar_final(Otro,437,   "Ciencias");
		insertar_final(Otro,466,   "Ingeniería, industria y construcción");
		insertar_final(Otro,0,     "Agricultura");
		insertar_final(Otro,168,   "Salud y servicios sociales");
		insertar_final(Otro,237,   "Otros servicios");
		insertar_final(Otro,0,     "Ignorada");
		imprimir_lista(Otro);
	}

	/**
	 * Datos de la institucion Ignorada
	 */
	if(indice == 9){
		struct lista_doble* Ignorada = crear_lista("Ignorada");
		printf("-----------------------------------------Ignorada-----------------------------------------\n");
		insertar_final(Ignorada,0,     "Educación");
		insertar_final(Ignorada,481,   "Humaniades y artes");
		insertar_final(Ignorada,1309,  "Ciencias sociales, educación comercial y derecho");
		insertar_final(Ignorada,674,   "Ciencias");
		insertar_final(Ignorada,975,   "Ingeniería, industria y construcción");
		insertar_final(Ignorada,0,     "Agricultura");
		insertar_final(Ignorada,0,     "Salud y servicios sociales");
		insertar_final(Ignorada,0,     "Otros servicios");
		insertar_final(Ignorada,389,   "Ignorada");
		imprimir_lista(Ignorada);
	}
}

/**
 * =======================================================================================
 * En esta funcion hace cargar los datos de manera que esten identificados con un "ID" el
 * cual es el indice que se le asigna de 0 a 9 cosa que puede revolverse la lista y no va 
 * afectar el resultado como si se estuviera trabajando con posiciones
 * =======================================================================================
 */
struct lista_doble* cargarDatos(){
		
		struct lista_doble* INA = crear_lista("INA");
		datosDeAreasFormacion(INA,0);
		
		struct lista_doble* InstitutoPrivado = crear_lista("InstitutoPrivado");
		datosDeAreasFormacion(InstitutoPrivado,1);

		struct lista_doble* ColegioUniversitario = crear_lista("ColegioUniversitario");
		datosDeAreasFormacion(ColegioUniversitario,2);

		struct lista_doble* UniversidadPublica = crear_lista("UniversidadPublica");
		datosDeAreasFormacion(UniversidadPublica,3);

		struct lista_doble* UniversidadPrivada = crear_lista("UniversidadPrivada");
		datosDeAreasFormacion(UniversidadPrivada,4);
		imprimir_lista(UniversidadPrivada);

		struct lista_doble* InstitucionPublica = crear_lista("InstitucionPublica");
		datosDeAreasFormacion(InstitucionPublica,5);

		struct lista_doble* EmpresaPrivada = crear_lista("EmpresaPrivada");
		datosDeAreasFormacion(EmpresaPrivada,6);

		struct lista_doble* Extranjero = crear_lista("Extranjero");
		datosDeAreasFormacion(Extranjero,7);

		struct lista_doble* Otro = crear_lista("Otro");
		datosDeAreasFormacion(Otro,8);

		struct lista_doble* Ignorada = crear_lista("Ignorada");
		datosDeAreasFormacion(Ignorada,9);
		
		return 0;
}

/**
 * ================================================================
 *    Esta funcion mete las listas con sus respectivos nombres
 * ================================================================

struct arbol* formaDelArbol(struct listaDeListas* listas, struct arbol* ARBOL){
	
	/**
	 * =====================================================================
	 * Se crea una raiz 
	 * 
	 * Se procede a agregar las otras areas de formacion en insertar arbol
	 * lo cual va a determinar si va a la izquierda o derecha del arbol
	 * =====================================================================
	 * 
	ARBOL -> raiz = insertar_arbol(ARBOL -> raiz, "Educacion");
	insertar_arbol(ARBOL -> raiz, "Humaniades y artes");
	insertar_arbol(ARBOL -> raiz, "Ciencias sociales, educación comercial y derecho");
	insertar_arbol(ARBOL -> raiz, "Ciencias");
	insertar_arbol(ARBOL -> raiz, "Ingeniería, industria y construcción");	
	insertar_arbol(ARBOL -> raiz, "Agricultura");
	insertar_arbol(ARBOL -> raiz, "Salud y servicios sociales");
	insertar_arbol(ARBOL -> raiz, "Otros servicios");
	insertar_arbol(ARBOL -> raiz, "Ignorada");

}
*/

/**
 * ========================================================
 *                   Menu principal
 * ========================================================
 */
int main(){
	/**
	 * El menu tendra una opcion a elegir en la funcionalidad del programa
	 */
	int opcion;
		
	printf("---------------------------Menu---------------------------\n");
	printf("1.Imprimir todas las listas\n");
	printf("2.Buscar los datos de una area en especifico\n");
	printf("Digite alguna opcion: ");
	scanf( "%d", &opcion );

	if(opcion == 1){

		cargarDatos();	
		
	}
	if(opcion == 2){
		printf("================================================\n");
		printf("Educación\n");
		printf("Humaniades y artes\n");
		printf("Ciencias sociales, educación comercial y derecho\n");
		printf("Ciencias\n");
		printf("Ingeniería, industria y construcción\n");
		printf("Agricultura\n");
		printf("Salud y servicios sociales\n");
		printf("Otros servicios\n");
		printf("Ignorada\n");
		printf("================================================\n");
		printf("   Escriba una opcion, pero EXACTAMENTE IGUAL\n");
		printf("================================================\n");
		
		/**
		 * Aqui se crea la lista de la institucion deseada
		 */
		struct listaDeListas* listas = crear_lista_de_lista();

		/**
		 * Aqui se imprime la lista especifica que uno requiera 
		 * ya previamente habiendo cargado los datos
		 */
		imprimir_lista_de_listas(listas);

	}
	return 0;
}





