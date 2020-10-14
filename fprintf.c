/*
 * fprintf.c
 *
 * Code generation for function 'fprintf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FIB_number.h"
#include "generate_FIB_range.h"
#include "update_parameters_FIB.h"
#include "fprintf.h"
#include "fileManager.h"
#include <stdio.h>

/* Function Definitions */
void ab_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[57] = { '\x0a', '>', '>', ' ', 'O', 'P', 'T', 'I', 'M',
    'I', 'Z', 'A', 'T', 'I', 'O', 'N', ' ', 'P', 'R', 'O', 'C', 'E', 'D', 'U',
    'R', 'E', ' ', '-', ' ', 'c', 'h', 'a', 'n', 'g', 'i', 'n', 'g', ' ', 't',
    'o', ' ', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', ' ', 'n', 'o', '.',
    ' ', '1', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void b_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[63] = { '\x0a', '*', '*', '*', '*', '*', '*', '*', '*',
    '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
    '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
    '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
    '*', '*', '*', '*', '*', '*', '*', '*', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void bb_fprintf(double varargin_1)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[7] = { '\x0a', '%', '5', '.', '0', 'f', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt, varargin_1);
    fflush(filestar);
  }
}

void c_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[63] = { '\x0a', ' ', '(', 'c', ')', ' ', 'M', 'o', 'd',
    'e', 'l', '-', 'f', 'r', 'e', 'e', ' ', 'a', 'u', 't', 'o', 't', 'u', 'n',
    'e', 'r', ' ', '(', '2', ' ', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r',
    's', ')', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void cb_fprintf(double varargin_1)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[8] = { ' ', ' ', '%', '5', '.', '0', 'f', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt, varargin_1);
    fflush(filestar);
  }
}

void d_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[63] = { '\x0a', ' ', ' ', ' ', ' ', ' ', 'b', 'a', 's',
    'e', 'd', ' ', 'o', 'n', ' ', 'z', 'e', 'r', 'o', '-', 'o', 'r', 'd', 'e',
    'r', ' ', 'F', 'i', 'b', 'o', 'n', 'a', 'c', 'c', 'i', ' ', 's', 'e', 'a',
    'r', 'c', 'h', ' ', 'm', 'e', 't', 'h', 'o', 'd', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void db_fprintf(double varargin_1)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[11] = { ' ', '|', ' ', ' ', '%', '1', '0', '.', '4',
    'f', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt, varargin_1);
    fflush(filestar);
  }
}

void e_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[63] = { '\x0a', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', 'D', 'a', 'r', 'i', 'u', 's', 'z', ' ', 'H', 'o',
    'r', 'l', 'a', ',', ' ', 'W', 'o', 'j', 'c', 'i', 'e', 'c', 'h', ' ', 'G',
    'i', 'e', 'r', 'n', 'a', 'c', 'k', 'i', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void eb_fprintf(double varargin_1)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[9] = { ' ', ' ', '%', '1', '0', '.', '4', 'f', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt, varargin_1);
    fflush(filestar);
  }
}

