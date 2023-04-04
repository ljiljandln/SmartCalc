#include "s21_smartcalc.h"

double smartCalc(char *input, double x) {
  double res = 0;
  int code = checkString(input);
  if (!code) {
    stack s = parseInput(input, x);
    res = calculate(getPolish(s));
  }
  return res;
}

int checkFirstInBraces(char *input) {
  if (*input == '+' || *input == '-') input++;
  return !strchr("0123456789(sctalx", *input);
}

int checkCos(char *input) {
  return *(++input) == 'o' && *(++input) == 's' && *(++input) == '(' &&
         !checkFirstInBraces(++input);
}

int checkAcos(char *input) { return *(input++) == 'a' && checkCos(input); }

int checkLn(char *input) {
  return *(++input) == 'n' && *(++input) == '(' && !checkFirstInBraces(++input);
}

int checkLog(char *input) {
  return *(++input) == 'o' && *(++input) == 'g' && *(++input) == '(' &&
         !checkFirstInBraces(++input);
}

int checkSin(char *input) {
  return *(++input) == 'i' && *(++input) == 'n' && *(++input) == '(' &&
         !checkFirstInBraces(++input);
}

int checkAsin(char *input) { return *(input++) == 'a' && checkSin(input); }

int checkSqrt(char *input) {
  return *(++input) == 'q' && *(++input) == 'r' && *(++input) == 't' &&
         *(++input) == '(' && !checkFirstInBraces(++input);
}

int checkTan(char *input) {
  return *(++input) == 'a' && *(++input) == 'n' && *(++input) == '(' &&
         !checkFirstInBraces(++input);
}

int checkAtan(char *input) { return *(input++) == 'a' && checkTan(input); }

int checkMod(char *input) {
  return *(++input) == 'o' && *(++input) == 'd' && !checkFirstInBraces(++input);
}

char *checkFunctions(char *input, int *code) {
  if (checkSin(input) || checkTan(input) || checkCos(input) ||
      checkLog(input) || checkMod(input))
    input += 3;
  else if (checkSqrt(input) || checkAcos(input) || checkAsin(input) ||
           checkAtan(input))
    input += 4;
  else if (checkLn(input))
    input += 2;
  else
    *code = 1;
  return input;
}

int checkSimbol(char *input) {
  return !strchr("0123456789.()+-*/^xcstalm", *input);
}

int checkDot(char *input) {
  char prev = *(--input);
  input++;
  char next = *(++input);
  return !(strchr("0123456789", prev) && strchr("0123456789", next));
}

int checkString(char *input) {
  int code = 0;
  if (strchr(input, ' ')) deleteSpaces(input);
  checkBraces(input, &code);
  while (*input != '\0' && !code) {
    if (checkSimbol(input)) {
      code = 1;
      break;
    }
    if (strchr("sctalm", *input)) input = checkFunctions(input, &code);
    if (*input == '.' && checkDot(input)) code = 1;
    input++;
  }
  return code;
}

void checkBraces(char *input, int *code) {
  int openingBracesCount = 0, closingBracesCount = 0;
  while (*input != '\0' && !*code) {
    if (*input == '(') {
      openingBracesCount++;
      if (*(++input) == ')') {
        *code = 1;
        input--;
      }
    } else if (*input == ')') {
      closingBracesCount++;
      if (closingBracesCount > openingBracesCount) *code = 1;
    }
    input++;
  }
  if (closingBracesCount != openingBracesCount) *code = 1;
}

void deleteSpaces(char *input) {
  int size = (int)strlen(input);
  char inputWithoutSpaces[1000] = {'\0'};
  int j = 0;
  for (int i = 0; i < size; i++) {
    if (input[i] != ' ') {
      inputWithoutSpaces[j] = input[i];
      j++;
    }
  }
  for (int i = j; i < size; i++) {
    input[i] = '\0';
  }
  strcpy(input, inputWithoutSpaces);
}
