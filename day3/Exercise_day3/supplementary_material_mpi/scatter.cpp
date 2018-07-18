#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int i, rank, size, senddata, recievedata;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (size>20) {
        if (rank==0)
            printf("do not use more than 20 processors\n");
        MPI_Finalize();
        exit(1);
        
    }

    /* scatter the value of senddata of rank 0 to receivedata of all ranks */
    if (rank==0) {
        int senddata = 9; // alex's favorite number
        for (i=0; i<size; i++) {
        
	MPI_Send(&senddata, 1, MPI_INT, /* message content */
		i,	/* message destination */
		0, 	/* message tag */
		MPI_COMM_WORLD /* communication type */
		);
        }
    }
   
    MPI_Recv(&recievedata, 1, MPI_INT, /* message content */
	     0,		/* message source */
	     0,		/* message tag */
             MPI_COMM_WORLD, /* comm type */
	     MPI_STATUS_IGNORE);

    printf("I am rank %i and the value is %i\n", rank, recievedata);
    MPI_Finalize();
    return 0;
}
