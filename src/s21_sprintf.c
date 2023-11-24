#include "s21_string.h"

void add_num_va(Flags *flags, va_list va, unsigned long long *num);
void format_e_spec(char *buf, char c, int flag, int i);

int s21_sprintf(char *str, const char *format, ...) {
  va_list va;
  va_start(va, format);
  char *str_start = str;
  int error = 0;
  for (; *format != '\0'; format++, *str = 0) {
    if (*format != '%') {
      *str = *format;
      str++;
    } else {
      Flags flags = {0};
      error = proc_flags(&format, &flags, va);
      if (error) break;
      proc_spec(&str, &format, va, &flags, str_start);
    }
  }
  str = str_start;
  int len;
  if (!error)
    len = s21_strlen(str_start);
  else
    len = -1;
  // возврат функции
  va_end(va);
  return len;
}

int proc_flags(const char **format, Flags *flags, va_list va) {
  (*format)++;
  char buf[4096] = {'\0'};
  int i = 0;
  while (**format != 'c' && **format != 'i' && **format != 'd' &&
         **format != 's' && **format != 'f' && **format != 'u' &&
         **format != 'e' && **format != 'E' && **format != 'o' &&
         **format != 'x' && **format != 'X' && **format != 'p' &&
         **format != 'n' && **format != 'g' && **format != 'G' &&
         **format != '%') {
    buf[i++] = *(*format)++;
  }
  buf[i] = **format;
  int error = checker(buf, flags, va);
  if (buf[0] == '\0') error = 1;
  return error;
}

// все функции обработки спецификаторов
void proc_spec(char **str, const char **format, va_list va, Flags *flags,
               char *str_start) {
  if (**format == 's')
    spec_s(str, va, flags);
  else if (**format == 'd' || **format == 'i')
    spec_d(str, va, flags);
  else if (**format == 'c')
    spec_c(str, va, flags);
  else if (**format == 'f')
    spec_f(str, va, flags);
  else if (**format == 'u')
    spec_u(str, va, flags);
  else if (**format == 'e' || **format == 'E')
    spec_e(str, format, va, flags);
  else if (**format == 'o')
    spec_o(str, va, flags);
  else if (**format == 'x' || **format == 'X')
    spec_x(str, format, va, flags);
  else if (**format == 'p')
    spec_p(str, va, flags);
  else if (**format == 'g' || **format == 'G')
    spec_g(str, format, va, flags);
  else if (**format == 'n')
    spec_n(va, str_start);
  else if ('%' == **format)
    spec_proc(str);
}
int checker(char *buf, Flags *flags, va_list va) {
  int error = 0;
  int len = s21_strlen(buf);
  if (len > 1) error = check_errors(buf, flags, va);
  return error;
}

int check_errors(char *format, Flags *flags, va_list va) {
  int error = 0;
  int len = s21_strlen(format);
  char type = format[len - 1];
  if (type == 'i') type = 'd';
  for (; *format != '\0'; format++) {
    check_space(format, flags, &error);
    check_minus(format, flags, &error);
    check_plus(format, flags, &error);
    check_zero(format, flags, &error);
    check_star(format, flags, &error, va);
    check_width(&format, flags, &error);
    check_point(format, flags, &error);
    check_precision(&format, flags, &error);
    check_length(&format, flags, &error, type);
    check_extra(format, &error, type);
    check_hex(format, flags, &error);
  }
  return error;
}

void check_extra(char *format, int *err, char type) {
  char *compare = ". +-#*0123456789lhL\0";
  char symb = *format++;
  char next = *format;
  if (symb == 'i') symb = type;
  if (symb != type || next != '\0') {
    int flag = 0;
    for (; *compare != '\0'; compare++) {
      if (symb == *compare) {
        flag = 1;
        break;
      }
    }
    if (!flag) *err = 1;
  }
  format--;
}

