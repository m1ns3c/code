void Bubble_Sort(int A[], int n) {
  int i, j;
  for (i=1; i<n; i++) {
    for (j=0; j<n-i; j++) {
      if (A[j] > A[j+1]) {
        int t = A[j+1];
        A[j+1] = A[j];
        A[j] = t;
      }
    }
  }
}
