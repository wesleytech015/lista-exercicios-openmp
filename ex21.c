#include <stdio.h>
#include <omp.h>

#define N 1000000000LL

int main() {

    double soma = 0.0;
    double inicio, fim;

    // SERIAL
    inicio = omp_get_wtime();

    for (long long i = 0; i < N; i++) {
        double termo = (i % 2 == 0 ? 1.0 : -1.0) / (2.0 * i + 1.0);
        soma += termo;
    }

    fim = omp_get_wtime();

    printf("SERIAL\n");
    printf("Pi = %.10f\n", 4.0 * soma);
    printf("Tempo = %.6f segundos\n\n", fim - inicio);

    int threads[] = {2, 4, 8};

    for (int t = 0; t < 3; t++) {

        soma = 0.0;
        omp_set_num_threads(threads[t]);

        inicio = omp_get_wtime();

        #pragma omp parallel for reduction(+:soma)
        for (long long i = 0; i < N; i++) {
            double termo =
                (i % 2 == 0 ? 1.0 : -1.0) / (2.0 * i + 1.0);

            soma += termo;
        }

        fim = omp_get_wtime();

        printf("%d THREADS\n", threads[t]);
        printf("Pi = %.10f\n", 4.0 * soma);
        printf("Tempo = %.6f segundos\n\n", fim - inicio);
    }

    return 0;
}