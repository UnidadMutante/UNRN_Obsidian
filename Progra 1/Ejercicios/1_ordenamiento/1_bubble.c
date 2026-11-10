/*
Bubble Sort (El de los intercambios constantes): 
El bucle externo controla el número de "pasadas" por el arreglo (hasta “N” pasadas). 
El bucle interno recorre los elementos para intercambiar los adyacentes si están desordenados (hasta “N-1” comparaciones). 
En el peor de los casos (un arreglo ordenado a la inversa), el elemento más grande debe "burbujear" intercambiándose 
“N-1” veces, el segundo “N-2” veces, y así sucesivamente. Terminas multiplicando iteraciones por iteraciones.
*/

void bubbleSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        int swapped = 0; 
        for (int j = 0; j < n - 1 - i; j++) { 
            if (arr[j] > arr[j + 1]) {
                 // Intercambio 
                 int temp = arr[j]; 
                 arr[j] = arr[j + 1]; 
                 arr[j + 1] = temp; 
                 swapped = 1; 
                } 
            } // Si no hubo intercambios, el arreglo ya está ordenado 
            if (!swapped) break; 
        } 
    }

int main (void) {


    return 0;
}