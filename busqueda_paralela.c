#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000        // Tamaño del arreglo
#define OBJETIVO 999999  // Número a buscar

int main() {
    int *arr = malloc(N * sizeof(int));
    if (arr == NULL) {//El programa no funciona sin memoria asignada
        printf("No se pudo asignar memoria\n");
        return 1;
    }

    // Inicializa el arreglo con números aleatorios de forma paralela
    #pragma omp parallel
    {
        unsigned int seed = time(NULL);
        srand(seed);  // Cada hilo debe tener su propia semilla
        #pragma omp parallel for
        for (int i = 0; i < N; i++) {
            arr[i] = rand_r(&seed) % 1000000;
        }
        #pragma omp barrier
    }

    int resultado = -1;

    // Realiza una búsqueda del número OBJETIVO en el arreglo de forma paralela
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        if (arr[i] == OBJETIVO) {
            int encontrado = 0;

            // Sección crítica aquí para asegurar que solo un hilo actualice `resultado`
            #pragma omp critical
            {
                if (resultado == -1) {
                    resultado = i;
                    encontrado = 1;
                }
            }
            // Implementa una forma de cancelar el resto de las iteraciones si ya se encontró el número
            #pragma omp cancel for
        }
    }

    if (resultado != -1) {
        printf("El número %d se encontró en el índice: %d\n", OBJETIVO, resultado);
    } else {
        printf("El número %d no se encontró en el arreglo.\n", OBJETIVO);
    }

    free(arr);
    return 0;
}

