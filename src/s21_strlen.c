#include "s21_string.h"

S21_SIZE_T s21_strlen(const char *str) {
  const char *p;
  for (p = str; *p; p++) {
  }
  return p - str;
}