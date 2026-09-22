#include <stdio.h>
#include <stdlib.h> // Libreria obligatoria para usar atoi()

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error: Tenes que ingresar dos palabras.\n");
        printf("[Nombre] [apellido]\n");
        return 1; // Un return distinto de 0 indica que el programa falló
    } //Verificó

    char* nombre = argv[1]; 
    char* apellido = argv[2]; 

    printf("Hola %s %s , Bienvenido!\n", nombre, apellido);

    return 0;
}