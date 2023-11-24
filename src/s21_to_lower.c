#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *res = S21_NULL;
  int str_len = s21_strlen(str);

  res = (char *)calloc(str_len * 2, sizeof(char));

  if (res != NULL) {
    for (int i = 0; i < str_len; ++i) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        res[i] = str[i] + 32;
      } else {
        res[i] = str[i];
      }
    }
  }

  return res;
}
