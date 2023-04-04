#include <check.h>

#include "../s21_smartcalc.h"

START_TEST(test_1) {
  int true_res = 10;
  char str[255] = "5 + 5";
  double x = smartCalc(str, 0);
  ck_assert_int_eq(x, true_res);
}
END_TEST

START_TEST(valid_false_brace_1) {
  int true_res = 1;
  char str[255] = "5 + (";
  int res = checkString(str);
  ck_assert_int_eq(res, true_res);
}
END_TEST

START_TEST(valid_false_brace_2) {
  int true_res = 1;
  char str[255] = "5 + )(";
  int res = checkString(str);
  ck_assert_int_eq(res, true_res);
}
END_TEST

START_TEST(valid_false_brace_3) {
  int true_res = 1;
  char str[255] = "5 + ()";
  int res = checkString(str);
  ck_assert_int_eq(res, true_res);
}
END_TEST


START_TEST(valid_false_dot) {
  int true_res = 1;
  char str[255] = "5. + 4";
  int res = checkString(str);
  ck_assert_int_eq(res, true_res);
}
END_TEST

START_TEST(valid_false_cos) {
  int true_res = 1;
  char str[255] = "cos(.)";
  int res = checkString(str);
  ck_assert_int_eq(res, true_res);
}
END_TEST

START_TEST(valid_false_sin) {
  int true_res = 1;
  char str[255] = "sin(i)";
  int res = checkString(str);
  ck_assert_int_eq(res, true_res);
}
END_TEST

START_TEST(valid_false_func_1) {
  int true_res = 1;
  char str[255] = "sqrw(7)";
  int res = checkString(str);
  ck_assert_int_eq(res, true_res);
}
END_TEST

START_TEST(valid_false_func_2) {
  int true_res = 1;
  char str[255] = "ataf(1+9)";
  int res = checkString(str);
  ck_assert_int_eq(res, true_res);
}
END_TEST

START_TEST(valid_false_func_3) {
  int true_res = 1;
  char str[255] = "lop(7)";
  int res = checkString(str);
  ck_assert_int_eq(res, true_res);
}
END_TEST

START_TEST(valid_false_symbol) {
  int true_res = 1;
  char str[255] = "sqrth(7)";
  int res = checkString(str);
  ck_assert_int_eq(res, true_res);
}
END_TEST

START_TEST(calc_1) {
  double a = smartCalc("2/(3+2)*5", 0);
  ck_assert_int_eq(a, 2);
}
END_TEST

START_TEST(calc_2) {
  double a = smartCalc("2^3", 0);
  ck_assert_int_eq(a, 8);
}
END_TEST

START_TEST(calc_3) {
  char str[255] = "4*5*2*2*2+2";
  double x = smartCalc(str, 0);
  ck_assert_int_eq(x, 162);
}
END_TEST

START_TEST(calc_4) {
  double x = 0;
  double orig = 20;
  char str[255] = "150/10+5*2/2";
  x = smartCalc(str, 0);
  ck_assert_int_eq(x, orig);
}
END_TEST

START_TEST(calc_5) {
  double x = 0;
  double orig = 9;
  char str[255] = "5+5-2*3/6";
  x = smartCalc(str, 0);
  ck_assert_int_eq(x, orig);
}
END_TEST

START_TEST(calc_6) {
  double x = 0;
  double orig = 69;
  char str[255] = "2+(5*5*5+5+2*2)/(2)";
  x = smartCalc(str, 0);
  ck_assert_int_eq(x, orig);
}
END_TEST

START_TEST(calc_7) {
  char *str = "24*4-3*2";
  double orig = 90;
  double value = smartCalc(str, 0);
  ck_assert_int_eq(value, orig);
}
END_TEST

START_TEST(calc_8) {
  double orig = 4;
  char *str = "2-(-2)";
  double value = smartCalc(str, 0);
  ck_assert_int_eq(value, orig);
}
END_TEST

START_TEST(calc_9) {
  double orig = -0.41211848524;
  char *str = "-sin(9)";
  double value = smartCalc(str, 0);
  ck_assert_float_eq(value, orig);
}
END_TEST

START_TEST(calc_10) {
  double orig = 2.41211848524;
  char *str = "sin(9)-(-2)";
  double value = smartCalc(str, 0);
  ck_assert_float_eq(value, orig);
}

END_TEST
START_TEST(calc_11) {
  double orig = 0.91113026188;
  char *str = "-cos(9)";
  double value = smartCalc(str, 0);
  ck_assert_float_eq(value, orig);
}
END_TEST

START_TEST(plus) {
  double a = smartCalc("(-2)+2", 0);
  ck_assert_int_eq(a, 0);
}
END_TEST

START_TEST(minus) {
  double a = smartCalc("(-2)-2", 0);
  ck_assert_int_eq(a, -4);
}
END_TEST

START_TEST(mult) {
  double a = smartCalc("(-2)*(+2)", 0);
  ck_assert_int_eq(a, -4);
}
END_TEST

START_TEST(division) {
  double a = smartCalc("(-2.2)/2.2", 0);
  ck_assert_int_eq(a, -1);
}
END_TEST

START_TEST(test_sin) {
  double a = smartCalc("sin(-2)", 0);
  ck_assert_float_eq(a, sinl(-2));
}
END_TEST

