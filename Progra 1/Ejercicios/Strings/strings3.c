# include <stdio.h>
# include <stdlib.h>
# include <string.h>

//

int main (void) {
    
    //strlen
    // Firma: size_t strlen(const char *s)
    // Cuenta los caracteres de s sin contar el '\0' final	
    // retorna: La longitud como size_t
    char nombre[] = "Hola";
    printf("Longitud: %zu\n", strlen(nombre)); // Imprime 4 (no cuenta el '\0')

    char nombre1[] = "Lucila";
    size_t len = strlen(nombre1);
    printf("Longitud: %zu\n", len); 

    //strcat
   // char *strcat(char *dest, const char *src)	
   //Pega (concatena) src al final de dest, sobrescribiendo el '\0' de dest y agregando uno nuevo al final	
   // retorna: Puntero a dest
    char saludo[20] = "Hola ";
    strcat(saludo, "mundo");
    printf("%s\n", saludo);   // Hola mundo

    // strncat (la versión "segura" de strcat)
    char saludo1[10] = "Hola";
    strncat(saludo1, " mundo", 3);   // copia como máximo 3 caracteres de " mundo"
    printf("%s\n", saludo1);   // Hola mu

    //strcpy
    // char *strcpy(char *dest, const char *src)	
    // Copia src completo (incluyendo '\0') dentro de dest	
    // devuelve: Puntero a dest
    char origen[] = "Programacion en C"; 
    char destino[20];
    strcpy(destino, "Programacion en J");
    printf("%s\n", destino);   // Hola

// Peligro: strcpy no chequea el tamaño de destino. 
//Si src es más largo de lo que destino puede contener, hay buffer overflow (comportamiento indefinido, riesgo de seguridad).
    strncpy(destino, origen, sizeof(destino) - 1); 
    destino[sizeof(destino) - 1] = '\0'; // Aseguramos el cierre 
    printf("Destino: %s\n", destino); // Imprime "Programac"

    char *strcpy( char* dest, const char* src ); 
    char saludo3[20] = "Hola "; 
    char nombre2[] = "Carlos"; 


    // strncat	
    // char *strncat(char *dest, const char *src, size_t n)	
    // Igual que strcat, pero copia como máximo n caracteres de src (más el '\0' final que siempre agrega)	
    // Retorna: Puntero a dest
    // Añade "Carlos" al final de "Hola " respetando el espacio libre 
    strncat(saludo3, nombre2, sizeof(saludo3) - strlen(saludo3) - 1); 
    printf("%s\n", saludo3); // Imprime "Hola Carlos" 


    //strcmp	
    // int strcmp(const char *s1, const char *s2)	
    // Compara dos cadenas carácter por carácter (orden lexicográfico, como el diccionario)	
    // 0 si son iguales, <0 si s1 < s2, >0 si s1 > s2

    /*
    int strcmp( const char* lhs, const char* rhs ); 
    if (strncmp(usuario, "admin", 5) == 0) { 
        printf("Acceso correcto\n"); 
    }


if (strcmp("hola", "hola") == 0) {
    printf("Son iguales\n");
}

int resultado = strcmp("banana", "manzana");
if (resultado < 0) {
    printf("banana va antes que manzana\n");  // se cumple, 'b' < 'm'
}
    */

    return 0;
}