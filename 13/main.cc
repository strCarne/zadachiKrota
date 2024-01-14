#include <cstdio>
#include <cstdlib>

#define BUFFER_CAP 256

int strlen(char const *s) {
  if (s == NULL) {
    return 0;
  }
  int size = 0;
  while (s[size] != '\0') {
    size++;
  }
  return size;
}

int findStart(char const *s, int from) {
  if (s == NULL) { return -1; }
  while (s[from] != '\0' && s[from] != '{') {
    from++;
  }
  return from;
}

int findEnd(char const *s, int from) {
  if (s == NULL) { return -1; }
  from++;
  int balance = 0;
  while (s[from] != '\0' && balance >= 0) {
    if (s[from] == '{') {
      balance++;
    } else if (s[from] == '}') {
      balance--;
    }
    from++;
  }
  return from;
}

char *append(char *buf, char const *s, int from, int end) {
  if (end - from == 0) { return buf; }

  int size = strlen(buf);
  int newSize = size + end - from;
  char *tmpBuf = (char *)malloc(sizeof(char) * (newSize + 1));

  for (int i = 0; i < size; i++) {
    tmpBuf[i] = buf[i];
  }
  free(buf);

  for (int i = size; i < newSize && from < end; i++, from++) {
    tmpBuf[i] = s[from];
  }
  tmpBuf[newSize] = '\0';

  return tmpBuf;
}

char *deleteComments(char *s) {
  char *final = NULL;

  int nonCommStart = 0;
  int i = findStart(s, 0);
  while (s[i] != '\0' && s[i] == '{') {
    int j = findEnd(s, i);
    if (s[j - 1] != '}') {
      return NULL;
    } else {
      final = append(final, s, nonCommStart, i);
    }
    nonCommStart = j;
    i = findStart(s, j);
  }
  
  return append(final, s, nonCommStart, strlen(s));
}

int main() {
  char *s = (char *)malloc(sizeof(char) * BUFFER_CAP);
  size_t size = BUFFER_CAP;
  size_t l = getline(&s, &size, stdin);
  s[--l] = '\0';

  char *final = deleteComments(s);
  if (final != NULL) {
    printf("%s\n", final);
    free(final);
  }

  free(s);
}
