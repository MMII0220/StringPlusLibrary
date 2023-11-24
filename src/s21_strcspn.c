#include "s21_string.h"

S21_SIZE_T s21_strcspn(const char *str1, const char *str2) {
  S21_SIZE_T result = 0;
  int i, j, flag = 1;
  for (i = 0; str1[i] != '\0'; i++) {
    for (j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) flag = 0;
    }
    if (flag == 0) break;
    result++;
  }
  return result;
}