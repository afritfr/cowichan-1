/**
 * Matrix-vector product
 *
 * \file product.cpp
 * \author Andrew Borzenko
 * \date 02-02-09
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

  real2D*	matrix;			/* to multiply by */
  real1D*	vector;			/* to be multiplied */
  real1D*	result;			/* result of multiply */
  int		nr;			/* row size */
  int		nc;			/* column size */
  int limit;
  int i, j;

  srand (222);

  nr = MAXEXT;
  nc = MAXEXT;
  limit = 10;

  matrix = new real2D[MAXEXT];
  for (i = 0; i < nr; i++)
  {
    for (j = 0; j < nc; j++)
    {
      matrix[i][j] = (real) (rand () % limit);
    }
  }

  vector = new real1D[MAXEXT];
  for (i = 0; i < nr; i++)
  {
    vector[i] = (real) (rand () % limit);
  }

  result = new real1D[MAXEXT];

  printf ("Matrix\n");
  print_matrix (matrix, nr, nc);
  printf ("x Vector\n");
  print_vector (vector, nr);

#ifdef IS_PARALLEL
  product_mpi (world, matrix, vector, result, nr, nc);
#else
  product (matrix, vector, result, nr, nc);
#endif

  printf ("=\n");
  print_vector (result, nr);

  delete [] matrix;
  delete [] vector;
  delete [] result;

  return 0;
}
