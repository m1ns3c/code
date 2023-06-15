#include <stdio.h>

#define MaxSize 25

extern void Bubble_Sort(int[], int);
extern void Insertion_Sort(int[], int);
extern void Selection_Sort(int[], int);
extern void Quick_Sort(int[], int);
extern void Heap_Sort(int[], int);
extern void Shell_Sort(int[], int);

int main() {
  int A[] = {206,105,340,90,229,221,287,38,8,367,309,551,312,764,492,20,618,796,483,698,26,711,641,502,23};

  //Quick_Sort(A, MaxSize);
  //Heap_Sort(A, MaxSize);
  Shell_Sort(A, MaxSize);

  for (int i=0; i<MaxSize; i++) {
    printf("[%02d] %d\n", i, A[i]);
  }

  return 0;
}
