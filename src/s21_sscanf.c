#include "s21_string.h"

int s21_sscanf(const char *buf, const char *params, ...) {
  int cnt = 0;
  char patr[BUFF_SIZE] = {0};
  va_list val, va;
  va_start(val, params);
  va_copy(va, val);
  // проверяем на два пробела
  check_spaces(params, &cnt);
  if (cnt != -1) {
    struct options opt = {0};
    check_buf(&buf, &opt);
    params_buf(&params, &buf, &opt, va, &cnt, patr);
    if (opt.error && 0 == cnt && opt.cnt) {
      cnt = -1;
    }
  }
  cleaner_patr(patr);
  va_end(va);
  return (cnt == -1) ? -1 : cnt;
}

void opt_zero(struct options *opt) {
  opt->astr = 0;
  opt->error = 0;
  opt->L = 0;
  opt->l = 0;
  opt->ll = 0;
  opt->plus = 0;
  opt->shrt = 0;
  opt->space = 0;
  opt->width = 0;
}

void check_buf(const char **buf, struct options *opt) {
  const char *check_buf = *buf;
  skip_space(&check_buf);
  if ('\0' == *check_buf) {
    opt->cnt = 1;
  }
}

void patr_params(const char **buf, char *patr, int idx, struct options *opt) {
  for (int i = 0; i < idx; ++i, ++(*buf), ++patr) {
    if (*patr != *(*buf)) {
      opt->error = 1;
      break;
    }
  }
  check_skip_space(opt, buf);
}

void check_skip_space(struct options *opt, const char **buf) {
  if (opt->space) {
    while (' ' == *(*buf) || '\t' == *(*buf) || '\n' == *(*buf)) {
      ++(*buf);
    }
  }
}

void skip_space(const char **buf) {
  while (' ' == *(*buf) || '\t' == *(*buf) || '\n' == *(*buf)) {
    ++(*buf);
  }
}

void params_buf(const char **params, const char **buf, struct options *opt,
                va_list va, int *cnt, char *patr) {
  int cnt_n = 0, width = 0, idx = 0, flag_p = 0;
  ;
  const char *s_n = *buf;
  while ('\0' != *(*params)) {
    int flag = 0;
    // проверяем на пробел перед %
    if (' ' == *(*params)) {
      opt->space = 1;
    }
    if ('%' == *(*params)) {
      check_skip_space(opt, buf);
      if (flag_p) {
        patr_params(buf, patr, idx, opt);
        if (opt->error) break;
      }
      ++(*params);
      // проверяем стрингу на точность
      check_params(params, opt, &width);
      check_modif(params, opt);
      if ('s' == *(*params)) {
        skip_space(buf);
        flag = spec_str(buf, va, width, opt);
        check_flag(buf, cnt, flag, opt);
        if (!width && !opt->space) ++(*buf);
      } else if ('d' == *(*params) || 'i' == *(*params)) {
        flag = spec_dec(buf, va, width, opt, **params);
        check_flag(buf, cnt, flag, opt);
      } else if ('c' == *(*params)) {
        flag = spec_char(buf, va, opt);
        check_flag(buf, cnt, flag, opt);
      } else if ('n' == *(*params)) {
        spec_proc_n(buf, &s_n, &cnt_n, va);
      } else if ('%' == *(*params)) {
        spec_procent(buf);
      } else if ('o' == *(*params)) {
        flag = spec_oct(buf, va, width, opt, 8);
        check_flag(buf, cnt, flag, opt);
      } else if ('u' == *(*params)) {
        flag = spec_oct(buf, va, width, opt, 10);
        check_flag(buf, cnt, flag, opt);
      } else if ('x' == *(*params) || 'X' == *(*params)) {
        flag = spec_oct(buf, va, width, opt, 16);
        check_flag(buf, cnt, flag, opt);
      } else if (s21_strchr("feEgG", *(*params)) != S21_NULL) {
        flag = spec_float(buf, va, width, opt);
        check_flag(buf, cnt, flag, opt);
      } else if ('p' == *(*params)) {
        flag = spec_ptr(buf, va, width, opt);
        check_flag(buf, cnt, flag, opt);
      }
      if (opt->error) break;
      opt_zero(opt);
      cleaner_patr(patr);
      flag_p = 0, idx = 0;
    } else if ('%' != *(*params) && ' ' != *(*params) && '\t' != *(*params)) {
      add_pattrn(params, patr, &flag_p, &idx);
    }
    ++(*params);
  }
}

