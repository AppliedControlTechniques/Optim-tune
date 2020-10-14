/*
 * update_parameters_FIB.c
 *
 * Code generation for function 'update_parameters_FIB'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FIB_number.h"
#include "generate_FIB_range.h"
#include "update_parameters_FIB.h"
#include "fprintf.h"
#include "isequal.h"
#include "mod.h"
#include "round.h"
#include "mean.h"
#include "update_parameters_FIB_data.h"
#include <stdio.h>

/* Function Declarations */
static void eml_null_assignment(double x_data[], int x_size[2], const boolean_T
  idx_data[], const int idx_size[2]);

/* Function Definitions */
static void eml_null_assignment(double x_data[], int x_size[2], const boolean_T
  idx_data[], const int idx_size[2])
{
  int nxin;
  int k0;
  int k;
  int nxout;
  double b_x_data[49];
  nxin = x_size[1];
  k0 = 0;
  for (k = 1; k <= idx_size[1]; k++) {
    k0 += idx_data[k - 1];
  }

  nxout = x_size[1] - k0;
  k0 = -1;
  for (k = 1; k <= nxin; k++) {
    if ((k > idx_size[1]) || (!idx_data[k - 1])) {
      k0++;
      x_data[k0] = x_data[k - 1];
    }
  }

  if (1 > nxout) {
    k0 = 0;
  } else {
    k0 = nxout;
  }

  for (nxout = 0; nxout < k0; nxout++) {
    b_x_data[nxout] = x_data[nxout];
  }

  x_size[0] = 1;
  x_size[1] = k0;
  for (nxout = 0; nxout < k0; nxout++) {
    x_data[x_size[0] * nxout] = b_x_data[nxout];
  }
}

