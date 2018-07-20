#!/bin/bash
# job submission script for midway for Dynamic Programming project

# set job name
#SBATCH --job-name=dynamic_programming_project

# send output to file below
#SBATCH --output=project_dp.out

# email alerts
#SBATCH --mail-type=BEGIN,END,DAIL

#SBATCH --account=osmlab

# number of CPUs to use
#SBATCH --ntasks=1

#SBATCH --cpus-per-task=16

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

# specify which partition
#SBATCH --partition=sandyb

# run my process
./VFI
