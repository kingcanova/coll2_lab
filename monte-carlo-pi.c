/*
  @author     Keith Grable, Tristan Canova
  @version    2017-10-16
  @file       monte-carlo-pi.c
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
  long circlepoints = 0;
  long min, max;
  
  double x, y;

  double mypi, pi;
  
  MPI_Init(&argc, &argv);
  
  if(argc != 2)
  {
    fprintf(stderr, "Usage: %s numpoints\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  numpoints = atol(argv[1]);


  /*
  if(errno)
  {
    fprintf(stderr, "Usage: %s invalid format for numpoints, you inputted %ld\n", argv[0], numpoints);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }
  */


  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
  
  /* Set up random seed */
  struct timeval time;
  gettimeofday(&time, NULL);
  srand48((unsigned int)time.tv_usec + rank);


  
  /* Compute pi */
  if(rank == 0)
    printf("Will use %ld points per process\n", numpoints);

  int i;

  //for each point
  for(i = 0; i < numpoints; i++)
  {
    //generate random coordinates
    x = drand48();
    y = drand48();

    //if a point within the circle is found
    //increment our count
    //sqrt is not needed cuz math
    if(x*x + y*y < 1.0)
      circlepoints++;
  }

  mypi = (4.0 * circlepoints) / numpoints; 



  /* Display process results */
  printf("[%d] %ld in circle, pi approx = %1.6f\n", rank, circlepoints, mypi);

  /* Get global values */
  MPI_Reduce(&circlepoints, &min, 1, MPI_LONG, MPI_MIN, 0, MPI_COMM_WORLD);
  MPI_Reduce(&circlepoints, &max, 1, MPI_LONG, MPI_MAX, 0, MPI_COMM_WORLD);

  MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  pi = pi / numprocs;
  
  if(rank == 0)
  {
    printf("in circle values range from %ld to %ld\n", min, max);
    printf("Final approximation of pi: %1.6f\n", pi);
  }
  
  MPI_Finalize();
  
  return 0;
}
