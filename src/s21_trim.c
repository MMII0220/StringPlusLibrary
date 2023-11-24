#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *trim_chars_tmp;
  if (!trim_chars || s21_strlen(trim_chars) == 0)
    trim_chars_tmp = " \t\n";
  else
    trim_chars_tmp = (char *)trim_chars;
  int flag = 0;
  char *tmp;
  if (src) {
    int c = s21_strspn(src, trim_chars_tmp);
    if (c) src += c;
    int len = s21_strlen(src);
    tmp = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
      tmp[i] = (char)src[i];
    }
    tmp[len] = '\0';
    if (len) {
      int len2 = s21_strlen(trim_chars_tmp);
      int k;
      for (int i = len - 1; i > 0; i--) {
        k = 0;
        for (int j = 0; j < len2; j++) {
          if (tmp[i] == trim_chars_tmp[j]) k++;
        }
        if (k == 0)
          break;
        else if (k > 0)
          tmp[i] = '\0';
      }
    }
    flag = 1;
  }
  return (flag) ? tmp : S21_NULL;
}