void update_parameters_FIB(double input, double main_iteration_counter, const
  double P1_range[2], const double P2_range[2], double N_c, double N_max, double
  Par_initial, double method, double comments, double output[4])
{
  double indexes_similar_params;
  double controller_pars[2];
  double P_range[4];
  int i0;
  double b_P_range[2];
  double proposed_range[2];
  double new_range[2];
  int columns_size[2];
  int loop_ub;
  int k;
  double columns_data[98];
  int indexes_similar_params_size[2];
  double indexes_similar_params_data[49];
  int tmp_size[2];
  boolean_T tmp_data[49];
  double b_tmp_data[49];
  int b_tmp_size[2];
  double c_tmp_data[50];
  double i;
  int d_tmp_data[12];

  /*  input                     - incremental value of the performance index */
  /*  main_iteration_counter    - iterates from 1 to 48 */
  /*  P1_range                  - admissible range for the first parameter */
  /*  P2_range                  - admissible range for the second parameter */
  /*  N_c                       - number of samples to obtain J */
  /*  N_max                     - number of samples in a single iteration */
  /*  Par_initial               - initial value of the second parameter */
  /*  method - one of the below: */
  /*            = 0 - performance index calculated every time it is needed */
  /*            = 1 - performance index is averaged over all past measurements with the */
  /*                  same parameters */
  /*            = 2 - performance index is evaluated only for parameters that have been  */
  /*                  UNCONSIDERED BEFORE (the length of the tuning procedure is reduced) */
  /*  comments - one of the below: */
  /*            = 0 - all comments are turned off (silent mode) */
  /*            = 1 - comments are turned on */
  indexes_similar_params = -1.0;
  for (i0 = 0; i0 < 2; i0++) {
    controller_pars[i0] = 0.0;

    /*  create, if unnecessary (default value) */
    P_range[i0 << 1] = P1_range[i0];
    P_range[1 + (i0 << 1)] = P2_range[i0];
  }

  /*  initial range for the 1st parameter (1st row), and the 2nd parameter (2nd row) */
  /*  (matrix in which all data is stored) */
  /*  (current value of the performance index - updated every iteration) */
  /*  (iteration counter, for performance index update, see N_c and N_max) */
  /*  ID of the changed parameter (== 1 or 2) */
  if (isequal(main_iteration_counter, 0.0)) {
    /*  if the method is launched for the first time */
    b_fprintf();
    c_fprintf();
    d_fprintf();
    e_fprintf();
    f_fprintf();
    g_fprintf();
    b_fprintf();
    h_fprintf();
    i_fprintf();
    j_fprintf();
    k_fprintf();
    if (isequal(method, 1.0)) {
      l_fprintf();
    } else {
      if (isequal(method, 2.0)) {
        m_fprintf();
      }
    }

    n_fprintf();
    o_fprintf();
    p_fprintf();

    /*     fprintf(1,'\n>> Number of FIB iterations to obtain epsilon accuracy = %.6f',N_fib); */
    memset(&information_matrix[0], 0, 343U * sizeof(double));

    /*  generate empty matrix  */
    iteration = 0.0;

    /*  iteration counter (J update) */
    J = 0.0;

    /*  initial value of the performance index */
    changed_parameter = 1.0;

    /*  ID of the changed parameter */
    main_iteration_counter = 1.0;

    /*  main counter, defining rows of the information_matrix */
    for (i0 = 0; i0 < 12; i0++) {
      information_matrix[49 + i0] = 1.0;
    }

    /*  change the 1st paramter */
    information_matrix[0] = 1.0;

    /*  change the 1st paramter */
    for (i0 = 0; i0 < 2; i0++) {
      b_P_range[i0] = P_range[i0 << 1];
    }

    generate_FIB_range(1.0, 6.0, b_P_range, proposed_range);
    information_matrix[98] = P_range[0];

    /*  calculated value (1st row) */
    information_matrix[147] = P_range[2];

    /*  calculated value (1st row) */
    information_matrix[99] = P_range[0];

    /*  calculated value (1st row) */
    information_matrix[148] = P_range[2];

    /*  calculated value (1st row) */
    information_matrix[196] = proposed_range[0];

    /*  calculated value (1st row) */
    information_matrix[197] = proposed_range[1];

    /*  calculated value (2nd row) */
    for (i0 = 0; i0 < 12; i0++) {
      information_matrix[245 + i0] = Par_initial;
    }

    /*  calculated value */
    information_matrix[294] = 0.0;

    /*  value of the performance index */
    information_matrix[295] = 0.0;

    /*  value of the performance index */
  }

  /*  if ~exist('J') */
  iteration++;

  /*  increase the iteration number */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  if (isequal(main_iteration_counter, 49.0)) {
    /*  termiate the algorithm */
    controller_pars[0] = information_matrix[244];
    controller_pars[1] = information_matrix[293];
    if (isequal(iteration, 1.0)) {
      q_fprintf();
    }

    iteration = 9999.0;
    J = 0.0;
    main_iteration_counter++;
    r_fprintf();
    s_fprintf(controller_pars[0]);
    s_fprintf(controller_pars[1]);
  } else if (iteration < N_c) {
    /*  main iteration count,  */
    if (isequal(comments, 1.0)) {
      t_fprintf();
    }

    J += input;
    controller_pars[0] = information_matrix[(int)main_iteration_counter + 195];
    controller_pars[1] = information_matrix[(int)main_iteration_counter + 244];

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  } else if ((iteration == N_c) && (main_iteration_counter < 3.0)) {
    /*  measurements have ended, 1st row filled */
    if (isequal(comments, 1.0)) {
      u_fprintf();
    }

    J += input;
    if (b_mod(main_iteration_counter, 2.0) != 0.0) {
      /*  1 == is odd, % 0 == otherwise */
      information_matrix[(int)main_iteration_counter + 293] = J;
      controller_pars[0] = information_matrix[196 + (int)main_iteration_counter];
      controller_pars[1] = information_matrix[245 + (int)main_iteration_counter];
    } else {
      information_matrix[(int)main_iteration_counter - 1] =
        main_iteration_counter;
      information_matrix[(int)main_iteration_counter + 293] = J;

      /*  odd row (left-hand side in the range) */
      /*  even row (right-hand side in the range) */
      controller_pars[0] = information_matrix[(int)main_iteration_counter + 97];
      controller_pars[1] = information_matrix[(int)main_iteration_counter + 146];
      generate_FIB_range(1.0, 6.0, controller_pars, proposed_range);
      if (information_matrix[(int)main_iteration_counter + 292] <=
          information_matrix[(int)main_iteration_counter + 293]) {
        /*  reduce from the right */
        new_range[0] = information_matrix[(int)main_iteration_counter + 97];
        new_range[1] = proposed_range[1];
      } else {
        /*  reduce from the left */
        new_range[0] = proposed_range[0];
        new_range[1] = information_matrix[(int)main_iteration_counter + 146];
      }

      generate_FIB_range(2.0, 6.0, new_range, proposed_range);
      information_matrix[98 + (int)main_iteration_counter] = new_range[0];

      /*  odd row (new range, to-be-reduced) */
      information_matrix[147 + (int)main_iteration_counter] = new_range[1];
      information_matrix[(int)main_iteration_counter + 99] = new_range[0];

      /*  even row (new range, to-be-reduced) */
      information_matrix[(int)main_iteration_counter + 148] = new_range[1];
      information_matrix[196 + (int)main_iteration_counter] = proposed_range[0];

      /*   */
      information_matrix[(int)main_iteration_counter + 197] = proposed_range[1];

      /*   */
      controller_pars[0] = information_matrix[196 + (int)main_iteration_counter];
      controller_pars[1] = information_matrix[245 + (int)main_iteration_counter];
    }

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  } else if ((iteration == N_c) && (main_iteration_counter >= 3.0)) {
    /*  measurements have ended */
    if (isequal(comments, 1.0)) {
      u_fprintf();
    }

    J += input;
    if (isequal(method, 1.0)) {
      /*  the columns with computed parameters are there */
      columns_size[0] = (int)main_iteration_counter;
      columns_size[1] = 2;
      for (i0 = 0; i0 < 2; i0++) {
        loop_ub = (int)main_iteration_counter;
        for (k = 0; k < loop_ub; k++) {
          columns_data[k + (int)main_iteration_counter * i0] = 1000.0 *
            information_matrix[k + 49 * (4 + i0)];
        }
      }

      b_round(columns_data, columns_size);
      loop_ub = columns_size[0] << 1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        columns_data[i0] /= 1000.0;
      }

      /*  rounding to the 3-digits */
      for (i0 = 0; i0 < 2; i0++) {
        controller_pars[i0] = 1000.0 * information_matrix[((int)
          main_iteration_counter + 49 * (4 + i0)) - 1];
      }

      c_round(controller_pars);
      for (i0 = 0; i0 < 2; i0++) {
        controller_pars[i0] /= 1000.0;
      }

      loop_ub = (int)main_iteration_counter - 1;
      indexes_similar_params_size[0] = 1;
      indexes_similar_params_size[1] = 1 + loop_ub;
      indexes_similar_params_data[0] = -1.0;
      for (i0 = 0; i0 < loop_ub; i0++) {
        indexes_similar_params_data[i0 + 1] = 0.0;
      }

      /*  no matches found, prealoccating memory */
      for (k = 0; k < (int)main_iteration_counter; k++) {
        for (i0 = 0; i0 < 2; i0++) {
          b_P_range[i0] = columns_data[k + columns_size[0] * i0];
        }

        if (b_isequal(b_P_range, controller_pars)) {
          indexes_similar_params_data[k] = 1.0 + (double)k;
        }
      }

      tmp_size[0] = 1;
      tmp_size[1] = 1 + loop_ub;
      loop_ub++;
      for (i0 = 0; i0 < loop_ub; i0++) {
        tmp_data[i0] = (indexes_similar_params_data[i0] <= 0.0);
      }

      eml_null_assignment(indexes_similar_params_data,
                          indexes_similar_params_size, tmp_data, tmp_size);
      if (!(indexes_similar_params_size[1] == 0)) {
        /*  if any match has been found */
        if (isequal(comments, 1.0)) {
          v_fprintf(J);
        }

        if (isequal(indexes_similar_params_data[indexes_similar_params_size[1] -
                    1], main_iteration_counter)) {
          if (1 > indexes_similar_params_size[1] - 1) {
            loop_ub = 1;
          } else {
            loop_ub = indexes_similar_params_size[1];
          }

          b_tmp_size[0] = 1;
          b_tmp_size[1] = loop_ub;
          for (i0 = 0; i0 <= loop_ub - 2; i0++) {
            b_tmp_data[i0] = information_matrix[(int)
              indexes_similar_params_data[i0] + 293];
          }

          b_tmp_data[loop_ub - 1] = J;
          J = mean(b_tmp_data, b_tmp_size);

          /*  mean value is stored */
        } else {
          b_tmp_size[0] = 1;
          b_tmp_size[1] = indexes_similar_params_size[1] + 1;
          loop_ub = indexes_similar_params_size[1];
          for (i0 = 0; i0 < loop_ub; i0++) {
            c_tmp_data[i0] = information_matrix[(int)
              indexes_similar_params_data[indexes_similar_params_size[0] * i0] +
              293];
          }

          c_tmp_data[indexes_similar_params_size[1]] = J;
          J = mean(c_tmp_data, b_tmp_size);

          /*  mean value is stored */
        }

        if (isequal(comments, 1.0)) {
          w_fprintf(J);
        }
      }

      /*  does not change the rest of the algorithm */
    }

    if (b_mod(main_iteration_counter, 2.0) != 0.0) {
      /*  1 == is odd, % 0 == otherwise */
      /*  1) store in information_matrix the current value of J */
      information_matrix[(int)main_iteration_counter + 293] = J;

      /*  2) switch to the next row (next controller parameter, right-hand */
      /*  side value parameter in the current range) */
      /*  if the current row is odd, and in the next iteration (even */
      /*  row) parameters have been already considered, and this is not */
      /*  the last iteration from the bootstrap -- generate new range */
      if (isequal(method, 2.0) && (!isequal(main_iteration_counter + 1.0, 12.0)))
      {
        /*  check if the parameters have already been considered       */
        /*  the columns with computed parameters are there */
        columns_size[0] = (int)main_iteration_counter;
        columns_size[1] = 2;
        for (i0 = 0; i0 < 2; i0++) {
          loop_ub = (int)main_iteration_counter;
          for (k = 0; k < loop_ub; k++) {
            columns_data[k + (int)main_iteration_counter * i0] = 1000.0 *
              information_matrix[k + 49 * (4 + i0)];
          }
        }

        b_round(columns_data, columns_size);
        loop_ub = columns_size[0] << 1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          columns_data[i0] /= 1000.0;
        }

        /*  rounding to the 3-digits */
        for (i0 = 0; i0 < 2; i0++) {
          controller_pars[i0] = 1000.0 * information_matrix[(int)
            main_iteration_counter + 49 * (4 + i0)];
        }

        c_round(controller_pars);
        for (i0 = 0; i0 < 2; i0++) {
          controller_pars[i0] /= 1000.0;
        }

        loop_ub = (int)main_iteration_counter - 1;
        indexes_similar_params_size[0] = 1;
        indexes_similar_params_size[1] = 1 + loop_ub;
        indexes_similar_params_data[0] = -1.0;
        for (i0 = 0; i0 < loop_ub; i0++) {
          indexes_similar_params_data[i0 + 1] = 0.0;
        }

        /*  no matches found, prealoccating memory */
        for (k = 0; k < (int)main_iteration_counter; k++) {
          for (i0 = 0; i0 < 2; i0++) {
            b_P_range[i0] = columns_data[k + columns_size[0] * i0];
          }

          if (b_isequal(b_P_range, controller_pars)) {
            indexes_similar_params_data[k] = 1.0 + (double)k;
          }
        }

        tmp_size[0] = 1;
        tmp_size[1] = 1 + loop_ub;
        loop_ub++;
        for (i0 = 0; i0 < loop_ub; i0++) {
          tmp_data[i0] = (indexes_similar_params_data[i0] <= 0.0);
        }

        eml_null_assignment(indexes_similar_params_data,
                            indexes_similar_params_size, tmp_data, tmp_size);
        if (!(indexes_similar_params_size[1] == 0)) {
          /*  if any match has been found */
          if (isequal(comments, 1.0)) {
            x_fprintf();
          }

          indexes_similar_params = indexes_similar_params_data[0];

          /*  ID of the found previous combination */
        }
      }

      /*  if isequal(method,2)          */
      /*  if indexes_similar_params = -1 the method is either 2 */
      /*  or 0, and no skipping is required */
      if ((indexes_similar_params < 0.0) || (!(indexes_similar_params > 0.0))) {
        /*  if the next combination has not already been considered */
      } else {
        /*  if the next combination has already been considered */
        /*  if we are here, it means that the next iteration is not the */
        /*  last one from the bootstrap, and can be skipped */
        /*  OPTIMIZATION IS REQUIRED!!! */
        information_matrix[(int)main_iteration_counter - 1] =
          main_iteration_counter;
        information_matrix[(int)main_iteration_counter] = main_iteration_counter
          + 1.0;
        information_matrix[294 + (int)main_iteration_counter] =
          information_matrix[(int)indexes_similar_params + 293];

        /*  odd row (left-hand side in the range) */
        /*  even row (right-hand side in the range) */
        controller_pars[0] = information_matrix[(int)main_iteration_counter + 97];
        controller_pars[1] = information_matrix[(int)main_iteration_counter +
          146];

        /*  PROPOSE THE NEW REDUCED RANGE */
        /*  current iteration index 1 <= i <= N_fib */
        i = b_mod(ceil(main_iteration_counter / 2.0), 6.0);
        generate_FIB_range(i + 1.0, 6.0, controller_pars, proposed_range);

        /*  decide how to use it (how to reduce the old range) */
        if (information_matrix[(int)main_iteration_counter + 293] <=
            information_matrix[294 + (int)main_iteration_counter]) {
          /*  reduce from the right */
          /* disp('The range is reduced from the right to:') */
          new_range[0] = information_matrix[(int)main_iteration_counter + 97];
          new_range[1] = proposed_range[1];
        } else {
          /*  reduce from the left */
          /* disp('The range is reduced from the left to:') */
          new_range[0] = proposed_range[0];
          new_range[1] = information_matrix[(int)main_iteration_counter + 146];
        }

        /*  below: prepare parameters for the next iteration */
        information_matrix[(int)main_iteration_counter + 99] = new_range[0];

        /*  odd row (new range, to-be-reduced) */
        information_matrix[(int)main_iteration_counter + 148] = new_range[1];
        information_matrix[(int)main_iteration_counter + 100] = new_range[0];

        /*  even row (new range, to-be-reduced) */
        information_matrix[(int)main_iteration_counter + 149] = new_range[1];

        /*  3) calculate a pair of values for the next iteration, fill the next two rows */
        /*  current iteration index 1 <= i <= N_fib */
        /*  generate two new points for the selected paramter */
        generate_FIB_range(i + 2.0, 6.0, new_range, controller_pars);
        if (isequal(changed_parameter, 1.0)) {
          information_matrix[(int)main_iteration_counter + 197] =
            controller_pars[0];
          information_matrix[(int)main_iteration_counter + 198] =
            controller_pars[1];

          /*  columnt 6 is filled at the beginning of main */
          /*  iteration with the values of the 2nd paramter */
        } else {
          information_matrix[(int)main_iteration_counter + 246] =
            controller_pars[0];
          information_matrix[(int)main_iteration_counter + 247] =
            controller_pars[1];

          /*  columnt 5 is filled at the beginning of main */
          /*  iteration with the values of the 1st paramter */
        }
      }
    } else if (isequal(main_iteration_counter, 48.0)) {
      /*  last call of the algorithm */
      information_matrix[(int)main_iteration_counter + 293] = J;
      if (information_matrix[340] <= information_matrix[341]) {
        /*  reduce from the right */
        /* disp('The range is reduced from the right to:') */
        new_range[0] = information_matrix[(int)main_iteration_counter + 97];
        new_range[1] = information_matrix[(int)main_iteration_counter + 244];
      } else {
        /*  reduce from the left */
        /* disp('The range is reduced from the left to:') */
        new_range[0] = information_matrix[(int)main_iteration_counter + 243];
        new_range[1] = information_matrix[(int)main_iteration_counter + 146];
      }

      information_matrix[244] = information_matrix[243];
      information_matrix[293] = b_mean(new_range);
    } else {
      /*  if mod(main_iteration_counter,2) % 1 == is odd, % 0 == otherwise */
      information_matrix[(int)main_iteration_counter - 1] =
        main_iteration_counter;

      /*  1) store in information_matrix the current value of J */
      information_matrix[(int)main_iteration_counter + 293] = J;

      /*  2) decide how to reduce the current range */
      /*  odd row (left-hand side in the range) */
      /*  even row (right-hand side in the range) */
      controller_pars[0] = information_matrix[(int)main_iteration_counter + 97];
      controller_pars[1] = information_matrix[(int)main_iteration_counter + 146];

      /*  PROPOSE THE NEW REDUCED RANGE */
      /*  current iteration index 1 <= i <= N_fib */
      i = b_mod(ceil(main_iteration_counter / 2.0), 6.0);
      generate_FIB_range(i, 6.0, controller_pars, proposed_range);

      /*  decide how to use it (how to reduce the old range) */
      if (information_matrix[(int)main_iteration_counter + 292] <=
          information_matrix[(int)main_iteration_counter + 293]) {
        /*  reduce from the right */
        /* disp('The range is reduced from the right to:') */
        new_range[0] = information_matrix[(int)main_iteration_counter + 97];
        new_range[1] = proposed_range[1];
      } else {
        /*  reduce from the left */
        /* disp('The range is reduced from the left to:') */
        new_range[0] = proposed_range[0];
        new_range[1] = information_matrix[(int)main_iteration_counter + 146];
      }

      /*  below: prepare parameters for the next iteration */
      information_matrix[98 + (int)main_iteration_counter] = new_range[0];

      /*  odd row (new range, to-be-reduced) */
      information_matrix[147 + (int)main_iteration_counter] = new_range[1];
      information_matrix[(int)main_iteration_counter + 99] = new_range[0];

      /*  even row (new range, to-be-reduced) */
      information_matrix[(int)main_iteration_counter + 148] = new_range[1];

      /*  3) calculate a pair of values for the next iteration, fill the next two rows */
      /*  current iteration index 1 <= i <= N_fib */
      if (b_mod(main_iteration_counter, 12.0) > 0.0) {
        /*  generate two new points for the selected paramter */
        generate_FIB_range(i + 1.0, 6.0, new_range, controller_pars);
        if (isequal(changed_parameter, 1.0)) {
          information_matrix[196 + (int)main_iteration_counter] =
            controller_pars[0];
          information_matrix[(int)main_iteration_counter + 197] =
            controller_pars[1];

          /*  columnt 6 is filled at the beginning of main */
          /*  iteration with the values of the 2nd paramter */
        } else {
          information_matrix[245 + (int)main_iteration_counter] =
            controller_pars[0];
          information_matrix[(int)main_iteration_counter + 246] =
            controller_pars[1];

          /*  columnt 5 is filled at the beginning of main */
          /*  iteration with the values of the 1st paramter */
        }

        /*  IF THE NEXT ROW IS ODD AND ALREADY EVALUATED - SKIP IT!!! */
        if (isequal(method, 2.0)) {
          /*  the columns with computed parameters are there */
          columns_size[0] = (int)main_iteration_counter;
          columns_size[1] = 2;
          for (i0 = 0; i0 < 2; i0++) {
            loop_ub = (int)main_iteration_counter;
            for (k = 0; k < loop_ub; k++) {
              columns_data[k + (int)main_iteration_counter * i0] = 1000.0 *
                information_matrix[k + 49 * (4 + i0)];
            }
          }

          b_round(columns_data, columns_size);
          loop_ub = columns_size[0] << 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            columns_data[i0] /= 1000.0;
          }

          /*  rounding to the 3-digits */
          for (i0 = 0; i0 < 2; i0++) {
            controller_pars[i0] = 1000.0 * information_matrix[(int)
              main_iteration_counter + 49 * (4 + i0)];
          }

          c_round(controller_pars);
          for (i0 = 0; i0 < 2; i0++) {
            controller_pars[i0] /= 1000.0;
          }

          loop_ub = (int)main_iteration_counter - 1;
          indexes_similar_params_size[0] = 1;
          indexes_similar_params_size[1] = 1 + loop_ub;
          indexes_similar_params_data[0] = -1.0;
          for (i0 = 0; i0 < loop_ub; i0++) {
            indexes_similar_params_data[i0 + 1] = 0.0;
          }

          /*  no matches found, prealoccating memory */
          for (k = 0; k < (int)main_iteration_counter; k++) {
            for (i0 = 0; i0 < 2; i0++) {
              b_P_range[i0] = columns_data[k + columns_size[0] * i0];
            }

            if (b_isequal(b_P_range, controller_pars)) {
              indexes_similar_params_data[k] = 1.0 + (double)k;
            }
          }

          tmp_size[0] = 1;
          tmp_size[1] = 1 + loop_ub;
          loop_ub++;
          for (i0 = 0; i0 < loop_ub; i0++) {
            tmp_data[i0] = (indexes_similar_params_data[i0] <= 0.0);
          }

          eml_null_assignment(indexes_similar_params_data,
                              indexes_similar_params_size, tmp_data, tmp_size);
          if (!(indexes_similar_params_size[1] == 0)) {
            /*  if any match has been found */
            if (isequal(comments, 1.0)) {
              x_fprintf();
            }

            indexes_similar_params = indexes_similar_params_data[0];

            /*  ID of the found previous combination */
          }

          if (indexes_similar_params > 0.0) {
            /*  if the next combination has already been considered */
            information_matrix[(int)main_iteration_counter] =
              main_iteration_counter + 1.0;
            information_matrix[294 + (int)main_iteration_counter] =
              information_matrix[(int)indexes_similar_params + 293];
            main_iteration_counter++;
          }
        }

        /*  if isequal(method,2)             */
      } else {
        /*  stopping criterion met, prepare the optimal value of the changed_parameter for the next 2*N_fib iterations */
        indexes_similar_params = b_mean(new_range);
        if (isequal(changed_parameter, 1.0)) {
          if (isequal(comments, 1.0)) {
            y_fprintf();
          }

          for (i0 = 0; i0 < 12; i0++) {
            d_tmp_data[i0] = (int)(main_iteration_counter + (1.0 + (double)i0));
          }

          for (i0 = 0; i0 < 12; i0++) {
            information_matrix[d_tmp_data[i0] + 195] = indexes_similar_params;
          }

          changed_parameter = 2.0;
          for (i0 = 0; i0 < 2; i0++) {
            information_matrix[(int)(main_iteration_counter + (1.0 + (double)i0))
              + 97] = P_range[1];
          }

          for (i0 = 0; i0 < 2; i0++) {
            information_matrix[(int)(main_iteration_counter + (1.0 + (double)i0))
              + 146] = P_range[3];
          }

          /*  generate two new inner solutions */
          for (i0 = 0; i0 < 2; i0++) {
            b_P_range[i0] = P_range[1 + (i0 << 1)];
          }

          generate_FIB_range(1.0, 6.0, b_P_range, proposed_range);
          information_matrix[245 + (int)main_iteration_counter] =
            proposed_range[0];
          information_matrix[(int)main_iteration_counter + 246] =
            proposed_range[1];
        } else {
          if (isequal(comments, 1.0)) {
            ab_fprintf();
          }

          for (i0 = 0; i0 < 12; i0++) {
            d_tmp_data[i0] = (int)(main_iteration_counter + (1.0 + (double)i0));
          }

          for (i0 = 0; i0 < 12; i0++) {
            information_matrix[d_tmp_data[i0] + 244] = indexes_similar_params;
          }

          changed_parameter = 1.0;
          for (i0 = 0; i0 < 2; i0++) {
            information_matrix[(int)(main_iteration_counter + (1.0 + (double)i0))
              + 97] = P_range[0];
          }

          for (i0 = 0; i0 < 2; i0++) {
            information_matrix[(int)(main_iteration_counter + (1.0 + (double)i0))
              + 146] = P_range[2];
          }

          /*  generate two new inner solutions */
          for (i0 = 0; i0 < 2; i0++) {
            b_P_range[i0] = P_range[i0 << 1];
          }

          generate_FIB_range(1.0, 6.0, b_P_range, proposed_range);
          information_matrix[196 + (int)main_iteration_counter] =
            proposed_range[0];
          information_matrix[(int)main_iteration_counter + 197] =
            proposed_range[1];
        }

        for (i0 = 0; i0 < 12; i0++) {
          d_tmp_data[i0] = (int)(main_iteration_counter + (1.0 + (double)i0));
        }

        for (i0 = 0; i0 < 12; i0++) {
          information_matrix[d_tmp_data[i0] + 48] = changed_parameter;
        }
      }
    }

    /* if mod(main_iteration_counter,2) % 1 == is odd, % 0 == otherwise */
    controller_pars[0] = information_matrix[196 + (int)main_iteration_counter];
    controller_pars[1] = information_matrix[245 + (int)main_iteration_counter];

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  } else if ((iteration > N_c) && (iteration < N_max)) {
    J = 0.0;
    controller_pars[0] = information_matrix[(int)(main_iteration_counter + 1.0)
      + 195];
    controller_pars[1] = information_matrix[(int)(main_iteration_counter + 1.0)
      + 244];

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  } else if ((iteration == N_max) && (main_iteration_counter <= 48.0)) {
    controller_pars[0] = information_matrix[(int)(main_iteration_counter + 1.0)
      + 195];
    controller_pars[1] = information_matrix[(int)(main_iteration_counter + 1.0)
      + 244];
    information_matrix[(int)main_iteration_counter - 1] = main_iteration_counter;
    bb_fprintf(information_matrix[(int)main_iteration_counter - 1]);
    cb_fprintf(information_matrix[(int)main_iteration_counter + 48]);
    db_fprintf(information_matrix[(int)main_iteration_counter + 97]);
    eb_fprintf(information_matrix[(int)main_iteration_counter + 146]);
    db_fprintf(information_matrix[(int)main_iteration_counter + 195]);
    eb_fprintf(information_matrix[(int)main_iteration_counter + 244]);
    db_fprintf(information_matrix[(int)main_iteration_counter + 293]);
    iteration = 0.0;
    main_iteration_counter++;
    J = 0.0;
    if (isequal(b_mod(main_iteration_counter - 1.0, 12.0), 0.0)) {
      p_fprintf();
    }
  } else {
    if (iteration >= 10000.0) {
      /*  stopping condition is met */
      controller_pars[0] = information_matrix[244];
      controller_pars[1] = information_matrix[293];

      /*     if isequal(information_matrix(end,2),1) % first parameter changed */
      /*        controller_pars = [ mean([information_matrix(end,5) information_matrix(end-1,5)]) information_matrix(end,6)]; */
      /*    else */
      /*        controller_pars = [ information_matrix(end,5) mean([information_matrix(end,6) information_matrix(end-1,6)]) ]; */
      /*    end */
      /* information_matrix(main_iteration_counter,1) = main_iteration_counter; */
      /* main_iteration_counter = main_iteration_counter+1; */
      J = 0.0;
    }
  }

  output[0] = controller_pars[0];
  output[1] = controller_pars[1];
  output[2] = J;
  output[3] = main_iteration_counter;
}

/* End of code generation (update_parameters_FIB.c) */
