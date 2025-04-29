#include <stdio.h>
#include <stdlib.h>

#define N 1000000        // Tamaño del arreglo
#define OBJETIVO 999999  // Número a buscar

int main() {
    int *arr = malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("No se pudo asignar memoria\n");
        return 1;
    }

    // TODO: Inicializa el arreglo con números aleatorios de forma paralela
    // Pista: Usa un bloque paralelo y divide el trabajo con una directiva tipo "for"
    {
        // unsigned int seed = ...;  // Cada hilo debe tener su propia semilla

        for (int i = 0; i < N; i++) {
            // arr[i] = rand_r(&seed) % 1000000;
        }
    }

    int resultado = -1;

    // TODO: Realiza una búsqueda del número OBJETIVO en el arreglo de forma paralela
    // Pista: Usa una estructura "parallel for" y protege el acceso a `resultado` con una sección crítica
    for (int i = 0; i < N; i++) {
        if (arr[i] == OBJETIVO) {
            int encontrado = 0;

            // TODO: Sección crítica aquí para asegurar que solo un hilo actualice `resultado`
            {
                if (resultado == -1) {
                    resultado = i;
                    encontrado = 1;
                }
            }

            // TODO: Implementa una forma de cancelar el resto de las iteraciones si ya se encontró el número
            // Pista: Revisa cómo usar cancelación temprana en OpenMP (versión 4.0+)
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

