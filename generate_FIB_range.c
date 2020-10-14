/*
 * generate_FIB_range.c
 *
 * Code generation for function 'generate_FIB_range'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FIB_number.h"
#include "generate_FIB_range.h"
#include "update_parameters_FIB.h"
#include <stdio.h>

/* Function Definitions */
void generate_FIB_range(double i, double N_max, const double current_range[2],
  double new_range[2])
{
  double rho;
  double dd;
  double length_old;
  rho = FIB_number(N_max - i) / FIB_number((N_max - i) + 2.0);
  if (i == N_max) {
    dd = 0.01;
  } else {
    dd = 0.0;
  }

  /*  previous range */
  length_old = current_range[1] - current_range[0];
  new_range[0] = current_range[0] + (rho - dd) * length_old;
  new_range[1] = current_range[0] + ((1.0 - rho) + dd) * length_old;
}

/* End of code generation (generate_FIB_range.c) */
