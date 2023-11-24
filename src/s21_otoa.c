#include "s21_string.h"

char *reverse_str(char *buf) {
  int len = s21_strlen(buf);
  int k = 0;
  char tmp;
  for (int i = len - 1; i > 0; i--) {
    if (k < i) {
      tmp = buf[k];
      buf[k] = buf[i];
      buf[i] = tmp;
      k++;
    }
  }
  return buf;
}

char *s21_otoa(unsigned long long int num, char *buf) {
  unsigned long long cel = 0;
  int k = 0;
  if (num == 0) {
    *(buf++) = '0';
    *buf = '\0';
  } else {
    while (num - cel > 0) {
      cel = (long long)num / 8 * 8;
      s21_itoa(num - cel, buf);
      buf++;
      num /= 8;
      k++;
    }
    *buf = '\0';
    buf -= k;
    reverse_str(buf);
  }
  return buf;
}