void check_hex(char *format, Flags *flags, int *err) {
  if (*format == '#') {
    if (flags->width || flags->point || flags->precis || flags->length_h ||
        flags->length_L || flags->length_l)
      *err = 1;
    else
      flags->hex = 1;
  }
}
void check_space(char *format, Flags *flags, int *err) {
  if (*format == ' ') {
    if (flags->width || flags->point || flags->precis || flags->length_h ||
        flags->length_L || flags->length_l)
      *err = 1;
    else
      flags->space = 1;
  }
}
// инициализация минуса
void check_minus(char *format, Flags *flags, int *err) {
  if (*format == '-') {
    if (flags->width || flags->point || flags->precis || flags->minus ||
        flags->length_h || flags->length_L || flags->length_l)
      *err = 1;
    else
      flags->minus = 1;
  }
}

// инициализаия плюса
void check_plus(char *format, Flags *flags, int *err) {
  if (*format == '+') {
    if (flags->width || flags->point || flags->precis || flags->plus ||
        flags->length_h || flags->length_L || flags->length_l)
      *err = 1;
    else
      flags->plus = 1;
  }
}

void check_zero(char *format, Flags *flags, int *err) {
  if (*format == '0' && !flags->point) {
    if (flags->length_h || flags->length_L || flags->length_l) {
      *err = 1;
    } else
      flags->zero++;
  }
}

void check_star(char *format, Flags *flags, int *err, va_list va) {
  if (*format == '*') {
    if (flags->length_h || flags->length_L || flags->length_l ||
        (!flags->point && flags->width) || (flags->point && flags->precis))
      *err = 1;
    else if (!flags->point)
      flags->width = va_arg(va, int);
    else if (flags->point)
      flags->precis = va_arg(va, int);
  }
}

// проверка ширины
void check_width(char **format, Flags *flags, int *err) {
  if (**format >= '1' && **format <= '9' && !flags->point) {
    if (flags->length_h || flags->length_L || flags->length_l || flags->width) {
      *err = 1;
    } else {
      char buf[4096] = {0};
      int i = 0;
      while (**format >= '0' && **format <= '9') {
        buf[i++] = *(*format)++;
      }
      flags->width = s21_atoi(buf);
      (*format)--;
    }
  }
}

// флаг точность
void check_point(char *format, Flags *flags, int *err) {
  if (*format == '.') {
    if (flags->point)
      *err = 1;
    else {
      flags->point++;
      format++;
      for (; *format == '0'; format++) {
      }
      format--;
    }
  }
}

void num(char **format, Flags *flags) {
  int flag = 0;
  if (**format >= '1' && **format <= '9') {
    flag = 1;
    char buf[4096];
    int i = 0;
    for (; **format >= '0' && **format <= '9'; i++, (*format)++) {
      buf[i] = **format;
    }
    buf[i] = '\0';
    flags->precis = s21_atoi(buf);
  }
  (*format)--;
  if (flag == 0) flags->precis = 0;
}

void check_precision(char **format, Flags *flags, int *err) {
  if (**format >= '1' && **format <= '9' && flags->point) {
    if (flags->length_h || flags->length_L || flags->length_l || flags->precis)
      *err = 1;
    else
      num(format, flags);
  }
}

// проверка флагов длины
void check_length(char **format, Flags *flags, int *err, char type) {
  if (**format == 'l' || **format == 'L' || **format == 'h') {
    type = type;
    *err = *err;
    if (**format == 'l') {
      for (; **format == 'l'; (*format)++, flags->length_l++) {
      }
    } else if (**format == 'L') {
      flags->length_L++;
      (*format)++;
    } else if (**format == 'h') {
      flags->length_h++;
      (*format)++;
    }
    (*format)--;
  }
}

// сдвиг для ширины (если флаг 0 или точность в интах заполняется нулями элсе
// пробелами)
void shift(char **str, int len, Flags *flags, char c) {
  for (; len < flags->width; len++, (*str)++) {
    **str = c;
  }
}

