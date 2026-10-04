#include <stdio.h>
#include <omp.h>

#define N 100

int main() {

    int vetor[N];

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        vetor[i] = omp_get_thread_num();
    }

    printf("Vetor preenchido:\n");

    for (int i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    return 0;
}