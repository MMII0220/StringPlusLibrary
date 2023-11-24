#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, S21_SIZE_T n) {
  int ans = 0;
  S21_SIZE_T idx, len = s21_strlen(str1);
  const unsigned char *lh = (unsigned char *)str1;
  const unsigned char *rh = (unsigned char *)str2;
  if (len > 0 && n > 0) {
    for (idx = 0; idx <= n; idx++, lh++, rh++) {
      if (*lh < *rh) {
        ans = *lh - *rh;
        break;
      } else if (*lh > *rh) {
        ans = *lh - *rh;
        break;
      }
    }
  } else if (n > 0) {
    ans = *lh - *rh;
  }
  return ans;
}
