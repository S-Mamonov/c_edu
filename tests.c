#include <check.h>
#include "s21_string.h"

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

    TCase* tc_core = tcase_create("JopKa");
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