void spec_c(char **str, va_list va, Flags *flags) {
  // флаг !минус прижатие к правой стороне
  if (flags->width && !flags->minus) shift(str, 1, flags, ' ');
  *(*str)++ = va_arg(va, int);
  // флаг минус прижатие к левой стороне
  if (flags->width && flags->minus) shift(str, 1, flags, ' ');
}

// похоже на обработку чара
void spec_s(char **str, va_list va, Flags *flags) {
  char *pr_s = va_arg(va, char *);
  int len = s21_strlen(pr_s);
  if (flags->precis < len && flags->point) len = flags->precis;
  int i = 0;
  if (flags->width && !flags->minus) shift(str, len, flags, ' ');
  for (; *pr_s != '\0'; (*str)++, pr_s++, i++) {
    if (i == flags->precis && flags->point) break;
    **str = *pr_s;
  }
  if (flags->width && flags->minus) shift(str, len, flags, ' ');
}

// добавляем нули если флаг 0
void add_zeros(char **str, int len, Flags *flags) {
  int diff = flags->precis - len;
  for (int i = 0; i < diff; i++, (*str)++) **str = '0';
}

void spec_d(char **str, va_list va, Flags *flags) {
  long long num;
  if (flags->length_l == 1)
    num = va_arg(va, long);
  else if (flags->length_l == 2)
    num = va_arg(va, long long);
  else if (flags->length_h == 1)
    num = (short)va_arg(va, int);
  else
    num = va_arg(va, int);
  char num_str[4096] = {'\0'};
  s21_itoa(num, num_str);

  int num_len = s21_strlen(num_str), len = 0, i = 0, flag = 1;
  if (flags->space && !flags->plus && num >= 0) {
    *(*str)++ = ' ';
    len++;
  }
  if (s21_strcmp(num_str, "0") == 0 && flags->point && flags->precis == 0) {
    flag = 0;
    len--;
  }
  if (flags->zero && (flags->precis || flags->point)) flags->zero = 0;
  if (num_len < flags->precis)
    len += flags->precis;
  else
    len += num_len;
  if (flags->plus && num > 0) len++;
  if (num < 0) len++;

  if (flags->width && !flags->minus && !flags->zero)
    shift(str, len, flags, ' ');
  if (flags->plus && num >= 0) *(*str)++ = '+';
  if (num < 0) *(*str)++ = '-';

  if (!flags->zero) {
    if (num_len < flags->precis) add_zeros(str, num_len, flags);
  } else
    shift(str, len, flags, '0');
  if (flag) {
    while (num_str[i] != '\0') *(*str)++ = num_str[i++];
  }
  if (flags->width && flags->minus && !flags->zero) shift(str, len, flags, ' ');
}

// похоже на инт, но флага + быть не может
void spec_u(char **str, va_list va, Flags *flags) {
  unsigned long long num;
  if (flags->length_l == 1)
    num = (unsigned long)va_arg(va, unsigned long);
  else if (flags->length_l == 2)
    num = va_arg(va, unsigned long long);
  else if (flags->length_h == 1)
    num = (unsigned short)va_arg(va, int);
  else
    num = va_arg(va, int);

  // unsigned int num = va_arg(va, unsigned);
  char num_str[4096] = {'\0'};
  s21_utoa(num, num_str);
  if (flags->zero && (flags->precis || flags->point)) flags->zero = 0;
  int num_len = s21_strlen(num_str);
  int i = 0, len = 0, flag = 1;

  if (s21_strcmp(num_str, "0") == 0 && flags->point && flags->precis == 0) {
    flag = 0;
    len--;
  }
  if (num_len < flags->precis)
    len += flags->precis;
  else
    len += num_len;

  if (flags->width && !flags->minus && !flags->zero)
    shift(str, len, flags, ' ');
  if (!flags->zero) {
    if (num_len < flags->precis) add_zeros(str, num_len, flags);
  } else {
    shift(str, len, flags, '0');
  }
  if (flag) {
    while (num_str[i] != '\0') *(*str)++ = num_str[i++];
  }
  if (flags->width && flags->minus && !flags->zero) shift(str, len, flags, ' ');
}

