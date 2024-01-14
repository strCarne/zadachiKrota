#include <cstdio>
#include <cstdlib>

#define BUF_CAP 256

#define CHARTYPE_NUM 4
typedef enum {
  Digit,
  Space,
  Op,
  Other,
} CharType;

#define STATE_NUM 6
typedef enum {
  WaitingForFirstDigit,
  DigitRead,
  WaitingForOp,
  OpRead,
  Final,
  Error,
} State;

State T[STATE_NUM][CHARTYPE_NUM] = {
    {DigitRead, WaitingForFirstDigit, Error, Error},
    {DigitRead, WaitingForOp, OpRead, Error},
    {Error, WaitingForOp, OpRead, Error},
    {Final, OpRead, Error, Error},
    {Final, WaitingForOp, OpRead, Error},
    {Error, Error, Error, Error},
};

char isDigit(char c) { return '0' <= c && c <= '9'; }

char isSpace(char c) { return c == ' '; }

char isOp(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

State defineState(State state, char c) {
  if (isDigit(c)) {
    return T[state][Digit];
  } else if (isSpace(c)) {
    return T[state][Space];
  } else if (isOp(c)) {
    return T[state][Op];
  }
  return T[state][Other];
}

char isError(State state) { return state == Error; }
char isFinal(State state) { return state == Final; }

int main() {
  char *expression = (char *)malloc(sizeof(char) * BUF_CAP);
  size_t size = BUF_CAP;
  printf("Enter the expression: ");
  size_t l = getline(&expression, &size, stdin);
  expression[--l] = '\0';

  int i = 0;
  State state = WaitingForFirstDigit;
  while (i < l) {
    state = defineState(state, expression[i++]);
    if (isError(state)) {
      break;
    }
  }

  if (isFinal(state)) {
    printf("It's a correct expression\n");
  } else {
    printf("It isn't a correct expression");
  }

  free(expression);
}
