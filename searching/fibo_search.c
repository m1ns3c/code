// Function to find nth Fibonacci number
int fibo(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  return fibo(n-1) + fibo(n-2);
}

// Function for Fibonacci search
int Fibonacci_Search(int A[], int n, int key) {
  int f1, f2, t, mid, j, f;

  j = 1;
  while (fibo(j) <= n) {
    j++;
  }
  f = fibo(j);
  f1 = fibo(j - 2); // lower Fibonacci numbers
  f2 = fibo(j - 3);

  mid = n - f1 + 1;
  while (key != A[mid]) {
    if (mid < 0 || key > A[mid]) {
      // look in lower half
      if (f1 == 1) {
        return -1;
      }
      mid = mid + f2; // decrease Fibonacci numbers
      f1 = f1 - f2;
      f2 = f2 - f1;
    } else {
      // look in upper half
      if (f2 == 0) {
        return -1;
      }
      mid = mid - f2;
      t = f1 - f2;
      f1 = f2;
      f2 = t;
    }
  }
  return mid;
}