void add_pattrn(const char **params, char *patr, int *flag_p, int *idx) {
  patr[*idx] = *(*params);
  ++(*idx);
  *flag_p = 1;
}

void spec_procent(const char **buf) {
  if ('%' == *(*buf)) {
    ++(*buf);
  }
}

char *reverse_str_ss(char *buf) {
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

void check_flag(const char **buf, int *cnt, int flag, struct options *opt) {
  if (0 == flag) {
    if (!opt->astr) ++(*cnt);
    if (opt->space) {
      if (' ' == *(*buf) || '\t' == *(*buf)) ++(*buf);
    }
    opt->astr = 0;
  } else {
    opt->error = 1;
  }
}

void check_spaces(const char *params, int *cnt) {
  if (' ' == params[0] && ' ' == params[1]) {
    *cnt = -1;
  }
}

void check_modif(const char **params, struct options *opt) {
  while ('s' != *(*params) && 'd' != *(*params) && 'c' != *(*params) &&
         'f' != *(*params) && 'e' != *(*params) && 'E' != *(*params) &&
         'G' != *(*params) && 'g' != *(*params) && 'o' != *(*params) &&
         'u' != *(*params) && 'x' != *(*params) && 'X' != *(*params) &&
         'n' != *(*params) && 'i' != *(*params) && 'p' != *(*params) &&
         '%' != *(*params) && '\0' != *(*params)) {
    if ('*' == *(*params)) {
      opt->astr = 1;
      ++(*params);
    } else if ('l' == *(*params) && opt->l) {
      opt->ll = 1;
      opt->l = 0;
      ++(*params);
    } else if ('l' == *(*params)) {
      opt->l = 1;
      ++(*params);
    } else if ('h' == *(*params)) {
      opt->shrt = 1;
      ++(*params);
    } else if (' ' == *(*params)) {
      opt->space = 1;
      ++(*params);
    } else if ('L' == *(*params)) {
      opt->L = 1;
      ++(*params);
    }
  }
}

// длинна строки до пробела или таба
S21_SIZE_T len_befor_space(const char *buf) {
  S21_SIZE_T ans = 0;
  for (; ' ' != *buf && '\0' != *buf && '\t' != *buf && '\n' != *buf;
       ++buf, ++ans)
    ;
  return ans;
}

void check_params(const char **params, struct options *opt, int *width) {
  S21_SIZE_T cnt = 0;
  char str[10] = {'\0'};  // int это 10 чисел
  if (' ' == *(*params)) {
    opt->error = 1;
  } else {
    for (; 's' != *(*params) && 'd' != *(*params) && 'c' != *(*params) &&
           'f' != *(*params) && 'e' != *(*params) && 'E' != *(*params) &&
           'G' != *(*params) && 'g' != *(*params) && 'o' != *(*params) &&
           'u' != *(*params) && 'x' != *(*params) && 'X' != *(*params) &&
           'l' != *(*params) && 'h' != *(*params) && '*' != *(*params) &&
           'n' != *(*params) && 'i' != *(*params) && 'p' != *(*params) &&
           'L' != *(*params) && '%' != *(*params) && '\0' != *(*params);
         ++cnt, ++(*params)) {
      if (48 <= *(*params) && *(*params) <= 57) {
        str[cnt] = *(*params);
      }
    }
  }
  *width = s21_my_atoi(str);
  // return cnt;
}

int s21_my_atoi(const char *num_c) {
  int ans = 0;
  int len = s21_strlen(num_c);
  if (0 < len) {
    if (1 == len) {
      if (48 <= *num_c && 57 >= *num_c) {
        ans = *num_c - 48;
      }
      ++num_c;
    }
    for (; '\0' != *num_c && ' ' != *num_c; ++num_c) {
      if (48 <= *num_c && 57 >= *num_c) {
        ans *= 10;
        ans += *num_c - 48;
      }
    }
  }
  return ans;
}

int cnt_numbers(long long num) {
  int cnt = 0;
  if (0 > num) {
    num *= -1;
  }
  for (; 0 < num; num /= 10, ++cnt)
    ;
  return cnt;
}

void process_i_spef_oct(const char **buf, int *width, int flag_oct,
                        int flag_hex, int *cnt_d, int *error,
                        long long *result) {
  char str[4096] = {'\0'};
  int idx = 0;
  for (; '\0' != *(*buf) &&
         (('0' <= *(*buf) && '9' >= *(*buf)) ||
          ('a' <= *(*buf) && 'f' >= *(*buf)) ||
          ('A' <= *(*buf) && 'F' >= *(*buf))) &&
         0 < *width;
       ++(*buf), ++idx, --(*width)) {
    if (flag_oct) {
      if (**buf >= '0' && **buf <= '7') {
        str[idx] = **buf;
        ++(*cnt_d);
      } else {
        *error = 1;
        break;
      }
    } else if (flag_hex) {
      if (('0' <= *(*buf) && '9' >= *(*buf)) ||
          ('a' <= *(*buf) && 'f' >= *(*buf)) ||
          ('A' <= *(*buf) && 'F' >= *(*buf))) {
        str[idx] = **buf;
        ++(*cnt_d);
      } else {
        *error = 1;
        break;
      }
    }
  }
  reverse_str_ss(str);
  switch_oct_hex(result, str, flag_oct);
}

void res(const char **buf, int width, int *cnt_d, int *error, long long *result,
         int minus, char params) {
  int flag_oct = 0, flag_hex = 0;
  for (; **buf == '0'; (*buf)++) {
    ++(*cnt_d);
    width--;
    if (params == 'i') flag_oct++;
  }
  if ((**buf == 'x' || **buf == 'X') && flag_oct == 1) {
    (*buf)++;
    width--;
    flag_hex = 1;
    ++(*cnt_d);
    flag_oct = 0;
  }
  if (flag_hex == 0 && flag_oct == 0) {
    for (; '\0' != *(*buf) && 48 <= *(*buf) && 57 >= *(*buf) && 0 < width;
         ++(*buf), --width) {
      if (48 <= *(*buf) && 57 >= *(*buf)) {
        *result *= 10;
        *result += *(*buf) - 48;
        ++(*cnt_d);
      } else {
        *error = 1;
        break;
      }
    }
  } else if ((flag_oct || flag_hex)) {
    process_i_spef_oct(buf, &width, flag_oct, flag_hex, cnt_d, error, result);
  }
  if (minus) {
    *result *= -1;
  }
}

void switch_oct_hex(long long *result, char *str, int flag_oct) {
  int len = s21_strlen(str);
  long long c = 1, a = 1;
  if (flag_oct)
    a = 8;
  else
    a = 16;
  long long tmp = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] >= '0' && str[i] <= '9')
      tmp = (long long)(str[i] - 48) * c;
    else if (str[i] >= 'A' && str[i] <= 'F')
      tmp = (long long)(str[i] - 55) * c;
    else
      tmp = (long long)(str[i] - 87) * c;
    (*result) += tmp;
    c *= a;
  }
}

