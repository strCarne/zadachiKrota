#include <cstdio>
#include <cstdlib>

#define BUFFER_CAP 256

int main() {
  char *s = (char *)malloc(sizeof(char) * BUFFER_CAP);
  size_t size = BUFFER_CAP;
  printf("Enter the string: ");
  size_t l = getline(&s, &size, stdin);
  s[--l] = '\0';

  printf("Enter your character: ");
  char c = getc(stdin);

  int count = 0;
  for (int i = 0; i < l; i++) {
    if (s[i] == c) {
      count++;
    }
  }

  printf("%f", ((float)count) / l * 100.0f);
}
