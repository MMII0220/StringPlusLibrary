#ifndef S21_STRING_H_
#define S21_STRING_H_
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#define S21_SIZE_T unsigned long long
#define S21_NULL (void *)0

// MAIN FUNCTIONS
S21_SIZE_T len_befor_space(const char *buf);
S21_SIZE_T s21_strlen(const char *str);
char *s21_strerror(int errnum);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strchr(const char *str, int c);
S21_SIZE_T s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
char *s21_strpbrk(const char *str1, const char *str2);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_insert(const char *src, const char *str, S21_SIZE_T start_index);
void *s21_memchr(const void *str, int c, S21_SIZE_T n);
int s21_memcmp(const void *str1, const void *str2, S21_SIZE_T n);
void *s21_memcpy(void *dest, const void *src, S21_SIZE_T n);
void *s21_memmove(void *dest, const void *src, S21_SIZE_T n);
void *s21_memset(void *str, int c, S21_SIZE_T n);
char *s21_strcpy(char *dest, const char *src);
S21_SIZE_T s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
int s21_strncmp(const char *str1, const char *str2, S21_SIZE_T n);
char *s21_strncpy(char *dest, const char *src, S21_SIZE_T n);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
char *s21_strncat(char *dest, const char *src, int num);
char *s21_strrchr(const char *str, int num);
S21_SIZE_T s21_strcspn(const char *str1, const char *str2);

// SPRINTF_FUNCTIONS
typedef struct Flags {
  int plus;
  int minus;
  int zero;
  int width;
  int precis;
  int point;
  int space;
  int length_l;
  int length_h;
  int length_L;
  int hex;
} Flags;
#define S21_INF __builtin_huge_vall()
#define S21_NAN asin(5);
int s21_sprintf(char *str, const char *buf, ...);
int proc_flags(const char **format, Flags *flags, va_list va);
void proc_spec(char **str, const char **format, va_list va, Flags *flags,
               char *str_start);

int checker(char *buf, Flags *flags, va_list va);
int check_errors(char *format, Flags *flags, va_list va);

char *s21_ftoa_for_g(long double num, char *buf, Flags *flags);
char *s21_ftoa(long double num, char *buf, Flags *flags);
char *s21_otoa(unsigned long long int num, char *buf);
char *s21_itoa(long long int num, char *buf);
char *s21_utoa(unsigned long long num, char *buf);
char *s21_strcat(char *dest, const char *str);
char *reverse_str(char *buf);
char *s21_xtoa(unsigned long long int num, char *buf, char c);

void check_space(char *format, Flags *flags, int *err);
void check_zero(char *format, Flags *flags, int *err);
void check_width(char **format, Flags *flags, int *err);
void check_minus(char *format, Flags *flags, int *err);
void check_star(char *format, Flags *flags, int *err, va_list va);
void check_plus(char *format, Flags *flags, int *err);
void check_precision(char **format, Flags *flags, int *err);
void check_length(char **format, Flags *flags, int *err, char type);
void check_point(char *format, Flags *flags, int *err);
void check_extra(char *format, int *err, char type);
void check_hex(char *format, Flags *flags, int *err);

void formating_floats(char *num_str, long double num, Flags *flags, char **str);
void spec_u(char **str, va_list va, Flags *flags);
void spec_c(char **str, va_list va, Flags *flags);
void spec_s(char **str, va_list va, Flags *flags);
void spec_d(char **str, va_list va, Flags *flags);
void spec_f(char **str, va_list va, Flags *flags);
void spec_e(char **str, const char **format, va_list va, Flags *flags);
void spec_o(char **str, va_list va, Flags *flags);
void spec_x(char **str, const char **format, va_list va, Flags *flags);
void spec_p(char **str, va_list va, Flags *flags);
void spec_n(va_list va, char *str_start);
void spec_g(char **str, const char **format, va_list va, Flags *flags);
void process_e_spec(char *buf, long double num, Flags *flags, char c);
void process_e_spec(char *buf, long double num, Flags *flags, char c);
void spec_proc(char **str);

void add_zeros(char **str, int len, Flags *flags);
void shift(char **str, int len, Flags *flags, char c);

// SCANF_FUNCTIONS
#define BUFF_SIZE 1024
struct options {
  unsigned char plus : 1;
  unsigned char width : 1;
  unsigned char space : 1;
  unsigned char l : 1;
  unsigned char ll : 1;
  unsigned char L : 1;
  unsigned char shrt : 1;
  unsigned char astr : 1;
  unsigned char error : 1;
  unsigned char cnt : 1;
};

int s21_sscanf(const char *buf, const char *params, ...);
void params_buf(const char **params, const char **buf, struct options *opt,
                va_list va, int *cnt, char *patr);

void check_params(const char **params, struct options *opt, int *width);
void check_buf(const char **buf, struct options *opt);
void check_skip_space(struct options *opt, const char **buf);
void check_spaces(const char *params, int *cnt);
void check_modif(const char **params, struct options *opt);
void check_flag(const char **buf, int *cnt, int flag, struct options *opt);
void skip_space(const char **buf);
void add_pattrn(const char **params, char *patr, int *flag_p, int *idx);
void cleaner_patr(char *patr);
void patr_params(const char **buf, char *patr, int idx, struct options *opt);
void check_plus_min(const char **buf, int *minus, int width, int *len);
void add_char(const char **buf, va_list va, int len);
void skip_astr(const char **buf, int len);

int spec_str(const char **buf, va_list va, int width, struct options *opt);
int spec_dec(const char **buf, va_list va, int num, struct options *opt,
             char params);
void spec_proc_n(const char **buf, const char **start, int *cnt_n, va_list va);
void spec_procent(const char **buf);
int spec_char(const char **buf, va_list va, struct options *opt);
int spec_float(const char **buf, va_list va, int num, struct options *opt);
void res(const char **buf, int width, int *cnt_d, int *error, long long *result,
         int minus, char params);
int spec_oct(const char **buf, va_list va, int num, struct options *opt, int a);
int spec_ptr(const char **buf, va_list va, int width, struct options *opt);

int s21_my_atoi(const char *num_c);
int num_for_d(const char **buf, int num, long long *result, char params);
int cnt_numbers(long long num);
void opt_zero(struct options *opt);
void switch_oct_hex(long long *result, char *str, int flag_oct);

// COMMON FUNCTIONS
long long s21_atoi(char *buf);
unsigned long long s21_atou(char *buf);
void s21_my_itoa(int num, char *buf);
#endif  //  S21_STRING_H_