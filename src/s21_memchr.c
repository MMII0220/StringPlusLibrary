#include "s21_string.h"

void *s21_memchr(const void *str, int c, S21_SIZE_T n) {
  S21_SIZE_T idx;
  const char *pt = str;
  if (0 == n) {
    pt = S21_NULL;
  } else {
    for (idx = 0; idx < n; idx++, pt++) {
      if (c == *pt) {
        break;
      }
    }
  }
  return (void *)pt;
}
