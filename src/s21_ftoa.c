#include "s21_string.h"

void round_num(long double right, long long add, char **buf);
void delete_zeroes(int len, int i, char **buf, Flags *flags);

char *s21_ftoa(long double num, char *buf, Flags *flags) {
  int precis, i = 0;
  if (flags->point == 0)
    precis = 6;
  else
    precis = flags->precis;
  if (num < 0) num = -num;
  long double left = 0, right = modfl(num, &left);
  long long cel = left, add;
  s21_itoa(cel, buf);
  if (precis > 0) {
    buf += s21_strlen(buf);
    *buf = '.';
    buf++;
    while (i < precis) {
      if (right > 4000000) {
        long double lft = 0;
        long double new_right = right;
        right = modfl(new_right, &lft);
      }
      right *= 10.0;
      add = fmodl(right, 10);
      s21_itoa(add, buf);
      buf++;
      i++;
    }
    add = fmodl(right * 10, 10);
    round_num(right, add, &buf);
  } else {
    buf += s21_strlen(buf) - 1;
    if (right >= 0.5) *buf = (char)*buf + 1;
    buf++;
    if (flags->hex) *buf = '.';
  }
  return buf;
}

char *s21_ftoa_for_g(long double num, char *buf, Flags *flags) {
  int precis, flag = 0;
  if (flags->point == 0)
    precis = 6;
  else
    precis = flags->precis;
  (num < 0) ? num *= -1 : num;
  long double left = 0, right = modfl(num, &left);
  long long cel = left;
  char *buf_start = buf;
  s21_itoa(cel, buf);
  int len = s21_strlen(buf);
  if (precis == 0) precis = 1;
  if (len <= precis) {
    if (precis > 0) {
      buf += s21_strlen(buf);
      int i = len;
      if (cel == 0) precis++;
      if (precis > i) {
        *buf = '.';
        buf++;
      }
      int k = 0;
      long long add = 0;
      while (i < precis && right > 1e-300) {
        if (k >= precis - len && cel != 0) break;
        if (right > 4000000) {
          long double lft = 0, new_right = right;
          right = modfl(new_right, &lft);
        }
        right *= 10.0;
        add = fmodl(right, 10);
        s21_itoa(add, buf);
        if (add != 0) flag++;
        buf++;
        k++;
        if (flag) i++;
      }
      round_num(right, add, &buf);
      int len_zero = (int)s21_strlen(buf_start);
      delete_zeroes(len_zero, i, &buf, flags);
    }
  } else
    buf_start[0] = '\0';
  return buf;
}

void delete_zeroes(int len, int i, char **buf, Flags *flags) {
  if (i != len) {
    (*buf)--;
    while (*(*buf) == '0') {
      *(*buf)-- = '\0';
    }
    if (*(*buf) == '.' && !flags->hex) {
      *(*buf) = '\0';
    }
  }
}

void round_num(long double right, long long add, char **buf) {
  right *= 10;
  add = fmodl(right, 10);
  if (add >= 5) {
    (*buf)--;
    if (*(*buf) != '9') {
      add = fmodl(right, 10);
      s21_itoa(*(*buf) - 47, (*buf));
    } else {
      while (*(*buf) == '9') {
        s21_itoa(0, (*buf));
        (*buf)--;
        if (*(*buf) == '.') (*buf)--;
      }
      if (*(*buf) != '0')
        s21_itoa(*(*buf) - 47, (*buf));
      else
        s21_itoa(1, (*buf));
    }
    (*buf) += s21_strlen((*buf));
  }
}