#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void p(int m[4][4]) {
  printf("\n");

  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      printf("%2d ", m[i][j]);
    }
    printf("\n");
  }

  printf("\n");
}


void rotate_horizontal(int (*m)[4], int row, int col) {
  for (int i=0; i<row; i++) {
    int l = 0, r = col-1, t;
    while (l<r) {
      t = m[i][l];
      m[i][l] = m[i][r];
      m[i][r] = t;
      l++;
      r--;
    }
  }
  p(m);
}

void rotate_diagonal(int (*m)[4], int row, int col) {
  int l=0, r=row*col-1, t;

  while (l < r) {
    t = m[l/col][l%col];
    m[l/col][l%col] = m[r/col][r%col];
    m[r/col][r%col] = t;
    l++;
    r--;
  }

  p(m);
}

int main() {
  int matrix[4][4];
  //int n[4][4];

  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      srand(i*10+j);
      matrix[i][j] = rand() % 99 + 1;
      //n[i][j] = m[i][j];
    }
  }

  p(matrix);
  rotate_horizontal(matrix, 4, 4);

  rotate_diagonal(matrix, 4, 4);

  return 0;
}
