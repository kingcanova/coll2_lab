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
  int finalArr[numprocs];

  struct timeval time;
  gettimeofday(&time, NULL);
  srand48((unsigned int)time.tv_usec + rank);

  //Init the array with random values between 0 and 9
  for(int i = 0; i < numprocs; i++)
  {
    int x = drand48() * 10;
    myArr[i] = x;
  }

  //Then scan all of the arrays to get a prefix sum answer and put it into finalArray so that proc 0 can print it
  MPI_Scan(&myArr,&finalArr,numprocs,MPI_Int,MPI_SUM,MPI_COMM_WORLD);
  printf("The prefix sums are as follows \n");
  if(rank == 0)
  {
    for(int i = 0; i < numprocs; i++)
    {
      printf("[ %d ] ", finalArr[i]);
    }
  }
  




  MPI_Finalize();
  return 0;
}
