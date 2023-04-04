#include "s21_smartcalc.h"

stack parseInput(char *input, double x) {
  stack s = createStack();
  while (*input != '\0') {
    if (strchr("0123456789.", *input)) {
      input = parseNumber(input, &s);
    } else if (strchr("+-*/^()", *input)) {
      parceOperators(input++, &s);
    } else if (*input == 'x') {
      push(&s, getElement(x, 0, X));
      input++;
    } else if (strchr("sctalm", *input)) {
      input = parseFunctions(input, &s);
    } else {
      break;
    }
  }
  return s;
}

char *parseNumber(char *input, stack *s) {
  char number[255] = {0};
  int j = 0;
  while (strchr("0123456789.", *input)) {
    number[j] = *input;
    input++;
    j++;
  }
  number[j] = '\0';
  double value = atof(number);
  push(s, getElement(value, 0, NUMBER));
  return input;
}

void parceOperators(char *input, stack *s) {
  switch (*input) {
    case '+':
      if (isEmptyStack(s) || *(--input) == '(' || *input == 'd')
        push(s, getElement(0, 0, NUMBER));
      push(s, getElement(0, 1, PLUS));
      break;
    case '-':
      if (isEmptyStack(s) || *(--input) == '(' || *input == 'd')
        push(s, getElement(0, 0, NUMBER));
      push(s, getElement(0, 1, MINUS));
      break;
    case '*':
      push(s, getElement(0, 2, MULT));
      break;
    case '/':
      push(s, getElement(0, 2, DIV));
      break;
    case '^':
      push(s, getElement(0, 3, EXP));
      break;
    case '(':
      push(s, getElement(0, 5, OPEN_BRACE));
      break;
    case ')':
      push(s, getElement(0, 6, CLOSE_BRACE));
      break;
  }
}

char *parseFunctions(char *input, stack *s) {
  switch (*input) {
    case 'c':
      if (*(++input) == 'o' && *(++input) == 's')
        push(s, getElement(0, 4, COS));
      break;
    case 's':
      if (*(++input) == 'i') {
        push(s, getElement(0, 4, SIN));
        input++;
      } else {
        push(s, getElement(0, 4, SQRT));
        input += 2;
      }
      break;
    case 't':
      push(s, getElement(0, 4, TAN));
      input += 2;
      break;
    case 'a':
      if (*(++input) == 's') {
        push(s, getElement(0, 4, ASIN));
        input += 2;
      } else if (*input == 'c') {
        push(s, getElement(0, 4, ACOS));
        input += 2;
      } else if (*input == 't') {
        push(s, getElement(0, 0, ATAN));
        input += 2;
      }
      break;
    case 'l':
      if (*(++input) == 'n') {
        push(s, getElement(0, 4, LN));
      } else if (*input == 'o') {
        push(s, getElement(0, 4, LOG));
        input++;
      }
      break;
    case 'm':
      if (*(++input) == 'o' && *(++input) == 'd')
        push(s, getElement(0, 2, MOD));
      break;
  }
  return ++input;
}
