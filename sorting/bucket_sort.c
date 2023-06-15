#define bSize 8

void Bucket_Sort(int A[], int n) {
  int buckets[MaxSize] = {0};
  int i;
  // 分桶

  int min = A[0], max = A[0];

  for (i=1; i<n; i++) {
    if (A[i] < min) {
      min = A[i];
    } else if (A[i] > max) {
      max = A[i];
    }
  }
}
