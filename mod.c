/*
 * mod.c
 *
 * Code generation for function 'mod'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FIB_number.h"
#include "generate_FIB_range.h"
#include "update_parameters_FIB.h"
#include "mod.h"
#include "update_parameters_FIB_rtwutil.h"
#include <stdio.h>

/* Function Definitions */
double b_mod(double x, double y)
{
  double r;
  if (y == floor(y)) {
    r = x - floor(x / y) * y;
  } else {
    r = x / y;
    if (fabs(r - rt_roundd_snf(r)) <= 2.2204460492503131E-16 * fabs(r)) {
      r = 0.0;
    } else {
      r = (r - floor(r)) * y;
    }
  }

  return r;
}

/* End of code generation (mod.c) */