void f_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[63] = { '\x0a', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', 'P', 'o', 'z', 'n', 'a', 'n', ' ', 'U', 'n', 'i',
    'v', 'e', 'r', 's', 'i', 't', 'y', ' ', 'o', 'f', ' ', 'T', 'e', 'c', 'h',
    'n', 'o', 'l', 'o', 'g', 'y', ' ', ' ', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void g_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[63] = { '\x0a', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', 'd', 'a', 'r', 'i', 'u', 's', 'z', '.', 'h', 'o',
    'r', 'l', 'a', '@', 'p', 'u', 't', '.', 'p', 'o', 'z', 'n', 'a', 'n', '.',
    'p', 'l', ' ', ' ', ' ', ' ', ' ', ' ', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void h_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[44] = { '\x0a', ' ', 'a', 'c', 'c', 'u', 'r', 'a', 'c',
    'y', ' ', 'o', 'f', ' ', 'c', 'a', 'l', 'c', 'u', 'l', 'a', 't', 'i', 'o',
    'n', 's', ' ', '(', 'e', 'p', 's', 'i', 'l', 'o', 'n', ')', ' ', '=', ' ',
    '0', '.', '0', '5', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void i_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[41] = { '\x0a', ' ', 'n', 'o', '.', ' ', 'o', 'f', ' ',
    'b', 'o', 'o', 't', 's', 't', 'r', 'a', 'p', ' ', 'c', 'y', 'c', 'l', 'e',
    's', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '=', ' ',
    '2', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void j_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[63] = { '\x0a', ' ', 't', 'o', 't', 'a', 'l', ' ', 'n',
    'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'm', 'a', 'i', 'n', ' ', 'i',
    't', 'e', 'r', 'a', 't', 'i', 'o', 'n', 's', ' ', ' ', ' ', ' ', '=', ' ',
    '4', '8', ' ', '(', 'f', 'o', 'r', ' ', 'm', 'e', 't', 'h', 'o', 'd', '=',
    '=', '0', ' ', 'o', 'r', ' ', '1', ')', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void k_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[63] = { '\x0a', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '<', ' ',
    '4', '8', ' ', '(', 'f', 'o', 'r', ' ', 'm', 'e', 't', 'h', 'o', 'd', '=',
    '=', '2', ')', ' ', ' ', ' ', ' ', ' ', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void l_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[70] = { '\x0a', ' ', '*', '*', '*', ' ', 'W', 'A', 'R',
    'N', 'I', 'N', 'G', ':', ' ', 's', 'o', 'm', 'e', ' ', 'p', 'e', 'r', 'f',
    'o', 'r', 'm', 'a', 'n', 'c', 'e', ' ', 'i', 'n', 'd', 'e', 'x', 'e', 's',
    ' ', 'm', 'i', 'g', 'h', 't', ' ', 'b', 'e', ' ', 'a', 'v', 'e', 'r', 'a',
    'g', 'e', 'd', ' ', '(', 'm', 'e', 't', 'h', 'o', 'd', '=', '=', '1', ')',
    '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void m_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[72] = { '\x0a', ' ', '*', '*', '*', ' ', 'W', 'A', 'R',
    'N', 'I', 'N', 'G', ':', ' ', 's', 'o', 'm', 'e', ' ', 'p', 'a', 'r', 'a',
    'm', 'e', 't', 'e', 'r', ' ', 'c', 'o', 'm', 'b', 'i', 'n', 'a', 't', 'i',
    'o', 'n', 's', ' ', 'm', 'i', 'g', 'h', 't', ' ', 'b', 'e', ' ', 'o', 'm',
    'i', 't', 't', 'e', 'd', ' ', '(', 'm', 'e', 't', 'h', 'o', 'd', '=', '=',
    '2', ')', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void n_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[3] = { '\x0a', '\x0a', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void o_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[79] = { 'I', 't', 'e', 'r', '.', ' ', ' ', ' ', 'P',
    'a', 'r', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', 'P', 'a', 'r', '(',
    '-', ')', ' ', ' ', ' ', ' ', ' ', ' ', 'P', 'a', 'r', '(', '+', ')', ' ',
    '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'P', 'a', 'r', '1', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', 'P', 'a', 'r', '2', ' ', '|', ' ', ' ', ' ',
    ' ', ' ', ' ', 'J', ' ', ' ', ' ', ' ', ' ', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void p_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[81] = { '\x0a', '-', '-', '-', '-', '-', '-', '-', '-',
    '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
    '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
    '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
    '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',
    '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void q_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[88] = { '\x0a', '>', '>', ' ', 'T', 'h', 'e', ' ', 'a',
    'l', 'g', 'o', 'r', 'i', 't', 'h', 'm', ' ', 'r', 'e', 'a', 'c', 'h', 'e',
    'd', ' ', 'i', 't', 's', ' ', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', ' ',
    'n', 'u', 'm', 'b', 'e', 'r', ' ', 'o', 'f', ' ', 'i', 't', 'e', 'r', 'a',
    't', 'i', 'o', 'n', 's', ' ', '(', '2', ' ', 'b', 'o', 'o', 't', 's', 't',
    'r', 'a', 'p', 's', ')', ',', ' ', 't', 'e', 'r', 'm', 'i', 'n', 'a', 't',
    'i', 'n', 'g', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void r_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[34] = { '\x0a', '>', '>', ' ', 'O', 'P', 'T', 'I', 'M',
    'A', 'L', ' ', 'S', 'O', 'L', 'U', 'T', 'I', 'O', 'N', ' ', '(', 'P', 'a',
    'r', '1', ',', 'P', 'a', 'r', '2', ')', ':', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void s_fprintf(double varargin_1)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[8] = { '\x0a', '%', '1', '4', '.', '4', 'f', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt, varargin_1);
    fflush(filestar);
  }
}

void t_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[49] = { '\x0a', '>', '>', ' ', 'G', 'a', 't', 'h', 'e',
    'r', 'i', 'n', 'g', ' ', 'p', 'e', 'r', 'f', 'o', 'r', 'm', 'a', 'n', 'c',
    'e', ' ', 'i', 'n', 'd', 'e', 'x', ' ', '(', 'i', 't', 'e', 'r', 'a', 't',
    'i', 'o', 'n', ' ', '<', ' ', 'N', 'c', ')', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void u_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[54] = { '\x0a', '>', '>', ' ', 'O', 'P', 'T', 'I', 'M',
    'I', 'Z', 'A', 'T', 'I', 'O', 'N', ' ', 'P', 'R', 'O', 'C', 'E', 'D', 'U',
    'R', 'E', ' ', 'l', 'a', 'u', 'n', 'c', 'h', 'e', 'd', ' ', '(', 'i', 't',
    'e', 'r', 'a', 't', 'i', 'o', 'n', ' ', '=', '=', ' ', 'N', 'c', ')', '\x00'
  };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void v_fprintf(double varargin_1)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[51] = { '\x0a', ' ', ' ', ' ', '>', '>', ' ', 'C', 'u',
    'r', 'r', 'e', 'n', 't', ' ', 'v', 'a', 'l', 'u', 'e', ' ', 'o', 'f', ' ',
    'p', 'e', 'r', 'f', 'o', 'r', 'm', 'a', 'n', 'c', 'e', ' ', 'i', 'n', 'd',
    'e', 'x', ' ', 'J', ' ', '=', ' ', '%', '.', '6', 'f', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt, varargin_1);
    fflush(filestar);
  }
}

void w_fprintf(double varargin_1)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[48] = { '\x0a', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', 'a', 'v', 'e', 'r', 'a', 'g', 'e', 'd', ' ', 't', 'o',
    ' ', 't', 'h', 'e', ' ', 'v', 'a', 'l', 'u', 'e', ' ', 'o', 'f', ' ', ' ',
    'J', ' ', '=', ' ', '%', '.', '6', 'f', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt, varargin_1);
    fflush(filestar);
  }
}

void x_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[72] = { '\x0a', ' ', ' ', ' ', '>', '>', ' ', 'N', 'e',
    'x', 't', ' ', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', ' ', 'c', 'o',
    'm', 'b', 'i', 'n', 'a', 't', 'i', 'o', 'n', ' ', 'h', 'a', 's', ' ', 'b',
    'e', 'e', 'n', ' ', 'c', 'o', 'n', 's', 'i', 'd', 'e', 'r', 'e', 'd', ' ',
    'b', 'e', 'f', 'o', 'r', 'e', ' ', '(', 's', 'k', 'i', 'p', 'p', 'i', 'n',
    'g', ')', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

void y_fprintf(void)
{
  FILE * b_NULL;
  boolean_T autoflush;
  FILE * filestar;
  static const char cfmt[57] = { '\x0a', '>', '>', ' ', 'O', 'P', 'T', 'I', 'M',
    'I', 'Z', 'A', 'T', 'I', 'O', 'N', ' ', 'P', 'R', 'O', 'C', 'E', 'D', 'U',
    'R', 'E', ' ', '-', ' ', 'c', 'h', 'a', 'n', 'g', 'i', 'n', 'g', ' ', 't',
    'o', ' ', 'p', 'a', 'r', 'a', 'm', 'e', 't', 'e', 'r', ' ', 'n', 'o', '.',
    ' ', '2', '\x00' };

  b_NULL = NULL;
  fileManager(&filestar, &autoflush);
  if (filestar == b_NULL) {
  } else {
    fprintf(filestar, cfmt);
    fflush(filestar);
  }
}

/* End of code generation (fprintf.c) */