void check_plus_min(const char **buf, int *minus, int width, int *len) {
  if ('-' == *(*buf)) {
    *minus = 1;
    ++(*buf);
    --*len;
  }
  if ('+' == *(*buf) && 0 == width) {
    ++(*buf);
    --*len;
  }
}

int num_for_d(const char **buf, int width, long long *result, char params) {
  int error = 0, cnt_d = 0, minus = 0;  // смогли ли добавить цифру
  if ('\0' == *(*buf)) {
    error = 1;
  } else {
    while (' ' == *(*buf)) {
      ++(*buf);
    }
    const char *leng_str = *buf;
    int len = 0;
    for (; '\0' != *leng_str && ' ' != *leng_str; ++len, ++(leng_str))
      ;
    ;
    check_plus_min(buf, &minus, width, &len);
    if (0 < len) {
      if (1 == len) {
        if (48 <= *(*buf) && 57 >= *(*buf)) {
          *result = *(*buf) - 48;
          ++(*buf);
          ++cnt_d;
        } else {
          error = 1;
        }
        if (minus) {
          *result *= -1;
        }
      } else if (0 < width) {
        res(buf, width, &cnt_d, &error, result, minus, params);
      } else {
        res(buf, len, &cnt_d, &error, result, minus, params);
      }
    } else {
      error = 1;
    }
  }
  if (0 == cnt_d) {
    error = 1;
  }
  return error;
}

void spec_proc_n(const char **buf, const char **start, int *cnt_n, va_list va) {
  while ((*buf) != (*start)) {
    ++*cnt_n;
    ++(*start);
  }
  int *pArg = va_arg(va, int *);
  *pArg = *cnt_n;
}

