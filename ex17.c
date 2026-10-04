#include <stdio.h>
#include <omp.h>

#define N 4

int main() {

    int valores[N];

    #pragma omp parallel num_threads(N) shared(valores)
    {
        int id = omp_get_thread_num();

        // Fase 1
        valores[id] = (id + 1) * 10;

        printf("Thread %d - Fase 1: valor = %d\n",
               id, valores[id]);

        // Espera todas as threads terminarem a Fase 1
        #pragma omp barrier

        // Fase 2
        int soma = 0;

        for (int i = 0; i < N; i++) {
            soma += valores[i];
        }

        printf("Thread %d - Fase 2: soma = %d\n",
               id, soma);
    }

    return 0;
}