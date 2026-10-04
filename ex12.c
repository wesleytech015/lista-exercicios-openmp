#include <stdio.h>
#include <omp.h>

#define N 1000000

int main() {

    long long resultado = 0;

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        resultado += 1 * 2;
    }

    printf("Resultado obtido: %lld\n", resultado);
    printf("Resultado esperado: %d\n", N * 2);

    return 0;
}