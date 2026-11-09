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

static void intercambiar(Telemetria *a, Telemetria *b) {
    Telemetria aux = *a;
    *a = *b;
    *b = aux;
}

static int particion(Telemetria datos[], int inicio, int fin) {
    float pivote = datos[fin].altitud;
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        if (datos[j].altitud <= pivote) {
            i++;
            intercambiar(&datos[i], &datos[j]);
        }
    }

    intercambiar(&datos[i + 1], &datos[fin]);

    return i + 1;
}

void quickSort(Telemetria datos[], int inicio, int fin) {
    if (inicio < fin) {
        int p = particion(datos, inicio, fin);

        quickSort(datos, inicio, p - 1);
        quickSort(datos, p + 1, fin);
    }
}