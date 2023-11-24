#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, S21_SIZE_T n) {
  S21_SIZE_T idx;
  char *targ = (char *)dest;
  char *from = (char *)src;
  for (idx = 0; idx < n; idx++, targ++, from++) {
    *targ = *from;
  }
  return (void *)dest;
}
