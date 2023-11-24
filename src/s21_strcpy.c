#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  size_t i;
  if (src != NULL && (s21_strlen(dest) >= s21_strlen(src))) {
    for (i = 0; src[i] != '\0'; i++) {
      dest[i] = src[i];
    }
    for (; dest[i] != '\0'; i++) dest[i] = '\0';
  }
  return dest;
}