#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, S21_SIZE_T n) {
  S21_SIZE_T i;
  if (src != NULL && (s21_strlen(dest) >= s21_strlen(src))) {
    for (i = 0; src[i] != '\0' && i < n; i++) {
      dest[i] = src[i];
    }
    for (; dest[i] != '\0'; i++) dest[i] = '\0';
  }
  return dest;
}