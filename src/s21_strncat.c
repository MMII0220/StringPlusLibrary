#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, int num) {
  size_t dest_len = s21_strlen(dest);
  int i = 0;

  for (; i < num; ++i) {
    dest[dest_len + i] = src[i];
  }

  dest[dest_len + i] = '\0';

  return dest;
}
