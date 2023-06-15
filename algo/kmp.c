#include <stdio.h>
#include <string.h>

void getNextVal(char p[], int n, int nextVal[]) {
  int i=-1, j=0;

  while (j < n-1) {
    if (i == -1 || p[j] == p[i]) {
      i++;
      j++;

      if (p[j] == p[i]) {
        nextVal[j] = i;
      } else {
        nextVal[j] = nextVal[i];
      }
    } else {
      i = nextVal[i];
    }
  }
}

void getNext(char p[], int n, int next[]) {
  int i=0, j=1;
  next[0] = 0;

  while (j < n) {
    if (p[i] == p[j]) {
      next[j++] = ++i;
    } else {
      if (i != 0) {
        i = next[i-1];
      } else {
        next[j++] = 0;
      }
    }
  }
}

int KMP(char s[], int slen, char p[], int plen, int start) {
  if (start < 0 || start >= slen-plen) {
    return -1;
  }

  int i = start, j = 0;

  int next[plen];

  getNext(p, plen, next);

  while (i < slen) {
    if (s[i] == p[j]) {
      j++;
      i++;
    } else {
      if (j > 0) {
        j = next[j-1];
      }
      i++;
    }

    if (j == plen) {
      return i-j;
    }
  }

  return -1;
}

int main() {
  char text[] = "ABABDABACDABABCABAB";
  char pattern[] = "ABABCABAB";

  int len = strlen(text);
  int p_len = strlen(pattern);

  int start = 0;

  int pos = KMP(text, len, pattern, p_len, start);
  if (pos < 0) {
    printf("not found\n");
  } else {
    printf("pos: [%d]", pos);
  }

  return 0;
}
