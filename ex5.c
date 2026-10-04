#include <stdio.h>
#include <omp.h>

int main() {

    int contador_privado;

    #pragma omp parallel private(contador_privado)
    {
        contador_privado = 0;

        for (int i = 0; i < 100; i++) {
            contador_privado++;
        }

        printf("Thread %d: contador = %d\n",
               omp_get_thread_num(),
               contador_privado);
    }

    return 0;
}