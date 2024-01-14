#include <cstdio>
#include <cstdlib>
#define BUFFER_CAP 256

char *formNumsString(char const *s);
int getWordEnd(char const *s, int start);
char isNumString(char const *s, int start, int end);
int skipSpaces(char const *s, int currPos);
char *appendNum(char const *s, int start, int end, char *recver);

int main() {
  char *s = (char *)malloc(sizeof(char) * BUFFER_CAP);
  size_t size = BUFFER_CAP;
  printf("Enter the string: ");
  size_t l = getline(&s, &size, stdin);
  s[l - 1] = '\0';

  putc('\n', stdout);
  printf("Base string: %s\n", s);

  char *nums = formNumsString(s);
  if (nums == NULL) {
    printf("No nums in the string\n");
  } else {
    printf("Nums:%s", nums);
  }
}

char *formNumsString(char const *s) {
  int i = skipSpaces(s, 0);
  char *result = NULL;
  while (s[i] != '\0') {
    int j = getWordEnd(s, i);
    if (isNumString(s, i, j)) {
      result = appendNum(s, i, j, result);
    }
    i = skipSpaces(s, j);
  }

  return result;
}

int getWordEnd(char const *s, int start) {
  while (s[start] != '\0' && s[start] != ' ') {
    start++;
  }
  return start;
}

int skipSpaces(char const *s, int currPos) {
  while (s[currPos] != '\0' && s[currPos] == ' ') {
    currPos++;
  }
  return currPos;
}

char isNumString(char const *s, int start, int end) {
  if (start == end) {
    return 0;
  }
  for (; start < end; start++) {
    if (s[start] < '0' || s[start] > '9') {
      return 0;
    }
  }
  return 1;
}

size_t strlen(char const *s) {
  if (s == NULL) {
    return 0;
  }
  size_t size = 0;
  while (s[size] != '\0') {
    size++;
  }
  return size;
}

char *appendNum(char const *s, int start, int end, char *recver) {
  size_t prevLen = strlen(recver);
  size_t newLen = prevLen + end - start + 1;
  char *tmpBuffer = (char *)malloc(sizeof(char) * (newLen + 1));

  tmpBuffer[newLen] = '\0';
  for (int i = 0; i < prevLen; i++) {
    tmpBuffer[i] = recver[i];
  }

  tmpBuffer[prevLen] = ' ';

  for (int i = prevLen + 1; i < newLen && start < end; i++, start++) {
    tmpBuffer[i] = s[start];
  }

  return tmpBuffer;
}
