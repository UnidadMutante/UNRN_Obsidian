#include <stdio.h>
#define M 3
#define K 4

// params
// pre
// post
void transponer_estatica(size_t n, size_t m, const float orig [ ][K], float dest [ ][M]);

// params
// pre
// post
void imprimir_matriz(int n, int m, float *a);

int main (void) {
float A [M][K] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
float A_T [K][M];
transponer_estatica(M, K, A, A_T);
imprimir_matriz(M,K,&(A_T[0][0]));
return 0;
}

void imprimir_matriz(int n, int m, float *a) {
    for (size_t i=0; i < n; i++) {
        for(size_t j=0; j < m; j++) {
            printf(" %.2f," , a[i*m+j]);
        }
        printf("\n");
    }
    printf("\n");
}
void transponer_estatica(size_t n, size_t m, const float orig[ ][K], float dest[ ][M]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        dest[j][i] = orig[i][j];
    }
    printf("\n");
}
}


