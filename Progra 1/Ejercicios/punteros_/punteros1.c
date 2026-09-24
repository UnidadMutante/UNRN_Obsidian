#include <stdio.h>

int main(void)
{       int valor = 10;
	int *puntero = &valor;

	//puntero a puntero
	int **puntero_a_puntero = &puntero;
	printf("La direccion de memoria del puntero es: %p\n", puntero);

return 0;
}
