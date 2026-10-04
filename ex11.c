#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {

    int *A = malloc(N * sizeof(int));
    int *B = malloc(N * sizeof(int));
    int *C = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }

    printf("Primeiros resultados:\n");

    for (int i = 0; i < 10; i++) {
        printf("A[%d] = %d + B[%d] = %d -> C[%d] = %d\n",
               i, A[i], i, B[i], i, C[i]);
    }

    free(A);
    free(B);
    free(C);

    return 0;
}