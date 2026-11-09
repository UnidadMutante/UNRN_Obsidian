#include <stdio.h>
#include "ordenamiento.h"

void imprimirTelemetria(const Telemetria datos[], size_t cantidad) {
    for (size_t i = 0; i < cantidad; i++) {
        printf("ID: %d | Altitud: %.1f | Temperatura: %.1f\n",
               datos[i].id_paquete,
               datos[i].altitud,
               datos[i].temperatura);
    }
}

// swap
// a y b son punteros a Telemetria. Eso significa que la función no recibe copias de los registros, sino las direcciones donde están almacenados.
// como son punteros, luego se llama asi -> intercambiar(&datos[i], &datos[j]);
static void intercambiar(Telemetria *a, Telemetria *b) {
    Telemetria aux = *a;
    *a = *b;
    *b = aux;
}

/*
 * Función de partición.
1. Elegir un pivote.
2. Reordenar los elementos.
3. Dejar todos los elementos menores o iguales al pivote a su izquierda.
4. Dejar todos los elementos mayores al pivote a su derecha.
5. Devolver la posición final del pivote.
 */
static int particion(Telemetria datos[], int inicio, int fin) {
    float pivote = datos[fin].altitud;
// Comienza una posición antes del inicio porque todavía no encontramos ningún elemento menor o igual.
    int i = inicio - 1;
// No incluimos fin en el recorrido porque ahí está el pivote.
    for (int j = inicio; j < fin; j++) {
        if (datos[j].altitud <= pivote) {
            // Avanzamos la frontera de elementos "menores".
            i++;
            // Colocamos este registro en la zona izquierda. 
            // Se llama con & porque la funcion recibe punteros 
// "Envíale a la función las direcciones de esos dos registros para que pueda modificar el arreglo real."
            intercambiar(&datos[i], &datos[j]);
        }
    }
 /*
     * Al finalizar el ciclo:
     *
     * - Desde inicio hasta i hay elementos <= pivote.
     * - Desde i+1 hasta fin-1 hay elementos > pivote.
     *
     * Ahora ubicamos el pivote entre ambas zonas.
     */
    intercambiar(&datos[i + 1], &datos[fin]);
 /*
     * Devolvemos la posición definitiva del pivote.
     */
    return i + 1;
}
/*
 * Algoritmo QuickSort.
 *
 * Divide el arreglo en dos partes usando un pivote
 * y luego ordena recursivamente cada parte.
 */
void quickSort(Telemetria datos[], int inicio, int fin) {
     /*
     * Caso base:
     * si hay 0 o 1 elementos, el segmento ya está ordenado.
     */
    if (inicio < fin) {
         /*
         * Reorganizamos el arreglo y obtenemos
         * la posición final del pivote.
         */
        int p = particion(datos, inicio, fin);

        /*
         * Ordenamos recursivamente los elementos
         * que quedaron a la izquierda del pivote.
         */
        quickSort(datos, inicio, p - 1);

        /*
         * Ordenamos recursivamente los elementos
         * que quedaron a la derecha del pivote.
         */
        quickSort(datos, p + 1, fin);
    }
}