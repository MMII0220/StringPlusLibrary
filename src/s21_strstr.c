#include "s21_string.h"

int compare(const char *str1, const char *str2) {
  int ans;
  if (s21_strlen(str1) < s21_strlen(str2)) {
    ans = 0;
  } else {
    while (*str1 && *str2) {
      ans = 1;
      if (*str1 != *str2) {
        ans = 0;
        break;
      }
      str1++;
      str2++;
    }
  }
  return ans;
}

char *s21_strstr(const char *haystack, const char *needle) {
  int flag = 0;
  char *str1 = (char *)haystack;
  char *str2 = (char *)needle;
  int i = 0;
  if (S21_NULL != haystack && S21_NULL != needle) {
    int len1 = s21_strlen(haystack), len2 = s21_strlen(needle);
    if (0 == len2) {
      flag = 1;
    } else {
      for (; i < len1; i++) {
        if (*str1 == *str2 && compare(str1, str2)) {
          flag = 1;
          break;
        }
        str1++;
      }
    }
  }
  return (flag) ? str1 : S21_NULL;
}
