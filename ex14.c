#include <stdio.h>
#include <omp.h>

#define N 10000

void trabalho(int quantidade) {
    volatile long long x = 0;

    for (int j = 0; j < quantidade; j++) {
        x += j;
    }
}

int main() {

    double inicio, fim;

    // STATIC
    inicio = omp_get_wtime();

    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++) {
        trabalho((N - i) * 1000);
    }

    fim = omp_get_wtime();
    printf("Tempo STATIC:  %.6f segundos\n", fim - inicio);

    // DYNAMIC
    inicio = omp_get_wtime();

    #pragma omp parallel for schedule(dynamic, 1)
    for (int i = 0; i < N; i++) {
        trabalho((N - i) * 1000);
    }

    fim = omp_get_wtime();
    printf("Tempo DYNAMIC: %.6f segundos\n", fim - inicio);

    // GUIDED
    inicio = omp_get_wtime();

    #pragma omp parallel for schedule(guided)
    for (int i = 0; i < N; i++) {
        trabalho((N - i) * 1000);
    }

    fim = omp_get_wtime();
    printf("Tempo GUIDED:  %.6f segundos\n", fim - inicio);

    return 0;
}