#include <cstdio>
#include <cstdlib>

int *remove(int *a, int *n, int k) {
  a[k] = a[(*n) - 1];
  (*n)--;

  int *ptr = (int *)realloc(a, sizeof(int) * (*n));
  if (ptr == a) {
    return ptr;
  } else if (ptr != a) {
    for (int i = 0; i < *n; i++) {
      ptr[i] = a[i];
    }
    free(a);
    return ptr;
  }

  // failure
  return NULL;
}

int main() {
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  int k;
  printf("Enter k: ");
  scanf("%d", &k);
  k--;

  int *a = (int *)malloc(sizeof(int) * n);
  printf("Enter the array elements.\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  a = remove(a, &n, k);

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}
