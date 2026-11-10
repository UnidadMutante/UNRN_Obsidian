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
// Fusiona dos mitades ordenadas
void merge(Telemetria datos[], int left, int mid, int right) {
    int i, j, k;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Arreglos temporales
    Telemetria L[n1];
    Telemetria R[n2];

    // Copiar mitad izquierda
    for (i = 0; i < n1; i++) {
        L[i] = datos[left + i];
    }

    // Copiar mitad derecha
    for (j = 0; j < n2; j++) {
        R[j] = datos[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    // Fusionar comparando altitudes
    while (i < n1 && j < n2) {

        if (L[i].altitud <= R[j].altitud) {
            datos[k] = L[i];
            i++;
        } else {
            datos[k] = R[j];
            j++;
        }

        k++;
    }

    // Copiar elementos restantes de L
    while (i < n1) {
        datos[k] = L[i];
        i++;
        k++;
    }

    // Copiar elementos restantes de R
    while (j < n2) {
        datos[k] = R[j];
        j++;
        k++;
    }
}

// Algoritmo MergeSort
void mergeSort(Telemetria datos[], int left, int right) {

    if (left < right) {

        int mid = left + (right - left) / 2;

        // Ordenar mitad izquierda
        mergeSort(datos, left, mid);

        // Ordenar mitad derecha
        mergeSort(datos, mid + 1, right);

        // Fusionar ambas mitades
        merge(datos, left, mid, right);
    }
}