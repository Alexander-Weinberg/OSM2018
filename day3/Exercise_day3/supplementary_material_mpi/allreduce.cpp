/*================================================
 * Program to compute the sum of all the ranks
 * 
 *   
 *    
 *=================================================*/

#include <stdio.h>
#include <iostream>
#include <mpi.h>
#include <math.h>
#include <stdio.h>

using namespace std;

int main(int argc, char **argv)
{
      int my_rank,tag,p, ierr, sum, worker, home;
      int master = 0;  /* processor performing total sum */

      MPI_Init(&argc,&argv);         
      MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); /* Store each rank's number*/        
      MPI_Comm_size(MPI_COMM_WORLD, &p);       /* Store the total number of ranks */     

      cout << "I am rank: " << my_rank << endl;

      MPI_Send(        /* Send my_rank from each rank to master */
              &my_rank, 1, MPI_INT, /* Content of message */
              master,        /* message destination */
              tag,          /* message tag */
              MPI_COMM_WORLD);

      if(my_rank == master) {
        sum = 0;
        for (worker=0; worker< p; worker++) 
	{   /* for-loop serializes receives */
          MPI_Recv(         /* Receive my_int from proc to master  */
                &my_rank, 1, MPI_FLOAT, 
                worker,        /* message source */
                tag,         /* message tag */
                MPI_COMM_WORLD, MPI_STATUS_IGNORE);     /* status reports source, tag */
          sum += my_rank;
        }
        cout << " Sum of all the ranks = " << sum << endl; /* sum of my_int */
      }
      MPI_Finalize();                        /* let MPI finish up ... */
}

