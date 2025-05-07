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
 #include <iostream>
 #include <mpi.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <omp.h>
 #include <random>
 
 int main(int argc, char **argv) {//argc may be the total samples
     int rank, size;
     long long int local_count = 0;
     long long int total_count = 0;
     long long int total_samples = 0;
     long long int samples_per_proc = 0;
     double start, end;
     /* 1: Inicializar el entorno MPI (MPI_Init) y obtener rank y size */
     MPI_Init(&argc, &argv);
     MPI_Comm_size(MPI_COMM_WORLD, &size);
     MPI_Comm_rank(MPI_COMM_WORLD, &rank);
     /* 2: Validar el argumento de entrada en el proceso 0. Enviar
                total_samples a todos los procesos (MPI_Bcast)           */  
     if (rank == 0) {
         for (int c = 1; c < size; c++) {
             MPI_Send(&total_samples, 1, MPI_INT, c, 0, MPI_COMM_WORLD);
         }
     } else {
         MPI_Recv(&total_samples, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
     }
     /* 3: Calcular samples_per_proc = total_samples / size.*/
     samples_per_proc = total_samples / size;
     /* 4: Sembrar una semilla diferente por proceso (time(NULL) + rank)                                */
     std::mt19937_64 seed(time(nullptr) + rank);
     std::uniform_real_distribution<> rng(0.0, 1.0); // Define the rng range
     /* 5: Generar points (x,y) aleatorios y contar los que caen dentro del círculo de radio 1.    */
     for(int i = 0; i < samples_per_proc; i++) {
         //Obtain the (x,y) point
         start = rng(seed);
         end = rng(seed);
         double dist = start * start + end * end;
         //Check if it's in the circle'
         if (dist <= 1) {
             local_count++;
         }
     }
     /* 6: Reducir los conteos locales en total_count usando MPI_Reduce                                 */
     MPI_Reduce(&local_count, &total_count, 1, MPI_LONG_LONG_INT, MPI_SUM, 0, MPI_COMM_WORLD);
     /* 7: En el proceso 0, calcular pi_estimate = 4 * total_count / total_samples y mostrar resultados */
     if (rank == 0) {
         double pi_estimate = 4 * (total_count / total_samples);
         std::cout << "Valor estimado de PI: " << pi_estimate << std::endl;
         std::cout << "Numero de procesadores: " << size << std::endl;
         std::cout << "Numero de samples: " << total_samples << std::endl;
     }
     /* 8: Finalizar MPI (MPI_Finalize) */
     MPI_Finalize();
     return 0;
 }
 
