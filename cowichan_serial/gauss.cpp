#include "cowichan_serial.hpp"

/**
 * Matrices are required to be symmetric and diagonally dominant in order to
 * guarantee that there is a well-formed solution to the equation.
 */
void CowichanSerial::gauss (Matrix matrix, Vector target, Vector solution)
{
  INT64 i, j, k;

  // forward elimination
  for (i = 0; i < n; i++) {
    // get row with maximum column i
    INT64 max = i;
    for (j = i + 1; j < n; j++) {
      if (fabs(MATRIX(matrix, j, i)) > fabs(MATRIX(matrix, max, i))) {
        max = j;
      }
    }

    real tmp;
    // swap max row with row i
    for (j = i; j < n; j++) {
      tmp = MATRIX(matrix, i, j);
      MATRIX(matrix, i, j) = MATRIX(matrix, max, j);
      MATRIX(matrix, max, j) = tmp;
    }
    tmp = target[i];
    target[i] = target[max];
    target[max] = tmp;

    // eliminate i-th column in j-th row
    real column_i = MATRIX(matrix, i, i);
    for (j = i + 1; j < n; j++) {
      real factor = -(MATRIX(matrix, j, i) / column_i);
      for (k = n - 1; k >= i; k--) {
        MATRIX(matrix, j, k) += MATRIX(matrix, i, k) * factor;
      }
      target[j] += target[i] * factor;
    }
  }

  // back substitution
  for (k = (n - 1); k >= 0; k--) {
    solution[k] = target[k] / MATRIX_SQUARE(matrix, k, k);
    for (i = k - 1; i >= 0; i--) {
      target[i] = target[i] - (MATRIX_SQUARE(matrix, i, k) * solution[k]);
    }
  }
}

