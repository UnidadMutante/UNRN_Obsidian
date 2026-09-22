#include <stdio.h>

#define M 3
#define K 4

// 'orig' es const porque la función solo LEE la matriz original,
// nunca la modifica.
void transponer_estatica(int m, int k, const float orig[][K], float dest[][M]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            dest[j][i] = orig[i][j];
        }
    }
}

int main() {
    float A[M][K] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    float A_T[K][M];

    transponer_estatica(M, K, A, A_T);

    printf("Matriz original A (%dx%d):\n", M, K);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            printf("%.1f ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz transpuesta A_T (%dx%d):\n", K, M);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < M; j++) {
            printf("%.1f ", A_T[i][j]);
        }
        printf("\n");
    }

    return 0;
}