// в целом похоже на инт и ансайнд, но другие условия по точности и нулям
void spec_f(char **str, va_list va, Flags *flags) {
  long double num;
  if (flags->length_L == 1) {
    num = va_arg(va, long double);
  } else if (flags->length_l) {
    num = (double)va_arg(va, double);
  } else {
    num = va_arg(va, double);
  }
  char num_str[4096] = {'\0'};
  s21_ftoa(num, num_str, flags);
  formating_floats(num_str, num, flags, str);
}

void spec_p(char **str, va_list va, Flags *flags) {
  unsigned long long num;
  num = va_arg(va, unsigned long long);
  char num_str[4096] = {'\0'};
  int flag = 0;
  if (num)
    s21_xtoa(num, num_str, 'x');
  else {
#if defined(__linux__)
    s21_strcat(num_str, "(nil)");
#elif defined(__APPLE__)
    s21_strcat(num_str, "0");
    flag = 1;
#endif
  }
  int num_len = s21_strlen(num_str), i = 0, len = 0;
  num_len += 2;
  if (num_len < flags->precis)
    len += flags->precis;
  else
    len += num_len;
  if (flags->plus && num > 0) {
    **str = '+';
    (*str)++;
    len++;
  }
  if (flags->width && !flags->minus && !flags->zero)
    shift(str, len, flags, ' ');
  if (!(!flag && num == 0)) {
    **str = '0';
    (*str)++;
    **str = 'x';
    (*str)++;
  }
  if (flags->precis && flag) {
    if (num_len < flags->precis) add_zeros(str, num_len - 2, flags);
  }
  if (!(flags->point && flags->precis == 0 && num == 0 && flag)) {
    while (num_str[i] != '\0') *(*str)++ = num_str[i++];
  }
  if (flags->width && flags->minus) shift(str, len, flags, ' ');
}

void add_num_va(Flags *flags, va_list va, unsigned long long *num) {
  if (flags->length_l == 1) {
    *num = (unsigned long)va_arg(va, unsigned long);
  } else if (flags->length_l == 2) {
    *num = va_arg(va, unsigned long long);
  } else if (flags->length_h == 1) {
    *num = (unsigned short)va_arg(va, int);
  } else {
    *num = (unsigned)va_arg(va, int);
  }
}

void spec_o(char **str, va_list va, Flags *flags) {
  unsigned long long num = 0;
  add_num_va(flags, va, &num);
  char num_str[4096] = {'\0'};
  s21_otoa(num, num_str);
  if (flags->zero && (flags->precis || flags->point)) flags->zero = 0;
  int num_len = s21_strlen(num_str), i = 0, len = 0, flag = 1;
  if (s21_strcmp(num_str, "0") == 0 && flags->point && flags->precis == 0) {
    flag = 0;
    len--;
  }
  if (flags->hex && s21_strcmp(num_str, "0") != 0) len++;
  if (num_len < flags->precis)
    len += flags->precis;
  else
    len += num_len;
  if (flags->plus && num > 0) len++;
  if (flags->width && !flags->minus && !flags->zero)
    shift(str, len, flags, ' ');
  if (!flags->zero) {
    if (num_len < flags->precis) add_zeros(str, num_len, flags);
  }
  if (flags->hex && s21_strcmp(num_str, "0") != 0) {
    **str = '0';
    (*str)++;
  }
  if (flags->zero) {
    shift(str, len, flags, '0');
  }
  if (flag) {
    while (num_str[i] != '\0') *(*str)++ = num_str[i++];
  }
  if (flags->width && flags->minus && !flags->zero) shift(str, len, flags, ' ');
}

