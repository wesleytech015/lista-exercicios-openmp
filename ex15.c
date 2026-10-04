#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000

int main() {

    int *vetor = malloc(N * sizeof(int));
    int maior = 0;

    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 100000;
    }

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {

        #pragma omp critical
        {
            if (vetor[i] > maior) {
                maior = vetor[i];
            }
        }
    }

    printf("Maior valor encontrado: %d\n", maior);

    free(vetor);

    return 0;
}