#include <stdio.h>
#include <omp.h>

#define N 100

int main() {

    int vetor[N];

    #pragma omp parallel shared(vetor)
    {
        int id = omp_get_thread_num();
        int total = omp_get_num_threads();

        int istart = id * N / total;
        int iend = (id + 1) * N / total;

        for (int i = istart; i < iend; i++) {
            vetor[i] = id;
        }

        printf("Thread %d: posicoes %d ate %d\n",
               id, istart, iend - 1);
    }

    printf("\nVetor preenchido:\n");

    for (int i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    return 0;
}