/**
 * Successive over-relaxation
 *
 * \file sor.cpp
 * \author Andrew Borzenko
 * \date 03-02-09
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

  real2D* matrix;
  real1D* vector;
  real1D* answer;
  int n;
  int limit;
  int i, j;
  real tolerance;
  real max;

  n = MAXEXT;
  limit = 10;
  tolerance = 10e-6;

  srand (333);

  matrix = new real2D[MAXEXT];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      matrix[i][j] = rand () % limit;
      if (matrix[i][j] > max) {
        max = matrix[i][j];
      }
    }
  }
  // ensure diagonally dominant
  max *= n;
  for (i = 0; i < n; i++) {
    matrix[i][i] = max;
  }

  vector = new real1D[MAXEXT];
  for (i = 0; i < n; i++) {
    vector[i] = rand () % limit;
  }

  answer = new real1D[MAXEXT];

  //printf ("Matrix is:\n");
  //print_matrix (matrix, n, n);

  //printf ("Vector is:\n");
  //print_vector (vector, n);

#ifdef IS_PARALLEL
  sor_mpi (world, matrix, vector, answer, n, tolerance);
#else
  sor (matrix, vector, answer, n, tolerance);
#endif

  //printf ("Answer is:\n");
  //print_vector (answer, n);

  return 0;
}
