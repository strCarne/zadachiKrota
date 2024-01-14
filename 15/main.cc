#include <cstdio>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int matrix[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  int maxCol = 0;
  int maxSum = -(1 << (8 * sizeof(int) - 1));
  for (int j = 0; j < m; j++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += matrix[i][j];
    }
    if (sum > maxSum) {
      maxSum = sum;
      maxCol = j;
    }
  }

  printf("MaxCol: %d\nMaxSum: %d\n", maxCol, maxSum);
}
