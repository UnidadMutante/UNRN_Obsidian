/*
Implementar la función void contar_paridad(const int vec[], size_t n, size_t *cant_pares, size_t *cant_impares) 
que analice el vector de entrada y guarde en las direcciones pasadas por referencia la cantidad total de números pares e 
impares encontrados.
*/
/*
@pre vec != NULL, cant_pares != NULL, cant_impares != NULL.
@post *cant_pares almacena la cantidad de elementos con vec[i] % 2 == 0 y *cant_impares almacena el resto.
*/

# include <stdio.h>
void contar_paridad(const int vec[], size_t n, size_t *cant_pares, size_t *cant_impares);

int main (void) {

    int numeros[] = {1, 2, 3};
    size_t tamano = sizeof(numeros)/sizeof(numeros[0]);
    size_t pares = 0;
    size_t impares = 0;
    
    contar_paridad(numeros, tamano, &pares, &impares);
    printf("pares: %d\n", pares);
    printf("impares: %d\n", impares);
    return 0;
}

void contar_paridad(const int vec[], size_t n, size_t *cant_pares, size_t *cant_impares){

    for (int i = 0; i < n; i++) {
        if (vec[i]%2 == 0) {
            *cant_pares+=1;
        } else {
            *cant_impares+=1;
        }
    }
}