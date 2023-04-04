#include "s21_smartcalc.h"

stack getPolish(stack input) {
  stack ready = createStack();
  stack support = createStack();
  for (int i = 0; i <= input.top; i++) {
    element current = input.elements[i];
    if (current.type == NUMBER || current.type == X) {
      push(&ready, current);
    } else if (current.type >= COS || current.type == OPEN_BRACE) {
      push(&support, current);
    } else if (current.type > X && current.type < OPEN_BRACE) {
      element tmp = support.elements[support.top];
      while (tmp.priority >= current.priority && tmp.type != OPEN_BRACE &&
             !isEmptyStack(&support)) {
        push(&ready, pop(&support));
        tmp = support.elements[support.top];
      }
      push(&support, current);
    } else if (current.type == CLOSE_BRACE) {
      element tmp = support.elements[support.top];
      while (tmp.type != OPEN_BRACE && !isEmptyStack(&support)) {
        push(&ready, pop(&support));
        tmp = support.elements[support.top];
      }
      pop(&support);
      if (support.elements[support.top].type >= COS) {
        push(&ready, pop(&support));
      }
    }
  }
  while (support.top != -1) {
    push(&ready, pop(&support));
  }
  return ready;
}
