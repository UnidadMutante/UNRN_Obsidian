/*
Implementar en C la función int sumar_elementos(const int vec[], size_t n) 
que calcule y retorne la suma acumulada de todos los enteros contenidos en el arreglo.
Precondición: vec != NULL. Si n == 0, debe retornar 0.
Postcondición: Retorna $\sum_{i=0}^{n-1} \text{vec}[i]$.
*/

# include <stdio.h>
/*
@param 
@param 
@return 
@pre vec != NULL. Si n == 0, debe retornar 0.
@post Retorna $\sum_{i=0}^{n-1} \text{vec}[i]$.
*/
int sumar_elementos(const int vec[], size_t n);
 
int main (void){
    int arreglo[3] = {0,1,2};
    int tamano = sizeof(arreglo)/sizeof(arreglo[0]);
    int resultado = sumar_elementos(arreglo, tamano);
    printf("resultado: %d", resultado);

    return 0;
}

int sumar_elementos(const int vec[], size_t n) {
    int resultado = 0;
    for (int i = 0; i < n; i++) {
        resultado = resultado + vec[i];
    }
    return resultado;
}
