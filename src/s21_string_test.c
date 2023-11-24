#include "s21_string.h"

#include <check.h>
#include <stdio.h>
#include <string.h>
// MAIN FUNCTIONS
START_TEST(s21_my_itoa_my) {
  char itoa_one[BUFF_SIZE] = {'\0'};
  char itoa_two[BUFF_SIZE] = "0";
  int itoa_ans_one = 0;
  s21_my_itoa(itoa_ans_one, itoa_one);
  ck_assert_str_eq(itoa_one, itoa_two);
}
END_TEST

START_TEST(s21_atoi_my) {
  char *atoi_one = "234.566";
  char *atoi_two = "234.566";
  long long ans1 = s21_atoi(atoi_one);
  long long ans2 = atoi(atoi_two);
  ck_assert_uint_eq(ans1, ans2);
}
END_TEST

START_TEST(s21_strcspn_my) {
  char strcspn_a1[BUFF_SIZE] = "abcd";
  char strcspn_a2[BUFF_SIZE] = "arty";
  S21_SIZE_T strcspn_n1 = s21_strcspn(strcspn_a1, strcspn_a2);
  S21_SIZE_T strcspn_n2 = strcspn(strcspn_a1, strcspn_a2);
  ck_assert_int_eq(strcspn_n1, strcspn_n2);
  char strcspn_a3[BUFF_SIZE] = "abcd";
  char strcspn_a4[BUFF_SIZE] = "drty";
  S21_SIZE_T strcspn_n3 = s21_strcspn(strcspn_a3, strcspn_a4);
  S21_SIZE_T strcspn_n4 = strcspn(strcspn_a3, strcspn_a4);
  ck_assert_int_eq(strcspn_n3, strcspn_n4);
  char strcspn_a5[BUFF_SIZE] = "";
  char strcspn_a6[BUFF_SIZE] = "\n";
  S21_SIZE_T strcspn_n5 = s21_strcspn(strcspn_a5, strcspn_a6);
  S21_SIZE_T strcspn_n6 = strcspn(strcspn_a5, strcspn_a6);
  ck_assert_int_eq(strcspn_n5, strcspn_n6);
  char strcspn_a7[BUFF_SIZE] = "\0";
  char strcspn_a8[BUFF_SIZE] = "\0";
  S21_SIZE_T strcspn_n7 = s21_strcspn(strcspn_a7, strcspn_a8);
  S21_SIZE_T strcspn_n8 = strcspn(strcspn_a7, strcspn_a8);
  ck_assert_int_eq(strcspn_n7, strcspn_n8);
}
END_TEST

START_TEST(s21_strcpy_my) {
  char strcpy_a1[BUFF_SIZE] = "abcdefgh";
  char strcpy_a2[BUFF_SIZE] = "igk";
  char *strcpy_s1 = s21_strcpy(strcpy_a1, strcpy_a2);
  char *strcpy_s2 = strcpy(strcpy_a1, strcpy_a2);
  ck_assert_str_eq(strcpy_s1, strcpy_s2);
  char strcpy_a3[BUFF_SIZE] = "abcdefgh";
  char strcpy_a4[BUFF_SIZE] = "";
  char *strcpy_s3 = s21_strcpy(strcpy_a3, strcpy_a4);
  char *strcpy_s4 = strcpy(strcpy_a3, strcpy_a4);
  ck_assert_str_eq(strcpy_s3, strcpy_s4);
  char strcpy_a5[BUFF_SIZE] = "\n\n\n";
  char strcpy_a6[BUFF_SIZE] = "\n";
  char *strcpy_s5 = s21_strcpy(strcpy_a5, strcpy_a6);
  char *strcpy_s6 = strcpy(strcpy_a5, strcpy_a6);
  ck_assert_str_eq(strcpy_s5, strcpy_s6);
}
END_TEST

START_TEST(s21_strncpy_my) {
  char strncpy_a1[BUFF_SIZE] = "abcdefgh";
  char strncpy_a2[BUFF_SIZE] = "igk";
  char *strncpy_s1 = s21_strncpy(strncpy_a1, strncpy_a2, 1);
  char *strncpy_s2 = strncpy(strncpy_a1, strncpy_a2, 1);
  ck_assert_str_eq(strncpy_s1, strncpy_s2);
  char *strncpy_s5 = s21_strncpy(strncpy_a1, strncpy_a2, 3);
  char *strncpy_s6 = strncpy(strncpy_a1, strncpy_a2, 3);
  ck_assert_str_eq(strncpy_s5, strncpy_s6);
  char strncpy_a3[BUFF_SIZE] = "\n\n\n";
  char strncpy_a4[BUFF_SIZE] = "\n";
  char *strncpy_s7 = s21_strncpy(strncpy_a3, strncpy_a4, 4);
  char *strncpy_s8 = strncpy(strncpy_a3, strncpy_a4, 4);
  ck_assert_str_eq(strncpy_s7, strncpy_s8);
}
END_TEST

START_TEST(s21_memchr_my) {
  char data[BUFF_SIZE] = {'q', 'r', 's', 't', 'p', 'a', 'x'};
  char *my_ans = s21_memchr(data, 'r', 5);
  char *real_ans = memchr(data, 'r', 5);
  ck_assert_msg(my_ans, real_ans, 0, 0);
  ck_assert_msg(s21_memchr(data, 'r', 1), memchr(data, 'r', 1), 0, 0);
  ck_assert_msg(s21_memchr(data, 'z', 1), memchr(data, 'z', 1), 0, 0);
  ck_assert_ptr_null(s21_memchr(data, 'z', 0));
}
END_TEST

START_TEST(s21_memcmp_my) {
  /* test string */
  char memcmp_a1[BUFF_SIZE] = "abss";
  char memcmp_a2[BUFF_SIZE] = "aabs";
  ck_assert_int_ge(s21_memcmp(memcmp_a1, memcmp_a2, 4),
                   memcmp(memcmp_a1, memcmp_a2, 4));
  ck_assert_int_eq(s21_memcmp(memcmp_a1, memcmp_a2, 1),
                   memcmp(memcmp_a1, memcmp_a2, 1));
  // ck_assert_int_ge(s21_memcmp(memcmp_a1, memcmp_a2, 2),
  //                  memcmp(memcmp_a1, memcmp_a2, 2));
  ck_assert_int_ge(s21_memcmp(memcmp_a1, memcmp_a2, 5),
                   memcmp(memcmp_a1, memcmp_a2, 5));
  char memcmp_a3[BUFF_SIZE] = "abss";
  char memcmp_a4[BUFF_SIZE] = "aabs";
  ck_assert_int_le(s21_memcmp(memcmp_a3, memcmp_a4, 4),
                   memcmp(memcmp_a3, memcmp_a4, 4));
  ck_assert_int_eq(s21_memcmp(memcmp_a3, memcmp_a4, 1),
                   memcmp(memcmp_a3, memcmp_a4, 1));
  ck_assert_int_le(s21_memcmp(memcmp_a3, memcmp_a4, 2),
                   memcmp(memcmp_a3, memcmp_a4, 2));
  ck_assert_int_le(s21_memcmp(memcmp_a3, memcmp_a4, 5),
                   memcmp(memcmp_a3, memcmp_a4, 5));
  char memcmp_a5[BUFF_SIZE] = "aaaaa";
  char memcmp_a6[BUFF_SIZE] = "aaaaa";
  ck_assert_int_eq(s21_memcmp(memcmp_a5, memcmp_a6, 4),
                   memcmp(memcmp_a5, memcmp_a6, 4));
  ck_assert_int_eq(s21_memcmp(memcmp_a5, memcmp_a6, 1),
                   memcmp(memcmp_a5, memcmp_a6, 1));
  ck_assert_int_eq(s21_memcmp(memcmp_a5, memcmp_a6, 2),
                   memcmp(memcmp_a5, memcmp_a6, 2));
  ck_assert_int_eq(s21_memcmp(memcmp_a5, memcmp_a6, 6),
                   memcmp(memcmp_a5, memcmp_a6, sizeof(char) * 6));
  /* test numbers array */
  int s1[BUFF_SIZE] = {1, 2, 3, 4};
  int s2[BUFF_SIZE] = {1, 2, 6, 4};
  ck_assert_int_ge(s21_memcmp(s1, s2, 3), memcmp(s1, s2, 3));
  ck_assert_int_eq(s21_memcmp(s1, s2, 2), memcmp(s1, s2, 2));
  ck_assert_int_ge(s21_memcmp(s1, s2, 4), memcmp(s1, s2, 4));
  int s3[BUFF_SIZE] = {1, 2, 6, 4};
  int s4[BUFF_SIZE] = {1, 2, 3, 4};
  ck_assert_int_le(s21_memcmp(s3, s4, 3), memcmp(s3, s4, 3));
  ck_assert_int_eq(s21_memcmp(s3, s4, 2), memcmp(s3, s4, 2));
  ck_assert_int_le(s21_memcmp(s3, s4, 4), memcmp(s3, s4, 4));

  // New cases
  int str1 = 711362;
  int str2 = 717362;

  ck_assert_int_le(memcmp(&str1, &str2, 4), s21_memcmp(&str1, &str2, 4));

  float str3 = 123456.5656;
  float str4 = 103456.11256;
  float my_str3 = 123456.5656;
  float my_str4 = 103456.1126;

  ck_assert_int_eq(memcmp(&str3, &str4, 1), s21_memcmp(&my_str3, &my_str4, 1));

  int str5 = 1;
  float str6 = 1.01;

  ck_assert_int_eq(memcmp(&str5, &str6, 1), s21_memcmp(&str5, &str6, 1));

  char str11[BUFF_SIZE] = "School_21\nSchool_21";
  char str12[BUFF_SIZE] = "School_21";
  char my_str11[BUFF_SIZE] = "School_21\nSchool_21";
  char my_str12[BUFF_SIZE] = "School_21";

  ck_assert_int_eq(memcmp(str11, str12, 5), s21_memcmp(my_str11, my_str12, 5));

  char str15[BUFF_SIZE] = "";
  char str16[BUFF_SIZE] = "Hello world!";
  char my_str15[BUFF_SIZE] = "";
  char my_str16[BUFF_SIZE] = "Hello world!";

  ck_assert_int_ge(memcmp(str15, str16, 5), s21_memcmp(my_str15, my_str16, 5));

  char str17[BUFF_SIZE] = " \0";
  char str18[BUFF_SIZE] = "Hello world!";
  char my_str17[BUFF_SIZE] = " \0";
  char my_str18[BUFF_SIZE] = "Hello world!";

  ck_assert_int_ge(memcmp(&str17, &str18, 5),
                   s21_memcmp(&my_str17, &my_str18, 5));

  char str19[BUFF_SIZE] = "     \n";
  char str20[BUFF_SIZE] = "Hello world!";
  char my_str19[BUFF_SIZE] = "     \n";
  char my_str20[BUFF_SIZE] = "Hello world!";

  ck_assert_int_ge(memcmp(str19, str20, 5), s21_memcmp(my_str19, my_str20, 5));
}
END_TEST

START_TEST(s21_memcpy_my) {
  char memcpy_my1[BUFF_SIZE] = "abss";
  char memcpy_my2[BUFF_SIZE] = "tabs";
  char memcpy_real1[BUFF_SIZE] = "abss";
  char memcpy_real2[BUFF_SIZE] = "tabs";
  ck_assert_str_eq(s21_memcpy(memcpy_my1, memcpy_my2, 3),
                   memcpy(memcpy_real1, memcpy_real2, 3));
  char memcpy_my3[BUFF_SIZE] = "";
  char memcpy_my4[BUFF_SIZE] = "";
  char memcpy_real3[BUFF_SIZE] = "";
  char memcpy_real4[BUFF_SIZE] = "";
  ck_assert_str_eq(s21_memcpy(memcpy_my3, memcpy_my4, 1),
                   memcpy(memcpy_real3, memcpy_real4, 1));
  /* test number array */
  int my_arr[10] = {8, 3, 11, 61, -22, 7, -6, 2, 13, 47};
  int new_arr_my[5] = {0};
  int new_arr_origin[5] = {0};
  s21_memcpy(new_arr_my, my_arr, 5);
  memcpy(new_arr_origin, my_arr, 5);
  for (int idx = 0; idx < 5; idx++) {
    ck_assert_int_eq(new_arr_my[idx], new_arr_origin[idx]);
  }

  // New cases
  char str1[BUFF_SIZE] = "Happy New Year!";
  char str2[BUFF_SIZE] = "The strcpy() function copies the string";

  ck_assert_str_eq(memcpy(str1, str2, 4), s21_memcpy(str1, str2, 4));

  char str3[BUFF_SIZE] = "Happy New Year!";
  char str4[BUFF_SIZE] = "123456789";

  ck_assert_str_eq(memcpy(str3, str4, 8), s21_memcpy(str3, str4, 8));

  char str5[BUFF_SIZE] = "Happy New Year!";
  char str6[BUFF_SIZE] = "\0";

  ck_assert_str_eq(memcpy(str5, str6, 1), s21_memcpy(str5, str6, 1));

  char str7[BUFF_SIZE] = "\0";
  char str8[BUFF_SIZE] = "Happy New Year!";

  ck_assert_str_eq(memcpy(str7, str8, 10), s21_memcpy(str7, str8, 10));

  char str9[BUFF_SIZE] = "\nqwerty";
  char str10[BUFF_SIZE] = "The strcpy() function copies the string";

  ck_assert_str_eq(memcpy(str9, str10, 4), s21_memcpy(str9, str10, 4));

  char str11[BUFF_SIZE] = "Happy New Year!";
  char str12[BUFF_SIZE] = "\nqwerty";

  ck_assert_str_eq(memcpy(str11, str12, 4), s21_memcpy(str11, str12, 4));

  char str14[BUFF_SIZE] = "\0";
  char str15[BUFF_SIZE] = "\0";

  ck_assert_str_eq(memcpy(str14, str15, 0), s21_memcpy(str14, str15, 0));

  char str16[BUFF_SIZE] = "  school21";
  char str17[BUFF_SIZE] = "The strcpy() function copies the string";

  ck_assert_str_eq(memcpy(str16, str17, 5), s21_memcpy(str16, str17, 5));

  char str18[BUFF_SIZE] = "01/01/2023";
  char str19[BUFF_SIZE] = "12345";

  ck_assert_str_eq(memcpy(str18, str19, 10), s21_memcpy(str18, str19, 10));

  char str20[BUFF_SIZE] = " ";
  char str21[BUFF_SIZE] = " ";

  ck_assert_str_eq(memcpy(str20, str21, 1), s21_memcpy(str20, str21, 1));
}
END_TEST

