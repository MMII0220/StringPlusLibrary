#include "s21_string.h"

void spec_g(char **str, const char **format, va_list va, Flags *flags) {
  long double num;
  if (flags->length_L == 1) {
    long double tmp = va_arg(va, long double);
    num = tmp;
  } else {
    double tmp = va_arg(va, double);
    num = tmp;
  }
  char num_float[4096] = {'\0'}, num_exp[4096] = {'\0'}, num_str[4096] = {'\0'};
  if (fabsl(num) < 1e-300) {
    num_str[0] = '0';
  } else {
    s21_ftoa_for_g(num, num_float, flags);
    process_e_spec(num_exp, num, flags, **format);
    int len_exp = s21_strlen(num_exp), len_float = s21_strlen(num_float);
    if (fabsl(num) < 1 && len_float) {
      int count_zer = 0;
      for (int i = 0; i < len_float; i++)
        if (num_float[i] == '0') count_zer++;
      if ((count_zer = len_float - 2) && num_exp[len_exp - 2] == '0' &&
          num_exp[len_exp - 1] < '5') {
        num_exp[0] = '\0';
        len_exp = 0;
      }
    }
    if (len_float > 0 && len_exp == 0) {
      for (int i = 0; i < len_float; i++) num_str[i] = num_float[i];
    } else if (len_float == 0 && len_exp > 0) {
      for (int i = 0; i < len_exp; i++) num_str[i] = num_exp[i];
    } else if (len_exp < len_float) {
      for (int i = 0; i < len_exp; i++) num_str[i] = num_exp[i];
    } else {
      for (int i = 0; i < len_float; i++) num_str[i] = num_float[i];
    }
  }
  formating_floats(num_str, num, flags, str);
}
