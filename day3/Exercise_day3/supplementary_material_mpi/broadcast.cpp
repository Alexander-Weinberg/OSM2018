#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, data;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank==0) {
   	data = 9; // alex's favorite number
     }

    /* broadcast the value of data of rank 0 to all ranks */

    printf("I am rank %i and the value is %i\n", rank, data);
    MPI_Finalize();
    return 0;
}