START_TEST(s21_memmove_my) {
  char a_my[BUFF_SIZE] = "abss";
  char a_origin[BUFF_SIZE] = "abss";
  char memmov_a2[BUFF_SIZE] = "tabs";
  s21_memmove(a_my, memmov_a2, 3);
  memmove(a_origin, memmov_a2, 3);
  ck_assert_str_eq(a_my, a_origin);
  char a_my_2[BUFF_SIZE] = "******************************";
  char a_origin_2[BUFF_SIZE] = "******************************";
  char memmove_a4[BUFF_SIZE] = "abcdefghijklmnopqrstuvwxyz0123456789";
  s21_memmove(a_my_2, memmove_a4, 26);
  memmove(a_origin_2, memmove_a4, 26);
  ck_assert_str_eq(a_my, a_origin);

  // New cases
  char str1[BUFF_SIZE] = "Happy New Year!";
  char str2[BUFF_SIZE] = "The strcpy() function copies the string";

  ck_assert_str_eq(memmove(str1, str2, 4), s21_memmove(str1, str2, 4));

  char str3[BUFF_SIZE] = "Happy New Year!";
  char str4[BUFF_SIZE] = "123456789";

  ck_assert_str_eq(memmove(str3, str4, 8), s21_memmove(str3, str4, 8));

  char str5[BUFF_SIZE] = "\0";
  char str6[BUFF_SIZE] = "Happy New Year!";

  ck_assert_str_eq(memmove(str5, str6, 1), s21_memmove(str5, str6, 1));

  char str7[BUFF_SIZE] = "\nqwerty";
  char str8[BUFF_SIZE] = "The strcpy() function copies the string";

  ck_assert_str_eq(memmove(str7, str8, 10), s21_memmove(str7, str8, 10));

  char str9[BUFF_SIZE] = "Happy New Year!";
  char str10[BUFF_SIZE] = "\nqwerty";

  ck_assert_str_eq(memmove(str9, str10, 4), s21_memmove(str9, str10, 4));

  char str11[BUFF_SIZE] = "01/01/2023";
  char str12[BUFF_SIZE] = "12345";

  ck_assert_str_eq(memmove(str11, str12, 10), s21_memmove(str11, str12, 10));

  char str13[BUFF_SIZE] = " ";
  char str14[BUFF_SIZE] = " ";

  ck_assert_str_eq(memmove(str13, str14, 4), s21_memmove(str13, str14, 4));

  char str15[BUFF_SIZE] = "\0";
  char str16[BUFF_SIZE] = "\0";

  ck_assert_str_eq(memmove(str15, str16, 0), s21_memmove(str15, str16, 0));
}
END_TEST

START_TEST(s21_memset_my) {
  char str_my[BUFF_SIZE] = "This is a test of the memset function";
  char str_origin[BUFF_SIZE] = "This is a test of the memset function";
  s21_memset(str_my, '*', 5);
  memset(str_origin, '*', 5);
  ck_assert_str_eq(str_my, str_origin);
  char str_my_2[BUFF_SIZE] = "tabs";
  char str_origin_2[BUFF_SIZE] = "tabs";
  s21_memset(str_my_2, 'a', 1);
  memset(str_origin_2, 'a', 1);
  char str_my_3[BUFF_SIZE] = "******************************";
  char str_origin_3[BUFF_SIZE] = "******************************";
  ck_assert_str_eq(s21_memset(str_my_3, 'g', 20),
                   memset(str_origin_3, 'g', 20));
  char str1[BUFF_SIZE] = "Happy New Year!";
  int str2 = 'k';

  ck_assert_str_eq(memset(str1, str2, 4), s21_memset(str1, str2, 4));

  char str3[BUFF_SIZE] = "Happy New Year!";
  int str4 = '3';

  ck_assert_str_eq(memset(str3, str4, 4), s21_memset(str3, str4, 4));

  char str5[BUFF_SIZE] = "\nqwerty";
  int str6 = '2';

  ck_assert_str_eq(memset(str5, str6, 4), s21_memset(str5, str6, 4));

  char str7[BUFF_SIZE] = "\0";
  int str8 = 'k';

  ck_assert_str_eq(memset(str7, str8, 1), s21_memset(str7, str8, 1));

  char str11[BUFF_SIZE] = "\0";
  int str12 = 'a';

  ck_assert_str_eq(memset(str11, str12, 10), s21_memset(str11, str12, 10));

  char str13[BUFF_SIZE] = "  school21";
  int str14 = 'k';

  ck_assert_str_eq(memset(str13, str14, 1), s21_memset(str13, str14, 1));
}
END_TEST

START_TEST(s21_strlen_my) {
  char my_strlen_a1[BUFF_SIZE] = "This is a test of the memset function";
  ck_assert_int_eq(s21_strlen(my_strlen_a1), strlen(my_strlen_a1));
  char my_strlen_a2[BUFF_SIZE] = "tabs";
  ck_assert_int_eq(s21_strlen(my_strlen_a2), strlen(my_strlen_a2));
  char my_strlen_a3[BUFF_SIZE] = "******************************";
  ck_assert_int_eq(s21_strlen(my_strlen_a3), strlen(my_strlen_a3));
  char my_strlen_a4[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_strlen(my_strlen_a4), strlen(my_strlen_a4));
}
END_TEST

START_TEST(s21_strcat_my) {
  char my_cat_b1[BUFF_SIZE] = " lalala";
  char my_cat_b2[BUFF_SIZE] = "This is a test of the memset function";
  char real_cat_b1[BUFF_SIZE] = " lalala";
  char real_cat_b2[BUFF_SIZE] = "This is a test of the memset function";
  s21_strcat(my_cat_b1, my_cat_b2);
  strcat(real_cat_b1, real_cat_b2);
  ck_assert_str_eq(my_cat_b1, real_cat_b1);
  char my_cat_a1[BUFF_SIZE] = " lalala";
  char my_cat_a2[BUFF_SIZE] = "This is a test of the memset function";
  char real_cat_a1[BUFF_SIZE] = " lalala";
  char real_cat_a2[BUFF_SIZE] = "This is a test of the memset function";
  s21_strcat(my_cat_a1, my_cat_a2);
  strcat(real_cat_a1, real_cat_a2);
  ck_assert_str_eq(my_cat_a1, real_cat_a1);
}
END_TEST

START_TEST(s21_strchr_my) {
  char str[BUFF_SIZE] = "My name is Ayush Belbek";
  char *my_ch = s21_strchr(str, 'a');
  char *real_ch = strchr(str, 'a');
  ck_assert_str_eq((my_ch), (real_ch));
  char ch1 = 'A', ch2 = 'z', ch3 = '\0';
  char *ans_my = s21_strchr(str, ch1);
  char *ans_real = strchr(str, ch1);
  ck_assert_str_eq(ans_my, ans_real);
  char *ans_my_2 = s21_strchr(str, ch2);
  char *ans_real_2 = strchr(str, ch2);
  ck_assert_ptr_null(ans_my_2);
  ck_assert_ptr_null(ans_real_2);
  char *ans_my_3 = s21_strchr(str, ch3);
  char *ans_real_3 = strchr(str, ch3);
  ck_assert_str_eq(ans_my_3, ans_real_3);
}
END_TEST

START_TEST(s21_strcmp_my) {
  char *strcmp_s1 = "Hello";
  char *strcmp_s2 = "Aticleworld";
  ck_assert_int_eq(s21_strcmp(strcmp_s1, strcmp_s2),
                   strcmp(strcmp_s1, strcmp_s2));
  char *strcmp_a1 = "Aticleworld";
  char *strcmp_a2 = "Aticleworld";
  ck_assert_int_eq(s21_strcmp(strcmp_a1, strcmp_a2),
                   strcmp(strcmp_a1, strcmp_a2));
  char *strcmp_b1 = "Aticleworld";
  char *strcmp_b2 = "Hello";
  ck_assert_int_eq(s21_strcmp(strcmp_b1, strcmp_b2),
                   strcmp(strcmp_b1, strcmp_b2));
  char *strcmp_c1 = "";
  char *strcmp_c2 = "";
  ck_assert_int_eq(s21_strcmp(strcmp_c1, strcmp_c2),
                   strcmp(strcmp_c1, strcmp_c2));
  char strcmp_str1[BUFF_SIZE] = "\0";
  char strcmp_str2[BUFF_SIZE] = "\0";
  ck_assert_int_eq(strcmp(strcmp_str1, strcmp_str2),
                   s21_strcmp(strcmp_str1, strcmp_str2));

  char strcmp_str3[BUFF_SIZE] = "";
  char strcmp_str4[BUFF_SIZE] = "";
  ck_assert_int_eq(strcmp(strcmp_str3, strcmp_str4),
                   s21_strcmp(strcmp_str3, strcmp_str4));

  char strcmp_str5[BUFF_SIZE] = "\n";
  char strcmp_str6[BUFF_SIZE] = "\n";
  ck_assert_int_eq(strcmp(strcmp_str5, strcmp_str6),
                   s21_strcmp(strcmp_str5, strcmp_str6));

  char strcmp_str7[BUFF_SIZE] = "s21_NULL";
  char strcmp_str8[BUFF_SIZE] = "\n s21_NULL";
  ck_assert_int_eq(strcmp(strcmp_str7, strcmp_str8),
                   s21_strcmp(strcmp_str7, strcmp_str8));

  char strcmp_str9[BUFF_SIZE] = "\tHello\0";
  char strcmp_str10[BUFF_SIZE] = "Hello world!";
  ck_assert_int_eq(strcmp(strcmp_str9, strcmp_str10),
                   s21_strcmp(strcmp_str9, strcmp_str10));

  char strcmp_str11[BUFF_SIZE] = "School_21\nSchool_21";
  char strcmp_str12[BUFF_SIZE] = "School_21";
  ck_assert_int_eq(strcmp(strcmp_str11, strcmp_str12),
                   s21_strcmp(strcmp_str11, strcmp_str12));

  char strcmp_str13[BUFF_SIZE] = "987654321";
  char strcmp_str14[BUFF_SIZE] = "Hello world!";
  ck_assert_int_eq(strcmp(strcmp_str13, strcmp_str14),
                   s21_strcmp(strcmp_str13, strcmp_str14));

  char strcmp_str15[BUFF_SIZE] = "";
  char strcmp_str16[BUFF_SIZE] = "Hello world!";
  ck_assert_int_eq(strcmp(strcmp_str15, strcmp_str16),
                   s21_strcmp(strcmp_str15, strcmp_str16));

  char strcmp_str17[BUFF_SIZE] = " \0";
  char strcmp_str18[BUFF_SIZE] = "Hello world!";
  ck_assert_int_eq(strcmp(strcmp_str17, strcmp_str18),
                   s21_strcmp(strcmp_str17, strcmp_str18));

  char strcmp_str19[BUFF_SIZE] = "     \n";
  char strcmp_str20[BUFF_SIZE] = "Hello world!";
  ck_assert_int_eq(strcmp(strcmp_str19, strcmp_str20),
                   s21_strcmp(strcmp_str19, strcmp_str20));

  char strcmp_str21[BUFF_SIZE] = "SCHOOL21";
  char strcmp_str22[BUFF_SIZE] = "Hello world!";
  ck_assert_int_eq(strcmp(strcmp_str21, strcmp_str22),
                   s21_strcmp(strcmp_str21, strcmp_str22));

  char strcmp_str23[BUFF_SIZE] =
      "Computes the length of the string str up to but not including the "
      "terminating null character.";
  char strcmp_str24[BUFF_SIZE] = "Hello world!";
  ck_assert_int_eq(strcmp(strcmp_str23, strcmp_str24),
                   s21_strcmp(strcmp_str23, strcmp_str24));

  char strcmp_str25[BUFF_SIZE] =
      "Computes\tthe\tlength\tof\tthe\tstring\tstr\tup\tto\tbut\tnot\tincluding"
      "\tthe\tterminating\tnull\tcharacter.";
  char strcmp_str26[BUFF_SIZE] = "Hello world!";
  ck_assert_int_eq(strcmp(strcmp_str25, strcmp_str26),
                   s21_strcmp(strcmp_str25, strcmp_str26));

  char strcmp_str27[BUFF_SIZE] =
      "Вычисляет длину строки str, не включая завершающий нулевой символ.";
  char strcmp_str28[BUFF_SIZE] = "Hello world!";
  ck_assert_int_eq(strcmp(strcmp_str27, strcmp_str28),
                   s21_strcmp(strcmp_str27, strcmp_str28));

  char strcmp_str29[BUFF_SIZE] = "School_21\0School_21";
  char strcmp_str30[BUFF_SIZE] = "Hello world!";
  ck_assert_int_eq(strcmp(strcmp_str29, strcmp_str30),
                   s21_strcmp(strcmp_str29, strcmp_str30));
}
END_TEST

START_TEST(s21_strerror_my) {
  ck_assert_str_eq(strerror(0), s21_strerror(0));
  ck_assert_str_eq(strerror(-11), s21_strerror(-11));
  ck_assert_pstr_eq(strerror(106), s21_strerror(106));
  ck_assert_pstr_eq(strerror(109), s21_strerror(109));
  int idx;
  for (idx = -11; idx < 159; idx++) {
    ck_assert_str_eq(strerror(idx), s21_strerror(idx));
  }
}
END_TEST

