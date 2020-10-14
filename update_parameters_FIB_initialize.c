/*
 * update_parameters_FIB_initialize.c
 *
 * Code generation for function 'update_parameters_FIB_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FIB_number.h"
#include "generate_FIB_range.h"
#include "update_parameters_FIB.h"
#include "update_parameters_FIB_initialize.h"
#include "update_parameters_FIB_data.h"
#include <stdio.h>

/* Named Constants */
#define b_iteration                    (0.0)
#define b_J                            (0.0)
#define b_changed_parameter            (1.0)

/* Function Definitions */
void update_parameters_FIB_initialize(void)
{
  rt_InitInfAndNaN(8U);
  changed_parameter = b_changed_parameter;
  J = b_J;
  iteration = b_iteration;
  memset(&information_matrix[0], 0, 343U * sizeof(double));
}

/* End of code generation (update_parameters_FIB_initialize.c) */
