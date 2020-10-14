/*
 * FIB_number.c
 *
 * Code generation for function 'FIB_number'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FIB_number.h"
#include "generate_FIB_range.h"
#include "update_parameters_FIB.h"
#include <stdio.h>

/* Function Definitions */
double FIB_number(double n)
{
  double FFF;
  double F;
  double FF;
  int i;
  FFF = 0.0;
  if (n > 0.0) {
    F = 0.0;
    FF = 1.0;
    for (i = 0; i < (int)n; i++) {
      FFF = FF + F;
      F = FF;
      FF = FFF;
    }
  } else {
    FFF = 1.0;
  }

  return FFF;
}

/* End of code generation (FIB_number.c) */
