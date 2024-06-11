#include <check.h>
#include "s21_string.h"

START_TEST(S21_MEMCHR) {
  char str1[] = "abc\nabc";
  int a = 'a';
  size_t n1 = 3;
  ck_assert_ptr_eq(memchr(str1, a, n1), s21_memchr(str1, a, n1));

  char str2[] = "abcabc";
  int b = 'a';
  size_t n2 = 0;
  ck_assert_ptr_eq(memchr(str2, b, n2), s21_memchr(str2, b, n2));

  char str3[] = "abcabc";
  int c = 'a';
  size_t n3 = 0;
  ck_assert_ptr_eq(memchr(str3, c, n3), s21_memchr(str3, c, n3));

  char str4[] = "";
  int c1 = '\0';
  size_t n4 = 4;
  ck_assert_ptr_eq(memchr(str4, c1, n4), s21_memchr(str4, c1, n4));
}
END_TEST

START_TEST(S21_MEMCMP) {
  ck_assert_int_eq(s21_memcmp("", "", 0), memcmp("", "", 0));
  ck_assert_msg(s21_memcmp("", "", 0) == memcmp("", "", 0),
                "FAILURE! Test \'\' in \'\' failed!");
  ck_assert_msg(s21_memcmp("abc", "abc", 3) == memcmp("abc", "abc", 3),
                "FAILURE! Test ");
  ck_assert_msg(s21_memcmp("abcd", "abcd", 4) == memcmp("abcd", "abcd", 4),
                "FAILURE! Test ");
  ck_assert_msg(s21_memcmp("cba", "cba", 3) == memcmp("cba", "cba", 3),
                "FAILURE! Test ");
  ck_assert_msg(s21_memcmp("tall", "small", 4) == memcmp("tal", "small", 4),
                "FAILURE! ");
  ck_assert_msg(s21_memcmp("small", "tall", 4) == memcmp("small", "tall", 4),
                "FAILURE!");
  char *a = "at";
  char *b = "atb";
  int result = memcmp(a, b, 2);
  result = result > 0 ? 1 : (result == 0) ? 0 : -1;
  ck_assert_msg(s21_memcmp(a, b, 2) == result,
                "FAILURE! Test \"at\" in \"atb\" failed!");
  result = memcmp(b, a, 2);
  result = result > 0 ? 1 : (result == 0) ? 0 : -1;
  ck_assert_msg(s21_memcmp(b, a, 2) == result,
                "FAILURE! Test \"atb\" in \"at\" failed!");
}
END_TEST

START_TEST(S21_MEMCPY) {
  char dest[100];
  ck_assert_msg(
      memcmp(s21_memcpy(dest, "abc", 3), memcpy(dest, "abc", 3), 99) == 0,
      "FAILURE! Test ");
  ck_assert_msg(
      memcmp(s21_memcpy(dest, "aac", 1), memcpy(dest, "aac", 1), 99) == 0,
      "FAILURE! Test ");
  ck_assert_msg(memcmp(s21_memcpy(dest, "", 0), memcpy(dest, "", 0), 99) == 0,
                "FAILURE! Test \'\' ");
  ck_assert_msg(memcmp(s21_memcpy(dest, "11111111111", 10),
                       memcpy(dest, "11111111111", 10), 99) == 0,
                "F");
}
END_TEST

START_TEST(S21_STRLEN) {
  ck_assert_msg(s21_strlen("") == strlen(""), "FAILURE! Tes \"\" failed!");
  ck_assert_msg(s21_strlen("abc") == strlen("abc"),
                "FAILURE! Test \"abc\" failed!");
  ck_assert_msg(s21_strlen("123 ") == strlen("123 "),
                "FAILURE! Test \"123 \" failed!");
  ck_assert_msg(s21_strlen("l") == strlen("l"), "FAILURE! Test \"l\" failed!");
}
END_TEST

START_TEST(S21_STRCHR) {
  char msg[50] = "Hello, World!";
  ck_assert_msg(strcmp(s21_strchr("", '\0'), strchr("", '\0')) == 0,
                "FAILURE!");
  ck_assert_msg(strcmp(s21_strchr(msg, '\0'), strchr(msg, '\0')) == 0,
                "FAILURE! ");
  ck_assert_msg(strcmp(s21_strchr(msg, ','), strchr(msg, ',')) == 0,
                "FAILURE! ");
  ck_assert_msg(s21_strchr(msg, 'h') == strchr(msg, 'h'), "FAILURE! ");
  ck_assert_msg(strcmp(s21_strchr(msg, ' '), strchr(msg, ' ')) == 0,
                "FAILURE!");
}
END_TEST

Suite* string_suite(){
    Suite* s = suite_create("s21_string testing");

    TCase* tc_core = tcase_create("Vugluskr");
    tcase_add_test(tc_core, S21_MEMCHR);
    tcase_add_test(tc_core, S21_MEMCMP);
    tcase_add_test(tc_core, S21_MEMCPY);
    tcase_add_test(tc_core, S21_STRLEN);
    tcase_add_test(tc_core, S21_STRCHR);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(){
    Suite* s = string_suite();
    SRunner* sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return number_failed ? 1 : 0;
}