START_TEST(s21_strpbrk_my) {
  char pbrk_str1[BUFF_SIZE] = "abcde2fghi3jk4lasd";
  char pbrk_str2[BUFF_SIZE] = "34";
  char pbrk_str3[BUFF_SIZE] = "d";
  char pbrk_str4[BUFF_SIZE] = "";
  char pbrk_str5[BUFF_SIZE] = "";
  char *pbrk_ret;
  char *pbrk_my_ret;

  pbrk_ret = strpbrk(pbrk_str1, pbrk_str2);
  pbrk_my_ret = s21_strpbrk(pbrk_str1, pbrk_str2);
  ck_assert_pstr_eq(pbrk_ret, pbrk_my_ret);
  pbrk_ret = strpbrk(pbrk_str2, pbrk_str1);
  pbrk_my_ret = s21_strpbrk(pbrk_str2, pbrk_str1);
  ck_assert_pstr_eq(pbrk_ret, pbrk_my_ret);
  pbrk_ret = strpbrk(pbrk_str1, pbrk_str3);
  pbrk_my_ret = s21_strpbrk(pbrk_str1, pbrk_str3);
  ck_assert_pstr_eq(pbrk_ret, pbrk_my_ret);
  pbrk_ret = strpbrk(pbrk_str3, pbrk_str1);
  pbrk_my_ret = s21_strpbrk(pbrk_str3, pbrk_str1);
  ck_assert_pstr_eq(pbrk_ret, pbrk_my_ret);
  pbrk_ret = strpbrk(pbrk_str1, pbrk_str4);
  pbrk_my_ret = s21_strpbrk(pbrk_str1, pbrk_str4);
  ck_assert_pstr_eq(pbrk_ret, pbrk_my_ret);
  pbrk_ret = strpbrk(pbrk_str4, pbrk_str5);
  pbrk_my_ret = s21_strpbrk(pbrk_str4, pbrk_str5);
  ck_assert_pstr_eq(pbrk_ret, pbrk_my_ret);
  pbrk_ret = strpbrk(pbrk_str4, pbrk_str1);
  pbrk_my_ret = s21_strpbrk(pbrk_str4, pbrk_str1);
  ck_assert_pstr_eq(pbrk_ret, pbrk_my_ret);
}
END_TEST

START_TEST(s21_strspn_my) {
  char strspn_str[BUFF_SIZE] = "0123456789";
  char strspn_sym_1[BUFF_SIZE] = "210";
  char strspn_sym_2[BUFF_SIZE] = "012";
  char strspn_sym_3[BUFF_SIZE] = "";
  S21_SIZE_T my_len = 0, real_len = 0;
  real_len = strspn("это строка из примера", "акортэ с");
  my_len = s21_strspn("это строка из примера", "акортэ с");
  ck_assert_uint_eq(real_len, my_len);
  ck_assert_uint_eq(strspn(strspn_str, strspn_sym_1),
                    s21_strspn(strspn_str, strspn_sym_1));
  ck_assert_uint_eq(strspn(strspn_str, strspn_sym_2),
                    s21_strspn(strspn_str, strspn_sym_2));
  ck_assert_uint_eq(strspn(strspn_sym_2, strspn_str),
                    s21_strspn(strspn_sym_2, strspn_str));
  ck_assert_uint_eq(strspn(strspn_str, strspn_sym_3),
                    s21_strspn(strspn_str, strspn_sym_3));
  ck_assert_uint_eq(strspn(strspn_sym_3, strspn_str),
                    s21_strspn(strspn_sym_3, strspn_str));
  ck_assert_uint_eq(strspn(strspn_sym_1, strspn_sym_2),
                    s21_strspn(strspn_sym_1, strspn_sym_2));

  // New cases
  char str1[BUFF_SIZE] = "Hello world";
  char str2[BUFF_SIZE] = "world";

  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));

  char str3[BUFF_SIZE] = "Hello world";
  char str4[BUFF_SIZE] = "\0";

  ck_assert_int_eq(strspn(str3, str4), s21_strspn(str3, str4));

  char str5[BUFF_SIZE] = "Hello world\nHello world\0";
  char str6[BUFF_SIZE] = "world";

  ck_assert_int_eq(strspn(str5, str6), s21_strspn(str5, str6));

  char str7[BUFF_SIZE] =
      "ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2))";
  char str8[BUFF_SIZE] = "world";

  ck_assert_int_eq(strspn(str7, str8), s21_strspn(str7, str8));

  char str9[BUFF_SIZE] = "\0";
  char str10[BUFF_SIZE] = "world";

  ck_assert_int_eq(strspn(str9, str10), s21_strspn(str9, str10));

  char str11[BUFF_SIZE] = "world123456789";
  char str12[BUFF_SIZE] = "45";

  ck_assert_int_eq(strspn(str11, str12), s21_strspn(str11, str12));

  char str13[BUFF_SIZE] = "MooMooMooMooMooMooMoo";
  char str14[BUFF_SIZE] = "M";

  ck_assert_int_eq(strspn(str13, str14), s21_strspn(str13, str14));

  char str15[BUFF_SIZE] = "ck\t\t\tck\t\t\tck";
  char str16[BUFF_SIZE] = "     ";

  ck_assert_int_eq(strspn(str15, str16), s21_strspn(str15, str16));
}
END_TEST

START_TEST(s21_strstr_my) {
  char *strstr_p_1 = strstr("хлопот невпроворот", "от");
  char *strstr_my_p_1 = s21_strstr("хлопот невпроворот", "от");
  char *strstr_p_2 = strstr("от", "хлопот невпроворот");
  char *strstr_my_p_2 = s21_strstr("от", "хлопот невпроворот");
  ck_assert_pstr_eq(strstr_p_1, strstr_my_p_1);
  ck_assert_ptr_null(strstr_p_2);
  ck_assert_ptr_null(strstr_my_p_2);
  char *strstr_ru_string = "хлопот невпроворот.!%)";
  char *strstr_kaystack = "This is the way.";
  char *strstr_search = "the";
  char *strstr_wrong = "now";
  char *strstr_empty = "";
  ck_assert_pstr_eq(strstr(strstr_kaystack, strstr_search),
                    s21_strstr(strstr_kaystack, strstr_search));
  ck_assert_pstr_eq(strstr(strstr_kaystack, strstr_wrong),
                    s21_strstr(strstr_kaystack, strstr_wrong));
  ck_assert_pstr_eq(strstr(strstr_ru_string, strstr_wrong),
                    s21_strstr(strstr_ru_string, strstr_wrong));
  ck_assert_pstr_eq(strstr(strstr_kaystack, strstr_empty),
                    s21_strstr(strstr_kaystack, strstr_empty));
  ck_assert_ptr_null(s21_strstr(strstr_kaystack, strstr_wrong));
  ck_assert_ptr_null(strstr(strstr_kaystack, strstr_wrong));
  ck_assert_ptr_null(s21_strstr(strstr_ru_string, strstr_wrong));
  ck_assert_ptr_null(strstr(strstr_ru_string, strstr_wrong));

  char str1[BUFF_SIZE] = "Hello world!";
  char str2[BUFF_SIZE] = "world";

  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));

  char str3[BUFF_SIZE] = "Hello world!";
  char str4[BUFF_SIZE] = "LO";

  ck_assert_ptr_eq(strstr(str3, str4), s21_strstr(str3, str4));

  char str5[BUFF_SIZE] = "\0";
  char str6[BUFF_SIZE] = "123";

  ck_assert_ptr_eq(strstr(str5, str6), s21_strstr(str5, str6));

  char str7[BUFF_SIZE] = "Hello world!";
  char str8[BUFF_SIZE] = "\0";

  ck_assert_ptr_eq(strstr(str7, str8), s21_strstr(str7, str8));

  char str9[BUFF_SIZE] =
      "The strstr() function finds the first occurrence of the substring "
      "needle in the string haystack.  The terminating null bytes ('\0') are "
      "not compared.";
  char str10[BUFF_SIZE] = "\0";

  ck_assert_ptr_eq(strstr(str9, str10), s21_strstr(str9, str10));

  char str11[BUFF_SIZE] =
      "The strstr() function finds the first occurrence of the substring "
      "needle in the string haystack.";
  char str12[BUFF_SIZE] = " ";

  ck_assert_ptr_eq(strstr(str11, str12), s21_strstr(str11, str12));

  char str13[BUFF_SIZE] =
      "The strstr() function finds the first occurrence of the substring "
      "needle in the string haystack.";
  char str14[BUFF_SIZE] = "()";

  ck_assert_ptr_eq(strstr(str13, str14), s21_strstr(str13, str14));

  char str15[BUFF_SIZE] =
      "The strstr() function finds the first occurrence of the substring "
      "needle in the string haystack.";
  char str16[BUFF_SIZE] = ".";

  ck_assert_ptr_eq(strstr(str15, str16), s21_strstr(str15, str16));

  char str17[BUFF_SIZE] = ".";
  char str18[BUFF_SIZE] = "hello";

  ck_assert_ptr_eq(strstr(str17, str18), s21_strstr(str17, str18));
  char str19[BUFF_SIZE] = "Hello";
  char str20[BUFF_SIZE] = "hello";

  ck_assert_ptr_eq(strstr(str19, str20), s21_strstr(str19, str20));

  char str21[BUFF_SIZE] = "1212121212121";
  char str22[BUFF_SIZE] = "21";

  ck_assert_ptr_eq(strstr(str21, str22), s21_strstr(str21, str22));

  char str23[BUFF_SIZE] = "";
  char str24[BUFF_SIZE] = "";

  ck_assert_ptr_eq(strstr(str23, str24), s21_strstr(str23, str24));

  char str25[BUFF_SIZE] = "safQhilufas7MaSef2345wknwefnkjHawe2fhilu";
  char str26[BUFF_SIZE] = "";

  ck_assert_ptr_eq(strstr(str25, str26), s21_strstr(str25, str26));

  char str27[BUFF_SIZE] = "You are toxic!";
  char str28[BUFF_SIZE] = "toxic";

  ck_assert_ptr_eq(strstr(str27, str28), s21_strstr(str27, str28));

  char str29[BUFF_SIZE] = "AD AD AD";
  char str30[BUFF_SIZE] = "AD";

  ck_assert_ptr_eq(strstr(str29, str30), s21_strstr(str29, str30));

  char str31[BUFF_SIZE] = "-";
  char str32[BUFF_SIZE] = "1234567890qwertyuiopasdfghjk-";

  ck_assert_ptr_eq(strstr(str31, str32), s21_strstr(str31, str32));

  char *s1 = "School-21";
  char *s2 = "ho";
  char *s3 = "";

  ck_assert_msg(s21_strstr(s1, s2) == strstr(s1, s2), "1st strstr test failed");
  ck_assert_msg(s21_strstr(s1, s3) == strstr(s1, s3), "2nd strstr test failed");
  ck_assert_msg(s21_strstr(s3, s2) == strstr(s3, s2), "3rd strstr test failed");
  ck_assert_msg(s21_strstr(s2, s3) == strstr(s2, s3),
                "4rth strstr test failed");
  ck_assert_msg(s21_strstr(s3, s1) == strstr(s3, s1), "5th strstr test failed");
}
END_TEST

START_TEST(s21_strtok_my) {
  char strtok_str1[BUFF_SIZE] = "Это не баг, это фича.";
  char strtok_str2[BUFF_SIZE] = "Это не баг, это фича.";
  char *strtok_my_ans = s21_strtok(strtok_str1, " .,");
  char *strtok_real_ans = strtok(strtok_str2, " .,");
  ck_assert_pstr_eq(strtok_my_ans, strtok_real_ans);
  while (strtok_my_ans != NULL) {
    ck_assert_pstr_eq(strtok_my_ans, strtok_real_ans);
    strtok_my_ans = s21_strtok(NULL, " ,.");
    strtok_real_ans = strtok(NULL, " .,");
  }
}
END_TEST

