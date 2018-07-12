#!/bin/bash

# this is a job-submission script to submit a batch to midway

# set the job name to hello­world
#SBATCH ­­job­name=hello

# send output to hello­world.out
#SBATCH ­­output=hello.out

# receive an email when job starts, ends, and fails 
#SBATCH ­­mail­type=BEGIN,END,DAIL

# this job requests 1 core. Cores can be selected from various nodes. 
#SBATCH ­­ntasks=1

# there are many partitions on Midway1 and it is important to specify which # partition you want to run your job on. Not having the following option, the # sandby partition on Midway1 will be selected as the default partition 
#SBATCH ­­partition=sandyb

# Run the process with mpirun. Notice ­n is not required. mpirun will
# automatically figure out how many processes to run from the slurm options
./hidiho.exec