int spec_dec(const char **buf, va_list va, int width, struct options *opt,
             char params) {
  long long res = 0, error = num_for_d(buf, width, &res, params);
  if (!error) {
    int b = cnt_numbers(res);
    int idx = 0;
    if (width > 0) {
      width = b - width;
    }
    if (0 < width) {
      for (; idx < width; ++idx, res /= 10)
        ;
    }
  }
  if (!opt->astr && !error) {
    if (opt->l) {
      long int *pArg = va_arg(va, long int *);
      *pArg = (long)res;
    } else if (opt->ll) {
      long long int *pArg = va_arg(va, long long int *);
      *pArg = (long long)res;
    } else if (opt->shrt) {
      short int *pArg = va_arg(va, short int *);
      *pArg = (short)res;
    } else {
      int *pArg = va_arg(va, int *);
      *pArg = (int)res;
    }
  }
  return error;
}

void skip_astr(const char **buf, int len) {
  for (; ' ' != *(*buf) && '\t' != *(*buf) && '\n' != *(*buf) && 0 < len;
       ++(*buf), --len)
    ;
}

void add_char(const char **buf, va_list va, int len) {
  // char *pArg = calloc(len, sizeof(char));
  char *pArg = va_arg(va, char *);
  for (; ' ' != *(*buf) && '\t' != *(*buf) && '\n' != *(*buf) && 0 < len;
       ++(*buf), ++pArg, --len) {
    *pArg = *(*buf);
  }
}

int spec_str(const char **buf, va_list va, int width, struct options *opt) {
  int error = 0;
  if ('\0' == *(*buf)) {
    error = 1;
  } else {
    S21_SIZE_T len = len_befor_space(*buf);
    // если есть ширина то читаем до ширины
    if (0 == width) {
      if (!opt->astr) {
        add_char(buf, va, len);
      } else
        skip_astr(buf, len);
    } else if (0 < width) {
      if (!opt->astr) {
        add_char(buf, va, width);
        if (' ' == *(*buf) || '\t' == *(*buf)) ++(*buf);
      } else
        skip_astr(buf, width);
    } else {
      error = 1;
    }
  }
  return error;
}

void cleaner_patr(char *patr) {
  int idx;
  for (idx = 0; '\0' != patr[idx]; ++idx) {
    patr[idx] = '\0';
  }
}

int spec_char(const char **buf, va_list va, struct options *opt) {
  int error = 0;
  if (!opt->astr) {
    if (0 <= *(*buf) && 126 >= *(*buf)) {
      char *pArg = va_arg(va, char *);
      *pArg = *(*buf);
      ++(*buf);
    }
  } else {
    if (0 <= *(*buf) && 126 >= *(*buf)) {
      ++(*buf);
    }
  }
  return error;
}

void check_signes(int *error, int *width, const char **buf, int *minus_flag) {
  int flag = 0;
  if (**buf == '-') {
    (*minus_flag)++;
    (*buf)++;
    (*width)--;
    flag = 1;
  }
  if (**buf == '+') {
    (*buf)++;
    (*width)--;
    flag = 1;
  }
  if (*width < 0) {
    *width = 0;
  } else if (*width == 0 && flag == 1) {
    *error = -1;
    *width = -1;
  }
}

int spec_ptr(const char **buf, va_list va, int width, struct options *opt) {
  int error = 0, minus_flag = 0, idx;
  unsigned long long res = 0;
  char str[4096] = {'\0'};
  if (**buf == '0') {
    (*buf)++;
    width--;
    if (**buf == 'x') {
      (*buf)++;
      width--;
    }
  }
  if (!(s21_strchr("0123456789ABCDEFabcdef+- ", **buf) != S21_NULL)) error = -1;
  if (!error) {
    idx = 0;
    check_signes(&error, &width, buf, &minus_flag);
    int sig = 0;
    if (width == 0) {
      width = 100;
      sig = 1;
    }
    for (; **buf != ' ' && idx < width && **buf != '\t' && **buf != '\0' &&
           **buf != '\n';
         (*buf)++, idx++) {
      if (!((**buf >= '0' && **buf <= '9') || (**buf >= 'A' && **buf <= 'F') ||
            (**buf >= 'a' && **buf <= 'f')))
        break;
      str[idx] = (char)**buf;
      if (sig) width++;
    }
    reverse_str_ss(str);
    int len = s21_strlen(str);
    for (int i = 0; i < len; i++) {
      if (str[i] >= '0' && str[i] <= '9')
        res += (int)(str[i] - 48) * pow(16, i);
      else if (str[i] >= 'A' && str[i] <= 'F')
        res += (int)(str[i] - 55) * pow(16, i);
      else
        res += (int)(str[i] - 87) * pow(16, i);
    }
    if (minus_flag) res = -res;
    if (!opt->astr) {
      unsigned *result = va_arg(va, unsigned *);
      if (error == 0) {
        *result = (unsigned)res;
      }
    }
  }
  return error;
}