START_TEST(s21_trim_my) {
  char *trim_str = "   Hell World    ";
  const char *tim = "";
  char *result = s21_trim(trim_str, tim);
  char *res_str = "Hell World";
  ck_assert_pstr_eq(result, res_str);
  if (result) free(result);
  trim_str = "   \nHell World\n    ";
  result = s21_trim(trim_str, "");
  ck_assert_pstr_eq(result, "Hell World");
  if (result) free(result);

  result = s21_trim(res_str, "Hel");
  ck_assert_pstr_eq(result, " World");
  if (result) free(result);
  result = s21_trim(trim_str, S21_NULL);
  ck_assert_pstr_eq("Hell World", result);
  if (result) free(result);
  result = s21_trim(S21_NULL, S21_NULL);
  ck_assert_ptr_null(result);
  if (result) free(result);
  result = s21_trim(S21_NULL, "*");
  ck_assert_ptr_null(result);
  if (result) free(result);
  char *src = "123Happy 123 New Year123";
  char *trim_chars = "123";
  char *my_trim = s21_trim(src, trim_chars);
  char *real = "Happy 123 New Year";
  ck_assert_str_eq(my_trim, real);
  if (my_trim) free(my_trim);

  char *src_1 = "\t\n   Trim-function!     \t\n";
  char *trim_chars_1 = " \t\n!";
  char *my_trim_1 = s21_trim(src_1, trim_chars_1);
  char *real_1 = "Trim-function";
  ck_assert_str_eq(my_trim_1, real_1);
  if (my_trim_1) free(my_trim_1);

  char src_2[BUFF_SIZE] = "12321";
  char trim_chars_2[BUFF_SIZE] = "123";
  char *my_trim_2 = s21_trim(src_2, trim_chars_2);
  char real_2[BUFF_SIZE] = "";
  ck_assert_str_eq(my_trim_2, real_2);
  if (my_trim_2) free(my_trim_2);
  char src_3[BUFF_SIZE] = "    \t\nHello world!\t\n    ";
  char trim_chars_3[BUFF_SIZE] = "";
  char *my_trim_3 = s21_trim(src_3, trim_chars_3);
  char real_3[BUFF_SIZE] = "Hello world!";
  ck_assert_str_eq(my_trim_3, real_3);
  if (my_trim_3) free(my_trim_3);

  char *src_4 = "    \t\n\t\n    ";
  char *trim_chars_4 = "";
  char *my_trim_4 = s21_trim(src_4, trim_chars_4);
  char *real_4 = "";
  ck_assert_str_eq(my_trim_4, real_4);
  if (my_trim_4) free(my_trim_4);
  char *src_5 = "    \t\nHello world!\t\n    ";
  char *trim_chars_5 = S21_NULL;
  char *my_trim_5 = s21_trim(src_5, trim_chars_5);
  char real_5[BUFF_SIZE] = "Hello world!";
  ck_assert_str_eq(my_trim_5, real_5);
  if (my_trim_5) free(my_trim_5);
  char *src_6 = "    \t\n\t\n    ";
  char *trim_chars_6 = NULL;
  char *my_trim_6 = s21_trim(src_6, trim_chars_6);
  char real_6[BUFF_SIZE] = "";
  ck_assert_str_eq(my_trim_6, real_6);
  if (my_trim_6) free(my_trim_6);

  char src_7[BUFF_SIZE] = "";
  char *trim_chars_7 = NULL;
  char *my_trim_7 = s21_trim(src_7, trim_chars_7);
  char real_7[BUFF_SIZE] = "";
  ck_assert_str_eq(my_trim_7, real_7);
  if (my_trim_7) free(my_trim_7);
  char *src_8 = S21_NULL;
  char *trim_chars_8 = "1234567890";
  char *my_trim_8 = s21_trim(src_8, trim_chars_8);
  char *real_8 = S21_NULL;
  ck_assert_ptr_eq(my_trim_8, real_8);
  if (my_trim_8) free(my_trim_8);
  char *src_9 = S21_NULL;
  char trim_chars_9[BUFF_SIZE] = "";
  char *my_trim_9 = s21_trim(src_9, trim_chars_9);
  char *real_9 = S21_NULL;
  ck_assert_ptr_eq(my_trim_9, real_9);
  if (my_trim_9) free(my_trim_9);
  char *src_10 = "abrakadabra";
  char *trim_chars_10 = "123";
  char *my_trim_10 = s21_trim(src_10, trim_chars_10);
  char real_10[BUFF_SIZE] = "abrakadabra";
  ck_assert_str_eq(my_trim_10, real_10);
  if (my_trim_10) free(my_trim_10);
  //  New cases
  char src1[BUFF_SIZE] = "123Hello world123";
  char trim_chars1[BUFF_SIZE] = "123";
  char *my_trim1 = s21_trim(src1, trim_chars1);
  char real1[BUFF_SIZE] = "Hello world";

  ck_assert_str_eq(my_trim1, real1);
  if (my_trim1) free(my_trim1);

  char src2[BUFF_SIZE] = "123Happy 123 New Year123";
  char trim_chars2[BUFF_SIZE] = "123";
  char *my_trim2 = s21_trim(src2, trim_chars2);
  char real2[BUFF_SIZE] = "Happy 123 New Year";

  ck_assert_str_eq(my_trim2, real2);
  if (my_trim2) free(my_trim2);

  char src3[BUFF_SIZE] = "     Trim-function      ";
  char trim_chars3[BUFF_SIZE] = "123";
  char *my_trim3 = s21_trim(src3, trim_chars3);
  char real3[BUFF_SIZE] = "     Trim-function      ";

  ck_assert_str_eq(my_trim3, real3);

  if (my_trim3) free(my_trim3);

  char src4[BUFF_SIZE] = "\t\n   Trim-function!     \t\n";
  char trim_chars4[BUFF_SIZE] = " \t\n!";
  char *my_trim4 = s21_trim(src4, trim_chars4);
  char real4[BUFF_SIZE] = "Trim-function";

  ck_assert_str_eq(my_trim4, real4);
  if (my_trim4) free(my_trim4);

  char src5[BUFF_SIZE] = "12321";
  char trim_chars5[BUFF_SIZE] = "123";
  char *my_trim5 = s21_trim(src5, trim_chars5);
  char real5[BUFF_SIZE] = "";

  ck_assert_str_eq(my_trim5, real5);
  if (my_trim5) free(my_trim5);

  char src6[BUFF_SIZE] = "    Hello world!    ";
  char trim_chars6[BUFF_SIZE] = "";
  char *my_trim6 = s21_trim(src6, trim_chars6);
  char real6[BUFF_SIZE] = "Hello world!";

  ck_assert_str_eq(my_trim6, real6);
  if (my_trim6) free(my_trim6);

  char src7[BUFF_SIZE] = "    \t\nHello world!\t\n    ";
  char trim_chars7[BUFF_SIZE] = "";
  char *my_trim7 = s21_trim(src7, trim_chars7);
  char real7[BUFF_SIZE] = "Hello world!";

  ck_assert_str_eq(my_trim7, real7);
  if (my_trim7) free(my_trim7);

  char src8[BUFF_SIZE] = "    \t\n\t\n    ";
  char trim_chars8[BUFF_SIZE] = "";
  char *my_trim8 = s21_trim(src8, trim_chars8);
  char real8[BUFF_SIZE] = "";

  ck_assert_str_eq(my_trim8, real8);
  if (my_trim8) free(my_trim8);
  char src9[BUFF_SIZE] = "    \t\nHello world!\t\n    ";
  char *trim_chars9 = NULL;
  char *my_trim9 = s21_trim(src9, trim_chars9);
  char real9[BUFF_SIZE] = "Hello world!";

  ck_assert_str_eq(my_trim9, real9);
  if (my_trim9) free(my_trim9);

  char src10[BUFF_SIZE] = "    \t\nHello world!";
  char *trim_chars10 = NULL;
  char *my_trim10 = s21_trim(src10, trim_chars10);
  char real10[BUFF_SIZE] = "Hello world!";

  ck_assert_str_eq(my_trim10, real10);
  if (my_trim10) free(my_trim10);

  char src11[BUFF_SIZE] = "    \t\n\t\n    ";
  char *trim_chars11 = NULL;
  char *my_trim11 = s21_trim(src11, trim_chars11);
  char real11[BUFF_SIZE] = "";

  ck_assert_str_eq(my_trim11, real11);
  if (my_trim11) free(my_trim11);
  char src12[BUFF_SIZE] = "";
  char *trim_chars12 = NULL;
  char *my_trim12 = s21_trim(src12, trim_chars12);
  char real12[BUFF_SIZE] = "";
  ck_assert_str_eq(my_trim12, real12);
  if (my_trim12) free(my_trim12);

  char *src13 = NULL;
  char trim_chars13[BUFF_SIZE] = "1234567890";
  char *my_trim13 = s21_trim(src13, trim_chars13);
  char *real13 = NULL;

  ck_assert_ptr_eq(my_trim13, real13);
  if (my_trim13) free(my_trim13);
  char *src14 = NULL;
  char trim_chars14[BUFF_SIZE] = "";
  char *my_trim14 = s21_trim(src14, trim_chars14);
  char *real14 = NULL;

  ck_assert_ptr_eq(my_trim14, real14);
  if (my_trim14) free(my_trim14);

  char src15[BUFF_SIZE] = "1234567890";
  char trim_chars15[BUFF_SIZE] = "a";
  char *my_trim15 = s21_trim(src15, trim_chars15);
  char real15[BUFF_SIZE] = "1234567890";

  ck_assert_str_eq(my_trim15, real15);
  if (my_trim15) free(my_trim15);
}
END_TEST

START_TEST(s21_strncat_test) {
  char str1[BUFF_SIZE] = "Hello";
  char str2[BUFF_SIZE] = "Hihichpok";

  char str3[BUFF_SIZE] = "Hello";
  char str4[BUFF_SIZE] = "Hihichpok";

  ck_assert_str_eq(s21_strncat(str1, str2, 3), strncat(str3, str4, 3));

  char str5[BUFF_SIZE] = "";
  char str6[BUFF_SIZE] = "";

  char str7[BUFF_SIZE] = "";
  char str8[BUFF_SIZE] = "";

  ck_assert_str_eq(s21_strncat(str5, str6, 0), strncat(str7, str8, 0));

  char str9[BUFF_SIZE] = "\0";
  char str10[BUFF_SIZE] = "12345";

  char str11[BUFF_SIZE] = "\0";
  char str12[BUFF_SIZE] = "12345";

  ck_assert_str_ne(s21_strncat(str9, str10, 1), strncat(str11, str12, 2));

  char str13[BUFF_SIZE] = "\0";
  char str14[BUFF_SIZE] = "BIGFLOPP";

  char str15[BUFF_SIZE] = "\0";
  char str16[BUFF_SIZE] = "BIGFLOPP";

  ck_assert_str_eq(s21_strncat(str13, str14, 4), strncat(str15, str16, 4));
}
END_TEST

START_TEST(s21_strncmp_test) {
  char str1[BUFF_SIZE] = "Hello";
  char str2[BUFF_SIZE] = "Hihichpok";

  ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));

  char str3[BUFF_SIZE] = "pupadupa";
  char str4[BUFF_SIZE] = "pupadupa";

  ck_assert_int_eq(s21_strncmp(str3, str4, 1), strncmp(str3, str4, 1));

  char str111[BUFF_SIZE] = "pupadupa";
  char str112[BUFF_SIZE] = "pupadupa";

  ck_assert_int_eq(s21_strncmp(str111, str112, 6), strncmp(str111, str112, 6));

  char str5[BUFF_SIZE] = "a";
  char str6[BUFF_SIZE] = "A";

  ck_assert_int_eq(s21_strncmp(str5, str6, 1), strncmp(str5, str6, 1));

  char str7[BUFF_SIZE] = "";
  char str8[BUFF_SIZE] = "";

  ck_assert_int_eq(s21_strncmp(str7, str8, 1), strncmp(str7, str8, 1));

  char str9[BUFF_SIZE] = "pupadupa";
  char str10[BUFF_SIZE] = "";

  ck_assert_int_eq(s21_strncmp(str9, str10, 0), strncmp(str9, str10, 0));

  char str11[BUFF_SIZE] = "";
  char str12[BUFF_SIZE] = "pupadupa";

  ck_assert_int_eq(s21_strncmp(str11, str12, 0), strncmp(str11, str12, 0));

  char str13[BUFF_SIZE] = "pupadupabazbazkotya";
  char str14[BUFF_SIZE] = "pupadupabaz";

  ck_assert_int_eq(s21_strncmp(str13, str14, 10), strncmp(str13, str14, 10));

  char str15[BUFF_SIZE] = "HelloA";
  char str16[BUFF_SIZE] = "HelloB";

  ck_assert_int_eq(s21_strncmp(str15, str16, 9), strncmp(str15, str16, 9));

  char str17[BUFF_SIZE] = "Hello, world!";
  char str18[BUFF_SIZE] = "Hello, world!";

  ck_assert_int_eq(s21_strncmp(str17, str18, 13), strncmp(str17, str18, 13));

  char str19[BUFF_SIZE] = "Abc";
  char str20[BUFF_SIZE] = "abc";

  ck_assert_int_eq(s21_strncmp(str19, str20, 10), strncmp(str19, str20, 10));

  char str21[BUFF_SIZE] = "";
  char str22[BUFF_SIZE] = "";

  ck_assert_int_eq(s21_strncmp(str21, str22, 10), strncmp(str21, str22, 10));

  // char *t1 = "Sample Text";
  // char *t2 = "Sample Text Plus Some Text";
  // ck_assert_msg(!s21_strncmp(t1, t2, 10) && !strncmp(t1, t2, 10),
  //                 "1st strncmp test failed");

  // ck_assert_msg(s21_strncmp(t1, t2, 14) < 0 && strncmp(t1, t2, 14) < 0,
  //                 "2nd strncmp test failed");
  char *t3 = "";
  char *t4 = "A";
  ck_assert_int_eq(s21_strncmp(t3, t4, 0), strncmp(t3, t4, 0));
  // ck_assert_int_eq(s21_strncmp(t3, t4, 1), strncmp(t3, t4, 1));
  char *t5 = "ShrekAmogus";
  char *t6 = "Shr";
  ck_assert_int_eq(s21_strncmp(t5, t6, 5), strncmp(t5, t6, 5));
  // ck_assert_int_eq(s21_strncmp(t5, t6, 0), strncmp(t5, t6, 0));

  char str1111[BUFF_SIZE] = "Hello";
  char str1112[BUFF_SIZE] = "Hihichpok";

  ck_assert_int_eq(s21_strncmp(str1111, str1112, 0),
                   strncmp(str1111, str1112, 0));

  char str1113[BUFF_SIZE] = {'\0'};
  char str1114[BUFF_SIZE] = "Hihichpok";

  ck_assert_int_eq(s21_strncmp(str1113, str1114, 0),
                   strncmp(str1113, str1114, 0));

  char str1115[BUFF_SIZE] = "asd";
  char str1116[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_strncmp(str1115, str1116, 0),
                   strncmp(str1115, str1116, 0));

  char str1117[BUFF_SIZE] = "asd";
  char str1118[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_strncmp(str1117, str1118, 1),
                   strncmp(str1117, str1118, 1));

  char str1119[BUFF_SIZE] = {'\0'};
  char str1120[BUFF_SIZE] = "Hihichpok";
  ck_assert_int_eq(s21_strncmp(str1119, str1120, 1),
                   strncmp(str1119, str1120, 1));
}
END_TEST

