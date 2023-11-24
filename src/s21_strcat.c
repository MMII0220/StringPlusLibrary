#include "s21_string.h"

char *s21_strcat(char *dest, const char *str) {
  int flag = 0;
  if (dest && str) {
    flag = 1;
    S21_SIZE_T idx = s21_strlen(dest);
    for (; *str != '\0'; idx++) {
      dest[idx] = *str;
      str++;
    }
    dest[idx] = '\0';
  }
  return (flag) ? dest : S21_NULL;
}
