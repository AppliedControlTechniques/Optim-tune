/*
 * update_parameters_FIB.h
 *
 * Code generation for function 'update_parameters_FIB'
 *
 */

#ifndef __UPDATE_PARAMETERS_FIB_H__
#define __UPDATE_PARAMETERS_FIB_H__

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

  extern void update_parameters_FIB(double input, double main_iteration_counter,
    const double P1_range[2], const double P2_range[2], double N_c, double N_max,
    double Par_initial, double method, double comments, double output[4]);

#ifdef __cplusplus

}
#endif
#endif

/* End of code generation (update_parameters_FIB.h) */