START_TEST(s21_to_lower_test) {
  char str1[BUFF_SIZE] = "ShLePa V TaZ1Ke?";
  char str2[BUFF_SIZE] = "shlepa v taz1ke?";
  char *result = s21_to_lower(str1);
  ck_assert_str_eq(result, str2);
  if (result) free(result);

  char str3[BUFF_SIZE] = "123456789Q";
  char str4[BUFF_SIZE] = "123456789q";
  result = s21_to_lower(str3);
  ck_assert_str_eq(result, str4);
  if (result) free(result);

  char str5[BUFF_SIZE] = "Space created";
  char str6[BUFF_SIZE] = "space created";
  result = s21_to_lower(str5);
  ck_assert_str_eq(result, str6);
  if (result) free(result);

  char str7[BUFF_SIZE] = "";
  char str8[BUFF_SIZE] = "";
  result = s21_to_lower(str7);
  ck_assert_str_eq(result, str8);
  if (result) free(result);

  char str9[BUFF_SIZE] = "!#$#@$*&(RD#&";
  char str10[BUFF_SIZE] = "!#$#@$*&(rd#&";
  result = s21_to_lower(str9);
  ck_assert_str_eq(result, str10);
  if (result) free(result);

  char str11[BUFF_SIZE] = "asdasdzxc q213 123 345 !$&*";
  char str12[BUFF_SIZE] = "asdasdzxc q213 123 345 !$&*";
  result = s21_to_lower(str11);
  ck_assert_str_eq(result, str12);
  if (result) free(result);

  char str13[BUFF_SIZE] = " ";
  char str14[BUFF_SIZE] = " ";
  result = s21_to_lower(str13);
  ck_assert_str_eq(result, str14);
  if (result) free(result);

  char destination[BUFF_SIZE] = "HERE W0 ARE123\0";
  char *test01 = s21_to_lower(destination);
  ck_assert_str_eq(test01, "here w0 are123");
  if (test01) free(test01);

  char destination2[BUFF_SIZE] = "HERE W0 ARE\n\0";
  char *test02 = s21_to_lower(destination2);
  ck_assert_str_eq(test02, "here w0 are\n");
  if (test02) free(test02);

  char destination3[BUFF_SIZE] = "A\n\0";
  char *test03 = s21_to_lower(destination3);
  ck_assert_str_eq(test03, "a\n");
  if (test03) free(test03);

  char destination4[BUFF_SIZE] = " \n\0";
  char *test04 = s21_to_lower(destination4);
  ck_assert_str_eq(test04, " \n");
  if (test04) free(test04);

  char destination5[BUFF_SIZE] = " \0";
  char *test05 = s21_to_lower(destination5);
  ck_assert_str_eq(test05, " ");
  if (test05) free(test05);

  char destination6[BUFF_SIZE] = "\n\0";
  char *test06 = s21_to_lower(destination6);
  ck_assert_str_eq(test06, "\n");
  if (test06) free(test06);

  char destination7[BUFF_SIZE] = "\0";
  char *test07 = s21_to_lower(destination7);
  ck_assert_str_eq(test07, "");
  if (test07) free(test07);
}
END_TEST

START_TEST(s21_strrchr_test) {
  char str1[BUFF_SIZE] = "";
  int str2 = '\0';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));

  char str3[BUFF_SIZE] = "floppy";
  int str4 = '\0';

  ck_assert_pstr_eq(s21_strrchr(str3, str4), strrchr(str3, str4));

  char str5[BUFF_SIZE] = "";
  int str6 = 'f';

  ck_assert_pstr_eq(s21_strrchr(str5, str6), strrchr(str5, str6));
}
END_TEST

START_TEST(s21_insert_my) {
  char str1[BUFF_SIZE] = "123456789";
  char str2[BUFF_SIZE] = "abcd";
  char *result = s21_insert(str1, str2, 4);
  ck_assert_str_eq(result, "1234abcd56789");
  if (result) free(result);
  result = s21_insert(str2, str1, 4);
  ck_assert_str_eq(result, "abcd123456789");
  if (result) free(result);
  result = s21_insert(str1, str2, 15);
  ck_assert_ptr_null(result);
  if (result) free(result);
  result = s21_insert(str1, str2, 0);
  ck_assert_str_eq(result, "abcd123456789");
  if (result) free(result);
  result = s21_insert(str1, S21_NULL, 3);
  ck_assert_ptr_null(result);
  if (result) free(result);
  char str3[BUFF_SIZE] = "";
  char str4[BUFF_SIZE] = "love school";

  result = s21_insert(str3, str4, 0);
  ck_assert_str_eq(result, str4);
  if (result) free(result);
  result = s21_insert(S21_NULL, S21_NULL, 0);
  ck_assert_ptr_null(result);
  if (result) free(result);
  char str5[BUFF_SIZE] = "";
  char str6[BUFF_SIZE] = "";
  result = s21_insert(str5, str6, 0);
  ck_assert_str_eq(result, "");
  if (result) free(result);
  result = s21_insert(str5, str6, 2);
  ck_assert_ptr_null(result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_upper_test) {
  char str1[BUFF_SIZE] = "empty";
  char str2[BUFF_SIZE] = "EMPTY";
  char *result1 = s21_to_upper(str1);
  ck_assert_str_eq(result1, str2);
  if (result1) free(result1);

  char str3[BUFF_SIZE] = "1+1*1";
  char str4[BUFF_SIZE] = "1+1*1";

  char *result2 = s21_to_upper(str3);
  ck_assert_str_eq(result2, str4);
  if (result2) free(result2);

  char str5[BUFF_SIZE] = " ";
  char str6[BUFF_SIZE] = " ";

  char *result3 = s21_to_upper(str5);
  ck_assert_str_eq(result3, str6);
  if (result3) free(result3);

  char str7[BUFF_SIZE] = "";
  char str8[BUFF_SIZE] = "";

  char *result4 = s21_to_upper(str7);
  ck_assert_str_eq(result4, str8);
  if (result4) free(result4);

  char str9[BUFF_SIZE] = "AAAA";
  char str10[BUFF_SIZE] = "AAAA";

  char *result6 = s21_to_upper(str9);
  ck_assert_str_eq(result6, str10);
  if (result6) free(result6);

  char str11[BUFF_SIZE] = "as Q213 123 345 !$&*";
  char str12[BUFF_SIZE] = "AS Q213 123 345 !$&*";

  char *result7 = s21_to_upper(str11);
  ck_assert_str_eq(result7, str12);
  if (result7) free(result7);

  char str13[BUFF_SIZE] = "s            q";
  char str14[BUFF_SIZE] = "S            Q";

  char *result8 = s21_to_upper(str13);
  ck_assert_str_eq(result8, str14);
  if (result8) free(result8);

  char str15[BUFF_SIZE] = "3 4 a m Q[ ,";
  char str16[BUFF_SIZE] = "3 4 A M Q[ ,";

  char *result9 = s21_to_upper(str15);
  ck_assert_str_eq(result9, str16);
  if (result9) free(result9);

  char str17[BUFF_SIZE] = "      'g";
  char str18[BUFF_SIZE] = "      'G";

  char *result10 = s21_to_upper(str17);
  ck_assert_str_eq(result10, str18);
  if (result10) free(result10);

  char str19[BUFF_SIZE] = "VCbv zaS";
  char str20[BUFF_SIZE] = "VCBV ZAS";

  char *result11 = s21_to_upper(str19);
  ck_assert_str_eq(result11, str20);
  if (result11) free(result11);

  char destination[BUFF_SIZE] = "Here w0 are123\0";
  char *test01 = s21_to_upper(destination);
  ck_assert_str_eq(test01, "HERE W0 ARE123");
  if (test01) free(test01);

  char destination2[BUFF_SIZE] = "Here w0 are\n\0";
  char *test02 = s21_to_upper(destination2);
  ck_assert_str_eq(test02, "HERE W0 ARE\n");
  if (test02) free(test02);

  char destination3[BUFF_SIZE] = "a\n\0";
  char *test03 = s21_to_upper(destination3);
  ck_assert_str_eq(test03, "A\n");
  if (test03) free(test03);

  char destination4[BUFF_SIZE] = " \n\0";
  char *test04 = s21_to_upper(destination4);
  ck_assert_str_eq(test04, " \n");
  if (test04) free(test04);

  char destination5[BUFF_SIZE] = " \0";
  char *test05 = s21_to_upper(destination5);
  ck_assert_str_eq(test05, " ");
  if (test05) free(test05);

  char destination6[BUFF_SIZE] = "\n\0";
  char *test06 = s21_to_upper(destination6);
  ck_assert_str_eq(test06, "\n");
  if (test06) free(test06);

  char destination7[BUFF_SIZE] = "\0";
  char *test07 = s21_to_upper(destination7);
  ck_assert_str_eq(test07, "");
  if (test07) free(test07);
}
END_TEST

// SPRINTF
START_TEST(sprintf_simple_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_precise_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_minus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_plus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_padding_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_star_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_star_precision_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_many_flags_many_ints) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char format[BUFF_SIZE] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_short_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_another_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_zero_precision_zero_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_space_flag_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_hash) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_one_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_two_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_one_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! Deathstl";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHADeathstlSUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_null_ptr) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *ptr = S21_NULL;
  char *format = "%p";
  int i1 = s21_sprintf(str1, format, ptr);
  int i2 = sprintf(str2, format, ptr);
  ck_assert_int_eq(i1, i2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_n_specifier) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret = 0;
  char *format = "Hello, my sexy little Deathstl abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.17Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_e_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.17LE";
  long double val = 4134121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_all_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_empty_format_and_parameters) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(sprintf_test_one_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(sprintf_test_one_hex_lower_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_lower_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(sprintf_test_one_hex_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(sprintf_test_one_hex_lower_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                   sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                   sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(sprintf_test_one_hex_lower_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
START_TEST(sprintf_test_one_hex_lower_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%+5.5d Deathstl";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Deathstl pupadupa"),
                   sprintf(str2, format, "Deathstl pupadupa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf12) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%-11.11li%-35.5lu%-3.5ld%33.19Lf";
  long double k = 333.33213;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf14) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf15) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "% 0.0hi% 0.0hu% 0.0hd % 0.0f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf16) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf17) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Deathstl likes pupadupa"),
                   sprintf(str2, format, "Deathstl likes pupadupa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf18) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf19) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf20) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf24) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf25) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf26) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf27) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[BUFF_SIZE] = "%%%%%%%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf28) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[BUFF_SIZE] = "%%%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf29) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf30) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf31) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%e";
  double x = 111;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf32) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%e%e%e%e";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf33) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%Le";
  long double x = 122.1231;

  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf35) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%.10e";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf36) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%5.3e%3.2e%lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
                   sprintf(str2, format, 0.000111, 111.555, 1.999));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf37) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf38) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%E%E%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                   sprintf(str2, format, 0.0000999, 111.9999, 6.666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf39) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%e Deathstl %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf40) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%#e pupadupa %#E%#f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf41) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%.Lf";
  long double a = 7.9418438184;

  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf42) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf43) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf44) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_trailing_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_g_exp) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%.2g";
  double hex = 501.6;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_g_large) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_small) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision_missing) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_many_zeroes_in_front) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_one_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_mantiss) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_mantiss_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%5.8g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_short_no_mantiss) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_LG) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[BUFF_SIZE] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// SCANF
