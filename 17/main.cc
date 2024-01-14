#include <cstdio>
#include <cstdlib>

char *remove(char *s, size_t size, char c) {
  char *buf = (char *)malloc(sizeof(char) * (size + 1));
  for (int i = 0, j = 0; i < size; i++) {
    if (s[i] != c) {
      buf[j++] = s[i];
    }
  }
  return buf;
}

int main() {
  char *s = (char *)malloc(sizeof(char) * 256);
  size_t size = 256;
  size = getline(&s, &size, stdin);
  s[--size] = '\0';

  char c = getc(stdin);

  char *res = remove(s, size, c);
  printf("%s", res);

  free(s);
  free(res);
}
