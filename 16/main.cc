#include <cstdio>
#include <cstdlib>

typedef struct {
  char *s;
  size_t len;
  size_t cap;
} String;

String *newString(size_t len, size_t cap) {
  String *s = (String *)malloc(sizeof(String));
  s->len = len;
  s->cap = cap;
  s->s = (char *)malloc(sizeof(char) * cap);
  return s;
}

void grow(String *s) {
  size_t oldCap = s->cap;
  s->cap <<= 1;
  char *buf = (char *)malloc(sizeof(char) * s->cap);

  for (size_t i = 0; i < s->len; i++) {
    buf[i] = s->s[i];
  }
  free(s->s);
  s->s = buf;
}

void append(String *s, char c) {
  s->len++;
  if (s->len > s->cap) {
    grow(s);
  }
  s->s[s->len - 1] = c;
}

void reverse(String *s) {
  for (int i = 0, j = s->len - 1; i < j; i++, j--) {
    char tmp = s->s[i];
    s->s[i] = s->s[j];
    s->s[j] = tmp;
  }
}

char itoa(int d) { return '0' + d; }

String *conv(int a, int d) {
  String *s = newString(0, 8);
  while (a > 0) {
    append(s, itoa(a % d));
    a /= d;
  }
  reverse(s);
  return s;
}

void destroyString(String *s) {
  free(s->s);
  free(s);
}

int main() {
  int a, d;
  scanf("%d %d", &a, &d);

  String *s = conv(a, d);
  for (int i = 0; i < s->len; i++) {
    putc(s->s[i], stdout);
  }

  destroyString(s);
}