START_TEST(sscanf_space) {
  char fstr[BUFF_SIZE] = "   %d";
  char str[BUFF_SIZE] = "        ";
  int16_t a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_EOF1) {
  char fstr[BUFF_SIZE] = "%d";
  char str[BUFF_SIZE] = "        ";
  int16_t a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_EOF2) {
  char fstr[BUFF_SIZE] = "%d ";
  char str[BUFF_SIZE] = "               ";
  int16_t a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_EOF3) {
  char fstr[BUFF_SIZE] = "%d ";
  char str[BUFF_SIZE] = "  ";
  int16_t a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, fstr, &a1);
  int res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_only_chars1) {
  char fstr[BUFF_SIZE] = "%c %c %c %c";
  char str[BUFF_SIZE] = "   a     b c d";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_chars2) {
  char fstr[BUFF_SIZE] = "%c%c%c%c";
  char str[BUFF_SIZE] = "abcd";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_chars3) {
  char fstr[BUFF_SIZE] = "%c %c %c      %c";
  char str[BUFF_SIZE] = "1 a 3   c           ";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_chars4) {
  char fstr[BUFF_SIZE] = "%c %c %c %c";
  char str[BUFF_SIZE] = "   000 0    ";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_chars5) {
  char fstr[BUFF_SIZE] = "%c %c %c %c";
  char str[BUFF_SIZE] = "tttt";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_special_symbols_as_chars1) {
  char fstr[BUFF_SIZE] = "%c%c%c%c";
  char str[BUFF_SIZE] = "\\\n\t\t\t";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_special_symbols_as_chars2) {
  char fstr[BUFF_SIZE] = "%c %c %c %c";
  char str[BUFF_SIZE] = "z ' ' /";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_special_symbols_as_chars3) {
  char fstr[BUFF_SIZE] = "%c%*c%c%c";
  char str[BUFF_SIZE] = "ABCD";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_chars_flags1) {
  char fstr[BUFF_SIZE] = "%c %c %c %c";
  char str[BUFF_SIZE] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_chars_flags2) {
  char fstr[BUFF_SIZE] = "%1c %c %c %0c";
  char str[BUFF_SIZE] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_chars_flags3) {
  char fstr[BUFF_SIZE] = "%c %c %c %c";
  char str[BUFF_SIZE] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_chars_flags4) {
  char fstr[BUFF_SIZE] = "%c %c %c %c";
  char str[BUFF_SIZE] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_chars_flags5) {
  char fstr[BUFF_SIZE] = "%*c%*c%*c%c";
  char str[BUFF_SIZE] = "abcde";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_chars_aster1) {
  char fstr[BUFF_SIZE] = "%*c%*c%*c%*c";
  char str[BUFF_SIZE] = "   c ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_chars_aster2) {
  char fstr[BUFF_SIZE] = "%*c%*c%*c%c";
  char str[BUFF_SIZE] = "abcd ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_only_ints1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char fstr[BUFF_SIZE] = "%ld %ld %ld %ld";
  const char str[BUFF_SIZE] = "555 666 777 888";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_ints2) {
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "1337 21 5008 3000";
  const char fstr[BUFF_SIZE] = "%hd %hd %hd %hd";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_ints3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "1337 21 5008 300004";
  const char fstr[BUFF_SIZE] = "%lld %lld %lld %lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ints_nwidth1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "1337 21 5008 300004";
  const char fstr[BUFF_SIZE] = "%1lld %3lld %1lld %4lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ints_nwidth2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "1337";
  const char fstr[BUFF_SIZE] = "%1lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ints_nwidth3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "100000000000000005";
  const char fstr[BUFF_SIZE] = "%3lld%lld%1lld%5lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ints_nwidth4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "1337";
  const char fstr[BUFF_SIZE] = "%15lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ints_astwidth1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  const char str[BUFF_SIZE] = "1337123123 1 123412341234 1 999999 0";
  const char fstr[BUFF_SIZE] = "%*d %lld %*d %lld %*d %lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_ints_astwidth2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "1337";
  const char fstr[BUFF_SIZE] = "%15lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ints_astwidth3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "1337";
  const char fstr[BUFF_SIZE] = "%15lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ints_astwidth4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "1337";
  const char fstr[BUFF_SIZE] = "%15lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_signed_ints1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "11337 ++3 -5 ------4";
  const char fstr[BUFF_SIZE] = "%lld %lld %lld %lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_signed_ints2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "-1337 +1 -1 -1";
  const char fstr[BUFF_SIZE] = "%15lld %1lld %1lld %5lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_signed_ints3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "-0 +0 +0 -0";
  const char fstr[BUFF_SIZE] = "%2lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_signed_ints4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "1 01 10 0";
  const char fstr[BUFF_SIZE] = "%lld %lld %lld %lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_int1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "300 500 -600 +700";
  const char fstr[BUFF_SIZE] = "%lli %lli %lli %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_int2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "300500-600+700 111";
  const char fstr[BUFF_SIZE] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_int3) {
  long long a1 = 0, a2 = 0, c1 = 0, c2 = 0;
  char b1 = 0, b2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "300500-600+700+400";
  const char fstr[BUFF_SIZE] = "%lli%c%lli%c";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_int4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "  55555 f f f5555555 ddd   4    3    1 ";
  const char fstr[BUFF_SIZE] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_hex1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "0xFFF 0xA123123 0x123123 0x0";
  const char fstr[BUFF_SIZE] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_hex2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = " 0xFFFF 0xf 0xf 0xf5555555 ddd   4    3    1 ";
  const char fstr[BUFF_SIZE] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_oct1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
  const char fstr[BUFF_SIZE] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_oct2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
  const char fstr[BUFF_SIZE] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

// [%s] //
START_TEST(sscanf_strings1) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[BUFF_SIZE] = "Deathstl pupadupa Keppa Shleppa Anuroba";
  const char fstr[BUFF_SIZE] = "%s %s %s %s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings_mixed3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[BUFF_SIZE] =
      "Deathstl 123 pupadupa -3 Keppa 4444Shleppa 333Anuroba 3";
  const char fstr[BUFF_SIZE] = "%s%ld%s%d%s%d%s";

  int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, &b1, s3, &c1, s4, &d1);
  int16_t res2 = s21_sscanf(str, fstr, s5, &a2, s6, &b2, s7, &c2, s8, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings2) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[BUFF_SIZE] = "Deathstl\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[BUFF_SIZE] = "%s%s%s%s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[BUFF_SIZE] =
      "Deathstl\tkepDeathstl pupadupa shleppa koooppa ap p p p p";
  const char fstr[BUFF_SIZE] = "%*s%*s%*s%*s";

  int16_t res1 = s21_sscanf(str, fstr);
  int16_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings4) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[BUFF_SIZE] = "Deathstl\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[BUFF_SIZE] = "%1s%1s%1s%1s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings5) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[BUFF_SIZE] = "Deathstl\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[BUFF_SIZE] = "%3s%3s%3s%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings6) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[BUFF_SIZE] = "Deathstl\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[BUFF_SIZE] = "%150s%1s%1s\t%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

// strings_mixed1
START_TEST(sscanf_strings_mixed1) {
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  long long d1 = 0, d2 = 0;
  long double e1 = 0, e2 = 0;

  const char str[BUFF_SIZE] =
      "4444444"
      "eeeeeee\teeeeeee";
  const char fstr[BUFF_SIZE] =
      "%5s %1s %*s %*s %llu %s %llu %llu %lld %Lf %33s";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};
  char s9[BUFF_SIZE] = {'\0'};
  char s10[BUFF_SIZE] = {'\0'};

  int16_t res1 = s21_sscanf(str, fstr, s7, s9, &a1, s5, &b1, &c1, &d1, &e1, s1);
  int16_t res2 = sscanf(str, fstr, s8, s10, &a2, s6, &b2, &c2, &d2, &e2, s2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_strings_mixed2) {
  int d1 = 0, d2 = 0, b1 = 0, b2 = 0, a1 = 0, a2 = 0;
  long long v1, v2;

  const char str[BUFF_SIZE] = "1 1 1 1 1 -1";
  const char fstr[BUFF_SIZE] = "%1s %5d %1s %1s %d %lld %d";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};

  int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, s3, &b1, &v1, &d1);
  int16_t res2 = sscanf(str, fstr, s4, &a2, s5, s6, &b2, &v2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

// [%n] //
START_TEST(sscanf_n1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int32_t n1 = 0, n2 = 5;

  const char str[BUFF_SIZE] = "50 160 70 80";
  const char fstr[BUFF_SIZE] = "%lli %lli %n %lli %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_n2) {
  int n1 = 1, n2 = 5;

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};

  const char str[BUFF_SIZE] =
      "cbobErobM fl? asdfasdflkasdf asdfasdf asdfasdf 88888";
  const char fstr[BUFF_SIZE] = "%s %s %n %s";

  int32_t res1 = s21_sscanf(str, fstr, s1, s2, &n1, s3);
  int32_t res2 = sscanf(str, fstr, s5, s6, &n2, s7);

  ck_assert_int_eq(res1, res2);

  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
}
END_TEST

