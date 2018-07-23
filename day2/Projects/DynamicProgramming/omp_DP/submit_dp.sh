#!/bin/bash
# job submission script for midway for Dynamic Programming project

#SBATCH --job-name=dynamic_programming_project

#SBATCH --output=two_project_dp.out

# email alerts
#SBATCH --mail-type=BEGIN,END,DAIL

#SBATCH --account=osmlab

#SBATCH --ntasks=1

# number of CPUs to use
#SBATCH --cpus-per-task=2

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

#SBATCH --partition=sandyb

# run my process
./VFI
