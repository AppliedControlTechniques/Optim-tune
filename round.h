/*
 * round.h
 *
 * Code generation for function 'round'
 *
 */

#ifndef __ROUND_H__
#define __ROUND_H__

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

  extern void b_round(double x_data[], int x_size[2]);
  extern void c_round(double x[2]);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (round.h) */
