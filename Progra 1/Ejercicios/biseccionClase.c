#include <stdio.h>

float funcion(float x) 
{
    return (x - 5);
    /*
1. Funcion y = x*x − 4 ;, intervalo=[0.0, 3.0], error=1e-5
2. Funcion y = x*x*x − x − 2 ;, intervalo=[1.0, 2.0], error=1e-6
3. Funcion , intervalo=[5.0, 10.0], error=1e-4
4. Funcion , intervalo=[-1.0, 1.0], error=1e-4

*/
}

float biseccion(float a, float b, float tol) {

    float c = (a+b)/2;

    if (funcion(a)*funcion(b)>0) {
        return 0;
    }

    while (funcion(c)!=0 && (b-a)/2 > tol) {
            b=c;
        } else {
            a = c;
        }
    c = (a+b)/2;
    printf("a:%f - b:%f - c:%f\n", a, b, c);
    }
    return c;    
}

int main(void)
{
    // pongo los valores del intervalo que quiero testear en a y b + pongo el nivel de tolerancia que acepto para encontrar el punto en "tol"
    float a = 3; // para testear, con la funcion x -5, se que con este calir x-5 = -2
    float b = 6; // para testear, con la funcion x -5, se que con este calir 6-5 = 1
    float tol = 0.00001;
    float raiz;

    //funcion(a)*funcion(b) = -2 * 1 = -2
    raiz = biseccion(a, b, tol);
    printf("la raiz es %f", raiz); 

    return 0;
}