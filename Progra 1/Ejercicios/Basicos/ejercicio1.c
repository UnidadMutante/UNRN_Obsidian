#include <stdio.h>

int main(void)
{
    float cargaActual, consumo, tiempoRestante; 
    
    printf("Ingrese la carga actual de la bateria: ");
    scanf("%f", &cargaActual);
    
    printf("Ingrese el consumo instantaneo del dispositivo: ");
    scanf("%f", &consumo);
    
    if (cargaActual < 0.0f || cargaActual > 100.0f) {
         printf("Porcentaje de carga fuera de rango");
    }
    else if (consumo <= 0.0f) {
        printf("El consumo del sensor no puede ser 0 ni menor a 0");
    }
    else if (cargaActual > 50) {
        printf("Estado optimo");
    } 
    else if (cargaActual >= 15) {
        printf("Estado moderado");
    }
    else {
         tiempoRestante = (cargaActual * 0.5f) / consumo;
          printf("Estado critico. El tiempo restante es: %2f horas de uso\n", tiempoRestante);
    }
    
    return 0;
}