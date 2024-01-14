#include <cstdio>
#include <cstdlib>

#define BUFFER_CAP 256

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

int convChar(char c) {
  if ('a' <= c && c <= 'z') {
    c += 'A' - 'a';
  }
  if (c < '0') {
    return 0;
  }
  if (c <= '9') {
    return c - '0';
  }
  if (c < 'A') {
    return 0;
  }
  if (c <= 'Z') {
    return c - 'A' + 10;
  }
  return 0;
}

char convDigit(int digit) {
  if (digit < 10) {
    return '0' + digit;
  }
  return 'A' + digit - 10;
}

int pow(int x, int y) {
  int res = 1;
  for (; y > 0; y--) {
    res *= x;
  }
  return res;
}

int toBase10(char *num, int fromBase) {
  size_t len = strlen(num);
  int res = 0;
  for (int i = len - 1; i >= 0; i--) {
    res += convChar(num[i]) * pow(fromBase, len - i - 1);
  }
  return res;
}

char *grow(char *buf, size_t *size) {
  size_t newSize = *size << 1;
  char *tmpBuf = (char *)malloc(sizeof(char) * newSize);
  for (int i = 0; i < *size; i++) {
    tmpBuf[i] = buf[i];
  }
  tmpBuf[newSize - 1] = '\0';
  *size = newSize;
  free(buf);
  return tmpBuf;
}

char *reverse(char *s) {
  int l = strlen(s);
  for (int i = 0, j = l - 1; i < j; i++, j--) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
  return s;
}

char *toBaseN(int num, int toBase) {
  char *result = (char *)malloc(sizeof(char) * BUFFER_CAP);
  size_t size = BUFFER_CAP;
  int i = 0;
  while (num > 0) {
    if (i >= size) {
      result = grow(result, &size);
    }
    result[i++] = convDigit(num % toBase);
    num /= toBase;
  }
  result[i] = '\0';
  return reverse(result);
}

int main() {
  char *num = (char *)malloc(sizeof(char) * BUFFER_CAP);
  size_t size = BUFFER_CAP;
  printf("Num: ");
  size_t l = getline(&num, &size, stdin);
  num[--l] = '\0';

  int k;
  printf("Given base: ");
  scanf("%d", &k);

  int num10 = toBase10(num, k);
  printf("num10: %d\n", num10);

  int n;
  printf("Base n: ");
  scanf("%d", &n);

  char *res = toBaseN(num10, n);
  printf("Result: %s\n", res);
}
