#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, S21_SIZE_T n) {
  int ans = 0;
  S21_SIZE_T idx;
  const unsigned char *lh = str1;
  const unsigned char *rh = str2;
  for (idx = 0; idx < n; idx++, lh++, rh++) {
    if (*lh < *rh) {
      ans = *lh - *rh;
      break;
    } else if (*lh > *rh) {
      ans = *lh - *rh;
      break;
    }
  }
  return ans;
}