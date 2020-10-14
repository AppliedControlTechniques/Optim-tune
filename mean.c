/*
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FIB_number.h"
#include "generate_FIB_range.h"
#include "update_parameters_FIB.h"
#include "mean.h"
#include <stdio.h>

/* Function Definitions */
double b_mean(const double x[2])
{
  return (x[0] + x[1]) / 2.0;
}

double mean(const double x_data[], const int x_size[2])
{
  double y;
  int k;
  y = x_data[0];
  for (k = 2; k <= x_size[1]; k++) {
    y += x_data[k - 1];
  }

  y /= (double)x_size[1];
  return y;
}

/* End of code generation (mean.c) */
