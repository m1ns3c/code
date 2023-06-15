#include <stdio.h>
#include <string.h>

int max(int a, int b) {
  return (a > b) ? a : b;
}

int lcs(char *X, char *Y, int m, int n) {
  int L[m+1][n+1], i, j;

  for (i=0; i<=m; i++) {
    for (j=0; j<=n; j++) {
      if (i==0 || j==0) {
        L[i][j] = 0;
        continue;
      }

      //printf("%c=%c\n", X[i-1], Y[j-1]);

      if (X[i-1] == Y[j-1]) {
        L[i][j] = L[i-1][j-1] + 1;
      } else {
        L[i][j] = max(L[i-1][j], L[i][j-1]);
      }
    }
  }

  for (i=0; i<=m; i++) {
    for (j=0; j<=n; j++) {
      printf("%3d", L[i][j]);
    }
    printf("\n");
  }

  return L[m][n];
}

int main() {
  char S1[] = "AGGTAB";
  char S2[] = "GXTXAYB";

  int m = strlen(S1);
  int n = strlen(S2);

  /*int dp[m+1][n+1];
  for (int i=0; i<=m; i++) {
    for (int j=0; j<=n; j++) {
      dp[i][j] = -1;
    }
  }*/

  printf("pos[%d]\n", lcs(S1, S2, m, n));

  return 0;
}
