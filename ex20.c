#include <stdio.h>
#include <omp.h>

int main() {

    int vetor[] = {2, 4, 6, 8, 10};
    int n = 5;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            int soma = 0;

            for (int i = 0; i < n; i++) {
                soma += vetor[i];
            }

            printf("Soma = %d | Thread %d\n",
                   soma, omp_get_thread_num());
        }

        #pragma omp section
        {
            int produto = 1;

            for (int i = 0; i < n; i++) {
                produto *= vetor[i];
            }

            printf("Produto = %d | Thread %d\n",
                   produto, omp_get_thread_num());
        }

        #pragma omp section
        {
            int menor = vetor[0];

            for (int i = 1; i < n; i++) {
                if (vetor[i] < menor) {
                    menor = vetor[i];
                }
            }

            printf("Menor valor = %d | Thread %d\n",
                   menor, omp_get_thread_num());
        }
    }

    return 0;
}