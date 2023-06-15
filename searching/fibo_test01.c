#include <stdio.h>

extern int fibo(int);
extern int Fibonacci_Search(int[], int, int);

int main() {
  int i;

  for (i=0; i<10; i++) {
    printf("%d\t", fibo(i));
  }

  int n = 10, key = 81;
  int A[] = {6,14,23,36,55,67,76,78,81,89};

  Fibonacci_Search(A, n, key);

  return 0;
}
