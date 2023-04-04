#ifndef SRC_S21_SMARTCALC_H_
#define SRC_S21_SMARTCALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    REMOVED = -1,
    NUMBER = 0,
    X = 1,
    PLUS = 2,
    MINUS = 3,
    MULT = 4,
    DIV = 5,
    MOD = 6,
    EXP = 7,
    OPEN_BRACE = 8,
    CLOSE_BRACE = 9,
    COS = 10,
    SIN = 11,
    SQRT = 12,
    TAN = 13,
    ACOS = 14,
    ASIN = 15,
    ATAN = 16,
    LN = 17,
    LOG = 18
} type_el;

typedef struct Element {
    double value;
    int priority;
    type_el type;
} element;

typedef struct Stack {
    int top;
    element elements[256];
} stack;

void deleteSpaces(char *input);
void checkBraces(char *input, int *code);
int checkSimbol(char *input);
char *checkFunctions(char *input, int *code);
int checkFirstInBraces(char *input);
int checkSin(char *input);
int checkSqrt(char *input);
int checkTan(char *input);
int checkCos(char *input);
int checkLn(char *input);
int checkLog(char *input);
int checkMod(char *input);
double smartCalc(char *input, double x);
int checkString(char *input);

stack createStack();
element pop(stack *s);
element getElement(double value, int priority, type_el type);
void push(stack *s, element el);
void printStack(stack *s);
void converter(int type);
int isEmptyStack(stack *s);

stack parseInput(char *input, double x);
char *parseNumber(char *input, stack *s);
void parceOperators(char *input, stack *s);
char* parseFunctions(char *input, stack *s);

stack getPolish(stack input);

double calculate(stack input);
void calcFunctions(int type, int i, stack *input);
void calcOperators(int type, int i, int j, stack *input);

#endif // SRC_S21_SMARTCALC_H_