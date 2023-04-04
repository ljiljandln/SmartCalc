#include "s21_smartcalc.h"

double calculate(stack input) {
  for (int i = 0; i <= input.top; i++) {
    while (input.elements[i].type == NUMBER || input.elements[i].type == X) {
      i++;
    }
    int type = input.elements[i].type;

    if (type >= PLUS && type <= EXP &&
        (input.elements[i - 1].type == 0 || input.elements[i - 1].type == 1)) {
      int j = i - 2;
      while (input.elements[j].type != 0 && input.elements[j].type != 1) j--;
      calcOperators(type, i, j, &input);
    } else if (type >= COS && (input.elements[i - 1].type == 0 ||
                               input.elements[i - 1].type == 1)) {
      calcFunctions(type, i, &input);
    }
  }
  return input.elements[input.top].value;
}

void calcOperators(int type, int i, int j, stack *input) {
  double res = 0, b = input->elements[i - 1].value,
         a = input->elements[j].value;
  if (type == PLUS) {
    res = a + b;
  } else if (type == MINUS) {
    res = a - b;
  } else if (type == MULT) {
    res = a * b;
  } else if (type == DIV) {
    res = a / b;
  } else if (type == MOD) {
    res = fmod(a, b);
  } else if (type == EXP) {
    res = pow(a, b);
  }
  input->elements[i - 1].type = REMOVED;
  input->elements[j].type = REMOVED;
  input->elements[i].value = res;
  input->elements[i].type = NUMBER;
}

void calcFunctions(int type, int i, stack *input) {
  double res = 0, a = input->elements[i - 1].value;
  if (type == COS) {
    res = cos(a);
  } else if (type == SIN) {
    res = sin(a);
  } else if (type == SQRT) {
    res = sqrt(a);
  } else if (type == TAN) {
    res = tan(a);
  } else if (type == ACOS) {
    res = acos(a);
  } else if (type == ASIN) {
    res = asin(a);
  } else if (type == ATAN) {
    res = atan(a);
  } else if (type == LN) {
    res = log(a);
  } else if (type == LOG) {
    res = log10(a);
  }
  input->elements[i - 1].type = REMOVED;
  input->elements[i].value = res;
  input->elements[i].type = NUMBER;
}
