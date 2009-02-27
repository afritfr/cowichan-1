/**
 * Conway's game of life
 *
 * \file life.cpp
 * \author Andrew Borzenko
 * \date 01-26-09
 */

#include "../include/main.h"
#ifdef IS_PARALLEL
  #include "parallel.h"
#else
  #include "serial.h"
#endif

int main(int argc, char* argv[])
{
#ifdef IS_PARALLEL
  mpi::environment env(argc, argv);
  mpi::communicator world;

  printf ("I am process %d\n", world.rank ());
#endif

  bool2D* matrix; /* world to evolve */
  int    nr;    /* row size */
  int    nc;    /* column size */
  int    iters; /* number of iterations */

  int i, j;

  srand (222);

  nr = MAXEXT;
  nc = MAXEXT;
  iters = 10;

  matrix = new bool2D[MAXEXT];
  for (i = 0; i < nr; i++)
  {
    for (j = 0; j < nc; j++)
    {
      matrix[i][j] = rand () % 2;
    }
  }

  print_matrix (matrix, nr, nc);

#ifdef IS_PARALLEL
  life_mpi (world, matrix, nr, nc, iters);
#else
  life (matrix, nr, nc, iters);
#endif

  print_matrix (matrix, nr, nc);

  delete [] matrix;

  return 0;
}
