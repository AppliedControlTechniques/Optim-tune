/*
 * round.c
 *
 * Code generation for function 'round'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FIB_number.h"
#include "generate_FIB_range.h"
#include "update_parameters_FIB.h"
#include "round.h"
#include "mod.h"
#include "update_parameters_FIB_rtwutil.h"
#include <stdio.h>

/* Function Definitions */
void b_round(double x_data[], int x_size[2])
{
  int i1;
  int k;
  i1 = x_size[0] << 1;
  for (k = 0; k < i1; k++) {
    x_data[k] = rt_roundd_snf(x_data[k]);
  }
}

void c_round(double x[2])
{
  int k;
  for (k = 0; k < 2; k++) {
    x[k] = rt_roundd_snf(x[k]);
  }
}

/* End of code generation (round.c) */
