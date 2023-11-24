#include "s21_string.h"

void reversed(char *str) {
  char tmp;
  int i, j;
  for (i = 0, j = s21_strlen(str) - 1; i < j; i++, j--) {
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }
}

void s21_my_itoa(int num, char *buf) {
  int idx = 0, flag = 0;
  char d;
  if (0 == num) {
    buf[idx] = 48;
  } else {
    if (0 > num) {
      flag = 1;
      num = -num;
    }
    while (0 < num) {
      d = num % 10;
      buf[idx++] = d + 48;
      num /= 10;
    }
    if (flag) {
      buf[idx++] = '-';
    }
    buf[idx] = '\0';
  }
  reversed(buf);
}
