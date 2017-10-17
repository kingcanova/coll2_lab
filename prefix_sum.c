/* Tristan Canova and Keith Grable Prefix sum */
#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <errno.h>

#include "timer.h"


int main(int argc, char *argv[])
{
  int rank,numprocs;

  MPI_Init(&argc,&argv);

  if(argc != 2)
  {
    MPI_Abort(MPI_COMM_WORLD,1);
  }
  
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&numprocs);

  int myArr[numprocs];

  struct timeval time;
  gettimeofday(&time, NULL);
  srand48((unsigned int)time.tv_usec + rank);

  






  
}
