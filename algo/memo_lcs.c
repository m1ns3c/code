#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int row;
int col;

int key(int m, int n) {
  return m * col + n;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

int lcs(char *X, char *Y, int m, int n, int *dp) {
  int k = key(m, n);
  printf("%d=(%d,%d)\n", k, m, n);

  if (m == 0||n == 0) {
    return dp[k] = 0;
  }

  if (X[m-1] == Y[n-1]) {
    return dp[k] = 1 + lcs(X, Y, m-1, n-1, dp);
  }

  if (dp[k] != -1) {
    return dp[k];
  }

  return dp[k] = max(lcs(X,Y,m,n-1,dp),lcs(X,Y,m,n-1,dp));
}

int main() {
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";

  row = strlen(X);
  col = strlen(Y);

  int *dp = (int *)calloc((row+1) * (col+1), sizeof(int));
  if (dp == NULL) {
    exit(-1);
  }

  for (int i=0; i<(row+1)*(col+1); i++) {
    dp[i] = -1;
  }

  printf("pos:[%d]\n", lcs(X,Y,row,col,dp));

  printf("   ");
  for (int i=1; i<=col; i++) {
    printf("[%3c]", Y[i-1]);
  }
  printf("\n");

  for (int i=1;i<=row; i++) {
    printf("[%c]", X[i-1]);
    for (int j=1;j<=col;j++) {
      printf("{%3d}", dp[i*col+j]);
    }
    printf("\n");
  }
  return 0;
}
