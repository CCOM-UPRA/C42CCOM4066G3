/*
 * Monte Carlo Estimation of Pi using MPI
 *
 * Completar las secciones marcadas con TODO.
 * 
 * Instrucciones:
 *   Compilar: mpicc -O2 -o pi_montecarlo pi_montecarlo.c
 *   Ejecutar: mpirun -np <num_procesos> ./pi_montecarlo <total_samples>
 *
 * total_samples debe ser un entero largo (p.ej. 100000000)
 */

 #include <mpi.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 
 int main(int argc, char **argv) {
     int rank, size;
     long long int local_count = 0;
     long long int total_count = 0;
     long long int total_samples = 0;
     long long int samples_per_proc = 0;
     double start, end;
 
     /* TODO 1: Inicializar el entorno MPI (MPI_Init) y obtener rank y size */
 
     /* TODO 2: Validar el argumento de entrada en el proceso 0. Enviar
                total_samples a todos los procesos (MPI_Bcast)           */
 
     /* TODO 3: Calcular samples_per_proc = total_samples / size         */
 
     /* TODO 4: Sembrar una semilla diferente por proceso
                (time(NULL) + rank)                                      */
 
     /* TODO 5: Generar points (x,y) aleatorios y contar los que caen
                dentro del círculo de radio 1.                           */
 
     /* TODO 6: Reducir los conteos locales en total_count usando
                MPI_Reduce                                               */
 
     /* TODO 7: En el proceso 0, calcular pi_estimate =
                4 * total_count / total_samples y mostrar resultados     */
 
     /* TODO 8: Finalizar MPI (MPI_Finalize)                             */
 
     return 0;
 }
 