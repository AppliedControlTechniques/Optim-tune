/*
 * isequal.c
 *
 * Code generation for function 'isequal'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FIB_number.h"
#include "generate_FIB_range.h"
#include "update_parameters_FIB.h"
#include "isequal.h"
#include <stdio.h>

/* Function Definitions */
boolean_T b_isequal(const double varargin_1[2], const double varargin_2[2])
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(varargin_1[k] == varargin_2[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  return p;
}

boolean_T isequal(double varargin_1, double varargin_2)
{
  boolean_T p;
  boolean_T b_p;
  p = false;
  b_p = true;
  if (!(varargin_1 == varargin_2)) {
    b_p = false;
  }

  if (!b_p) {
  } else {
    p = true;
  }

  return p;
}

/* End of code generation (isequal.c) */
