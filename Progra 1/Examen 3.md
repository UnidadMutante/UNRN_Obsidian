- recursion
- pila
- complejidad
- ordenamiento TODO 
- los ultimos temas que vimos post parcial 2

**¿Cuál es la ventaja principal del QuickSort Iterativo?**

Respuesta:

> Evita utilizar la pila de llamadas del sistema y reduce el riesgo de Stack Overflow en arreglos muy grandes, utilizando una pila implementada manualmente mediante memoria dinámica (`malloc`).


1. Ejercicio de Escritorio (Papel y Lápiz): ● Objetivo: Comprender exactamente cómo los índices entran y salen del Stack simulado, consolidando el concepto LIFO. ● Consigna: Se da el arreglo [8, 2, 5, 3, 9, 4]. Asumiendo que usamos partición de Lomuto (el último elemento es el pivote), dibuja el estado del arreglo y el contenido exacto de la pila de índices [low, high] en cada iteración del ciclo while hasta que la pila quede vacía. 


2. Ejercicio de Adaptación (Programación en C): "Quick Sort en el Catálogo" ● Objetivo: Aplicar el algoritmo genérico de enteros a un Tipo de Dato Abstracto (TAD) con estructuras reales. ● Consigna: Tomando el TAD de un Catalogo de películas, implementa la función ordenarPorId_QuickSortIterativo(Catalogo cat).