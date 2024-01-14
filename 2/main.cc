#include <cstdio>

void sort(int *a, int n);
char less(int a, int b);

int main() {
  printf("%d\n", less(1, 0));
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  sort(a, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}

char less(int a, int b) { return (a & 1) == 1 && (b & 1) == 0; }

void sort(int *a, int n) {
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    for (; j >= 0 && less(key, a[j]); j--) {
      printf("DO\n");
      a[j + 1] = a[j];
    }
    a[j + 1] = key;
  }
}
