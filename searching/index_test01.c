#include <stdio.h>

#define max 24

extern void createIndex(int[], int, int[], int);
extern int indexSeqSearch(int, int[], int, int[], int);

int main() {
  int A[] = {8,20,26,38,90,105,206,221,229,287,309,312,340,367,483,492,502,551,618,641,698,711,764,796};

  int index[(max/8) + 1] = {0};
  int position;
  int key = 367, i, choice;
  int opt = 0, pos = 0;
  createIndex(index, (max/8)+1, A, max);
  pos = indexSeqSearch(key, index, (max/8)+1, A, max);

  if (pos != -1) {
    printf("pos: %d\n", pos);
  } else {
    printf("not found\n");
  }

  return 0;
}