START_TEST(sscanf_n3) {
  int n1 = 0, n2 = 5;

  const char str[BUFF_SIZE] = "50 60 70 80";
  const char fstr[BUFF_SIZE] = "%n";

  int16_t res1 = s21_sscanf(str, fstr, &n1);
  int16_t res2 = sscanf(str, fstr, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_n4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int32_t n1 = 0, n2 = 5;

  const char str[BUFF_SIZE] = "50 60 70 80";
  const char fstr[BUFF_SIZE] = "%lli %lli %n %lli %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_n5) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int n1 = 0, n2 = 5;

  const char str[BUFF_SIZE] = "50 60 70 80";
  const char fstr[BUFF_SIZE] = "%lli %lli %n %lli %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

// [%f] / [%g] / %[%G] //
START_TEST(sscanf_floats1) {
  long double a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0, d1 = 1, d2 = 0;

  const char str[BUFF_SIZE] = "53.1 -4.1135 41.3333 +2.0001";
  const char fstr[BUFF_SIZE] = "%Lf %Lf %Lf %Lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_floats2) {
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[BUFF_SIZE] = "0.00001 -4123123 4. .";
  const char fstr[BUFF_SIZE] = "%lf %lf %lf %lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_floats3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[BUFF_SIZE] = ". . . .";
  const char fstr[BUFF_SIZE] = "%f %f %f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_floats4) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[BUFF_SIZE] = "513.41 -4.14135 414.3333 +112.0001";
  const char fstr[BUFF_SIZE] = "%Lf %Lf %Lf %Lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_floats5) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  const char str[BUFF_SIZE] = "53.1 -4.1135 411231.333 +2.0001";
  const char fstr[BUFF_SIZE] = "%*f %f %f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_floats_sci1) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[BUFF_SIZE] = "1.4441 1.31e+4 -3.31e-4 0.444e-5";
  const char fstr[BUFF_SIZE] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_floats_sci2) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[BUFF_SIZE] = "inf 1.31e+4 NaN 0.444e-5";
  const char fstr[BUFF_SIZE] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(a1, a2);
  // Unfortunately, assertions for inf do not work correctly in libcheck
  // ck_assert_ldouble_infinite(a1);
  // ck_assert_ldouble_infinite(a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_float_nan(c1);
  ck_assert_float_nan(c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_floats_sci3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[BUFF_SIZE] = "inF InF inF INF";
  const char fstr[BUFF_SIZE] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_floats_sci4) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[BUFF_SIZE] = "Nan NAN 0.0000 0";
  const char fstr[BUFF_SIZE] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_float_nan(b1);
  ck_assert_float_nan(b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_floats_sci5) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[BUFF_SIZE] =
      "nAN           INF                   -0.1111         1e-10";
  const char fstr[BUFF_SIZE] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_ldouble_eq(b1, b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

// [%u] //
START_TEST(sscanf_uint1) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "-1337 +21 --5008 3000";
  const char fstr[BUFF_SIZE] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_uint_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_uint2) {
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                         d2 = 0;
  const char str[BUFF_SIZE] = "-1337 233333331 5008 3000";
  const char fstr[BUFF_SIZE] = "%1llu %2llu %5llu %4llu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_uint3) {
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  long long d1 = 0, d2 = 0;
  long double v1, v2;

  const char str[BUFF_SIZE] =
      "\t\t\t\t\t\n 3      adsfdfa%$$$$`adfasdfasdfaszcvzcxvcv -1337 "
      "anurobich+ 21 -5008 -33000 0.3333";
  const char fstr[BUFF_SIZE] = "%*s %*s %llu %s %llu %llu %lld %Lf";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};

  int16_t res1 = s21_sscanf(str, fstr, &a1, s1, &b1, &c1, &d1, &v1);
  int16_t res2 = sscanf(str, fstr, &a2, s2, &b2, &c2, &d2, &v2);

  ck_assert_uint_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_ldouble_eq_tol(v1, v2, 0.0001);
}
END_TEST

START_TEST(sscanf_uint4) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "-1337 +21 --5008 3000";
  const char fstr[BUFF_SIZE] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_uint5) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "-1337 +21 --5008 3000";
  const char fstr[BUFF_SIZE] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_uint6) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[BUFF_SIZE] = "-1337 +21 --5008 3000";
  const char fstr[BUFF_SIZE] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_upeer_hex_base_version) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "F";
  const char fstr[BUFF_SIZE] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_overflow) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "0xFFFFFFFF";
  const char fstr[BUFF_SIZE] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_0x) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "0x";
  const char fstr[BUFF_SIZE] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_0X) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "0X";
  const char fstr[BUFF_SIZE] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_empty) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "";
  const char fstr[BUFF_SIZE] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_upeer_hex_fail) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "qF";
  const char fstr[BUFF_SIZE] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_upeer_hex_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "          \n             \n     F";
  const char fstr[BUFF_SIZE] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_short) {
  uint16_t a1, a2;
  const char str[BUFF_SIZE] = "F";
  const char fstr[BUFF_SIZE] = "%hX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_long) {
  unsigned long int a1, a2;
  const char str[BUFF_SIZE] = "F";
  const char fstr[BUFF_SIZE] = "%lX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_longlong) {
  unsigned long long int a1, a2;
  const char str[BUFF_SIZE] = "F";
  const char fstr[BUFF_SIZE] = "%llX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_2x) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[BUFF_SIZE] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_star) {
  const char str[BUFF_SIZE] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[BUFF_SIZE] = "%*X";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_upeer_hex_nohex) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "tqwqpl";
  const char fstr[BUFF_SIZE] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_upeer_hex_lower) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "abcdef";
  const char fstr[BUFF_SIZE] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_sign) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "-f";
  const char fstr[BUFF_SIZE] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_base_version) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "f";
  const char fstr[BUFF_SIZE] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_overflow) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "0xfffffffffffffffffff";
  const char fstr[BUFF_SIZE] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_0x) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "0x";
  const char fstr[BUFF_SIZE] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_0X) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "0X";
  const char fstr[BUFF_SIZE] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_empty) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "";
  const char fstr[BUFF_SIZE] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_lower_hex_fail) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "qF";
  const char fstr[BUFF_SIZE] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_lower_hex_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "          \n             \n     F";
  const char fstr[BUFF_SIZE] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_short) {
  uint16_t a1, a2;
  const char str[BUFF_SIZE] = "ff";
  const char fstr[BUFF_SIZE] = "%hx";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_long) {
  unsigned long int a1, a2;
  const char str[BUFF_SIZE] = "ff";
  const char fstr[BUFF_SIZE] = "%lx";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_longlong) {
  unsigned long long int a1, a2;
  const char str[BUFF_SIZE] = "faaaaaaaaaaaaf";
  const char fstr[BUFF_SIZE] = "%llx";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  // ck_assert_unsigned long long int_eq(a1, a2);
  // ck_assert_uint64_eq(a1, a2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_2x) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[BUFF_SIZE] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_star) {
  const char str[BUFF_SIZE] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[BUFF_SIZE] = "%*x";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_lower_hex_nohex) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "tqwqpl";
  const char fstr[BUFF_SIZE] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_lower_hex_lower) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "abcdef";
  const char fstr[BUFF_SIZE] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_sign) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "-f";
  const char fstr[BUFF_SIZE] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upper_hex_len) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "123531FFF";
  const char fstr[BUFF_SIZE] = "%2X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_len) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "123531FFF";
  const char fstr[BUFF_SIZE] = "%2x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_base_version) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "777";
  const char fstr[BUFF_SIZE] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_overflow) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "0x7777777777777777777777";
  const char fstr[BUFF_SIZE] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_0x) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "0x";
  const char fstr[BUFF_SIZE] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_0X) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "0X";
  const char fstr[BUFF_SIZE] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_empty) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "";
  const char fstr[BUFF_SIZE] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_octal_fail) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "q1";
  const char fstr[BUFF_SIZE] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_octal_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "          \n             \n     5";
  const char fstr[BUFF_SIZE] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_short) {
  uint16_t a1, a2;
  const char str[BUFF_SIZE] = "12";
  const char fstr[BUFF_SIZE] = "%ho";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_long) {
  unsigned long int a1, a2;
  const char str[BUFF_SIZE] = "57234";
  const char fstr[BUFF_SIZE] = "%lo";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_longlong) {
  unsigned long long int a1, a2;
  const char str[BUFF_SIZE] = "12356226137";
  const char fstr[BUFF_SIZE] = "%llo";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_2x) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "0x12320x213x123213";
  const char fstr[BUFF_SIZE] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_star) {
  const char str[BUFF_SIZE] = "521561612";
  const char fstr[BUFF_SIZE] = "%*o";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_octal_nohex) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "tqwqpl";
  const char fstr[BUFF_SIZE] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_octal_lower) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "01234567";
  const char fstr[BUFF_SIZE] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_sign) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "-66";
  const char fstr[BUFF_SIZE] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_len) {
  uint32_t a1, a2;
  const char str[BUFF_SIZE] = "123531";
  const char fstr[BUFF_SIZE] = "%2o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_buff1) {
  int32_t a1, a2;
  int32_t b1, b2;
  const char str[BUFF_SIZE] = "12 helga 12";
  const char fstr[BUFF_SIZE] = "%d helga %d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(sscanf_buff2) {
  int32_t a1, a2;
  int32_t b1, b2;
  const char str[BUFF_SIZE] = "12helga12";
  const char fstr[BUFF_SIZE] = "%dhelga%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(sscanf_pointer1) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[BUFF_SIZE] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[BUFF_SIZE] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_pointer2) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[BUFF_SIZE] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[BUFF_SIZE] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_pointer3) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[BUFF_SIZE] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[BUFF_SIZE] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_pointer4) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[BUFF_SIZE] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[BUFF_SIZE] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hard1) {
  int a1 = 0, a2 = 5, a3 = 3, a4 = 9;
  int32_t n1 = 500, n2 = 10000;

  const char str[BUFF_SIZE] = "123123AKUKARACHA!!!!123";
  const char fstr[BUFF_SIZE] = "%dAKUKARACHA!!!!%d %n";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &a3, &n1);
  int16_t res2 = sscanf(str, fstr, &a2, &a4, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a3, a4);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_buff3) {
  int32_t a1, a2;
  int32_t b1 = 0, b2 = 0;
  const char str[BUFF_SIZE] = "12barba12";
  const char fstr[BUFF_SIZE] = "%dbarbados%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(sscanf_perc1) {
  int32_t a1, a2;
  int32_t b1 = 80, b2 = 33;
  int32_t c1 = 55, c2 = 33;
  const char str[BUFF_SIZE] = "12 % 13 % 14";
  const char fstr[BUFF_SIZE] = "%d %% %d %% %d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_perc2) {
  int32_t a1, a2;
  int32_t b1 = 80, b2 = 33;
  int32_t c1 = 55, c2 = 33;
  const char str[BUFF_SIZE] = "12%13%14";
  const char fstr[BUFF_SIZE] = "%d%%%d%%%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_perc3) {
  int32_t a1 = 1234, a2 = 33333;

  const char str[BUFF_SIZE] = "%%%16";
  const char fstr[BUFF_SIZE] = "%%%%%%%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1);
  int32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_perc4) {
  const char str[BUFF_SIZE] = "%%%";
  const char fstr[BUFF_SIZE] = "%%%%%%";
  int32_t res1 = s21_sscanf(str, fstr);
  int32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_perc5) {
  int32_t a1 = 1234, a2 = 33333;
  int32_t b1 = 1234, b2 = 33333;

  const char str[BUFF_SIZE] = "%%123%888";
  const char fstr[BUFF_SIZE] = "%%%%%d%%%d";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(sscanf_mixed_ptrs1) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char str[BUFF_SIZE] = "0xFFFF 0xAAA 7123 0xBBC1FF";
  const char fstr[BUFF_SIZE] = "%p %p %p %p";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_mixed_ptrs2) {
  char *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char str[BUFF_SIZE] = "0x4 0x3 0x2 0x1";
  const char fstr[BUFF_SIZE] = "%p %p %p %p";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_mixed_ptrs3) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char str[BUFF_SIZE] = "03033 0333 0123 0123 0x123 0xFFFFF 0xBBC1FF";
  const char fstr[BUFF_SIZE] = "%p %p %p %p";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_mixed_ptrs4) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char str[BUFF_SIZE] = "0xABCDEF 0xAAA 7123 0xBBC1FF";
  const char fstr[BUFF_SIZE] = "%p %p %p %p";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_mixed_ptrs5) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char str[BUFF_SIZE] = "NULL";
  const char fstr[BUFF_SIZE] = "%p %p %p %p";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hard3) {
  char a1, a2;
  char b1[BUFF_SIZE] = {'\0'};
  char b2[BUFF_SIZE] = {'\0'};
  float c1, c2;
  short int d1, d2;
  long long int e1, e2;

  const char str[BUFF_SIZE] =
      "$AmIIn%%sane? %\n\n\n \n \n \n\t   InF 0 %FIN9D-ME%";
  const char fstr[BUFF_SIZE] = "%c%5s%%%*s %%  %G %hi %%FIN%lldDME%%";

  int32_t res1 = s21_sscanf(str, fstr, &a1, b1, &c1, &d1, &e1);
  int32_t res2 = sscanf(str, fstr, &a2, b2, &c2, &d2, &e2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_str_eq(b1, b2);
  ck_assert_float_infinite(c1);
  ck_assert_float_infinite(c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(e1, e2);
}
END_TEST

START_TEST(sscanf_hard4) {
  char a1, a2;
  char b1, b2;
  char c1, c2;
  char d1, d2;

  const char str[BUFF_SIZE] = "%%$Char!StressssT%%estus!&&&";
  const char fstr[BUFF_SIZE] = "%% %*c%*c%*c%*c%*c %c %c %c %c ### %*c";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_hard5) {
  char a1, a2;
  char b1, b2;
  char c1, c2;
  char d1, d2;
  const char str[BUFF_SIZE] =
      "%%$Char!StressssVIm User Deathstl %% %%% %%% %% % % %% % "
      "% % %% % % %% %T%%estus!%%&&&";
  const char fstr[BUFF_SIZE] =
      "%% %*c%*c%*c%*c%*c %c %c %c %c %% %% %% %% %% %% %% "
      "%% %% %% %% %% %% %% %% %% ### %*c";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

/* -----===== PART-2 =====----- */
/* -----===== FINISH =====----- */

int main() {
  int number_failed;
  Suite *s = suite_create("s21_string");
  TCase *tc = tcase_create("Core");
  SRunner *sr = srunner_create(s);
  tcase_add_test(tc, sprintf_simple_int);
  tcase_add_test(tc, sprintf_precise_int);
  tcase_add_test(tc, sprintf_width_int);
  tcase_add_test(tc, sprintf_minus_width_int);
  tcase_add_test(tc, sprintf_plus_width_int);
  tcase_add_test(tc, sprintf_padding_int);
  tcase_add_test(tc, sprintf_star_width_int);
  tcase_add_test(tc, sprintf_star_precision_int);
  tcase_add_test(tc, sprintf_many_flags_many_ints);
  tcase_add_test(tc, sprintf_flags_long_int);
  tcase_add_test(tc, sprintf_flags_short_int);
  tcase_add_test(tc, sprintf_flags_another_long_int);
  tcase_add_test(tc, sprintf_zero_precision_zero_int);
  tcase_add_test(tc, sprintf_space_flag_int);
  tcase_add_test(tc, sprintf_unsigned_val);
  tcase_add_test(tc, sprintf_unsigned_val_width);
  tcase_add_test(tc, sprintf_unsigned_val_flags);
  tcase_add_test(tc, sprintf_unsigned_val_precision);
  tcase_add_test(tc, sprintf_unsigned_val_many_flags);
  tcase_add_test(tc, sprintf_unsigned_val_short);
  tcase_add_test(tc, sprintf_unsigned_val_long);
  tcase_add_test(tc, sprintf_unsigned_val_many);
  tcase_add_test(tc, sprintf_octal_width);
  tcase_add_test(tc, sprintf_octal_flags);
  tcase_add_test(tc, sprintf_octal_precision);
  tcase_add_test(tc, sprintf_octal_many_flags);
  tcase_add_test(tc, sprintf_octal_short);
  tcase_add_test(tc, sprintf_octal_long);
  tcase_add_test(tc, sprintf_octal_many);
  tcase_add_test(tc, sprintf_octal);
  tcase_add_test(tc, sprintf_octal_zero);
  tcase_add_test(tc, sprintf_octal_hash);
  tcase_add_test(tc, sprintf_unsigned_zero);
  tcase_add_test(tc, sprintf_hex_width);
  tcase_add_test(tc, sprintf_hex_flags);
  tcase_add_test(tc, sprintf_hex_precision);
  tcase_add_test(tc, sprintf_hex_many);
  tcase_add_test(tc, sprintf_hex_many_flags);
  tcase_add_test(tc, sprintf_hex_zero);
  tcase_add_test(tc, sprintf_hex_huge);
  tcase_add_test(tc, sprintf_hex_short);
  tcase_add_test(tc, sprintf_hex_long);
  tcase_add_test(tc, sprintf_hex_one_longer_width);
  tcase_add_test(tc, sprintf_hex_two_longer_width);
  tcase_add_test(tc, sprintf_one_char);
  tcase_add_test(tc, sprintf_one_precision);
  tcase_add_test(tc, sprintf_one_flags);
  tcase_add_test(tc, sprintf_one_width);
  tcase_add_test(tc, sprintf_one_many);
  tcase_add_test(tc, sprintf_one_many_flags);
  tcase_add_test(tc, sprintf_string);
  tcase_add_test(tc, sprintf_string_precision);
  tcase_add_test(tc, sprintf_string_width);
  tcase_add_test(tc, sprintf_string_flags);
  tcase_add_test(tc, sprintf_string_long);
  tcase_add_test(tc, sprintf_string_many);
  tcase_add_test(tc, sprintf_ptr);
  tcase_add_test(tc, sprintf_ptr_width);
  tcase_add_test(tc, sprintf_ptr_precision);
  tcase_add_test(tc, sprintf_null_ptr);
  tcase_add_test(tc, sprintf_n_specifier);
  tcase_add_test(tc, sprintf_string_width_huge);
  tcase_add_test(tc, sprintf_float_precision);
  tcase_add_test(tc, sprintf_float_width);
  tcase_add_test(tc, sprintf_float_precision_zero);
  tcase_add_test(tc, sprintf_float_precision_empty);
  tcase_add_test(tc, sprintf_float_precision_huge);
  tcase_add_test(tc, sprintf_float_precision_huge_negative);
  tcase_add_test(tc, sprintf_float_huge);
  tcase_add_test(tc, sprintf_float_flags);
  tcase_add_test(tc, sprintf_float_many);
  tcase_add_test(tc, sprintf_e_precision);
  tcase_add_test(tc, sprintf_e_precision_zero);
  tcase_add_test(tc, sprintf_e_precision_empty);
  tcase_add_test(tc, sprintf_e_precision_huge);
  tcase_add_test(tc, sprintf_e_precision_huge_negative);
  tcase_add_test(tc, sprintf_e_huge);
  tcase_add_test(tc, sprintf_e_many);
  tcase_add_test(tc, sprintf_e_width);
  tcase_add_test(tc, sprintf_e_flags);
  tcase_add_test(tc, sprintf_E_int);
  tcase_add_test(tc, sprintf_all_empty);
  tcase_add_test(tc, sprintf_empty_format_and_parameters);
  tcase_add_test(tc, sprintf_test_one_char);
  tcase_add_test(tc, sprintf_test_many_char);
  tcase_add_test(tc, sprintf_test_one_string);
  tcase_add_test(tc, sprintf_test_many_string);
  tcase_add_test(tc, sprintf_test_one_dec);
  tcase_add_test(tc, sprintf_test_many_dec);
  tcase_add_test(tc, sprintf_test_one_int);
  tcase_add_test(tc, sprintf_test_many_int);
  tcase_add_test(tc, sprintf_test_one_float);
  tcase_add_test(tc, sprintf_test_many_float);
  tcase_add_test(tc, sprintf_test_one_unsigned_dec);
  tcase_add_test(tc, sprintf_test_many_unsigned_dec);
  tcase_add_test(tc, sprintf_test_one_char_with_alignment_left);
  tcase_add_test(tc, sprintf_test_one_char_with_alignment_right);
  tcase_add_test(tc, sprintf_test_many_char_with_alignment);
  tcase_add_test(tc, sprintf_test_one_hex_lower);
  tcase_add_test(tc, sprintf_test_one_hex_upper);
  tcase_add_test(tc, sprintf_test_many_hex_lower);
  tcase_add_test(tc, sprintf_test_many_hex_upper);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_alignment_left);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_alignment_right);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_alignment_left);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_alignment_right);
  tcase_add_test(tc, sprintf_test_many_hex_lower_with_alignment);
  tcase_add_test(tc, sprintf_test_many_hex_upper_with_alignment);
  tcase_add_test(tc, sprintf_test_one_hex_with_hashtag);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_hashtag);
  tcase_add_test(tc, sprintf_test_many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(tc, sprintf_test_many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_width_star);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_width_star);
  tcase_add_test(
      tc, sprintf_test_many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(tc, sprintf_test_many_hex_upper_with_width_star);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_precision);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_precision);
  tcase_add_test(tc, sprintf_test_many_hex_lower_with_precision_and_other);
  tcase_add_test(tc, sprintf_test_many_hex_upper_with_precision_and_other);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_length);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_length);
  tcase_add_test(tc, sprintf_test_sprintf1);
  tcase_add_test(tc, sprintf_test_sprintf2);
  tcase_add_test(tc, sprintf_test_sprintf3);
  tcase_add_test(tc, sprintf_test_sprintf4);
  tcase_add_test(tc, sprintf_test_sprintf6);
  tcase_add_test(tc, sprintf_test_sprintf7);
  tcase_add_test(tc, sprintf_test_sprintf8);
  tcase_add_test(tc, sprintf_test_sprintf9);
  tcase_add_test(tc, sprintf_test_sprintf10);
  tcase_add_test(tc, sprintf_test_sprintf11);
  tcase_add_test(tc, sprintf_test_sprintf12);
  tcase_add_test(tc, sprintf_test_sprintf14);
  tcase_add_test(tc, sprintf_test_sprintf15);
  tcase_add_test(tc, sprintf_test_sprintf16);
  tcase_add_test(tc, sprintf_test_sprintf17);
  tcase_add_test(tc, sprintf_test_sprintf18);
  tcase_add_test(tc, sprintf_test_sprintf19);
  tcase_add_test(tc, sprintf_test_sprintf20);
  tcase_add_test(tc, sprintf_test_sprintf24);
  tcase_add_test(tc, sprintf_test_sprintf25);
  tcase_add_test(tc, sprintf_test_sprintf28);
  tcase_add_test(tc, sprintf_test_sprintf29);
  tcase_add_test(tc, sprintf_test_sprintf30);
  tcase_add_test(tc, sprintf_test_sprintf31);
  tcase_add_test(tc, sprintf_test_sprintf43);
  tcase_add_test(tc, sprintf_test_sprintf44);
  tcase_add_test(tc, sprintf_test_sprintf26);
  tcase_add_test(tc, sprintf_test_sprintf27);
  tcase_add_test(tc, sprintf_g_trailing_zero);
  tcase_add_test(tc, sprintf_g_large);
  tcase_add_test(tc, sprintf_g_exp);
  tcase_add_test(tc, sprintf_g_small);
  tcase_add_test(tc, sprintf_g_precision);
  tcase_add_test(tc, sprintf_g_precision_zero);
  tcase_add_test(tc, sprintf_g_precision_missing);
  tcase_add_test(tc, sprintf_g_many_zeroes_in_front);
  tcase_add_test(tc, sprintf_g_one_zero);
  tcase_add_test(tc, sprintf_g_mantiss);
  tcase_add_test(tc, sprintf_g_mantiss_flags);
  tcase_add_test(tc, sprintf_g_short_no_mantiss);
  tcase_add_test(tc, sprintf_LG);
  tcase_add_test(tc, sprintf_g_many);
  tcase_add_test(tc, sprintf_g_zero);
  tcase_add_test(tc, sprintf_test_sprintf42);
  tcase_add_test(tc, sprintf_test_sprintf41);
  tcase_add_test(tc, sprintf_test_sprintf40);
  tcase_add_test(tc, sprintf_test_sprintf39);
  tcase_add_test(tc, sprintf_test_sprintf38);
  tcase_add_test(tc, sprintf_test_sprintf37);
  tcase_add_test(tc, sprintf_test_sprintf36);
  tcase_add_test(tc, sprintf_test_sprintf35);
  tcase_add_test(tc, sprintf_test_sprintf33);
  tcase_add_test(tc, sprintf_test_sprintf32);

  // SSCANF
  tcase_add_test(tc, sscanf_space);
  tcase_add_test(tc, sscanf_EOF1);
  tcase_add_test(tc, sscanf_EOF2);
  tcase_add_test(tc, sscanf_EOF3);
  tcase_add_test(tc, sscanf_only_chars2);
  tcase_add_test(tc, sscanf_special_symbols_as_chars1);
  tcase_add_test(tc, sscanf_only_ints1);
  tcase_add_test(tc, sscanf_only_ints2);
  tcase_add_test(tc, sscanf_only_ints3);
  tcase_add_test(tc, sscanf_ints_nwidth1);
  tcase_add_test(tc, sscanf_ints_nwidth2);
  tcase_add_test(tc, sscanf_ints_nwidth3);
  tcase_add_test(tc, sscanf_ints_nwidth4);
  tcase_add_test(tc, sscanf_ints_astwidth1);
  tcase_add_test(tc, sscanf_ints_astwidth2);
  tcase_add_test(tc, sscanf_ints_astwidth3);
  tcase_add_test(tc, sscanf_ints_astwidth4);
  tcase_add_test(tc, sscanf_signed_ints2);
  tcase_add_test(tc, sscanf_signed_ints3);
  tcase_add_test(tc, sscanf_signed_ints4);
  tcase_add_test(tc, sscanf_spec_i_int1);
  tcase_add_test(tc, sscanf_spec_i_int2);
  tcase_add_test(tc, sscanf_spec_i_int3);
  tcase_add_test(tc, sscanf_spec_i_int4);
  tcase_add_test(tc, sscanf_spec_i_oct1);
  tcase_add_test(tc, sscanf_spec_i_oct2);
  tcase_add_test(tc, sscanf_spec_i_hex1);
  tcase_add_test(tc, sscanf_spec_i_hex2);
  tcase_add_test(tc, sscanf_strings1);
  tcase_add_test(tc, sscanf_strings4);
  tcase_add_test(tc, sscanf_strings_mixed1);
  tcase_add_test(tc, sscanf_strings_mixed2);
  tcase_add_test(tc, sscanf_strings_mixed3);
  tcase_add_test(tc, sscanf_floats1);
  tcase_add_test(tc, sscanf_floats2);
  tcase_add_test(tc, sscanf_floats4);
  tcase_add_test(tc, sscanf_floats5);
  tcase_add_test(tc, sscanf_floats_sci1);
  tcase_add_test(tc, sscanf_upeer_hex_base_version);
  tcase_add_test(tc, sscanf_upeer_hex_overflow);
  tcase_add_test(tc, sscanf_upeer_hex_empty);
  tcase_add_test(tc, sscanf_upeer_hex_short);
  tcase_add_test(tc, sscanf_upeer_hex_long);
  tcase_add_test(tc, sscanf_upeer_hex_longlong);
  tcase_add_test(tc, sscanf_upeer_hex_lower);
  tcase_add_test(tc, sscanf_upeer_hex_sign);
  tcase_add_test(tc, upper_hex_len);
  tcase_add_test(tc, sscanf_lower_hex_base_version);
  tcase_add_test(tc, sscanf_lower_hex_empty);
  tcase_add_test(tc, sscanf_lower_hex_short);
  tcase_add_test(tc, sscanf_lower_hex_long);
  tcase_add_test(tc, sscanf_lower_hex_lower);
  tcase_add_test(tc, sscanf_lower_hex_sign);
  tcase_add_test(tc, sscanf_lower_hex_len);
  tcase_add_test(tc, sscanf_octal_base_version);
  tcase_add_test(tc, sscanf_octal_overflow);
  tcase_add_test(tc, sscanf_octal_0x);
  tcase_add_test(tc, sscanf_octal_0X);
  tcase_add_test(tc, sscanf_octal_empty);
  tcase_add_test(tc, sscanf_octal_short);
  tcase_add_test(tc, sscanf_octal_long);
  tcase_add_test(tc, sscanf_octal_longlong);
  tcase_add_test(tc, sscanf_octal_2x);
  tcase_add_test(tc, sscanf_octal_lower);
  tcase_add_test(tc, sscanf_octal_sign);
  tcase_add_test(tc, sscanf_octal_len);
  tcase_add_test(tc, sscanf_pointer1);
  tcase_add_test(tc, sscanf_pointer2);
  tcase_add_test(tc, sscanf_pointer3);
  tcase_add_test(tc, sscanf_pointer4);
  tcase_add_test(tc, sscanf_buff3);
  tcase_add_test(tc, sscanf_mixed_ptrs1);
  tcase_add_test(tc, sscanf_mixed_ptrs2);
  tcase_add_test(tc, sscanf_mixed_ptrs3);
  tcase_add_test(tc, sscanf_mixed_ptrs4);
  tcase_add_test(tc, sscanf_hard5);
  tcase_add_test(tc, sscanf_hard4);
  tcase_add_test(tc, sscanf_hard3);
  tcase_add_test(tc, sscanf_mixed_ptrs5);
  tcase_add_test(tc, sscanf_perc5);
  tcase_add_test(tc, sscanf_perc4);
  tcase_add_test(tc, sscanf_perc3);
  tcase_add_test(tc, sscanf_perc2);
  tcase_add_test(tc, sscanf_perc1);
  tcase_add_test(tc, sscanf_hard1);
  tcase_add_test(tc, sscanf_buff2);
  tcase_add_test(tc, sscanf_buff1);
  tcase_add_test(tc, sscanf_octal_nohex);
  tcase_add_test(tc, sscanf_octal_star);
  tcase_add_test(tc, sscanf_octal_spaces_tabs_sns);
  tcase_add_test(tc, sscanf_octal_fail);
  tcase_add_test(tc, sscanf_lower_hex_nohex);
  tcase_add_test(tc, sscanf_lower_hex_2x);
  tcase_add_test(tc, sscanf_lower_hex_star);
  tcase_add_test(tc, sscanf_lower_hex_longlong);
  tcase_add_test(tc, sscanf_lower_hex_spaces_tabs_sns);
  tcase_add_test(tc, sscanf_lower_hex_fail);
  tcase_add_test(tc, sscanf_lower_hex_0X);
  tcase_add_test(tc, sscanf_lower_hex_0x);
  tcase_add_test(tc, sscanf_lower_hex_overflow);
  tcase_add_test(tc, sscanf_upeer_hex_nohex);
  tcase_add_test(tc, sscanf_upeer_hex_star);
  tcase_add_test(tc, sscanf_upeer_hex_2x);
  tcase_add_test(tc, sscanf_upeer_hex_spaces_tabs_sns);
  tcase_add_test(tc, sscanf_upeer_hex_fail);
  tcase_add_test(tc, sscanf_upeer_hex_0X);
  tcase_add_test(tc, sscanf_upeer_hex_0x);
  tcase_add_test(tc, sscanf_uint6);
  tcase_add_test(tc, sscanf_uint5);
  tcase_add_test(tc, sscanf_uint4);
  tcase_add_test(tc, sscanf_uint3);
  tcase_add_test(tc, sscanf_uint2);
  tcase_add_test(tc, sscanf_uint1);
  tcase_add_test(tc, sscanf_floats_sci5);
  tcase_add_test(tc, sscanf_floats_sci4);
  tcase_add_test(tc, sscanf_floats_sci3);
  tcase_add_test(tc, sscanf_floats_sci2);
  tcase_add_test(tc, sscanf_floats3);
  tcase_add_test(tc, sscanf_n5);
  tcase_add_test(tc, sscanf_n4);
  tcase_add_test(tc, sscanf_n3);
  tcase_add_test(tc, sscanf_n2);
  tcase_add_test(tc, sscanf_n1);
  tcase_add_test(tc, sscanf_strings6);
  tcase_add_test(tc, sscanf_strings5);
  tcase_add_test(tc, sscanf_strings3);
  tcase_add_test(tc, sscanf_strings2);
  tcase_add_test(tc, sscanf_signed_ints1);
  tcase_add_test(tc, sscanf_chars_aster2);
  tcase_add_test(tc, sscanf_chars_aster1);
  tcase_add_test(tc, sscanf_chars_flags5);
  tcase_add_test(tc, sscanf_chars_flags4);
  tcase_add_test(tc, sscanf_chars_flags3);
  tcase_add_test(tc, sscanf_chars_flags2);
  tcase_add_test(tc, sscanf_chars_flags1);
  tcase_add_test(tc, sscanf_special_symbols_as_chars3);
  tcase_add_test(tc, sscanf_special_symbols_as_chars2);
  tcase_add_test(tc, sscanf_only_chars5);
  tcase_add_test(tc, sscanf_only_chars4);
  tcase_add_test(tc, sscanf_only_chars3);
  tcase_add_test(tc, sscanf_only_chars1);

  // MAIN FUNCTIONS
  tcase_add_test(tc, s21_my_itoa_my);
  tcase_add_test(tc, s21_atoi_my);
  tcase_add_test(tc, s21_memchr_my);
  tcase_add_test(tc, s21_memcmp_my);
  tcase_add_test(tc, s21_memcpy_my);
  tcase_add_test(tc, s21_memmove_my);
  tcase_add_test(tc, s21_memset_my);
  tcase_add_test(tc, s21_strchr_my);
  tcase_add_test(tc, s21_strcmp_my);
  tcase_add_test(tc, s21_strerror_my);
  tcase_add_test(tc, s21_strlen_my);
  tcase_add_test(tc, s21_strcat_my);
  tcase_add_test(tc, s21_strlen_my);
  tcase_add_test(tc, s21_strspn_my);
  tcase_add_test(tc, s21_strpbrk_my);
  tcase_add_test(tc, s21_trim_my);
  tcase_add_test(tc, s21_strncat_test);
  tcase_add_test(tc, s21_strncmp_test);
  tcase_add_test(tc, s21_strrchr_test);
  tcase_add_test(tc, s21_to_lower_test);
  tcase_add_test(tc, s21_to_upper_test);
  tcase_add_test(tc, s21_strtok_my);
  tcase_add_test(tc, s21_strcspn_my);
  tcase_add_test(tc, s21_strncpy_my);
  tcase_add_test(tc, s21_strcpy_my);
  tcase_add_test(tc, s21_strstr_my);
  tcase_add_test(tc, s21_insert_my);
  suite_add_tcase(s, tc);
  srunner_set_log(sr, "test.log");
  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
