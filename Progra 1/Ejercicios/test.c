#include <stdio.h>
#include <stdlib.h> // Libreria obligatoria para usar atoi()

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error: Debes ingresar exactamente dos números.\n");
        printf("Uso correcto: calculadora <num1> <num2>\n");
        return 1; // Un return distinto de 0 indica que el programa falló
    } //Verificó

    int numero1 = atoi(argv[1]); //atoi convierte de cadena de texto a entero - array to integer
    int numero2 = atoi(argv[2]); //atoi convierte de cadena de texto a entero

    // 3. Hacemos la matemática y mostramos el resultado
    int suma = numero1 + numero2;
    printf("La suma de %d y %d es: %d\n", numero1, numero2, suma);

    return 0;
}