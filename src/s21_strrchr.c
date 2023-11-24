#include "s21_string.h"

char *s21_strrchr(const char *str, int num) {
  char *res = S21_NULL;

  for (int i = s21_strlen(str); i >= 0; --i) {
    if (str[i] == num) {
      res = (char *)str + i;
      break;
    }
  }

  return res;
}
