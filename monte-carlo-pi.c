/*
  @author Keith Grable, Tristan Canova
  @version 2017-10-16
  @file monte-carlo-pi.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <errno.h>

#include "timer.h"

int main(int argc, char *argv[])
{
  int rank, numprocs;
  long numpoints;
  
  MPI_Init(&argc, &argv);
  
  if(argc != 2)
  {
    fprintf(stderr, "Usage: %s numpoints\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  numpoints = atol(argv[1]);

  if(errno)
  {
    fprintf(stderr, "Usage: %s invalid format for numpoints\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }
  
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&numprocs);

  
  /* Set up random seed */
  struct timeval time;
  gettimeofday(&time, NULL);
  srand48((unsigned int)time.tv_usec + rank);

  printf("%5.9f\n", drand48());
  
  MPI_Finalize();
  
  return 0;
}
