![[Pasted image 20260915155747.png]]

![[Pasted image 20260915164132.png]]

![[Pasted image 20260915164533.png]]

1. Definir las dimensiones estaticas de prueba
#define M 3
#define K 4

2. Declarar la matriz orifinal A de dimension MxK y la matriz transpuesrta A T de dimension KxM

float a\[M]\[K];
float A_T \[K]\[M];

La matriz transpuesta invierte sus dimensiones a KxM

3. implementar la funcion de transposicion:
4. 
void transponer_estatica(int M, int K, const float orig \[ \] \[ K\], float dest \[ \] [M])

const float orig -> es const porque la original no quiero modificarla sin querer

float dest -> no es const proque quiero poder modificarla

4. En la funcion main inicializar A con valores de prueba, realizar la transposicion e imprimir ambas matrices. 