void check_inf(const char **buf, int *error, int *width) {
  (*buf)++;
  (*width)--;
  if ((**buf == 'N' || **buf == 'n') && *width) {
    (*buf)++;
    (*width)--;
  } else {
    *error = -1;
  }
  if ((**buf == 'F' || **buf == 'f') && *width) {
    (*buf)++;
    (*width)--;
  } else {
    *error = -1;
  }
}
void check_nan(const char **buf, int *error, int *width) {
  (*buf)++;
  (*width)--;
  if ((**buf == 'a' || **buf == 'A') && *width) {
    (*buf)++;
    (*width)--;
  } else {
    *error = -1;
  }
  if ((**buf == 'N' || **buf == 'n') && *width) {
    (*buf)++;
    (*width)--;
  } else {
    *error = -1;
  }
}

void assign_oct(struct options *opt, va_list va, unsigned long long res,
                int error) {
  if (opt->ll && !opt->astr) {
    unsigned long long *result = va_arg(va, unsigned long long *);
    if (error == 0) *result = res;
  } else if (opt->l && !opt->astr) {
    unsigned long *result = va_arg(va, unsigned long *);
    if (error == 0) *result = (unsigned long)res;
  } else if (opt->shrt && !opt->astr) {
    unsigned short *result = va_arg(va, unsigned short *);
    if (error == 0) *result = (unsigned short)res;
  } else if (!opt->astr) {
    unsigned *result = va_arg(va, unsigned *);
    if (error == 0) *result = (unsigned)res;
  }
}

void create_str_for_oct(const char **buf, int idx, int width, int *error, int a,
                        int sig, char *str) {
  int count_x = 0;
  for (; **buf != ' ' && idx < width && **buf != '\t' && **buf != '\0' &&
         **buf != '\n';
       (*buf)++, idx++) {
    if (a == 10) {
      if (!((**buf >= '0' && **buf <= '9'))) {
        *error = -1;
        break;
      }
    } else if (a == 8) {
      if (!((**buf >= '0' && **buf <= '7'))) break;
    } else {
      if (**buf == 'x' || **buf == 'X') {
        width--;
        idx--;
        count_x++;
        if (count_x > 1) break;
        continue;
      }
      if (!((**buf >= '0' && **buf <= '9') || (**buf >= 'A' && **buf <= 'F') ||
            (**buf >= 'a' && **buf <= 'f')))
        break;
    }
    str[idx] = (char)**buf;
    if (sig) width++;
  }
}

void process_oct_str(char *str, struct options *opt, unsigned long long *res,
                     int a, int minus_flag) {
  if (str[0] != '\0')
    reverse_str_ss(str);
  else
    opt->error = 1;
  int len = s21_strlen(str);
  unsigned long long c = 1, tmp = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] >= '0' && str[i] <= '9')
      tmp = (unsigned long long)(str[i] - 48) * c;
    else if (str[i] >= 'A' && str[i] <= 'F')
      tmp = (unsigned long long)(str[i] - 55) * c;
    else
      tmp = (unsigned long long)(str[i] - 87) * c;
    (*res) += tmp;
    c *= a;
  }
  if (minus_flag) *res = -(*res);
}

int spec_oct(const char **buf, va_list va, int width, struct options *opt,
             int a) {
  int error = 0, minus_flag = 0, idx = 0;
  unsigned long long res = 0;
  char str[4096] = {'\0'};
  skip_space(buf);
  if (*buf == S21_NULL || **buf == '\0') opt->error = 1;
  if (a == 10) {
    if (!(s21_strchr("0123456789+-", **buf) != S21_NULL && **buf != '\0'))
      error = -1;
  } else if (a == 8) {
    if (!(s21_strchr("01234567+-", **buf) != S21_NULL && **buf != '\0'))
      error = -1;
  } else {
    if (!(s21_strchr("Xx0123456789ABCDEFabcdef+-", **buf) != S21_NULL &&
          **buf != '\0'))
      error = -1;
  }
  if (error == 0) {
    check_signes(&error, &width, buf, &minus_flag);
    int sig = 0;
    if (width == 0) {
      width = 10;
      sig = 1;
    }
    create_str_for_oct(buf, idx, width, &error, a, sig, str);
    process_oct_str(str, opt, &res, a, minus_flag);
    assign_oct(opt, va, res, error);
  }
  return error;
}

