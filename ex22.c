#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void executar(int N) {

    double *M = malloc((long long)N * N * sizeof(double));
    double *V = malloc(N * sizeof(double));
    double *R = malloc(N * sizeof(double));

    if (M == NULL || V == NULL || R == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    // Preenchimento
    for (long long i = 0; i < (long long)N * N; i++) {
        M[i] = 1.0;
    }

    for (int i = 0; i < N; i++) {
        V[i] = 1.0;
    }

    double inicio = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {

        double soma = 0.0;

        for (int j = 0; j < N; j++) {
            soma += M[(long long)i * N + j] * V[j];
        }

        R[i] = soma;
    }

    double fim = omp_get_wtime();

    printf("Matriz %d x %d\n", N, N);
    printf("Resultado R[0] = %.0f\n", R[0]);
    printf("Tempo = %.6f segundos\n\n", fim - inicio);

    free(M);
    free(V);
    free(R);
}

int main() {

    printf("Multiplicacao Matriz x Vetor\n\n");

    executar(1000);
    executar(5000);

    return 0;
}