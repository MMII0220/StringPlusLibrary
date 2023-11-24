#include "s21_string.h"

char *s21_xtoa(unsigned long long int num, char *buf, char c) {
  unsigned long long cel = 0;
  unsigned long long add;
  int k = 0;
  char *letters_1 = "abcdef";
  char *letters_2 = "ABCDEF";
  char *let;
  if (c == 'x')
    let = letters_1;
  else
    let = letters_2;
  if (num == 0) {
    *(buf)++ = '0';
    *buf = '\0';
  } else {
    while (num - cel > 0) {
      cel = (long long)num / 16 * 16;
      add = num - cel;
      if (add > 9)
        *buf = let[add % 10];
      else
        s21_itoa(add, buf);
      buf++;
      num /= 16;
      k++;
    }
    buf -= k;
    reverse_str(buf);
  }
  return buf;
}