long double s21_atof(char *buf) {
  long double result = 0, drob = 0;
  int flag = 0;
  for (; *buf != '\0'; buf++) {
    if (*buf == '.') {
      flag = 1;
      break;
    }
    result *= 10;
    result += *buf - 48;
  }
  if (flag) buf++;
  int i = 1;
  for (; *buf != '\0'; buf++) {
    drob += (*buf - 48) / pow(10, i);
    i++;
  }
  result += drob;
  return result;
}

void create_str_for_float(const char **buf, int *idx, int sig, int *width,
                          int *point_flag, char *str) {
  for (; **buf != ' ' && *idx < *width && **buf != '\t' && **buf != 'e' &&
         **buf != 'E' && **buf != '\0' && **buf != '\n';
       (*buf)++, (*idx)++) {
    if ((**buf < '0' || **buf > '9') && **buf != '.') break;
    if (**buf == '.') (*point_flag)++;
    if (*point_flag > 1) break;
    str[*idx] = (char)**buf;
    if (sig) (*width)++;
  }
}

void process_exp_int_floats(const char **buf, int idx, int width, int sig,
                            long double *res) {
  char estr[4096] = {'\0'};
  if (**buf == 'e' || **buf == 'E') {
    (*buf)++;
    idx++;
    int minus_pow = 0;
    int i = 0;
    for (; *(*buf) != ' ' && idx < width && *(*buf) != '\t' &&
           *(*buf) != '\0' && *(*buf) != '\n';
         (*buf)++, idx++) {
      if ((*(*buf) < '0' || *(*buf) > '9') && *(*buf) != '-' && *(*buf) != '+')
        break;
      if (*(*buf) == '-') {
        minus_pow++;
      }
      if (sig) width++;
      if (minus_pow > 1) break;
      if (*(*buf) != '+') {
        estr[i] = (char)*(*buf);
        i++;
      }
    }
    int del = 0;
    if (estr[0] != '\0') {
      del = s21_atoi(estr);
      // printf("%d\n", del); exit(1);
      *(res) *= pow(10, del);
    }
  }
}

void assign_res_float(long double res, struct options *opt, va_list va,
                      int error) {
  if (opt->L && !opt->astr) {
    long double *result = va_arg(va, long double *);
    if (error == 0) *result = res;
  } else if (opt->l && !opt->astr) {
    double *result = va_arg(va, double *);
    if (error == 0) *result = (double)res;
  } else if (!opt->astr) {
    float *result = va_arg(va, float *);
    if (error == 0) *result = (float)res;
  }
}

int spec_float(const char **buf, va_list va, int width, struct options *opt) {
  int minus_flag = 0;
  long double res = 0;
  char str[4096] = {'\0'};
  int error = 0;
  int idx, point_flag;
  if (**buf == '\0') {
    opt->error = 1;
  } else if (!(s21_strchr("0123456789iIenNE+-. ", **buf) != S21_NULL)) {
    error = -1;
  } else {
    skip_space(buf);
    idx = 0;
    point_flag = 0;
    check_signes(&error, &width, buf, &minus_flag);
    if (**buf == 'i' || **buf == 'I') {
      check_inf(buf, &error, &width);
      if (!error) res = S21_INF;
    } else if (**buf == 'n' || **buf == 'N') {
      check_nan(buf, &error, &width);
      if (error == 0) res = S21_NAN;
    } else {
      int sig = 0;
      if (width == 0) {
        width = 10;
        sig = 1;
      }
      create_str_for_float(buf, &idx, sig, &width, &point_flag, str);
      if (!(str[0] == '.' && str[1] == '\0'))
        res = s21_atof(str);
      else
        error = -1;
      process_exp_int_floats(buf, idx, width, sig, &res);
    }
    if (minus_flag) res = -res;
    assign_res_float(res, opt, va, error);
  }
  return error;
}
