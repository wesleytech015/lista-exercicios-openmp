#include <stdio.h>
#include <omp.h>

#define N 1000000

int main() {

    int contador = 0;

    #pragma omp parallel for
    for (int i = 1; i <= N; i++) {

        if (i % 3 == 0) {

            #pragma omp atomic
            contador++;
        }
    }

    printf("Multiplos de 3 encontrados: %d\n", contador);

    return 0;
}