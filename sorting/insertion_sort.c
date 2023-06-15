void Insertion_Sort(int A[], int n) {
  int i, j, p;
  for (i=1; i<n; i++) {
    p = A[i];
    j = i;
    while (j > 0 && A[j-1] > p) {
      A[j] = A[j-1];
      j--;
    }
    A[j] = p;
  }
}
