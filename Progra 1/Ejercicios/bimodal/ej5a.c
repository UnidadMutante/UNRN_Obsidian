#include <stdio.h>

int main () {

char cadena_valida[] = "Hola";
char arreglo_sin_nulo[] = {'H', 'o', 'l', 'a'};
char arreglo_con_nulo[] = {'H', 'o', 'l', 'a', 0};


printf("cadena válida: %s\n", cadena_valida);
printf("Arreglos sin nulo: %s\n", arreglo_sin_nulo);
// si imprimo esto asi nomas, como no hay un 0 para avisar donde termina el arreglo, C sigue imprimiendo cosas

printf("%lu\n", sizeof(cadena_valida));
// cadena válida ocupa un byte adicional porque deje un espacio adicional para el 0
printf("%lu\n", sizeof(arreglo_sin_nulo));

return 0;
}