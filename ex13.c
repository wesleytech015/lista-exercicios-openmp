#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000

int main() {

    int *M = malloc(N * N * sizeof(int));

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            M[i * N + j] = i + j;
        }
    }

    printf("Matriz %d x %d preenchida com sucesso.\n", N, N);

    printf("M[0][0] = %d\n", M[0 * N + 0]);
    printf("M[10][20] = %d\n", M[10 * N + 20]);
    printf("M[999][999] = %d\n", M[999 * N + 999]);

    free(M);

    return 0;
}