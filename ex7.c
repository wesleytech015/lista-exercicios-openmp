#include <stdio.h>
#include <omp.h>

int dados[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {

    int soma_local;

    #pragma omp parallel private(soma_local)
    {
        int id = omp_get_thread_num();
        int total = omp_get_num_threads();

        int inicio = id * 10 / total;
        int fim = (id + 1) * 10 / total;

        soma_local = 0;

        for (int i = inicio; i < fim; i++) {
            soma_local += dados[i];
        }

        printf("Thread %d: indices %d a %d, soma = %d\n",
               id, inicio, fim - 1, soma_local);
    }

    return 0;
}