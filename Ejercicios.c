
/* Ejercicio 1 */
#include <stdio.h>
int largoDeUnaCadena(char* cadena)
{
	int i = 0;
	while (cadena[i] != '\0')
	{
		i++;
	}
	return i;
}

int main()
{
	int logitud = largoDeUnaCadena("Somos pricipiantes en C, esto fue mucho");
	printf("%d \n", logitud);
	return 0;
}

/* Ejercicio 2 */
#include <stdio.h>
int buscarCaracter(char* string)
{
	char letra;
	int indice = 0;
	int contador = 0;
	printf("Ingrese la letra que sea \n");
	scanf("%c", letra);
	while(letra != '\0')
	{
		if (letra == string[indice])
		{
			contador++;
		}
		indice++;
	}
	printf("La letra '%c' aparece %d veces en el texto %s", letra ,contador, string);
	return 0;
}
int main(int argc, char **argv)
{
	buscarCaracter("Willump");
	return 0;
}
/*  Ejercicio 3 
    Nota: Esto no es codigo, sino solo una investigacion
    Investigar cuales son las funciones que existen en string.h
    Y esos son:
    * memcpy	* strcat	* strncmp	* strlen	* strtok
    * memmove	* strncat	* strcoll	* strspn	* strxfrm
    * memchr	* strchr	* strcpy	* strcspn	* strrev
    * memcmp	* strrchr	* strncpy	* strpbrk	
    * memset	* strcmp	* strerror	* strstr	
    * */

/*  Ejercicio 4
    Nota: Esto no es codigo, sino solo una investigacion
    * strlen: Devuelve la longitud de una cadena 
    * strcpy: Copia una cadena en otra 
    * strtok: Parte una cadena en una secuencia de tokens 
    * */
    
/*  Ejercicio 5 */
#include <stdio.h>
#include <string.h>

int eliminarCaracter(char* string)
{
	char letra;
	int indice = 0;
	int contador = 0;
	int vacio = ' ';
	printf("Ingrese la letra que sea \n");
	scanf("%c", letra);
	while(string[indice] != '\0')
	{
		if (letra == string[indice])
		{
			string[indice] = vacio;
			contador++;
		}
		indice++;
	}
	printf("Frase final es: %c");
	return 0;
}
int main(int argc, char **argv)
{
	eliminarCaracter("Willump");
	return 0;
}

/*  Ejercicio 6 */
/** Esta funcion da errores pero si cumple el cometido :D
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* cadena = calloc(32,sizeof(char));    
	int i = 0;
    int j;
    printf("Introduce lo que quiere invertir: ");
    gets(cadena); //Recibe como único argumento la variable en la que
                  //debe almacenarse una entrada de usuario que va a
                  //ser considerada como una cadena de caracteres
    while(cadena[i]!='\0')
    {
        i++;
    }
    printf("La cadena invertida es: ");
    for (j=i-1; j>=0; j--)
    {
        printf("%c", cadena[j]); // Dudas en esta linea
    }
    puts("");
    return 0;
}

/*  Ejercicio 7 */
#include <stdio.h>
#include <stdlib.h>

char* solicitarLaEntrada()
{
	char* buffer_entrada = calloc(32,sizeof(char));
	scanf("%s", buffer_entrada);
	
	return buffer_entrada;
}
char* eliminar(char* texto, char c){
	
	return NULL;
	
int main()
{
	char* textoNuevo = solicitarLaEntrada();
	printf("Esto era: %s \n", textoNuevo);
	
	return 0;
}
