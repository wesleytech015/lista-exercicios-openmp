#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {

    int *vetor = malloc(N * sizeof(int));
    long long soma = 0;

    for (int i = 0; i < N; i++) {
        vetor[i] = 1;
    }

    #pragma omp parallel for reduction(+:soma)
    for (int i = 0; i < N; i++) {
        soma += vetor[i];
    }

    printf("Soma final: %lld\n", soma);

    free(vetor);

    return 0;
}