void spec_x(char **str, const char **format, va_list va, Flags *flags) {
  unsigned long long num;
  add_num_va(flags, va, &num);
  if (flags->zero && (flags->precis || flags->point)) flags->zero = 0;
  char num_str[4096] = {'\0'};
  s21_xtoa(num, num_str, **format);
  int num_len = s21_strlen(num_str), i = 0, flag = 1, len = 0;
  if (s21_strcmp(num_str, "0") == 0 && flags->point && flags->precis == 0) {
    flag = 0;
    len--;
  }
  if (flags->hex && s21_strcmp(num_str, "0") != 0) len += 2;
  if (num_len < flags->precis)
    len += flags->precis;
  else
    len += num_len;
  if (flags->plus && num > 0) len++;
  if (flags->width && !flags->minus && !flags->zero)
    shift(str, len, flags, ' ');
  if (flags->hex && s21_strcmp(num_str, "0") != 0) {
    **str = '0';
    (*str)++;
    if (**format == 'x') {
      **str = 'x';
    } else
      **str = 'X';
    (*str)++;
  }
  if (!flags->zero) {
    if (num_len < flags->precis) add_zeros(str, num_len, flags);
  } else
    shift(str, len, flags, '0');
  if (flag) {
    while (num_str[i] != '\0') *(*str)++ = num_str[i++];
  }
  if (flags->width && flags->minus && !flags->zero) shift(str, len, flags, ' ');
}

void spec_n(va_list va, char *str_start) {
  int *pArg = va_arg(va, int *);
  *pArg = (int)s21_strlen(str_start);
}

void spec_e(char **str, const char **format, va_list va, Flags *flags) {
  long double num;
  if (flags->length_L == 1) {
    long double tmp = va_arg(va, long double);
    num = tmp;
  } else {
    long double tmp = va_arg(va, double);
    num = tmp;
  }
  char num_str[4096] = {'\0'};
  process_e_spec(num_str, num, flags, **format);
  formating_floats(num_str, num, flags, str);
}
void formating_floats(char *num_str, long double num, Flags *flags,
                      char **str) {
  int num_len = s21_strlen(num_str), i = 0, len = 0;
  if (flags->minus) flags->zero = 0;
  if (flags->space && !flags->plus && !flags->zero && num >= 0) {
    *(*str)++ = ' ';
    len++;
  }
  if (flags->width > num_len)
    len += num_len;
  else
    len += num_len;

  if (flags->plus && num > 1e-300) len++;
  if (num < 0) len++;

  if (flags->width && !flags->minus && !flags->zero)
    shift(str, len, flags, ' ');
  if (flags->plus && num >= 0) *(*str)++ = '+';
  if (num < 0) {
    *(*str)++ = '-';
  }
  if (flags->zero && !flags->minus) shift(str, len, flags, '0');
  while (num_str[i] != '\0') *(*str)++ = num_str[i++];
  if (flags->width && flags->minus && !flags->zero) shift(str, len, flags, ' ');
}

void process_e_spec(char *buf, long double num, Flags *flags, char c) {
  if (num < 0) num = -num;
  int i = 0, flag = 0;
  long double left = 0, right;
  right = modfl(num, &left);
  long long cel = left;
  if (cel == 0 && fabsl(num) > 1e-300) {
    for (; !(long long)num; num *= 10, i++) {
    }
    flag = 1;
  } else {
    while ((long long)num) {
      num /= 10;
      if (!(long long)num) {
        num *= 10;
        break;
      }
      i++;
    }
  }
  right = modfl(num, &left);
  cel = left;
  if (c == 'e' || c == 'E')
    s21_ftoa(num, buf, flags);
  else if (right > 1e-300 && (c == 'g' || c == 'G'))
    s21_ftoa_for_g(num, buf, flags);
  else if (c == 'g' || c == 'G')
    s21_itoa(cel, buf);
  buf += s21_strlen(buf);
  format_e_spec(buf, c, flag, i);
}

void format_e_spec(char *buf, char c, int flag, int i) {
  if (c == 'e' || c == 'g')
    *buf = 'e';
  else
    *buf = 'E';
  buf++;
  if (!flag)
    *buf = '+';
  else
    *buf = '-';
  buf++;
  if (i < 10) {
    *buf = '0';
    buf++;
  }
  s21_itoa(i, buf);
}

void spec_proc(char **str) {
  *(*str) = '%';
  ++(*str);
}
