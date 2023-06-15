void heapify(int A[], int n, int i) {
  if (i >= n) {
    return;
  }

  int largest = i, t, lchild = 2*i+1, rchild = 2*i+2;

  if (lchild < n && A[largest] < A[lchild]) {
    largest = lchild;
  }

  if (rchild < n && A[largest] < A[rchild]) {
    largest = rchild;
  }

  if (largest != i) {
    t = A[largest];
    A[largest] = A[i];
    A[i] = t;
    heapify(A, n, largest);
  }
}

void Heap_Sort(int A[], int n) {
  int lastNode = n-1, parent = (lastNode - 1) / 2;
  for (int i=parent; i>=0; i--) {
    make_heap(A, n, i);
  }

  for (int i=n-1; i>=0; i--) {
    A[i] = A[0];
    make_heap(A, i, 0);
  }
}
