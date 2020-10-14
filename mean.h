/*
 * mean.h
 *
 * Code generation for function 'mean'
 *
 */

#ifndef __MEAN_H__
#define __MEAN_H__

/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "update_parameters_FIB_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern double b_mean(const double x[2]);
  extern double mean(const double x_data[], const int x_size[2]);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (mean.h) */
