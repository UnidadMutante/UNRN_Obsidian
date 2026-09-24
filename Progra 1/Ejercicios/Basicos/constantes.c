#include <stdio.h>
#define PI 3.14159

/*
Sintaxis: #define PI 3.14159 (Nota: no lleva punto y coma al final) 
● Ventaja: Cero consumo de memoria en tiempo de ejecución. 
● Desventaja: Al no tener un tipo de dato explícito (int, float, etc.), 
es más difícil para el compilador detectar errores de tipo, y es más complicado de depurar
*/

int main (void) {

    const int LIMITE_MAXIMO = 100;

/*
Tiene un tipo de dato claro (int, float, char). Si intentas modificar (LIMITE_MAXIMO = 200;), 
el compilador detendrá la compilación con un error inmediatamente. 
*/
    return 0;
}