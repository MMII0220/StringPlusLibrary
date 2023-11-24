#include "s21_string.h"

void *s21_memset(void *str, int c, S21_SIZE_T n) {
  S21_SIZE_T idx;
  unsigned char *dest = str;
  for (idx = 0; idx < n; idx++, dest++) {
    *dest = (unsigned char)c;
  }
  return (void *)str;
}
