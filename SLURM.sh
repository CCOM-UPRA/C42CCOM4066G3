#!/bin/bash
#SBATCH -J Monte-Carlo
#SBATCH -A gen243            # tu cuenta de proyecto
#SBATCH -N 1                 # 1 nodo
#SBATCH --ntasks-per-node=32 # 32 procesos MPI
#SBATCH -t 00:01:00
#SBATCH --output=pi_solution_%j.out

# 1. Empezar limpio
module purge

# 2. Cargar la toolchain Cray con MPICH
module load PrgEnv-cray      # wrappers cc, CC, ftn
module load cray-mpich       # MPI real

# 3. Ejecutable ya compilado (o compílalo aquí con CC)
EXEC=./pi_montecarlo_solution
TOTAL_SAMPLES=9999999

# 4. Lanzar — deja que Slurm escoja el plugin por defecto (PMI2)
srun $EXEC $TOTAL_SAMPLES
