#include "sort.h"

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void print_arr(elemType arr[], int n)
{

  for (int i=0;i<n;i++) {
    printf("%d\t", arr[i]);
  }

  printf("\n");
}

int main()
{
  int n;
  elemType arr[N];

  while(scanf("%d", &n) != EOF) {
    printf("count:%d\n", n);

    int tmp;
    printf("test:%d\n", tmp = n);

    for (int i =0; i<n;i++) {
      scanf("%d", &arr[i]);
    }

    (*sort_ptr)(arr, n);
    print_arr(arr, n);
  }

  return 0;
}
