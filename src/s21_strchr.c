#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = (char *)str;
  int len = s21_strlen(str);
  if (len > 0) {
    if (len != 0) {
      for (int i = 0; i < len + 1; i++) {
        if (i == len && str[i] != c) {
          result = S21_NULL;
          break;
        }
        if (str[i] == c) {
          result += i;
          break;
        }
      }
    }
  }
  return result;
}