#include "s21_smartcalc.h"

stack createStack() {
  stack s = {0};
  s.top = -1;
  return s;
}

int isEmptyStack(stack *s) { return s->top == -1; }

element pop(stack *s) {
  element tmp = {0};
  if (!isEmptyStack(s)) {
    tmp = s->elements[s->top];
    s->top--;
  }
  return tmp;
}

element getElement(double value, int priority, type_el type) {
  element res;
  res.value = value;
  res.priority = priority;
  res.type = type;
  return res;
}

void push(stack *s, element el) {
  int index = ++s->top;
  s->elements[index] = el;
}

