#include "s21_string.h"

char *s21_utoa(unsigned long long num, char *buf) {
  unsigned long long tmp = num;
  long long count = 0;
  while (tmp >= 10) {
    tmp /= 10;
    count++;
  }
  long long k, h;
  while (count > 0) {
    k = 0;
    h = 1;
    while (k < count) {
      h *= 10;
      k++;
    }
    *buf++ = num / h + 48;
    num %= h;
    count--;
  }
  *buf++ = num + 48;
  return buf;
}