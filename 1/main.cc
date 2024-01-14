#include <cstdio>
#include <cstdlib>

#define BUFFER_CAPACITY 256
#define NUM_BUFFER_CAPACITY 64

size_t skipSpaces(char *str, size_t start);
int calcNumOfEntries(char *str, char *M);
size_t getWordEnd(char *str, size_t start);
char substrEquals(char *str, size_t from, size_t to, char *substr);

int main() {
  char *str = (char *)calloc(BUFFER_CAPACITY, sizeof(char));
  size_t size = BUFFER_CAPACITY;

  printf("Enter the string: ");
  getline(&str, &size, stdin);

  char *M = (char *)calloc(NUM_BUFFER_CAPACITY, sizeof(char));
  size_t sizeM = NUM_BUFFER_CAPACITY;

  printf("Enter M: ");
  getline(&M, &sizeM, stdin);

  int numOfEntries = calcNumOfEntries(str, M);
  printf("The number of entries of M in a given string is %d\n", numOfEntries);
}

int calcNumOfEntries(char *str, char *M) {
  int total = 0;

  size_t currPos = 0;
  while (str[currPos] != '\0') {
    currPos = skipSpaces(str, currPos);
    size_t end = getWordEnd(str, currPos);
    if (substrEquals(str, currPos, end, M)) {
      total++;
    }
    currPos = end;
  }
  return total;
}

size_t getWordEnd(char *str, size_t start) {
  start = skipSpaces(str, start);
  while (str[start] != '\0' && str[start] != ' ') {
    start++;
  }
  return start;
}

size_t skipSpaces(char *str, size_t start) {
  while (str[start] != '\0' && str[start] == ' ') {
    start++;
  }
  return start;
}

char substrEquals(char *str, size_t from, size_t to, char *substr) {
  for (int i = 0; from < to && substr[i] != '\0'; from++, i++) {
    if (str[from] != substr[i]) {
      return 0;
    }
  }
  return 1;
}
