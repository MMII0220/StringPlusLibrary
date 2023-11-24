#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *res = S21_NULL;
  S21_SIZE_T str_len = s21_strlen(str);

  res = (char *)calloc(str_len * 2, sizeof(char));

  if (res != NULL) {
    for (S21_SIZE_T i = 0; i < str_len; ++i) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        res[i] = str[i] - 32;
      } else {
        res[i] = str[i];
      }
    }
  }
  return res;
}
