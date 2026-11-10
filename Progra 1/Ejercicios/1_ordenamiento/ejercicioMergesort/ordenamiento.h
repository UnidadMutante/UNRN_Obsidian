#ifndef __ORDENAMIENTO_H__
#define __ORDENAMIENTO_H__

typedef struct {
    int id_paquete;
    float altitud;
    float temperatura;
} Telemetria;

void imprimirTelemetria(const Telemetria datos[], size_t cantidad);
void mergeSort(Telemetria datos[], int left, int right);

#endif