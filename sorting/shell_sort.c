#include <stdio.h>

void debug_p(int A[], int n) {
  printf("\n");
  for (int i=0; i<n; i++) {
    printf("%3d ", i);
  }
  printf("\n");
  for (int i=0; i<n; i++) {
    printf("%3d ", A[i]);
  }
  printf("\n");
}

void Shell_Sort(int A[], int n) {
  int gap = n, i, j, temp;

  debug_p(A, n);

  while ((gap = gap / 2) >= 1) {
    printf("gap [%d]\n", gap);
    for (i=0; i<n-gap; i++) {
      for (j = i; j>=gap; j-=gap) {
        if (A[j] < A[j-gap]) {
          temp = A[j];
          A[j] = A[j-gap];
          A[j-gap] = temp;
        }
      }
      A[j] = A[i];
      debug_p(A, n);
      getchar();
    }
  }
}
