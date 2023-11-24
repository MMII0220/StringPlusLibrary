#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  int len1 = s21_strlen(str1), len2 = s21_strlen(str2), flag = 0;
  char *str;
  if (0 != len1 && 0 != len2) {
    flag = 1;
    int i;
    for (i = 0; i < len1; i++) {
      int j;
      for (j = 0; j < len2; j++) {
        if (str1[i] == str2[j]) break;
      }
      if (j < len2) break;
    }
    str = (char *)str1 + i;
  }
  return (flag) ? str : S21_NULL;
}
