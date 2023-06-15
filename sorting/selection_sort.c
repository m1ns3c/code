void Selection_Sort(int A[], int n) {
  int i, j, max;
  for (i=n-1; i>0; i--) {
    max = i;
    for (j=0; j<i; j++) {
      if (A[j] > A[max]) {
        max = j;
      }
    }

    if (max != i) {
      int t = A[max];
      A[max] = A[i];
      A[i] = t;
    }
  }
}

void SelectionSort(int A[], int n) {
  int i, j;
  int minpos, temp;
  for (i=0; i<n-1; i++) {
    minpos = i;
    for (j=i+1; j<n; j++) {
      if (A[j] < A[minpos]) {
        minpos = j;
      }
    }
    if (minpos != i) {
      temp = A[i];
      A[i] = A[minpos];
      A[minpos] = temp;
    }
  }
}