START_TEST(test_cos) {
  double a = smartCalc("cos(2)", 0);
  ck_assert_double_eq(a, cosl(2));
}
END_TEST

START_TEST(test_tan) {
  double a = smartCalc("tan(2)", 0);
  ck_assert_double_eq(a, tanl(2));
}
END_TEST

START_TEST(test_asin) {
  double a = smartCalc("asin(1)", 0);
  ck_assert_double_eq(a, asinl(1));
}
END_TEST

START_TEST(test_acos) {
  double a = smartCalc("acos(1)", 0);
  ck_assert_double_eq(a, acosl(1));
}
END_TEST

START_TEST(test_atan) {
  double a = smartCalc("atan(1)", 0);
  ck_assert_double_eq(a, atanl(1));
}
END_TEST

START_TEST(test_ln) {
  double a = smartCalc("log(1)\n", 0);
  ck_assert_double_eq(a, logf(1));
}
END_TEST

START_TEST(test_log) {
  double a = smartCalc("log(1)", 0);
  ck_assert_double_eq(a, log10l(1));
}
END_TEST

START_TEST(test_sqrt) {
  double a = smartCalc("sqrt(1)", 0);
  ck_assert_double_eq(a, sqrtl(1));
}
END_TEST

START_TEST(mod) {
  long double my = smartCalc("4mod8+2", 0);
  ck_assert_int_eq(my, 6);
}
END_TEST

START_TEST(x_1) {
  char *src = "x+x";
  double x = 2;
  double result = smartCalc(src, x);
  double real_result = 4;
  ck_assert_int_eq(result, real_result);
}
END_TEST

START_TEST(x_2) {
  char *src = "log(x)";
  double x = -2;
  double result = smartCalc(src, x);
  double real_result = NAN;
  ck_assert_int_eq(result, real_result);
}
END_TEST

START_TEST(calc_12) {
  char *src = "123+0.456+4";
  double result = smartCalc(src, 0);
  double real_result = 127.456;
  ck_assert_double_eq(result, real_result);
}
END_TEST

START_TEST(calc_13) {
  char *src = "-(-1)";
  double result = smartCalc(src, 0);
  double real_result = 1;
  ck_assert_int_eq(result, real_result);
}
END_TEST

START_TEST(calc_15) {
  char *src = "sqrt(ln(10))";
  double result = smartCalc(src, 0);
  double real_result = 1.517427;
  ck_assert_int_eq(result, real_result);
}
END_TEST

START_TEST(calc_17) {
  char *src = "asin(1)";
  double result = smartCalc(src, 0);
  double real_result = 1.570796;
  ck_assert_int_eq(result, real_result);
}
END_TEST

START_TEST(calc_14) {
  char *src = "10-20*(-10)";
  double result = smartCalc(src, 0);
  double real_result = 210;
  ck_assert_int_eq(result, real_result);
}
END_TEST

START_TEST(calc_18) {
  char *src = "+(10-20)";
  double result = smartCalc(src, 0);
  double real_result = -10;
  ck_assert_int_eq(result, real_result);
}
END_TEST


int main(void) {
  Suite* s1 = suite_create("Core");
  TCase* tc = tcase_create("Core");
  SRunner* sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc);
  tcase_add_test(tc, test_1);
  tcase_add_test(tc, valid_false_brace_1);
  tcase_add_test(tc, valid_false_brace_2);
  tcase_add_test(tc, valid_false_brace_3);
  tcase_add_test(tc, valid_false_cos);
  tcase_add_test(tc, valid_false_sin);
  tcase_add_test(tc, valid_false_func_1);
  tcase_add_test(tc, valid_false_func_2);
  tcase_add_test(tc, valid_false_func_3);
  tcase_add_test(tc, valid_false_symbol);
  tcase_add_test(tc, valid_false_dot);
  tcase_add_test(tc, calc_1);
  tcase_add_test(tc, calc_2);
  tcase_add_test(tc, calc_3);
  tcase_add_test(tc, calc_4);
  tcase_add_test(tc, calc_5);
  tcase_add_test(tc, calc_6);
  tcase_add_test(tc, calc_7);
  tcase_add_test(tc, calc_8);
  tcase_add_test(tc, calc_9);
  tcase_add_test(tc, calc_10);
  tcase_add_test(tc, calc_11);
  tcase_add_test(tc, calc_12);
  tcase_add_test(tc, calc_13);
  tcase_add_test(tc, calc_15);
  tcase_add_test(tc, calc_17);
  tcase_add_test(tc, calc_14);
  tcase_add_test(tc, calc_18);

  tcase_add_test(tc, plus);
  tcase_add_test(tc, minus);
  tcase_add_test(tc, mult);
  tcase_add_test(tc, division);
  tcase_add_test(tc, test_sin);
  tcase_add_test(tc, test_cos);
  tcase_add_test(tc, test_tan);
  tcase_add_test(tc, test_asin);
  tcase_add_test(tc, test_acos);
  tcase_add_test(tc, test_atan);
  tcase_add_test(tc, test_ln);
  tcase_add_test(tc, test_log);
  tcase_add_test(tc, test_sqrt);
  tcase_add_test(tc, mod);
  tcase_add_test(tc, x_1);
  tcase_add_test(tc, x_2);
  
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
