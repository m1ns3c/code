int Binary_Search_non_recursive(int A[], int n, int key) {
  int low = 0, high = n-1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    // mid = low + (high - low) / 2
    if (A[mid] == key) {
      return mid;
    } else if (key < A[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return -1;
}

// Function binary search (recursive)
int Binary_Search(int A[], int low, int high, int key) {
  int mid;
  if (low <= high) {
    mid = (high + low) / 2;
    if (A[mid] == key) {
      return mid;
    } else if (key < A[mid]) {
      return Binary_search(A, low, mid - 1, key);
    } else {
      return Binary_search(A, mid + 1, high, key);
    }
  }

  return -1;
}
