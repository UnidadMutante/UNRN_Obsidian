#ifndef __ORDENAMIENTO_H__
#define __ORDENAMIENTO_H__

#include <stdio.h>

typedef struct {
    int id_paquete;
    float altitud;
    float temperatura;
} Telemetria;

void imprimirTelemetria(const Telemetria datos[], size_t cantidad);
void quickSort(Telemetria datos[], int inicio, int fin);

#endif